
// ��ʱ�ػ�Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// C��ʱ�ػ�Dlg �Ի���
class C��ʱ�ػ�Dlg : public CDialogEx
{
// ����
public:
	C��ʱ�ػ�Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CComboBox cbBox1;
	CComboBox cbBox2;
	afx_msg void OnBnClickedButton2();
	CButton cBtn1;
};
