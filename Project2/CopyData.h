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
	BOOL InitD3DVertexData(int count , inparameter  void * pVertex , ...);//�������ֻ�������ֲ����������ֲ����᷵��ʧ��
	float SumSumSumSum(float count, ...);
};
