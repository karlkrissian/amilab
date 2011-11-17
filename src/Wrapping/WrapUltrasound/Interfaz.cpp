
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
using namespace std;


// ----------------------------------------------------------------------------
// Tabla de eventos y otras macros para wxWidgets
// ----------------------------------------------------------------------------

// Las tablas de eventos conectan los eventos wxWidgets con las funciones que los procesan. 
// Puede también establecerse en tiempo de ejecución.
BEGIN_EVENT_TABLE(Ultrasound, wxFrame)
   // EVT_MENU(SConnect_Ultrasonix, Ultrasound::Connect_Ultrasonix)
   // EVT_MENU(SDisConnect_Ultrasonix, Ultrasound::DisConnect_Ultrasonix)
   // EVT_BUTTON(BStart, Ultrasound::GetImage)
END_EVENT_TABLE()


// ============================================================================
// Implementación
// ============================================================================



/*
// ----------------------------------------------------------------------------
// Clase de aplicación
// ----------------------------------------------------------------------------
// Creación de un objeto de aplicación
IMPLEMENT_APP(MiApp)

// Programa principal
bool MiApp::OnInit()
{

    if ( !wxApp::OnInit() )
        return false;
    // Creación de la ventana principal de la aplicación
    Ultrasound *frame = new Ultrasound(_T("Aplicación fusión-test V1.0"));
    // Muestra la ventana
    frame->Show(true);

    return true;
}
*/

// ----------------------------------------------------------------------------
// Ventana principal
// ----------------------------------------------------------------------------

// Cosntructor de la ventana principal
Ultrasound::Ultrasound()
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
        wxMessageBox(wxString::Format(
                  _T("Inicialización de ultrasonix completada con éxito\n")
               ),
               _T("Inicialización Ultrasonix"),
               wxOK | wxICON_INFORMATION ,
               this);
}



void Ultrasound::Connect_Ultrasonix(const wxString& IP)
{

   m_rc.Connect(IP);
  ImageUltrasonixCount = 0;
}

void Ultrasound::DisConnect_Ultrasonix()
{
    this->m_rc.Disconnect();
}

void Ultrasound::GetImage()
{
  if(ultrasonix_conect)
  {
    m_rc.getScreenCapture(RP_CAPTURE_DISPLAY,jpeg_e);
    _tcscpy(m_szImageType, _T("jpg"));
   }
}


//Funciones manejadores de los mensajes del servidor
void Ultrasound::RConnect_Ultrasonix(WXWPARAM wParam, WXLPARAM lparam)
{

  if (wParam == RP_SUCCESS)
	{	// a successful connection
    wxMessageBox(wxString::Format(
                    _T("Mensaje de confirmación de conexión recibido\n")
                 ),
                 _T("Conectando ultrasonix..."),
                 wxOK | wxICON_INFORMATION
             );
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

void Ultrasound::RClose_Ultrasonix(WXWPARAM wParam, WXLPARAM lparam)
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

void Ultrasound::RCaptureImg_Ultrasonix(WXWPARAM wParam, WXLPARAM lparam)
{
	// cast the wParam to a CIRPCapture
	CIRPCapture msg((LPVOID)wParam);

	TCHAR szFilename[_MAX_PATH];
	DWORD dwCount = msg.getImageCount();	// how many images are in this message?

	// increment the image counter
  ++ImageUltrasonixCount;

	// extract each image from 'msg' and save those images
	for (DWORD i = 0; i < dwCount; i++)
	{
    _stprintf(szFilename, _T("C:\\imagenes\\image%d-%d.%s"), ImageUltrasonixCount, i, m_szImageType);
		CFile file(szFilename, CFile::modeCreate | CFile::modeWrite);
    file.Write(msg.getImageData(i), msg.getImageLength(i));
		file.Close();        
	}
}


//Mapeo de mensajes de Windows sobre WxWidgets
WXLRESULT Ultrasound::MSWWindowProc(WXUINT message, WXWPARAM wParam, WXLPARAM lParam)
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












