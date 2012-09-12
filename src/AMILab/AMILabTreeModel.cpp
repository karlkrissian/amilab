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

#include "AMILabTreeModel.h"
#include <boost/format.hpp>

///@cond wxCHECK
#if wxCHECK_VERSION(2,9,0)
//#include <wx/any.h>

// ----------------------------------------------------------------------------
// AMILabTreeModel
// ----------------------------------------------------------------------------
AMILabTreeModel::AMILabTreeModel()
{
  m_root = new AMILabTreeModelNode( NULL, "Root");
//  m_global = new AMILabTreeModelNode( m_root, "Global" );
//  m_builtin = new AMILabTreeModelNode( m_root, "Builtin" );

}

//------------------------------------------------------------------------------
wxString AMILabTreeModel::GetName( const wxDataViewItem &item ) const
{
  AMILabTreeModelNode *node = (AMILabTreeModelNode*) item.GetID();

  if (!node)      // happens if item.IsOk()==false
      return wxEmptyString;

  return node->m_Name;
}

//------------------------------------------------------------------------------
wxString AMILabTreeModel::GetType( const wxDataViewItem &item ) const
{
  AMILabTreeModelNode *node = (AMILabTreeModelNode*) item.GetID();

  if (!node)      // happens if item.IsOk()==false
      return wxEmptyString;

  return node->m_Type;
}

//------------------------------------------------------------------------------
wxString AMILabTreeModel::GetVal(  const wxDataViewItem &item ) const
{
  AMILabTreeModelNode *node = (AMILabTreeModelNode*) item.GetID();

  if (!node)      // happens if item.IsOk()==false
      return wxEmptyString;

  return node->m_Val;
}

//------------------------------------------------------------------------------
wxString AMILabTreeModel::GetDetails( const wxDataViewItem &item ) const
{
  AMILabTreeModelNode *node = (AMILabTreeModelNode*) item.GetID();

  if (!node)      // happens if item.IsOk()==false
      return wxEmptyString;

  return node->m_Details;
}

//------------------------------------------------------------------------------
boost::weak_ptr<BasicVariable> AMILabTreeModel::GetVar( const wxDataViewItem &item) const
{
  AMILabTreeModelNode *node = (AMILabTreeModelNode*) item.GetID();

  if (!node)      // happens if item.IsOk()==false
      return boost::weak_ptr<BasicVariable>();

  return node->m_Var;
}

//------------------------------------------------------------------------------
void AMILabTreeModel::SetVar (const wxDataViewItem &item,
  boost::shared_ptr<BasicVariable> var)
{
  AMILabTreeModelNode *node = (AMILabTreeModelNode*) item.GetID();

  if (!node)
    std::cout << "AMILabTreeModel::SetVar Cannot changes the value of the Var field"
              << std::endl;
  else
    node->m_Var = var;
}

//------------------------------------------------------------------------------
void AMILabTreeModel::SetContainer( const wxDataViewItem &item,
  const bool container  )
{
  AMILabTreeModelNode *node = (AMILabTreeModelNode*) item.GetID();

  if (!node)
    std::cout << "AMILabTreeModel::SetVar Cannot changes the value of the container field"
              << std::endl;
  else
    node->m_container = container;
}

//------------------------------------------------------------------------------
void AMILabTreeModel::Delete( const wxDataViewItem &item )
{
  AMILabTreeModelNode *node = (AMILabTreeModelNode*) item.GetID();

  if (!node)      // happens if item.IsOk()==false
      return;

  wxDataViewItem parent( node->GetParent() );
  if (!parent.IsOk())
  {
      wxASSERT(node == m_root);

      // don't make the control completely empty:
      std::cout << "AMILabTreeModel::Delete Cannot remove the root item!" << std::endl;
      return;
  }

  // is the node one of those we keep stored in special pointers?
  //LOOK AT THIS!!!
  if (node == m_root)
      m_root = NULL;
  else if (node == m_global)
      m_global = NULL;
  else if (node == m_builtin)
      m_builtin = NULL;

//   std::cout << "AMILabTreeModel::Delete: delete node: " << node->m_Name
//             << " (parent: " << node->GetParent()->m_Name << ")"
//             << std::endl;  

  // first remove the node from the parent's array of children;
  // NOTE: AMILabTreeModelNodePtrArray is only an array of _pointers_
  //       thus removing the node from it doesn't result in freeing it
  node->GetParent()->GetChildren().Remove( node );

  // free the node
  delete node;

  // notify control
  ItemDeleted( parent, item );
}

