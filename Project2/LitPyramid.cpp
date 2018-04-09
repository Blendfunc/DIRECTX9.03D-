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
		LitPyramidVertex * v = nullptr;
		m_VB->Lock(0, 0, (void**)&v, 0);
		
		//front face
		LitPyramidVertex lpv1, lpv2, lpv3;
		calc(lpv1, lpv2, lpv3, -1.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.f, 1.0f, 0.0f, -1.0f);
		v[0] = lpv1;
		v[1] = lpv2;
		v[2] = lpv3;
		//left face
		LitPyramidVertex lpv4, lpv5, lpv6;
		calc(lpv4, lpv5, lpv6, -1.0f , 0.0f , 1.0f , 0.0f , 1.0f , 0.0f , -1.0f , 0.0f , -1.0f);
		v[3] = lpv4;
		v[4] = lpv5;
		v[5] = lpv6;
		//right face
		LitPyramidVertex lpv7, lpv8, lpv9;
		calc(lpv7, lpv8, lpv9, 1.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f);
		v[6] = lpv7;
		v[7] = lpv8;
		v[8] = lpv9;
		//back face
		LitPyramidVertex lpv10, lpv11, lpv12;
		calc(lpv10, lpv11, lpv12, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, -1.0f, 0.0f, 1.0f);
		v[9] = lpv10;
		v[10] = lpv11;
		v[11] = lpv12;
		m_VB->Unlock();

		//材质
		D3DMATERIAL9 mtrl;
		Materials m;
		D3DMATERIAL9 * dm9 = nullptr;
		m.GetMaterials(red, &dm9);
		assert(dm9);
		pDevice->SetMaterial(dm9);

		//光源
		D3DLIGHT9 * light = nullptr;
		D3DXVECTOR3 direction(1.0f, 0.0f, 0.0f);
		D3DXCOLOR color = _COLOR_::WHITE;
		CLight::GetDirectionalLight2(&light, &direction, &color);
		assert(light);
		pDevice->SetLight(0, light);
		pDevice->LightEnable(0, true);
		pDevice->SetRenderState(D3DRS_NORMALIZENORMALS, true);//重新规范化法向量
		pDevice->SetRenderState(D3DRS_SPECULARENABLE , true);//启用镜面高光

															 //position and aim the camera.
		D3DXVECTOR3 position(0.0f, 0.0f, -10.0f);
		D3DXVECTOR3 target(0.0f, 0.0f, 0.0f);
		D3DXVECTOR3 up(0.0f, 1.0f, 0.0f);
		D3DXMATRIX V;
		D3DXMatrixLookAtLH(&V, &position, &target, &up);//取景变换矩阵（即观察矩阵）
		pDevice->SetTransform(D3DTS_VIEW, &V);

		//Set the projection matrix.
		D3DXMATRIX proj;
		float Aspect = 800.0f / 600.0f;
		D3DXMatrixPerspectiveFovLH(&proj, D3DX_PI * 0.5f, Aspect, 1.0f, 1000.0f);//依据视域体的描述信息创建一个投影矩阵
		pDevice->SetTransform(D3DTS_PROJECTION, &proj);
		pDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
	}
}

void CLitPyramid::Display(float timeDelta)
{
	if (m_pDevice && m_VB)
	{
		D3DXMATRIX Rx, Ry;
		D3DXMatrixRotationX(&Rx, 3.14f / 4.0f);
		static float y = 0.0f;
		D3DXMatrixRotationY(&Ry, y);
		y += timeDelta;
		if (y >= 6.28f)
		{
			y = 0.0f;
		}
		D3DXMATRIX p = Rx * Ry;
		m_pDevice->SetTransform(D3DTS_WORLD, &p);

		m_pDevice->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0xffffffff, 1.0f, 0);
		m_pDevice->BeginScene();
		m_pDevice->SetStreamSource(0, m_VB, 0, sizeof(LitPyramidVertex));
		/*m_pDevice->SetIndices(m_IB);*/
		m_pDevice->SetFVF(D3DFVF_XYZ);
		m_pDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 4);
		m_pDevice->EndScene();
		m_pDevice->Present(0, 0, 0, 0);
	}
}

void CLitPyramid::calc(LitPyramidVertex & lpv1, LitPyramidVertex & lpv2, LitPyramidVertex & lpv3, float f1, float f2, float f3, float _f1, float _f2, float _f3, float __f1, float __f2, float __f3)
{
	D3DXVECTOR3 d3dvec1(f1, f2, f3);//三角形的一个顶点
	D3DXVECTOR3 d3dvec2(_f1, _f2, _f3);//三角形的一个顶点
	D3DXVECTOR3 d3dvec3(__f1, __f2, __f3);//三角形的一个顶点
	D3DXVECTOR3 * result = nullptr;//三角形所在面的法向量
	CCalculateNormalVectorOfThePlane::ComputeNormal(&d3dvec1, &d3dvec2, &d3dvec3, &result);
	assert(result);
	/*LitPyramidVertex lpv1, lpv2, lpv3;*/
	InitializeLitPyramidVertex(&lpv1, &d3dvec1, result);
	InitializeLitPyramidVertex(&lpv2, &d3dvec2, result);
	InitializeLitPyramidVertex(&lpv3, &d3dvec3, result);
}

void InitializeLitPyramidVertex(inparameter outparameter LitPyramidVertex * p, D3DXVECTOR3 * point, D3DXVECTOR3 * normal)
{
	if (p && point && normal)
	{
		p->x = point->x;
		p->y = point->y;
		p->z = point->z;
		p->_nx = normal->x;
		p->_ny = normal->y;
		p->_nz = normal->z;
	}
}
