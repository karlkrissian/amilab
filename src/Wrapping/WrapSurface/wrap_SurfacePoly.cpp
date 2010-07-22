//
// C++ Implementation: wrap_SurfacePoly
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "wrap_SurfacePoly.h"
#include "surface.hpp"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

#include "vtkwrap.h"
#include "FluidProject.h"
#include "Func_ReadCTALine.h"
#include "fonctions.h"

#define GET_PARAM(type,varname,defaultval) \
  type varname = defaultval; \
  if (!get_val_param<type>( varname, p, n)) \
    ClassHelpAndReturn;

#define GET_SMTPTR_PARAM(type,varname) \
  boost::shared_ptr<type> varname; \
  if (!get_val_smtptr_param<type>( varname, p, n)) \
    ClassHelpAndReturn;

#include "driver.h"

extern yyip::Driver GB_driver;

//-------------------------------------------------------------------------
AMIObject::ptr AddWrap_SurfacePoly(  WrapClass_SurfacePoly::ptr& objectptr)
{
  // Create new instance of the class
  AMIObject::ptr amiobject( new AMIObject);
  amiobject->SetName("SurfacePoly");
  amiobject->SetWrappedObject(objectptr);
  objectptr->SetAMIObject(amiobject);
  objectptr->AddMethods( objectptr);
  return amiobject;
}

//----------------------------------------------------------
Variable<AMIObject>::ptr CreateVar_SurfacePoly( SurfacePoly* si)
{
  // here SurfacePoly can be deleted
  boost::shared_ptr<SurfacePoly> _si_ptr( si );
  WrapClass_SurfacePoly::ptr sip(new WrapClass_SurfacePoly(_si_ptr));
  AMIObject::ptr amiobject(AddWrap_SurfacePoly(sip));
  Variable<AMIObject>::ptr varres(
      new Variable<AMIObject>( amiobject));
  return varres;
}

//---------------------------------------------------
//  SurfacePoly Constructor
//---------------------------------------------------
void  wrap_SurfacePoly::SetParametersComments() 
{
  ADDPARAMCOMMENT("filename: input filename (optional).");
  return_comments = "A wrapped SurfacePoly object.";
}
//---------------------------------------------------
BasicVariable::ptr wrap_SurfacePoly::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(std::string,filename,  "");

  SurfacePoly* surf = new SurfacePoly();
  if (filename!="") {
    int res = surf->Read(filename.c_str());
    if (!res) {
      CLASS_ERROR("Failed to read polydata.");
    }
  }
  return CreateVar_SurfacePoly(surf);
}

