#pragma once


// CLineDlg dialog

class CLineDlg : public CDialog
{
	DECLARE_DYNAMIC(CLineDlg)

public:
	CLineDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CLineDlg();

// Dialog Data
	enum { IDD = IDD_LINEDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double m_fmx;
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit1();
	double m_fmy;
	double m_tmx;
	afx_msg void OnEnChangeEdit4();
	double m_tmy;
};
