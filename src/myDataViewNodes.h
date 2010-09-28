//
// C++ Interface: MyDataViewNodes
//
// Description: Nodes for the models for render on the wxDataViewCtrl wxWidgets.
//
//
// Author:  <Karl Krissian>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef MYDATAVIEWNODES_H
#define MYDATAVIEWNODES_H

//--------------------------------------------------
// includes for wxWidgets
//--------------------------------------------------
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>

#include "Variable.hpp"

class BasicVariable;

template <class T>
class Variable;

class AMILabTreeModelNode;
WX_DEFINE_ARRAY_PTR( AMILabTreeModelNode*,AMILabTreeModelNodePtrArray );

/**
  * @brief  Nodes for the models for render on the wxDataViewCtrl wxWidgets
  *
  * A node inside AMILabTreeModel. Elements of node:
  * - Name: node name
  * - Type: node type
  * - Val: node value
  * - Details: node details
  * - Var: boost::weak_ptr to BasicVariable
  *
  * There are two types of nodes:
  * - Branch node: node with child nodes
  * - Leaf node: node that has zero child nodes
  */
class AMILabTreeModelNode
{
  public:
    /**
     * @brief The Class constructor
     *
     * Constructor definition for leaf nodes
     */
    AMILabTreeModelNode(AMILabTreeModelNode* parent, const wxString &name,
      const wxString &type, const wxString &val,  const wxString &details,
      boost::shared_ptr<BasicVariable> var
      )
    {
      m_parent = parent;

      m_Name = name;
      m_Type = type;
      m_Val = val;
      m_Details = details;
      m_Var = var;

      m_container = false;
    }

    /**
     * @brief The Class constructor
     *
     * Constructor definition for branch nodes
     */    
    AMILabTreeModelNode(AMILabTreeModelNode* parent, const wxString &branch)
    {
      m_parent = parent;

      m_Name = branch;
      m_Type = wxT("");
      m_Val = wxT("");
      m_Details = wxT("");
      m_Var = boost::weak_ptr<BasicVariable>();

      m_container = true;
    }

    /**
     * @brief The Class destructor
     *
     * Free all the children nodes
     */      
    ~AMILabTreeModelNode()
    {
      size_t count = m_children.GetCount();
      for (size_t i = 0; i < count; i++)
      {
          AMILabTreeModelNode *child = m_children[i];
          delete child;
      }
    }

    /**
     * @brief IsContainer
     *
     * Returns true if item is a container. Determines if it can have child items (is branch or leaf node?)
     */
    bool IsContainer() const
    { return m_container; }

    /**
     * @brief GetParent
     *
     * Get the parent of a item
     */ 
    AMILabTreeModelNode* GetParent()
    { return m_parent; }

    /**
     * @brief GetChildren
     *
     * Returns the children of item
     */
    AMILabTreeModelNodePtrArray& GetChildren()
    { return m_children; }

    /**
     * @brief GetNthChild
     *
     * Returns the nth child item of item
     */
    AMILabTreeModelNode* GetNthChild( unsigned int n )
    { return m_children.Item( n ); }

    /**
     * @brief Insert
     *
     * Inserts in the nth position a child item
     */
    void Insert( AMILabTreeModelNode* child, unsigned int n)
    { m_children.Insert( child, n); }

    /**
     * @brief Append
     *
     * Add a child item
     */
    void Append( AMILabTreeModelNode* child )
    { m_children.Add( child ); }

    /**
     * @brief GetChildCount
     *
     * Returns the number of childrens in the node
     */
    unsigned int GetChildCount() const
    { return m_children.GetCount(); }

public:     // public to avoid getters/setters
    wxString                        m_Name;
    wxString                        m_Type;
    wxString                        m_Val;
    wxString                        m_Details;
    boost::weak_ptr<BasicVariable>  m_Var;

    // TODO/FIXME:
    // the GTK version of wxDVC (in particular wxDataViewCtrlInternal::ItemAdded)
    // needs to know in advance if a node is or _will be_ a container.
    // Thus implementing:
    //   bool IsContainer() const
    //    { return m_children.GetCount()>0; }
    // doesn't work with wxGTK when MyMusicTreeModel::AddToClassical is called
    // AND the classical node was removed (a new node temporary without children
    // would be added to the control)
    bool m_container;

private:
    AMILabTreeModelNode          *m_parent;
    AMILabTreeModelNodePtrArray   m_children;
};

#endif // MYDATAVIEWNODES