
// Test_3_Houston.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CTest_3_HoustonApp:
// See Test_3_Houston.cpp for the implementation of this class
//

class CTest_3_HoustonApp : public CWinApp
{
public:
	CTest_3_HoustonApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CTest_3_HoustonApp theApp;