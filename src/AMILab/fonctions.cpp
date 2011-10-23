/*
    ==================================================
    Software : AMILab
    Authors  : Karl Krissian
    Email    : karl@bwh.harvard.edu

    AMILab is a language for image processing
    ==================================================
    Copyright (C) 1996-2005  Karl Krissian

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    ================================================== 
   The full GNU Lesser General Public License file is in Devel/Sources/Prog/LesserGPL_license.txt
*/

#include "fonctions.h"

#include "GeneralGaussianFilter.h"

#include "Coordonnees.hpp"

#include "IsoContour2.hpp"
#include "VarContexts.hpp"
#include "Viewer3D.hpp"
#include "isosurface.hpp"

#include <wx/textdlg.h>

using namespace amilab;

#define EPSILON_fonctions_cpp 1E-5

#include "driver.h"
#include "CommonConfigure.h"
COMMON_VAR_IMPORT unsigned char GB_debug;
COMMON_VAR_IMPORT yyip::Driver GB_driver;

#include "LanguageBaseConfigure.h"
LanguageBase_VAR_IMPORT VarContexts  Vars;

#include "AMILabConfigure.h"
AMILab_VAR_IMPORT wxFrame* GB_main_wxFrame;
AMILab_VAR_IMPORT wxString GB_scripts_dir;


InrImage* Func_OpImage( InrImage* im1, InrImage* im2, InrImage* im3,
            char*     exprmath,
            int    Format)
{

    InrImage*  res;
    InrImage*  ref;
    ExprMath*  expr_math;
    int        x,y,z;
    int        cx,cy,cz;
    float      vA,vB;
    float      vx,vy,vz;
    float      rayon,angle;
    Chaine    expr_string;

    expr_string = exprmath;
    expr_math = new ExprMath( expr_string, 'A','B');
    
    expr_math->AddParameter('X');
    expr_math->AddParameter('Y');
    expr_math->AddParameter('Z');
    
    expr_math->AddParameter('R');
    expr_math->AddParameter('T');
    
    // Test sur la syntaxe de l'expression
    expr_math->SetParamValue('C',0);
    expr_math->Value(0,0);
    Si expr_math->Erreurs() & SYNTAX_ERROR Alors
      fprintf(stderr," Erreur de syntaxe dans l'expression\n");
      return NULL;
    FinSi

    ref = im1;
    res = new InrImage((WORDTYPE) Format,"OpImageRes.inr.gz",ref);

    ref->InitBuffer();
    res->InitBuffer();

    Si im2 != NULL Alors
      Si (im1->_tx != im2->_tx) Ou
         (im1->_ty != im2->_ty) Ou
         (im1->_tz != im2->_tz) Alors
         printf("Image 1 et 2 de dimensions diff�entes ...\n");
         return NULL;
      FinSi
          im2->InitBuffer();
    FinSi

    Si im3 != NULL Alors
      Si (im1->_tx != im3->_tx) Ou
         (im1->_ty != im3->_ty) Ou
         (im1->_tz != im3->_tz) Alors
         printf("Image 1 et 3 de dimensions diff�entes ...\n");
         return NULL;
      FinSi
          im3->InitBuffer();
    FinSi


    cx = (ref->_tx/2);
    cy = (ref->_ty/2);
    cz = (ref->_tz/2);

    Pour( z, 0, ref->_tz - 1)
        Pour( y, 0, ref->_ty - 1)
        Pour( x, 0, ref->_tx - 1)
      
      expr_math->SetParamValue('X', x);
      expr_math->SetParamValue('Y', y);
      expr_math->SetParamValue('Z', z);
    
      rayon = sqrt((double) ((x-cx)*(x-cx)+(y-cy)*(y-cy)+(z-cz)*(z-cz)));
      angle = atan2f(y-cy,x-cx);

      expr_math->SetParamValue('R', rayon);
      expr_math->SetParamValue('T', angle);

          Si Format != WT_FLOAT_VECTOR Alors

        vA = ref->ValeurBuffer();   
            vB = 0; 
        Si im2 != NULL AlorsFait  vB = im2->ValeurBuffer(); 
        Si im3 != NULL AlorsFait 
          expr_math->SetParamValue('C', im3->ValeurBuffer());     

        res->FixeValeur( expr_math->Value(vA,vB) );

          Sinon

            Si (im2 != NULL) Et (im2->VectorialFormat()) Et (im2->GetVDim()>=3) Alors
             vx = expr_math->Value( ref->VectValeurBuffer(0) ,
                    im2->VectValeurBuffer(0));
         vy = expr_math->Value( ref->VectValeurBuffer(1) ,
                    im2->VectValeurBuffer(1));
             vz = expr_math->Value( ref->VectValeurBuffer(2) ,
                    im2->VectValeurBuffer(2));
            Sinon
             vB = 0;  
             Si im2 != NULL AlorsFait vB = im2->ValeurBuffer();     
             Si im3 != NULL AlorsFait 
               expr_math->SetParamValue('C', im3->ValeurBuffer());     

             vx = expr_math->Value( ref->VectValeurBuffer(0) ,vB);
             vy = expr_math->Value( ref->VectValeurBuffer(1) ,vB);
             vz = expr_math->Value( ref->VectValeurBuffer(2) ,vB);
            FinSi

            res->VectFixeValeurs( vx, vy, vz);

          FinSi


      ref->IncBuffer();
      Si (im2 != NULL) AlorsFait im2->IncBuffer(); 
      Si (im3 != NULL) AlorsFait im3->IncBuffer(); 
      res->IncBuffer();

    FinPour
    FinPour
    FinPour

      return res;
}


//#include "ParamBox.hpp"

#include <map>
#include <string>
//#include <pair>
using namespace std;

typedef pair<string,string> file_format;
typedef map<string,string>  file_format_map;

//----------------------------------------------------------------------
int AskFilename(std::string& name)
{

    file_format_map formats;

    formats.insert(file_format( "All ext",
                                "*.*"));
    formats.insert(file_format( "Amilab",
                                "*.ami;*.ami.gz"));
    formats.insert(file_format( "VTK",
                                "*.vtk"));
    formats.insert(file_format( "Standard images",  
                                "*.jpg;*.jpeg;*.png;*.bmp;*.tif;*.tiff"));
    formats.insert(file_format( "ITK",
                                "*.mhd"));
    formats.insert(file_format( "All",
                                "*"));

    wxString s_extDef = wxString::FromAscii(formats["All ext"].c_str());
    wxString format_choices;

    for(file_format_map::iterator p = formats.begin(); 
        p!=formats.end();
        ++p)
    {
      if (p!=formats.begin())
        format_choices << wxString::FromAscii("|");
      format_choices << wxString::FromAscii(str(format(" %1% (%2%) |%2%") % p->first % p->second).c_str());
    }
    if (GB_debug) std::cerr << format_choices << std::endl;

    wxString filename = wxFileSelector(
                                    _T("Select the filename"),
                                    wxEmptyString, // default path
                                    wxEmptyString, // default filename
                                    s_extDef, // default extension
                                    wxString::Format // wildcard
                                    ( format_choices,
                                        wxFileSelectorDefaultWildcardStr,
                                        wxFileSelectorDefaultWildcardStr
                                    ),
                                      wxFD_OPEN
                                    //|wxFD_CHANGE_DIR
                                    |wxFD_PREVIEW
                                    |wxFD_FILE_MUST_EXIST, // FLAGS
                                    NULL // parent
                                   );

    if ( !filename ) return 0;

    // it is just a sample, would use wxSplitPath in real program
    s_extDef = filename.AfterLast(_T('.'));
    name = filename.mb_str(wxConvUTF8);
    return 1;
}

