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
//  Karl Krissian
//  Las Palmas 
//  14 05 2000
//

#ifndef _PARAMCOULEUR_HPP
#define _PARAMCOULEUR_HPP

#include "wxParamTypes.hpp"
#include "ParamBox.hpp"
#include "couleur.hpp"


//======================================================================
class wxColorParameter : public wxButtonParameter
//
{

  ClasseCouleur*	parametre;
  wxColour      _wx_color;

 public:

  ///
  wxColorParameter( wxWindow* parent, const char* libelle, 
  //----------
				 ClasseCouleur* couleur);
  ///
  ~wxColorParameter();
  //---------

  ///
  void Update();
  //

  virtual void OnLeftButton( wxMouseEvent& );

private:
    DECLARE_EVENT_TABLE()
};
 // wxColorParameter


#endif // _PARAMCOULEUR_HPP

