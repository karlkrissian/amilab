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
/*
//  Fichier ParamBox.hpp
//
//  Creation d'une boite de dialogue pour les parametres
//  de maniere generique
//
//  Karl KRISSIAN   Sophia Antipolis, le 24-07-96
//


// Plusieurs types de parametres
//
// int
// unsigned char
// float
// Enumeration
// Chaine de caracteres
// Nom de fichier
// Couleur
//
// A preciser : Type d'affichage, domaine de validite, valeur par defaut, ...
//
// Proposer des valeurs par defaut de maniere a creer tres simplement une boite de dialogue
//
 *
 * $Author: karl $
 * $Revision: 1.5 $
 * $Log: 
 */

#ifndef _ParamBox_hpp
#define _ParamBox_hpp



// including vector after wxwidget classes could
// lead to problems because of the 'new' macro

// includes for wxWidgets
#include "wx/wxprec.h"
#ifdef __BORLANDC__
#pragma hdrstop
#endif
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/propdlg.h"
#include "wx/notebook.h"


//#include "NoyauParametre.hpp"
#include "widget.hpp"
#include "StructParams.hpp"
#include "couleur.hpp"
#include "palette.hpp"

#include <vector>
#include <stack>
#include <string>

#define MAX_ARGS         20

#include <boost/shared_ptr.hpp>
typedef boost::shared_ptr<std::string>     string_ptr;

//==============================================================================
/**
  La classe {\em ParamBox} permet de g�er facilement la modification \\
  d'un ensemble de param�res.

  Voici un exemple tir�du programme iv


  param = new ParamBox( WidgetPere,"Champ de Vecteurs"); \\
\\
  //-------------- \\
  param->AddFloat( &id_vecteurs_taille, &_taille_vecteur, "taille en pixels"); \\
  param->FloatConstraints(    id_vecteurs_taille, 0.01, 10, _taille_vecteur); \\
  param->ChangedValueCallback( id_vecteurs_taille, (void*) CB_taille_vecteurs, \\
                              (void*) data); \\
\\
  //-------------- \\
  param->AddInteger( &id_vecteurs_espacement, &_espacement_vecteur, "espacement en pixels"); \\
  param->IntegerConstraints(    id_vecteurs_espacement, 1, 20, _espacement_vecteur); \\
  param->ChangedValueCallback( id_vecteurs_espacement, 
                                        (void*) CB_taille_vecteurs, (void*) data); \\
\\
\\
  //-------------- \\
  param->AddEnumeration( &id_vecteur_type, 2, &_vecteur_type ,"type de vecteur"); \\
  param->AddEnumChoice( id_vecteur_type, &id_vecteur_fleche,     " Fl�he"); \\
  param->AddEnumChoice( id_vecteur_type, &id_vecteur_direction,  " Direction"); \\
  param->EnumerationDefaut( id_vecteur_type, id_vecteur_fleche); \\
  param->ChangedValueCallback( id_vecteur_type,(void*) CB_type_vecteur,(void*)data); \\
\\
 //---------- Creation de la boite de parametres \\
  param->CreeDialogue( ); \\
\\
 */

#include "ParamInfo.h"

