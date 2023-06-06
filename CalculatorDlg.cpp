
// CalculatorDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"
#include <iostream>
#include <string>
#include <stack>
#include <cmath>
#include<atlconv.h>
#include <afxres.h>
#include "resource.h"
#include"CalculatorDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//文本框与字符串关联
	//DDX_Text(pDX, IDC_EDIT1, str);

}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalculatorDlg 对话框



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	// 文本框关联字符串
	DDX_Text(pDX, IDC_EDIT1, str);
	DDX_Text(pDX, IDC_EDIT2, str2);

	DDX_Control(pDX, IDC_EDIT2, m_ControlEdit);
	DDX_Control(pDX, IDC_EDIT1, m_control);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_BN_CLICKED(IDC_BUTTON_1, &CCalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_2, &CCalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_3, &CCalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_4, &CCalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_5, &CCalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON_6, &CCalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_7, &CCalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON_8, &CCalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON_9, &CCalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_0, &CCalculatorDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_dot, &CCalculatorDlg::OnBnClickedButtondot)
	ON_BN_CLICKED(IDC_BUTTON_back, &CCalculatorDlg::OnBnClickedButtonback)
	ON_BN_CLICKED(IDC_BUTTON_clear, &CCalculatorDlg::OnBnClickedButtonclear)
	ON_BN_CLICKED(IDC_BUTTON_reverse, &CCalculatorDlg::OnBnClickedButtonreverse)
	ON_BN_CLICKED(IDC_BUTTON_enter, &CCalculatorDlg::OnBnClickedButtonenter)
	ON_BN_CLICKED(IDC_BUTTON_plus, &CCalculatorDlg::OnBnClickedButtonplus)
	ON_BN_CLICKED(IDC_BUTTON_minus, &CCalculatorDlg::OnBnClickedButtonminus)
	ON_BN_CLICKED(IDC_BUTTON_mul, &CCalculatorDlg::OnBnClickedButtonmul)
	ON_BN_CLICKED(IDC_BUTTON_div, &CCalculatorDlg::OnBnClickedButtondiv)
	ON_BN_CLICKED(IDC_BUTTON_mod, &CCalculatorDlg::OnBnClickedButtonmod)
	ON_WM_CTLCOLOR()
	ON_WM_NCHITTEST()
	ON_BN_CLICKED(IDC_BUTTONSin, &CCalculatorDlg::OnBnClickedButtonsin)
	ON_BN_CLICKED(IDC_BUTTONCos, &CCalculatorDlg::OnBnClickedButtoncos)
	ON_BN_CLICKED(IDC_BUTTONTan, &CCalculatorDlg::OnBnClickedButtontan)
	ON_BN_CLICKED(IDC_BUTTONLog10, &CCalculatorDlg::OnBnClickedButtonlog10)
	ON_EN_CHANGE(IDC_EDIT1, &CCalculatorDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CCalculatorDlg 消息处理程序

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}

		//indowLong(pButton->GetSafeHwnd(), GWL_EXSTYLE) | WS_EX_TRANSPARENT);


	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_Font.CreatePointFont(300, _T("宋体"), NULL);
	m_control.SetFont(&m_Font, FALSE);

	//CString sPath = _T("D:\\bridge.jpeg");
	//CImage img;
	//img.Load(sPath);
	//HBITMAP hbmp = img.Detach();
	//CBitmap bmp;
	//bmp.Attach(hbmp);
	//m_bgBrush.CreatePatternBrush(&bmp);
	//m_hBitmap = (HBITMAP)LoadImage(NULL, L"D:\\bridge.jpeg",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
	//m_hBitmap = (HBITMAP)LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE("Background"), IMAGE_BITMAP, 0, 0, LR_DEFAULTSIZE);
	// 加载位图资源




	return FALSE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCalculatorDlg::OnPaint()
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
		/*CDialogEx::OnPaint();*/
			//添加背景图片
		CPaintDC   dc(this);
		CRect   rect;
		GetClientRect(&rect);                     //获取对话框长宽      
		CDC   dcBmp;                               //定义并创建一个内存设备环境
		dcBmp.CreateCompatibleDC(&dc);             //创建兼容性DC
		CBitmap   bmpBackground;
		bmpBackground.LoadBitmap(IDB_BITMAP5);    //载入资源中图片
		BITMAP   m_bitmap;                         //图片变量               
		bmpBackground.GetBitmap(&m_bitmap);       //将图片载入位图中
		//将位图选入临时内存设备环境
		CBitmap* pbmpOld = dcBmp.SelectObject(&bmpBackground);
		//调用函数显示图片StretchBlt显示形状可变
		dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, 0, m_bitmap.bmWidth, m_bitmap.bmHeight, SRCCOPY);
	}
}



//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





