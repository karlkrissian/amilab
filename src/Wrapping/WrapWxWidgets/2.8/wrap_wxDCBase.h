/**
 * C++ Interface: wrap_wxDCBase
 *
 * Description: wrapping wxDCBase
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxDCBase_h_
#define _wrap_wxDCBase_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxObject.h"


AMI_DECLARE_TYPE(wxDCBase);

// TODO: check for inheritence ...
class WrapClass_wxDCBase : public WrapClass<wxDCBase>
    , public   WrapClass_wxObject
{
  DEFINE_CLASS(WrapClass_wxDCBase);

  protected:
    typedef WrapClass<wxDCBase>::ptr _parentclass_ptr;
    typedef wxDCBase ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxDCBase>& GetObj() const { return WrapClass<wxDCBase>::GetObj(); }

    /// Constructor
    WrapClass_wxDCBase(boost::shared_ptr<wxDCBase > si): 
    WrapClass<wxDCBase>(si)
    , WrapClass_wxObject(si)
    {}

    /// Destructor
    ~WrapClass_wxDCBase()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxDCBase*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(DrawObject,"void wxDCBase::DrawObject(wxDrawObject * drawobject)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawobject)")
    ADD_CLASS_METHOD(FloodFill_1,"bool wxDCBase::FloodFill(wxCoord x, wxCoord y, wxColour const & col, int style = wxFLOOD_SURFACE)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#floodfill)")
    ADD_CLASS_METHOD(FloodFill,"wxDCBase::FloodFill()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#floodfill)")
    ADD_CLASS_METHOD(FloodFill_2,"bool wxDCBase::FloodFill(wxPoint const & pt, wxColour const & col, int style = wxFLOOD_SURFACE)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#floodfill)")
    ADD_CLASS_METHOD(GradientFillConcentric_1,"void wxDCBase::GradientFillConcentric(wxRect const & rect, wxColour const & initialColour, wxColour const & destColour)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#gradientfillconcentric)")
    ADD_CLASS_METHOD(GradientFillConcentric,"wxDCBase::GradientFillConcentric()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#gradientfillconcentric)")
    ADD_CLASS_METHOD(GradientFillConcentric_2,"void wxDCBase::GradientFillConcentric(wxRect const & rect, wxColour const & initialColour, wxColour const & destColour, wxPoint const & circleCenter)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#gradientfillconcentric)")
    ADD_CLASS_METHOD(GradientFillLinear,"void wxDCBase::GradientFillLinear(wxRect const & rect, wxColour const & initialColour, wxColour const & destColour, wxDirection nDirection = wxRIGHT)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#gradientfilllinear)")
    ADD_CLASS_METHOD(GetPixel_1,"bool wxDCBase::GetPixel(wxCoord x, wxCoord y, wxColour * col)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#getpixel)")
    ADD_CLASS_METHOD(GetPixel,"wxDCBase::GetPixel()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#getpixel)")
    ADD_CLASS_METHOD(GetPixel_2,"bool wxDCBase::GetPixel(wxPoint const & pt, wxColour * col)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#getpixel)")
    ADD_CLASS_METHOD(DrawLine_1,"void wxDCBase::DrawLine(wxCoord x1, wxCoord y1, wxCoord x2, wxCoord y2)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawline)")
    ADD_CLASS_METHOD(DrawLine,"wxDCBase::DrawLine()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawline)")
    ADD_CLASS_METHOD(DrawLine_2,"void wxDCBase::DrawLine(wxPoint const & pt1, wxPoint const & pt2)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawline)")
    ADD_CLASS_METHOD(CrossHair_1,"void wxDCBase::CrossHair(wxCoord x, wxCoord y)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#crosshair)")
    ADD_CLASS_METHOD(CrossHair,"wxDCBase::CrossHair()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#crosshair)")
    ADD_CLASS_METHOD(CrossHair_2,"void wxDCBase::CrossHair(wxPoint const & pt)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#crosshair)")
    ADD_CLASS_METHOD(DrawArc_1,"void wxDCBase::DrawArc(wxCoord x1, wxCoord y1, wxCoord x2, wxCoord y2, wxCoord xc, wxCoord yc)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawarc)")
    ADD_CLASS_METHOD(DrawArc,"wxDCBase::DrawArc()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawarc)")
    ADD_CLASS_METHOD(DrawArc_2,"void wxDCBase::DrawArc(wxPoint const & pt1, wxPoint const & pt2, wxPoint const & centre)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawarc)")
    ADD_CLASS_METHOD(DrawCheckMark_1,"void wxDCBase::DrawCheckMark(wxCoord x, wxCoord y, wxCoord width, wxCoord height)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawcheckmark)")
    ADD_CLASS_METHOD(DrawCheckMark,"wxDCBase::DrawCheckMark()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawcheckmark)")
    ADD_CLASS_METHOD(DrawCheckMark_2,"void wxDCBase::DrawCheckMark(wxRect const & rect)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawcheckmark)")
    ADD_CLASS_METHOD(DrawEllipticArc_1,"void wxDCBase::DrawEllipticArc(wxCoord x, wxCoord y, wxCoord w, wxCoord h, double sa, double ea)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawellipticarc)")
    ADD_CLASS_METHOD(DrawEllipticArc,"wxDCBase::DrawEllipticArc()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawellipticarc)")
    ADD_CLASS_METHOD(DrawEllipticArc_2,"void wxDCBase::DrawEllipticArc(wxPoint const & pt, wxSize const & sz, double sa, double ea)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawellipticarc)")
    ADD_CLASS_METHOD(DrawPoint_1,"void wxDCBase::DrawPoint(wxCoord x, wxCoord y)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawpoint)")
    ADD_CLASS_METHOD(DrawPoint,"wxDCBase::DrawPoint()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawpoint)")
    ADD_CLASS_METHOD(DrawPoint_2,"void wxDCBase::DrawPoint(wxPoint const & pt)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawpoint)")
    ADD_CLASS_METHOD(DrawLines_1,"void wxDCBase::DrawLines(int n, wxPoint * points, wxCoord xoffset = 0, wxCoord yoffset = 0)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawlines)")
    ADD_CLASS_METHOD(DrawLines,"wxDCBase::DrawLines()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawlines)")
    ADD_CLASS_METHOD(DrawLines_2,"void wxDCBase::DrawLines(wxList const * list, wxCoord xoffset = 0, wxCoord yoffset = 0)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawlines)")
    ADD_CLASS_METHOD(DrawPolygon_1,"void wxDCBase::DrawPolygon(int n, wxPoint * points, wxCoord xoffset = 0, wxCoord yoffset = 0, int fillStyle = wxODDEVEN_RULE)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawpolygon)")
    ADD_CLASS_METHOD(DrawPolygon,"wxDCBase::DrawPolygon()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawpolygon)")
    ADD_CLASS_METHOD(DrawPolygon_2,"void wxDCBase::DrawPolygon(wxList const * list, wxCoord xoffset = 0, wxCoord yoffset = 0, int fillStyle = wxODDEVEN_RULE)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawpolygon)")
    ADD_CLASS_METHOD(DrawPolyPolygon,"void wxDCBase::DrawPolyPolygon(int n, int * count, wxPoint * points, wxCoord xoffset = 0, wxCoord yoffset = 0, int fillStyle = wxODDEVEN_RULE)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawpolypolygon)")
    ADD_CLASS_METHOD(DrawRectangle_1,"void wxDCBase::DrawRectangle(wxCoord x, wxCoord y, wxCoord width, wxCoord height)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawrectangle)")
    ADD_CLASS_METHOD(DrawRectangle,"wxDCBase::DrawRectangle()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawrectangle)")
    ADD_CLASS_METHOD(DrawRectangle_2,"void wxDCBase::DrawRectangle(wxPoint const & pt, wxSize const & sz)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawrectangle)")
    ADD_CLASS_METHOD(DrawRectangle_3,"void wxDCBase::DrawRectangle(wxRect const & rect)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawrectangle)")
    ADD_CLASS_METHOD(DrawRoundedRectangle_1,"void wxDCBase::DrawRoundedRectangle(wxCoord x, wxCoord y, wxCoord width, wxCoord height, double radius)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawroundedrectangle)")
    ADD_CLASS_METHOD(DrawRoundedRectangle,"wxDCBase::DrawRoundedRectangle()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawroundedrectangle)")
    ADD_CLASS_METHOD(DrawRoundedRectangle_2,"void wxDCBase::DrawRoundedRectangle(wxPoint const & pt, wxSize const & sz, double radius)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawroundedrectangle)")
    ADD_CLASS_METHOD(DrawRoundedRectangle_3,"void wxDCBase::DrawRoundedRectangle(wxRect const & r, double radius)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawroundedrectangle)")
    ADD_CLASS_METHOD(DrawCircle_1,"void wxDCBase::DrawCircle(wxCoord x, wxCoord y, wxCoord radius)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawcircle)")
    ADD_CLASS_METHOD(DrawCircle,"wxDCBase::DrawCircle()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawcircle)")
    ADD_CLASS_METHOD(DrawCircle_2,"void wxDCBase::DrawCircle(wxPoint const & pt, wxCoord radius)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawcircle)")
    ADD_CLASS_METHOD(DrawEllipse_1,"void wxDCBase::DrawEllipse(wxCoord x, wxCoord y, wxCoord width, wxCoord height)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawellipse)")
    ADD_CLASS_METHOD(DrawEllipse,"wxDCBase::DrawEllipse()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawellipse)")
    ADD_CLASS_METHOD(DrawEllipse_2,"void wxDCBase::DrawEllipse(wxPoint const & pt, wxSize const & sz)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawellipse)")
    ADD_CLASS_METHOD(DrawEllipse_3,"void wxDCBase::DrawEllipse(wxRect const & rect)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawellipse)")
    ADD_CLASS_METHOD(DrawIcon_1,"void wxDCBase::DrawIcon(wxIcon const & icon, wxCoord x, wxCoord y)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawicon)")
    ADD_CLASS_METHOD(DrawIcon,"wxDCBase::DrawIcon()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawicon)")
    ADD_CLASS_METHOD(DrawIcon_2,"void wxDCBase::DrawIcon(wxIcon const & icon, wxPoint const & pt)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawicon)")
    ADD_CLASS_METHOD(DrawBitmap_1,"void wxDCBase::DrawBitmap(wxBitmap const & bmp, wxCoord x, wxCoord y, bool useMask = false)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawbitmap)")
    ADD_CLASS_METHOD(DrawBitmap,"wxDCBase::DrawBitmap()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawbitmap)")
    ADD_CLASS_METHOD(DrawBitmap_2,"void wxDCBase::DrawBitmap(wxBitmap const & bmp, wxPoint const & pt, bool useMask = false)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawbitmap)")
    ADD_CLASS_METHOD(DrawText_1,"void wxDCBase::DrawText(wxString const & text, wxCoord x, wxCoord y)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawtext)")
    ADD_CLASS_METHOD(DrawText,"wxDCBase::DrawText()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawtext)")
    ADD_CLASS_METHOD(DrawText_2,"void wxDCBase::DrawText(wxString const & text, wxPoint const & pt)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawtext)")
    ADD_CLASS_METHOD(DrawRotatedText_1,"void wxDCBase::DrawRotatedText(wxString const & text, wxCoord x, wxCoord y, double angle)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawrotatedtext)")
    ADD_CLASS_METHOD(DrawRotatedText,"wxDCBase::DrawRotatedText()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawrotatedtext)")
    ADD_CLASS_METHOD(DrawRotatedText_2,"void wxDCBase::DrawRotatedText(wxString const & text, wxPoint const & pt, double angle)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawrotatedtext)")
    ADD_CLASS_METHOD(DrawLabel_1,"void wxDCBase::DrawLabel(wxString const & text, wxBitmap const & image, wxRect const & rect, int alignment = 0, int indexAccel = -0x00000000000000001, wxRect * rectBounding = 0l)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawlabel)")
    ADD_CLASS_METHOD(DrawLabel,"wxDCBase::DrawLabel()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawlabel)")
    ADD_CLASS_METHOD(DrawLabel_2,"void wxDCBase::DrawLabel(wxString const & text, wxRect const & rect, int alignment = 0, int indexAccel = -0x00000000000000001)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawlabel)")
    ADD_CLASS_METHOD(Blit_1,"bool wxDCBase::Blit(wxCoord xdest, wxCoord ydest, wxCoord width, wxCoord height, wxDC * source, wxCoord xsrc, wxCoord ysrc, int rop = wxCOPY, bool useMask = false, wxCoord xsrcMask = wxDefaultCoord, wxCoord ysrcMask = wxDefaultCoord)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#blit)")
    ADD_CLASS_METHOD(Blit,"wxDCBase::Blit()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#blit)")
    ADD_CLASS_METHOD(Blit_2,"bool wxDCBase::Blit(wxPoint const & destPt, wxSize const & sz, wxDC * source, wxPoint const & srcPt, int rop = wxCOPY, bool useMask = false, wxPoint const & srcPtMask = wxDefaultPosition)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#blit)")
    ADD_CLASS_METHOD(GetAsBitmap,"wxBitmap wxDCBase::GetAsBitmap(wxRect const * subrect = 0u)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#getasbitmap)")
    ADD_CLASS_METHOD(DrawSpline_1,"void wxDCBase::DrawSpline(wxCoord x1, wxCoord y1, wxCoord x2, wxCoord y2, wxCoord x3, wxCoord y3)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawspline)")
    ADD_CLASS_METHOD(DrawSpline,"wxDCBase::DrawSpline()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawspline)")
    ADD_CLASS_METHOD(DrawSpline_2,"void wxDCBase::DrawSpline(int n, wxPoint * points)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawspline)")
    ADD_CLASS_METHOD(DrawSpline_3,"void wxDCBase::DrawSpline(wxList * points)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#drawspline)")
    ADD_CLASS_METHOD(StartDoc,"bool wxDCBase::StartDoc(wxString const & param0)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#startdoc)")
    ADD_CLASS_METHOD(EndDoc,"void wxDCBase::EndDoc()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#enddoc)")
    ADD_CLASS_METHOD(StartPage,"void wxDCBase::StartPage()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#startpage)")
    ADD_CLASS_METHOD(EndPage,"void wxDCBase::EndPage()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#endpage)")
    ADD_CLASS_METHOD(BeginDrawing,"void wxDCBase::BeginDrawing()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#begindrawing)")
    ADD_CLASS_METHOD(EndDrawing,"void wxDCBase::EndDrawing()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#enddrawing)")
    ADD_CLASS_METHOD(SetClippingRegion_1,"void wxDCBase::SetClippingRegion(wxCoord x, wxCoord y, wxCoord width, wxCoord height)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#setclippingregion)")
    ADD_CLASS_METHOD(SetClippingRegion,"wxDCBase::SetClippingRegion()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#setclippingregion)")
    ADD_CLASS_METHOD(SetClippingRegion_2,"void wxDCBase::SetClippingRegion(wxPoint const & pt, wxSize const & sz)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#setclippingregion)")
    ADD_CLASS_METHOD(SetClippingRegion_3,"void wxDCBase::SetClippingRegion(wxRect const & rect)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#setclippingregion)")
    ADD_CLASS_METHOD(SetClippingRegion_4,"void wxDCBase::SetClippingRegion(wxRegion const & region)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#setclippingregion)")
    ADD_CLASS_METHOD(SetDeviceClippingRegion,"void wxDCBase::SetDeviceClippingRegion(wxRegion const & region)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#setdeviceclippingregion)")
    ADD_CLASS_METHOD(DestroyClippingRegion,"void wxDCBase::DestroyClippingRegion()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#destroyclippingregion)")
    ADD_CLASS_METHOD(GetClippingBox_1,"void wxDCBase::GetClippingBox(wxCoord * x, wxCoord * y, wxCoord * w, wxCoord * h)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#getclippingbox)")
    ADD_CLASS_METHOD(GetClippingBox,"wxDCBase::GetClippingBox()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#getclippingbox)")
    ADD_CLASS_METHOD(GetClippingBox_2,"void wxDCBase::GetClippingBox(wxRect & rect)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#getclippingbox)")
    ADD_CLASS_METHOD(GetTextExtent_1,"void wxDCBase::GetTextExtent(wxString const & string, wxCoord * x, wxCoord * y, wxCoord * descent = 0l, wxCoord * externalLeading = 0l, wxFont * theFont = 0l)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#gettextextent)")
    ADD_CLASS_METHOD(GetTextExtent,"wxDCBase::GetTextExtent()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#gettextextent)")
    ADD_CLASS_METHOD(GetTextExtent_2,"wxSize wxDCBase::GetTextExtent(wxString const & string)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#gettextextent)")
    ADD_CLASS_METHOD(GetMultiLineTextExtent_1,"void wxDCBase::GetMultiLineTextExtent(wxString const & string, wxCoord * width, wxCoord * height, wxCoord * heightLine = 0l, wxFont * font = 0l)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#getmultilinetextextent)")
    ADD_CLASS_METHOD(GetMultiLineTextExtent,"wxDCBase::GetMultiLineTextExtent()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#getmultilinetextextent)")
    ADD_CLASS_METHOD(GetMultiLineTextExtent_2,"wxSize wxDCBase::GetMultiLineTextExtent(wxString const & string)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#getmultilinetextextent)")
    ADD_CLASS_METHOD(GetPartialTextExtents,"bool wxDCBase::GetPartialTextExtents(wxString const & text, wxArrayInt & widths)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#getpartialtextextents)")
    ADD_CLASS_METHOD(GetSize_1,"void wxDCBase::GetSize(int * width, int * height)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#getsize)")
    ADD_CLASS_METHOD(GetSize,"wxDCBase::GetSize()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#getsize)")
    ADD_CLASS_METHOD(GetSize_2,"wxSize wxDCBase::GetSize()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#getsize)")
    ADD_CLASS_METHOD(GetSizeMM_1,"void wxDCBase::GetSizeMM(int * width, int * height)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#getsizemm)")
    ADD_CLASS_METHOD(GetSizeMM,"wxDCBase::GetSizeMM()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#getsizemm)")
    ADD_CLASS_METHOD(GetSizeMM_2,"wxSize wxDCBase::GetSizeMM()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#getsizemm)")
    ADD_CLASS_METHOD(DeviceToLogicalX,"wxCoord wxDCBase::DeviceToLogicalX(wxCoord x)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#devicetologicalx)")
    ADD_CLASS_METHOD(DeviceToLogicalY,"wxCoord wxDCBase::DeviceToLogicalY(wxCoord y)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#devicetologicaly)")
    ADD_CLASS_METHOD(DeviceToLogicalXRel,"wxCoord wxDCBase::DeviceToLogicalXRel(wxCoord x)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#devicetologicalxrel)")
    ADD_CLASS_METHOD(DeviceToLogicalYRel,"wxCoord wxDCBase::DeviceToLogicalYRel(wxCoord y)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#devicetologicalyrel)")
    ADD_CLASS_METHOD(LogicalToDeviceX,"wxCoord wxDCBase::LogicalToDeviceX(wxCoord x)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#logicaltodevicex)")
    ADD_CLASS_METHOD(LogicalToDeviceY,"wxCoord wxDCBase::LogicalToDeviceY(wxCoord y)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#logicaltodevicey)")
    ADD_CLASS_METHOD(LogicalToDeviceXRel,"wxCoord wxDCBase::LogicalToDeviceXRel(wxCoord x)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#logicaltodevicexrel)")
    ADD_CLASS_METHOD(LogicalToDeviceYRel,"wxCoord wxDCBase::LogicalToDeviceYRel(wxCoord y)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#logicaltodeviceyrel)")
    ADD_CLASS_METHOD(Ok,"bool wxDCBase::Ok()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#ok)")
    ADD_CLASS_METHOD(IsOk,"bool wxDCBase::IsOk()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#isok)")
    ADD_CLASS_METHOD(GetBackgroundMode,"int wxDCBase::GetBackgroundMode()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#getbackgroundmode)")
    ADD_CLASS_METHOD(GetBackground,"wxBrush const & wxDCBase::GetBackground()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#getbackground)")
    ADD_CLASS_METHOD(GetBrush,"wxBrush const & wxDCBase::GetBrush()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#getbrush)")
    ADD_CLASS_METHOD(GetFont,"wxFont const & wxDCBase::GetFont()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#getfont)")
    ADD_CLASS_METHOD(GetPen,"wxPen const & wxDCBase::GetPen()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#getpen)")
    ADD_CLASS_METHOD(GetTextForeground,"wxColour const & wxDCBase::GetTextForeground()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#gettextforeground)")
    ADD_CLASS_METHOD(GetTextBackground,"wxColour const & wxDCBase::GetTextBackground()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#gettextbackground)")
    ADD_CLASS_METHOD(SetTextForeground,"void wxDCBase::SetTextForeground(wxColour const & colour)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#settextforeground)")
    ADD_CLASS_METHOD(SetTextBackground,"void wxDCBase::SetTextBackground(wxColour const & colour)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#settextbackground)")
    ADD_CLASS_METHOD(GetMapMode,"int wxDCBase::GetMapMode()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#getmapmode)")
    ADD_CLASS_METHOD(GetUserScale,"void wxDCBase::GetUserScale(double * x, double * y)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#getuserscale)")
    ADD_CLASS_METHOD(GetLogicalScale,"void wxDCBase::GetLogicalScale(double * x, double * y)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#getlogicalscale)")
    ADD_CLASS_METHOD(SetLogicalScale,"void wxDCBase::SetLogicalScale(double x, double y)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#setlogicalscale)")
    ADD_CLASS_METHOD(GetLogicalOrigin_1,"void wxDCBase::GetLogicalOrigin(wxCoord * x, wxCoord * y)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#getlogicalorigin)")
    ADD_CLASS_METHOD(GetLogicalOrigin,"wxDCBase::GetLogicalOrigin()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#getlogicalorigin)")
    ADD_CLASS_METHOD(GetLogicalOrigin_2,"wxPoint wxDCBase::GetLogicalOrigin()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#getlogicalorigin)")
    ADD_CLASS_METHOD(GetDeviceOrigin_1,"void wxDCBase::GetDeviceOrigin(wxCoord * x, wxCoord * y)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#getdeviceorigin)")
    ADD_CLASS_METHOD(GetDeviceOrigin,"wxDCBase::GetDeviceOrigin()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#getdeviceorigin)")
    ADD_CLASS_METHOD(GetDeviceOrigin_2,"wxPoint wxDCBase::GetDeviceOrigin()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#getdeviceorigin)")
    ADD_CLASS_METHOD(ComputeScaleAndOrigin,"void wxDCBase::ComputeScaleAndOrigin()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#computescaleandorigin)")
    ADD_CLASS_METHOD(GetLogicalFunction,"int wxDCBase::GetLogicalFunction()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#getlogicalfunction)")
    ADD_CLASS_METHOD(SetOptimization,"void wxDCBase::SetOptimization(bool param0)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#setoptimization)")
    ADD_CLASS_METHOD(GetOptimization,"bool wxDCBase::GetOptimization()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#getoptimization)")
    ADD_CLASS_METHOD(CalcBoundingBox,"void wxDCBase::CalcBoundingBox(wxCoord x, wxCoord y)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#calcboundingbox)")
    ADD_CLASS_METHOD(ResetBoundingBox,"void wxDCBase::ResetBoundingBox()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#resetboundingbox)")
    ADD_CLASS_METHOD(MinX,"wxCoord wxDCBase::MinX()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#minx)")
    ADD_CLASS_METHOD(MaxX,"wxCoord wxDCBase::MaxX()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#maxx)")
    ADD_CLASS_METHOD(MinY,"wxCoord wxDCBase::MinY()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#miny)")
    ADD_CLASS_METHOD(MaxY,"wxCoord wxDCBase::MaxY()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#maxy)")
    ADD_CLASS_METHOD(GetTextExtent_3,"void wxDCBase::GetTextExtent(wxString const & string, long int * x, long int * y, long int * descent = 0l, long int * externalLeading = 0l, wxFont * theFont = 0l)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#gettextextent)")
    ADD_CLASS_METHOD(GetLogicalOrigin_3,"void wxDCBase::GetLogicalOrigin(long int * x, long int * y)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#getlogicalorigin)")
    ADD_CLASS_METHOD(GetDeviceOrigin_3,"void wxDCBase::GetDeviceOrigin(long int * x, long int * y)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#getdeviceorigin)")
    ADD_CLASS_METHOD(GetClippingBox_3,"void wxDCBase::GetClippingBox(long int * x, long int * y, long int * w, long int * h)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#getclippingbox)")
    ADD_CLASS_METHOD(GetLayoutDirection,"wxLayoutDirection wxDCBase::GetLayoutDirection()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#getlayoutdirection)")
    ADD_CLASS_METHOD(SetLayoutDirection,"void wxDCBase::SetLayoutDirection(wxLayoutDirection param0)  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#setlayoutdirection)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxDCBase::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxdcbase.html#getclassinfo)")





    void AddMethods(WrapClass<wxDCBase>::ptr this_ptr );

};


#endif // _wrap_wxDCBase_h
