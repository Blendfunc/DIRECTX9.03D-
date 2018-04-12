#pragma once
#include ".\DX\Include\d3dx9.h"
#include "Common.h"
#include <memory>
#include <string>
#include <vector>

class CCopyData
{
public:
	CCopyData();
	~CCopyData();
public:
	BOOL InitD3DVertexData(int count , inparameter  void * pVertex , ...);//这个方法只接受数字参数，非数字参数会返回失败
	float SumSumSumSum(float count, ...);
};
