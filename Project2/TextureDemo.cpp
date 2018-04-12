#include "TextureDemo.h"

#define _InitD3DVertexData_(name1,name2,name3,_x,_y,f1,f2,f3,ccd) \
(name1).data = (void *)(name3); \
(ccd).InitD3DVertexData(8,(void*)(&(name1)),f1,f2,f3,(name2)->x,(name2)->y,(name2)->z,_x,_y); \
(name1).data = (void *)(++name3);


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
		/*pTS[0] = */
		CCopyData ccd;
		D3DXVECTOR3 v1(-1.0f, -1.0f, 1.25f);
		D3DXVECTOR3 v2(-1.0f, 1.0f, 1.25f);
		D3DXVECTOR3 v3(1.0f, 1.0f, 1.25f);
		D3DXVECTOR3 * pv = nullptr;
		CCalculateNormalVectorOfThePlane::ComputeNormal(&v1, &v2, &v3, &pv);
		assert(pv);
		vertextype vt;
		vt.type = texturedemo;
		vt.data = (void *)pTS;
		float sum = ccd.SumSumSumSum(8.0f,1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		_InitD3DVertexData_(vt, pv, pTS, 0.0f, 3.0f, -1.0f, -1.0f, 1.25f, ccd)
		_InitD3DVertexData_(vt, pv, pTS, 0.0f, 0.0f, -1.0f, 1.0f, 1.25f, ccd)
		_InitD3DVertexData_(vt, pv, pTS, 3.0f, 0.0f, 1.0f, 1.0f, 1.25f, ccd)
		_InitD3DVertexData_(vt, pv, pTS, 0.0f, 3.0f, -1.0f, -1.0f, 1.25f, ccd)
		_InitD3DVertexData_(vt, pv, pTS, 3.0f, 0.0f, 1.0f, 1.0f, 1.25f, ccd)
		_InitD3DVertexData_(vt, pv, pTS, 3.0f, 3.0f, 1.0f, -1.0f, 1.25f, ccd)
		m_VB->Unlock();
		IDirect3DTexture9 * idt = nullptr;
		D3DXCreateTextureFromFile(pDevice, "D:\\DIRECTX9.03D-.git\\trunk\\Project2\\Debug\\texture.bmp", &idt);
		assert(idt);
		pDevice->SetTexture(0, idt);
		pDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
		pDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
		pDevice->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_POINT);
		pDevice->SetRenderState(D3DRS_LIGHTING, false);
		D3DXMATRIX proj;
		D3DXMatrixPerspectiveFovLH(&proj, D3DX_PI * 0.5f, 800.0f / 600.0, 1.0f, 1000.0f);
		pDevice->SetTransform(D3DTS_PROJECTION, &proj);


		/*ccd.InitD3DVertexData(8, (void *)&vt, -1.0f, -1.0f, 1.25f, pv->x, pv->y, pv->z, 0.0f, 3.0f);
		vt.data = (void *)++pTS;
		ccd.InitD3DVertexData(8, (void *)&vt, -1.0f, 1.0f, 1.25f, pv->x, pv->y, pv->z, 0.0f, 0.0f);
		vt.data = (void*)++pTS;
		ccd.InitD3DVertexData(8, (void*)&vt, 1.0f, 1.0f, 1.25f, pv->x, pv->y, pv->z, 3.0f, 0.0f);*/
		/*vt.data = ()*/
	}
}

void CTextureDemo::Display(float timeDelta)
{
	if (m_pDevice)
	{
		m_pDevice->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0xffffffff, 1.0f, 0);
		m_pDevice->BeginScene();
		m_pDevice->SetStreamSource(0, m_VB, 0, sizeof(TextureStruct));
		m_pDevice->SetFVF(TextureStruct::FVF);
		m_pDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);
		m_pDevice->EndScene();
		m_pDevice->Present(0, 0, 0, 0);
	}
}


