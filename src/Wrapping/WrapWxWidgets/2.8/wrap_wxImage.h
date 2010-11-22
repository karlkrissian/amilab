/**
 * C++ Interface: wrap_wxImage
 *
 * Description: wrapping wxImage
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxImage_h_
#define _wrap_wxImage_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxObject.h"


AMI_DECLARE_TYPE(wxImage);

// TODO: check for inheritence ...
class WrapClass_wxImage : public WrapClass<wxImage>
    , public   WrapClass_wxObject
{
  DEFINE_CLASS(WrapClass_wxImage);

  protected:
    typedef WrapClass<wxImage>::ptr _parentclass_ptr;
    typedef wxImage ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxImage>& GetObj() const { return WrapClass<wxImage>::GetObj(); }

    /// Constructor
    WrapClass_wxImage(boost::shared_ptr<wxImage > si): 
    WrapClass<wxImage>(si)
    , WrapClass_wxObject(si)
    {}

    /// Destructor
    ~WrapClass_wxImage()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxImage_1,"Constructor wxImage::wxImage(wxImage const & param0) (http://docs.wxwidgets.org/stable/wx_wximage.html#wximage).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxImage,"Constructor wxImage::wxImage() (http://docs.wxwidgets.org/stable/wx_wximage.html#wximage).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxImage_2,"Constructor wxImage::wxImage() (http://docs.wxwidgets.org/stable/wx_wximage.html#wximage).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxImage_3,"Constructor wxImage::wxImage(int width, int height, bool clear = true) (http://docs.wxwidgets.org/stable/wx_wximage.html#wximage).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxImage_4,"Constructor wxImage::wxImage(int width, int height, unsigned char * data, bool static_data = false) (http://docs.wxwidgets.org/stable/wx_wximage.html#wximage).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxImage_5,"Constructor wxImage::wxImage(int width, int height, unsigned char * data, unsigned char * alpha, bool static_data = false) (http://docs.wxwidgets.org/stable/wx_wximage.html#wximage).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxImage_6,"Constructor wxImage::wxImage(wxString const & name, long int type = wxBITMAP_TYPE_ANY, int index = -0x00000000000000001) (http://docs.wxwidgets.org/stable/wx_wximage.html#wximage).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxImage_7,"Constructor wxImage::wxImage(wxString const & name, wxString const & mimetype, int index = -0x00000000000000001) (http://docs.wxwidgets.org/stable/wx_wximage.html#wximage).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxImage_8,"Constructor wxImage::wxImage(char const * const * xpmData) (http://docs.wxwidgets.org/stable/wx_wximage.html#wximage).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxImage_9,"Constructor wxImage::wxImage(wxInputStream & stream, long int type = wxBITMAP_TYPE_ANY, int index = -0x00000000000000001) (http://docs.wxwidgets.org/stable/wx_wximage.html#wximage).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxImage_10,"Constructor wxImage::wxImage(wxInputStream & stream, wxString const & mimetype, int index = -0x00000000000000001) (http://docs.wxwidgets.org/stable/wx_wximage.html#wximage).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxImage*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(CanRead_1,"bool wxImage::CanRead(wxString const & name) (http://docs.wxwidgets.org/stable/wx_wximage.html#canread).");
    ADD_CLASS_STATICMETHOD(GetImageCount_1,"int wxImage::GetImageCount(wxString const & name, long int type = wxBITMAP_TYPE_ANY) (http://docs.wxwidgets.org/stable/wx_wximage.html#getimagecount).");
    ADD_CLASS_STATICMETHOD(CanRead,"wxImage::CanRead() (http://docs.wxwidgets.org/stable/wx_wximage.html#canread).");
    ADD_CLASS_STATICMETHOD(CanRead_2,"bool wxImage::CanRead(wxInputStream & stream) (http://docs.wxwidgets.org/stable/wx_wximage.html#canread).");
    ADD_CLASS_STATICMETHOD(GetImageCount,"wxImage::GetImageCount() (http://docs.wxwidgets.org/stable/wx_wximage.html#getimagecount).");
    ADD_CLASS_STATICMETHOD(GetImageCount_2,"int wxImage::GetImageCount(wxInputStream & stream, long int type = wxBITMAP_TYPE_ANY) (http://docs.wxwidgets.org/stable/wx_wximage.html#getimagecount).");
    ADD_CLASS_STATICMETHOD(GetHandlers,"wxList & wxImage::GetHandlers() (http://docs.wxwidgets.org/stable/wx_wximage.html#gethandlers).");
    ADD_CLASS_STATICMETHOD(AddHandler,"void wxImage::AddHandler(wxImageHandler * handler) (http://docs.wxwidgets.org/stable/wx_wximage.html#addhandler).");
    ADD_CLASS_STATICMETHOD(InsertHandler,"void wxImage::InsertHandler(wxImageHandler * handler) (http://docs.wxwidgets.org/stable/wx_wximage.html#inserthandler).");
    ADD_CLASS_STATICMETHOD(RemoveHandler,"bool wxImage::RemoveHandler(wxString const & name) (http://docs.wxwidgets.org/stable/wx_wximage.html#removehandler).");
    ADD_CLASS_STATICMETHOD(FindHandler_1,"wxImageHandler * wxImage::FindHandler(wxString const & name) (http://docs.wxwidgets.org/stable/wx_wximage.html#findhandler).");
    ADD_CLASS_STATICMETHOD(FindHandler,"wxImage::FindHandler() (http://docs.wxwidgets.org/stable/wx_wximage.html#findhandler).");
    ADD_CLASS_STATICMETHOD(FindHandler_2,"wxImageHandler * wxImage::FindHandler(wxString const & extension, long int imageType) (http://docs.wxwidgets.org/stable/wx_wximage.html#findhandler).");
    ADD_CLASS_STATICMETHOD(FindHandler_3,"wxImageHandler * wxImage::FindHandler(long int imageType) (http://docs.wxwidgets.org/stable/wx_wximage.html#findhandler).");
    ADD_CLASS_STATICMETHOD(FindHandlerMime,"wxImageHandler * wxImage::FindHandlerMime(wxString const & mimetype) (http://docs.wxwidgets.org/stable/wx_wximage.html#findhandlermime).");
    ADD_CLASS_STATICMETHOD(GetImageExtWildcard,"wxString wxImage::GetImageExtWildcard() (http://docs.wxwidgets.org/stable/wx_wximage.html#getimageextwildcard).");
    ADD_CLASS_STATICMETHOD(CleanUpHandlers,"void wxImage::CleanUpHandlers() (http://docs.wxwidgets.org/stable/wx_wximage.html#cleanuphandlers).");
    ADD_CLASS_STATICMETHOD(InitStandardHandlers,"void wxImage::InitStandardHandlers() (http://docs.wxwidgets.org/stable/wx_wximage.html#initstandardhandlers).");
    /* The following types are missing: HSVValue, RGBValue
    ADD_CLASS_STATICMETHOD(RGBtoHSV,"HSVValue wxImage::RGBtoHSV(RGBValue const & rgb) (http://docs.wxwidgets.org/stable/wx_wximage.html#rgbtohsv).");
    */
    /* The following types are missing: RGBValue, HSVValue
    ADD_CLASS_STATICMETHOD(HSVtoRGB,"RGBValue wxImage::HSVtoRGB(HSVValue const & hsv) (http://docs.wxwidgets.org/stable/wx_wximage.html#hsvtorgb).");
    */



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(Create_1,"bool wxImage::Create(int width, int height, bool clear = true)  (http://docs.wxwidgets.org/stable/wx_wximage.html#create)")
    ADD_CLASS_METHOD(Create,"wxImage::Create()  (http://docs.wxwidgets.org/stable/wx_wximage.html#create)")
    ADD_CLASS_METHOD(Create_2,"bool wxImage::Create(int width, int height, unsigned char * data, bool static_data = false)  (http://docs.wxwidgets.org/stable/wx_wximage.html#create)")
    ADD_CLASS_METHOD(Create_3,"bool wxImage::Create(int width, int height, unsigned char * data, unsigned char * alpha, bool static_data = false)  (http://docs.wxwidgets.org/stable/wx_wximage.html#create)")
    ADD_CLASS_METHOD(Create_4,"bool wxImage::Create(char const * const * xpmData)  (http://docs.wxwidgets.org/stable/wx_wximage.html#create)")
    ADD_CLASS_METHOD(Destroy,"void wxImage::Destroy()  (http://docs.wxwidgets.org/stable/wx_wximage.html#destroy)")
    ADD_CLASS_METHOD(Copy,"wxImage wxImage::Copy()  (http://docs.wxwidgets.org/stable/wx_wximage.html#copy)")
    ADD_CLASS_METHOD(GetSubImage,"wxImage wxImage::GetSubImage(wxRect const & rect)  (http://docs.wxwidgets.org/stable/wx_wximage.html#getsubimage)")
    ADD_CLASS_METHOD(Size,"wxImage wxImage::Size(wxSize const & size, wxPoint const & pos, int r = -0x00000000000000001, int g = -0x00000000000000001, int b = -0x00000000000000001)  (http://docs.wxwidgets.org/stable/wx_wximage.html#size)")
    ADD_CLASS_METHOD(Paste,"void wxImage::Paste(wxImage const & image, int x, int y)  (http://docs.wxwidgets.org/stable/wx_wximage.html#paste)")
    ADD_CLASS_METHOD(Scale,"wxImage wxImage::Scale(int width, int height, int quality = wxIMAGE_QUALITY_NORMAL)  (http://docs.wxwidgets.org/stable/wx_wximage.html#scale)")
    ADD_CLASS_METHOD(ResampleBox,"wxImage wxImage::ResampleBox(int width, int height)  (http://docs.wxwidgets.org/stable/wx_wximage.html#resamplebox)")
    ADD_CLASS_METHOD(ResampleBicubic,"wxImage wxImage::ResampleBicubic(int width, int height)  (http://docs.wxwidgets.org/stable/wx_wximage.html#resamplebicubic)")
    ADD_CLASS_METHOD(Blur,"wxImage wxImage::Blur(int radius)  (http://docs.wxwidgets.org/stable/wx_wximage.html#blur)")
    ADD_CLASS_METHOD(BlurHorizontal,"wxImage wxImage::BlurHorizontal(int radius)  (http://docs.wxwidgets.org/stable/wx_wximage.html#blurhorizontal)")
    ADD_CLASS_METHOD(BlurVertical,"wxImage wxImage::BlurVertical(int radius)  (http://docs.wxwidgets.org/stable/wx_wximage.html#blurvertical)")
    ADD_CLASS_METHOD(ShrinkBy,"wxImage wxImage::ShrinkBy(int xFactor, int yFactor)  (http://docs.wxwidgets.org/stable/wx_wximage.html#shrinkby)")
    ADD_CLASS_METHOD(Rescale,"wxImage & wxImage::Rescale(int width, int height, int quality = wxIMAGE_QUALITY_NORMAL)  (http://docs.wxwidgets.org/stable/wx_wximage.html#rescale)")
    ADD_CLASS_METHOD(Resize,"wxImage & wxImage::Resize(wxSize const & size, wxPoint const & pos, int r = -0x00000000000000001, int g = -0x00000000000000001, int b = -0x00000000000000001)  (http://docs.wxwidgets.org/stable/wx_wximage.html#resize)")
    ADD_CLASS_METHOD(Rotate,"wxImage wxImage::Rotate(double angle, wxPoint const & centre_of_rotation, bool interpolating = true, wxPoint * offset_after_rotation = 0u)  (http://docs.wxwidgets.org/stable/wx_wximage.html#rotate)")
    ADD_CLASS_METHOD(Rotate90,"wxImage wxImage::Rotate90(bool clockwise = true)  (http://docs.wxwidgets.org/stable/wx_wximage.html#rotate90)")
    ADD_CLASS_METHOD(Mirror,"wxImage wxImage::Mirror(bool horizontally = true)  (http://docs.wxwidgets.org/stable/wx_wximage.html#mirror)")
    ADD_CLASS_METHOD(Replace,"void wxImage::Replace(unsigned char r1, unsigned char g1, unsigned char b1, unsigned char r2, unsigned char g2, unsigned char b2)  (http://docs.wxwidgets.org/stable/wx_wximage.html#replace)")
    ADD_CLASS_METHOD(ConvertToGreyscale,"wxImage wxImage::ConvertToGreyscale(double lr = 2.98999999999999988009591334048309363424777984619140625e-1, double lg = 5.869999999999999662492200513952411711215972900390625e-1, double lb = 1.1400000000000000410782519111307919956743717193603515625e-1)  (http://docs.wxwidgets.org/stable/wx_wximage.html#converttogreyscale)")
    ADD_CLASS_METHOD(ConvertToMono,"wxImage wxImage::ConvertToMono(unsigned char r, unsigned char g, unsigned char b)  (http://docs.wxwidgets.org/stable/wx_wximage.html#converttomono)")
    ADD_CLASS_METHOD(SetRGB_1,"void wxImage::SetRGB(int x, int y, unsigned char r, unsigned char g, unsigned char b)  (http://docs.wxwidgets.org/stable/wx_wximage.html#setrgb)")
    ADD_CLASS_METHOD(SetRGB,"wxImage::SetRGB()  (http://docs.wxwidgets.org/stable/wx_wximage.html#setrgb)")
    ADD_CLASS_METHOD(SetRGB_2,"void wxImage::SetRGB(wxRect const & rect, unsigned char r, unsigned char g, unsigned char b)  (http://docs.wxwidgets.org/stable/wx_wximage.html#setrgb)")
    ADD_CLASS_METHOD(GetRed,"unsigned char wxImage::GetRed(int x, int y)  (http://docs.wxwidgets.org/stable/wx_wximage.html#getred)")
    ADD_CLASS_METHOD(GetGreen,"unsigned char wxImage::GetGreen(int x, int y)  (http://docs.wxwidgets.org/stable/wx_wximage.html#getgreen)")
    ADD_CLASS_METHOD(GetBlue,"unsigned char wxImage::GetBlue(int x, int y)  (http://docs.wxwidgets.org/stable/wx_wximage.html#getblue)")
    ADD_CLASS_METHOD(SetAlpha_1,"void wxImage::SetAlpha(int x, int y, unsigned char alpha)  (http://docs.wxwidgets.org/stable/wx_wximage.html#setalpha)")
    ADD_CLASS_METHOD(GetAlpha_1,"unsigned char wxImage::GetAlpha(int x, int y)  (http://docs.wxwidgets.org/stable/wx_wximage.html#getalpha)")
    ADD_CLASS_METHOD(FindFirstUnusedColour,"bool wxImage::FindFirstUnusedColour(unsigned char * r, unsigned char * g, unsigned char * b, unsigned char startR = 1, unsigned char startG = 0, unsigned char startB = 0)  (http://docs.wxwidgets.org/stable/wx_wximage.html#findfirstunusedcolour)")
    ADD_CLASS_METHOD(SetMaskFromImage,"bool wxImage::SetMaskFromImage(wxImage const & mask, unsigned char mr, unsigned char mg, unsigned char mb)  (http://docs.wxwidgets.org/stable/wx_wximage.html#setmaskfromimage)")
    ADD_CLASS_METHOD(ConvertAlphaToMask,"bool wxImage::ConvertAlphaToMask(unsigned char threshold = wxIMAGE_ALPHA_THRESHOLD)  (http://docs.wxwidgets.org/stable/wx_wximage.html#convertalphatomask)")
    ADD_CLASS_METHOD(ConvertColourToAlpha,"bool wxImage::ConvertColourToAlpha(unsigned char r, unsigned char g, unsigned char b)  (http://docs.wxwidgets.org/stable/wx_wximage.html#convertcolourtoalpha)")
    ADD_CLASS_METHOD(LoadFile_1,"bool wxImage::LoadFile(wxString const & name, long int type = wxBITMAP_TYPE_ANY, int index = -0x00000000000000001)  (http://docs.wxwidgets.org/stable/wx_wximage.html#loadfile)")
    ADD_CLASS_METHOD(LoadFile,"wxImage::LoadFile()  (http://docs.wxwidgets.org/stable/wx_wximage.html#loadfile)")
    ADD_CLASS_METHOD(LoadFile_2,"bool wxImage::LoadFile(wxString const & name, wxString const & mimetype, int index = -0x00000000000000001)  (http://docs.wxwidgets.org/stable/wx_wximage.html#loadfile)")
    ADD_CLASS_METHOD(LoadFile_3,"bool wxImage::LoadFile(wxInputStream & stream, long int type = wxBITMAP_TYPE_ANY, int index = -0x00000000000000001)  (http://docs.wxwidgets.org/stable/wx_wximage.html#loadfile)")
    ADD_CLASS_METHOD(LoadFile_4,"bool wxImage::LoadFile(wxInputStream & stream, wxString const & mimetype, int index = -0x00000000000000001)  (http://docs.wxwidgets.org/stable/wx_wximage.html#loadfile)")
    ADD_CLASS_METHOD(SaveFile_1,"bool wxImage::SaveFile(wxString const & name)  (http://docs.wxwidgets.org/stable/wx_wximage.html#savefile)")
    ADD_CLASS_METHOD(SaveFile,"wxImage::SaveFile()  (http://docs.wxwidgets.org/stable/wx_wximage.html#savefile)")
    ADD_CLASS_METHOD(SaveFile_2,"bool wxImage::SaveFile(wxString const & name, int type)  (http://docs.wxwidgets.org/stable/wx_wximage.html#savefile)")
    ADD_CLASS_METHOD(SaveFile_3,"bool wxImage::SaveFile(wxString const & name, wxString const & mimetype)  (http://docs.wxwidgets.org/stable/wx_wximage.html#savefile)")
    ADD_CLASS_METHOD(SaveFile_4,"bool wxImage::SaveFile(wxOutputStream & stream, int type)  (http://docs.wxwidgets.org/stable/wx_wximage.html#savefile)")
    ADD_CLASS_METHOD(SaveFile_5,"bool wxImage::SaveFile(wxOutputStream & stream, wxString const & mimetype)  (http://docs.wxwidgets.org/stable/wx_wximage.html#savefile)")
    ADD_CLASS_METHOD(Ok,"bool wxImage::Ok()  (http://docs.wxwidgets.org/stable/wx_wximage.html#ok)")
    ADD_CLASS_METHOD(IsOk,"bool wxImage::IsOk()  (http://docs.wxwidgets.org/stable/wx_wximage.html#isok)")
    ADD_CLASS_METHOD(GetWidth,"int wxImage::GetWidth()  (http://docs.wxwidgets.org/stable/wx_wximage.html#getwidth)")
    ADD_CLASS_METHOD(GetHeight,"int wxImage::GetHeight()  (http://docs.wxwidgets.org/stable/wx_wximage.html#getheight)")
    ADD_CLASS_METHOD(GetData,"unsigned char * wxImage::GetData()  (http://docs.wxwidgets.org/stable/wx_wximage.html#getdata)")
    ADD_CLASS_METHOD(SetData_1,"void wxImage::SetData(unsigned char * data, bool static_data = false)  (http://docs.wxwidgets.org/stable/wx_wximage.html#setdata)")
    ADD_CLASS_METHOD(SetData,"wxImage::SetData()  (http://docs.wxwidgets.org/stable/wx_wximage.html#setdata)")
    ADD_CLASS_METHOD(SetData_2,"void wxImage::SetData(unsigned char * data, int new_width, int new_height, bool static_data = false)  (http://docs.wxwidgets.org/stable/wx_wximage.html#setdata)")
    ADD_CLASS_METHOD(GetAlpha,"wxImage::GetAlpha()  (http://docs.wxwidgets.org/stable/wx_wximage.html#getalpha)")
    ADD_CLASS_METHOD(GetAlpha_2,"unsigned char * wxImage::GetAlpha()  (http://docs.wxwidgets.org/stable/wx_wximage.html#getalpha)")
    ADD_CLASS_METHOD(HasAlpha,"bool wxImage::HasAlpha()  (http://docs.wxwidgets.org/stable/wx_wximage.html#hasalpha)")
    ADD_CLASS_METHOD(SetAlpha,"wxImage::SetAlpha()  (http://docs.wxwidgets.org/stable/wx_wximage.html#setalpha)")
    ADD_CLASS_METHOD(SetAlpha_2,"void wxImage::SetAlpha(unsigned char * alpha = 0l, bool static_data = false)  (http://docs.wxwidgets.org/stable/wx_wximage.html#setalpha)")
    ADD_CLASS_METHOD(InitAlpha,"void wxImage::InitAlpha()  (http://docs.wxwidgets.org/stable/wx_wximage.html#initalpha)")
    ADD_CLASS_METHOD(IsTransparent,"bool wxImage::IsTransparent(int x, int y, unsigned char threshold = wxIMAGE_ALPHA_THRESHOLD)  (http://docs.wxwidgets.org/stable/wx_wximage.html#istransparent)")
    ADD_CLASS_METHOD(SetMaskColour,"void wxImage::SetMaskColour(unsigned char r, unsigned char g, unsigned char b)  (http://docs.wxwidgets.org/stable/wx_wximage.html#setmaskcolour)")
    ADD_CLASS_METHOD(GetOrFindMaskColour,"bool wxImage::GetOrFindMaskColour(unsigned char * r, unsigned char * g, unsigned char * b)  (http://docs.wxwidgets.org/stable/wx_wximage.html#getorfindmaskcolour)")
    ADD_CLASS_METHOD(GetMaskRed,"unsigned char wxImage::GetMaskRed()  (http://docs.wxwidgets.org/stable/wx_wximage.html#getmaskred)")
    ADD_CLASS_METHOD(GetMaskGreen,"unsigned char wxImage::GetMaskGreen()  (http://docs.wxwidgets.org/stable/wx_wximage.html#getmaskgreen)")
    ADD_CLASS_METHOD(GetMaskBlue,"unsigned char wxImage::GetMaskBlue()  (http://docs.wxwidgets.org/stable/wx_wximage.html#getmaskblue)")
    ADD_CLASS_METHOD(SetMask,"void wxImage::SetMask(bool mask = true)  (http://docs.wxwidgets.org/stable/wx_wximage.html#setmask)")
    ADD_CLASS_METHOD(HasMask,"bool wxImage::HasMask()  (http://docs.wxwidgets.org/stable/wx_wximage.html#hasmask)")
    ADD_CLASS_METHOD(HasPalette,"bool wxImage::HasPalette()  (http://docs.wxwidgets.org/stable/wx_wximage.html#haspalette)")
    ADD_CLASS_METHOD(GetPalette,"wxPalette const & wxImage::GetPalette()  (http://docs.wxwidgets.org/stable/wx_wximage.html#getpalette)")
    ADD_CLASS_METHOD(SetPalette,"void wxImage::SetPalette(wxPalette const & palette)  (http://docs.wxwidgets.org/stable/wx_wximage.html#setpalette)")
    ADD_CLASS_METHOD(SetOption_1,"void wxImage::SetOption(wxString const & name, wxString const & value)  (http://docs.wxwidgets.org/stable/wx_wximage.html#setoption)")
    ADD_CLASS_METHOD(SetOption,"wxImage::SetOption()  (http://docs.wxwidgets.org/stable/wx_wximage.html#setoption)")
    ADD_CLASS_METHOD(SetOption_2,"void wxImage::SetOption(wxString const & name, int value)  (http://docs.wxwidgets.org/stable/wx_wximage.html#setoption)")
    ADD_CLASS_METHOD(GetOption,"wxString wxImage::GetOption(wxString const & name)  (http://docs.wxwidgets.org/stable/wx_wximage.html#getoption)")
    ADD_CLASS_METHOD(GetOptionInt,"int wxImage::GetOptionInt(wxString const & name)  (http://docs.wxwidgets.org/stable/wx_wximage.html#getoptionint)")
    ADD_CLASS_METHOD(HasOption,"bool wxImage::HasOption(wxString const & name)  (http://docs.wxwidgets.org/stable/wx_wximage.html#hasoption)")
    ADD_CLASS_METHOD(CountColours,"long unsigned int wxImage::CountColours(long unsigned int stopafter = -1ul)  (http://docs.wxwidgets.org/stable/wx_wximage.html#countcolours)")
    ADD_CLASS_METHOD(ComputeHistogram,"long unsigned int wxImage::ComputeHistogram(wxImageHistogram & h)  (http://docs.wxwidgets.org/stable/wx_wximage.html#computehistogram)")
    ADD_CLASS_METHOD(RotateHue,"void wxImage::RotateHue(double angle)  (http://docs.wxwidgets.org/stable/wx_wximage.html#rotatehue)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxImage::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wximage.html#getclassinfo)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxImage & wxImage::operator =(wxImage const & param0) (http://docs.wxwidgets.org/stable/wx_wximage.html#__assign__)")




    void AddMethods(WrapClass<wxImage>::ptr this_ptr );

};


#endif // _wrap_wxImage_h