//----------------------------------------------------------------------
int AskImage(std::string& name)
{

    file_format_map formats;

    formats.insert(file_format( "Available",
                                "*.ami;*.ami.gz;*.vtk;*.mhd;*.jpg;*.jpeg;*.png;*.bmp;*.tif;*.tiff"));
    formats.insert(file_format( "Amilab",
                                "*.ami;*.ami.gz"));
    formats.insert(file_format( "VTK",
                                "*.vtk"));
    formats.insert(file_format( "Standard images",  
                                "*.jpg;*.jpeg;*.png;*.bmp;*.tif;*.tiff"));
    formats.insert(file_format( "ITK",
                                "*.mhd"));
    formats.insert(file_format( "All files with extensions",
                                "*.*"));
    formats.insert(file_format( "All files",
                                "*"));

    wxString s_extDef = wxString::FromAscii(formats["Available"].c_str());
    wxString format_choices;

    for(file_format_map::iterator p = formats.begin(); 
        p!=formats.end();
        ++p)
    {
      if (p!=formats.begin())
        format_choices << wxString::FromAscii("|");
      format_choices << wxString::FromAscii(str(format(" %1% (%2%) |%2%") % p->first % p->second).c_str());
    }
    if (GB_debug) std::cerr << format_choices << std::endl;

/*
    format_choices  << "Amilab (*.ami;*.ami.gz)|*.ami;*.ami.gz"
                    <<  "|VTK (*.vtk)|*.vtk"
                    <<  "|JPG (*.jpg) |*.jpg"
                    <<  "|PNG (*.png) |*.png"
                    <<  "|TIFF (*.tif;*.tiff) |*.tif;*tiff"
                    <<  "|All files (%s)|%s";
*/
    wxString filename = wxFileSelector(
                                    _T("Select the image to load"),
                                    wxEmptyString, // default path
                                    wxEmptyString, // default filename
                                    s_extDef, // default extension
                                    //wxString::Format // wildcard
                                    //( format_choices,
                                    //    wxFileSelectorDefaultWildcardStr,
                                    //    wxFileSelectorDefaultWildcardStr
                                    //),
                                    format_choices,
                                      wxFD_OPEN
                                    //|wxFD_CHANGE_DIR
                                    |wxFD_PREVIEW
                                    |wxFD_FILE_MUST_EXIST, // FLAGS
                                    NULL // parent
                                   );

    if ( !filename ) return 0;

    // it is just a sample, would use wxSplitPath in real program
    s_extDef = filename.AfterLast(_T('.'));
    name = filename.mb_str();
//	GB_driver.res_print(filename);
//	GB_driver.res_print(name);
//	std::cout << "image filename = " << name << std::endl;
    return 1;
}

//----------------------------------------------------------------------
int AskVarName(wxWindow* parent, const string title, const string label, const string def, std::string& name)
{

    wxTextEntryDialog dialog(parent,
                            wxString(title.c_str(),wxConvUTF8),
                            wxString(label.c_str(),wxConvUTF8),
                            wxString(def.c_str(),wxConvUTF8),
                             wxOK | wxCENTRE);

    if (dialog.ShowModal() == wxID_OK)
    {
      name = string(dialog.GetValue().mb_str());
      return 1;
    }

    return 0;

}


//----------------------------------------------------------------
int AskSurface(std::string& name)
{

    static wxString s_extDef;
    wxString filename = wxFileSelector(
                                    _T("Select the polydata to load"),
                                    wxEmptyString, // default path
                                    wxEmptyString, // default filename
                                    s_extDef, // default extension
                                    wxString::Format // wildcard
                                    (
                                        _T("VTK (*.vtk)|*.vtk|All files (%s)|%s"),
                                        wxFileSelectorDefaultWildcardStr,
                                        wxFileSelectorDefaultWildcardStr
                                    ),
                                    wxFD_OPEN
                                    //|wxFD_CHANGE_DIR
                                    |wxFD_PREVIEW|wxFD_FILE_MUST_EXIST, // FLAGS
                                    NULL // parent
                                   );

    if ( !filename ) return 0;

    // it is just a sample, would use wxSplitPath in real program
    s_extDef = filename.AfterLast(_T('.'));
    name = filename.mb_str(wxConvUTF8);
    return 1;

}


//----------------------------------------------------------------------
int AskScript(std::string& name)
{
    wxString s_extDef = wxString::FromAscii("*.amil");
    wxString format_choices;

    file_format_map formats;

    formats.insert(file_format( "Amilab Script",
                                "*.amil"));
    formats.insert(file_format( "text",
                                "*.txt"));
    formats.insert(file_format( "All files with extensions",
                                "*.*"));

    for(file_format_map::iterator p = formats.begin(); 
        p!=formats.end();
        ++p)
    {
      if (p!=formats.begin())
        format_choices << wxString::FromAscii("|");
      format_choices << wxString::FromAscii(str(format(" %1% (%2%) |%2%") % p->first % p->second).c_str());
    }
    if (GB_debug) std::cerr << format_choices << std::endl;

    wxString filename = wxFileSelector(
                                    _T("Select the script to load"),
                                    GB_scripts_dir, // default path
                                    wxEmptyString, // default filename
                                    s_extDef, // default extension
                                    wxString::Format // wildcard
                                    ( format_choices,
                                        wxFileSelectorDefaultWildcardStr,
                                        wxFileSelectorDefaultWildcardStr
                                    ),
                                      wxFD_OPEN
                                   // |wxFD_CHANGE_DIR
                                    |wxFD_PREVIEW
                                    |wxFD_FILE_MUST_EXIST, // FLAGS
                                    NULL // parent
                                   );

    if ( !filename ) return 0;

    // it is just a sample, would use wxSplitPath in real program
    s_extDef = filename.AfterLast(_T('.'));
    name = filename.mb_str(wxConvUTF8);
    return 1;
}


