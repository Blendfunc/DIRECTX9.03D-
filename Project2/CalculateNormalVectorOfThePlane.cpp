#include "CalculateNormalVectorOfThePlane.h"

BOOL CCalculateNormalVectorOfThePlane::ComputeNormal(inparameter D3DXVECTOR3 * p0, inparameter D3DXVECTOR3 * p1, inparameter D3DXVECTOR3 * p2, inoutparameter D3DXVECTOR3 ** pout)
{
	if (p0 && p1 && p2 && pout)
	{
		D3DXVECTOR3 u = *p1 - *p0;
		D3DXVECTOR3 v = *p2 - *p0;
		*pout = nullptr;
		D3DXVec3Cross(*pout, &u, &v);
		assert(*pout);
		D3DXVec3Normalize(*pout, *pout);
		return TRUE;
	}
	return FALSE;
}
