
// ��ʱ�ػ�.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C��ʱ�ػ�App: 
// �йش����ʵ�֣������ ��ʱ�ػ�.cpp
//

class C��ʱ�ػ�App : public CWinApp
{
public:
	C��ʱ�ػ�App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C��ʱ�ػ�App theApp;