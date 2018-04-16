#include "CubeEx.h"
#include "Common.h"
#include "CalculateNormalVectorOfThePlane.h"

CCubeEx::CCubeEx()
{
	m_pDevice = nullptr;
	m_VB = nullptr;
	m_IB = nullptr;
	m_Mesh = nullptr;
	m_pTexture3[0] = nullptr;
	m_pTexture3[1] = nullptr;
	m_pTexture3[2] = nullptr;
	_tcscpy(m_Texture1, "D:\\DIRECTX9.03D-.git\\trunk\\Project2\\Debug\\63.jpg");
	_tcscpy(m_Texture2, "D:\\DIRECTX9.03D-.git\\trunk\\Project2\\Debug\\62.jpg");
	_tcscpy(m_Texture3, "D:\\DIRECTX9.03D-.git\\trunk\\Project2\\Debug\\66.jpg");
}

CCubeEx::~CCubeEx()
{
}

void CCubeEx::Init(IDirect3DDevice9 * pDevice)
{
	if (pDevice)
	{
		m_pDevice = pDevice;
		ID3DXMesh * mesh = nullptr;
		D3DXCreateMeshFVF(12, 24, D3DXMESH_MANAGED, CubeExStruct::FVF, pDevice, &mesh);
		assert(mesh);
		m_Mesh = mesh;
		CubeExStruct * pces = nullptr;
		mesh->LockVertexBuffer(0, (void**)&pces);
		assert(pces);
		pces[0] = CubeExStruct(-1.0f, -1.0f, -1.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f);
		pces[1] = CubeExStruct(-1.0f, 1.0f, -1.0f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f);
		pces[2] = CubeExStruct(1.0f, 1.0f, -1.0f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f);
		pces[3] = CubeExStruct(1.0f, -1.0f, -1.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f);
		pces[4] = CubeExStruct(-1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
		pces[5] = CubeExStruct(1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f);
		pces[6] = CubeExStruct(1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);
		pces[7] = CubeExStruct(-1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f);
		pces[8] = CubeExStruct(-1.0f, 1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f);
		pces[9] = CubeExStruct(-1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f);
		pces[10] = CubeExStruct(1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f);
		pces[11] = CubeExStruct(1.0f, 1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f);
		pces[12] = CubeExStruct(-1.0f, -1.0f, -1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f);
		pces[13] = CubeExStruct(1.0f, -1.0f, -1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f);
		pces[14] = CubeExStruct(1.0f, -1.0f, 1.0f, 0.0f, -1.0f, 0.0f, 1.0f, 1.0f);
		pces[15] = CubeExStruct(-1.0f, -1.0f, 1.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f);
		pces[16] = CubeExStruct(-1.0f, -1.0f, 1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
		pces[17] = CubeExStruct(-1.0f, 1.0f, 1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
		pces[18] = CubeExStruct(-1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f);
		pces[19] = CubeExStruct(-1.0f, -1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f);
		pces[20] = CubeExStruct(1.0f, -1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
		pces[21] = CubeExStruct(1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
		pces[22] = CubeExStruct(1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f);
		pces[23] = CubeExStruct(1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f);
		mesh->UnlockVertexBuffer();
		WORD * pword = nullptr;
		mesh->LockIndexBuffer(0, (void **)&pword);
		/*0*/
		pword[0] = 0; pword[1] = 1; pword[2] = 2;
		pword[3] = 0; pword[4] = 2; pword[5] = 3;
		pword[6] = 4; pword[7] = 5; pword[8] = 6;
		pword[9] = 4; pword[10] = 6; pword[11] = 7;
		/*1*/
		pword[12] = 8; pword[13] = 9; pword[14] = 10;
		pword[15] = 8; pword[16] = 10; pword[17] = 11;
		pword[18] = 12; pword[19] = 13; pword[20] = 14;
		pword[21] = 12; pword[22] = 14; pword[23] = 15;
		/*2*/
		pword[24] = 16; pword[25] = 17; pword[26] = 18;
		pword[27] = 16; pword[28] = 18; pword[29] = 19;
		pword[30] = 20; pword[31] = 21; pword[32] = 22;
		pword[33] = 20; pword[34] = 22; pword[35] = 23;

		mesh->UnlockIndexBuffer();
		DWORD * _pword = nullptr;
		mesh->LockAttributeBuffer(0, &_pword);
		for (int a = 0; a < 4; a++)
		{
			_pword[a] = 0;
		}
		for (int b = 4; b < 8; b++)
		{
			_pword[b] = 1;
		}
		for (int c = 8; c < 12; c++)
		{
			_pword[c] = 2;
		}
		mesh->UnlockAttributeBuffer();
		std::vector<DWORD> ab(mesh->GetNumFaces() * 3);
		mesh->GenerateAdjacency(0.0f, &ab[0]);
		mesh->OptimizeInplace(D3DXMESHOPT_ATTRSORT | D3DXMESHOPT_COMPACT | D3DXMESHOPT_VERTEXCACHE, &ab[0], 0, 0, 0);
		D3DXCreateTextureFromFile(pDevice, m_Texture1, &(m_pTexture3[0]));
		D3DXCreateTextureFromFile(pDevice, m_Texture2, &(m_pTexture3[1]));
		D3DXCreateTextureFromFile(pDevice, m_Texture3, &(m_pTexture3[2]));
		pDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
		pDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
		pDevice->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_POINT);
		// 
		// Disable lighting.
		//

		pDevice->SetRenderState(D3DRS_LIGHTING, true);

		//����
		D3DMATERIAL9 mtrl;
		CMaterials m;
		D3DMATERIAL9 * dm9 = nullptr;
		m.GetMaterials(white, &dm9);
		assert(dm9);
		pDevice->SetMaterial(dm9);
		//��Դ
		D3DLIGHT9 * light = nullptr;
		D3DXVECTOR3 direction(1.0f, 0.0f, 0.0f);
		D3DXCOLOR color = _COLOR_::WHITE;
		CLight::GetDirectionalLight2(&light, &direction, &color);
		assert(light);
		pDevice->SetLight(0, light);
		pDevice->LightEnable(0, true);
		pDevice->SetRenderState(D3DRS_NORMALIZENORMALS, true);//���¹淶��������
		pDevice->SetRenderState(D3DRS_SPECULARENABLE, true);//���þ���߹�
		//
		// Set camera.
		//

		D3DXVECTOR3 pos(0.0f, 0.f, -4.0f);
		D3DXVECTOR3 target(0.0f, 0.0f, 0.0f);
		D3DXVECTOR3 up(0.0f, 1.0f, 0.0f);

		D3DXMATRIX V;
		D3DXMatrixLookAtLH(
			&V,
			&pos,
			&target,
			&up);

		pDevice->SetTransform(D3DTS_VIEW, &V);

		//
		// Set projection matrix.
		//

		D3DXMATRIX proj;
		D3DXMatrixPerspectiveFovLH(
			&proj,
			D3DX_PI * 0.5f, // 90 - degree
			(float)800.0 / (float)600.0,
			1.0f,
			1000.0f);
		pDevice->SetTransform(D3DTS_PROJECTION, &proj);
	}
}

void CCubeEx::Display(float timeDelta)
{
	if (m_pDevice && m_Mesh && m_pTexture3[0] && m_pTexture3[1] && m_pTexture3[2])
	{
		//
		// Update: Rotate the cube.
		//

		D3DXMATRIX xRot;
		D3DXMatrixRotationX(&xRot, D3DX_PI * 0.2f);

		static float y = 0.0f;
		D3DXMATRIX yRot;
		D3DXMatrixRotationY(&yRot, y);
		y += timeDelta;

		if (y >= 6.28f)
			y = 0.0f;

		D3DXMATRIX World = xRot * yRot;

		m_pDevice->SetTransform(D3DTS_WORLD, &World);

		//
		// Render
		//

		m_pDevice->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0x00000000, 1.0f, 0);
		m_pDevice->BeginScene();

		for (int i = 0; i < 3; i++)
		{
			m_pDevice->SetTexture(0, m_pTexture3[i]);
			m_Mesh->DrawSubset(i);
		}

		m_pDevice->EndScene();
		m_pDevice->Present(0, 0, 0, 0);
	}
}