
#include "amiDataViewTreeList.h"
#include <wx/log.h>

static wxDataViewItemAttr empty_attr = wxDataViewItemAttr();

//-----------------------------------------------------------------------------
// wxDataViewTreeListStore
//-----------------------------------------------------------------------------

//------------------------------------------------------------------------------
wxDataViewTreeListStoreNode::wxDataViewTreeListStoreNode(
        wxDataViewTreeListStoreNode *parent,
        const wxString &text, const wxIcon &icon, wxClientData *data )
{
    m_parent = parent;
    m_text = text;
    m_icon = icon;
    m_data = data;
/*    m_line_data.push_back(wxVariant(_T("")));
    m_line_data.push_back(wxVariant(_T("")));
    m_line_data.push_back(wxVariant(_T("")));
    m_line_data.push_back(wxVariant(_T("")));*/
}

//------------------------------------------------------------------------------
wxDataViewTreeListStoreNode::~wxDataViewTreeListStoreNode()
{
    if (m_data)
        delete m_data;
}


//------------------------------------------------------------------------------
void wxDataViewTreeListStoreNode::GetValue( wxVariant &value,
                                            unsigned int col ) const
{
  if (col<m_line_data.size())
    value = m_line_data[col];
  else
    value = wxVariant(_T(""));
}

//------------------------------------------------------------------------------
bool wxDataViewTreeListStoreNode::SetValue( const wxVariant &value,
                                            unsigned int col )
{
  if (col>=m_line_data.size()) {
    // fill with empty strings, should check variant type ...
    int init_size = m_line_data.size();
    m_line_data.resize(col+1);
    for(int i=init_size;i<=col-1;i++) {
      m_line_data[i] = wxVariant(wxEmptyString);
    }
  }
  m_line_data[col] = value;
  return true;
}

//------------------------------------------------------------------------------
void wxDataViewTreeListStoreNode::SetAttr( unsigned int col, 
                                           const wxDataViewItemAttr& attr)
{
  if (col>=m_line_attr.size()) {
    m_line_attr.resize(col+1);
  }
  m_line_attr[col] = attr;
}

//------------------------------------------------------------------------------
wxDataViewItemAttr& wxDataViewTreeListStoreNode::GetAttr(unsigned int col)
{
  if (col>=m_line_attr.size()) {
    m_line_attr.resize(col+1);
  }
  return m_line_attr[col];
}


#include "wx/listimpl.cpp"
WX_DEFINE_LIST(wxDataViewTreeListStoreNodeList)

wxDataViewTreeListStoreContainerNode::wxDataViewTreeListStoreContainerNode(
        wxDataViewTreeListStoreNode *parent, const wxString &text,
        const wxIcon &icon, const wxIcon &expanded, wxClientData *data ) :
    wxDataViewTreeListStoreNode( parent, text, icon, data )
{
    m_iconExpanded = expanded;
    m_isExpanded = false;
    m_children.DeleteContents(true);
}

wxDataViewTreeListStoreContainerNode::~wxDataViewTreeListStoreContainerNode()
{
}

//------------------------------------------------------------------------------
wxDataViewTreeListStore::wxDataViewTreeListStore()
{
    m_root = new wxDataViewTreeListStoreContainerNode( NULL, wxEmptyString );
}

//------------------------------------------------------------------------------
wxDataViewTreeListStore::~wxDataViewTreeListStore()
{
    delete m_root;
}

//------------------------------------------------------------------------------
bool wxDataViewTreeListStore::GetAttr ( const wxDataViewItem&  item,
                                        unsigned int col,
                                        wxDataViewItemAttr&  attr) const
{
  wxDataViewTreeListStoreNode *node = FindNode( item );
  if (!node) return false;
  attr = node->GetAttr(col);
  return true;
}

//------------------------------------------------------------------------------
void wxDataViewTreeListStore::PrependColumn( const wxString &varianttype )
{
    m_cols.Insert( varianttype, 0 );
}

//------------------------------------------------------------------------------
void wxDataViewTreeListStore::InsertColumn( unsigned int pos, 
                                            const wxString &varianttype )
{
    m_cols.Insert( varianttype, pos );
}

//------------------------------------------------------------------------------
void wxDataViewTreeListStore::AppendColumn( const wxString &varianttype )
{
    m_cols.Add( varianttype );
}

