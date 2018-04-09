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
		dm9->Diffuse = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);//指定材质对漫射光的反射率
		dm9->Ambient = D3DXCOLOR(1.0F, 0.0f, 0.0f, 1.0f);//指定材质对环境光的反射率
		dm9->Specular = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);//指定材质对镜面光的反射率
		dm9->Emissive = D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f);//该分量用于增强物体的亮度，使之看起来好像可以自己发光
		dm9->Power = 5.0f;//指定镜面高光点的锐度，该值越大，高光点的锐度越大
		m_Materials.push_back(dm9);
		return TRUE;
	}
	return FALSE;
}

void Materials::Clear()
{
}