//---------------------------------------------------
//  info
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_info::SetParametersComments() 
{}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_info::CallMember( ParamList* p)
{
  // TODO: create info command for variables??
  SurfacePoly::ptr s(this->_objectptr->GetObj());

  // we don't have the variable name here ...
  std::string tmp_string;
  tmp_string = (boost::format(" %s: %d points %d lines %d polygons  \n")
//    % var->Name()
    % "SurfacePoly variable"
    % s->GetNumberOfPoints()
    % s->GetNumberOfLines()
    % s->GetNumberOfPolys ()
    ).str();
  GB_driver.res_print(tmp_string);
  tmp_string = (boost::format(" limits X:[%4.2f %4.2f] Y:[%4.2f %4.2f]  Z:[%4.2f %4.2f]  \n")
    % s->_xmin % s->_xmax
    % s->_ymin % s->_ymax
    % s->_zmin % s->_zmax).str();
  GB_driver.res_print(tmp_string);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  save
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_save::SetParametersComments() 
{
  ADDPARAMCOMMENT("string: filename");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_save::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  std::string filename;
  int n=0;
  if (!get_val_param<string>( filename, p, n)) ClassHelpAndReturn;

  s->Write(filename.c_str());
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Read
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_Read::SetParametersComments() 
{
  ADDPARAMCOMMENT("filename: input filename");
  return_comments = "1 if success, 0 otherwise";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_Read::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  int n=0;
  GET_PARAM(std::string,filename, "");
  int res = s->Read(filename.c_str());
  RETURN_VAR(int,res);
}

//---------------------------------------------------
//  WriteCTALine
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_WriteCTALine::SetParametersComments() 
{
  ADDPARAMCOMMENT("string: filename.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_WriteCTALine::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  std::string filename;
  int n=0;
  if (!get_val_param<string>( filename, p, n)) ClassHelpAndReturn;

  Func_WriteCTALine(s.get(),filename.c_str());
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  OwnMaterial
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_OwnMaterial::SetParametersComments() 
{
   ADDPARAMCOMMENT("integer: 1 or 0 to enable or disable ownmaterial property.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_OwnMaterial::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  int ownmat;
  int n=0;
  if (!get_val_param<int>( ownmat, p, n)) ClassHelpAndReturn;

  s->SetOwnMaterial( ownmat);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetAmbient
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_SetAmbient::SetParametersComments() 
{
  ADDPARAMCOMMENT("Unsigned char: red   component (0-255)");
  ADDPARAMCOMMENT("Unsigned char: green component (0-255)");
  ADDPARAMCOMMENT("Unsigned char: blue  component (0-255)");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_SetAmbient::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  int n=0;
  GET_PARAM(unsigned char,red,  0);
  GET_PARAM(unsigned char,green,0);
  GET_PARAM(unsigned char,blue, 0);

  s->GetMaterial()._ambient.FixeValeur(red,green,blue);

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetDiffuse
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_SetDiffuse::SetParametersComments() 
{
  ADDPARAMCOMMENT("Unsigned char: red   component (0-255)");
  ADDPARAMCOMMENT("Unsigned char: green component (0-255)");
  ADDPARAMCOMMENT("Unsigned char: blue  component (0-255)");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_SetDiffuse::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  int n=0;
  GET_PARAM(unsigned char,red,  0);
  GET_PARAM(unsigned char,green,0);
  GET_PARAM(unsigned char,blue, 0);

  s->GetMaterial()._diffuse.FixeValeur(red,green,blue);

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetSpecular
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_SetSpecular::SetParametersComments() 
{
  ADDPARAMCOMMENT("Unsigned char: red   component (0-255)");
  ADDPARAMCOMMENT("Unsigned char: green component (0-255)");
  ADDPARAMCOMMENT("Unsigned char: blue  component (0-255)");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_SetSpecular::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  int n=0;
  GET_PARAM(unsigned char,red,  0);
  GET_PARAM(unsigned char,green,0);
  GET_PARAM(unsigned char,blue, 0);

  s->GetMaterial()._specular.FixeValeur(red,green,blue);

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetShininess
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_SetShininess::SetParametersComments() 
{
  ADDPARAMCOMMENT("float: the surface opengl shininess value.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_SetShininess::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  float shininess  = 0;
  int n=0;
  if (!get_val_param<float>( shininess, p, n)) ClassHelpAndReturn;

  s->GetMaterial()._shininess= shininess;

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetOpacity
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_SetOpacity::SetParametersComments() 
{
  ADDPARAMCOMMENT("float: surface opacity (in [0,1]).");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_SetOpacity::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  int n=0;
  float opacity  = 0;
  if (!get_val_param<float>( opacity, p, n)) ClassHelpAndReturn;

  s->GetMaterial()._opacity= opacity;
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetVisible
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_SetVisible::SetParametersComments() 
{
  ADDPARAMCOMMENT("integer: 0/1 for hide/show.");
  return_comments = "";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_SetVisible::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  int n=0;
  GET_PARAM(int,visible,1);
  s->SetVisible(visible);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetColorMaterial
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_SetColorMaterial::SetParametersComments() 
{
  ADDPARAMCOMMENT("integer: 1/0 for enable/disable.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_SetColorMaterial::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  int n=0;
  GET_PARAM(int,cm,1);
  s->GetMaterial()._colormaterial = (cm>0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetColorOpacity
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_SetColorOpacity::SetParametersComments() 
{
  ADDPARAMCOMMENT("float: opacity value (in [0,1]).");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_SetColorOpacity::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  int n=0;
  GET_PARAM(float,val,1);
  s->SetColorOpacity(val);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetColor
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_SetColor::SetParametersComments() 
{
  ADDPARAMCOMMENT("Unsigned char: red   component (0-255)");
  ADDPARAMCOMMENT("Unsigned char: green component (0-255)");
  ADDPARAMCOMMENT("Unsigned char: blue  component (0-255)");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_SetColor::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  int n=0;
  GET_PARAM(unsigned char,red,  0);
  GET_PARAM(unsigned char,green,0);
  GET_PARAM(unsigned char,blue, 0);

  for(int i=0; i<s->NbPoints(); i++)
    (*s)[i].SetColor(red,green,blue);

  s->SetColorMaterial(true);
  s->GLRecomputeList(  );
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetPointsColors
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_SetPointsColors::SetParametersComments() 
{
  ADDPARAMCOMMENT("Image: 1D image containing the colors for each vertex.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_SetPointsColors::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  int n=0;
  GET_SMTPTR_PARAM(InrImage,im);
  s->SetPointsColors( im.get());
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetColors
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_SetColors::SetParametersComments() 
{
  ADDPARAMCOMMENT("Image: 3D image (RGB or greyscale)  the colors of each surface vertex is set based on the color of the image at the same spatial position.");
  ADDPARAMCOMMENT("float: minimal intensity, in case of greyscale input image, defines the minimal intensity (black), default:0.");
  ADDPARAMCOMMENT("float: maximal intensity, in case of greyscale input image, defines the maximal intensity (white), default 255.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_SetColors::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  int n=0;
  GET_SMTPTR_PARAM( InrImage, im);
  GET_PARAM(        float,    Imin, 0);
  GET_PARAM(        float,    Imax, 255);
  s->SetColors( im.get() , Imin, Imax);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Statistics
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_Statistics::SetParametersComments() 
{
  ADDPARAMCOMMENT("Image: input image for computing the statistics");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_Statistics::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  int n=0;
  GET_SMTPTR_PARAM(InrImage,im);
  s->Statistics( im.get() );
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  MergePoints
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_MergePoints::SetParametersComments() 
{
  ADDPARAMCOMMENT("float: maximal distance for which points are merged (default:0.1).");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_MergePoints::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  int n=0;
  GET_PARAM( float, maxdist,0.1);
  s->MergePoints(maxdist);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Triangulate
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_Triangulate::SetParametersComments() 
{
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_Triangulate::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  s->Triangulate();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Curvatures
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_Curvatures::SetParametersComments() 
{
  ADDPARAMCOMMENT("integer: depth for the curvature calculations.");
  return_comments = "An object variable containing 4 images: cmin and cmax: min and max curvatures, dmin and dmax: min and max curvature directions (default:1).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_Curvatures::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  int n=0;
  GET_PARAM( int, depth, 1);

  std::string  name;
  int          nbpts;

  // Create images for the curvatures and their directions
  InrImage::ptr Icmin;
  InrImage::ptr Icmax;
  InrImage::ptr Idmin;
  InrImage::ptr Idmax;

  nbpts = s->GetNumberOfPoints();

  Icmin = InrImage::ptr(new InrImage(nbpts,1,1,WT_FLOAT,"mincurv.ami.gz"));
  Icmax = InrImage::ptr(new InrImage(nbpts,1,1,WT_FLOAT,"maxcurv.ami.gz"));

  Idmin = InrImage::ptr(new InrImage(nbpts,1,1,3,WT_FLOAT,"mincurvdir.ami.gz"));
  Idmax = InrImage::ptr(new InrImage(nbpts,1,1,3,WT_FLOAT,"maxcurvdir.ami.gz"));

  s->ComputeCurvatures( Icmin.get(),Icmax.get(),
                        Idmin.get(),Idmax.get(), 
                        depth);

  // Create new instance of the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("surf");

  // add the 4 images as variables
  amiobject->GetContext()->AddVar<InrImage>("cmin",Icmin, amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("cmax",Icmax, amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("dmin",Idmin, amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("dmax",Idmax, amiobject->GetContext());

  // return the variable
  Variable<AMIObject>::ptr varres(
      new Variable<AMIObject>( amiobject));
  return varres;
}

//---------------------------------------------------
//  Displace
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_Displace::SetParametersComments() 
{
  ADDPARAMCOMMENT("Image: input scalar image of displacements in the normal of the surface at each point.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_Displace::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  int n=0;
  GET_SMTPTR_PARAM(InrImage,im);
  s->DisplacePoints( im.get() );
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Translate
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_Translate::SetParametersComments() 
{
  ADDPARAMCOMMENT("float: translation in X (def:0).");
  ADDPARAMCOMMENT("float: translation in Y (def:0).");
  ADDPARAMCOMMENT("float: translation in Z (def:0).");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_Translate::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  int n=0;
  GET_PARAM( float, tr_x,0);
  GET_PARAM( float, tr_y,0);
  GET_PARAM( float, tr_z,0);
  s->Translate( tr_x, tr_y, tr_z );
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Scale
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_Scale::SetParametersComments() 
{
  ADDPARAMCOMMENT("float: scale in X (def:1).");
  ADDPARAMCOMMENT("float: scale in Y (def:1).");
  ADDPARAMCOMMENT("float: scale in Z (def:1).");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_Scale::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  int n=0;
  GET_PARAM( float, sc_x,1);
  GET_PARAM( float, sc_y,1);
  GET_PARAM( float, sc_z,1);
  s->Scale( sc_x,sc_y,sc_z,0 );
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetLineWidth
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_SetLineWidth::SetParametersComments() 
{
  ADDPARAMCOMMENT("integer: line width (def:1), a value between 1 and 10 is enforced.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_SetLineWidth::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  int n=0;
  GET_PARAM( int, lw,1);
  if (lw<1)  lw=1;
  if (lw>10) lw=10;
  s->_line_width = lw;
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  RemoveLine
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_RemoveLine::SetParametersComments() 
{
  ADDPARAMCOMMENT("Integer: line number to remove (def:0).");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_RemoveLine::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  int n=0;
  GET_PARAM( int, ln, 0);
  s->RemoveLine(ln);
  s->GLRecomputeList();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SelectLines
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_SelectLines::SetParametersComments() 
{
  ADDPARAMCOMMENT("Image: 1D image of size the number of lines, where the intensities higher than 0.5 mean the lines numbers to select.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_SelectLines::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  int n=0;
  GET_SMTPTR_PARAM(InrImage,im);
  s->SelectLines(im.get());
  s->GLRecomputeList();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  RemoveSelection
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_RemoveSelection::SetParametersComments() 
{}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_RemoveSelection::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  s->RemoveSelection();
  s->GLRecomputeList();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Recompute
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_Recompute::SetParametersComments() 
{}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_Recompute::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  s->GLRecomputeList();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Normals
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_Normals::SetParametersComments() 
{}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_Normals::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  s->RecomputeNormals();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  InvertNormals
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_InvertNormals::SetParametersComments() 
{}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_InvertNormals::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  s->InvertNormals();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  vtkSmooth
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_vtkSmooth::SetParametersComments() 
{
  ADDPARAMCOMMENT("Integer: number of smoothing iterations (def:30).");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_vtkSmooth::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  int n=0;
  GET_PARAM( int, it, 30);
  Func_ApplyvtkSmooth(s.get(), it);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  vtkWindowedSinc
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_vtkWindowedSinc::SetParametersComments() 
{
  ADDPARAMCOMMENT("Integer: number of smoothing iterations (def:30).");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_vtkWindowedSinc::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  int n=0;
  GET_PARAM( int, it, 30);
  Func_vtkWindowedSinc(s.get(), it);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  vtkDecimate
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_vtkDecimate::SetParametersComments() 
{
  return_comments = "Returns the decimates surface.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_vtkDecimate::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  SurfacePoly* surf = Func_decimate(s.get());
  return CreateVar_SurfacePoly(surf);
}

//---------------------------------------------------
//  setminCC
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_setminCC::SetParametersComments() 
{
  ADDPARAMCOMMENT("Integer: minimum size of connected components to display (def:10).");
  return_comments="The number of the recomputed GL list of the surface";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_setminCC::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  int n=0;
  GET_PARAM( int, minsize, 10);
  // TODO: check the use of _SURFACE, seems strange
  GLuint _SURFACE;

  if (!(s->_cc_calculees)) s->CalculCC();
  s->GLSurfaceMinThCC( _SURFACE, minsize);
  RETURN_VAR(int,(int)_SURFACE);
}

//---------------------------------------------------
//  drawCC
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_drawCC::SetParametersComments() 
{
  ADDPARAMCOMMENT("Integer: connected component number, if -1, draws all the CC (def:0).");
  ADDPARAMCOMMENT("Integer: if -1: only draws this CC, otherwise Enable/Disable drawing of the selected component (default:-1).");
  return_comments = "The number of the recomputed GL list of the surface";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_drawCC::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  int n=0;
  GET_PARAM( int, cc,    0);
  GET_PARAM( int, draw, -1);
  
  GLuint _SURFACE;

  if (!(s->_cc_calculees))  s->CalculCC();
  if (draw==-1)
    s->GLSurfaceDrawOnlyCC( _SURFACE, cc);
  else
    s->GLSurfaceSetDrawCC( _SURFACE, cc, draw);

  RETURN_VAR(int,(int)_SURFACE);
}

//---------------------------------------------------
//  AddPoint
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_AddPoint::SetParametersComments() 
{
  ADDPARAMCOMMENT("Float: X position (def:0).");
  ADDPARAMCOMMENT("Float: Y position (def:0).");
  ADDPARAMCOMMENT("Float: Z position (def:0).");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_AddPoint::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  int n=0;
  GET_PARAM( float, posx, 0);
  GET_PARAM( float, posy, 0);
  GET_PARAM( float, posz, 0);
  s->AddPoint(posx,posy,posz);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  NewLine
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_NewLine::SetParametersComments() 
{}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_NewLine::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  s->NewLine();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  LineAddPointNumber
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_LineAddPointNumber::SetParametersComments() 
{
  ADDPARAMCOMMENT("Integer: index of the point to add.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_LineAddPointNumber::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  int n=0;
  GET_PARAM( int, pid, 0);
  s->LineAddPointNumber( pid );
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  EndLine
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_EndLine::SetParametersComments() 
{}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_EndLine::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  s->EndLine();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  ElevateMesh
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_ElevateMesh::SetParametersComments() 
{
  ADDPARAMCOMMENT("Image: input image can be scalar or vectorial.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_ElevateMesh::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  int n=0;
  GET_SMTPTR_PARAM(InrImage,im);
  AMIFluid::Func_ElevateMesh(s.get(),im.get());
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  NbPoints
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_NbPoints::SetParametersComments() 
{
  return_comments = "Number of points of the polydata.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_NbPoints::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  int val = s->GetNumberOfPoints();
  RETURN_VAR(int,val);
}

//---------------------------------------------------
//  NbPolys
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_NbPolys::SetParametersComments() 
{
  return_comments = "Number of polygons of the polydata.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_NbPolys::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  int val = s->GetNumberOfPolys();
  RETURN_VAR(int,val);
}

//---------------------------------------------------
//  GetNumberOfLines
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_GetNumberOfLines::SetParametersComments() 
{
  return_comments = "Number of lines of the polydata.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_GetNumberOfLines::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  int val = s->GetNumberOfLines();
  RETURN_VAR(int,val);
}

//---------------------------------------------------
//  GetLinesLength
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_GetLinesLength::SetParametersComments() 
{
  return_comments = "1D image containing the length of all the lines.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_GetLinesLength::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  InrImage::ptr res(s->GetImageLinesLength());
  return Variable<InrImage>::ptr( 
    new Variable<InrImage>(res));
}

//---------------------------------------------------
//  GetLine
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_GetLine::SetParametersComments() 
{
  ADDPARAMCOMMENT("Integer: line number (def:0).");
  return_comments = "A vectorial image containing the points positions of the selected line.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_GetLine::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  int n=0;
  GET_PARAM( int, linenumber, 0);

  if ((linenumber>=0)&&
      (linenumber<s->GetNumberOfLines())) 
  {
    T_Line line=s->GetLine(linenumber);
    if (line.NbElts()>0) 
    {
      // Create the image
      InrImage::ptr res(new InrImage(
              line.NbElts(),1,1,3,WT_FLOAT,
              (boost::format("Image_line%1%") 
                % linenumber
              ).str().c_str()));
      // fill it with the point positions
      for(int p=0;p<line.NbElts();p++) {
        res->BufferPos(p,0,0);
        Point_3D<float>  pt = s->GetPoint(line[p]).pt;
        res->VectFixeValeurs( pt.X(),pt.Y(),pt.Z());
      }
      return Variable<InrImage>::ptr( 
        new Variable<InrImage>(res));
    } else
      GB_driver.err_print((boost::format("Line %1% has no point.") % linenumber).str());
  } else {
    GB_driver.err_print("Invalid line number.");
  }
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  GetLinesExtremities
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_GetLinesExtremities::SetParametersComments() 
{
  return_comments = "An image Mx2 where M is the number of lines and  containing the point id of the 2 extremities of each line";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_GetLinesExtremities::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  InrImage::ptr res(s->GetImageLinesExtremities());
  return Variable<InrImage>::ptr( 
        new Variable<InrImage>(res));
}

//---------------------------------------------------
//  GetConnections
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_GetConnections::SetParametersComments() 
{
  return_comments = "1D image of size the total number of points of the polydata, and the number of line connections of each point.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_GetConnections::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  InrImage::ptr res ( s->GetImageConnections());
  return Variable<InrImage>::ptr( 
        new Variable<InrImage>(res));
}

//---------------------------------------------------
//  GetIntensities
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_GetIntensities::SetParametersComments() 
{
  ADDPARAMCOMMENT("Input image to get the intensities from.");
  return_comments = "1D image representing the intensities of the input image at the position of the polydata vertices";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_GetIntensities::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  int n=0;
  GET_SMTPTR_PARAM(InrImage,im);
  InrImage::ptr res( s->GetIntensities( im.get() ));
  return Variable<InrImage>::ptr( 
        new Variable<InrImage>(res));
}

//---------------------------------------------------
//  ConnectLines
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_ConnectLines::SetParametersComments() 
{
  ADDPARAMCOMMENT("Float: maximal distance (square distance between extremities) (def:0.5)");
  ADDPARAMCOMMENT("Float: maximal angle (square length of the sum of the normalized extremity vectors) (def:0.1)");
  return_comments = "Resulting polydata.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_ConnectLines::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  int n=0;
  GET_PARAM( float, maxdist,  0.5);
  GET_PARAM( float, maxangle, 0.1);
  SurfacePoly* surf = 
    Func_ConnectLines( s.get(), maxdist, maxangle);
  return CreateVar_SurfacePoly(surf);
}

//---------------------------------------------------
//  left_assign
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_left_assign::SetParametersComments() 
{
  ADDPARAMCOMMENT(" New variable of type Surface Poly");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_left_assign::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  if ((!p)||p->GetNumParam()==0) 
    return BasicVariable::ptr();

  int n=0;
  CLASS_GET_OBJECT_PARAM(SurfacePoly, varsurf, surf);
//  BasicVariable::ptr var(p->GetParam(0));
//  DYNAMIC_CAST_VARIABLE(SurfacePoly, var, varsurf);

  if (varsurf.get()) {
    // should be OK
    if (varsurf->GetPtrCounter()==1) {
      CLASS_MESSAGE("GetPtrCounter()==1");
      this->_objectptr->_obj = surf; 
    } else {
      // make a copy first
      BasicVariable::ptr copy(varsurf->NewCopy());
      GET_WRAPPED_OBJECT(SurfacePoly, copy, surf);
      this->_objectptr->_obj = surf;
    }
  }
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  assign
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_assign::SetParametersComments() 
{
  ADDPARAMCOMMENT("Variable of type Surface Poly");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::
      wrap_assign::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  if ((!p)||p->GetNumParam()==0) 
    return BasicVariable::ptr();

  int n=0;
  CLASS_GET_OBJECT_PARAM(SurfacePoly, varsurf,surf);

  if (varsurf.get()) {
    // should be OK
    // default copy 
    (*s) = (*surf); 
  }
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  copy
//---------------------------------------------------
void WrapClass_SurfacePoly::
      wrap_copy::SetParametersComments() 
{
  return_comments="A copy of the SurfacePoly object within a new variable.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SurfacePoly::wrap_copy::CallMember( ParamList* p)
{
  SurfacePoly::ptr s(this->_objectptr->GetObj());
  return CreateVar_SurfacePoly( new SurfacePoly(*s));
}
