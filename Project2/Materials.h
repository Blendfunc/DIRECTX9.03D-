#pragma once
#include ".\DX\Include\d3dx9.h"
#include "Common.h"
#include <vector>
#include "Color.h"
enum Material
{
	red = 0 ,
	white = 1 ,
	green = 2 ,
	blue = 3 ,
	yellow = 4
};
class CMaterials
{
public:
	CMaterials();
	~CMaterials();
	BOOL GetMaterials(inparameter Material m , inparameter outparameter D3DMATERIAL9 ** material);
	BOOL GetMaterials(inparameter D3DXCOLOR a, inparameter D3DXCOLOR d, inparameter D3DXCOLOR s, inparameter D3DXCOLOR e, inparameter float p , inparameter outparameter D3DMATERIAL9 ** material);
protected:
	void Clear();
private:
	std::vector<D3DMATERIAL9 *> m_Materials;


};