unsigned  char   Func_Normalize( InrImage* im)
{
  double norm;
  int i;
  double tmp,norm2;

  Si !im->VectorialFormat() Alors
    fprintf(stderr,"Func_Normalize() \t image not vectorial \n");
    return 0;
  FinSi
 
  im->InitBuffer();  
  Repeter
    norm2 = 0;
    for(i=0;i<im->GetVDim();i++) {
      tmp = im->VectValeurBuffer(i);
      norm2 += tmp*tmp;
    }
    norm=sqrt(norm2);
    Si norm>1E-3 Alors
      for(i=0;i<im->GetVDim();i++) 
       im->VectFixeValeur(i,im->VectValeurBuffer(i)/norm);
    FinSi
  JusquA Non(im->IncBuffer()) FinRepeter

  return 1;
}


float  Func_eccentricity( InrImage* im)
{
  double bx,by;
  float       val;
  double val_sum=0;
  int x,y;
  double var_x=0;
  double var_y=0;
  double var_xy=0;
  double e1,e2,e3;

  // Computation of the barycenter  
  bx = by  = 0;

  im->InitBuffer();
  Pour(y,0,im->_ty-1)
  Pour(x,0,im->_tx-1)
    val      = im->ValeurBuffer();
    Si val>1E-5 Alors
      bx      += val*x;
      by      += val*y;
      //      bz      += val*z;
      val_sum += val;
    FinSi
    im->IncBuffer();
  FinPour
  FinPour

  Si val_sum > 1E-5 Alors
    bx /= val_sum;
    by /= val_sum;
  FinSi

  printf(" Barycenter %f %f  \n", bx,by);

  im->InitBuffer();
  Pour(y,0,im->_ty-1)
  Pour(x,0,im->_tx-1)
    val      = im->ValeurBuffer();
    Si val>1E-5 Alors
      var_x    += val*(x-bx)*(x-bx);
      var_y    += val*(y-by)*(y-by);
      var_xy   += val*(x-bx)*(y-by);
    FinSi
    im->IncBuffer();
  FinPour
  FinPour

  e1 = (var_x - var_y)*(var_x - var_y);
  e2 = (var_x + var_y)*(var_x + var_y);
  e3 = var_xy*var_xy;

  return ((e1+4*e3)/e2);
}


InrImage* Func_rot2D( InrImage* image, 
              float cx, float cy, float angle,
              float tx, float ty )
{

  
    InrImage* res;
    int       x1,y1;
    float      x,y;

  res = new InrImage( (int) tx, (int) ty, 1, WT_FLOAT, ((Chaine) image->GetName())+".rot.inr");

  res->InitBuffer();

  Pour(y1,0,res->_ty-1)
  Pour(x1,0,res->_tx-1)

    x = (cx+ cosd(-angle)*(x1-cx) - sind(-angle)*(y1-cy));
    y = (cy+ sind(-angle)*(x1-cx) + cosd(-angle)*(y1-cy));

    Si x >=0 Et x < image->_tx Et y >=0 Et y < image->_ty Alors
      res->FixeValeur(image->InterpLinIntensite(x,y));
    Sinon
      res->FixeValeur(0.0);
    FinSi

    res->IncBuffer();

  FinPour
  FinPour

  return res;

}

//
//  Parameters:
//    coord_system: 0 --> use translation and voxel size (vtk)
//                  1 --> IJK coord system
//                  2 --> RAS coord system: use the transformation matrix
//                            of the image
SurfacePoly* Func_isosurf( InrImage::ptr image, float seuil, InrImage* mask,
               int coord_system)
{

  
    TPolygone     polygone;
    int        p,n;
    Vect3D<float> norm;
    pt3D          pt,pt1;
    IsoSurface*   isosurface;
    SurfacePoly*  surf;

    float         translation[3];
    float         transfmat[4][4];

  image->GetTranslation( translation[0], translation[1], translation[2]);
  image->GetTransfMatrix(transfmat);

  isosurface = new IsoSurface( image);
  isosurface->CalculSurface( seuil, mask);

  surf = new SurfacePoly;

  surf->NewSurface();

  Si coord_system <0 AlorsFait coord_system = 0;
  Si coord_system >2 AlorsFait coord_system = 2;

  switch ( coord_system ){
    case 0:
      Pour( n, 0, isosurface->_image_points->NbPoints()-1)
        pt = isosurface->_image_points->Point(n);
       surf->AddPoint( pt.x*image->_size_x+translation[0], 
               pt.y*image->_size_y+translation[1], 
               pt.z*image->_size_z+translation[2]);
        // Ajout de la normale (-gradient)
        isosurface->CalculNormale(pt, norm);
        // The vectors are already normalized ...
        surf->SetNorm( norm.x, norm.y, norm.z);
      FinPour  
    break;

    case 1:
      Pour( n, 0, isosurface->_image_points->NbPoints()-1)
        pt = isosurface->_image_points->Point(n);
        surf->AddPoint( pt.x+translation[0],
            pt.y+translation[1],
            pt.z+translation[2]);
        // Ajout de la normale (-gradient)
        isosurface->CalculNormale(pt, norm);
        // The vectors are already normalized, so re-multiply
        surf->SetNorm( norm.x*image->_size_x, 
               norm.y*image->_size_y, 
               norm.z*image->_size_z);
      FinPour  
    break;

    case 2:
      Pour( n, 0, isosurface->_image_points->NbPoints()-1)
        pt = isosurface->_image_points->Point(n);

        pt.x += translation[0];
        pt.y += translation[1];
        pt.z += translation[2];

        pt1.x = pt.x*transfmat[0][0]+pt.y*transfmat[0][1]+pt.z*transfmat[0][2]+transfmat[0][3];
        pt1.y = pt.x*transfmat[1][0]+pt.y*transfmat[1][1]+pt.z*transfmat[1][2]+transfmat[1][3];
        pt1.z = pt.x*transfmat[2][0]+pt.y*transfmat[2][1]+pt.z*transfmat[2][2]+transfmat[2][3];

        // Apply the transformation matrix
        surf->AddPoint( pt1.x, pt1.y, pt1.z);

        // Ajout de la normale (-gradient)
        isosurface->CalculNormale(pt, norm);
        // The vectors are already normalized ...
    // SHOULD APPLY TRANSFORMATION TO THE NORMAL ...
        surf->SetNorm( norm.x, norm.y, norm.z);

      FinPour  
    break;

  } // end switch


  // Write the polygons
  Pour(p, 0, isosurface->tabPoly.NbElts()-1) 

    surf->NewPoly();

    polygone = isosurface->tabPoly[p];
    Pour( n, 0, polygone.NbElts()-1)
      surf->PolyAddPointNumber(polygone[n]);
    FinPour  // n

    surf->EndPoly();

  FinPour 

  delete isosurface;

  return surf;

}


