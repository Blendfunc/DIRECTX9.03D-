#pragma once
#include ".\DX\Include\d3dx9.h"
#include "Common.h"

struct LitPyramidVertex
{
	//顶点，法线，但是结构中没有包含表示颜色的成员变量
	//这是因为我们将用光照来计算顶点的颜色 
	float x, y, z;
	float _nx, _ny, _nz;
	static const DWORD FVF = D3DFVF_XYZ | D3DFVF_NORMAL;
};

class CLitPyramid
{

public:
	CLitPyramid();
	~CLitPyramid();
	void Init(inparameter IDirect3DDevice9 * pDevice);
private:
	IDirect3DVertexBuffer9 * m_VB;//顶点数据

	IDirect3DIndexBuffer9 * m_IB;//索引数据

	IDirect3DDevice9 * m_pDevice;
};