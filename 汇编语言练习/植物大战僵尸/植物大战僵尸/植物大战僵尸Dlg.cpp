
// 植物大战僵尸Dlg.cpp: 实现文件
//对话框类实现文件

#include "pch.h"
#include "framework.h"
#include "植物大战僵尸.h"
#include "植物大战僵尸Dlg.h"
#include "afxdialogex.h"
#include <iostream>
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
C植物大战僵尸Dlg* g_dlg;
HANDLE g_processHandle;
#define log(fmt,...)\
CString str; \
str.Format(CString(fmt),__VA_ARGS__); \
AfxMessageBox(str);

// 将某个值写入植物大战僵尸内存（后面的可变参数是地址链，要以-1结尾）
void WriteMemory(void* value, DWORD valueSize, ...)
{
	if (value == NULL || valueSize == 0 || g_processHandle == NULL) return;

	DWORD tempValue = 0;

	va_list addresses;
	va_start(addresses, valueSize);
	DWORD offset = 0;
	DWORD lastAddress = 0;
	while ((offset = va_arg(addresses, DWORD)) != -1)
	{
		lastAddress = tempValue + offset;
		::ReadProcessMemory(g_processHandle, (LPCVOID)lastAddress, &tempValue, sizeof(DWORD), NULL);
	}
	va_end(addresses);

	::WriteProcessMemory(g_processHandle, (LPVOID)lastAddress, value, valueSize, NULL);
}

void WriteMemory(void* value, DWORD valueSize, DWORD address)
{
	WriteMemory(value, valueSize, address, -1);
}






//用来监控游戏的线程
DWORD monitorThreadFunc(LPVOID IpThreadParameter)
{
	while (1)
	{
		//获取植物大战僵尸的句柄
		HWND windpwHANDLE = FindWindow(CString("MainWindow"), CString("植物大战僵尸中文版"));
		
		//判断游戏是否启动
		if (windpwHANDLE == NULL)
		{
			g_dlg->m_bnKill.SetCheck(FALSE);
			g_dlg->m_bnSUn.SetCheck(FALSE);
			//没启动不能点
			g_dlg->m_bnKill.EnableWindow(FALSE);
			g_dlg->m_bnSUn.EnableWindow(FALSE);
		}
		else if(g_processHandle ==  NULL)
		{
			g_dlg->m_bnKill.EnableWindow(TRUE);
			g_dlg->m_bnSUn.EnableWindow(TRUE);


			//获得植物大战僵尸的进程ID
			DWORD processpid;
			GetWindowThreadProcessId(windpwHANDLE, &processpid);
			//获取植物大战僵尸的进程句柄
			g_processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processpid);
		}


		if (g_dlg->m_bnSUn.GetCheck())
		{
			DWORD value = 9990;
			WriteMemory(&value, sizeof(value), 0x6A9EC0, 0x320, 0x8, 0x0, 0x8, 0x144, 0x2c, 0x5560, -1);
		}
		Sleep(1000);
	}
};



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


// C植物大战僵尸Dlg 对话框



C植物大战僵尸Dlg::C植物大战僵尸Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C植物大战僵尸Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	//绑定
	DDX_Control(pDX, IDC_KILL, m_bnKill);
	DDX_Control(pDX, IDC_SUN, m_bnSUn); //无线阳光
}

BEGIN_MESSAGE_MAP(C植物大战僵尸Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(1001,&C植物大战僵尸Dlg::OnBnClickedCourse) //ID和函数绑定
	ON_BN_CLICKED(IDC_KILL, &C植物大战僵尸Dlg::OnBnClickedKill) //秒杀僵尸

	ON_BN_CLICKED(IDC_SUN, &C植物大战僵尸Dlg::OnBnClickedSun)
END_MESSAGE_MAP()


// C植物大战僵尸Dlg 消息处理程序

BOOL C植物大战僵尸Dlg::OnInitDialog()
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//c创建一条子线程，监控游戏的打开或者关闭
	m_monitorthread = CreateThread(NULL, NULL, monitorThreadFunc, NULL, NULL, NULL);

	//保存对话框
	g_dlg = this;

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C植物大战僵尸Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C植物大战僵尸Dlg::OnPaint()
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
HCURSOR C植物大战僵尸Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//获取教程的点击函数
void C植物大战僵尸Dlg::OnBnClickedCourse()
{
	//F5调试输出
	//TRACE("hello word!");
	//int age = 10;

	//CString str;
	//str.Format(CString("age is %d"), age); //C语言的输出格式要用CString标注
	//AfxMessageBox(str); //弹出新框输出

	//int age = 10;
	//CString str;
	//str.Format(CString("age is %d"), age); 
	//MessageBox(str,CString("警告!"), MB_YESNOCANCEL | MB_ICONWARNING); //显示标签和警告图表

	//调用网址
	ShellExecute(NULL, CString("open"), CString("https://www.blog.foryouos.cn"), NULL, NULL, SW_SHOWNORMAL);
}


void C植物大战僵尸Dlg::OnBnClickedKill()
{
	if (m_bnKill.GetCheck()) //需要秒杀僵尸
	{
		//用机器码覆盖
		//跨进程
		//进程句柄'
		BYTE data[] = { 0xFF,0x90,0x90 };
		WriteMemory(data, sizeof(data), 0x00531310);
	}
	else //不需要秒杀
	{
		//
		BYTE data[] = { 0x7c,0x24,0x20 };
		WriteMemory(data, sizeof(data), 0x00531310);
	}
	// TODO: 在此添加控件通知处理程序代码
	//判断是否点击
	//BOOL checked = IsDlgButtonChecked(IDC_KILL);

	//CButton *button =(CButton *) GetDlgItem(IDC_KILL); //根据ID拿到按钮
	//if (button->GetCheck()) //判断ID是否勾选
	//{
	//	log("勾选了");
	//}
	//else
	//{
	//	log("没有勾选");
	//}
	

	//if (m_bnKill.GetCheck()) //判断ID是否勾选
	//{
	//	log("勾选了");
	//}
	//else
	//{
	//	log("没有勾选");
	//}
}


//无线阳光

void C植物大战僵尸Dlg::OnBnClickedSun()
{
	// TODO: 在此添加控件通知处理程序代码
	//if (m_bnSUn.GetCheck()) //判断ID是否勾选
	//{
	//	log("勾选了");
	//}
	//else
	//{
	//	log("没有勾选");
	//}




}