//----------------------------------------------------------------------
InrImage*  Func_OutFlux2D( InrImage* im)
//         --------------
{

  
    InrImage* res;
    register int x,y;
    int i,j,n;
    register float* res_buf0;
    register float* res_buf1;
    register double flux,norm;

    int    displace[8];  // displacement for the 8 neighbors
    double vector[8][2]; // vector normal
    int    tx;

  Si (!im->VectorialFormat()) Alors
    fprintf(stderr,"Func_OutFlux() \t input must be vectorial \n");
  FinSi

  tx = im->_tx;

  n = 0;
  Pour(i,-1,1)
  Pour(j,-1,1)
    Si (i==0)Et(j==0) AlorsFait continue;
    displace[n] = 3*(i+j*tx);
    norm = sqrt((double)(i*i+j*j));
    vector[n][0] = i/norm;
    vector[n][1] = j/norm;
    n++;
  FinPour
  FinPour

  res = new InrImage(WT_FLOAT,"outflux.ami.gz",im);
  res->InitImage(0.0);  

  Pour(y,1,im->_ty-2)
  im ->BufferPos(1,y,0);
  res->BufferPos(1,y,0);
  Pour(x,1,im->_tx-2)

    flux = 0;
    res_buf0 = (float*) im->BufferPtr();

    Pour(n,0,7)
      res_buf1 = res_buf0 + displace[n];
      flux += vector[n][0]*(*(res_buf1))   +
            vector[n][1]*(*(res_buf1+1));
    FinPour

    res->FixeValeur(flux);

    im->IncBuffer();
    res->IncBuffer();

  FinPour  
  FinPour  

  return res;

} // Func_OutFlux2D()


//----------------------------------------------------------------------
InrImage*  Func_OutFluxScalar( InrImage* im)
//         ------------------
{

  //  if (im->DimZ()==1) return Func_OutFlux2D(im);

  
    InrImage* res;
    register int x,y,z;
    int i,j,k,n;
    register float* res_buf0;
    register float* res_bufi;
    register float* res_bufj;
    register float* res_bufk;
    register double flux;

    int    displace[26];  // displacement for the 26 neighbors
    double vector[26][3]; // vector normal
    double norm[26];
    int    tx,txy;

  Si im->_format != WT_FLOAT Alors
    fprintf(stderr,"Func_OutFlux() \t input must be of type WT_FLOAT\n");
  FinSi

  tx = im->_tx;
  txy = tx*im->_ty;

  n = 0;
  Pour(i,-1,1)
  Pour(j,-1,1)
  Pour(k,-1,1)
    Si (i==0)Et(j==0)Et(k==0) AlorsFait continue;
    displace[n] = i+j*tx+k*txy;
    norm[n] = sqrt((double)(i*i+j*j+k*k));
    vector[n][0] = i/norm[n];
    vector[n][1] = j/norm[n];
    vector[n][2] = k/norm[n];
    n++;
  FinPour
  FinPour
  FinPour

  res = new InrImage(WT_FLOAT,"outflux.ami.gz",im);
  res->InitImage(0.0);  

  Pour(z,1,im->_tz-2)
  Pour(y,1,im->_ty-2)
  im ->BufferPos(1,y,z);
  res->BufferPos(1,y,z);
  Pour(x,1,im->_tx-2)

    flux = 0;
    res_buf0 = (float*) im->BufferPtr();

    n = 0;
    res_bufi = res_buf0-1;
    Pour(i,-1,1)
      res_bufj = res_buf0-tx;
      Pour(j,-1,1)
        res_bufk = res_buf0-txy;
        Pour(k,-1,1)
          Si ((i==0)Et(j!=0)Et(k!=0))Ou
             ((i!=0)Et(j==0)Et(k!=0))Ou
         ((i!=0)Et(j!=0)Et(k==0))  
          Alors
      //          Si ((i!=0)Ou(j!=0)Ou(k!=0)) Alors
        flux += ((*res_bufi-*res_buf0) +
                     (*res_bufj-*res_buf0) +
                 (*res_bufk-*res_buf0)) / norm[n];
      FinSi
          Si (i!=0)Ou(j!=0)Ou(k!=0) AlorsFait  n++;

          res_bufk += txy;
        FinPour
        res_bufj += tx;
      FinPour
      res_bufi++;
    FinPour

    res->FixeValeur(flux);

    im->IncBuffer();
    res->IncBuffer();

  FinPour  
  FinPour  
  FinPour  

  return res;

} // Func_OutFluxScalar()

//----------------------------------------------------------------------
InrImage*  Func_OutFlux( InrImage* im)
//         ------------
{

  if (im->DimZ()==1) return Func_OutFlux2D(im);

  
    InrImage* res;
    register int x,y,z;
    int i,j,k,n;
    register float* res_buf0;
    register float* res_buf1;
    register double flux,norm;

    int    displace[26];  // displacement for the 26 neighbors
    double vector[26][3]; // vector normal
    int    tx,txy;

  Si !im->VectorialFormat() Alors
    fprintf(stderr,"Func_OutFlux() \t input must be vectorial\n");
  FinSi

  tx = im->_tx;
  txy = tx*im->_ty;

  n = 0;
  Pour(i,-1,1)
  Pour(j,-1,1)
  Pour(k,-1,1)
    Si (i==0)Et(j==0)Et(k==0) AlorsFait continue;
    displace[n] = 3*(i+j*tx+k*txy);
    norm = sqrt((double) (i*i+j*j+k*k));
    vector[n][0] = i/norm;
    vector[n][1] = j/norm;
    vector[n][2] = k/norm;
    n++;
  FinPour
  FinPour
  FinPour

  res = new InrImage(WT_FLOAT,1,"outflux.ami.gz",im);
  res->InitImage(0.0);  

  Pour(z,1,im->_tz-2)
  Pour(y,1,im->_ty-2)
  im ->BufferPos(1,y,z);
  res->BufferPos(1,y,z);
  Pour(x,1,im->_tx-2)

    flux = 0;
    res_buf0 = (float*) im->BufferPtr();

    Pour(n,0,25)
      res_buf1 = res_buf0 + displace[n];
      flux += vector[n][0]*(*(res_buf1))   +
              vector[n][1]*(*(res_buf1+1)) +
          vector[n][2]*(*(res_buf1+2));
    FinPour

    res->FixeValeur(flux);

    im->IncBuffer();
    res->IncBuffer();

  FinPour  
  FinPour  
  FinPour  

  return res;

} // Func_OutFlux()

