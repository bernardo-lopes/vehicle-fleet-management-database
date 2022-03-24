
// MFConnectDlg.h : header file
//

#pragma once


// CMFConnectDlg dialog
class CMFConnectDlg : public CDialogEx
{
// Construction
public:
	CMFConnectDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCONNECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:

	// Search
	CString nome;
	CString ano;
	afx_msg void OnEnChangeEditName();
	afx_msg void OnEnChangeEditYear();

	// Results
	CString matricula;
	CString marca;
	CString modelo;
	CString cor;
	CString transmissao;
	CString combustivel;
	afx_msg void OnEnChangeEditPlate();
	afx_msg void OnEnChangeEditBrand();
	afx_msg void OnEnChangeEditModel();
	afx_msg void OnEnChangeEditColor();
	afx_msg void OnEnChangeEditAuto();
	afx_msg void OnEnChangeEditFuel();

	// Buttons
	afx_msg void OnBnClickedButtonSearch();
	afx_msg void OnBnClickedQuit();
};


