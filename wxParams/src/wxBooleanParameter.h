//
// C++ Interface: wxBooleanParameter
//
// Description: 
//
//
// Author: Karl Krissian <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wxBooleanParameter_h_
#define _wxBooleanParameter_h_

#include "widget.hpp"
#include "StructParams.hpp"

/*!
  \brief wxBooleanParameter: GUI for a boolean parameter
*/
class wxBooleanParameter : public wxCheckBox, public wxGenericWidget
//    ==================
{
  unsigned char*  parametre;
  unsigned char val_defaut;
  std::string   _libelle;
  type_booleen  _type;

public:

  wxBooleanParameter( wxWindow* parent, unsigned char* param,
  //----------
         const char* libelle);

  ~wxBooleanParameter();
  //---------

  void FixeDefaut( unsigned char defaut);
  //   ----------

  void FixeAccelerateur( std::string accelerateur, std::string texte);
  //   ----------------


  void UpdateValue();
  //   --------------

  unsigned char VerifieContraintes();
  //      ------------------

  /** Cette methode permet de remettre a jour la
      valeur du parametre dans le widget
  */
  void Update();
  //   ------


  virtual void OnCheck( wxCommandEvent& );

private:
    DECLARE_EVENT_TABLE();

}; // wxBooleanParameter


#endif // _wxBooleanParameter_h_
