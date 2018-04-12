#pragma once
#include ".\DX\Include\d3dx9.h"
#include "_GraphInterface_.h"
#include "assert.h"
#include "CalculateNormalVectorOfThePlane.h"
#include "Common.h"
#include "CopyData.h"
#include "CalculateNormalVectorOfThePlane.h"

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