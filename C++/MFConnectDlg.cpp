
// MFConnectDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFConnect.h"
#include "MFConnectDlg.h"
#include "afxdialogex.h"
#include "myconnectorclassDB.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSearch();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTONQuery, &CAboutDlg::OnBnClickedButtonSearch)
END_MESSAGE_MAP()


// CMFConnectDlg dialog



CMFConnectDlg::CMFConnectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCONNECT_DIALOG, pParent)

	// Search
	, nome(_T(""))
	, ano(_T(""))

	//Results
	, matricula(_T(""))
	, marca(_T(""))
	, modelo(_T(""))
	, cor(_T(""))
	, transmissao(_T(""))
	, combustivel(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFConnectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	// Search
	DDX_Text(pDX, IDC_EDITName, nome);
	DDX_Text(pDX, IDC_EDITYear, ano);

	// Results
	DDX_Text(pDX, IDC_EDITPlate, matricula);
	DDX_Text(pDX, IDC_EDITBrand, marca);
	DDX_Text(pDX, IDC_EDITModel, modelo);
	DDX_Text(pDX, IDC_EDITColor, cor);
	DDX_Text(pDX, IDC_EDITAuto, transmissao);
	DDX_Text(pDX, IDC_EDITFuel, combustivel);
}

BEGIN_MESSAGE_MAP(CMFConnectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	// Buttons
	ON_BN_CLICKED(IDC_BUTTONQuery, &CMFConnectDlg::OnBnClickedButtonSearch)
	ON_BN_CLICKED(IDOK, &CMFConnectDlg::OnBnClickedQuit)

	// Search
	ON_EN_CHANGE(IDC_EDITName, &CMFConnectDlg::OnEnChangeEditName)
	ON_EN_CHANGE(IDC_EDITYear, &CMFConnectDlg::OnEnChangeEditYear)

	// Results
	ON_EN_CHANGE(IDC_EDITPlate, &CMFConnectDlg::OnEnChangeEditPlate)
	// ON_EN_CHANGE(IDC_EDITBrand, &CMFConnectDlg::OnEnChangeEditBrand)
	ON_EN_CHANGE(IDC_EDITModel, &CMFConnectDlg::OnEnChangeEditModel)
	// ON_EN_CHANGE(IDC_EDITColor, &CMFConnectDlg::OnEnChangeEditColor)
	// ON_EN_CHANGE(IDC_EDITAuto, &CMFConnectDlg::OnEnChangeEditAuto)
	ON_EN_CHANGE(IDC_EDITFuel, &CMFConnectDlg::OnEnChangeEditFuel)
	
END_MESSAGE_MAP()


// CMFConnectDlg message handlers

BOOL CMFConnectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

void CMFConnectDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFConnectDlg::OnPaint()
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
HCURSOR CMFConnectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



 void CAboutDlg::OnBnClickedButtonSearch()
{
	// TODO: Add your control notification handler code here
}


void CMFConnectDlg::OnBnClickedButtonSearch()
{
	myconnectorclassDB MyConnection;
	MyConnection.connect();
	UpdateData(TRUE);

	matricula = MyConnection.CheckPlate(nome, ano);
	marca = MyConnection.CheckBrand(nome, ano);
	modelo = MyConnection.CheckModel(nome, ano);
	cor = MyConnection.CheckColor(nome, ano);
	transmissao = MyConnection.CheckAuto(nome, ano);
	combustivel = MyConnection.CheckFuel(nome, ano);

	UpdateData(FALSE);

}


void CMFConnectDlg::OnEnChangeEditPlate()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}




void CMFConnectDlg::OnEnChangeEditName()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}








void CMFConnectDlg::OnEnChangeEditYear()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}



void CMFConnectDlg::OnEnChangeEditModel()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CMFConnectDlg::OnEnChangeEditFuel()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}




void CMFConnectDlg::OnBnClickedQuit()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
