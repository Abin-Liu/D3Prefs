; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAdjustDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "D3Prefs.h"

ClassCount=4
Class1=CD3PrefsApp
Class2=CD3PrefsDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_D3PREFS_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=CAdjustDlg
Resource4=IDD_ADJUSTDLG

[CLS:CD3PrefsApp]
Type=0
HeaderFile=D3Prefs.h
ImplementationFile=D3Prefs.cpp
Filter=N

[CLS:CD3PrefsDlg]
Type=0
HeaderFile=D3PrefsDlg.h
ImplementationFile=D3PrefsDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CD3PrefsDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=D3PrefsDlg.h
ImplementationFile=D3PrefsDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_D3PREFS_DIALOG]
Type=1
Class=CD3PrefsDlg
ControlCount=10
Control1=IDC_STATIC,static,1342308352
Control2=IDC_DIR,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_HIGH,button,1476460544
Control5=IDC_SAVE,button,1476460544
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_LOW,button,1476460544
Control9=IDC_ADJUST,button,1342242816
Control10=IDC_STATIC,static,1342308352

[DLG:IDD_ADJUSTDLG]
Type=1
Class=CAdjustDlg
ControlCount=10
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_MIPBIAS,msctls_trackbar32,1342242817
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,button,1342177287
Control6=IDC_MUTESOUND,button,1342242819
Control7=IDC_MUTEMUSIC,button,1342242819
Control8=IDOK,button,1342242817
Control9=IDCANCEL,button,1342242816
Control10=IDC_STATIC,static,1342308352

[CLS:CAdjustDlg]
Type=0
HeaderFile=AdjustDlg.h
ImplementationFile=AdjustDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CAdjustDlg
VirtualFilter=dWC

