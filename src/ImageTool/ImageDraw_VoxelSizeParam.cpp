/*
 *  ImageDraw_VoxelSizeParam.cpp
 *  AMILab
 */

#include "ImageDraw_VoxelSizeParam.h"

#include "DessinImage.hpp"

#include "amilab_messages.h"


//----------------------------------------------------
ImageDraw_VoxelSizeParam::ImageDraw_VoxelSizeParam (DessinImage* parent): ParamPanel(parent, "Voxel Size")
{
  parent_class = parent;
  CreateParameters();
  SetToolTip(_T("Voxel Size Parameters"));
//  SetMinSize(wxSize(200,200));
  SetMinSize(GetEffectiveMinSize());
}

//----------------------------------------------------
void ImageDraw_VoxelSizeParam::CreateParameters ()
{

  DessinImageParametres* Param = parent_class->GetParam();
  
  BeginBox("VOXEL size");
    //--------------
    AddFloat( &_id_voxel_size_x, &Param->_dim._voxel_size_x,
                  "X ",
                  2,
                  "VOXEL size X");
    FloatConstraints(    _id_voxel_size_x, 0.1, 10, Param->_dim._voxel_size_x);
    ChangedValueCallback( _id_voxel_size_x,
                        (void*) ImageDraw_VoxelSizeParam::CB_voxel_size,
                        (void*) this);

    //--------------
    AddFloat( &_id_voxel_size_y, &Param->_dim._voxel_size_y,
                  "Y ",
                  2,
                  "VOXEL size Y");
    FloatConstraints(    _id_voxel_size_y, 0.1, 10, Param->_dim._voxel_size_y);
    ChangedValueCallback( _id_voxel_size_y,
                        (void*) ImageDraw_VoxelSizeParam::CB_voxel_size,
                        (void*) this);

    //--------------
    AddFloat( &_id_voxel_size_z, &Param->_dim._voxel_size_z,
                  "Z ",
                  2,
                  "VOXEL size Z");
    FloatConstraints(    _id_voxel_size_z, 0.1, 10, Param->_dim._voxel_size_z);
    ChangedValueCallback( _id_voxel_size_z,
                        (void*) ImageDraw_VoxelSizeParam::CB_voxel_size,
                        (void*) this);
  EndBox();
  
  ReAfficheParametres();
  EnleveBouttons();
  CreeDialogue();
  MAJ();

}

//----------------------------------------------------
void ImageDraw_VoxelSizeParam:: CB_voxel_size (void* cd)
{
  ImageDraw_VoxelSizeParam* _this = (ImageDraw_VoxelSizeParam*) cd;
  if (!_this) {
    CLASS_MESSAGE_STATIC(_this, "Invalid parameter");
    return;
  }
  DessinImage*    di = (DessinImage*) _this->parent_class;
  DessinImageParametres* Param = di->GetParam();
  InrImage::ptr _image_MIP = di->Get_image_MIP();
  ImageMIP* _MIP = di->Get_MIP();
  
  if (Param->_option_traitement == OPTION_MIP)
  {
    _MIP->FixeVoxelSize( Param->_dim._voxel_size_x,
                         Param->_dim._voxel_size_y,
                         Param->_dim._voxel_size_z );
    
    _image_MIP = InrImage::ptr(_MIP->CreeMIP(
                                              Param->_MIP._rot_X,
                                              Param->_MIP._rot_Y,
                                              Param->_MIP._rot_Z ));
    // La liberation l'ancienne image de la m�oire se fait dans FixeVoxelSize
    Param->_MIP._MAJ = true;
    di->Call_ChangeImage();
  }

  Param->_MAJ.MAJCoupes();
  di->EffaceTousLesEcrans( false);
  di->Paint();

  
} // CB_voxel_size()


