#pragma once
#include ".\DX\Include\d3dx9.h"
#include "Base.h"
class CLitPyramid
{

public:
	CLitPyramid();
	~CLitPyramid();
private:
	IDirect3DVertexBuffer9 * m_VB;//顶点数据

	IDirect3DIndexBuffer9 * m_IB;//索引数据

	IDirect3DDevice9 * m_pDevice;
};