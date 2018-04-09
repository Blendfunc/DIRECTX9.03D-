#pragma once
#include ".\DX\Include\d3dx9.h"
#include "Common.h"
#include <vector>
enum Material
{
	red = 0 ,

};
class Materials
{
public:
	Materials();
	~Materials();
	BOOL GetMaterials(inparameter Material m , inparameter outparameter D3DMATERIAL9 ** material);
protected:
	void Clear();
private:
	std::vector<D3DMATERIAL9 *> m_Materials;


};