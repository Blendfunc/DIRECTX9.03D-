#pragma once
#include".\DX\Include\d3dx9.h"
#include"assert.h"
#include"Common.h"
//�ó��������һ����ת���߿�������
//��Ա�������»���Ϊǰ׺


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