//------------------------------------------------------------------------------
unsigned int wxDataViewTreeListStore::GetColumnCount() const
{
  unsigned int n = m_cols.GetCount();
//  std::cout << "GetColumnCount() --> " << n << std::endl;
  return n;
}

//------------------------------------------------------------------------------
wxString wxDataViewTreeListStore::GetColumnType( unsigned int pos ) const
{
  std::cout   << "GetColumnType( " << pos << " )" << " --> " 
              << m_cols[pos] << std::endl;
  return m_cols[pos];
}

//------------------------------------------------------------------------------
wxDataViewItem wxDataViewTreeListStore::AppendItem( const wxDataViewItem& parent,
        const wxString &text, const wxIcon &icon, wxClientData *data )
{
    wxDataViewTreeListStoreContainerNode *parent_node = FindContainerNode( parent );
    if (!parent_node) return wxDataViewItem(0);

    wxDataViewTreeListStoreNode *node =
        new wxDataViewTreeListStoreNode( parent_node, text, icon, data );
    parent_node->GetChildren().Append( node );

    return node->GetItem();
}

//------------------------------------------------------------------------------
wxDataViewItem wxDataViewTreeListStore::PrependItem( const wxDataViewItem& parent,
        const wxString &text, const wxIcon &icon, wxClientData *data )
{
    wxDataViewTreeListStoreContainerNode *parent_node = FindContainerNode( parent );
    if (!parent_node) return wxDataViewItem(0);

    wxDataViewTreeListStoreNode *node =
        new wxDataViewTreeListStoreNode( parent_node, text, icon, data );
    parent_node->GetChildren().Insert( node );

    return node->GetItem();
}

//------------------------------------------------------------------------------
wxDataViewItem
wxDataViewTreeListStore::InsertItem(const wxDataViewItem& parent,
                                const wxDataViewItem& previous,
                                const wxString& text,
                                const wxIcon& icon,
                                wxClientData *data)
{
    wxDataViewTreeListStoreContainerNode *parent_node = FindContainerNode( parent );
    if (!parent_node) return wxDataViewItem(0);

    wxDataViewTreeListStoreNode *previous_node = FindNode( previous );
    int pos = parent_node->GetChildren().IndexOf( previous_node );
    if (pos == wxNOT_FOUND) return wxDataViewItem(0);

    wxDataViewTreeListStoreNode *node =
        new wxDataViewTreeListStoreNode( parent_node, text, icon, data );
    parent_node->GetChildren().Insert( (size_t) pos, node );

    return node->GetItem();
}

//------------------------------------------------------------------------------
wxDataViewItem wxDataViewTreeListStore::PrependContainer( const wxDataViewItem& parent,
        const wxString &text, const wxIcon &icon, const wxIcon &expanded,
        wxClientData *data )
{
    wxDataViewTreeListStoreContainerNode *parent_node = FindContainerNode( parent );
    if (!parent_node) return wxDataViewItem(0);

    wxDataViewTreeListStoreContainerNode *node =
        new wxDataViewTreeListStoreContainerNode( parent_node, text, icon, expanded, data );
    parent_node->GetChildren().Insert( node );

    return node->GetItem();
}

//------------------------------------------------------------------------------
wxDataViewItem
wxDataViewTreeListStore::AppendContainer(const wxDataViewItem& parent,
                                     const wxString &text,
                                     const wxIcon& icon,
                                     const wxIcon& expanded,
                                     wxClientData * data)
{
    wxDataViewTreeListStoreContainerNode *parent_node = FindContainerNode( parent );
    if (!parent_node) return wxDataViewItem(0);

    wxDataViewTreeListStoreContainerNode *node =
        new wxDataViewTreeListStoreContainerNode( parent_node, text, icon, expanded, data );
    parent_node->GetChildren().Append( node );

    return node->GetItem();
}

//------------------------------------------------------------------------------
wxDataViewItem
wxDataViewTreeListStore::InsertContainer(const wxDataViewItem& parent,
                                     const wxDataViewItem& previous,
                                     const wxString& text,
                                     const wxIcon& icon,
                                     const wxIcon& expanded,
                                     wxClientData * data)
{
    wxDataViewTreeListStoreContainerNode *parent_node = FindContainerNode( parent );
    if (!parent_node) return wxDataViewItem(0);

    wxDataViewTreeListStoreNode *previous_node = FindNode( previous );
    int pos = parent_node->GetChildren().IndexOf( previous_node );
    if (pos == wxNOT_FOUND) return wxDataViewItem(0);

    wxDataViewTreeListStoreContainerNode *node =
        new wxDataViewTreeListStoreContainerNode( parent_node, text, icon, expanded, data );
    parent_node->GetChildren().Insert( (size_t) pos, node );

    return node->GetItem();
}

