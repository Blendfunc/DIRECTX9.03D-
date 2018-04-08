#include "LitPyramid.h"

CLitPyramid::CLitPyramid()
{
	m_VB = nullptr;
	m_IB = nullptr;
	m_pDevice = nullptr;
}

CLitPyramid::~CLitPyramid()
{
}

void CLitPyramid::Init(inparameter IDirect3DDevice9 * pDevice)
{
	if (pDevice)
	{
		m_pDevice = pDevice;
		pDevice->SetRenderState(D3DRS_LIGHTING, true);
		pDevice->CreateVertexBuffer(12 * sizeof(LitPyramidVertex), D3DUSAGE_WRITEONLY, LitPyramidVertex::FVF, D3DPOOL_MANAGED, &m_VB, 0);
		LitPyramidVertex * v;
		m_VB->Lock(0 , 0 , )




	}


}
