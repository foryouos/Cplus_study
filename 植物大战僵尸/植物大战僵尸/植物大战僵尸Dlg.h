
// 植物大战僵尸Dlg.h: 头文件
//函数执行头文件标注

#pragma once


// C植物大战僵尸Dlg 对话框
class C植物大战僵尸Dlg : public CDialogEx
{
// 构造
public:
	C植物大战僵尸Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY_DIALOG };
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
	friend DWORD monitorThreadFunc(LPVOID);
	afx_msg void C植物大战僵尸Dlg::OnBnClickedCourse();
	afx_msg void OnBnClickedKill();
	afx_msg void OnBnClickedSun();

	CButton m_bnKill; //按钮对象
	// 无线阳光
	CButton m_bnSUn;
	//子线程句柄
	HANDLE m_monitorthread;
};
