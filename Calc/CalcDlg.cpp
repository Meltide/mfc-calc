// CalcDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Calc.h"
#include "CalcDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CFont m_editFont; // 字体对象

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
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalcDlg 对话框



CCalcDlg::CCalcDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCalcDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON_1, &CCalcDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_2, &CCalcDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_3, &CCalcDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_4, &CCalcDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_5, &CCalcDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON_6, &CCalcDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_7, &CCalcDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON_8, &CCalcDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON_9, &CCalcDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_0, &CCalcDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_BKSP, &CCalcDlg::OnBnClickedButtonBksp)
	ON_BN_CLICKED(IDC_BUTTON_PLUS, &CCalcDlg::OnBnClickedButtonPlus)
	ON_BN_CLICKED(IDC_BUTTON_POINT, &CCalcDlg::OnBnClickedButtonPoint)
	ON_BN_CLICKED(IDC_BUTTON_CE, &CCalcDlg::OnBnClickedButtonCe)
	ON_BN_CLICKED(IDC_BUTTON_SUB, &CCalcDlg::OnBnClickedButtonSub)
	ON_BN_CLICKED(IDC_BUTTON_MUL, &CCalcDlg::OnBnClickedButtonMul)
	ON_BN_CLICKED(IDC_BUTTON_DIV, &CCalcDlg::OnBnClickedButtonDiv)
	ON_BN_CLICKED(IDC_BUTTON_MOD, &CCalcDlg::OnClickedButtonMod)
	ON_BN_CLICKED(IDC_BUTTON_EQU, &CCalcDlg::OnBnClickedButtonEqu)
END_MESSAGE_MAP()


// CCalcDlg 消息处理程序

BOOL CCalcDlg::OnInitDialog()
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
	}

	// 设置此对话框的图标
	SetIcon(m_hIcon, TRUE);  // 设置大图标
	SetIcon(m_hIcon, FALSE); // 设置小图标

	// 获取当前窗口样式
	LONG lStyle = GetWindowLong(this->m_hWnd, GWL_STYLE);

	// 移除可调整大小的样式
	lStyle &= ~WS_THICKFRAME;

	// 设置新的窗口样式
	SetWindowLong(this->m_hWnd, GWL_STYLE, lStyle);

	// 初始化白色背景画刷
	m_brushWhite.CreateSolidBrush(RGB(255, 255, 255));

	m_bClearInput = false; // 初始化清除输入标志为false
	m_bCalcComplete = false; // 初始化计算完成标志为false

	// 创建更大的字体并应用到IDC_EDIT1
	m_editFont.CreatePointFont(155, _T("微软雅黑")); // 18磅字体，可根据需要调整
	GetDlgItem(IDC_EDIT1)->SetFont(&m_editFont);

	// 设置按钮字体大小
	m_editFont.CreatePointFont(120, _T("微软雅黑"));
	GetDlgItem(IDC_BUTTON_1)->SetFont(&m_editFont);
	GetDlgItem(IDC_BUTTON_2)->SetFont(&m_editFont);
	GetDlgItem(IDC_BUTTON_3)->SetFont(&m_editFont);
	GetDlgItem(IDC_BUTTON_4)->SetFont(&m_editFont);
	GetDlgItem(IDC_BUTTON_5)->SetFont(&m_editFont);
	GetDlgItem(IDC_BUTTON_6)->SetFont(&m_editFont);
	GetDlgItem(IDC_BUTTON_7)->SetFont(&m_editFont);
	GetDlgItem(IDC_BUTTON_8)->SetFont(&m_editFont);
	GetDlgItem(IDC_BUTTON_9)->SetFont(&m_editFont);
	GetDlgItem(IDC_BUTTON_0)->SetFont(&m_editFont);
	GetDlgItem(IDC_BUTTON_POINT)->SetFont(&m_editFont);
	GetDlgItem(IDC_BUTTON_PLUS)->SetFont(&m_editFont);
	GetDlgItem(IDC_BUTTON_SUB)->SetFont(&m_editFont);
	GetDlgItem(IDC_BUTTON_MUL)->SetFont(&m_editFont);
	GetDlgItem(IDC_BUTTON_DIV)->SetFont(&m_editFont);
	GetDlgItem(IDC_BUTTON_MOD)->SetFont(&m_editFont);
	GetDlgItem(IDC_BUTTON_EQU)->SetFont(&m_editFont);
	GetDlgItem(IDC_BUTTON_BKSP)->SetFont(&m_editFont);
	GetDlgItem(IDC_BUTTON_CE)->SetFont(&m_editFont);

	SetDlgItemText(IDC_EDIT_STATUS, _T("未输入操作"));

	// 设置焦点到 IDC_EDIT1 控件
	CWnd* pEdit = GetDlgItem(IDC_EDIT1);
	if (pEdit != nullptr)
	{
		pEdit->SetFocus();
		return FALSE; // 返回 FALSE 以指示我们已手动设置焦点
	}

	CenterWindow(); // 窗口居中

	ShowWindow(SW_MINIMIZE);

	// TODO: 在此添加额外的初始化代码

	// 设置标签的位置和大小
	CWnd* pLabel = GetDlgItem(IDC_STATIC);
	if (pLabel != nullptr)
	{
		// 设置标签的位置和大小 (x, y, width, height)
		pLabel->MoveWindow(50, 50, 200, 30); // 示例：x=50, y=50, 宽度=200, 高度=30
	}

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCalcDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCalcDlg::OnPaint()
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

