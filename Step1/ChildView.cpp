
// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "Step.h"
#include "ChildView.h"
#include "LineDlg.h"
#include "HeptDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


#define M_PI 3.14159265359
#define D2RAD 0.0174532925

// CChildView
CChildView::CChildView()
{
	m_linefmx = 0.5;
	m_linefmy = 0.5;
	m_linetox = 0.2;
	m_linetoy = 0.55;

	m_xpos = 0.0;
	m_ypos = 0.0;
	m_theta = 0.0;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, COpenGLWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_STEPSTUFF_LINEENDTO0, &CChildView::OnStepstuffLineendto0)
	ON_COMMAND(ID_STEPSTUFF_LINEDIALOG, &CChildView::OnStepstuffLinedialog)
	ON_COMMAND(ID_STEPSTUFF_HEPTAGON, &CChildView::OnStepstuffHeptagon)
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!COpenGLWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}



void CChildView::OnGLDraw(CDC * pDC)
{
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Simple rectangle example
	int width, height;
	GetSize(width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, // left
        1.0, // right
        0.0, // bottom
        GLdouble(height) / GLdouble(width), // top
        1.0, // near
        -1.0); // far

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glColor3d(0.5, 1.0, 0.0);
	
	glBegin(GL_LINE_STRIP);

	double x_offset = m_xpos + 0.5;
	double y_offset = m_ypos + 0.5;

	double x1 = 0.256 - x_offset;
	double y1 = 0.274 - y_offset;

	double x2 = 0.745 - x_offset;
	double y2 = 0.750 - y_offset;

	double x1p = x1;
	double y1p = y1;

	double x1r = x1p*cos(m_theta*D2RAD) - y1p*sin(m_theta*D2RAD);
	double y1r = x1p*sin(m_theta*D2RAD) + y1p*cos(m_theta*D2RAD);

	double x2p = x2;
	double y2p = y1;

	double x2r = x2p*cos(m_theta*D2RAD) - y2p*sin(m_theta*D2RAD);
	double y2r = x2p*sin(m_theta*D2RAD) + y2p*cos(m_theta*D2RAD);

	double x3p = x2;
	double y3p = y2;

	double x3r = x3p*cos(m_theta*D2RAD) - y3p*sin(m_theta*D2RAD);
	double y3r = x3p*sin(m_theta*D2RAD) + y3p*cos(m_theta*D2RAD);

	double x4p = x1;
	double y4p = y2;

	double x4r = x4p*cos(m_theta*D2RAD) - y4p*sin(m_theta*D2RAD);
	double y4r = x4p*sin(m_theta*D2RAD) + y4p*cos(m_theta*D2RAD);


	glVertex2d(x1r + x_offset, y1r + y_offset);
	glVertex2d(x2r + x_offset, y2r + y_offset);
	glVertex2d(x3r + x_offset, y3r + y_offset);
	glVertex2d(x4r + x_offset, y4r + y_offset);
	glVertex2d(x1r + x_offset, y1r + y_offset);
	glEnd();

	glColor3d(1.0, 0.5, 0.0);
	glBegin(GL_POLYGON);

	for (int i = 0; i < 7; ++i)
	{
		double x = 0.25*sin((i/7.0)*2*M_PI);
		double y = 0.25*cos((i/7.0)*2*M_PI);

		double xp = x*cos(m_theta*D2RAD) - y*sin(m_theta*D2RAD);
		double yp = x*sin(m_theta*D2RAD) + y*cos(m_theta*D2RAD);

		glVertex2d(xp+x_offset,yp+y_offset);
	}
	glEnd();
}


void CChildView::OnStepstuffLineendto0()
{
	// TODO: Add your command handler code here
	m_linetox = 0.1;
	m_linetoy = 0.1;

	Invalidate();
}


void CChildView::OnStepstuffLinedialog()
{
	// TODO: Add your command handler code here

	CLineDlg dlg;

	dlg.m_fmx = m_linefmx;
	dlg.m_fmy = m_linefmy;
	dlg.m_tmx = m_linetox;
	dlg.m_tmy = m_linetoy;

	if (dlg.DoModal() == IDOK)
	{
		m_linefmx = dlg.m_fmx;
		m_linefmy = dlg.m_fmy;
		m_linetox = dlg.m_tmx;
		m_linetoy = dlg.m_tmy;

		Invalidate();
	}
}


void CChildView::OnStepstuffHeptagon()
{
	// TODO: Add your command handler code here

	CHeptDlg dlg;

	dlg.m_xpos = m_xpos;
	dlg.m_ypos = m_ypos;
	dlg.m_theta = m_theta;

	if (dlg.DoModal() == IDOK)
	{
		m_xpos = dlg.m_xpos;
		m_ypos = dlg.m_ypos;
		m_theta = dlg.m_theta;
		Invalidate();
	}
}
