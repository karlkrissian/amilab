//
// C++ Implementation: wrap_imagedraw
//
// Description: 
//
//
// Author: Karl Krissian <>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//


#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "wrap_wxsamples.h"
#include "ami_object.h"
#include "penguin.h"
#include "stctest.h"
#include "MainFrame.h"

extern VarContexts  Vars;
extern MainFrame*     GB_main_wxFrame;

void AddWrapWXSamples()
{
  // Create new instance of the class
  AMIObject* amiobject = new AMIObject;
  amiobject->SetName("wxsamples");

  // Set the object context
  Variables::ptr previous_ocontext = Vars.GetObjectContext();
  Vars.SetObjectContext(amiobject->GetContext());

  Vars.AddVar(type_c_procedure, "penguin",  (void*)  wrap_penguin, OBJECT_CONTEXT_NUMBER);
  Vars.AddVar(type_c_procedure, "stctest",  (void*)  wrap_stctest, OBJECT_CONTEXT_NUMBER);

  // Restore the object context
  Vars.SetObjectContext(previous_ocontext);

  // 3. add the variables to this instance
  Vars.AddVar( type_ami_object, amiobject->GetName().c_str(), (void*) amiobject);
}

/**
 * Adds the wxwidgets sample wrapping
 * @param p 
 */
void wrap_wxsamples( ParamList* p)
{
    char functionname[] = "wxsamples";
    char description[]=" \n\
      Adds wrapping for the wxwidgets samples. \n\
            ";
    char parameters[] =" \n\
            ";

  AddWrapWXSamples();
}


/**
 * Runs the penguin wxwidgets sample. 
 * @param p 
 */
void wrap_penguin( ParamList* p)
{
    char functionname[] = "penguin";
    char description[]=" \n\
      Runs the penguin wxwidgets sample. \n\
            ";
    char parameters[] =" \n\
            ";

  int n=0;

  // Create the main frame window
  PenguinFrame *frame = new PenguinFrame(GB_main_wxFrame, wxT("wxWidgets Penguin Sample"),
      wxDefaultPosition, wxDefaultSize);

  #if wxUSE_ZLIB
    if (wxFileExists(wxT("penguin.dxf.gz")))
      frame->GetCanvas()->LoadDXF(wxT("penguin.dxf.gz"));
  #else
    if (wxFileExists(wxT("penguin.dxf")))
      frame->GetCanvas()->LoadDXF(wxT("penguin.dxf"));
  #endif

  // Show the frame
  frame->Show(true);

}


/**
 * Runs the scintilla test wxwidgets sample.
 * @param p 
 */
void wrap_stctest( ParamList* p)
{
    char functionname[] = "penguin";
    char description[]=" \n\
      Runs the scintilla test wxwidgets sample. \n\
            ";
    char parameters[] =" \n\
            - string: filename to open \n\
            - line number (def:0)";

  int n=0;
  std::string* filename = NULL;
  int line_number = 0;
  
  if (!get_var_param<string>( filename,    p, n)) HelpAndReturn;
  if (!get_int_param( line_number,    p, n)) HelpAndReturn;

  // create application frame
  StcTestFrame*  m_frame = new StcTestFrame ( wxT("wxWidgets Scintilla Sample"));

  // open application frame
  m_frame->Layout ();
  m_frame->Show (true);
  if (filename!=NULL) m_frame->FileOpen (wxString(filename->c_str(),wxConvUTF8));
  Edit* editor = m_frame->GetEditor();
  // TODO: 
  // - set show line numbers
  // - set highlight C++
  // - go to specific line
  editor->ShowLineNumbers(true);
  editor->GotoLine(line_number);
}


