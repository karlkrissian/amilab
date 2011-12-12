
#ifdef NOMINMAX
  #ifndef min
    #define min(a,b) ((a)<(b)?(a):(b))
  #endif
  #ifndef max
    #define max(a,b) ((a)>(b)?(a):(b))
  #endif
#endif

#include "stdafx.h"
#include "InterfaceUS.h"
#include <iostream>
#include <fstream>
#include "wx/mstream.h"
#include "wx/stream.h"
#include <inrimage.hpp>



using namespace std;


/*********************************************************************/
/*                  wxFrame  constructor                             */
/*         To capture events from ultrasound machine                 */
/*********************************************************************/
InterfaceUS::InterfaceUS(const wxString& Dir)
       : wxFrame(NULL, wxID_ANY, "",wxDefaultPosition,wxSize(1000,800))
{
    
  wxInitAllImageHandlers();

  wxMenu *Menu = new wxMenu;
  wxMenu *Ultrasonix = new wxMenu;

  //General menu
  Menu->Append(Submenu_Start, _T("&Start\tAlt-B"));
  Menu->Append(Submenu_Stop, _T("&Stop \tAlt-B"));
  Menu->AppendSeparator();

  //Ultrasonix menu
  Ultrasonix->Append(SConnect_Ultrasonix, _T("&Connect with ultrasonix"));
  Ultrasonix->Append(SDisConnect_Ultrasonix, _T("&Disconnect with ultrasonix"));

  //Attach the menu to the menu bar
  wxMenuBar *menuBar = new wxMenuBar();
  menuBar->Append(Ultrasonix, _T("&Ultrasonix"));

  //Attach the menu bar to the window
  SetMenuBar(menuBar);

  //Create sizer
  wxBoxSizer* itemBoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
  SetSizer(itemBoxSizer9);

  wxButton* ButtonStart = new wxButton( this, BStart, _("Start"), wxDefaultPosition, wxDefaultSize, 0 );
  itemBoxSizer9->Add(ButtonStart, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);
 
  UltrasonixConnect = false;
  //Initialize Ultrasonix sockets
  if (!AfxSocketInit())
  {
    AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
    //return FALSE;
  }
  AfxEnableControlContainer();

  //Initialize Ultrasonix API
  if (!this->m_rc.Initialize((HWND)GetHWND()))
        wxMessageBox(wxString::Format(
                  _T("The remote control could not be initialized\n")
               ),
               _T("Initialization Ultrasonix"),
               wxOK | wxICON_ERROR ,
               this);
 
  Directory = Dir;
  
  //Set frame dimension (cut dimension)
  Dimension[0] = 395;
  Dimension[1] = 412;
}

void InterfaceUS::GetFrameDim(int dim[2]){
  dim[0] = Dimension[0];
  dim[1] = Dimension[1];
}


/*********************************************************************/
/*  Request to the ultrasound machine; Connect, Disconnect, GetImage */                                
/*********************************************************************/
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
  if(UltrasonixConnect)
  {
    ImageCaptured = false;
    m_rc.getScreenCapture(RP_CAPTURE_PREMERGE | RP_CAPTURE_DISPLAY,png_e);
    _tcscpy(m_szImageType, _T("png"));
    return true;
  }
  else return false;
}


/*********************************************************************************************************/
/* Functions to handle ultrasound events; RConnect_Ultrasonix, RClose_Ultrasonix, RCaptureImg_Ultrasonix */                                
/*********************************************************************************************************/
void InterfaceUS::RConnect_Ultrasonix(WXWPARAM wParam, WXLPARAM lparam)
{
  if (wParam == RP_SUCCESS)
	{	
    //A successful connection
    UltrasonixConnect = true;
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
      //The connection attempt was unsuccessfull, so close the connection
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
	{	
    //A successful disconnection
    wxMessageBox(wxString::Format(
                    _T("Mensaje de desconexión correcta recibido\n")
                 ),
                 _T("Conectando ultrasonix..."),
                 wxOK | wxICON_INFORMATION
             );
    UltrasonixConnect = false;

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
      //The connection attempt was unsuccessfull, so close the connection
		  wxMessageBox(wxString::Format(
                    _T("Mensaje de objeto inválido en desconexión recibido\n")
                 ),
                 _T("Conectando ultrasonix..."),
                 wxOK | wxICON_INFORMATION
                 );
}

void InterfaceUS::RCaptureImg_Ultrasonix(WXWPARAM wParam, WXLPARAM lparam)
{
	//Cast the wParam to a CIRPCapture object. This object encapsulates the response.
	CIRPCapture msg((LPVOID)wParam);
  int dimx,dimy;
  dimx = 395;
  dimy = 412;
  wxRect* cut = new wxRect (122, 33, dimx, dimy); 
  InrImage::ptr usimage(new InrImage (dimx, dimy, 1, WT_UNSIGNED_CHAR));
  InrImageIteratorBase::ptr iterI = usimage->CreateIterator(); 
  double valor;
  unsigned char *pixels;
	TCHAR szFilename[_MAX_PATH];
	DWORD dwCount = msg.getImageCount();	// Always one image
  wxImage CUTimage;

	//Increment the image counter
  ++ImageUltrasonixCount;

	//Extract each image from 'msg' and save those images
	for (DWORD c = 0; c < dwCount; c++)
	{
    wxMemoryInputStream InputMemStream(msg.getImageData(c), msg.getImageLength(c)); 
    wxImage USimage(InputMemStream,wxBITMAP_TYPE_PNG);     
    CUTimage = USimage.GetSubImage(*cut); //Cut the image to remove noise
    pixels = CUTimage.GetData();
       
    //Convert to InrImage
    iterI->InitBuffer();
    for(int i=0; i<dimy;i++)
      for(int j=0;j<dimx;j++) {
        valor = (double)*(pixels+(i*dimx)+j);
        iterI->SetDoubleValue(valor);
        (*iterI)++;
       }

    Frame = usimage;
    ImageCaptured = true;

    if(Directory != ""){
      _stprintf(szFilename, _T("%s\\image%d-%d.%s"),Directory, ImageUltrasonixCount, c, m_szImageType);
      CUTimage.SaveFile(szFilename,wxBITMAP_TYPE_PNG);
    }
	}
}


//Map the Windows messages 
WXLRESULT InterfaceUS::MSWWindowProc(WXUINT message, WXWPARAM wParam, WXLPARAM lParam)
{
  //Disconnect 
  if (message == WM_RP_CLOSE){
      RClose_Ultrasonix(wParam,lParam);
  } 
  //Connect
  if (message == WM_RP_CONNECT){
       RConnect_Ultrasonix(wParam,lParam);
  }
  //Get capture
  if  (message == WM_RP_RECV_CAPTURE_RESP){
       RCaptureImg_Ultrasonix(wParam,lParam);
  }
  return wxFrame::MSWWindowProc(message, wParam, lParam);
}












