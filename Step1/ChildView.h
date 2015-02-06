
// ChildView.h : interface of the CChildView class
//


#pragma once

#include "graphics/OpenGLWnd.h"

// CChildView window

class CChildView : public COpenGLWnd
{
// Construction
public:
	CChildView();



// Attributes
public:

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	void OnGLDraw(CDC * pDC);
private:
	double m_linefmx;
	double m_linefmy;
	double m_linetox;
	double m_linetoy;

	double m_xpos;
	double m_ypos;
	double m_theta;

public:
	afx_msg void OnStepstuffLineendto0();
	afx_msg void OnStepstuffLinedialog();
	afx_msg void OnStepstuffHeptagon();
	afx_msg void OnStepstuffRotate15degrees();
};