//------------------------------------------------------------------------------
bool wxDataViewTreeListStore::IsContainer( const wxDataViewItem& item ) const
{
    wxDataViewTreeListStoreNode *node = FindNode( item );
    if (!node) return false;

    return node->IsContainer();
}

//------------------------------------------------------------------------------
wxDataViewItem wxDataViewTreeListStore::GetNthChild( const wxDataViewItem& parent, unsigned int pos ) const
{
    wxDataViewTreeListStoreContainerNode *parent_node = FindContainerNode( parent );
    if (!parent_node) return wxDataViewItem(0);

    wxDataViewTreeListStoreNodeList::compatibility_iterator node = parent_node->GetChildren().Item( pos );
    if (node)
        return wxDataViewItem(node->GetData());

    return wxDataViewItem(0);
}

//------------------------------------------------------------------------------
int wxDataViewTreeListStore::GetChildCount( const wxDataViewItem& parent ) const
{
    wxDataViewTreeListStoreNode *node = FindNode( parent );
    if (!node) return -1;

    if (!node->IsContainer())
        return 0;

    wxDataViewTreeListStoreContainerNode *container_node = (wxDataViewTreeListStoreContainerNode*) node;
    return (int) container_node->GetChildren().GetCount();
}

//------------------------------------------------------------------------------
void wxDataViewTreeListStore::SetItemText( const wxDataViewItem& item, const wxString &text )
{
    wxDataViewTreeListStoreNode *node = FindNode( item );
    if (!node) return;

    node->SetText( text );
}

//------------------------------------------------------------------------------
wxString wxDataViewTreeListStore::GetItemText( const wxDataViewItem& item ) const
{
    wxDataViewTreeListStoreNode *node = FindNode( item );
    if (!node) return wxEmptyString;

    return node->GetText();
}

//------------------------------------------------------------------------------
void wxDataViewTreeListStore::SetItemIcon( const wxDataViewItem& item, const wxIcon &icon )
{
    wxDataViewTreeListStoreNode *node = FindNode( item );
    if (!node) return;

    node->SetIcon( icon );
}

//------------------------------------------------------------------------------
const wxIcon &wxDataViewTreeListStore::GetItemIcon( const wxDataViewItem& item ) const
{
    wxDataViewTreeListStoreNode *node = FindNode( item );
    if (!node) return wxNullIcon;

    return node->GetIcon();
}

//------------------------------------------------------------------------------
void wxDataViewTreeListStore::SetItemExpandedIcon( const wxDataViewItem& item, const wxIcon &icon )
{
    wxDataViewTreeListStoreContainerNode *node = FindContainerNode( item );
    if (!node) return;

    node->SetExpandedIcon( icon );
}

//------------------------------------------------------------------------------
const wxIcon &wxDataViewTreeListStore::GetItemExpandedIcon( const wxDataViewItem& item ) const
{
    wxDataViewTreeListStoreContainerNode *node = FindContainerNode( item );
    if (!node) return wxNullIcon;

    return node->GetExpandedIcon();
}

//------------------------------------------------------------------------------
void wxDataViewTreeListStore::SetItemData( const wxDataViewItem& item, wxClientData *data )
{
    wxDataViewTreeListStoreNode *node = FindNode( item );
    if (!node) return;

    node->SetData( data );
}

//------------------------------------------------------------------------------
wxClientData *wxDataViewTreeListStore::GetItemData( const wxDataViewItem& item ) const
{
    wxDataViewTreeListStoreNode *node = FindNode( item );
    if (!node) return NULL;

    return node->GetData();
}

//------------------------------------------------------------------------------
void wxDataViewTreeListStore::DeleteItem( const wxDataViewItem& item )
{
    if (!item.IsOk()) return;

    wxDataViewItem parent_item = GetParent( item );

    wxDataViewTreeListStoreContainerNode *parent_node = FindContainerNode( parent_item );
    if (!parent_node) return;

    wxDataViewTreeListStoreContainerNode *node = FindContainerNode( item );
    if (!node) return;

    parent_node->GetChildren().DeleteObject( node );
}

