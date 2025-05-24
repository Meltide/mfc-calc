// CalcDlg.h: 头文件
//

#pragma once


// CCalcDlg 对话框
class CCalcDlg : public CDialogEx
{
private:
	bool m_bClearInput;
	bool m_bCalcComplete;
	CBrush m_brushWhite; // 用于背景填充
// 构造
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CCalcDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALC_DIALOG };
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
public:
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
	afx_msg void OnBnClickedButtonBksp();
	afx_msg void OnBnClickedButtonPlus();
	afx_msg void OnBnClickedButtonPoint();
	afx_msg void OnBnClickedButtonCe();
	afx_msg void OnBnClickedButtonPer();
	afx_msg void OnBnClickedButtonSub();
	afx_msg void OnBnClickedButtonMul();
	afx_msg void OnBnClickedButtonDiv();
	afx_msg void OnClickedButtonMod();
	afx_msg void OnBnClickedButtonEqu();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