//----------------------------------------------------------------------
InrImage*  Func_OrientationRatio2D( InrImage* im)
//         -----------------------
{

  
    InrImage* res;
    register int x,y;
    int i,j,n;
    register float* res_buf0;
    register float* res_buf1;

    int    displace[8];  // displacement for the 8 neighbors
    int    tx;
    int    nb_neg;
    float ps,vx,vy;

  Si (!im->VectorialFormat()) Alors
    fprintf(stderr,"Func_OutFlux() \t input must be vectorial \n");
  FinSi

  tx = im->_tx;

  n = 0;
  Pour(i,-1,1)
  Pour(j,-1,1)
    Si (i==0)Et(j==0) AlorsFait continue;
    displace[n] = 3*(i+j*tx);
    n++;
  FinPour
  FinPour

  res = new InrImage(WT_FLOAT,"outflux.ami.gz",im);
  res->InitImage(0.0);  

  Pour(y,1,im->_ty-2)
  im ->BufferPos(1,y,0);
  res->BufferPos(1,y,0);
  Pour(x,1,im->_tx-2)

    res_buf0 = (float*) im->BufferPtr();

    nb_neg = 0;

    vx = *res_buf0;
    vy = *(res_buf0+1);

    Pour(n,0,7)
      res_buf1 = res_buf0 + displace[n];
      ps = vx*(*(res_buf1))   +
           vy*(*(res_buf1+1));
      if (ps<0) nb_neg++;
    FinPour

    res->FixeValeur(1.0*nb_neg/8.0);

    im->IncBuffer();
    res->IncBuffer();

  FinPour  
  FinPour  

  return res;

} // Func_OrientationRatio2D()


//----------------------------------------------------------------------
InrImage*    Func_ThresholdCrossing( InrImage* im, float th)
{

  InrImage* res;
  register int x,y,z;
  int i,j,k,n;
  int sign, neigh_sign;
  //  float val;
  int   displace[5];  // displacement for the 5 neighbors
  int   tx,txy;

  res = new InrImage(WT_UNSIGNED_CHAR,"TC.ami.gz",im);
  res->InitImage(0);

  tx = im->_tx;
  txy = tx*im->_ty;

  n = 0;
  Pour(i,0,1)
  Pour(j,0,1)
  Pour(k,0,1)
    Si (i==0)Et(j==0)Et(k==0) AlorsFait continue;
    displace[n] = i+j*tx+k*txy;
    n++;
  FinPour
  FinPour
  FinPour

  Pour(z,0,im->_tz-2)
  Pour(y,0,im->_ty-2)
  im ->BufferPos(0,y,z);
  Pour(x,0,im->_tx-2)

    sign = (im->ValeurBuffer()>th); 

    Pour(n,0,5)

      neigh_sign =  (im->ValeurBuffer(displace[n])>th);

      if (sign != neigh_sign) {
    res->BufferPos(x,y,z);
    res->FixeValeur(255);
    res->IncBuffer(displace[n]);
    res->FixeValeur(255);
      }
    FinPour

    im->IncBuffer();

  FinPour  
  FinPour  
  FinPour  

  return res;

} // Func_ThresholdCrossing()


//----------------------------------------------------------------------
InrImage*    Func_IsocontourPoints( InrImage* im, float th)
{
  InrImage* res;
  register int   x, y, z;
  register float x1,y1,z1;
  int            n;
  int            sign, neigh_sign;
  float          val1,val2,d;
  int            displace[3];  // displacement for the 5 neighbors
  int            tx,txy;
  TableauDyn< Point_3D<float> > points;
  Point_3D<float> p;
  int             zmax,num_dir;

  tx = im->_tx;
  txy = tx*im->_ty;

  displace[0] = 1;
  displace[1] = tx;
  displace[2] = txy;

  Si (im->DimZ()>1) Alors
    num_dir=3;
    zmax = im->_tz-2;
  Sinon
    num_dir=2;
    zmax = 0;
  FinSi

  // first parse, check the number of points
  Pour(z,0,zmax)
  Pour(y,0,im->_ty-2)
  im ->BufferPos(0,y,z);
  Pour(x,0,im->_tx-2)

    val1 = im->ValeurBuffer()-th;
    sign = (val1>0); 

    Pour(n,0,num_dir-1)
      val2 = im->ValeurBuffer(displace[n])-th;
      neigh_sign =  (val2>0);
      if ((sign != neigh_sign)&&(fabsf(val1-val2)>1E-5)) {
    // Add interpolated point
    d = val1/(val1-val2);
    x1 = x;
    y1 = y;
    z1 = z;
    switch (n) {
    case 0: x1 += d; break;
    case 1: y1 += d; break;
    case 2: z1 += d; break;
    }
        p.Init(x1,y1,z1);
    points += p;
      }
    FinPour
    im->IncBuffer();
  FinPour  
  FinPour  
  FinPour  

  // Store in the image
  res = new InrImage(points.NbElts(),1,1,
             WT_FLOAT_VECTOR,
             "isosurf_pos.ami.gz"
             );

  InrImageIteratorBase::ptr res_it(res->CreateIterator());
  res_it->InitBuffer();
  Pour(x,0,res->DimX()-1)
    res_it->SetDoubleVectorValues(points[x].x,points[x].y,points[x].z);
    ++(*res_it);
  FinPour

  return res;


} // Func_IsocontourPoints()


//----------------------------------------------------------------------
InrImage*    Func_IsosurfDist2D( InrImage* im, float th)
{

  InrImage*    res;
  register int x,y;
  register int          n;
  register int          sign, neigh_sign;
  register float        val0,val1,diff;
  register float        val0_new,val1_new;
  register int          displace[2];  
  int          tx;

  register float        Grad[2];
  register float        vs[2];
  register float        norm=0;
  unsigned char      grad_computed;

  vs[0] = im->_size_x;
  vs[1] = im->_size_y;

  res = new InrImage(WT_FLOAT,"IsosurfDist.ami.gz",im);
  res->InitImage(0);

  im ->InitBuffer();
  res->InitBuffer();
  Repeter
    Si im->ValeurBuffer()>th Alors
      res->FixeValeur(1);
    Sinon
      Si im->ValeurBuffer()<th AlorsFait
        res->FixeValeur(-1);
    FinSi
    res->IncBuffer();
  JusquA Non(im->IncBuffer())
  FinRepeter

  tx = im->_tx;

  n = 0;

  displace[0] = 1;
  displace[1] = tx;

  Pour(y,0,im->_ty-2)
  im ->BufferPos(0,y,0);
  Pour(x,0,im->_tx-2)

    val0 = im->ValeurBuffer()-th;
    sign = (val0>0); 

    grad_computed = false;

    Pour(n,0,1)

      val1 = im->ValeurBuffer(displace[n])-th;
      neigh_sign =  (val1>0);

      if (sign != neigh_sign) {

    if (!grad_computed) {
      // gradient estimation
      Grad[0] = (im->ValeurBuffer(1)  - im->ValeurBuffer())/vs[0];
      Grad[1] = (im->ValeurBuffer(tx) - im->ValeurBuffer())/vs[1];
      
      // Normalization
      norm = sqrt(Grad[0]*Grad[0]+Grad[1]*Grad[1]);
      
      grad_computed = true;
      if (norm<EPSILON_fonctions_cpp) 
        fprintf(stderr, " %d %d %d norm=%f \n",x,y,0,norm);
    }

    if (sign)
      diff = (val0-val1)/vs[n];
    else
      diff = (val1-val0)/vs[n];

        if (diff<EPSILON_fonctions_cpp) {
      fprintf(stderr," %d %d %d %d  %f diff< %f \n",x,y,0,n,diff, 
          EPSILON_fonctions_cpp);
      continue;
    }

    val0_new = val0/diff;
    val1_new = val1/diff;

    if (norm>EPSILON_fonctions_cpp) {
      val0_new *= fabsf(Grad[n])/norm;
      val1_new *= fabsf(Grad[n])/norm;
    } else
      fprintf(stderr,"Func_IsosurfDist2D() \t norm<=EPSILON_fonctions_cpp \n");

    if (fabsf(val0_new)>1) {
      fprintf(stderr," %d %d %d %d  val0=%f val1=%f val0_new=%f \n",x,y,0,n,val0,val1,val0_new);
    }

    if (fabsf(val1_new)>1) {
      fprintf(stderr," %d %d %d %d  val0=%f val1=%f val1_new=%f \n",x,y,0,n,val0,val1,val1_new);
    }

    res->BufferPos(x,y,0);
    if (fabsf(val0_new)<fabsf(res->ValeurBuffer())) {
      if ((x==4)&&(y==15)) 
        fprintf(stderr,"new value %f \n",val0_new); 
      res->FixeValeur(val0_new);
    }

    res->IncBuffer(displace[n]);
    if (fabsf(val1_new)<fabsf(res->ValeurBuffer())) {
      if (((n==0)&&(x==3)&&(y==15)) ||
              ((n==1)&&(x==4)&&(y==14)))
        fprintf(stderr,"new value %d %f \n",n,val1_new); 
      res->FixeValeur(val1_new);
    }
      }
    FinPour

    im->IncBuffer();

  FinPour  
  FinPour  

  return res;

} // Func_IsosurfDist2D()


