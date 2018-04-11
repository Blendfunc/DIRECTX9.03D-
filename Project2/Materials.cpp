#include "Materials.h"
#define WRITEMATERIAL(a,b,c,d,e,f)\
D3DMATERIAL9 * dm9 = new D3DMATERIAL9;\
*f = dm9;\
::ZeroMemory(dm9, sizeof(*dm9));\
dm9->Diffuse = a; \
dm9->Ambient = b; \
dm9->Specular = c;\
dm9->Emissive = d;\
dm9->Power = e;\
m_Materials.push_back(dm9);\
/*dm9->Diffuse = a; \//ָ�����ʶ������ķ�����
dm9->Ambient = b; \//ָ�����ʶԻ�����ķ�����
dm9->Specular = c;\//ָ�����ʶԾ����ķ�����
dm9->Emissive = d;\//�÷���������ǿ��������ȣ�ʹ֮��������������Լ�����
dm9->Power = e;\//ָ������߹�����ȣ���ֵԽ�󣬸߹������Խ��*/

CMaterials::CMaterials()
{
}

CMaterials::~CMaterials()
{
	Clear();
}

BOOL CMaterials::GetMaterials(inparameter Material m, inparameter outparameter D3DMATERIAL9 ** material)
{
	if (nullptr == material) return FALSE;
	if (m == red)
	{
		WRITEMATERIAL(_COLOR_::RED, _COLOR_::RED, _COLOR_::RED, _COLOR_::BLACK, 2.0f, material);
		return TRUE;
	}
	if (m == white)
	{
		WRITEMATERIAL(_COLOR_::WHITE, _COLOR_::WHITE, _COLOR_::WHITE, _COLOR_::BLACK, 5.0f, material);
		return TRUE;
	}
	if (m == green)
	{
		WRITEMATERIAL(_COLOR_::GREEN, _COLOR_::GREEN, _COLOR_::GREEN, _COLOR_::BLACK, 2.0f, material);
		return TRUE;
	}
	if (m == blue)
	{
		WRITEMATERIAL(_COLOR_::BLUE, _COLOR_::BLUE, _COLOR_::BLUE, _COLOR_::BLACK, 2.0f, material);
		return TRUE;
	}
	if (m == yellow)
	{
		WRITEMATERIAL(_COLOR_::YELLOW, _COLOR_::YELLOW, _COLOR_::YELLOW, _COLOR_::BLACK, 2.0f, material);
		return TRUE;
	}
	return FALSE;
}

BOOL CMaterials::GetMaterials(inparameter D3DXCOLOR a, inparameter D3DXCOLOR d, inparameter D3DXCOLOR s, inparameter D3DXCOLOR e, inparameter float p, inparameter outparameter D3DMATERIAL9 ** material)
{
	if (nullptr == material)return FALSE;
	D3DMATERIAL9 * mtrl = new D3DMATERIAL9;
	*material = mtrl;
	mtrl->Ambient = a;
	mtrl->Diffuse = d;
	mtrl->Specular = s;
	mtrl->Emissive = e;
	mtrl->Power = p;
	return TRUE;
}

//BOOL Materials::GetMaterials(D3DXCOLOR a, D3DXCOLOR d, D3DXCOLOR s, D3DXCOLOR e, float p)
//{
//	return 0;
//}

void CMaterials::Clear()
{
}
