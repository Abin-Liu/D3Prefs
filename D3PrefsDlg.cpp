// D3PrefsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "D3Prefs.h"
#include "D3PrefsDlg.h"
#include "AdjustDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define WM_DIR_CHANGE	(WM_APP + 101)

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CD3PrefsDlg dialog

CD3PrefsDlg::CD3PrefsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CD3PrefsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CD3PrefsDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_sDir = AfxGetApp()->GetProfileString(_T(""), _T("Folder"));

	if (m_sDir.IsEmpty())
	{
		TCHAR szBuff[MAX_PATH + 1] = _T("");
		::SHGetSpecialFolderPath(NULL, szBuff, CSIDL_PERSONAL, FALSE);
		m_sDir = szBuff;
		m_sDir += _T("\\Diablo III");
	}

	m_nMipBias = AfxGetApp()->GetProfileInt(_T(""), _T("MipBias"), 3);
	if (m_nMipBias < 0 || m_nMipBias > 10)
		m_nMipBias = 3;

	m_bMuteSound = !!AfxGetApp()->GetProfileInt(_T(""), _T("MuteSound"), TRUE);
	m_bMuteMusic = !!AfxGetApp()->GetProfileInt(_T(""), _T("MuteMusic"), TRUE);
}

void CD3PrefsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CD3PrefsDlg)
	DDX_Control(pDX, IDC_SAVE, m_wndSave);
	DDX_Control(pDX, IDC_LOW, m_wndLow);
	DDX_Control(pDX, IDC_HIGH, m_wndHigh);
	DDX_Control(pDX, IDC_DIR, m_wndDir);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CD3PrefsDlg, CDialog)
	//{{AFX_MSG_MAP(CD3PrefsDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_HIGH, OnHigh)
	ON_BN_CLICKED(IDC_LOW, OnLow)
	ON_BN_CLICKED(IDC_SAVE, OnSave)
	ON_BN_CLICKED(IDC_ADJUST, OnAdjust)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_DIR_CHANGE, OnDirChange)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CD3PrefsDlg message handlers

BOOL CD3PrefsDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	UpdatePaths();

	m_wndDir.ModifyButtonStyle(0, BC_CTL_FOLDERSONLY);
	m_wndDir.SetDialogBanner(_T("请选择D3Prefs.txt所在的文件夹："));
	m_wndDir.SetPathName(m_sDir);
	m_wndDir.SetNotifyMessageID(WM_DIR_CHANGE);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CD3PrefsDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CD3PrefsDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CD3PrefsDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CD3PrefsDlg::UpdatePaths()
{
	m_sD3Prefs = m_sDir + _T("\\D3Prefs.txt");
	m_sBackup = m_sDir + _T("\\D3Prefs_Backup.txt");	

	CString sOldBackup = m_sDir + _T("\\D3PSwitch_Backup.txt");
	if (IsFileExist(sOldBackup))
	{
		::CopyFile(sOldBackup, m_sBackup, TRUE);
		::DeleteFile(sOldBackup);
	}

	UpdateButtons();
}

BOOL CD3PrefsDlg::IsFileExist(LPCTSTR lpszPath)
{
	return ::GetFileAttributes(lpszPath) != -1;
}

BOOL CD3PrefsDlg::Precheck()
{
	if (!IsFileExist(m_sD3Prefs))
	{
		CString sMsg;
		sMsg.Format(_T("指定的路径[%s]下没有找到D3Prefs.txt文件，请重新设置位置。"), (LPCTSTR)m_sDir);
		MessageBox(sMsg, _T("无效位置"), MB_ICONEXCLAMATION);
		return FALSE;
	}

	if (::FindWindow(_T("D3 Main Window Class"), NULL))
	{
		if (MessageBox(_T("Diablo III游戏正在运行中，此时切换配置无效。是否仍然要切换？"), _T("Diablo III运行中"), MB_ICONQUESTION | MB_YESNO | MB_DEFBUTTON2) != IDYES)
			return FALSE;
	}	
	
	return TRUE;
}

void CD3PrefsDlg::OnHigh() 
{
	// TODO: Add your control notification handler code here
	if (!Precheck())
		return;	

	if (!IsFileExist(m_sBackup))
	{	
		MessageBox(_T("目前已是正常配置。"), _T("配置切换"), MB_ICONINFORMATION);
	}
	else
	{
		if (::CopyFile(m_sBackup, m_sD3Prefs, FALSE))
		{
			MessageBox(_T("已切换到正常配置。"), _T("配置切换"), MB_ICONINFORMATION);
		}
		else
		{
			ErrCannotWrite();
		}
	}

	UpdateButtons();
}

