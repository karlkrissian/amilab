
#pragma once
#ifndef _amiDataViewTreeList_h
#define _amiDataViewTreeList_h

#include <wx/dataview.h>


//-----------------------------------------------------------------------------
// wxDataViewTreeListStore
//-----------------------------------------------------------------------------

class WXDLLIMPEXP_ADV wxDataViewTreeListStoreNode
{
public:
    wxDataViewTreeListStoreNode( wxDataViewTreeListStoreNode *parent,
        const wxString &text, const wxIcon &icon = wxNullIcon, wxClientData *data = NULL );
    virtual ~wxDataViewTreeListStoreNode();

    void SetText( const wxString &text )
        { m_text = text; }
    wxString GetText() const
        { return m_text; }
    void SetIcon( const wxIcon &icon )
        { m_icon = icon; }
    const wxIcon &GetIcon() const
        { return m_icon; }
    void SetData( wxClientData *data )
        { if (m_data) delete m_data; m_data = data; }
    wxClientData *GetData() const
        { return m_data; }

    wxDataViewItem GetItem() const
        { return wxDataViewItem( (void*) this ); }

    virtual bool IsContainer()
        { return false; }

    wxDataViewTreeListStoreNode *GetParent()
        { return m_parent; }

    virtual void GetValue( wxVariant &value,
                           unsigned int col ) const;

    virtual bool SetValue( const wxVariant &value,
                           unsigned int col );

    void SetAttr( unsigned int col, const wxDataViewItemAttr& attr);
    wxDataViewItemAttr& GetAttr(unsigned int col);
    
private:
    wxDataViewTreeListStoreNode  *m_parent;
    wxString                      m_text;
    wxIcon                        m_icon;
    wxClientData                 *m_data;
    wxVector<wxVariant>           m_line_data;
    // store cell attributes
    wxVector<wxDataViewItemAttr>  m_line_attr;
};

WX_DECLARE_LIST_WITH_DECL(wxDataViewTreeListStoreNode, wxDataViewTreeListStoreNodeList,
                          class WXDLLIMPEXP_ADV);

class WXDLLIMPEXP_ADV wxDataViewTreeListStoreContainerNode: public wxDataViewTreeListStoreNode
{
public:
    wxDataViewTreeListStoreContainerNode( wxDataViewTreeListStoreNode *parent,
        const wxString &text, const wxIcon &icon = wxNullIcon, const wxIcon &expanded = wxNullIcon,
        wxClientData *data = NULL );
    virtual ~wxDataViewTreeListStoreContainerNode();

    const wxDataViewTreeListStoreNodeList &GetChildren() const
        { return m_children; }
    wxDataViewTreeListStoreNodeList &GetChildren()
        { return m_children; }

    void SetExpandedIcon( const wxIcon &icon )
        { m_iconExpanded = icon; }
    const wxIcon &GetExpandedIcon() const
        { return m_iconExpanded; }

    void SetExpanded( bool expanded = true )
        { m_isExpanded = expanded; }
    bool IsExpanded() const
        { return m_isExpanded; }

    virtual bool IsContainer()
        { return true; }

private:
    wxDataViewTreeListStoreNodeList  m_children;
    wxIcon                       m_iconExpanded;
    bool                         m_isExpanded;
};

//-----------------------------------------------------------------------------

class WXDLLIMPEXP_ADV wxDataViewTreeListStore: public wxDataViewModel
{
public:
    wxDataViewTreeListStore();
    ~wxDataViewTreeListStore();

    void PrependColumn( const wxString &varianttype );
    void InsertColumn( unsigned int pos, const wxString &varianttype );
    void AppendColumn( const wxString &varianttype );

    virtual unsigned int GetColumnCount() const;
    virtual wxString     GetColumnType( unsigned int col ) const;

    virtual bool HasContainerColumns(const wxDataViewItem &item) const 
    { return true; }
    
    /**
     * @brief GetAttr
     * @param item The item for which the attribute is requested.
     * @param col The column of the item for which the attribute is requested.
     * @param attr The attribute to be filled in if the function returns true.
     *
     * Gets the attributes of an item.
     */     
    bool GetAttr ( const wxDataViewItem &  item,
      unsigned int col, wxDataViewItemAttr &  attr) const;

    wxDataViewItem AppendItem(  const wxDataViewItem& parent,
                                const wxString &text, 
                                const wxIcon &icon = wxNullIcon, 
                                wxClientData *data = NULL );
    wxDataViewItem PrependItem( const wxDataViewItem& parent,
                                const wxString &text, 
                                const wxIcon &icon = wxNullIcon, 
                                wxClientData *data = NULL );
    wxDataViewItem InsertItem(  const wxDataViewItem& parent, 
                                const wxDataViewItem& previous,
                                const wxString &text, 
                                const wxIcon &icon = wxNullIcon, 
                                wxClientData *data = NULL );

