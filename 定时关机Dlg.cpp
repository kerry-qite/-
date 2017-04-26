
// 定时关机Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "定时关机.h"
#include "定时关机Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C定时关机Dlg 对话框



C定时关机Dlg::C定时关机Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C定时关机Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C定时关机Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, cbBox1);
	DDX_Control(pDX, IDC_COMBO2, cbBox2);
	DDX_Control(pDX, IDC_BUTTON1, cBtn1);
}

BEGIN_MESSAGE_MAP(C定时关机Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &C定时关机Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &C定时关机Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// C定时关机Dlg 消息处理程序

BOOL C定时关机Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	cbBox1.SetCurSel(16);
	cbBox2.SetCurSel(30);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void C定时关机Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C定时关机Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C定时关机Dlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	CString hour, minute, msg;
	cbBox1.GetLBText(cbBox1.GetCurSel(), hour);
	cbBox2.GetLBText(cbBox2.GetCurSel(), minute);
	CTime time = CTime::GetCurrentTime();
	int m_nHour = time.GetHour();///当前时间：小时
	int m_nMinute = time.GetMinute();///当前时间：分钟
	int seconds = _ttoi(hour) * 3600 + _ttoi(minute) * 60 - (m_nHour * 3600 + m_nMinute * 60);///时间差（秒）
	msg.Format(_T("%d"), seconds);
	ShellExecute(NULL, _T("open"), _T("shutdown"), _T("-s -t ") + msg, NULL, NULL);
	cbBox1.EnableWindow(false);
	cbBox2.EnableWindow(false);
	cBtn1.EnableWindow(false);
}


void C定时关机Dlg::OnBnClickedButton2()
{
	// 取消关机计划
	ShellExecute(NULL, _T("open"), _T("shutdown"), _T("-a"), NULL, NULL);
	cbBox1.EnableWindow(true);
	cbBox2.EnableWindow(true);
	cBtn1.EnableWindow(true);
}