HBRUSH CCalcDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
    if (pWnd->GetDlgCtrlID() == IDC_EDIT1 && nCtlColor == CTLCOLOR_EDIT)
    {
        // 设置编辑框背景为白色
        pDC->SetBkColor(RGB(255, 255, 255));
        return this->m_brushWhite; // 使用当前类的成员
    }

    // 显式调用基类的 OnCtlColor 方法
    return CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCalcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


CString opt;
float num1, num2, result;

void CCalcDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs;
	if (m_bClearInput)
	{
		SetDlgItemText(IDC_EDIT1, _T("")); // 清空输入框
		if (m_bCalcComplete)
		{
			SetDlgItemText(IDC_EDIT_STATUS, _T("未输入操作"));
			m_bCalcComplete = false; // 重置计算完成标志
		}
		m_bClearInput = false;            // 重置标志位
	}
	GetDlgItemText(IDC_EDIT1, cs);
	SetDlgItemText(IDC_EDIT1, cs + _T("1"));
}

void CCalcDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs;
	if (m_bClearInput)
	{
		SetDlgItemText(IDC_EDIT1, _T("")); // 清空输入框
		if (m_bCalcComplete)
		{
			SetDlgItemText(IDC_EDIT_STATUS, _T("未输入操作"));
			m_bCalcComplete = false; // 重置计算完成标志
		}
		m_bClearInput = false;            // 重置标志位
	}
	GetDlgItemText(IDC_EDIT1, cs);
	SetDlgItemText(IDC_EDIT1, cs + _T("2"));
}

void CCalcDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs;
	if (m_bClearInput)
	{
		SetDlgItemText(IDC_EDIT1, _T("")); // 清空输入框
		if (m_bCalcComplete)
		{
			SetDlgItemText(IDC_EDIT_STATUS, _T("未输入操作"));
			m_bCalcComplete = false; // 重置计算完成标志
		}
		m_bClearInput = false;            // 重置标志位
	}
	GetDlgItemText(IDC_EDIT1, cs);
	SetDlgItemText(IDC_EDIT1, cs + _T("3"));
}

void CCalcDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs;
	if (m_bClearInput)
	{
		SetDlgItemText(IDC_EDIT1, _T("")); // 清空输入框
		if (m_bCalcComplete)
		{
			SetDlgItemText(IDC_EDIT_STATUS, _T("未输入操作"));
			m_bCalcComplete = false; // 重置计算完成标志
		}
		m_bClearInput = false;            // 重置标志位
	}
	GetDlgItemText(IDC_EDIT1, cs);
	SetDlgItemText(IDC_EDIT1, cs + _T("4"));
}

void CCalcDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs;
	if (m_bClearInput)
	{
		SetDlgItemText(IDC_EDIT1, _T("")); // 清空输入框
		if (m_bCalcComplete)
		{
			SetDlgItemText(IDC_EDIT_STATUS, _T("未输入操作"));
			m_bCalcComplete = false; // 重置计算完成标志
		}
		m_bClearInput = false;            // 重置标志位
	}
	GetDlgItemText(IDC_EDIT1, cs);
	SetDlgItemText(IDC_EDIT1, cs + _T("5"));
}

void CCalcDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs;
	if (m_bClearInput)
	{
		SetDlgItemText(IDC_EDIT1, _T("")); // 清空输入框
		if (m_bCalcComplete)
		{
			SetDlgItemText(IDC_EDIT_STATUS, _T("未输入操作"));
			m_bCalcComplete = false; // 重置计算完成标志
		}
		m_bClearInput = false;            // 重置标志位
	}
	GetDlgItemText(IDC_EDIT1, cs);
	SetDlgItemText(IDC_EDIT1, cs + _T("6"));
}

void CCalcDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs;
	if (m_bClearInput)
	{
		SetDlgItemText(IDC_EDIT1, _T("")); // 清空输入框
		if (m_bCalcComplete)
		{
			SetDlgItemText(IDC_EDIT_STATUS, _T("未输入操作"));
			m_bCalcComplete = false; // 重置计算完成标志
		}
		m_bClearInput = false;            // 重置标志位
	}
	GetDlgItemText(IDC_EDIT1, cs);
	SetDlgItemText(IDC_EDIT1, cs + _T("7"));
}

void CCalcDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs;
	if (m_bClearInput)
	{
		SetDlgItemText(IDC_EDIT1, _T("")); // 清空输入框
		if (m_bCalcComplete)
		{
			SetDlgItemText(IDC_EDIT_STATUS, _T("未输入操作"));
			m_bCalcComplete = false; // 重置计算完成标志
		}
		m_bClearInput = false;            // 重置标志位
	}
	GetDlgItemText(IDC_EDIT1, cs);
	SetDlgItemText(IDC_EDIT1, cs + _T("8"));
}

void CCalcDlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs;
	if (m_bClearInput)
	{
		SetDlgItemText(IDC_EDIT1, _T("")); // 清空输入框
		if (m_bCalcComplete)
		{
			SetDlgItemText(IDC_EDIT_STATUS, _T("未输入操作"));
			m_bCalcComplete = false; // 重置计算完成标志
		}
		m_bClearInput = false;            // 重置标志位
	}
	GetDlgItemText(IDC_EDIT1, cs);
	SetDlgItemText(IDC_EDIT1, cs + _T("9"));
}

void CCalcDlg::OnBnClickedButton0()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs;
	if (m_bClearInput)
	{
		SetDlgItemText(IDC_EDIT1, _T("")); // 清空输入框
		if (m_bCalcComplete)
		{
			SetDlgItemText(IDC_EDIT_STATUS, _T("未输入操作"));
			m_bCalcComplete = false; // 重置计算完成标志
		}
		m_bClearInput = false;            // 重置标志位
	}
	GetDlgItemText(IDC_EDIT1, cs);
	SetDlgItemText(IDC_EDIT1, cs + _T("0"));
}

void CCalcDlg::OnBnClickedButtonPoint()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs;
	if (m_bClearInput)
	{
		SetDlgItemText(IDC_EDIT1, _T("")); // 清空输入框
		if (m_bCalcComplete)
		{
			SetDlgItemText(IDC_EDIT_STATUS, _T("未输入操作"));
			m_bCalcComplete = false; // 重置计算完成标志
		}
		m_bClearInput = false;            // 重置标志位
	}
	GetDlgItemText(IDC_EDIT1, cs);
	SetDlgItemText(IDC_EDIT1, cs + _T("."));
}

void CCalcDlg::OnBnClickedButtonBksp()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs;
	GetDlgItemText(IDC_EDIT1, cs);
	cs.Delete(cs.GetLength() - 1);
	SetDlgItemText(IDC_EDIT1, cs);
}

void CCalcDlg::OnBnClickedButtonCe()
{
	// TODO: 在此添加控件通知处理程序代码
	SetDlgItemText(IDC_EDIT1, _T(""));
	SetDlgItemText(IDC_EDIT_STATUS, _T("未输入操作"));
	num1 = 0;
	num2 = 0;
	opt = _T("");
}

void CCalcDlg::OnBnClickedButtonPlus()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs;
	GetDlgItemText(IDC_EDIT1, cs);
	SetDlgItemText(IDC_EDIT_STATUS, _T("+ 加法"));
	m_bClearInput = true; // 设置标志位为true，表示下次输入时清空输入框
	if (m_bCalcComplete) m_bCalcComplete = false; // 重置计算完成标志
	num1 = _tstof(cs); // 获取第一个操作数
	opt = _T("+");
}

void CCalcDlg::OnBnClickedButtonSub()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs;
	GetDlgItemText(IDC_EDIT1, cs);
	SetDlgItemText(IDC_EDIT_STATUS, _T("- 减法"));
	m_bClearInput = true; // 设置标志位为true，表示下次输入时清空输入框
	if (m_bCalcComplete) m_bCalcComplete = false; // 重置计算完成标志
	num1 = _tstof(cs); // 获取第一个操作数
	opt = _T("-");
}

