// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//


#if !defined(AFX_STDAFX_H__9E17F9F2_05DF_4980_BDD4_4B52E7886C2D__INCLUDED_)
#define AFX_STDAFX_H__9E17F9F2_05DF_4980_BDD4_4B52E7886C2D__INCLUDED_

#ifdef _UNICODE
 #undef _UNICODE
 #define _UNICODE_BAK
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma warning( disable : 4018 )

#include <afxwin.h>         // MFC core and standard components

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers
#define STRICT
#define WINVER 0x0501

// uncomment the following line to enable the use of GDI+ features
// Karl Krissian 04/05/2009 uncomment the USE_GDIPLUS line
#define USE_GDIPLUS


  


#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls

#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxsock.h>		// MFC socket extensions
#ifdef USE_GDIPLUS
#include <gdiplus.h>
#endif

#undef  ON_MESSAGE
#define ON_MESSAGE(message, memberFxn)    \
   { message, 0, 0, 0, AfxSig_lwl, \
       (AFX_PMSG) (AFX_PMSGW) (static_cast< LRESULT (AFX_MSG_CALL CWnd::*)(WPARAM, LPARAM) > (&memberFxn)) },

#undef  ON_REGISTERED_MESSAGE
#define ON_REGISTERED_MESSAGE(nMessageVariable, memberFxn) \
  { 0xC000, 0, 0, 0, (UINT)(UINT*)(&nMessageVariable), \
     (AFX_PMSG)(AFX_PMSGW)(static_cast<LRESULT (AFX_MSG_CALL CWnd::*)(WPARAM, LPARAM)>(&memberFxn)) },

#undef  ON_THREAD_MESSAGE
#define ON_THREAD_MESSAGE(message, memberFxn) \
  { message, 0, 0, 0, AfxSig_vwl, \
     (AFX_PMSG)(AFX_PMSGT)(static_cast<void (AFX_MSG_CALL CWinThread::*)(WPARAM, LPARAM)>(&memberFxn)) },

#undef  ON_REGISTERED_THREAD_MESSAGE
#define ON_REGISTERED_THREAD_MESSAGE(nMessageVariable, memberFxn) \
  { 0xC000, 0, 0, 0, (UINT)(UINT*)(&nMessageVariable), \
     (AFX_PMSG)(AFX_PMSGT)(static_cast<void (AFX_MSG_CALL WinThread::*)(WPARAM, LPARAM)>(&memberFxn)) },

#include "RPCore.h"

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.


#ifdef _UNICODE_BAK
 #define _UNICODE
#endif

#endif // !defined(AFX_STDAFX_H__9E17F9F2_05DF_4980_BDD4_4B52E7886C2D__INCLUDED_)
