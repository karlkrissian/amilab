/*
 *  ImageDraw_InfoParam.cpp
 *  AMILab
 */

#include "ImageDraw_InfoParam.h"

#include "DessinImage.hpp"

#include "amilab_messages.h"


//----------------------------------------------------
ImageDraw_InfoParam::ImageDraw_InfoParam (DessinImage* parent): ParamPanel(parent, "Image Information")
{
  parent_class = parent;
  CreateParameters();
  SetToolTip(_T("Information Parameters"));
//  SetMinSize(wxSize(200,200));
  SetMinSize(GetEffectiveMinSize());
}

//----------------------------------------------------
void ImageDraw_InfoParam::CreateParameters ()
{

  InrImage::ptr _image = parent_class->Get_image();
  
  char texte[100];

  BeginBox("Information");
    //----- Nom du fichier
    AddLabel( &_id_info_name, "Name",
                    _image->GetName(), LabelTexte);

    //----- Nom du fichier
    AddLabel( &_id_info_format, "Format",
                      _image->FormatName().c_str(),
                      LabelTexte);

    //----- Dimensions
    sprintf(texte," (%4d, %4d, %4d) ",
        _image->_tx, _image->_ty, _image->_tz);
    AddLabel( &_id_info_dim, "Dim",
                      texte, LabelTexte);

    //----- Voxel Sizes
    sprintf(texte," (%2.2f, %2.2f, %2.2f) ",
        _image->_size_x, _image->_size_y, _image->_size_z);
    AddLabel( &_id_info_voxelsize, "Voxel Size",
                      texte, LabelTexte);
  EndBox();
  //----- Statistics
  AddButton( &_id_info_stat, "Statistics",
                     (void*) ImageDraw_InfoParam::CB_info_stat,
                     (void*) this);

  BeginBox("Statistics results");
    //-----  Number of Points
    sprintf(texte," xxx xxx xxx ");
    AddLabel( &_id_info_numpoints, "Num. of P.",
                      texte, LabelTexte, "Number of Points");

    //----- Min Max
    sprintf(texte," [xxxx.xxxx ; xxxx.xxxx]");
    AddLabel( &_id_info_min_max, "[Min ;  Max]",
                      texte, LabelTexte);

    //----- Mean
    sprintf(texte," xxxx.xxxx");
    AddLabel( &_id_info_mean, "Mean",
                      texte, LabelTexte);

    //----- Standard Deviation
    sprintf(texte," xxxx.xxxx");
    AddLabel( &_id_info_sd, "STD",
                      texte, LabelTexte, "Standard Deviation");

    //----- Mean / Standard Deviation
    sprintf(texte," xxxx.xxxx %%");
    AddLabel( &_id_info_sd_mean, "SD / Mean",
                      texte, LabelTexte);
  EndBox();
  
  ReAfficheParametres();
  EnleveBouttons();
  CreeDialogue();
  MAJ();

}

//----------------------------------------------------
void ImageDraw_InfoParam:: CB_info_stat (void* cd)
{
  ImageDraw_InfoParam* _this = (ImageDraw_InfoParam*) cd;
  if (!_this) {
    CLASS_MESSAGE_STATIC(_this, "Invalid parameter");
    return;
  }
  DessinImage*    di = (DessinImage*) _this->parent_class;
  InrImage::ptr _image = di->Get_image();
  InrImage::ptr _image_mask    = di->Get_image_mask().lock();
  unsigned char* _dessine_mask = di->Get_draw_mask();
  

  float         min=0,max=0;
  double        mean, sd,tmp,val;
  char          texte[100];
  long          numpoints,unit,thous,mill;
  unsigned char mask_ok;

  // Number of points
  // Minimum Maximum of intensity
  // Mean Intensity
  mean = 0;
  numpoints = 0;
  _image->InitBuffer();
  if (*_dessine_mask)
    _image_mask->InitBuffer();

  do
  { 
    val = _image->ValeurBuffer();
    
    if (*_dessine_mask)
    {
      mask_ok = (_image_mask->ValeurBuffer() > 127);
    }
    else
    {
      mask_ok = true;
    }

    if (mask_ok && (val>=di->GetMinIntensity()) &&
       (val<=di->GetMaxIntensity()))
    {
      if (numpoints == 0)
        min = max = val;
      
      if (val< min) min = val;
      if (val> max) max = val;
      mean += val;
      numpoints++;
    }


    if (*_dessine_mask)
      _image_mask->IncBuffer();

  } while (!(!(_image->IncBuffer())));

  mean /= numpoints;

  // Number of points
  unit  = numpoints % 1000;
  thous = (numpoints/1000) % 1000;
  mill  = (numpoints/1000000) % 1000;

  if (mill >0)
    sprintf(texte," %3d",(int)mill);

  if (mill >0)
  {
    sprintf(texte,"%s %03d",texte,(int)thous);
  }
  else
  {
    if (thous >0)
      sprintf(texte," %3d",(int)thous);
  }

  if (mill>0 || thous>0)
  {
    sprintf(texte,"%s %03d",texte,(int)unit);
  }
  else
  {
    sprintf(texte," %3d",(int)unit);
  }

  _this->SetLabelValue(_this->_id_info_numpoints,texte);


//  di->_image->MinMax(&min, &max);
  sprintf(texte," [%4.4f ; %4.4f]",min,max);

  _this->SetLabelValue(_this->_id_info_min_max,texte);

  sprintf(texte," %4.4f",mean);

  _this->SetLabelValue(_this->_id_info_mean,texte);

  // Standard Deviation
  sd = 0;
  _image->InitBuffer();
  if (*_dessine_mask)
    _image_mask->InitBuffer();

  do
  {
    val = _image->ValeurBuffer();

    if (*_dessine_mask)
    {
      mask_ok = (_image_mask->ValeurBuffer() > 127);
    }
    else
    {
      mask_ok = true;
    }

    if (mask_ok && (val>=di->GetMinIntensity()) &&
        (val<=di->GetMaxIntensity()))
    {
      tmp = (val-mean);
      sd += tmp*tmp;
    }

    if (*_dessine_mask)
      _image_mask->IncBuffer();

  } while (!( !(_image->IncBuffer())));

  sd = sqrt(sd/numpoints);

  sprintf(texte," %4.4f",sd);

  _this->SetLabelValue(_this->_id_info_sd,texte);

  // Standard Deviation / Mean
  sprintf(texte," %4.4f %%",sd/mean*100);

  _this->SetLabelValue(_this->_id_info_sd_mean,texte);
  
  
} // CB_info_stat()
