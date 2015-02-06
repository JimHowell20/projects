// HeptDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Step.h"
#include "HeptDlg.h"
#include "afxdialogex.h"


// CHeptDlg dialog

IMPLEMENT_DYNAMIC(CHeptDlg, CDialog)

CHeptDlg::CHeptDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHeptDlg::IDD, pParent)
	, m_xpos(0)
	, m_ypos(0)
	, m_theta(0)
{

}

CHeptDlg::~CHeptDlg()
{
}

void CHeptDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_XPOS, m_xpos);
	DDX_Text(pDX, IDC_YPOS, m_ypos);
	DDX_Text(pDX, IDC_THETA, m_theta);
}


BEGIN_MESSAGE_MAP(CHeptDlg, CDialog)
END_MESSAGE_MAP()


// CHeptDlg message handlers
