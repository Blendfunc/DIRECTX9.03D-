#pragma once
#include ".\DX\Include\d3dx9.h"
#include "Common.h"
#include "CalculateNormalVectorOfThePlane.h"
#include "Materials.h"

struct LitPyramidVertex
{
	//顶点，法线，但是结构中没有包含表示颜色的成员变量
	//这是因为我们将用光照来计算顶点的颜色 
	float x, y, z;//顶点
	float _nx, _ny, _nz;//法线
	static const DWORD FVF = D3DFVF_XYZ | D3DFVF_NORMAL;
};

static void InitializeLitPyramidVertex(inparameter outparameter LitPyramidVertex * p , D3DXVECTOR3 * point , D3DXVECTOR3 * normal);//

class CLitPyramid
{

public:
	CLitPyramid();
	~CLitPyramid();
	void Init(inparameter IDirect3DDevice9 * pDevice);
protected:
	void calc(LitPyramidVertex & lpv1 , LitPyramidVertex & lpv2 , LitPyramidVertex & lpv3 , float f1 , float f2 , float f3 , float _f1 , float _f2 , float _f3 , float __f1 , float __f2 , float __f3);
private:
	IDirect3DVertexBuffer9 * m_VB;//顶点数据

	IDirect3DIndexBuffer9 * m_IB;//索引数据

	IDirect3DDevice9 * m_pDevice;

};