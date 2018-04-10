#include "Light.h"

CLight::CLight()
{
}

CLight::~CLight()
{
	Clear();
}

D3DLIGHT9 * CLight::GetDirectionalLight(D3DXVECTOR3 * direction, D3DXCOLOR * color)
{
	D3DLIGHT9 * plight = new D3DLIGHT9;
	assert(plight);
	assert(direction);
	assert(color);
	::ZeroMemory(plight, sizeof(*plight));
	plight->Type = D3DLIGHT_DIRECTIONAL;
	plight->Ambient = (*color) * 0.4f;
	plight->Diffuse = *color;
	plight->Specular = (*color) * 0.6f;
	plight->Direction = *direction;
	m_Lights.push_back(plight);
	return plight;
}

BOOL CLight::GetDirectionalLight2(inoutparameter D3DLIGHT9 ** lightout, inparameter D3DXVECTOR3 * direction, D3DXCOLOR * color)
{
	if (lightout && direction && color)
	{
		D3DLIGHT9 * plight = new D3DLIGHT9;
		if (plight)
		{
			*lightout = plight;
			::ZeroMemory(plight , sizeof(plight));
			plight->Type = D3DLIGHT_DIRECTIONAL;
			plight->Ambient = (*color) * 0.6f;
			plight->Diffuse = *color;
			plight->Specular = (*color) * 0.3f;
			plight->Direction = *direction;
			/*m_Lights.push_back(plight);*//*这里为什么注释掉*/
			return TRUE;
		}
	}
	return FALSE;
}

D3DLIGHT9 * CLight::GetPointLight(D3DXVECTOR3 * position, D3DXCOLOR * color)
{
	return nullptr;
}

BOOL CLight::GetPointLight2(inoutparameter D3DLIGHT9 ** lightout, inparameter D3DXVECTOR3 * position, D3DXCOLOR * color)
{
	return 0;
}

D3DLIGHT9 * CLight::GetSpotLight(D3DXVECTOR3 * direction, D3DXCOLOR * color)
{
	return nullptr;
}

BOOL CLight::GetSpotLight2(inoutparameter D3DLIGHT9 ** lightout, inparameter D3DXVECTOR3 * position, inparameter D3DXVECTOR3 * direction, D3DXCOLOR * color)
{
	return 0;
}

void CLight::Clear()
{
	for (auto iter = m_Lights.begin(); iter != m_Lights.end(); iter++)
	{
		if (*iter)
		{
			delete (*iter);
			*iter = nullptr;
		}
	}
	m_Lights.clear();
}
