#include"Cube.h"

CTheRevolvingBoxCube::CTheRevolvingBoxCube()
{
	m_VB = 0;
	m_IB = 0;
	m_pDevice = 0;
}

CTheRevolvingBoxCube::~CTheRevolvingBoxCube()
{
}

void CTheRevolvingBoxCube::Init(IDirect3DDevice9 * pDevice)
{
	if (pDevice)
	{
		m_pDevice = pDevice;
		m_VB = 0;
		pDevice->CreateVertexBuffer(8 * sizeof(VERTEXCUBE), D3DUSAGE_WRITEONLY, VERTEXCUBE::FVF, D3DPOOL_MANAGED, &m_VB, 0);
		pDevice->CreateIndexBuffer(36 * sizeof(WORD), D3DUSAGE_WRITEONLY, D3DFMT_INDEX16, D3DPOOL_MANAGED, &m_IB, 0);
		//Fill the buffers with the cube data.
		VERTEXCUBE * buffer = 0;
		assert(m_VB);
		assert(m_IB);
		if (m_VB && m_IB)
		{
			m_VB->Lock(0, 0, (void **)&buffer, 0);
			//vertices of a unit cube
			assert(buffer);
			if (buffer)
			{
				buffer[0] = VERTEXCUBE(-1.0f, -1.0f, -1.0f);
				buffer[1] = VERTEXCUBE(-1.0f, 1.0f, -1.0f);
				buffer[2] = VERTEXCUBE(1.0f, 1.0f, -1.0f);
				buffer[3] = VERTEXCUBE(1.0f, -1.0f, -1.0f);
				buffer[4] = VERTEXCUBE(-1.0f, -1.0f, 1.0f);
				buffer[5] = VERTEXCUBE(-1.0f, 1.0f, 1.0f);
				buffer[6] = VERTEXCUBE(1.0f, 1.0f, 1.0f);
				buffer[7] = VERTEXCUBE(1.0f, -1.0f, 1.0f);
			}
			m_VB->Unlock();
			//define the triangles of the cube:
			WORD * pWORD = 0;
			m_IB->Lock(0, 0, (void **)&pWORD , 0);

			if (pWORD)
			{
				//front side
				pWORD[0] = 0; pWORD[1] = 1; pWORD[2] = 2;
				pWORD[3] = 0; pWORD[4] = 2; pWORD[5] = 3;

				//back side
				pWORD[6] = 4; pWORD[7] = 6; pWORD[8] = 5;
				pWORD[9] = 4; pWORD[10] = 7; pWORD[11] = 6;

				//left side
				pWORD[12] = 4; pWORD[13] = 5; pWORD[14] = 1;
				pWORD[15] = 4; pWORD[16] = 1; pWORD[17] = 0;

				//right side
				pWORD[18] = 3; pWORD[19] = 2; pWORD[20] = 6;
				pWORD[21] = 3; pWORD[22] = 6; pWORD[23] = 7;

				//top
				pWORD[24] = 1; pWORD[25] = 5; pWORD[26] = 6;
				pWORD[27] = 1; pWORD[28] = 6; pWORD[29] = 2;

				//bottom
				pWORD[30] = 4; pWORD[31] = 0; pWORD[32] = 3;
				pWORD[33] = 4; pWORD[34] = 3; pWORD[35] = 7;
			}
			m_IB->Unlock();

			//position and aim the camera.
			D3DXVECTOR3 position(0.0f, 0.0f, -10.0f);
			D3DXVECTOR3 target(0.0f, 0.0f, 0.0f);
			D3DXVECTOR3 up(0.0f, -1.0f, 0.0f);
			D3DXMATRIX V;
			D3DXMatrixLookAtLH(&V, &position, &target, &up);//取景变换矩阵（即观察矩阵）
			pDevice->SetTransform(D3DTS_VIEW, &V);

			//Set the projection matrix.
			D3DXMATRIX proj;
			float Aspect = 800.0f / 600.0f;
			D3DXMatrixPerspectiveFovLH(&proj, D3DX_PI * 0.5f, Aspect, 1.0f, 1000.0f);//依据视域体的描述信息创建一个投影矩阵
			pDevice->SetTransform(D3DTS_PROJECTION, &proj);

			//Switch to wireframe mode.
			pDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);

		}
		//
	}
}

void CTheRevolvingBoxCube::Display(float timeDelta)
{
	if (m_pDevice && m_VB && m_IB)
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
		m_pDevice->SetStreamSource(0, m_VB, 0, sizeof(VERTEXCUBE));
		m_pDevice->SetIndices(m_IB);
		m_pDevice->SetFVF(VERTEXCUBE::FVF);
		m_pDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 8, 0, 12);
		m_pDevice->EndScene();
		m_pDevice->Present(0, 0, 0, 0);
	}
}
