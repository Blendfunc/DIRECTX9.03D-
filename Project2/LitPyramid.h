#pragma once
#include ".\DX\Include\d3dx9.h"
#include "Base.h"
class CLitPyramid
{

public:
	CLitPyramid();
	~CLitPyramid();
private:
	IDirect3DVertexBuffer9 * m_VB;//��������

	IDirect3DIndexBuffer9 * m_IB;//��������

	IDirect3DDevice9 * m_pDevice;
};