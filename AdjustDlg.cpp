// AdjustDlg.cpp : implementation file
//

#include "stdafx.h"
#include "D3Prefs.h"
#include "AdjustDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAdjustDlg dialog


CAdjustDlg::CAdjustDlg(int nMipBias, BOOL bMuteSound, BOOL bMuteMusic, CWnd* pParent /*=NULL*/)
	: CDialog(CAdjustDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAdjustDlg)
	m_bMuteMusic = bMuteMusic;
	m_bMuteSound = bMuteSound;
	m_nMipBias = nMipBias;
	//}}AFX_DATA_INIT
}


void CAdjustDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAdjustDlg)
	DDX_Control(pDX, IDC_MIPBIAS, m_wndMipBias);
	DDX_Check(pDX, IDC_MUTEMUSIC, m_bMuteMusic);
	DDX_Check(pDX, IDC_MUTESOUND, m_bMuteSound);
	DDX_Slider(pDX, IDC_MIPBIAS, m_nMipBias);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAdjustDlg, CDialog)
	//{{AFX_MSG_MAP(CAdjustDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAdjustDlg message handlers

BOOL CAdjustDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_wndMipBias.SetRange(0, 10, TRUE);
	m_wndMipBias.SetPos(m_nMipBias);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
