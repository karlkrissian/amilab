//
// C++ Interface: DragAndDrop
//
// Description: Drag and drop operation for wxTreeCtrl.
//
//
// Author:  <Karl Krissian>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef DRAGANDDROP_H
#define DRAGANDDROP_H

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "wx/dnd.h"
#include "wx/dataobj.h"

#include "xmtext.hpp"

#include "Variable.hpp"

class BasicVariable;

template <class T>
class Variable;

// ----------------------------------------------------------------------------
// MyNode
// ----------------------------------------------------------------------------
class MyNode
{
  public:
    MyNode()
    {
      m_absoluteName = wxEmptyString;
      m_var = boost::weak_ptr<BasicVariable>();
    }
    
    MyNode(const wxString & name, boost::shared_ptr<BasicVariable> var)
    {
      m_absoluteName = name;
      m_var = var;
    }

    boost::weak_ptr<BasicVariable> GetVar() const { return m_var; }
    
    wxString GetAbsoluteName() const { return m_absoluteName; }

    void SetVar( boost::shared_ptr<BasicVariable> var)
    {
      m_var = var;
    }

    void SetAbsoluteName(const wxString & name)
    {
      m_absoluteName = name;
    }

  private:
    wxString                        m_absoluteName;
    boost::weak_ptr<BasicVariable>  m_var;
};

// ----------------------------------------------------------------------------
// NodeFormatId: the Id format
// ----------------------------------------------------------------------------
static const wxChar* NodeFormatId = wxT("amilab:NodeData");

// ----------------------------------------------------------------------------
// MyNodeDataObject
// ----------------------------------------------------------------------------
class MyNodeDataObject : public wxDataObjectSimple
{
  public:
    MyNodeDataObject() : wxDataObjectSimple(NodeFormatId)
    {
      m_formatNode = NodeFormatId;
    }

    MyNodeDataObject(const MyNode& node) : wxDataObjectSimple(NodeFormatId)
    {
      m_node.SetAbsoluteName(node.GetAbsoluteName());
      m_node.SetVar(node.GetVar().lock());
      m_formatNode = NodeFormatId;
    }

    MyNode GetNode() const { return m_node; }
    void SetNode(const MyNode & node)
    {
      m_node.SetAbsoluteName(node.GetAbsoluteName());
      m_node.SetVar(node.GetVar().lock());
    }

    ///Gets the size of our data.
    virtual size_t GetDataSize() const { return GetDataSize(); }

    ///Copy the data to the buffer, return true on success.
    virtual bool GetDataHere(void *buf) const { return GetDataHere(buf); }

    ///Copy the data from the buffer, return true on success.
    virtual bool SetData(size_t len, const void *buf) { return SetData(len, buf); }

    ///Returns the (one and only one) format supported by this object.
    const wxDataFormat &  GetFormat () const { return m_formatNode; }

    ///Sets the supported format. 
    void  SetFormat (const wxDataFormat &format) { m_formatNode = format; }

  private:
    wxDataFormat  m_formatNode; // our custom format
    MyNode        m_node;       // our data
};

// ----------------------------------------------------------------------------
// MyNodeDropTarget
// ----------------------------------------------------------------------------
class MyNodeDropTarget : public wxDropTarget
{
public:
    MyNodeDropTarget() :wxDropTarget() {};

    virtual bool OnDrop(wxCoord x, wxCoord y, const MyNode & node) = 0;

    virtual wxDragResult OnData(wxCoord x, wxCoord y, wxDragResult def)
    {
        if ( !GetData() )
        {
            std::cout <<"Failed to get drag and drop data"<<std::endl;

            return wxDragNone;
        }

        return def;
    }    

};

// ----------------------------------------------------------------------------
// TextControlDropTarget: dragging text to TextControl.
// ----------------------------------------------------------------------------

class TextControlDropTarget : public wxDropTarget
{
  public:
    TextControlDropTarget(TextControl *pOwner) {
      m_pOwner = pOwner;
    }

    virtual bool OnDropNode(wxCoord x, wxCoord y, const MyNode& node);

    virtual wxDragResult OnEnter(wxCoord x, wxCoord y, wxDragResult def);

    virtual wxDragResult OnData(wxCoord x, wxCoord y, wxDragResult def)
    {
        if ( !GetData() )
        {
            std::cout <<"Failed to get drag and drop data"<<std::endl;

            return wxDragNone;
        }
        

        return def;
    }    

  private:
    TextControl* m_pOwner;
};

// ----------------------------------------------------------------------------
// TextControlTextDropTarget: dragging text to TextControl.
// ----------------------------------------------------------------------------

class TextControlTextDropTarget : public wxTextDropTarget
{
  public:
    TextControlTextDropTarget(TextControl *pOwner) {
      m_pOwner = pOwner;
    }

    virtual bool OnDropText(wxCoord x, wxCoord y, const wxString& text);

    virtual wxDragResult OnEnter(wxCoord x, wxCoord y, wxDragResult def);

  private:
    TextControl* m_pOwner;
};

#endif // DRAGANDDROP_H
