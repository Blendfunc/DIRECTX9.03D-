#pragma once
#include ".\DX\Include\d3dx9.h"
#include "Common.h"
#include "assert.h"
class CCalculateNormalVectorOfThePlane
{
public:
	static BOOL ComputeNormal(inparameter D3DXVECTOR3 * p0 , inparameter D3DXVECTOR3 * p1 , inparameter D3DXVECTOR3 * p2 , inoutparameter D3DXVECTOR3 ** pout);//����һ�����������㹹�ɵ�������������ķ�����
};