// 按钮一
void CCalculatorDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (flag == true)	// 没有摁下=号
		str = L"";	// 清屏

	if (str[0] == '0' && str[1] != '.')
	{
		str = L"";
	}

	str = str + _T("1");
	UpdateData(FALSE);

	flag = false;

}


void CCalculatorDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (flag == true)	// 没有摁下=号
		str = L"";	// 清屏

	if (str[0] == '0' && str[1] != '.')
	{
		str = L"";
	}

	str = str + _T("2");
	UpdateData(FALSE);

	flag = false;
}


void CCalculatorDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (flag == true)	// 没有摁下=号
		str = L"";	// 清屏

	if (str[0] == '0' && str[1] != '.')
	{
		str = L"";
	}

	str = str + _T("3");
	UpdateData(FALSE);

	flag = false;
}




void CCalculatorDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (flag == true)	// 没有摁下=号
		str = L"";	// 清屏

	if (str[0] == '0' && str[1] != '.')
	{
		str = L"";
	}

	str = str + _T("4");
	UpdateData(FALSE);

	flag = false;
}




void CCalculatorDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (flag == true)	// 没有摁下=号
		str = L"";	// 清屏

	if (str[0] == '0' && str[1] != '.')
	{
		str = L"";
	}

	str = str + _T("5");
	UpdateData(FALSE);

	flag = false;
}




void CCalculatorDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (flag == true)	// 没有摁下=号
		str = L"";	// 清屏

	if (str[0] == '0' && str[1] != '.')
	{
		str = L"";
	}

	str = str + _T("6");
	UpdateData(FALSE);

	flag = false;
}




void CCalculatorDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (flag == true)	// 没有摁下=号
		str = L"";	// 清屏

	if (str[0] == '0' && str[1] != '.')
	{
		str = L"";
	}

	str = str + _T("7");
	UpdateData(FALSE);

	flag = false;
}




void CCalculatorDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (flag == true)	// 没有摁下=号
		str = L"";	// 清屏

	if (str[0] == '0' && str[1] != '.')
	{
		str = L"";
	}

	str = str + _T("8");
	UpdateData(FALSE);

	flag = false;
}




void CCalculatorDlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (flag == true)	// 没有摁下=号
		str = L"";	// 清屏

	if (str[0] == '0' && str[1] != '.')
	{
		str = L"";
	}

	str = str + _T("9");
	UpdateData(FALSE);

	flag = false;
}


void CCalculatorDlg::OnBnClickedButton0()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (flag == true)
		str = L"";

	if (str.GetLength() == 0) {	//空串可以添加0
		str = str + _T("0");
	}
	if (str[0] != '0') {	// 开头不是0，才能追加0，即不能出现0000的形式
		str = str + _T("0");
	}
	if (str[0] == '0' && str[1] == '.')// 开头如果是0，虽然不能再追加0，但是如果第二位为小数点的话也是可以进行追加的
	{
		str = str + _T("0");
	}

	UpdateData(FALSE);
	flag = false;
}


void CCalculatorDlg::OnBnClickedButtondot()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (str.Find(L'.') == -1 && !str.IsEmpty())	// 如果没有小数点，就加上小数点，如果是空串也不能加小数点
	{
		str = str + L'.';
	}
	UpdateData(FALSE);
	flag = false;
}




void CCalculatorDlg::OnBnClickedButtonback()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (str.GetLength() == 1 || str.GetLength()==0)  // 只有一位数或是空串，那么退格之后就变成0
	{
		str = L"0";
	}
	else// 如果有多位数即位数大于1
	{
		str = str.Left(str.GetLength() - 1);
	}
	UpdateData(FALSE);
}




void CCalculatorDlg::OnBnClickedButtonclear()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	str = L"0";
	str2 = L"";
	num1 = 0;
	num2 = 0;
	count = 0;
	tempNum = 0;
	op = PLUS;
	UpdateData(FALSE);
}




void CCalculatorDlg::OnBnClickedButtonreverse()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (str.IsEmpty())
	{
		str = str + '-';
	}
	else {
		double temp = _wtof(str);
		temp = 0 - temp;

		// 把浮点数转成字符串
		str.Format(_T("%f"), temp);
		int pos = str.Find('.');	// 找到小数点的位置，
		CString str3 = str;
		for (int i = str.GetLength() - 1; i > pos; i--) {
			if (str[i] == '0') {
				str3.Delete(i);		// 把尾数的0去掉
			}
			if (str[i - 1] != '0')	// 避免产生10.0000020变成10.2
			{
				break; 
			}
		}

		// CString str4 = str3;
		if (str3[str3.GetLength() - 1] == '.') {
			str3.Delete(str3.GetLength() - 1);
		}
		str = str3;
	}
	UpdateData(FALSE);
}



void CCalculatorDlg::OnBnClickedButtonenter()
{
	// TODO: 在此添加控件通知处理程序代码
	calc();
	tempStr = L"";
	flag = true;
	count = 0;
}

