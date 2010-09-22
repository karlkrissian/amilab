//
// C++ Interface: MyDataViewModels
//
// Description: Models for render on the wxDataViewCtrl wxWidgets.
//
//
// Author:  <Karl Krissian>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef MYDATAVIEWMODELS_H
#define MYDATAVIEWMODELS_H

#include <wx/dataview.h>

#include "myDataViewNodes.h"

/*******************************************************************************
Implement this data model:

Name                  Type                Val                 Details
--------------------------------------------------------------------------
Root
  Global
    Strings
      category        std::string         '&Visualization'
    Functions
    Objects
  Builtin
    Objects
      Wrapped Var. Func.

*******************************************************************************/

class AMILabTreeModel: public wxDataViewModel
{
  public:
    AMILabTreeModel();

    ~AMILabTreeModel()
    {
      delete m_root;
    }

    wxString GetName( const wxDataViewItem &item ) const;
    wxString GetType( const wxDataViewItem &item ) const;
    wxString GetVal(  const wxDataViewItem &item ) const;
    wxString GetDetails( const wxDataViewItem &item ) const;

//     boost::weak_ptr<BasicVariable> GetVar( const wxDataViewItem &item) const;
//     void SetVar (const wxDataViewItem &item, boost::shared_ptr<BasicVariable> var);

    void Delete( const wxDataViewItem &item );

    // override sorting to always sort branches ascendingly

    int Compare( const wxDataViewItem &item1, const wxDataViewItem &item2,
      unsigned int column, bool ascending ) const;

    // implementation of base class virtuals to define model

    virtual unsigned int GetColumnCount() const
    {
      return 4;//The VAR column is not visible.
    }

    virtual wxString GetColumnType( unsigned int col ) const
    {
  //     if (col == 4)
  //       return wxT("BasicVariable");

      return wxT("string");
    }

    virtual void GetValue( wxVariant &variant,
      const wxDataViewItem &item, unsigned int col ) const;

    virtual bool SetValue( const wxVariant &variant,
      const wxDataViewItem &item, unsigned int col );

    virtual wxDataViewItem GetParent( const wxDataViewItem &item ) const;
    virtual bool IsContainer( const wxDataViewItem &item ) const;
    virtual unsigned int GetChildren( const wxDataViewItem &parent,
      wxDataViewItemArray &array ) const;

  private:
    AMILabTreeModelNode*   m_root;
    AMILabTreeModelNode*   m_global;
    AMILabTreeModelNode*   m_builtin;
};

#endif // MYDATAVIEWMODELS_H