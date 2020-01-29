
// Test_3_HoustonDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Test_3_Houston.h"
#include "Test_3_HoustonDlg.h"
#include "afxdialogex.h"

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


// CTest_3_HoustonDlg dialog



CTest_3_HoustonDlg::CTest_3_HoustonDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTest_3_HoustonDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTest_3_HoustonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, ED);
	DDX_Control(pDX, IDC_SLIDER1, SL);
}

BEGIN_MESSAGE_MAP(CTest_3_HoustonDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CTest_3_HoustonDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CTest_3_HoustonDlg::OnBnClickedButton2)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CTest_3_HoustonDlg::OnNMCustomdrawSlider1)
END_MESSAGE_MAP()


// CTest_3_HoustonDlg message handlers

BOOL CTest_3_HoustonDlg::OnInitDialog()
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
	ED.SetWindowTextA("All colors Gray");
	SL.SetRange(0, 70);
	for(int i=0; i<=70; i+=10)
	SL.SetTic(i);

	this->SetWindowTextA("Test 3 - Houston Calvert");
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTest_3_HoustonDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTest_3_HoustonDlg::OnPaint()
{
	CDC *cdc = this->GetDC();
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
		if (SL.GetPos() < 11)
	{
		cdc->FillSolidRect(50, 15, 375, 180, RGB(128, 128, 128));
		ED.SetWindowTextA("Gray is Displayed");
	}
	else if (SL.GetPos() >= 11 && SL.GetPos() <=20)
	{
		cdc->FillSolidRect(50, 15, 375, 180, RGB(255, 0, 0));
		ED.SetWindowTextA("Red is Displayed");
	}
	else if (SL.GetPos() >= 21 && SL.GetPos() <=30)
	{
		cdc->FillSolidRect(50, 15, 375, 180, RGB(255, 0, 0));
		cdc->FillSolidRect(65, 30, 345, 150, RGB(255, 128, 0));
		ED.SetWindowTextA("Red-Orange is Displayed");
	}
	else if (SL.GetPos() >= 31 && SL.GetPos() <=40)
	{
		cdc->FillSolidRect(50, 15, 375, 180, RGB(255, 0, 0));
		cdc->FillSolidRect(65, 30, 345, 150, RGB(255, 128, 0));
		cdc->FillSolidRect(80, 45, 315, 120, RGB(255, 255, 0));
		ED.SetWindowTextA("Red-Orange-Yellow is Displayed");
	}
	else if (SL.GetPos() >= 41 && SL.GetPos() <=50)
	{
		cdc->FillSolidRect(50, 15, 375, 180, RGB(255, 0, 0));
		cdc->FillSolidRect(65, 30, 345, 150, RGB(255, 128, 0));
		cdc->FillSolidRect(80, 45, 315, 120, RGB(255, 255, 0));
		cdc->FillSolidRect(95, 60, 285, 90, RGB(0, 255, 0));
		ED.SetWindowTextA("Red-Orange-Yellow-Green is Displayed");
	}
	else if (SL.GetPos() >= 51 && SL.GetPos() <=60)
	{
		cdc->FillSolidRect(50, 15, 375, 180, RGB(255, 0, 0));
		cdc->FillSolidRect(65, 30, 345, 150, RGB(255, 128, 0));
		cdc->FillSolidRect(80, 45, 315, 120, RGB(255, 255, 0));
		cdc->FillSolidRect(95, 60, 285, 90, RGB(0, 255, 0));
		cdc->FillSolidRect(110, 75, 255, 60, RGB(0, 0, 255));
		ED.SetWindowTextA("Red-Orange-Yellow-Green-Blue is Displayed");
	}
	else if (SL.GetPos() > 60)
	{
		cdc->FillSolidRect(50, 15, 375, 180, RGB(255, 0, 0));
		cdc->FillSolidRect(65, 30, 345, 150, RGB(255, 128, 0));
		cdc->FillSolidRect(80, 45, 315, 120, RGB(255, 255, 0));
		cdc->FillSolidRect(95, 60, 285, 90, RGB(0, 255, 0));
		cdc->FillSolidRect(110, 75, 255, 60, RGB(0, 0, 255));
		cdc->FillSolidRect(125, 90, 235, 30, RGB(128, 0, 128));
		ED.SetWindowTextA("Red-Orange-Yellow-Green-Blue-Violet is Displayed");
	}

	}

}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTest_3_HoustonDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTest_3_HoustonDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	SL.SetPos(70);
	OnPaint();
}


void CTest_3_HoustonDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	SL.SetPos(0);
	OnPaint();
}


void CTest_3_HoustonDlg::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
		*pResult = 0;
	// TODO: Add your control notification handler code here
		OnPaint();
	*pResult = 0;
}
