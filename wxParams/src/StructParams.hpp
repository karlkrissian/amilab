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

#ifndef _STRUCTPARAMS_HPP
#define _STRUCTPARAMS_HPP


/** @name Types de param�tres */
//@{
///
enum {
  TYPE_PARAMETER_BOOLEEN_UCHAR =1,
  TYPE_PARAMETER_BOOLEEN_BOOL,
  TYPE_PARAMETER_ENTIER,
  TYPE_PARAMETER_REEL,
  TYPE_PARAMETER_ENUMERATION,
  TYPE_PARAMETER_CHAINE,
  TYPE_PARAMETER_BOUTTON,
  TYPE_PARAMETER_COULEUR,
  TYPE_PARAMETER_LABEL,
  TYPE_PARAMETER_WIDGET,
  TYPE_SEPARATEUR,
  TYPE_PARAMETER_ANY,
};
//@}


typedef
/** @name Differents types de bouttons */
enum{
/// Text button
  TextButton,
/// Pixmap button
  PixmapButton,
    } button_type;

typedef
/** @name Differents types de booleens */
enum{
      /// On separe minuscules: false, majuscules: true
      CaractereMinMaj,
      /// ToggleButton
      CaractereToggle,
      CaracterePixmap
    } type_booleen;

typedef
/** @name Differents types de labels */
enum{
/// On separe le libelle (label) et le contenu (text)
  LabelTexte,
/// Le libelle et le contenu sont concatene dans un meme widget de type label
  LabelLabel
    } type_label;

typedef
/** @name Differents types d'�num�rations */
enum{
/// 
  EnumOptionMenu,
///
  EnumListToggle, 
///
  EnumCascadeToggle,
///
  EnumPixmapButton
    } type_enum;

#endif // _STRUCTPARAMS_HPP
 
