// D3PrefsDlg.h : header file
//

#if !defined(AFX_D3PREFSDLG_H__B6CD4ACF_7254_4291_8A3B_21C2C640D545__INCLUDED_)
#define AFX_D3PREFSDLG_H__B6CD4ACF_7254_4291_8A3B_21C2C640D545__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BrowseCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CD3PrefsDlg dialog

class CD3PrefsDlg : public CDialog
{
// Construction
public:
	CD3PrefsDlg(CWnd* pParent = NULL);	// standard constructor
	CString m_sDir;
	CString m_sD3Prefs;
	CString m_sBackup;

// Dialog Data
	//{{AFX_DATA(CD3PrefsDlg)
	enum { IDD = IDD_D3PREFS_DIALOG };
	CButton	m_wndSave;
	CButton	m_wndLow;
	CButton	m_wndHigh;
	CBrowseCtrl	m_wndDir;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CD3PrefsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void UpdateButtons();
	BOOL IsHighConfig();
	static BOOL IsFileExist(LPCTSTR lpszPath);
	void UpdatePaths();
	void ErrCannotWrite(BOOL bBackup = FALSE);
	LRESULT OnDirChange(WPARAM wParam, LPARAM lParam);

	static void WriteLine(CStdioFile& file, LPCTSTR lpszKey, int nValue);
	static void WriteLine(CStdioFile &file, LPCTSTR lpszKey, double fValue);
	BOOL CreateLowPrefs();
	BOOL Precheck();
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CD3PrefsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnHigh();
	afx_msg void OnLow();
	afx_msg void OnSave();
	afx_msg void OnAdjust();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

protected:
	
	int m_nMipBias;
	BOOL m_bMuteSound;
	BOOL m_bMuteMusic;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_D3PREFSDLG_H__B6CD4ACF_7254_4291_8A3B_21C2C640D545__INCLUDED_)
