#pragma once
#include ".\DX\Include\d3dx9.h"
#include "Common.h"

struct LitPyramidVertex
{
	//���㣬���ߣ����ǽṹ��û�а�����ʾ��ɫ�ĳ�Ա����
	//������Ϊ���ǽ��ù��������㶥�����ɫ 
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
	IDirect3DVertexBuffer9 * m_VB;//��������

	IDirect3DIndexBuffer9 * m_IB;//��������

	IDirect3DDevice9 * m_pDevice;
};