void CD3PrefsDlg::OnLow() 
{
	// TODO: Add your control notification handler code here
	if (!Precheck())
		return;

	// Backup the current config?
	::CopyFile(m_sD3Prefs, m_sBackup, TRUE);

	if (CreateLowPrefs())
		MessageBox(_T("已切换到最低配置。"), _T("配置切换"), MB_ICONINFORMATION);
	else
		ErrCannotWrite();

	UpdateButtons();
}

BOOL CD3PrefsDlg::CreateLowPrefs()
{
	CStdioFile file;
	if (!file.Open(m_sD3Prefs, CFile::modeCreate | CFile::modeWrite))
		return FALSE;

	WriteLine(file, _T("PreferencesVersion"), 46);
	WriteLine(file, _T("PlayedCutscene0"), 1);
	WriteLine(file, _T("PlayedCutscene1"), 0);
	WriteLine(file, _T("PlayedCutscene2"), 3);
	WriteLine(file, _T("PlayedCutscene3"), 131);
	WriteLine(file, _T("PlayedCutscene4"), 1);
	WriteLine(file, _T("DisplayModeFlags"), 0);
	WriteLine(file, _T("DisplayModeWindowMode"), 1);
	WriteLine(file, _T("DisplayModeWinLeft"), 250);
	WriteLine(file, _T("DisplayModeWinTop"), 100);
	WriteLine(file, _T("DisplayModeWinWidth"), 1296);
	WriteLine(file, _T("DisplayModeWinHeight"), 812);
	WriteLine(file, _T("DisplayModeUIOptWidth"), 1680);
	WriteLine(file, _T("DisplayModeUIOptHeight"), 1050);
	WriteLine(file, _T("DisplayModeWidth"), 1280);
	WriteLine(file, _T("DisplayModeHeight"), 774);
	WriteLine(file, _T("DisplayModeRefreshRate"), 60);
	WriteLine(file, _T("DisplayModeBitDepth"), 32);
	WriteLine(file, _T("DisplayModeMSAALevel"), 1);
	WriteLine(file, _T("Gamma"), 1.0);
	WriteLine(file, _T("MipOffset"), 1);
	WriteLine(file, _T("ShadowQuality"), 0);
	WriteLine(file, _T("ShadowDetail"), 0);
	WriteLine(file, _T("PhysicsQuality"), 0);
	WriteLine(file, _T("ClutterQuality"), 0);
	WriteLine(file, _T("Vsync"), 1);
	WriteLine(file, _T("Letterbox"), 1);
	WriteLine(file, _T("Antialiasing"), 0);
	WriteLine(file, _T("DisableScreenShake"), 0);
	WriteLine(file, _T("LowFX"), 1);
	WriteLine(file, _T("LockCursorInFullscreenWindowed"), 0);
	WriteLine(file, _T("LimitForegroundFPS"), 1);
	WriteLine(file, _T("MaxForegroundFPS"), 60);
	WriteLine(file, _T("LimitBackgroundFPS"), 1);
	WriteLine(file, _T("MaxBackgroundFPS"), 15);
	WriteLine(file, _T("DisableTrilinearFiltering"), 1);
	WriteLine(file, _T("ColorCorrection"), 1);
	WriteLine(file, _T("MipBias"), (double)m_nMipBias);
	WriteLine(file, _T("ReflectionQuality"), 0);
	WriteLine(file, _T("HardwareClass"), 1);
	WriteLine(file, _T("PCIVendor"), 4318);
	WriteLine(file, _T("PCIDevice"), 4544);
	WriteLine(file, _T("flSafeZoneLeft"), 0.0);
	WriteLine(file, _T("MasterVolume"), 1.0);
	WriteLine(file, _T("EffectVolume"), 0.8);
	WriteLine(file, _T("MusicVolume"), 0.8);
	WriteLine(file, _T("NarrationVolume"), 0.8);
	WriteLine(file, _T("AmbientVolume"), 0.8);
	WriteLine(file, _T("ChannelsToUse"), 32);
	WriteLine(file, _T("SoundDriver"), 0);
	WriteLine(file, _T("SpeakerMode"), 0);
	WriteLine(file, _T("ReverseSpeakers"), 0);
	WriteLine(file, _T("QuestSubtitlesEnabled"), 0);
	WriteLine(file, _T("CinematicsSubtitlesEnabled"), 0);
	WriteLine(file, _T("PlayInBackground"), 0);
	WriteLine(file, _T("MuteSound"), m_bMuteSound);
	WriteLine(file, _T("MuteEffects"), 0);
	WriteLine(file, _T("MuteAmbient"), 0);
	WriteLine(file, _T("MuteVoice"), 0);
	WriteLine(file, _T("MuteMusic"), m_bMuteMusic);	

	file.Close();
	return TRUE;
}