//----------------------------------------------------------------------
InrImage*    Func_IsosurfDist( InrImage* im, float th)
{

  InrImage*    res;
  register int x,y,z;
  register int          n;
  register int          sign, neigh_sign;
  register float        val0,val1,diff;
  register float        val0_new,val1_new;
  register int          displace[3];  
  int          tx,txy;

  register float        Grad[3];
  register float        vs[3];
  register float        norm=0;
  unsigned char      grad_computed;

  if (im->DimZ() == 1) return Func_IsosurfDist2D(im,th);

  vs[0] = im->_size_x;
  vs[1] = im->_size_y;
  vs[2] = im->_size_z;


  res = new InrImage(WT_FLOAT,"IsosurfDist.ami.gz",im);
  res->InitImage(0);

  im ->InitBuffer();
  res->InitBuffer();
  Repeter
    Si im->ValeurBuffer()>th Alors
      res->FixeValeur(1);
    Sinon
      Si im->ValeurBuffer()<th AlorsFait
        res->FixeValeur(-1);
    FinSi
    res->IncBuffer();
  JusquA Non(im->IncBuffer())
  FinRepeter

  tx = im->_tx;
  txy = tx*im->_ty;

  n = 0;

  displace[0] = 1;
  displace[1] = tx;
  displace[2] = txy;

  Pour(z,0,im->_tz-2)
  Pour(y,0,im->_ty-2)
  im ->BufferPos(0,y,z);
  Pour(x,0,im->_tx-2)

    val0 = im->ValeurBuffer()-th;
    sign = (val0>0); 

    grad_computed = false;

    Pour(n,0,2)

      val1 = im->ValeurBuffer(displace[n])-th;
      neigh_sign =  (val1>0);

      if (sign != neigh_sign) {

    if (!grad_computed) {
      // gradient estimation
      Grad[0] = (im->ValeurBuffer(1)  - im->ValeurBuffer())/vs[0];
      Grad[1] = (im->ValeurBuffer(tx) - im->ValeurBuffer())/vs[1];
      Grad[2] = (im->ValeurBuffer(txy)- im->ValeurBuffer())/vs[2];
      
      // Normalization
      norm = sqrt(Grad[0]*Grad[0]+Grad[1]*Grad[1]+Grad[2]*Grad[2]);
      
      grad_computed = true;
      if (norm<EPSILON_fonctions_cpp)
        fprintf(stderr, " %d %d %d norm=%f \n",x,y,z,norm);
    }

    if (sign)
      diff = (val0-val1)/vs[n];
    else
      diff = (val1-val0)/vs[n];

        if (diff<EPSILON_fonctions_cpp) {
      fprintf(stderr," %d %d %d %d  %f diff<1-2 \n",x,y,z,n,diff);
      continue;
    }

    val0_new = val0/diff;
    val1_new = val1/diff;

    if (norm>EPSILON_fonctions_cpp) {
      val0_new *= fabsf(Grad[n])/norm;
      val1_new *= fabsf(Grad[n])/norm;
    }

    if (fabsf(val0_new)>1) {
      fprintf(stderr," %d %d %d %d  val0=%f val1=%f val0_new=%f \n",x,y,z,n,val0,val1,val0_new);
    }

    if (fabsf(val1_new)>1) {
      fprintf(stderr," %d %d %d %d  val0=%f val1=%f val1_new=%f \n",x,y,z,n,val0,val1,val1_new);
    }

    res->BufferPos(x,y,z);
    if (fabsf(val0_new)<fabsf(res->ValeurBuffer())) {
      res->FixeValeur(val0_new);
    }

    res->IncBuffer(displace[n]);
    if (fabsf(val1_new)<fabsf(res->ValeurBuffer())) {
      res->FixeValeur(val1_new);
    }
      }
    FinPour

    im->IncBuffer();

  FinPour  
  FinPour  
  FinPour  

  return res;

} // Func_IsosurfDist()


//----------------------------------------------------------------------
InrImage*  Func_Convolve( InrImage* in, InrImage* kernel )
//         -------------
{
  InrImage* res;
  long int       kernel_size;
  int*      kernel_pos;
  int       i,j,k,x,y,z,n;
  int       msx2;
  int       msy2;
  int       msz2;
  int       min_x,max_x;
  int       min_y,max_y;
  int       min_z,max_z;
  double    sum;
  float*    kernel_buf;


  res = new InrImage(WT_FLOAT,"Convolve.ami.gz",in);
  (*res) = (*in);

  
  msx2 = kernel->_tx/2;
  msy2 = kernel->_ty/2;
  msz2 = kernel->_tz/2;

  kernel_size = kernel->_tx*kernel->_ty*kernel->_tz;
  kernel_pos = new int[kernel_size];

  min_x = msx2;
  max_x = in->_tx-1-msx2;
  min_y = msy2;
  max_y = in->_ty-1-msy2;
  min_z = msz2;
  max_z = in->_tz-1-msz2;

  n = 0;
  Pour(k,0,kernel->_tz-1)
  Pour(j,0,kernel->_ty-1)
  Pour(i,0,kernel->_tx-1)
    kernel_pos[n]  = (i-msx2)+((j-msy2)+(k-msz2)*in->_ty)*in->_tx; 
    kernel_pos[n] *= -1;
    n++;
  FinPour
  FinPour
  FinPour

  kernel_buf = (float*) kernel->Buffer();

  Pour(z,min_z,max_z)
  Pour(y,min_y,max_y)
    in ->BufferPos(min_x,y,z);
    res->BufferPos(min_x,y,z);
  Pour(x,min_x,max_x)

    sum = 0;
    Pour(n,0,kernel_size-1)
      sum += kernel_buf[n]*in->ValeurBuffer(kernel_pos[n]);
    FinPour

    res->FixeValeur(sum);

    in->IncBuffer();
    res->IncBuffer();

  FinPour
  FinPour
  FinPour

  delete [] kernel_pos;
  return res;

} // Func_Convolve()


