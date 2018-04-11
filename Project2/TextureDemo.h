#pragma once
#include ".\DX\Include\d3dx9.h"
#include "_GraphInterface_.h"
#include "assert.h"
#include "CalculateNormalVectorOfThePlane.h"

typedef struct TextureStruct 
{
	float _x, _y, _z;
	float _nx, _ny, _nz;
	float _u, _v;
	static const DWORD FVF = D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1;
};

class CTextureDemo : public _CGraphInterface_
{
public:
	CTextureDemo();
	~CTextureDemo();
	virtual void Init(IDirect3DDevice9 * pDevice);
	virtual void Display(float timeDelta);
protected:
private:
	//IDirect3DVertexBuffer9 * m_VB;//¶¥µãÊý¾Ý

};