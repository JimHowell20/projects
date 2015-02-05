// LineDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Step.h"
#include "LineDlg.h"
#include "afxdialogex.h"


// CLineDlg dialog

IMPLEMENT_DYNAMIC(CLineDlg, CDialog)

CLineDlg::CLineDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLineDlg::IDD, pParent)
	, m_fmx(0)
	, m_fmy(0)
	, m_tmx(0)
	, m_tmy(0)
{

}

CLineDlg::~CLineDlg()
{
}

void CLineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_FMX , m_fmx);
	DDX_Text(pDX, IDC_FMY, m_fmy);
	DDX_Text(pDX, IDC_TMX, m_tmx);
	DDX_Text(pDX, IDC_TMY, m_tmy);
}


BEGIN_MESSAGE_MAP(CLineDlg, CDialog)
	ON_EN_CHANGE(IDC_FMX, &CLineDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_FMY, &CLineDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_TMX, &CLineDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_TMY, &CLineDlg::OnEnChangeEdit2)
END_MESSAGE_MAP()


// CLineDlg message handlers


void CLineDlg::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CLineDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CLineDlg::OnEnChangeEdit4()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
