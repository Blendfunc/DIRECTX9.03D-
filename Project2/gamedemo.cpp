#include".\DX\Include\d3dx9.h"
#include "cube.h"
#include "LitPyramid.h"
static IDirect3D9 * static_d3d9;
static D3DCAPS9 static_d3dpp;
static IDirect3DDevice9 * static_device;
bool Display(IDirect3DDevice9 * device)
{
	if (device)
	{
		device->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0xffffffff, 1.0f, 0);
		device->Present(0, 0, 0, 0);
		return true;
	}
	return false;
}
void Init(HWND hwnd)
{
	/*HWND hwnd = 0;*/
	IDirect3D9 * _d3d9;
	_d3d9 = Direct3DCreate9(D3D_SDK_VERSION);
	static_d3d9 = _d3d9;
	D3DCAPS9 caps;
	_d3d9->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &caps);



	D3DPRESENT_PARAMETERS d3dpp;
	d3dpp.BackBufferWidth = 800;
	d3dpp.BackBufferHeight = 600;
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
	d3dpp.BackBufferCount = 1;
	d3dpp.MultiSampleType = D3DMULTISAMPLE_NONE;
	d3dpp.MultiSampleQuality = 0;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = hwnd;
	d3dpp.Windowed = true;
	d3dpp.EnableAutoDepthStencil = true;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;
	d3dpp.Flags = 0;
	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
	IDirect3DDevice9 * device = 0;
	HRESULT hr = _d3d9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &device);
	if (hr == D3DERR_INVALIDCALL)
	{
		::MessageBox(0, "CreateDevice() - FAILED", 0, 0);
	}
	else if (hr == D3DERR_NOTAVAILABLE)
	{
		::MessageBox(0, "CreateDevice() - FAILED", 0, 0);
	}
	else if (hr == D3DERR_OUTOFVIDEOMEMORY)
	{
		::MessageBox(0, "CreateDevice() - FAILED", 0, 0);
	}
	else
	{
		::MessageBox(0, "CreateDevice() - YES", 0, 0);
		static_device = device;
		/*Display(device);*/
	}
	DWORD dw = ::GetLastError();
	if (FAILED(hr))
	{
		::MessageBox(0, "CreateDevice() - FAILED", 0, 0);
		//return 0 ;
	}
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;         //绘制结构
	switch (message)        //处理得到的消息
	{
	case WM_CREATE:          //窗口创建完成时发来的消息
		MessageBox(hwnd, TEXT("窗口已创建完成!"), TEXT("我的窗口"), MB_OK | MB_ICONINFORMATION);
		return 0;

	case WM_PAINT:           //处理窗口区域无效时发来的消息
							 /*hdc = BeginPaint(hwnd, &ps);
							 GetClientRect(hwnd, &rect);
							 DrawText(hdc, TEXT("Hello, 这是我自己的窗口!"), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);*/
		BeginPaint(hwnd, &ps);
		EndPaint(hwnd, &ps);
		return 0;
	case WM_LBUTTONDOWN:     //处理鼠标左键被按下的消息
							 /*MessageBox(hwnd, TEXT("鼠标左键被按下。"), TEXT("单击"), MB_OK | MB_ICONINFORMATION);
							 return 0;*/

	case WM_DESTROY:         //处理窗口关闭时的消息
		MessageBox(hwnd, TEXT("关闭程序!"), TEXT("结束"), MB_OK | MB_ICONINFORMATION);
		PostQuitMessage(0);
		return 0;
	}
	
	return DefWindowProc(hwnd, message, wParam, lParam);        //DefWindowProc处理我们自定义的消息处理函数没有处理到的消息
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	static TCHAR szAppName[] = TEXT("MyWindow");
	HWND hwnd;
	MSG msg;
	WNDCLASS wndclass;        //声明一个窗口类对象

							  //以下为窗口类对象wndclass的属性
	wndclass.style = CS_HREDRAW | CS_VREDRAW;                         //窗口样式
	wndclass.lpszClassName = szAppName;                               //窗口类名
	wndclass.lpszMenuName = NULL;                                     //窗口菜单:无
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);    //窗口背景颜色
	wndclass.lpfnWndProc = WndProc;                                   //窗口处理函数
	wndclass.cbWndExtra = 0;                                          //窗口实例扩展:无
	wndclass.cbClsExtra = 0;                                          //窗口类扩展:无
	wndclass.hInstance = hInstance;                                   //窗口实例句柄
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);               //窗口最小化图标:使用缺省图标
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);                 //窗口采用箭头光标

	if (!RegisterClass(&wndclass))
	{    //注册窗口类, 如果注册失败弹出错误提示
		MessageBox(NULL, TEXT("窗口注册失败!"), TEXT("错误"), MB_OK | MB_ICONERROR);
		return 0;
	}

	hwnd = CreateWindow(                   //创建窗口
		szAppName,                 //窗口类名
		TEXT("我的窗口"),           //窗口标题
		WS_OVERLAPPEDWINDOW,       //窗口的风格
		CW_USEDEFAULT,             //窗口初始显示位置x:使用缺省值
		CW_USEDEFAULT,             //窗口初始显示位置y:使用缺省值
		800,             //窗口的宽度:使用缺省值
		600,             //窗口的高度:使用缺省值
		NULL,                      //父窗口:无
		NULL,                      //子菜单:无
		hInstance,                 //该窗口应用程序的实例句柄 
		NULL                       //
		);
	Init(hwnd);
	ShowWindow(hwnd, iCmdShow);        //显示窗口
	UpdateWindow(hwnd);                //更新窗口

	/*CTheRevolvingBoxCube cube;
	cube.Init(static_device);*/
	CLitPyramid clp;
	clp.Init(static_device);
	static float i = 0.0f;
	while (true)
	{
		i = i + 0.000000001f;
		clp.Display(i);
	}
	
	while (GetMessage(&msg, NULL, 0, 0))        //从消息队列中获取消息
	{
		if (msg.message != WM_QUIT)
		{
			/*i = i + 0.0001f;*/
			/*cube.Display(i);*/
			if (::PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
			{
				
				TranslateMessage(&msg);                 //将虚拟键消息转换为字符消息
				DispatchMessage(&msg);                  //分发到回调函数(过程函数)

			}
			else
			{
				//Display(static_device);
			}
		}	
	}
}