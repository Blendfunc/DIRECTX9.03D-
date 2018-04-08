#pragma once
#include ".\DX\Include\d3dx9.h"
#include "Common.h"
#include "assert.h"
#include <vector>
class CLight
{
public:
	static D3DLIGHT9 * GetDirectionalLight(D3DXVECTOR3 * direction , D3DXCOLOR * color);//方向光
	static BOOL GetDirectionalLight2(inoutparameter D3DLIGHT9 ** lightout, inparameter D3DXVECTOR3 * direction, D3DCOLOR * color);//方向光

	static D3DLIGHT9 * GetPointLight(D3DXVECTOR3 * position, D3DXCOLOR * color);//点光源
	static BOOL GetPointLight2(inoutparameter D3DLIGHT9 ** lightout, inparameter D3DXVECTOR3 * position, D3DCOLOR * color);//点光源
	
	static D3DLIGHT9 * GetSpotLight(D3DXVECTOR3 * direction, D3DXCOLOR * color);//聚光灯
	static BOOL GetSpotLight2(inoutparameter D3DLIGHT9 ** lightout, inparameter D3DXVECTOR3 * position , inparameter D3DXVECTOR3 * direction,  D3DCOLOR * color);//聚光灯
	
	static void Clear();//清空内存
private:
	static std::vector<D3DLIGHT9 *> m_Lights;
};