//------------------------------------------------------------------------------
int AMILabTreeModel::Compare( const wxDataViewItem &item1, const wxDataViewItem &item2,
  unsigned int column, bool ascending ) const
{
  wxASSERT(item1.IsOk() && item2.IsOk());
      // should never happen

  if (IsContainer(item1) && IsContainer(item2))
  {
      wxVariant value1, value2;
      GetValue( value1, item1, 0 );
      GetValue( value2, item2, 0 );

      wxString str1 = value1.GetString();
      wxString str2 = value2.GetString();
      int res = str1.Cmp( str2 );
      if (res) return res;

      // items must be different
      wxUIntPtr litem1 = (wxUIntPtr) item1.GetID();
      wxUIntPtr litem2 = (wxUIntPtr) item2.GetID();

      return litem1-litem2;
  }

  return wxDataViewModel::Compare( item1, item2, column, ascending );
}

//------------------------------------------------------------------------------
void AMILabTreeModel::GetValue( wxVariant &variant,
  const wxDataViewItem &item, unsigned int col ) const
{
  wxASSERT(item.IsOk());

  AMILabTreeModelNode *node = (AMILabTreeModelNode*) item.GetID();
  switch (col)
  {
    case 0:
      variant = node->m_Name;
      break;
    case 1:
      variant = node->m_Type;
      break;
    case 2:
      variant = node->m_Val;
      break;
    case 3:
      variant = node->m_Details;
      break;
    case 4:
      variant =  wxT("boost::weak_ptr<BasicVariable>");
      break;
    default:
      std::cout << "AMILabTreeModel::GetValue: wrong column "
                << col
                << std::endl;
  }
}

//------------------------------------------------------------------------------
bool AMILabTreeModel::SetValue( const wxVariant &variant,
  const wxDataViewItem &item, unsigned int col )
{
  wxASSERT(item.IsOk());

  AMILabTreeModelNode *node = (AMILabTreeModelNode*) item.GetID();
  switch (col)
  {
    case 0:
      node->m_Name = variant.GetString();
      return true;
    case 1:
      node->m_Type = variant.GetString();
      return true;
    case 2:
      node->m_Val = variant.GetString();
      return true;
    case 3:
      node->m_Details = variant.GetString();
      return true;
    case 4:
      //Do nothing
      break;      
    default:
      std::cout << "AMILabTreeModel::SetValue: wrong column" << std::endl;
  }
  return false;
}

//------------------------------------------------------------------------------
wxDataViewItem AMILabTreeModel::GetParent( const wxDataViewItem &item ) const
{
  if (!item.IsOk())
    return wxDataViewItem(0);

  AMILabTreeModelNode *node = (AMILabTreeModelNode*) item.GetID();

  // The root node has no parent
  if (node == m_root)
    return wxDataViewItem(0);

  return wxDataViewItem( (void*) node->GetParent() );
}

//------------------------------------------------------------------------------
bool AMILabTreeModel::IsContainer( const wxDataViewItem &item ) const
{
  if (!item.IsOk())
    return true;

  AMILabTreeModelNode *node = (AMILabTreeModelNode*) item.GetID();

  return node->IsContainer();
}

//------------------------------------------------------------------------------
unsigned int AMILabTreeModel::GetChildren( const wxDataViewItem &parent,
  wxDataViewItemArray &array ) const
{
  AMILabTreeModelNode *node = (AMILabTreeModelNode*) parent.GetID();

  if (!node)
  {
    array.Add( wxDataViewItem( (void*) m_root ) );
    return 1;
  }

  if (node->GetChildCount() == 0)
  {
    return 0;
  }

  unsigned int count = node->GetChildren().GetCount();
  for (unsigned int pos = 0; pos < count; pos++)
  {
    AMILabTreeModelNode *child = node->GetChildren().Item( pos );
    array.Add( wxDataViewItem( (void*) child ) );
  }

  return count;
}

//------------------------------------------------------------------------------
void AMILabTreeModel::DeleteChildren( const wxDataViewItem &item )
{
  AMILabTreeModelNode *node = (AMILabTreeModelNode*) item.GetID();

  if (!node)
    std::cout << "AMILabTreeModel::DeleteChildren Cannot remove the children nodes!"
              << std::endl;
  else
  {
    //wxDataViewItemArray children;
    //GetChildren(item,children);
    while (HasChildren(item))
    {
      AMILabTreeModelNode *child = node->GetChildren().Item(0);
      Delete( wxDataViewItem( (void*) child ) );
    }
    
    // notify control
    //ItemsDeleted(  item, children);
  }
}

//------------------------------------------------------------------------------
wxDataViewItem AMILabTreeModel::CreateLeafNode(
                                            const wxDataViewItem &parent,
                                            const wxString &name,
                                            const wxString &type,
                                            const wxString &val,
                                            const wxString &details,
                                            boost::weak_ptr<BasicVariable> var
                                          )
{
  AMILabTreeModelNode *parent_node = (AMILabTreeModelNode*) parent.GetID();
  std::cout << boost::format("CreateLeafNode with parent %1%") 
                % parent_node 
            << boost::format(" name = '%1%'") % name.c_str()
            << std::endl;

  if (!parent_node)
  {
    std::cout << "AMILabTreeModel::CreateLeafNode Cannot create the new leaf node!"
              << std::endl;
    return parent;
  }
  else
  {
    AMILabTreeModelNode* child_node =  new AMILabTreeModelNode( parent_node,
      name, type, val, details, var );
    parent_node->Append (child_node);

    // notify control
    wxDataViewItem Child( (void*) child_node );
    wxDataViewItem Parent( (void*) parent_node );
    ItemAdded( Parent, Child );

    std::cout << boost::format("Added item %1%") % Child.GetID() << std::endl;
    return Child;
  }
}

