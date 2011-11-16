
// ============================================================================
// Declaraciones
// ============================================================================

// ----------------------------------------------------------------------------
// Cabeceras
// ----------------------------------------------------------------------------


#include "stdafx.h"
#include "InterfaceUS.h"
#include <iostream>
#include <fstream>
#include "wx/mstream.h"
#include "wx/stream.h"
#include <inrimage.hpp>



using namespace std;


// ----------------------------------------------------------------------------
// Ventana principal
// ----------------------------------------------------------------------------

// Cosntructor de la ventana principal
InterfaceUS::InterfaceUS(const wxString& Dir)
       : wxFrame(NULL, wxID_ANY, "",wxDefaultPosition,wxSize(1000,800))
{
    
  wxInitAllImageHandlers();

  // Crea los elementos de la barra de menú
  wxMenu *Menu = new wxMenu;
  wxMenu *Ultrasonix = new wxMenu;

  //Menú general
  Menu->Append(Submenu_Start, _T("&Start\tAlt-B"));
  Menu->Append(Submenu_Stop, _T("&Stop \tAlt-B"));
  Menu->AppendSeparator();

  //Menú ultrasonix
  Ultrasonix->Append(SConnect_Ultrasonix, _T("&Connect with ultrasonix"));
  Ultrasonix->Append(SDisConnect_Ultrasonix, _T("&Disconnect with ultrasonix"));


  // Asociamos el menú a la barra de menú
  wxMenuBar *menuBar = new wxMenuBar();
  menuBar->Append(Ultrasonix, _T("&Ultrasonix"));

  // ... enganchamos la barra de menú a la ventana
  SetMenuBar(menuBar);


  //Crear sizer y demás contenido interno
  wxBoxSizer* itemBoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
  SetSizer(itemBoxSizer9);

  wxButton* ButtonStart = new wxButton( this, BStart, _("Start"), wxDefaultPosition, wxDefaultSize, 0 );
  itemBoxSizer9->Add(ButtonStart, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

 
  ultrasonix_conect = false;
  // initialize sockets de ulrasonix
  if (!AfxSocketInit())
  {
  AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
  //return FALSE;
  }

  AfxEnableControlContainer();

  //Inicializar API máquina ultrasonidos
  if (!this->m_rc.Initialize((HWND)GetHWND()))
        wxMessageBox(wxString::Format(
                  _T("El control remoto no pudo ser inicializado\n")
               ),
               _T("Inicialización Ultrasonix"),
               wxOK | wxICON_ERROR ,
               this);
  else
     /*   wxMessageBox(wxString::Format(
                  _T("Inicialización de ultrasonix completada con éxito\n")
               ),
               _T("Inicialización Ultrasonix"),
               wxOK | wxICON_INFORMATION ,
               this);*/
  
  Directory = Dir;
}



void InterfaceUS::Connect_Ultrasonix(const wxString& IP)
{

   m_rc.Connect(IP);
  ImageUltrasonixCount = 0;
}

void InterfaceUS::DisConnect_Ultrasonix()
{
    this->m_rc.Disconnect();
}

bool InterfaceUS::GetImage()
{
  if(ultrasonix_conect)
  {
    //m_rc.getScreenCapture(RP_CAPTURE_DISPLAY,jpeg_e);
    image_captured = false;
  //  m_rc.getScreenCapture(RP_CAPTURE_PREMERGE | RP_CAPTURE_DISPLAY,jpeg_e);
 m_rc.getScreenCapture(RP_CAPTURE_PREMERGE | RP_CAPTURE_DISPLAY,png_e);
   // _tcscpy(m_szImageType, _T("jpg"));
 _tcscpy(m_szImageType, _T("png"));
    return true;
  }
  else return false;
}




//Funciones manejadores de los mensajes del servidor
void InterfaceUS::RConnect_Ultrasonix(WXWPARAM wParam, WXLPARAM lparam)
{

  if (wParam == RP_SUCCESS)
	{	// a successful connection
 /*   wxMessageBox(wxString::Format(
                    _T("Mensaje de confirmación de conexión recibido\n")
                 ),
                 _T("Conectando ultrasonix..."),
                 wxOK | wxICON_INFORMATION
             );*/
    ultrasonix_conect = true;
	}
	else	
      if (wParam == RP_ERROR)
        wxMessageBox(wxString::Format(
                    _T("Mensaje de error en conexión recibido\n")
                 ),
                 _T("Conectando ultrasonix..."),
                 wxOK | wxICON_INFORMATION
                 );
      else if (wParam == RP_INVALID)
      // the connection attempt was unsuccessfull, so close the connection
		    wxMessageBox(wxString::Format(
                    _T("Mensaje de objeto inválido en conexión recibido\n")
                 ),
                 _T("Conectando ultrasonix..."),
                 wxOK | wxICON_INFORMATION
                 );
}

void InterfaceUS::RClose_Ultrasonix(WXWPARAM wParam, WXLPARAM lparam)
{

  if (wParam == RP_SUCCESS)
	{	// a successful disconnection
    wxMessageBox(wxString::Format(
                    _T("Mensaje de desconexión correcta recibido\n")
                 ),
                 _T("Conectando ultrasonix..."),
                 wxOK | wxICON_INFORMATION
             );
    ultrasonix_conect = false;

	}
	else	
      if (wParam == RP_ERROR)
        wxMessageBox(wxString::Format(
                    _T("Mensaje de error en desconexión recibido\n")
                 ),
                 _T("Conectando ultrasonix..."),
                 wxOK | wxICON_INFORMATION
                 );
      else if (wParam == RP_INVALID)
      // the connection attempt was unsuccessfull, so close the connection
		    wxMessageBox(wxString::Format(
                    _T("Mensaje de objeto inválido en desconexión recibido\n")
                 ),
                 _T("Conectando ultrasonix..."),
                 wxOK | wxICON_INFORMATION
                 );
}

void InterfaceUS::RCaptureImg_Ultrasonix(WXWPARAM wParam, WXLPARAM lparam)
{
	// cast the wParam to a CIRPCapture



	CIRPCapture msg((LPVOID)wParam);
  int dimx,dimy;
  dimx = 395;
  dimy = 412;
  wxRect* cut = new wxRect (122, 33, dimx, dimy); //definir el rectánculo de corte para obtener la subimagen
  InrImage::ptr usimage(new InrImage (dimx, dimy, 1, WT_UNSIGNED_CHAR));

  InrImageIteratorBase::ptr iterI = usimage->CreateIterator(); 
  double valor;
  unsigned char *pixels;

  

	TCHAR szFilename[_MAX_PATH];
	DWORD dwCount = msg.getImageCount();	// how many images are in this message?

	// increment the image counter
  ++ImageUltrasonixCount;

	// extract each image from 'msg' and save those images
	for (DWORD i = 0; i < dwCount; i++)
	{
    if(Directory != "") //si no se definió directorio, no se guardan las imágenes en disco
    {
      wxMemoryInputStream InputMemStream(msg.getImageData(i), msg.getImageLength(i)); 
   //   wxImage USimage(InputMemStream,wxBITMAP_TYPE_JPEG);
      wxImage USimage(InputMemStream,wxBITMAP_TYPE_PNG);
      
//      wxImage* CUTimage = &(USimage->GetSubImage(*cut));
      wxImage CUTimage = USimage.GetSubImage(*cut);
      pixels = CUTimage.GetData();
      //USimage.SaveFile("C:\\prueba.jpeg",wxBITMAP_TYPE_JPEG);
      USimage.SaveFile("C:\\prueba.png",wxBITMAP_TYPE_PNG);
   

      //*********** Pasar la imagen a InrImage ******************
      iterI->InitBuffer();
      

      for(int i=0; i<dimy;i++)
        for(int j=0;j<dimx;j++) {
          //image
          valor = (double)*(pixels+(i*dimx)+j);
          iterI->SetDoubleValue(valor);
      
          (*iterI)++;
  
         }

      Frame = usimage;


    //  CUTimage.SaveFile("C:\\\\imagenes\\prueba.jpeg",wxBITMAP_TYPE_JPEG);
  CUTimage.SaveFile("C:\\\\imagenes\\prueba.png",wxBITMAP_TYPE_PNG);
      image_captured = true;
      //  TODO de momento está a fuego
  /*    _stprintf(szFilename, _T("C:\\imagenes\\image%d-%d.%s"), ImageUltrasonixCount, i, m_szImageType);
      CFile file(szFilename, CFile::modeCreate | CFile::modeWrite);
      file.Write(msg.getImageData(i), msg.getImageLength(i));
		  file.Close();        */

    }
	}
}


//Mapeo de mensajes de Windows sobre WxWidgets
WXLRESULT InterfaceUS::MSWWindowProc(WXUINT message, WXWPARAM wParam, WXLPARAM lParam)
{
 // For some reason wxWindows don't respond to WM_CLOSE
 // calls from outside the application (it seems the
 // application must have focus to process this message),
 // so we manually exit the application.
if (message == WM_RP_CLOSE){
    RClose_Ultrasonix(wParam,lParam);
    //TheApp->ExitMainLoop();
  } 

if (message == WM_RP_CONNECT){
     RConnect_Ultrasonix(wParam,lParam);
  }

if  (message == WM_RP_RECV_CAPTURE_RESP){
     RCaptureImg_Ultrasonix(wParam,lParam);
  
  }
 
 return wxFrame::MSWWindowProc(message, wParam, lParam);
}












