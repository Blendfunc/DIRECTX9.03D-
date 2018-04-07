#pragma once
#include".\DX\Include\d3dx9.h"
#include"assert.h"
//�ó��������һ����ת���߿�������
//��Ա�������»���Ϊǰ׺
struct VERTEXCUBE
{
	VERTEXCUBE() {}
	VERTEXCUBE(float x, float y, float z)
	{
		_x = x; _y = y; _z = z;
	}
	float _x, _y, _z;
	static const DWORD FVF = D3DFVF_XYZ;//����ṹ��sizeof�����ʱ���������FVF����μ����
};

//const DWORD VERTEXCUBE::FVF = D3DFVF_XYZ;

class CTheRevolvingBoxCube
{
public:
	CTheRevolvingBoxCube();
	~CTheRevolvingBoxCube();
	//˳��---�ȵ���Init---�����Display
	void Init(IDirect3DDevice9 * pDevice);
	void Display(float timeDelta);
protected:


private:
	IDirect3DVertexBuffer9 * m_VB;//��������

	IDirect3DIndexBuffer9 * m_IB;//��������

	IDirect3DDevice9 * m_pDevice;

};