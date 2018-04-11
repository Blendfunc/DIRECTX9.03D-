#pragma once
#include".\DX\Include\d3dx9.h"
#include"assert.h"
#include"Common.h"
//该程序绘制了一个旋转的线框立方体
//成员变量以下划线为前缀


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