void CCalculatorDlg::calc()
{
	UpdateData(TRUE);
	num2 = _wtof(str);
	double ret = 0;

	// 计算结果
	switch (op) {
	case PLUS:
		ret = num1 + num2;
		tempStr = tempStr + _T(" + ") + str + _T(" = ");
		break;
	case SUB:
		ret = num1 + num2;
		tempStr = tempStr + _T(" + ") + str + _T(" = ");
		break;
	case MUL:
		ret = num1 * num2;
		tempStr += _T(" * ") + str + _T(" = ");
		break;
	case DIV:
		if (num2 == 0.0f) {
			ret = 0;
			tempStr = _T("除数不能为");
			MessageBox(TEXT("除数不能为0"),TEXT("提示"));
		}
		ret = num1 / num2;
		tempStr += _T(" / ") + str + _T(" = ");
		break;
	case MOD:
		
		ret = int(num1) % int(num2);
		tempStr += _T(" % ") + str + _T(" = ");
		break;
	default:
		break;

	}

	// 浮点数转换成字符串
	str.Format(_T("%f"), ret);
	

	//下面用于历史记录
	std::string s(CT2A(tempStr.GetString()));
	double want = evaluate(s);
	// 浮点数转换成字符串
	str.Format(_T("%f"), want);
	//  str.Format(_T("%f"), ret);
	// 去0操作
	int pos = str.Find('.');//小数点的位置，把小数点后面的0都删掉
	CString str3 = str;
	for (int i = str.GetLength() - 1; i > pos; i--) {
		if (str[i] == '0')
		{
			str3.Delete(i);// 把尾数0去掉
		}
		if (str[i - 1] != '0')	//避免产生10.00020变成10.2
		{
			break;
		}
	}
	if (str3[str3.GetLength() - 1] == '.')//把尾数是小数点去掉
	{
		str3.Delete(str3.GetLength() - 1);
	}
	str = str3;
	tempStr = tempStr + str;
	str2 = tempStr;
	
	UpdateData(FALSE);
	num1 = ret;
	num2 = 0;
}



bool isOperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/' || c=='%';
}

int precedence(char op){
	if (op == '+' || op == '-') {
		return 1;
	}
	if (op == '*' || op == '/'||op=='%') {
		return 2;
	}
	return 0;
}
double applyOp(double a, double b, char op) {
	switch (op) {
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': return a / b;
	case '%': return int(a) % int(b);
	}
	return 0.0;
}

double evaluate(string s) {

	int n = s.length()-1;
	stack<double> values;
	stack<char> ops;
	for (int i = 0; i < n; i++) {
		if (s[i] == ' ') { // 忽略空格
			continue;
		}
		else if (isdigit(s[i]) || s[i] == '.') { // 处理数字
			double num = 0;
			int decimal_digits = 0;
			bool is_negative = false;
			if (s[i] == '-') {
				is_negative = true;
				i++;
			}
			while (i < n && (isdigit(s[i]) || s[i] == '.')) {
				if (s[i] == '.') {
					decimal_digits = 1;
					i++;
					break;
				}
				num = num * 10 + (s[i] - '0');
				i++;
			}
			while (decimal_digits > 0 && i < n && isdigit(s[i])) {
				num += (s[i] - '0') * pow(10, -decimal_digits);
				decimal_digits++;
				i++;
			}
			if (is_negative) {
				num = -num;
			}
			values.push(num);
			i--;
		}
		else if (isOperator(s[i])) { // 处理操作符
			char op = s[i];
			if (op == '-') {
				if (i == 0 || (!isdigit(s[i - 1]) && s[i - 1] != '.')) { // 减号表示负数
					i++;
					double num = 0;
					int decimal_digits = 0;
					while (i < n && (isdigit(s[i]) || s[i] == '.')) {
						if (s[i] == '.') {
							decimal_digits = 1;
							i++;
							break;
						}
						num = num * 10 + (s[i] - '0');
						i++;
					}
					while (decimal_digits > 0 && i < n && isdigit(s[i])) {
						num += (s[i] - '0') * pow(10, -decimal_digits);
						decimal_digits++;
						i++;
					}
					num = -num;
					values.push(num);
					i--;
					continue;
				}
			}
			while (!ops.empty() && precedence(ops.top()) >= precedence(op)) {
				double b = values.top();
				values.pop();
				double a = values.top();
				values.pop();
				char op1 = ops.top();
				ops.pop();
				values.push(applyOp(a, b, op1));
			}
			ops.push(op);
		}
	}

	while (!ops.empty()) { // 处理剩余的操作符
		double b = values.top();
		values.pop();
		double a = values.top();
		values.pop();
		char op = ops.top();
		ops.pop();
		values.push(applyOp(a, b, op));
	}

	return values.top();
}


