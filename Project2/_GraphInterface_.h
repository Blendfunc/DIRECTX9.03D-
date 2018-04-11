#pragma once
#include "Common.h"
#include ".\DX\Include\d3dx9.h"

_BEGIN_INTERFACE_(_CGraphInterface_)
_USE_PUBLIC_
_FUNCTION_NAME_(Init, void, IDirect3DDevice9 * pDevice)
_FUNCTION_NAME_(Display, void, float timeDelta)
_USE_PROTECTED_
_VARIABLE_NAME_(m_VB, IDirect3DVertexBuffer9 *)
_VARIABLE_NAME_(m_IB, IDirect3DIndexBuffer9 *)
_VARIABLE_NAME_(m_pDevice, IDirect3DDevice9 *)
_END_INTERFACE_