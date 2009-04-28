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
#define TYPE_PARAMETRE_BOOLEEN		1
///
#define TYPE_PARAMETRE_ENTIER		2
///
#define TYPE_PARAMETRE_REEL		3
///
#define TYPE_PARAMETRE_ENUMERATION	4
///
#define TYPE_PARAMETRE_CHAINE		5
///
#define TYPE_PARAMETRE_NOM_FICHIER	6
///
#define TYPE_PARAMETRE_BOUTTON	        7
///
#define TYPE_PARAMETRE_COULEUR		8
///
#define TYPE_PARAMETRE_LABEL            9
///
#define TYPE_PARAMETRE_WIDGET           10
///
#define TYPE_SEPARATEUR			11
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
 