//----------------------------------------------------------------------
InrImage*  Func_ConvolveMask( InrImage* in, InrImage* kernel, InrImage* mask )
//         -----------------
{
  InrImage* res;
  long int       kernel_size;
  int*      kernel_pos;
  int       i,j,k,x,y,z,n;
  int       msx2;
  int       msy2;
  int       msz2;
  int       min_x,max_x;
  int       min_y,max_y;
  int       min_z,max_z;
  double    sum;
  double    weight;
  float*    kernel_buf;


  res = new InrImage(WT_FLOAT,"Convolve.ami.gz",in);
  (*res) = (*in);

  
  msx2 = kernel->_tx/2;
  msy2 = kernel->_ty/2;
  msz2 = kernel->_tz/2;

  kernel_size = kernel->_tx*kernel->_ty*kernel->_tz;
  kernel_pos = new int[kernel_size];

  min_x = msx2;
  max_x = in->_tx-1-msx2;
  min_y = msy2;
  max_y = in->_ty-1-msy2;
  min_z = msz2;
  max_z = in->_tz-1-msz2;

  n = 0;
  Pour(k,0,kernel->_tz-1)
  Pour(j,0,kernel->_ty-1)
  Pour(i,0,kernel->_tx-1)
    kernel_pos[n]  = (i-msx2)+((j-msy2)+(k-msz2)*in->_ty)*in->_tx; 
    kernel_pos[n] *= -1;
    n++;
  FinPour
  FinPour
  FinPour

  kernel_buf = (float*) kernel->Buffer();

  Pour(z,min_z,max_z)
  Pour(y,min_y,max_y)
    in   ->BufferPos(min_x,y,z);
    mask ->BufferPos(min_x,y,z);
    res  ->BufferPos(min_x,y,z);
  Pour(x,min_x,max_x)

    sum = 0;
    weight = 0;
    Pour(n,0,kernel_size-1)
      if (mask->ValeurBuffer(kernel_pos[n])>0) {
    sum += kernel_buf[n]*in->ValeurBuffer(kernel_pos[n]);
    weight += kernel_buf[n];
      }
    FinPour

    if (weight>0)
      res->FixeValeur(sum/weight);
    else
      res->FixeValeur(0);

    in  ->IncBuffer();
    mask->IncBuffer();
    res ->IncBuffer();

  FinPour
  FinPour
  FinPour

  delete [] kernel_pos;
  return res;

} // Func_ConvolveMask()


//----------------------------------------------------------------------
void         Func_Pad( InrImage* im1, InrImage* im2, 
//           --------
               int stepx, int stepy, int stepz,
               int posx,int posy,int posz
               )
{
  
    int x,y,z;
    int x1,y1,z1;

  printf("pad %d %d %d %d %d %d \n",stepx,stepy,stepz,posx,posy,posz);

    if (GB_debug) fprintf(stderr,"Func_Pad() begin \n");

 z1 = posz; 
 Pour(z,0,im2->DimZ()-1)
    if (z1>im1->DimZ()-1) {
      fprintf(stderr,"Func_Pad() out of image1 limits in Z \n");
      break;
    }
    y1 = posy;
    Pour(y,0,im2->DimY()-1)
      if (y1>im1->DimY()-1) {
    fprintf(stderr,"Func_Pad() out of image1 limits in Y\n");
    break;
      }
      x1 = posx;
      im1->BufferPos(x1,y1,z1);
      im2->BufferPos(0,y,z);
      Pour(x,0,im2->DimX()-1)
    //       if (GB_debug) fprintf(stderr,"x %d y %d z %d x1 %d  y1 %d  z1 %d \n",x,y,z,x1,y1,z1);
        if (x1>im1->DimX()-1) {
      fprintf(stderr,"Func_Pad() out of image1 limits in X\n");
      break;
        }
        if (im1->ScalarFormat() && im2->ScalarFormat()) {
          im1->FixeValeur(im2->ValeurBuffer());
        } else 
        if (im1->VectorialFormat()&&im2->VectorialFormat()) {
      for(int i=0;i<im2->GetVDim();i++)
           im1->VectFixeValeur(i,im2->VectValeurBuffer(i));
        }
        else {
          fprintf(stderr,"Func_Pad() \t mixing scalar and vectorial images is not allowed \n");
          return;
        }

        x1 += stepx;
    im1->IncBuffer(stepx);
    im2->IncBuffer();
      FinPour
      y1 += stepy;
    FinPour
    z1 += stepz;
  FinPour

    if (GB_debug) fprintf(stderr,"Func_Pad() end \n");

} // Func_Pad()



//--------------------------------------------------
InrImage*    Func_CC(InrImage* im, float background_threshold, int topology)
{
  IsoContour2*  isocontour;
  InrImage* image_num_contour;

  image_num_contour =  new InrImage( WT_SIGNED_INT, "connected_components.ami.gz", im);
  image_num_contour->InitImage(-1);

  isocontour = new IsoContour2(im);

  isocontour->SetTopology(topology);

  isocontour->SetInputImage(im);
  isocontour->SetImageContours(im,image_num_contour,NULL);
  isocontour->SetMaxFond(background_threshold);

  isocontour->SetSauve(0);
  isocontour->SetDebug(GB_debug);

  isocontour->RechercheContours( image_num_contour);
  isocontour->DefinitInterieur(  1);
  isocontour->SortContours();

  BasicVariable::ptr var;

  InrImage::ptr reorder_image( isocontour->GetReorderImage());
  Vars.AddVar<InrImage>("reorder",reorder_image);

  InrImage::ptr inclusion_image( isocontour->GetInclusionImage());
  Vars.AddVar<InrImage>("inclusion",inclusion_image);

  InrImage::ptr sign_image( isocontour->GetSignImage());
  Vars.AddVar<InrImage>("cc_sign",sign_image);

  InrImage::ptr size_image (isocontour->GetSizeImage());
  Vars.AddVar<InrImage>("cc_size",size_image);

  delete isocontour;

  return image_num_contour;
}