    wxDataViewItem PrependContainer( const wxDataViewItem& parent,
                                     const wxString &text, 
                                     const wxIcon &icon = wxNullIcon, 
                                     const wxIcon &expanded = wxNullIcon,
        wxClientData *data = NULL );
    wxDataViewItem AppendContainer( const wxDataViewItem& parent,
                                    const wxString &text, 
                                    const wxIcon &icon = wxNullIcon, 
                                    const wxIcon &expanded = wxNullIcon,
                                    wxClientData *data = NULL );
    wxDataViewItem InsertContainer( const wxDataViewItem& parent, 
                                    const wxDataViewItem& previous,
                                    const wxString &text,
                                    const wxIcon &icon = wxNullIcon,
                                    const wxIcon &expanded = wxNullIcon,
        wxClientData *data = NULL );

    wxDataViewItem GetNthChild( const wxDataViewItem& parent, unsigned int pos ) const;
    int GetChildCount( const wxDataViewItem& parent ) const;

    void SetItemText( const wxDataViewItem& item, const wxString &text );
    wxString GetItemText( const wxDataViewItem& item ) const;
    void SetItemIcon( const wxDataViewItem& item, const wxIcon &icon );
    const wxIcon &GetItemIcon( const wxDataViewItem& item ) const;
    void SetItemExpandedIcon( const wxDataViewItem& item, const wxIcon &icon );
    const wxIcon &GetItemExpandedIcon( const wxDataViewItem& item ) const;
    void SetItemData( const wxDataViewItem& item, wxClientData *data );
    wxClientData *GetItemData( const wxDataViewItem& item ) const;

    void DeleteItem( const wxDataViewItem& item );
    void DeleteChildren( const wxDataViewItem& item );
    void DeleteAllItems();

    // Set/Get cell attributes
    void SetAttr(                 const wxDataViewItem &item,
                                  unsigned int col, const 
                                  wxDataViewItemAttr& attr);

    wxDataViewItemAttr& GetAttr(  const wxDataViewItem &item,
                                  unsigned int col);

    // implement base methods

    virtual void GetValue( wxVariant &variant,
                           const wxDataViewItem &item, unsigned int col ) const;
    virtual bool SetValue( const wxVariant &variant,
                           const wxDataViewItem &item, unsigned int col );
    virtual wxDataViewItem GetParent( const wxDataViewItem &item ) const;
    virtual bool IsContainer( const wxDataViewItem &item ) const;
    virtual unsigned int GetChildren( const wxDataViewItem &item, wxDataViewItemArray &children ) const;

    virtual int Compare( const wxDataViewItem &item1, const wxDataViewItem &item2,
                         unsigned int column, bool ascending ) const;

    virtual bool HasDefaultCompare() const
    // comparing is slow ...
        { return false; }

    wxDataViewTreeListStoreNode *FindNode( const wxDataViewItem &item ) const;
    wxDataViewTreeListStoreContainerNode *FindContainerNode( const wxDataViewItem &item ) const;
    wxDataViewTreeListStoreNode *GetRoot() const { return m_root; }

public:
    wxDataViewTreeListStoreNode *m_root;
    wxArrayString                m_cols;
};

//-----------------------------------------------------------------------------

