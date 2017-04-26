
// 定时关机Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// C定时关机Dlg 对话框
class C定时关机Dlg : public CDialogEx
{
// 构造
public:
	C定时关机Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
