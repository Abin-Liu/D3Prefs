#if !defined(AFX_ADJUSTDLG_H__B2A97B22_0DA4_4DC7_BC8B_7870937DEE13__INCLUDED_)
#define AFX_ADJUSTDLG_H__B2A97B22_0DA4_4DC7_BC8B_7870937DEE13__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AdjustDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAdjustDlg dialog

class CAdjustDlg : public CDialog
{
// Construction
public:
	CAdjustDlg(int nMipBias, BOOL bMuteSound, BOOL bMuteMusic, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAdjustDlg)
	enum { IDD = IDD_ADJUSTDLG };
	CSliderCtrl	m_wndMipBias;
	BOOL	m_bMuteMusic;
	BOOL	m_bMuteSound;
	int		m_nMipBias;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdjustDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAdjustDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADJUSTDLG_H__B2A97B22_0DA4_4DC7_BC8B_7870937DEE13__INCLUDED_)