class WXDLLIMPEXP_ADV wxDataViewTreeListCtrl: public wxDataViewCtrl,
                                          public wxWithImages
{
public:
    wxDataViewTreeListCtrl() { }
    wxDataViewTreeListCtrl(wxWindow *parent,
                          wxWindowID id,
                          const wxPoint& pos = wxDefaultPosition,
                          const wxSize& size = wxDefaultSize,
                          long style = wxDV_NO_HEADER | wxDV_ROW_LINES,
                          const wxValidator& validator = wxDefaultValidator,
                          int num_columns=1
                          )
    {
        Create(parent, id, pos, size, style, validator,num_columns);
    }

    bool Create(wxWindow *parent,
                wxWindowID id,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxDV_NO_HEADER | wxDV_ROW_LINES,
                const wxValidator& validator = wxDefaultValidator,
                int num_columns=1
               );

    wxDataViewTreeListStore *GetStore()
        { return (wxDataViewTreeListStore*) GetModel(); }
    const wxDataViewTreeListStore *GetStore() const
        { return (const wxDataViewTreeListStore*) GetModel(); }

    bool IsContainer( const wxDataViewItem& item ) const
        { return GetStore()->IsContainer(item); }

    // Deal with columns
    bool AppendColumn( wxDataViewColumn *column, const wxString &varianttype );
    bool PrependColumn( wxDataViewColumn *column, const wxString &varianttype );
    bool InsertColumn( unsigned int pos, wxDataViewColumn *column, const wxString &varianttype );

    // overridden from base class
    virtual bool PrependColumn( wxDataViewColumn *col );
    virtual bool InsertColumn( unsigned int pos, wxDataViewColumn *col );
    virtual bool AppendColumn( wxDataViewColumn *col );

    wxDataViewColumn *AppendTextColumn( const wxString &label,
          wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT,
          int width = -1, wxAlignment align = wxALIGN_LEFT, int flags = wxDATAVIEW_COL_RESIZABLE );
    wxDataViewColumn *AppendToggleColumn( const wxString &label,
          wxDataViewCellMode mode = wxDATAVIEW_CELL_ACTIVATABLE,
          int width = -1, wxAlignment align = wxALIGN_LEFT, int flags = wxDATAVIEW_COL_RESIZABLE );
    wxDataViewColumn *AppendProgressColumn( const wxString &label,
          wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT,
          int width = -1, wxAlignment align = wxALIGN_LEFT, int flags = wxDATAVIEW_COL_RESIZABLE );
    wxDataViewColumn *AppendIconTextColumn( const wxString &label,
          wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT,
          int width = -1, wxAlignment align = wxALIGN_LEFT, int flags = wxDATAVIEW_COL_RESIZABLE );


    wxDataViewItem AppendItem( const wxDataViewItem& parent,
        const wxString &text, int icon = NO_IMAGE, wxClientData *data = NULL );
    wxDataViewItem PrependItem( const wxDataViewItem& parent,
        const wxString &text, int icon = NO_IMAGE, wxClientData *data = NULL );
    wxDataViewItem InsertItem( const wxDataViewItem& parent, const wxDataViewItem& previous,
        const wxString &text, int icon = NO_IMAGE, wxClientData *data = NULL );

    wxDataViewItem PrependContainer( const wxDataViewItem& parent,
        const wxString &text, int icon = NO_IMAGE, int expanded = NO_IMAGE,
        wxClientData *data = NULL );
    wxDataViewItem AppendContainer( const wxDataViewItem& parent,
        const wxString &text, int icon = NO_IMAGE, int expanded = NO_IMAGE,
        wxClientData *data = NULL );
    wxDataViewItem InsertContainer( const wxDataViewItem& parent, const wxDataViewItem& previous,
        const wxString &text, int icon = NO_IMAGE, int expanded = NO_IMAGE,
        wxClientData *data = NULL );

    wxDataViewItem GetNthChild( const wxDataViewItem& parent, unsigned int pos ) const
        { return GetStore()->GetNthChild(parent, pos); }
    int GetChildCount( const wxDataViewItem& parent ) const
        { return GetStore()->GetChildCount(parent); }

    void SetItemText( const wxDataViewItem& item, const wxString &text );
    wxString GetItemText( const wxDataViewItem& item ) const
        { return GetStore()->GetItemText(item); }
    void SetItemIcon( const wxDataViewItem& item, const wxIcon &icon );
    const wxIcon &GetItemIcon( const wxDataViewItem& item ) const
        { return GetStore()->GetItemIcon(item); }
    void SetItemExpandedIcon( const wxDataViewItem& item, const wxIcon &icon );
    const wxIcon &GetItemExpandedIcon( const wxDataViewItem& item ) const
        { return GetStore()->GetItemExpandedIcon(item); }
    void SetItemData( const wxDataViewItem& item, wxClientData *data )
        { GetStore()->SetItemData(item,data); }
    wxClientData *GetItemData( const wxDataViewItem& item ) const
        { return GetStore()->GetItemData(item); }

    // Set/Get cell attributes
    void SetAttr(                 const wxDataViewItem &item,
                                  unsigned int col, const 
                                  wxDataViewItemAttr& attr)
    {
      GetStore()->SetAttr(item,col,attr);
    }

    wxDataViewItemAttr& GetAttr(  const wxDataViewItem &item,
                                  unsigned int col)
    {
      return GetStore()->GetAttr(item,col);
    }

    void GetValue( wxVariant &variant,
                   const wxDataViewItem &item, unsigned int col ) const
    {
      GetStore()->GetValue(variant,item,col);
    }
    bool SetValue( const wxVariant &variant,
                   const wxDataViewItem &item, unsigned int col )
    {
      bool res = GetStore()->SetValue(variant,item,col);
      if (res)
      {
        GetStore()->ItemChanged(item);
        GetStore()->ValueChanged(item,col);
      }
      return res;
    }

    void DeleteItem( const wxDataViewItem& item );
    void DeleteChildren( const wxDataViewItem& item );
    void DeleteAllItems();

    void OnExpanded( wxDataViewEvent &event );
    void OnCollapsed( wxDataViewEvent &event );
    void OnSize( wxSizeEvent &event );

private:
    DECLARE_EVENT_TABLE()
    DECLARE_DYNAMIC_CLASS_NO_ASSIGN(wxDataViewTreeListCtrl)
};

#endif 
