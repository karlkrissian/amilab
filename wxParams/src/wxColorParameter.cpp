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
//
//
//
//

#include "wxColorParameter.h"


//================================================================================
// Class wxColorParameter
//
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/colordlg.h"

//BEGIN_EVENT_TABLE(wxColorParameter, wxButtonParameter)
//    EVT_LEFT_UP(  wxColorParameter::OnLeftButton)
//END_EVENT_TABLE()


///
wxColorParameter::wxColorParameter( wxWindow* parent, const char* libelle, ClasseCouleur* couleur)
//----------
  : wxButtonParameter(parent,libelle ,
		      (void*) NULL,
		      (void*) NULL)
{
  SetBackgroundStyle( wxBG_STYLE_COLOUR);
  parametre = couleur;
  Update();
}

///
wxColorParameter::~wxColorParameter()
//---------
{
}

///
void  wxColorParameter::Update()
//
{
  this->_wx_color.Set(parametre->Red(),
                      parametre->Green(),
                      parametre->Blue());
  this->SetBackgroundColour(this->_wx_color);

  if (_wx_color.Red()+ _wx_color.Green()+ _wx_color.Blue()
      < (1.5*255))
    SetForegroundColour(*wxWHITE);
  else
    SetForegroundColour(*wxBLACK);

}

///
void wxColorParameter::OnButton( wxCommandEvent& event)
//                     --------
{

  //printf("wxColorParameter::OnLeftButton()\n");
  wxColour col;
  this->_wx_color.Set(parametre->Red(),
                      parametre->Green(),
                      parametre->Blue());

  wxColourData data;
  data.SetColour( this->_wx_color);
  wxColourDialog dialog(this, &data);

  if ( dialog.ShowModal() == wxID_OK )
    {
      col = dialog.GetColourData().GetColour();
    }

  parametre->FixeValeur(col.Red(),col.Green(),col.Blue());
  this->Update();

  //printf("wxColorParameter::OnLeftButton() \tthis->_callback != NULL ??\n");
  if (this->_calldata != NULL) {
    //printf("wxColorParameter::OnLeftButton() \tthis->_callback != NULL\n");
    this->Callback();
  }
  //  event.Skip();
}


