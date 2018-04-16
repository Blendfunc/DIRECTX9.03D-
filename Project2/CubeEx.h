#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include".\DX\Include\d3dx9.h"
#include ".\_GraphInterface_.h"
#include "assert.h"
#include <vector>
#include "tchar.h"
#include "color.h"
#include "Light.h"
#include "Materials.h"

class CCubeEx : public _CGraphInterface_
{
public:
	CCubeEx();
	~CCubeEx();
public:
	void Init(IDirect3DDevice9 * pDevice);
	void Display(float timeDelta);
private:
	IDirect3DVertexBuffer9 * m_VB;
	IDirect3DIndexBuffer9 * m_IB;
	IDirect3DDevice9 * m_pDevice;

	char m_Texture1[MAX_PATH];
	char m_Texture2[MAX_PATH];
	char m_Texture3[MAX_PATH];

	ID3DXMesh * m_Mesh;

	IDirect3DTexture9 * m_pTexture3[3];
};