//------------------------------------------------------------------------------
void wxDataViewTreeListStore::DeleteChildren( const wxDataViewItem& item )
{
    wxDataViewTreeListStoreContainerNode *node = FindContainerNode( item );
    if (!node) return;

    node->GetChildren().clear();
}

//------------------------------------------------------------------------------
void wxDataViewTreeListStore::DeleteAllItems()
{
    DeleteChildren(wxDataViewItem(m_root));
}

//------------------------------------------------------------------------------
// Set/Get cell attributes
void wxDataViewTreeListStore::SetAttr(
                              const wxDataViewItem &item,
                              unsigned int col, const 
                              wxDataViewItemAttr& attr)
{
  wxDataViewTreeListStoreNode *node = FindNode( item );
  if (!node) return;
  node->SetAttr(col,attr);
}

//------------------------------------------------------------------------------
wxDataViewItemAttr& wxDataViewTreeListStore::GetAttr(
                              const wxDataViewItem &item,
                              unsigned int col)
{
  wxDataViewTreeListStoreNode *node = FindNode( item );
  if (!node) return empty_attr; //wxDataViewItemAttr();
  return node->GetAttr(col);
}

//------------------------------------------------------------------------------
void
wxDataViewTreeListStore::GetValue(wxVariant &variant,
                              const wxDataViewItem &item,
                              unsigned int col) const
{
    // if (col != 0) return;
//std::cout << "GetValue for col " << col << " / " << GetColumnCount() << std::endl;
    wxDataViewTreeListStoreNode *node = FindNode( item );
    if (!node) return;

    if (col==0) 
    {
      wxIcon icon( node->GetIcon());
      if (node->IsContainer())
      {
          wxDataViewTreeListStoreContainerNode *container = (wxDataViewTreeListStoreContainerNode*) node;
          if (container->IsExpanded() && container->GetExpandedIcon().IsOk())
            icon = container->GetExpandedIcon();
      }
      wxDataViewIconText data( node->GetText(), icon );
      variant << data;
    } else {
      node->GetValue(variant,col);
    }
}

//------------------------------------------------------------------------------
bool
wxDataViewTreeListStore::SetValue(const wxVariant& variant,
                              const wxDataViewItem& item,
                              unsigned int col)
{

    wxDataViewTreeListStoreNode *node = FindNode( item );
    if (!node) return false;

    if (col==0) {
      wxDataViewIconText data;
      data << variant;
      node->SetText( data.GetText() );
      node->SetIcon( data.GetIcon() );
    } else {
      node->SetValue(variant, col);
    }

    return true;
}

//------------------------------------------------------------------------------
wxDataViewItem wxDataViewTreeListStore::GetParent( const wxDataViewItem &item ) const
{
    wxDataViewTreeListStoreNode *node = FindNode( item );
    if (!node) return wxDataViewItem(0);

    wxDataViewTreeListStoreNode *parent = node->GetParent();
    if (!parent) return wxDataViewItem(0);

    if (parent == m_root)
        return wxDataViewItem(0);

    return parent->GetItem();
}

//------------------------------------------------------------------------------
unsigned int wxDataViewTreeListStore::GetChildren( const wxDataViewItem &item, wxDataViewItemArray &children ) const
{
    wxDataViewTreeListStoreContainerNode *node = FindContainerNode( item );
    if (!node) return 0;

    wxDataViewTreeListStoreNodeList::iterator iter;
    for (iter = node->GetChildren().begin(); iter != node->GetChildren().end(); iter++)
    {
        wxDataViewTreeListStoreNode* child = *iter;
        children.Add( child->GetItem() );
    }

    return node->GetChildren().GetCount();
}

//------------------------------------------------------------------------------
int wxDataViewTreeListStore::Compare( const wxDataViewItem &item1, 
                                      const wxDataViewItem &item2,
                                      unsigned int column, 
                                      bool ascending ) const
{
    wxDataViewTreeListStoreNode *node1 = FindNode( item1 );
    wxDataViewTreeListStoreNode *node2 = FindNode( item2 );

    if (!node1 || !node2)
        return 0;

    wxDataViewTreeListStoreContainerNode* parent1 =
        (wxDataViewTreeListStoreContainerNode*) node1->GetParent();
    wxDataViewTreeListStoreContainerNode* parent2 =
        (wxDataViewTreeListStoreContainerNode*) node2->GetParent();

    if (parent1 != parent2)
    {
        wxLogError( wxT("Comparing items with different parent.") );
        return 0;
    }

    if (node1->IsContainer() && !node2->IsContainer())
        return -1;

    if (node2->IsContainer() && !node1->IsContainer())
        return 1;

/*    wxVariant value1, value2;
    GetValue( value1, item1, column );
    GetValue( value2, item2, column );

    wxString str1 = value1.GetString();
    wxString str2 = value2.GetString();
    int res = str1.Cmp( str2 );
    if (res) return res;

    // items must be different
    wxUIntPtr litem1 = (wxUIntPtr) item1.GetID();
    wxUIntPtr litem2 = (wxUIntPtr) item2.GetID();

    return litem1-litem2;*/
    return parent1->GetChildren().IndexOf( node1 ) - parent2->GetChildren().IndexOf( node2 );
}

