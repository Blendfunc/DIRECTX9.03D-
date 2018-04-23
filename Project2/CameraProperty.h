#pragma once
#include ".\DX/Include/d3dx9.h"

struct CCameraProperty
{
public:
	D3DXVECTOR3 static_right;
	D3DXVECTOR3 static_up;
	D3DXVECTOR3 static_look;
	D3DXVECTOR3 static_pos;
};