// D3Prefs.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "D3Prefs.h"
#include "D3PrefsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CD3PrefsApp

BEGIN_MESSAGE_MAP(CD3PrefsApp, CWinApp)
	//{{AFX_MSG_MAP(CD3PrefsApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CD3PrefsApp construction

CD3PrefsApp::CD3PrefsApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CD3PrefsApp object

CD3PrefsApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CD3PrefsApp initialization

BOOL CD3PrefsApp::InitInstance()
{
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	SetInstanceUniqueID(_T("{26B1EF82-2F9F-47FB-A0CA-898385D8EF8D}"));
	if (!IsInstanceUnique())
	{
		RestorePrevInstanceMainWnd();
		return FALSE;
	}

	SetRegistryKey(_T("Abin"));

	CD3PrefsDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();
	return FALSE;
}
