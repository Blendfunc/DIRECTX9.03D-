#include "TextureDemo.h"

CTextureDemo::CTextureDemo()
{
	m_VB = nullptr;
	m_IB = nullptr;
	m_pDevice = nullptr;
}

CTextureDemo::~CTextureDemo()
{
}

void CTextureDemo::Init(IDirect3DDevice9 * pDevice)
{
	if (pDevice)
	{
		m_pDevice = pDevice;
		pDevice->CreateVertexBuffer(6 * sizeof(TextureStruct), D3DUSAGE_WRITEONLY, TextureStruct::FVF, D3DPOOL_MANAGED, &m_VB , 0);
		TextureStruct * pTS = nullptr;
		assert(m_VB);
		m_VB->Lock(0, 0, (void**)&pTS, 0);
		assert(pTS);
		pTS[0] = 
	}
}

void CTextureDemo::Display(float timeDelta)
{
}