//------------------------------------------------------------------------------
wxDataViewItem AMILabTreeModel::CreateBranchNode(
                                            const wxDataViewItem &parent, 
                                            const wxString &name,
                                            const wxString &type, 
                                            const wxString &val,  
                                            const wxString &details,
                                            boost::weak_ptr<BasicVariable> var
                                          )
{
  AMILabTreeModelNode *parent_node = (AMILabTreeModelNode*) parent.GetID();
  std::cout << boost::format("CreateBranchNode with parent %1%") 
                % parent_node 
            << boost::format(" name = '%1%'") % name.c_str()
            << std::endl;

  if (!parent_node)
  {
    std::cout << "AMILabTreeModel::CreateBranchNode Cannot create the new branch node!"
              << std::endl;
    return parent;
  }
  else
  {
    AMILabTreeModelNode* child_node =  new AMILabTreeModelNode( 
                                                                parent_node,
                                                                name,
                                                                type,
                                                                val,
                                                                details,
                                                                var 
                                                              );
    child_node->SetContainer(true);
    parent_node->Append (child_node);

    // notify control
    wxDataViewItem Child( (void*) child_node );
    ItemAdded( parent, Child );

    std::cout << boost::format("Added item %1%") % Child.GetID() << std::endl;
    return Child;
  }
}

//------------------------------------------------------------------------------
bool AMILabTreeModel::HasChildren(const wxDataViewItem &item) const
{
  AMILabTreeModelNode *node = (AMILabTreeModelNode*) item.GetID();

  if (!node)
  {
    std::cout << "AMILabTreeModel::HasChildren Cannot determine if the node has children!"
              << std::endl;
    return false;
  }
  else
    return (node->GetChildren().GetCount() > 0);
}

//------------------------------------------------------------------------------
bool AMILabTreeModel::GetAttr ( const wxDataViewItem &  item,
  unsigned int col, wxDataViewItemAttr &  attr) const
{
  AMILabTreeModelNode *node = (AMILabTreeModelNode*) item.GetID();

  if (!node)
  {
    std::cout << "AMILabTreeModel::GetAttr Cannot get the attributes of the item!"
              << std::endl;
    return false;
  }
  else
  {
    if ((node == m_root) || (node == m_global) || (node == m_builtin))
    {
      attr.SetBold(true);
      attr.SetColour(*wxBLACK);
    }
    else
    {
      if (node->IsContainer()) 
      {
        boost::shared_ptr<BasicVariable> variable = node->m_Var.lock();
        if (!variable.get())
        {
          attr.SetItalic(true);
          attr.SetColour(*wxBLUE);
        }
      }
    }    
  }
  return true;
}

//------------------------------------------------------------------------------
void AMILabTreeModel::BuildAbsoluteName( const wxDataViewItem & item )
{
  AMILabTreeModelNode *node = (AMILabTreeModelNode*) item.GetID();

  if (!node)
    std::cout << "AMILabTreeModel::BuildAbsoluteName Cannot build the full name of the item!"
              << std::endl;
  else
  {
    boost::shared_ptr<BasicVariable> variable = node->m_Var.lock();

    if ((node->m_Name != m_global->m_Name) &&
        (node->m_Name != m_builtin->m_Name) && (variable.get()))
    {
      AMILabTreeModelNode *child = node->GetParent();
      wxString name = node->m_AbsoluteName;

      while ((child->m_Name != m_global->m_Name) && (child->m_Name != m_builtin->m_Name))
      {
        variable = child->m_Var.lock();

        if (variable.get())
          name = child->m_Name + "." + name;

        child = child->GetParent();
      }

      if (child->m_Name == m_global->m_Name)
        node->m_AbsoluteName = m_global->m_Name.Lower() + "::" + name;
      else
        node->m_AbsoluteName = name;
    }
  }
}

//------------------------------------------------------------------------------
wxDataViewItem AMILabTreeModel::GetRootNode() const
{
  return wxDataViewItem( (void*) m_root );
}

//------------------------------------------------------------------------------
wxDataViewItem AMILabTreeModel::GetGlobalNode() const
{
  return wxDataViewItem( (void*) m_global );
}

//------------------------------------------------------------------------------
wxDataViewItem AMILabTreeModel::GetBuiltinNode() const
{
  return wxDataViewItem( (void*) m_builtin );
}

#endif
/// @endcond