
// CalculatorDlg.h: 头文件
//

#pragma once
//运算符
#include <iostream>
#include <string>
#include <stack>
#include <cmath>
using namespace std;
enum OP {
	PLUS,
	SUB,
	MUL,
	DIV,
	MOD
};

// CCalculatorDlg 对话框
class CCalculatorDlg : public CDialogEx
{
// 构造
public:
	CCalculatorDlg(CWnd* pParent = nullptr);	// 标准构造函数
	void calc();	// 点击enter时进行计算
	void SaveFirstValue();//保存结果函数
	friend bool isOperator(char c);
	friend int precedence(char op);
	friend double applyOp(double a, double b, char op);
	friend double evaluate(string s);

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	//stack<double> values;
	//stack<char> ops;
	CString str = L"0";	//编辑框1中的字符串
	CString str2;	// 编辑框2中的字符串
	CString tempStr = L"";

	double num1 = 0;//输入的数1
	double num2 = 0;//输入的数2
	double tempNum = 0;// 存放临时结果
	int count = 0;//第几次运算
	OP op;// 运算符
	bool flag = false;// 是否运算结束的标志，在摁下等于号之后变成true

public:
	CFont m_Font;
	CEdit m_ControlEdit;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButtondot();
	afx_msg void OnBnClickedButtonback();
	afx_msg void OnBnClickedButtonclear();
	afx_msg void OnBnClickedButtonreverse();
	afx_msg void OnBnClickedButtonenter();
	afx_msg void OnBnClickedButtonplus();
	afx_msg void OnBnClickedButtonminus();
	afx_msg void OnBnClickedButtonmul();
	afx_msg void OnBnClickedButtondiv();
	afx_msg void OnBnClickedButtonmod();
	CEdit m_control;
	afx_msg void OnBnClickedlog();
	afx_msg void OnBnClickedtan();
	afx_msg void OnBnClickedcos();
	afx_msg void OnBnClickedsin();

private:
	HBITMAP m_hBitmap;
	CBrush m_bgBrush;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg LRESULT OnNcHitTest(CPoint point);
public:
	afx_msg void OnBnClickedButtonsin();
	afx_msg void OnBnClickedButtoncos();
	afx_msg void OnBnClickedButtontan();
	afx_msg void OnBnClickedButtonlog10();
	afx_msg void OnEnChangeEdit1();
};