//------------------------------------------------------------------------------
wxDataViewTreeListStoreNode *wxDataViewTreeListStore::FindNode( const wxDataViewItem &item ) const
{
    if (!item.IsOk())
        return m_root;

    return (wxDataViewTreeListStoreNode*) item.GetID();
}

//------------------------------------------------------------------------------
wxDataViewTreeListStoreContainerNode *wxDataViewTreeListStore::FindContainerNode( const wxDataViewItem &item ) const
{
    if (!item.IsOk())
        return (wxDataViewTreeListStoreContainerNode*) m_root;

    wxDataViewTreeListStoreNode* node = (wxDataViewTreeListStoreNode*) item.GetID();

    if (!node) return NULL;
    if (!node->IsContainer())
        return NULL;

    return (wxDataViewTreeListStoreContainerNode*) node;
}

//-----------------------------------------------------------------------------
// wxDataViewTreeListCtrl
//-----------------------------------------------------------------------------

IMPLEMENT_DYNAMIC_CLASS(wxDataViewTreeListCtrl,wxDataViewCtrl)

BEGIN_EVENT_TABLE(wxDataViewTreeListCtrl,wxDataViewCtrl)
   EVT_DATAVIEW_ITEM_EXPANDED(-1, wxDataViewTreeListCtrl::OnExpanded)
   EVT_DATAVIEW_ITEM_COLLAPSED(-1, wxDataViewTreeListCtrl::OnCollapsed)
   EVT_SIZE( wxDataViewTreeListCtrl::OnSize )
END_EVENT_TABLE()

bool wxDataViewTreeListCtrl::Create( wxWindow *parent, wxWindowID id,
           const wxPoint& pos, const wxSize& size, long style, 
           const wxValidator& validator,
           int num_columns )
{
    if ( !wxDataViewCtrl::Create( parent, id, pos, size, style, validator ) )
        return false;

     // create the standard model and a column in the tree
    wxDataViewTreeListStore *store = new wxDataViewTreeListStore;
    AssociateModel( store );
    store->DecRef();

    AppendIconTextColumn
    (
        wxString(),                 // no label (header is not shown anyhow)
        //0,                          // the only model column
        wxDATAVIEW_CELL_EDITABLE,
        -1,                         // default width
        wxALIGN_NOT,                //  and alignment
        1                           // not resizable
    );

    return true;
}


//------------------------------------------------------------------------------
bool wxDataViewTreeListCtrl::AppendColumn( wxDataViewColumn *column, 
                                       const wxString &varianttype )
{
    GetStore()->AppendColumn( varianttype );
    return wxDataViewCtrl::AppendColumn( column );
}

//------------------------------------------------------------------------------
bool wxDataViewTreeListCtrl::PrependColumn( wxDataViewColumn *column, 
                                            const wxString &varianttype )
{
//    GetStore()->PrependColumn( varianttype );
    return wxDataViewCtrl::PrependColumn( column );
}

//------------------------------------------------------------------------------
bool wxDataViewTreeListCtrl::InsertColumn( unsigned int pos, 
                                           wxDataViewColumn *column, 
                                           const wxString &varianttype )
{
//    GetStore()->InsertColumn( pos, varianttype );
    return wxDataViewCtrl::InsertColumn( pos, column );
}

//------------------------------------------------------------------------------
bool wxDataViewTreeListCtrl::PrependColumn( wxDataViewColumn *col )
{
    return PrependColumn( col, "string" );
}

//------------------------------------------------------------------------------
bool wxDataViewTreeListCtrl::InsertColumn( unsigned int pos, 
                                           wxDataViewColumn *col )
{
    return InsertColumn( pos, col, "string" );
}