void CCalcDlg::OnBnClickedButtonMul()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs;
	GetDlgItemText(IDC_EDIT1, cs);
	SetDlgItemText(IDC_EDIT_STATUS, _T("* 乘法"));
	m_bClearInput = true; // 设置标志位为true，表示下次输入时清空输入框
	if (m_bCalcComplete) m_bCalcComplete = false; // 重置计算完成标志
	num1 = _tstof(cs); // 获取第一个操作数
	opt = _T("*");
}

void CCalcDlg::OnBnClickedButtonDiv()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs;
	GetDlgItemText(IDC_EDIT1, cs);
	SetDlgItemText(IDC_EDIT_STATUS, _T("/ 除法"));
	m_bClearInput = true; // 设置标志位为true，表示下次输入时清空输入框
	if (m_bCalcComplete) m_bCalcComplete = false; // 重置计算完成标志
	num1 = _tstof(cs); // 获取第一个操作数
	opt = _T("/");
}

void CCalcDlg::OnClickedButtonMod()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs;
	GetDlgItemText(IDC_EDIT1, cs);
	SetDlgItemText(IDC_EDIT_STATUS, _T("% 取模"));
	m_bClearInput = true; // 设置标志位为true，表示下次输入时清空输入框
	if (m_bCalcComplete) m_bCalcComplete = false; // 重置计算完成标志
	num1 = _tstof(cs); // 获取第一个操作数
	opt = _T("%");
}

void CCalcDlg::OnBnClickedButtonEqu()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs;
	GetDlgItemText(IDC_EDIT1, cs);
	num2 = _tstof(cs); // 获取第二个操作数

	if (!opt.Compare(_T("+")))
	{
		result = num1 + num2;
	}
	else if (!opt.Compare(_T("-")))
	{
		result = num1 - num2;
	}
	else if (!opt.Compare(_T("*")))
	{
		result = num1 * num2;
	}
	else if (!opt.Compare(_T("/")))
	{
		if (num2 == 0)
		{
			SetDlgItemText(IDC_EDIT1, _T("除数不能为零！"));
			return;
		}
		result = num1 / num2;
	}
	else if (!opt.Compare(_T("%")))
	{
		if (num2 == 0)
		{
			SetDlgItemText(IDC_EDIT_STATUS, _T("除数不能为零！"));
			return;
		}
		result = static_cast<int>(num1) % static_cast<int>(num2);
	}

	cs.Format(_T("%.16f"), result); // 格式化结果，保留两位小数

	int len = cs.GetLength();
	for (; cs.Mid(len - 1) == _T("0"); len--)
		cs = cs.Left(len - 1); // 去掉末尾的0
	if (cs.Mid(len - 1) == _T(".")) // 如果最后一个字符是小数点，去掉它
		cs = cs.Left(len - 1);

	SetDlgItemText(IDC_EDIT_STATUS, _T("计算结果"));
	SetDlgItemText(IDC_EDIT1, cs); // 显示结果，保留两位小数
	m_bClearInput = true; // 设置标志位为true，表示下次输入时清空输入框
	m_bCalcComplete = true; // 设置计算完成标志为true
}

BOOL CCalcDlg::PreTranslateMessage(MSG* pMsg)
{
    if (pMsg->message == WM_KEYDOWN)
    {
        switch (pMsg->wParam)
        {
        case '0':
            OnBnClickedButton0();
            return TRUE;
        case '1':
            OnBnClickedButton1();
            return TRUE;
        case '2':
            OnBnClickedButton2();
            return TRUE;
        case '3':
            OnBnClickedButton3();
            return TRUE;
        case '4':
            OnBnClickedButton4();
            return TRUE;
        case '5':
            OnBnClickedButton5();
            return TRUE;
        case '6':
            OnBnClickedButton6();
            return TRUE;
        case '7':
            OnBnClickedButton7();
            return TRUE;
        case '8':
            OnBnClickedButton8();
            return TRUE;
        case '9':
            OnBnClickedButton9();
            return TRUE;
		case '+':
			OnBnClickedButtonPlus();
			return TRUE;
		case '-':
			OnBnClickedButtonSub();
			return TRUE;
		case '*':
			OnBnClickedButtonMul();
			return TRUE;
		case '/':
			OnBnClickedButtonDiv();
			return TRUE;
		case '%':
			OnClickedButtonMod();
			return TRUE;
        case VK_DECIMAL: // 小数点键
        case '.':
            OnBnClickedButtonPoint();
            return TRUE;
        case VK_BACK: // 退格键
            OnBnClickedButtonBksp();
            return TRUE;
        case VK_RETURN: // 回车键
            OnBnClickedButtonEqu();
            return TRUE;
        }
    }

    return CDialogEx::PreTranslateMessage(pMsg);
}
