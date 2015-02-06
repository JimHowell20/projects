#pragma once


// CHeptDlg dialog

class CHeptDlg : public CDialog
{
	DECLARE_DYNAMIC(CHeptDlg)

public:
	CHeptDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CHeptDlg();

// Dialog Data
	enum { IDD = IDD_HEPTDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double m_xpos;
	double m_ypos;
	double m_theta;
	double m_length;
};
