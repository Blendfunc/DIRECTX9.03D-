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
	PAINTSTRUCT ps;         //���ƽṹ
	switch (message)        //����õ�����Ϣ
	{
	case WM_CREATE:          //���ڴ������ʱ��������Ϣ
		MessageBox(hwnd, TEXT("�����Ѵ������!"), TEXT("�ҵĴ���"), MB_OK | MB_ICONINFORMATION);
		return 0;

	case WM_PAINT:           //������������Чʱ��������Ϣ
							 /*hdc = BeginPaint(hwnd, &ps);
							 GetClientRect(hwnd, &rect);
							 DrawText(hdc, TEXT("Hello, �������Լ��Ĵ���!"), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);*/
		BeginPaint(hwnd, &ps);
		EndPaint(hwnd, &ps);
		return 0;
	case WM_LBUTTONDOWN:     //���������������µ���Ϣ
							 /*MessageBox(hwnd, TEXT("�����������¡�"), TEXT("����"), MB_OK | MB_ICONINFORMATION);
							 return 0;*/

	case WM_DESTROY:         //�����ڹر�ʱ����Ϣ
		MessageBox(hwnd, TEXT("�رճ���!"), TEXT("����"), MB_OK | MB_ICONINFORMATION);
		PostQuitMessage(0);
		return 0;
	}
	
	return DefWindowProc(hwnd, message, wParam, lParam);        //DefWindowProc���������Զ������Ϣ������û�д�������Ϣ
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	static TCHAR szAppName[] = TEXT("MyWindow");
	HWND hwnd;
	MSG msg;
	WNDCLASS wndclass;        //����һ�����������

							  //����Ϊ���������wndclass������
	wndclass.style = CS_HREDRAW | CS_VREDRAW;                         //������ʽ
	wndclass.lpszClassName = szAppName;                               //��������
	wndclass.lpszMenuName = NULL;                                     //���ڲ˵�:��
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);    //���ڱ�����ɫ
	wndclass.lpfnWndProc = WndProc;                                   //���ڴ�����
	wndclass.cbWndExtra = 0;                                          //����ʵ����չ:��
	wndclass.cbClsExtra = 0;                                          //��������չ:��
	wndclass.hInstance = hInstance;                                   //����ʵ�����
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);               //������С��ͼ��:ʹ��ȱʡͼ��
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);                 //���ڲ��ü�ͷ���

	if (!RegisterClass(&wndclass))
	{    //ע�ᴰ����, ���ע��ʧ�ܵ���������ʾ
		MessageBox(NULL, TEXT("����ע��ʧ��!"), TEXT("����"), MB_OK | MB_ICONERROR);
		return 0;
	}

	hwnd = CreateWindow(                   //��������
		szAppName,                 //��������
		TEXT("�ҵĴ���"),           //���ڱ���
		WS_OVERLAPPEDWINDOW,       //���ڵķ��
		CW_USEDEFAULT,             //���ڳ�ʼ��ʾλ��x:ʹ��ȱʡֵ
		CW_USEDEFAULT,             //���ڳ�ʼ��ʾλ��y:ʹ��ȱʡֵ
		800,             //���ڵĿ��:ʹ��ȱʡֵ
		600,             //���ڵĸ߶�:ʹ��ȱʡֵ
		NULL,                      //������:��
		NULL,                      //�Ӳ˵�:��
		hInstance,                 //�ô���Ӧ�ó����ʵ����� 
		NULL                       //
		);
	Init(hwnd);
	ShowWindow(hwnd, iCmdShow);        //��ʾ����
	UpdateWindow(hwnd);                //���´���

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
	
	while (GetMessage(&msg, NULL, 0, 0))        //����Ϣ�����л�ȡ��Ϣ
	{
		if (msg.message != WM_QUIT)
		{
			/*i = i + 0.0001f;*/
			/*cube.Display(i);*/
			if (::PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
			{
				
				TranslateMessage(&msg);                 //���������Ϣת��Ϊ�ַ���Ϣ
				DispatchMessage(&msg);                  //�ַ����ص�����(���̺���)

			}
			else
			{
				//Display(static_device);
			}
		}	
	}
}