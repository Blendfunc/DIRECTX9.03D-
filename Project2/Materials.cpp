#include "Materials.h"

Materials::Materials()
{
}

Materials::~Materials()
{
	Clear();
}

BOOL Materials::GetMaterials(inparameter Material m, inparameter outparameter D3DMATERIAL9 ** material)
{
	if (nullptr == material) return FALSE;
	if (m == red)
	{
		D3DMATERIAL9 * dm9 = new D3DMATERIAL9;
		*material = dm9;
		::ZeroMemory(dm9, sizeof(*dm9));
		dm9->Diffuse = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);//ָ�����ʶ������ķ�����
		dm9->Ambient = D3DXCOLOR(1.0F, 0.0f, 0.0f, 1.0f);//ָ�����ʶԻ�����ķ�����
		dm9->Specular = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);//ָ�����ʶԾ����ķ�����
		dm9->Emissive = D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f);//�÷���������ǿ��������ȣ�ʹ֮��������������Լ�����
		dm9->Power = 5.0f;//ָ������߹�����ȣ���ֵԽ�󣬸߹������Խ��
		m_Materials.push_back(dm9);
		return TRUE;
	}
	return FALSE;
}

void Materials::Clear()
{
}
