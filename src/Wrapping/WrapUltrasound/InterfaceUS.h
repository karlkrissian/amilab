#ifndef _Interfaz_h_
#define _Interfaz_h_

/*  Cabecera del módulo de interfaz */
#include "RPCore.h"
#include "resource.h"	
#include <boost/shared_ptr.hpp>
class InrImage;


#ifdef __BORLANDC__
    #pragma hdrstop
#endif

// for all others, include the necessary headers (this file is usually all you
// need because it includes almost all "standard" wxWidgets headers)
#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif



/************** Nuevo tipo de marco (ventana), que será nuestro marco principal *****************/

class InterfaceUS : public wxFrame
{
public:
    // constructor
    InterfaceUS(const wxString& Dir);
    
    void Connect_Ultrasonix(const wxString& IP);
    void DisConnect_Ultrasonix();
    bool GetImage();
    bool IsImageCaptured(){return image_captured;};
    boost::shared_ptr<InrImage> ReadImage(){return Frame;}; 
    bool IsUltrasonixConnect(){return ultrasonix_conect;};

    

private:
    //Ultrasonido
    wxString Directory; //directorio donde guardar las imágenes
    CIRPRemoteControl m_rc;
    int ImageUltrasonixCount;
    TCHAR m_szImageType[5];	
    bool ultrasonix_conect;
    bool image_captured;
    boost::shared_ptr<InrImage> Frame;

    void RConnect_Ultrasonix(WXWPARAM wParam, WXLPARAM lparam);
    void RClose_Ultrasonix(WXWPARAM wParam, WXLPARAM lparam);
    void RCaptureImg_Ultrasonix(WXWPARAM wParam, WXLPARAM lparam);

    //Mapeo de mensajes de windows
    WXLRESULT MSWWindowProc(WXUINT message, WXWPARAM wParam, WXLPARAM lParam);
};

// IDs de los controles de menú
enum
{
  Submenu_Start = wxID_HIGHEST + 1,  //Nuevos botones irán aumentando 
	Submenu_Stop = wxID_HIGHEST + 2,
 
  SConnect_Ultrasonix = wxID_HIGHEST + 5,
  SDisConnect_Ultrasonix = wxID_HIGHEST + 7,

  //Botones
  BStart = wxID_HIGHEST + 8,
 
 
};


#endif // _Interfaz_h_