//----------------------------------------------------------------------
InrImage* Func_Flip(InrImage::ptr& im, int axis)
//           ---------
{

  InrImage* res;
  int x,y,z;
  int x1,y1,z1;

  res = new InrImage(im->_format,"flipped.ami.gz", im.get() );

  res->InitBuffer();
  Pour(z,0,im->DimZ()-1)
  Pour(y,0,im->DimY()-1)
  Pour(x,0,im->DimX()-1)

    x1=x;y1=y;z1=z;
    switch(axis) {
    case 0:x1=im->DimX()-1-x; break;
    case 1:y1=im->DimY()-1-y; break;
    case 2:z1=im->DimZ()-1-z; break;
    }
    if (res->ScalarFormat())
      res->FixeValeur((*im)(x1,y1,z1));
    else 
      if (res->_format==WT_RGB) {
        res->VectFixeValeurs((*im)(x1,y1,z1,0),
                 (*im)(x1,y1,z1,1),
                 (*im)(x1,y1,z1,2));
      }
    else
      if (res->GetVDim()==3) {
      switch(axis) {
      case 0:
    res->VectFixeValeurs(-(*im)(x1,y1,z1,0),
                (*im)(x1,y1,z1,1),
                (*im)(x1,y1,z1,2));
    break;
      case 1:
    res->VectFixeValeurs((*im)(x1,y1,z1,0),
                -(*im)(x1,y1,z1,1),
                (*im)(x1,y1,z1,2));
    break;
      case 2:
    res->VectFixeValeurs((*im)(x1,y1,z1,0),
                (*im)(x1,y1,z1,1),
                -(*im)(x1,y1,z1,2));
    break;
      } // switch
      } // if vdim ==3
    else
      for(int i=0;i<im->GetVDim();i++)
    res->VectFixeValeur(i,(*im)(x1,y1,z1,i));
    res->IncBuffer();

  FinPour
  FinPour
  FinPour

  return res;

} // Func_Flip()

//----------------------------------------------------------------------
//
// Create Ellipsoids from 3 vector fields
// 
// 
//
SurfacePoly* Func_CreateEllipsoids(InrImage* v1, InrImage* v2, InrImage* v3, 
//           ------------------
                   int stepx, int stepy, int stepz, int res,
                   InrImage* colors,
                   InrImage* mask)
{
  int x,y,z;
  double teta,phi;
  SurfacePoly* surf;
  double v1x,v1y,v1z;
  double v2x,v2y,v2z;
  double v3x,v3y,v3z;
  double v4x,v4y,v4z;

  double p1x,p1y,p1z;
  //  double p2x,p2y,p2z;

  //  double p3x,p3y,p3z;
  //  double p4x,p4y,p4z;
  double phi_step,teta_step;
  double cteta,steta,cphi,sphi;
  int    npoints;
  int    phi_pos,teta_pos,teta_pos1;
  int    red=0,green=0,blue=0;

  surf = new SurfacePoly;
  surf->NewSurface();

  phi_step=1.0*(PI-0.02)/res;
  teta_step=1.0*PI/res;
  printf("phi_step = %3.3f, teta_step = %3.3f\n",phi_step,teta_step);

  for(x=0;x<v1->DimX(); x+=stepx)
  for(y=0;y<v1->DimY(); y+=stepy)
  for(z=0;z<v1->DimZ(); z+=stepz)
    {

      if ((mask!=NULL)&&((*mask)(x,y,z)<0.5))
    continue;

      //      printf("x,y,z = %d %d %d \n",x,y,z);
      v1x=(*v1)(x,y,z,0);
      v1y=(*v1)(x,y,z,1);
      v1z=(*v1)(x,y,z,2);

      if ((fabsf(v1x)<1E-5)&&(fabsf(v1y)<1E-5)&&(fabsf(v1z)<1E-5))
    continue;

      v2x=(*v2)(x,y,z,0);
      v2y=(*v2)(x,y,z,1);
      v2z=(*v2)(x,y,z,2);

      if ((fabsf(v2x)<1E-5)&&(fabsf(v2y)<1E-5)&&(fabsf(v2z)<1E-5))
    continue;

      v3x=(*v3)(x,y,z,0);
      v3y=(*v3)(x,y,z,1);
      v3z=(*v3)(x,y,z,2);

      if ((fabsf(v3x)<1E-5)&&(fabsf(v3y)<1E-5)&&(fabsf(v3z)<1E-5))
    continue;


      if ((colors!=NULL)&&(colors->_format==WT_RGB)) {
    red   = (int)(*colors)(x,y,z,0);
    green = (int)(*colors)(x,y,z,1);
    blue  = (int)(*colors)(x,y,z,2);
      }

      // check if the basis is direct, if not, reverse the last vector
      v4x = v1y*v2z-v1z*v2y;
      v4y = v1z*v2x-v1x*v2z;
      v4z = v1x*v2y-v1y*v2x;

      float ps=v4x*v3x+v4y*v3y+v4z*v3z;
      if (ps<0) {
    v3x=-v3x;
    v3y=-v3y;
    v3z=-v3z;
      }

      npoints = surf->NbPoints();

      int n;

      // Add all the points
      for(phi=-PI/2.0+0.01;phi<=PI/2.0-0.01+1E-5;phi+=phi_step) {
    cphi=cos(phi);
    sphi=sin(phi);
    //printf("phi = %3.3f \n",phi);
    n = 0;
    for(teta=0;teta<=2*PI-1E-5;teta+=teta_step) {
      //      printf("teta = %3.3f \n",teta);
      cteta=cos(teta);
      steta=sin(teta);
      p1x = cphi*cteta*v1x+cphi*steta*v2x+sphi*v3x;
      p1y = cphi*cteta*v1y+cphi*steta*v2y+sphi*v3y;
      p1z = cphi*cteta*v1z+cphi*steta*v2z+sphi*v3z;

      p1x += x*v1->VoxSizeX()+v1->TrX();
      p1y += y*v1->VoxSizeY()+v1->TrY();
      p1z += z*v1->VoxSizeZ()+v1->TrZ();


      surf->AddPoint(p1x,p1y,p1z);
      if ((colors!=NULL)&&(colors->_format==WT_RGB)) {
        surf->GetPoint(surf->GetNumberOfPoints()-1).SetColor(red,green,blue);
      }
      
      n++;
    }
      }


      int tmp;
      int nteta=2*res;

      //      printf("nteta = %d, n = %d \n",nteta,n);
      // Create the triangles
      for(phi_pos=0;phi_pos<res;phi_pos++) {
    //printf("phi_pos = %d \n",phi_pos);
    tmp = npoints+phi_pos*nteta;
    for(teta_pos=0;teta_pos<nteta;teta_pos++) {
      surf->NewPoly();
      teta_pos1 = (teta_pos+1)%nteta;
      surf->PolyAddPointNumber(tmp+      teta_pos);
      surf->PolyAddPointNumber(tmp+      teta_pos1);
      surf->PolyAddPointNumber(tmp+nteta+teta_pos1);
      surf->PolyAddPointNumber(tmp+nteta+teta_pos);
      surf->EndPoly();      
    }
      }
    }

  return surf;

} // Func_CreateEllipsoids()


