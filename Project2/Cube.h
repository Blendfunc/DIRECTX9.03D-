#pragma once
#include".\DX\Include\d3dx9.h"
#include"assert.h"
//该程序绘制了一个旋转的线框立方体
//成员变量以下划线为前缀
struct VERTEXCUBE
{
	VERTEXCUBE() {}
	VERTEXCUBE(float x, float y, float z)
	{
		_x = x; _y = y; _z = z;
	}
	float _x, _y, _z;
	static const DWORD FVF = D3DFVF_XYZ;//这里结构体sizeof计算的时候，这个变量FVF是如何计算的
};

//const DWORD VERTEXCUBE::FVF = D3DFVF_XYZ;

class CTheRevolvingBoxCube
{
public:
	CTheRevolvingBoxCube();
	~CTheRevolvingBoxCube();
	//顺序---先调用Init---后调用Display
	void Init(IDirect3DDevice9 * pDevice);
	void Display(float timeDelta);
protected:


private:
	IDirect3DVertexBuffer9 * m_VB;//顶点数据

	IDirect3DIndexBuffer9 * m_IB;//索引数据

	IDirect3DDevice9 * m_pDevice;

};