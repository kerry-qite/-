
// ��ʱ�ػ�Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��ʱ�ػ�.h"
#include "��ʱ�ػ�Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ʱ�ػ�Dlg �Ի���



C��ʱ�ػ�Dlg::C��ʱ�ػ�Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C��ʱ�ػ�Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C��ʱ�ػ�Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, cbBox1);
	DDX_Control(pDX, IDC_COMBO2, cbBox2);
	DDX_Control(pDX, IDC_BUTTON1, cBtn1);
}

BEGIN_MESSAGE_MAP(C��ʱ�ػ�Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &C��ʱ�ػ�Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &C��ʱ�ػ�Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// C��ʱ�ػ�Dlg ��Ϣ�������

BOOL C��ʱ�ػ�Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	cbBox1.SetCurSel(16);
	cbBox2.SetCurSel(30);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void C��ʱ�ػ�Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C��ʱ�ػ�Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C��ʱ�ػ�Dlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString hour, minute, msg;
	cbBox1.GetLBText(cbBox1.GetCurSel(), hour);
	cbBox2.GetLBText(cbBox2.GetCurSel(), minute);
	CTime time = CTime::GetCurrentTime();
	int m_nHour = time.GetHour();///��ǰʱ�䣺Сʱ
	int m_nMinute = time.GetMinute();///��ǰʱ�䣺����
	int seconds = _ttoi(hour) * 3600 + _ttoi(minute) * 60 - (m_nHour * 3600 + m_nMinute * 60);///ʱ���룩
	msg.Format(_T("%d"), seconds);
	ShellExecute(NULL, _T("open"), _T("shutdown"), _T("-s -t ") + msg, NULL, NULL);
	cbBox1.EnableWindow(false);
	cbBox2.EnableWindow(false);
	cBtn1.EnableWindow(false);
}


void C��ʱ�ػ�Dlg::OnBnClickedButton2()
{
	// ȡ���ػ��ƻ�
	ShellExecute(NULL, _T("open"), _T("shutdown"), _T("-a"), NULL, NULL);
	cbBox1.EnableWindow(true);
	cbBox2.EnableWindow(true);
	cBtn1.EnableWindow(true);
}
