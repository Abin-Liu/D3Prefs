// D3Prefs.h : main header file for the D3PREFS application
//

#if !defined(AFX_D3PREFS_H__A2748BBC_9955_41EE_A633_CD6404EF3F38__INCLUDED_)
#define AFX_D3PREFS_H__A2748BBC_9955_41EE_A633_CD6404EF3F38__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "WinAppEx.h"

/////////////////////////////////////////////////////////////////////////////
// CD3PrefsApp:
// See D3Prefs.cpp for the implementation of this class
//

class CD3PrefsApp : public CWinAppEx
{
public:
	CD3PrefsApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CD3PrefsApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CD3PrefsApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_D3PREFS_H__A2748BBC_9955_41EE_A633_CD6404EF3F38__INCLUDED_)