void CD3PrefsDlg::WriteLine(CStdioFile &file, LPCTSTR lpszKey, int nValue)
{
	CString sLine;
	sLine.Format(_T("%s \"%d\"\n"), lpszKey, nValue);
	file.WriteString(sLine);
}

void CD3PrefsDlg::WriteLine(CStdioFile &file, LPCTSTR lpszKey, double fValue)
{
	CString sLine;
	sLine.Format(_T("%s \"%.6f\"\n"), lpszKey, fValue);
	file.WriteString(sLine);
}

LRESULT CD3PrefsDlg::OnDirChange(WPARAM wParam, LPARAM lParam)
{
	if (wParam == IDOK)
	{
		m_sDir = m_wndDir.GetPathName();		
		AfxGetApp()->WriteProfileString(_T(""), _T("Folder"), m_sDir);
		UpdatePaths();
	}

	return 0;
}

void CD3PrefsDlg::ErrCannotWrite(BOOL bBackup)
{
	CString sMsg;
	sMsg.Format(_T("无法写入文件[%s]，访问被禁止。"), (LPCTSTR)(bBackup ? m_sBackup : m_sD3Prefs));
	MessageBox(sMsg, _T("文件访问错误"), MB_ICONEXCLAMATION);
}

void CD3PrefsDlg::OnSave() 
{
	// TODO: Add your control notification handler code here
	if (!IsHighConfig())
	{
		MessageBox(_T("当前配置文件属于极低配置，为防止您误覆盖正常配置文件，操作取消。"), _T("操作取消"), MB_ICONEXCLAMATION);
		return;
	}

	if (MessageBox(_T("将当前的游戏配置文件作为正常配置保存，确定吗？"), _T("保存配置"), MB_ICONQUESTION | MB_YESNO | MB_DEFBUTTON2) != IDYES)
		return;

	if (::CopyFile(m_sD3Prefs, m_sBackup, FALSE))
		MessageBox(_T("配置保存成功。"), _T("保存配置"), MB_ICONINFORMATION);
	else
		ErrCannotWrite(TRUE);
}

BOOL CD3PrefsDlg::IsHighConfig()
{
	CStdioFile file;
	if (!file.Open(m_sD3Prefs, CFile::modeRead))
		return FALSE;

	CString sLine;
	while (file.ReadString(sLine))
	{
		int nIndex = sLine.Find(_T("HardwareClass "));
		if (nIndex != -1)
		{
			nIndex += _tcslen(_T("HardwareClass "));
			CString sValue = sLine.Mid(nIndex + 1);
			int nVal = _ttoi(sValue);
			return nVal > 1;
		}
	}

	return FALSE;
}

void CD3PrefsDlg::UpdateButtons()
{
	BOOL bValid = IsFileExist(m_sD3Prefs);
	BOOL bHigh = IsHighConfig();
	m_wndHigh.EnableWindow(bValid && !bHigh);
	m_wndSave.EnableWindow(bValid && bHigh);
	m_wndLow.EnableWindow(bValid && bHigh);
}

void CD3PrefsDlg::OnAdjust() 
{
	// TODO: Add your control notification handler code here
	CAdjustDlg dlg(m_nMipBias, m_bMuteSound, m_bMuteMusic, this);
	if (dlg.DoModal() != IDOK)
		return;

	if (m_nMipBias == dlg.m_nMipBias && m_bMuteSound == dlg.m_bMuteSound && m_bMuteMusic == dlg.m_bMuteMusic)
		return;

	BOOL bHighConfig = IsHighConfig();	
	if (!bHighConfig && ::FindWindow(_T("D3 Main Window Class"), NULL))
	{
		MessageBox(_T("Diablo III游戏正在运行中，此时无法调节配置。"), _T("Diablo III运行中"), MB_ICONEXCLAMATION);
		return;
	}	

	m_nMipBias = dlg.m_nMipBias;
	m_bMuteSound = dlg.m_bMuteSound;
	m_bMuteMusic = dlg.m_bMuteMusic;

	AfxGetApp()->WriteProfileInt(_T(""), _T("MipBias"), m_nMipBias);
	AfxGetApp()->WriteProfileInt(_T(""), _T("MuteSound"), m_bMuteSound);
	AfxGetApp()->WriteProfileInt(_T(""), _T("MuteMusic"), m_bMuteMusic);

	if (bHighConfig)
		return;

	if (CreateLowPrefs())
		MessageBox(_T("最低配置数据已保存，并已更新到D3Prefs.txt。"), _T("更新配置"), MB_ICONINFORMATION);
	else
		ErrCannotWrite();		
}