//------------------------------------------------------------------------------
bool wxDataViewTreeListCtrl::AppendColumn( wxDataViewColumn *col )
{

  return AppendColumn( col, "string" );
}

//------------------------------------------------------------------------------
wxDataViewColumn *wxDataViewTreeListCtrl::AppendTextColumn( 
                                                    const wxString &label,
                                                    wxDataViewCellMode mode, 
                                                    int width, 
                                                    wxAlignment align, 
                                                    int flags )
{
    GetStore()->AppendColumn( wxT("string") );

    wxDataViewColumn *ret = new wxDataViewColumn( label,
        new wxDataViewTextRenderer( wxT("string"), mode ),
        GetStore()->GetColumnCount()-1, width, align, flags );

    wxDataViewCtrl::AppendColumn( ret );

    return ret;
}

//------------------------------------------------------------------------------
wxDataViewColumn *wxDataViewTreeListCtrl::AppendToggleColumn( 
                                                    const wxString &label,
                                                    wxDataViewCellMode mode, 
                                                    int width, 
                                                    wxAlignment align, 
                                                    int flags )
{
    GetStore()->AppendColumn( wxT("bool") );

    wxDataViewColumn *ret = new wxDataViewColumn( label,
        new wxDataViewToggleRenderer( wxT("bool"), mode ),
        GetStore()->GetColumnCount()-1, width, align, flags );

    wxDataViewCtrl::AppendColumn( ret );

    return ret;
}

//------------------------------------------------------------------------------
wxDataViewColumn *wxDataViewTreeListCtrl::AppendProgressColumn( 
                                                      const wxString &label,
                                                      wxDataViewCellMode mode, 
                                                      int width, 
                                                      wxAlignment align, 
                                                      int flags )
{
    GetStore()->AppendColumn( wxT("long") );

    wxDataViewColumn *ret = new wxDataViewColumn( label,
        new wxDataViewProgressRenderer( wxEmptyString, wxT("long"), mode ),
        GetStore()->GetColumnCount()-1, width, align, flags );

    wxDataViewCtrl::AppendColumn( ret );

    return ret;
}

//------------------------------------------------------------------------------
wxDataViewColumn *wxDataViewTreeListCtrl::AppendIconTextColumn( 
                                                      const wxString &label,
                                                      wxDataViewCellMode mode, 
                                                      int width, 
                                                      wxAlignment align, 
                                                      int flags )
{
    GetStore()->AppendColumn( wxT("wxDataViewIconText") );

    wxDataViewColumn *ret = new wxDataViewColumn( label,
        new wxDataViewIconTextRenderer( wxT("wxDataViewIconText"), mode ),
        GetStore()->GetColumnCount()-1, width, align, flags );

    wxDataViewCtrl::AppendColumn( ret );

    return ret;
}


//------------------------------------------------------------------------------
wxDataViewItem wxDataViewTreeListCtrl::AppendItem( const wxDataViewItem& parent,
        const wxString &text, int iconIndex, wxClientData *data )
{
    wxDataViewItem res = GetStore()->
        AppendItem( parent, text, GetImage(iconIndex), data );

    GetStore()->ItemAdded( parent, res );

    return res;
}

//------------------------------------------------------------------------------
wxDataViewItem wxDataViewTreeListCtrl::PrependItem( const wxDataViewItem& parent,
        const wxString &text, int iconIndex, wxClientData *data )
{
    wxDataViewItem res = GetStore()->
        PrependItem( parent, text, GetImage(iconIndex), data );

    GetStore()->ItemAdded( parent, res );

    return res;
}

//------------------------------------------------------------------------------
wxDataViewItem wxDataViewTreeListCtrl::InsertItem( 
                                                const wxDataViewItem& parent, 
                                                const wxDataViewItem& previous,
                                                const wxString &text, 
                                                int iconIndex, 
                                                wxClientData *data )
{
    wxDataViewItem res = GetStore()->
        InsertItem( parent, previous, text, GetImage(iconIndex), data );

    GetStore()->ItemAdded( parent, res );

    return res;
}

//------------------------------------------------------------------------------
wxDataViewItem wxDataViewTreeListCtrl::PrependContainer( 
                                                const wxDataViewItem& parent,
                                                const wxString &text, 
                                                int iconIndex, 
                                                int expandedIndex, 
                                                wxClientData *data )
{
    wxDataViewItem res = GetStore()->
        PrependContainer( parent, text,
                          GetImage(iconIndex), GetImage(expandedIndex), data );

    GetStore()->ItemAdded( parent, res );

    return res;
}

