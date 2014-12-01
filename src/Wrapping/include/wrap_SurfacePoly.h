/**
 * C++ Interface: wrap_SurfacePoly
 *
 * Description: wrapping SurfacePoly
 *
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_SurfacePoly_h_
#define _wrap_SurfacePoly_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "Variables.hpp"
#include "paramlist.h"
#include "ami_object.h"

//#include "surface.hpp"
namespace amilab {
class SurfacePoly;
};

using namespace amilab;

AMI_DECLARE_TYPE(SurfacePoly)

template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<SurfacePoly>::CreateVar( ParamList* p, bool quiet );


class WrapClass_SurfacePoly : public WrapClass<SurfacePoly>
{
  DEFINE_CLASS(WrapClass_SurfacePoly);


  public:

    /// Constructor
    WrapClass_SurfacePoly(boost::shared_ptr<SurfacePoly> sp): 
      WrapClass<SurfacePoly>(sp) { }

    /// Constructor const
    WrapClass_SurfacePoly(boost::shared_ptr<SurfacePoly const> sp,bool): 
      WrapClass<SurfacePoly>(sp,true) { }

    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( SurfacePoly* sp);

   /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR( SurfacePoly, "Wrapping of SurfacePoly." );


    ADD_CLASS_METHOD(info,             "Prints information about the polygonal surface");
    ADD_CLASS_METHOD(save,             "Saves to disk.");
    ADD_CLASS_METHOD(Read,             "Reads from disk.");
    ADD_CLASS_METHOD(WriteCTALine,     "Saves the first line of the polydata in ASCII format.");
    ADD_CLASS_METHOD(OwnMaterial,      "Sets OwnMaterial OpenGL property.");
    ADD_CLASS_METHOD(SetAmbient,       "Sets Ambient color.");
    ADD_CLASS_METHOD(SetDiffuse,       "Sets Diffuse color.");
    ADD_CLASS_METHOD(SetSpecular,      "Sets Specular color.");
    ADD_CLASS_METHOD(SetShininess,     "Sets Shininess.");
    ADD_CLASS_METHOD(SetOpacity,       "Sets Opacity.");
    ADD_CLASS_METHOD(SetVisible,       "Sets the object visible or not visible in the scene.");
    ADD_CLASS_METHOD(SetColorMaterial, "Enable/Disable colormaterial for the associated surface.");
    ADD_CLASS_METHOD(SetColorOpacity,  "Define the transparency to the RGB color associated per each vertex (actived with Enable ColorMaterial).");
    ADD_CLASS_METHOD(SetColor,         "Sets all points to the given RGB color and activates colormaterial, or uses an image to set the colors.");
    ADD_CLASS_METHOD(SetPointsColors,  "Sets the colors based on a 1D image (RGB or greyscale) of size the number of points.");
    ADD_CLASS_METHOD(SetColors,        "Sets the colors based on a 3D image (RGB or greyscale).");
    ADD_CLASS_METHOD(Statistics,       "Displays the statistics of the input image at the position of the vertices.");
    ADD_CLASS_METHOD(MergePoints,      "Merges the points which distance is smaller than dist");
    ADD_CLASS_METHOD(Triangulate,      "Triangulates the surface.");
    ADD_CLASS_METHOD(Curvatures,       "Computes the principal curvatues at vertex positions and save the results in different images.");
    ADD_CLASS_METHOD(Displace,         "Displaces each point in the normal direction with a distance given by the image.");
    ADD_CLASS_METHOD(Translate,        "Translates the polydata.");
    ADD_CLASS_METHOD(Scale,            "Scales the polydata.");
    ADD_CLASS_METHOD(SetLineWidth,     "Sets the width of the lines.");
    ADD_CLASS_METHOD(RemoveLine,       "Removes one line and recomputes the GL list.");
    ADD_CLASS_METHOD(SelectLines,      "Selects lines based on an image and recomputes the GL list.\n\
        The image is 1D of size the number of lines\n\
        if the value is > 0.5, then select the corresponding line.");
    ADD_CLASS_METHOD(RemoveSelection,  "Removes selected lines and recomputes de GL list.");
    ADD_CLASS_METHOD(Recompute,        "Recomputes OpenGL list.");
    ADD_CLASS_METHOD(Normals,          "Recomputes the normals of the surface.");
    ADD_CLASS_METHOD(InvertNormals,    "Inverts the normals of the surface.");
    ADD_CLASS_METHOD(vtkSmooth,        "Smoothes the surface applying the vtkSmooth filter.");
    ADD_CLASS_METHOD(vtkWindowedSinc,  "Smoothes the surface applying the vtkWindowedSinc filter.");
    ADD_CLASS_METHOD(vtkDecimate,      "Decimates the surface using vtkDecimate filter.");
    ADD_CLASS_METHOD(setminCC,         "Sets a threshold for drawing connected components bigger that it.");
    ADD_CLASS_METHOD(drawCC,           "Draws one connected component only (if one parameter), Activates/Desactivates Drawing of one connected components (if two parameters.)");
    ADD_CLASS_METHOD(AddPoint,         "Adds a new point to the polydata.");
    ADD_CLASS_METHOD(NewLine,          "Adds a new line to the polydata.");
    ADD_CLASS_METHOD(LineAddPointNumber, "Adds a point to a given line.");
    ADD_CLASS_METHOD(EndLine,          "Ends the definition of a line.");
    ADD_CLASS_METHOD(ElevateMesh,      "        ElevateMesh can have different behaviors depending on the type of\n\
        the input image. In any case, it scans all the points of the mesh,\n\
        and uses their 2 first coordinates (x,y) to deduce a position in\n\
        the input image, and interpolate a value.\n\
          - if the image is scalar, the value of the image at position\n\
          (x,y) is used to set the elevation of the mesh (z coordinate).\n\
          - if the image contains 2D vectors, the vectors are used to set\n\
          the (x,y) coordinates of each vertex of the mesh.\n\
          - if the image contains 3D vectors, those vectors are used\n\
          to set new positions (x,y,z) for each vertex of the mesh.");
    ADD_CLASS_METHOD(NbPoints,         "Returns the total number of points.");
    ADD_CLASS_METHOD(NbPolys,          "Returns the total number of polygons.");
    ADD_CLASS_METHOD(GetNumberOfLines, "Returns the total number of lines.");
    ADD_CLASS_METHOD(GetLinesLength,   "Returns a 1D image containing the length of all the lines.");
    ADD_CLASS_METHOD(GetLine,          "Gets the points of the given line as a vectorial 1D image of the point positions.");
    ADD_CLASS_METHOD(GetLinesExtremities, "        Returns an image Mx2 where M is the number of lines and \n\
        containing the point id of the 2 extremities of each line");
    ADD_CLASS_METHOD(GetConnections,   "Get the number of lines connected to each point.\n\
        The result is given as a 1D image of size the total\n\
        number of points of the polydata");
    ADD_CLASS_METHOD(GetIntensities,   "Get the intensities of an image at the position of the polydata vertices.");
    ADD_CLASS_METHOD(ConnectLines,     "Connects close lines based on several criteria.");


    ADD_CLASS_METHOD(copy,            "Copy of the Surface.");
    ADD_CLASS_METHOD(left_assign,     "Operator <<=, forces assignation of a new surface.");
    ADD_CLASS_METHOD(assign,          "Operator =, copy assignment.");

    void AddMethods(WrapClass<SurfacePoly>::ptr this_ptr )
    {
      AddVar_info(   this_ptr, "_info"); // avoid pb with token 'info'
      AddVar_save(   this_ptr, "_save"); // avoid pb with token 'save'

      AddVar_Read(         this_ptr);
      AddVar_WriteCTALine( this_ptr);
      AddVar_OwnMaterial(  this_ptr);
      AddVar_SetAmbient(   this_ptr);
      AddVar_SetDiffuse(   this_ptr);
      AddVar_SetSpecular(  this_ptr);
      AddVar_SetShininess( this_ptr);
      AddVar_SetOpacity(   this_ptr);
      AddVar_SetVisible(   this_ptr);
      AddVar_SetColorMaterial( this_ptr);
      AddVar_SetColorOpacity(  this_ptr);
      AddVar_SetColor(         this_ptr);
      AddVar_SetPointsColors(  this_ptr);
      AddVar_SetColors(        this_ptr);
      AddVar_Statistics(       this_ptr);
      AddVar_MergePoints(      this_ptr);
      AddVar_Triangulate(      this_ptr);
      AddVar_Curvatures(         this_ptr, "_Curvatures");
      AddVar_Displace(           this_ptr);
      AddVar_Translate(          this_ptr);
      AddVar_Scale(              this_ptr);
      AddVar_SetLineWidth(       this_ptr);
      AddVar_RemoveLine(         this_ptr);
      AddVar_SelectLines(        this_ptr);
      AddVar_RemoveSelection(    this_ptr);
      AddVar_Recompute(          this_ptr);
      AddVar_Normals(            this_ptr);
      AddVar_InvertNormals(      this_ptr);
      AddVar_vtkSmooth(          this_ptr, "_vtkSmooth");
      AddVar_vtkWindowedSinc(    this_ptr, "_vtkWindowedSinc");
      AddVar_vtkDecimate(        this_ptr, "_vtkDecimate");
      AddVar_setminCC(           this_ptr);
      AddVar_drawCC(             this_ptr);
      AddVar_AddPoint(           this_ptr);
      AddVar_NewLine(            this_ptr);
      AddVar_LineAddPointNumber( this_ptr);
      AddVar_EndLine(            this_ptr);
      AddVar_ElevateMesh(        this_ptr);
      AddVar_NbPoints(           this_ptr);
      AddVar_NbPolys(            this_ptr);
      AddVar_GetNumberOfLines(   this_ptr);
      AddVar_GetLinesLength(     this_ptr);
      AddVar_GetLine(            this_ptr);
      AddVar_GetLinesExtremities( this_ptr);
      AddVar_GetConnections(      this_ptr);
      AddVar_GetIntensities(      this_ptr);
      AddVar_ConnectLines(        this_ptr);

      // Operators
      AddVar_copy(                this_ptr);
      AddVar_left_assign(         this_ptr);
      AddVar_assign(              this_ptr);

    }
};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassamilab__NS__SurfacePoly_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_SurfacePoly_h_
