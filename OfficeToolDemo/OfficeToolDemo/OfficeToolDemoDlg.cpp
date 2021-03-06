
// OfficeToolDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "OfficeToolDemo.h"
#include "OfficeToolDemoDlg.h"
#include "afxdialogex.h"
#include "..\..\OfficeTool\OfficeTool\Excel.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// COfficeToolDemoDlg dialog



COfficeToolDemoDlg::COfficeToolDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(COfficeToolDemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COfficeToolDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(COfficeToolDemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BT_OUT_EXCEL, &COfficeToolDemoDlg::OnBnClickedBtOutExcel)
	ON_BN_CLICKED(IDC_BT_OPEN_EXCEL, &COfficeToolDemoDlg::OnBnClickedBtOpenExcel)
END_MESSAGE_MAP()


// COfficeToolDemoDlg message handlers

BOOL COfficeToolDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void COfficeToolDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void COfficeToolDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR COfficeToolDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void COfficeToolDemoDlg::OnBnClickedBtOutExcel()
{
	// TODO: Add your control notification handler code 
	CExcel mExcel;
	if ( !mExcel.Open(true, _T("d:\\OfficeToolDemo.xlsx")) )
		return;

	mExcel.AddWorkSheet(_T("工作表1"), 5, 2);
	mExcel.SetRangeStyle(1, 1, 1, 1, 2, CExcel::RS_NORMAL);
	mExcel.SetRangeStyle(1, 2, 1, 2, 2, CExcel::RS_NUMBER);
	mExcel.SetRangeStyle(1, 3, 1, 3, 2, CExcel::RS_STRING);
	mExcel.SetRangeStyle(1, 4, 1, 4, 2, CExcel::RS_DATE);
	mExcel.SetRangeStyle(1, 5, 1, 5, 2, CExcel::RS_TIME);

	mExcel.SetRangeText(1, 1, 1, _T("常规"));
	mExcel.SetRangeText(1, 1, 2, _T("12常规abc"));
	mExcel.SetRangeText(1, 2, 1, _T("12.1234"));
	mExcel.SetRangeText(1, 2, 2, _T("13.1234"));
	mExcel.SetRangeText(1, 3, 1, _T("12字符串"));
	mExcel.SetRangeText(1, 3, 2, _T("12字符串abc"));
	mExcel.SetRangeText(1, 4, 1, _T("2018/5/16"));
	mExcel.SetRangeText(1, 4, 2, _T("2018/5/15"));
	mExcel.SetRangeText(1, 5, 1, _T("2018/5/16 13:46:00"));
	mExcel.SetRangeText(1, 5, 2, _T("2018/5/15 13:46:01"));

	mExcel.AddWorkSheet(_T("工作表2"), 2, 2);
	mExcel.SetRangeText(2, 1, 1, _T("工作表211"));
	mExcel.SetRangeText(2, 1, 2, _T("工作表212"));
	mExcel.SetRangeText(2, 2, 1, _T("工作表221"));
	mExcel.SetRangeText(2, 2, 2, _T("工作表222"));

	mExcel.Save();
	mExcel.Close();
	AfxMessageBox(_T("Finished!"));
}


void COfficeToolDemoDlg::OnBnClickedBtOpenExcel()
{
	// TODO: Add your control notification handler code here
	CExcel mExcel;
	if ( !mExcel.Open(FALSE, _T("d:\\OfficeToolDemo.xlsx")) )
		return;
}
