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

// ----------------------------------------------------------------------------
// AMILabTreeModelNode: a node inside AMILabTreeModel
//  Columns:
//    - Name: wxString of 250 characters wide (Node name).
//    - Type: wxString of 100 characters wide(Node type).
//    - Val: wxString of 60 characters wide (Node value).
//    - Details: wxString of 250 characters wide (Node details).
//    - Var: boost::weak_ptr to BasicVariable.
//  There are two types of nodes:
//    - Branch node: Node with child nodes.
//    - Leaf node: Node that has zero child nodes.
// ----------------------------------------------------------------------------

class AMILabTreeModelNode;
WX_DEFINE_ARRAY_PTR( AMILabTreeModelNode*,AMILabTreeModelNodePtrArray );

class AMILabTreeModelNode
{
  public:
    // -------------------------------------------------------------------------
    // AMILabTreeModelNode: Constructor definition for leaf nodes
    // -------------------------------------------------------------------------
    AMILabTreeModelNode(AMILabTreeModelNode* parent, const wxString &name,
      const wxString &type, const wxString &val,  const wxString &details/*,
      boost::shared_ptr<BasicVariable> var)*/
      )
    {
      m_parent = parent;

      //std::cout <<"Name: "<<name<<" Type: "<<type<<" Val: "<<val<<" Details: "<<details<<std::endl;
      m_Name = name;
      m_Type = type;
      m_Val = val;
      m_Details = details;
//      m_Var = var;

     // std::cout <<"Name: "<<m_Name<<" Type: "<<m_Type<<" Val: "<<m_Val<<" Details: "<<m_Details<<std::endl;
      
      m_container = false;
    }

    // -------------------------------------------------------------------------
    // AMILabTreeModelNode: Constructor definition for nodes branch
    // -------------------------------------------------------------------------
    AMILabTreeModelNode(AMILabTreeModelNode* parent, const wxString &branch)
    {
      m_parent = parent;

      m_Name = branch;
      m_Type = wxT("");
      m_Val = wxT("");
      m_Details = wxT("");
//      m_Var = boost::weak_ptr<BasicVariable>();

      m_container = true;
    }

    // -------------------------------------------------------------------------
    // ~AMILabTreeModelNode: Destructor definition
    // -------------------------------------------------------------------------
    ~AMILabTreeModelNode()
    {
      // free all our children nodes
      size_t count = m_children.GetCount();
      for (size_t i = 0; i < count; i++)
      {
          AMILabTreeModelNode *child = m_children[i];
          delete child;
      }
    }

    bool IsContainer() const
    { return m_container; }

    AMILabTreeModelNode* GetParent()
    { return m_parent; }

    AMILabTreeModelNodePtrArray& GetChildren()
    { return m_children; }

    AMILabTreeModelNode* GetNthChild( unsigned int n )
    { return m_children.Item( n ); }

    void Insert( AMILabTreeModelNode* child, unsigned int n)
    { m_children.Insert( child, n); }

    void Append( AMILabTreeModelNode* child )
    { m_children.Add( child ); }

    unsigned int GetChildCount() const
    { return m_children.GetCount(); }

public:     // public to avoid getters/setters
    wxString                        m_Name;
    wxString                        m_Type;
    wxString                        m_Val;
    wxString                        m_Details;
//    boost::weak_ptr<BasicVariable>  m_Var;

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