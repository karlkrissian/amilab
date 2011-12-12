/**
 *  @brief Wrapping of some Ultrasonix functionalities
 *  @author Karl Krissian (krissian@dis.ulpgc.es)
 *  @author Sara Illera Santana (sara.illera101@estudiantes.ulpgc.es)
*/
#ifndef _Interfaz_h_
#define _Interfaz_h_

#include "RPCore.h"
#include "resource.h"	
#include <boost/shared_ptr.hpp>
class InrImage;

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

// For all others, include the necessary headers (this file is usually all you
// need because it includes almost all "standard" wxWidgets headers)
#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif



/**
 *Wrap class for Ultrasonix functionalities
 *Interface build over wxFrame, a wxWindow-derived class,to override a virtual MSWWindowProc()method, 
 *so we can mapper the ultrasonix messages over wxWidgets to handle it.
*/

class InterfaceUS : public wxFrame
{
public:
    /**
      * Creates a new InterfaceUS object. Default constructor
      *@param Dir If exists Directory then ultrasound images are saved in that directory
    */ 
    InterfaceUS(const wxString& Dir);
    
    ~InterfaceUS() {};
    
    /**
     * Connect with the Ultrasonix machine
     *@param IP The IP to connect
     *@see IsUltrasonixConnect
    */
    void Connect_Ultrasonix(const wxString& IP);
    
    /**
     * Disconnect with the Ultrasonix machine
    */ 
    void DisConnect_Ultrasonix();

    /** 
     * Request an ultrasound frame to Ultrasonix
     *
     * Ultrasonix send a response message with the
     * encapsulated information, or error message in other case.
     * @see IsImageCaptured
     * @see ReadImage
    */
    bool GetImage();

    /**
      * Return true if the Ultrasonix already sent the image request. False in other case.
    */
    bool IsImageCaptured(){return ImageCaptured;};

    /** 
     * Read the ultrasound image
     * @return The frame converted to amilab image object InrImage
    */
    boost::shared_ptr<InrImage> ReadImage(){return Frame;};

    /**
     * Return true if Ultrasonix machine is connected. False in the other case.
    */  
    bool IsUltrasonixConnect(){return UltrasonixConnect;};

    /**
     * Get the ultrasound frame dimension. 
     * @param dim Vector in/out contains dimensions {x,y}
    */
    void GetFrameDim(int dim[2]);

private:
    wxString Directory; 
    CIRPRemoteControl m_rc;
    int ImageUltrasonixCount;
    int Dimension[2];
    TCHAR m_szImageType[5];	
    bool UltrasonixConnect; 
    bool ImageCaptured;
    boost::shared_ptr<InrImage> Frame; ///< Ultrasound image encapsulated in AMILab object InrImage
    

    void RConnect_Ultrasonix(WXWPARAM wParam, WXLPARAM lparam);
    void RClose_Ultrasonix(WXWPARAM wParam, WXLPARAM lparam);
    void RCaptureImg_Ultrasonix(WXWPARAM wParam, WXLPARAM lparam);

    /**
      *To handle a Windows message you need to override a virtual <i>MSWWindowProc()</i> method in a wxWindow-derived class.   
      *You should then test if nMsg parameter is the message you need to process and perform the necessary action if 
      *it is or call the base class method otherwise.
    */
    WXLRESULT MSWWindowProc(WXUINT message, WXWPARAM wParam, WXLPARAM lParam);
};

// IDs menu controls
enum
{
  Submenu_Start = wxID_HIGHEST + 1, 
	Submenu_Stop = wxID_HIGHEST + 2,
 
  SConnect_Ultrasonix = wxID_HIGHEST + 5,
  SDisConnect_Ultrasonix = wxID_HIGHEST + 7,
  
  BStart = wxID_HIGHEST + 8,
};

#endif // _Interfaz_h_
