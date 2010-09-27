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

/**
  * @brief  Models for render on the wxDataViewCtrl wxWidgets
  *
  * Implement this data model:
  *
  * Name                  Type                Val                 Details
  * --------------------------------------------------------------------------
  * Root
  *   Global
  *     Strings
  *       category        std::string         '&Visualization'
  *     Functions
  *     Objects
  *   Builtin
  *     Objects
  *       Wrapped Var. Func.
  */
class AMILabTreeModel: public wxDataViewModel
{
  public:
    /**
     * @brief The Class constructor
     *
     * Constructor definition for the AMILabTreeModel class 
     */    
    AMILabTreeModel();

    /**
     * @brief The Class destructor
     *
     * Destructor definition for the AMILabTreeModel class
     */     
    ~AMILabTreeModel()
    {
      delete m_builtin; // Liberated m_builtin branch
      delete m_global;  // Liberated m_global branch
      delete m_root;    // Liberated m_root branch
    }

    /**
     * @brief GetName
     * @param item
     *
     * Returns the item's name
     */
    wxString GetName( const wxDataViewItem &item ) const;

    /**
     * @brief GetType
     * @param item
     *
     * Returns the item's type
     */    
    wxString GetType( const wxDataViewItem &item ) const;

    /**
     * @brief GetVal
     * @param item
     *
     * Returns the item's value
     */  
    wxString GetVal(  const wxDataViewItem &item ) const;

    /**
     * @brief GetDetails
     * @param item
     *
     * Returns the item's details
     */ 
    wxString GetDetails( const wxDataViewItem &item ) const;

//     boost::weak_ptr<BasicVariable> GetVar( const wxDataViewItem &item) const;
//     void SetVar (const wxDataViewItem &item, boost::shared_ptr<BasicVariable> var);

    /**
     * @brief Delete
     * @param item
     *
     * Deletes an item from the model
     */ 
    void Delete( const wxDataViewItem &item );

    /**
     * @brief Compare
     * @param item1
     * @param item2
     * @param column
     * @param ascending    
     *
     * Override sorting to always sort branches ascendingly
     */ 
    int Compare( const wxDataViewItem &item1, const wxDataViewItem &item2,
      unsigned int column, bool ascending ) const;

    // implementation of base class virtuals to define model

    /**
     * @brief GetColumnCount
     *
     * Returns the number of columns
     */ 
    virtual unsigned int GetColumnCount() const
    {
      return 4;//The VAR column is not visible.
    }

    /**
     * @brief GetColumnType
     * @param col
     *
     * Indicates what type of data is stored in the column specified by col
     */ 
    virtual wxString GetColumnType( unsigned int col ) const
    {
  //     if (col == 4)
  //       return wxT("BasicVariable");

      return wxT("string");
    }

    /**
     * @brief GetValue
     * @param variant
     * @param item
     * @param col
     *
     * Indicates the value of item
     */
    virtual void GetValue( wxVariant &variant,
      const wxDataViewItem &item, unsigned int col ) const;

    /**
     * @brief SetValue
     * @param variant
     * @param item
     * @param col
     *
     * Changes the value of the given item and update the control to reflect it
     */
    virtual bool SetValue( const wxVariant &variant,
      const wxDataViewItem &item, unsigned int col );

    /**
     * @brief GetParent
     * @param item
     *
     * Returns the parent of a item
     */      
    virtual wxDataViewItem GetParent( const wxDataViewItem &item ) const;

    /**
     * @brief IsContainer
     * @param item     
     *
     * Returns true if item is a container. Determines if it can have child items (is branch or leaf node?)
     */    
    virtual bool IsContainer( const wxDataViewItem &item ) const;

    /**
     * @brief GetChildren
     * @param parent
     * @param array
     *
     * Returns the children of item
     */
    virtual unsigned int GetChildren( const wxDataViewItem &parent,
      wxDataViewItemArray &array ) const;

    // News methods for to define model

    /**
     * @brief DeleteChildren
     * @param item
     *
     * Removes the children nodes
     */
    void DeleteChildren( const wxDataViewItem &item );

    /**
     * @brief CreateLeafNode
     * @param parent
     * @param name
     * @param type
     * @param val
     * @param details     
     *
     * Creates the new leaf node
     */    
    wxDataViewItem CreateLeafNode(const wxDataViewItem &parent, const wxString &name,
      const wxString &type, const wxString &val,  const wxString &details);

    /**
     * @brief CreateBranchNode
     * @param parent
     * @param branch
     *
     * Creates the new branch node
     */      
    wxDataViewItem CreateBranchNode(const wxDataViewItem &parent, const wxString &branch);

    /**
     * @brief HasChildren
     * @param item
     *
     * Determines if it have child items
     */ 
    bool HasChildren(const wxDataViewItem &item) const;

    /**
     * @brief GetRootNode
     *
     * Returns the root's branch
     */    
    wxDataViewItem GetRootNode() const;

    /**
     * @brief GetGlobalNode
     *
     * Returns the global's branch
     */       
    wxDataViewItem GetGlobalNode() const;

    /**
     * @brief GetBuiltinNode
     *
     * Returns the builtin's branch
     */       
    wxDataViewItem GetBuiltinNode() const;

  private:
    AMILabTreeModelNode*   m_root;
    AMILabTreeModelNode*   m_global;
    AMILabTreeModelNode*   m_builtin;
};

#endif // MYDATAVIEWMODELS_H