//------------------------------------------------------------------------------
wxDataViewItem wxDataViewTreeListCtrl::AppendContainer( const wxDataViewItem& parent,
        const wxString &text, int iconIndex, int expandedIndex, wxClientData *data )
{
    wxDataViewItem res = GetStore()->
        AppendContainer( parent, text,
                         GetImage(iconIndex), GetImage(expandedIndex), data );

    GetStore()->ItemAdded( parent, res );

    return res;
}

//------------------------------------------------------------------------------
wxDataViewItem wxDataViewTreeListCtrl::InsertContainer( const wxDataViewItem& parent, const wxDataViewItem& previous,
        const wxString &text, int iconIndex, int expandedIndex, wxClientData *data )
{
    wxDataViewItem res = GetStore()->
        InsertContainer( parent, previous, text,
                         GetImage(iconIndex), GetImage(expandedIndex), data );

    GetStore()->ItemAdded( parent, res );

    return res;
}

//------------------------------------------------------------------------------
void wxDataViewTreeListCtrl::SetItemText( const wxDataViewItem& item, const wxString &text )
{
    GetStore()->SetItemText(item,text);

    // notify control
    GetStore()->ValueChanged( item, 0 );
}

//------------------------------------------------------------------------------
void wxDataViewTreeListCtrl::SetItemIcon( const wxDataViewItem& item, const wxIcon &icon )
{
    GetStore()->SetItemIcon(item,icon);

    // notify control
    GetStore()->ValueChanged( item, 0 );
}

//------------------------------------------------------------------------------
void wxDataViewTreeListCtrl::SetItemExpandedIcon( const wxDataViewItem& item, const wxIcon &icon )
{
    GetStore()->SetItemExpandedIcon(item,icon);

    // notify control
    GetStore()->ValueChanged( item, 0 );
}

//------------------------------------------------------------------------------
void wxDataViewTreeListCtrl::DeleteItem( const wxDataViewItem& item )
{
    wxDataViewItem parent_item = GetStore()->GetParent( item );

    GetStore()->DeleteItem(item);

    // notify control
    GetStore()->ItemDeleted( parent_item, item );
}

//------------------------------------------------------------------------------
void wxDataViewTreeListCtrl::DeleteChildren( const wxDataViewItem& item )
{
    wxDataViewTreeListStoreContainerNode *node = GetStore()->FindContainerNode( item );
    if (!node) return;

    wxDataViewItemArray array;
    wxDataViewTreeListStoreNodeList::iterator iter;
    for (iter = node->GetChildren().begin(); iter != node->GetChildren().end(); iter++)
    {
        wxDataViewTreeListStoreNode* child = *iter;
        array.Add( child->GetItem() );
    }

    GetStore()->DeleteChildren( item );

    // notify control
    GetStore()->ItemsDeleted( item, array );
}

//------------------------------------------------------------------------------
void  wxDataViewTreeListCtrl::DeleteAllItems()
{
    GetStore()->DeleteAllItems();

    GetStore()->Cleared();
}

//------------------------------------------------------------------------------
void wxDataViewTreeListCtrl::OnExpanded( wxDataViewEvent &event )
{
    if (HasImageList()) return;

    wxDataViewTreeListStoreContainerNode* container = GetStore()->FindContainerNode( event.GetItem() );
    if (!container) return;

    container->SetExpanded( true );

    GetStore()->ItemChanged( event.GetItem() );
}

//------------------------------------------------------------------------------
void wxDataViewTreeListCtrl::OnCollapsed( wxDataViewEvent &event )
{
    if (HasImageList()) return;

    wxDataViewTreeListStoreContainerNode* container = GetStore()->FindContainerNode( event.GetItem() );
    if (!container) return;

    container->SetExpanded( false );

    GetStore()->ItemChanged( event.GetItem() );
}

//------------------------------------------------------------------------------
void wxDataViewTreeListCtrl::OnSize( wxSizeEvent &event )
{
#if defined(wxUSE_GENERICDATAVIEWCTRL)
    // automatically resize our only column to take the entire control width
    if ( GetColumnCount() )
    {
        wxSize size = GetClientSize();
        GetColumn(0)->SetWidth(size.x);
    }
#endif
    event.Skip( true );
}