void CCalculatorDlg::OnBnClickedButtonplus()
{
	// TODO: 在此添加控件通知处理程序代码
	count++;
	SaveFirstValue();
	op = PLUS;
}

void CCalculatorDlg::SaveFirstValue()
{
	if (count == 1)	// 1+2
	{
		UpdateData(TRUE);
		num1 = _wtof(str);
		tempNum = num1;//temp保存（上一次）num1的值
		tempStr = str;//tempStr是为了构建历史记录，暂存一下输入内容
		str = L"";
		UpdateData(FALSE);
	}
	else // 形如1+2-3=这种
	{
		UpdateData(TRUE);
		num1 = _wtof(str);
		if (op == PLUS) {	// 这里需要进行相应的优化
			num1 = tempNum + num1;//上次的num1 + 这次的num1 称为num1,
			tempNum = num1;
			tempStr = tempStr + L" + " + str;
		}
		else if (op = MUL) {
			num1 = tempNum * num1;//上次的num1 * 这次的num1 称为num1,
			tempNum = num1;
			tempStr = tempStr + L" * " + str;
		}
		else if (op == DIV) {
			num1 = tempNum / num1;//上次的num1 / 这次的num1 称为num1,
			tempNum = num1;
			tempStr = tempStr + L" / " + str;
		}
		else if (op == SUB) {
			num1 = tempNum + num1;//上次的num1 + 这次的num1 称为num1,
			tempNum = num1;
			tempStr = tempStr + L" + " + str;
		}
		else if (op == MOD)
		{
			num1 = fmod(tempNum , num1);//上次的num1 % 这次的num1 称为num1,
			tempNum = num1;
			tempStr = tempStr + L" % " + str;
		}
		// tempStr = str; tempStr是为了构建历史记录，暂存一下输入内容
	}
	str = L"";
	UpdateData(FALSE);
}



void CCalculatorDlg::OnBnClickedButtonminus()
{
	// TODO: 在此添加控件通知处理程序代码
	count++;
	SaveFirstValue();
	op = SUB;
}


void CCalculatorDlg::OnBnClickedButtonmul()
{
	// TODO: 在此添加控件通知处理程序代码
	count++;
	SaveFirstValue();
	op = MUL;
}




void CCalculatorDlg::OnBnClickedButtondiv()
{
	// TODO: 在此添加控件通知处理程序代码
	count++;
	SaveFirstValue();
	op = DIV;
}

void CCalculatorDlg::OnBnClickedButtonmod()
{
	// TODO: 在此添加控件通知处理程序代码
	count++;
	SaveFirstValue();
	op = MOD;
}


void CCalculatorDlg::OnBnClickedlog()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnBnClickedtan()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	double ret = _wtof(str);
	ret = tan(ret);
	str.Format(_T("%f"), ret);
	// 去0操作
	int pos = str.Find('.');//小数点的位置，把小数点后面的0都删掉
	CString str3 = str;
	for (int i = str.GetLength() - 1; i > pos; i--) {
		if (str[i] == '0')
		{
			str3.Delete(i);// 把尾数0去掉
		}
		if (str[i - 1] != '0')	//避免产生10.00020变成10.2
		{
			break;
		}
	}
	if (str3[str3.GetLength() - 1] == '.')//把尾数是小数点去掉
	{
		str3.Delete(str3.GetLength() - 1);
	}
	str = str3;
	tempStr = tempStr + str;
	str2 = tempStr;
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedcos()
{
	/*UpdateData(TRUE);
	double a = _wtof(str);
	a = cos(a);
	str.Format(_T("%f"), a);
	UpdateData(FALSE);*/
	OnBnClickedButtonclear();
	


	// TODO: 在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnBnClickedsin()
{
	// TODO: 在此添加控件通知处理程序代码
}




HBRUSH CCalculatorDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	if (pWnd == this) {
		return m_bgBrush;
	}
	
	return hbr;
}


LRESULT CCalculatorDlg::OnNcHitTest(CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	return CDialogEx::OnNcHitTest(point);
}


void CCalculatorDlg::OnBnClickedButtonsin()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);

	double a = _wtof(str);
	a = sin(a);
	OnBnClickedButtonclear();
	str.Format(_T("%f"), a);
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtoncos()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);

	double a = _wtof(str);
	a = cos(a);
	OnBnClickedButtonclear();
	str.Format(_T("%f"), a);
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtontan()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);

	double a = _wtof(str);
	a = tan(a);
	OnBnClickedButtonclear();
	str.Format(_T("%f"), a);
	UpdateData(FALSE);
}



void CCalculatorDlg::OnBnClickedButtonlog10()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	double a = _wtof(str);
	a = log(a);
	OnBnClickedButtonclear();
	str.Format(_T("%f"), a);
	UpdateData(FALSE);
}


void CCalculatorDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

