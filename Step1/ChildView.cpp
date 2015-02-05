
// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "Step.h"
#include "ChildView.h"
#include "LineDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


#define M_PI 3.14159265359

// CChildView
CChildView::CChildView()
{
	m_linefmx = 0.5;
	m_linefmy = 0.5;
	m_linetox = 0.2;
	m_linetoy = 0.55;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, COpenGLWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_STEPSTUFF_LINEENDTO0, &CChildView::OnStepstuffLineendto0)
	ON_COMMAND(ID_STEPSTUFF_LINEDIALOG, &CChildView::OnStepstuffLinedialog)
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
	glVertex2d(0.256, 0.274);
	glVertex2d(0.745, 0.274);
	glVertex2d(0.745, 0.75);
	glVertex2d(0.256, 0.75);
	glVertex2d(0.256, 0.274);
	glEnd();

	glColor3d(1.0, 0.5, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 7; ++i) {
		glVertex2d(0.5 + 0.25*sin(i / 7.0 * 2 * M_PI),
			0.5 + 0.25*cos(i / 7.0 * 2 * M_PI));
	}
	glEnd();
	

	glColor3d(1.0, 1.0, 0.0);

	glBegin(GL_LINES);
	glVertex2d(m_linefmx, m_linefmy);
	glVertex2d(m_linetox, m_linetoy);

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