/*!
  \brief ParamBox: a wxDialog to include parameters
*/
class ParamBox: public  wxDialog
//    ========
{

  DECLARE_CLASS(ParamBox);

private:

  unsigned char       _inclu_bouttons;

  std::vector<ParamInfo> _tab_param;

  std::stack<wxBoxSizer*>  _current_sizer;
  std::stack<wxPanel*>     _panels;
  std::stack<wxNotebook*>  _current_book;

  wxBoxSizer*  _main_sizer;


public:

/** @name (s), ~ */
//@{

/*
  ///
   ParamBox( Widget parent,const char* titre);
  //----------
*/

  ///
   ParamBox( wxWindow* parent,  const char* titre,
  //----------
                        long style =  wxPROPSHEET_TOOLBOOK
//wxPROPSHEET_TREEBOOK
//(wxPROPSHEET_SHRINKTOFIT| wxPROPSHEET_TOOLBOOK) 
                        );

  wxNotebook* GetBookCtrl() 
  {
    if (!_current_book.empty())
      return _current_book.top(); 
    else
      return NULL;
  }

  void BeginBook();

  void EndBook();

  void AddPage(const std::string& panel_name);
  //   -------

  void BeginPanel(const std::string& panel_name);
  //   --------

  void EndPanel();

  ///
  ~ ParamBox();
  //---------
//@}

  wxPanel* LastPanel()
  {
    if (_panels.empty()) {
      BeginPanel("main panel");
    }
    return _panels.top();
  }

  wxWindow* CurrentParent()
  {
    if (_panels.empty())
      return this;
    else
      return LastPanel();
  }

  wxSizer* LastPanelSizer()
  {
    if (_panels.empty()) {
      fprintf(stderr,"ParamBox::LastPanelSizer() \t No panel !!! \n");
      return NULL;
    }
    return _panels.top()->GetSizer();
  }

  ///
  void RecupereDimensions( int* , int* );
  //

  int NbParameters() { return _tab_param.size(); } 
  //
 
  //
  template <class T>
  wxSizerItem* AddParam( T* w);
  //

  //
  wxSizerItem* AddWidget( wxWindow* w);
  //

  //
  wxSizerItem* AddWidget( wxSizer* w);
  //

/** @name Type unsigned char */
//@{

  ///
  unsigned char AddBoolean( int* id, unsigned char* param, const char* libelle,
  //      -------------
             type_booleen type=CaractereToggle);

  ///
  void BooleanDefault( int id, unsigned char defaut);
  //   -------------
//@}

/** @name Type int */
//@{
  ///
  unsigned char AddInteger( int* id, int* param, const char* libelle,  const std::string& tooltip="");
  //      ------------

  int AddInteger( int* param, const char* libelle,
                  const std::string& tooltip="");
  //      ------------

  ///
  void IntegerConstraints( int id, int min, int max, int defaut);
  //   -----------------
//@}

  void ParamIntGetLimits( int id, int& min, int& max);


/** @name Type float */
//@{
  /**
    @param precision nombre de chiffres apr� la virgule
   */
  bool AddFloat( 
                  int* id,
                  float* r,
                  const char* libelle, 
                  int precision = 2,
                  const std::string& tooltip=""
                );

  int AddFloat( 
                float* r,
                const char* libelle,
                int precision = 2,
                const std::string& tooltip=""
              );

  ///
  void FloatConstraints(
  //   ---------------
      int id,  
      const float& min,
      const float& max,
      const float& defaut);
//@}

  void ParamShowSlider( int id, bool show);
  //   --------------------

  void ParamFloatGetLimits( int id, float& min, float& max);

/** @name Type double */
//@{
  /**
    @param precision nombre de chiffres apr� la virgule
   */
  unsigned char AddFloatDouble( int* id, double* r, const char* libelle, int precision = 2);
  //      ----------

  int AddFloatDouble( double* r, const char* libelle, int precision = 2);
  //      ----------

  ///
  void FloatConstraintsDouble( int id, double min, double max, double defaut);
  //   ---------------
//@}

/** @name Type Chaine */
//@{
  ///
  unsigned char AjouteChaine( int* id, string_ptr ch, const char* libelle);
  //      ------------

  ///
  void ContraintesChaine( int id, char* defaut);
  //   -----------------
//@}


/** @name Type NomFichier */
//@{
  ///
  unsigned char AddFilename( int* id, string_ptr& nom, const char* libelle);
  //      ----------------

  ///
  void ContraintesNomFichier( int id, const char* defaut, const char* rep, const char* masque);
  //   ---------------------
//@}

/** @name Type Boutton */
//@{
  ///
  unsigned char AddButton( int* id, const char* libelle, 
  //      -------------
             void* callback, void* data);
//@}

/** @name Type Boutton avec Pixmap*/
//@{
  ///
  unsigned char AddPixmapButton( int* id, const char* libelle, 
  //            ---------------
                   void* callback, void* data,
                   const char** pixmap_string);
//@}

/** @name Type Couleur */
//@{
  ///
  // for wxwidgets version
  unsigned char AddColor( int* id, const char* libelle, 
  //            -------
             ClasseCouleur* couleur);
//@}

/** @name Type Label */
//@{
  ///
  unsigned char AddLabel( int* id, const char* libelle, const char* contenu, 
  //      -----------
               type_label type=LabelLabel);
//@}
  
  void SetLabelValue(int id, char* value);

/** @name Type Widget */
//@{
  ///
//  unsigned char AjouteWidget( int* id, Widget widget);
  //      ------------
//@}


/** @name Type Enumeration */
//@{
  ///
  unsigned char AddEnumeration( int* id, int taille, int* param, 
  //      -----------------
                 const char* libelle, 
                 type_enum type=EnumOptionMenu);

  ///
  unsigned char AddEnumeration( int* id,  int* param, 
  //      -----------------
                 const char* libelle, 
                 type_enum type=EnumOptionMenu);

  ///
  unsigned char AddEnumChoice( int id_enum, int* id_enum_choix, 
  //      ---------------
               const char* libelle, const char* pixmap_name="");

  ///
  unsigned char AddEnumChoice( int id_enum, int* id_enum_choix, 
  //      ---------------
               const char* libelle, const char** pixmap_string);

  ///
  void EnumerationDefaut( int id_enum, int id_enum_choix);
  //   -----------------
//@}


  ///
  void FixeVisible( int id, unsigned char);
  //   -----------

/*  ///
  void Attache( int id, Widget haut, Widget gauche);
  //   -------
*/

  ///
  void ChangedValueCallback( int id, void* callback, void* calldata);
  //   -------------------- 

  ///
  void EnleveBouttons();
  //   --------------

  ///
  void CreeDialogue( );
  //   ------------

  ///
  void ReAfficheParametres( );
  //   -------------------

  ///
  void RecupereValeur( int id );
  //   --------------

  ///
  void RecupereValeurs( );
  //   ---------------

  ///
  void MAJ( );
  //   ---

  ///
  void AfficheDialogue();
  //   ---------------

  ///
//  int GetState() { return *_etat_sortie; }
  //  --------

  ///
  void FermeDialogue( );
  //   -------------

  ///
  void UpdateParameter( int id);
  //   ---------------
  
  ///
  void SetStackDirection( int id, int type_empilement);
  //   -----------------
  

  /// si l'identificateur vaut -1, il n'est pas pris en compte
  void Attache(int id, int id_h, int id_g, int id_b=-1, int id_d=-1);
  //   -------

/*
///
  Widget GetWidget(int id);
  //     ---------
*/

  void SetDragCallback( int id);

  void BeginBox( const char* boxname);
  void EndBox();
  
  void BeginHorizontal();
  void EndHorizontal();
  
  virtual void OnOK( wxCommandEvent& );
  virtual void OnApply( wxCommandEvent& );
  virtual void OnCancel( wxCommandEvent& );

  virtual void OnClose(wxCloseEvent& event);
  
private:
    DECLARE_EVENT_TABLE()

}; // ParamBox
//==============================================================================
#include <boost/shared_ptr.hpp>
typedef boost::shared_ptr<ParamBox> ParamBox_ptr;


#endif // _ParamBox_hpp
