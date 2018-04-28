#include "Terrain.h"
#include "HeightMap.h"
#include "Common.h"

#define PROC(a) \
float angle = /*(D3DX_PI / 18.0f) + */timeDelta; \
D3DXMATRIX * pm = nullptr; \
D3DXVECTOR3 pos(m_CameraPrpperty.static_pos.x , m_CameraPrpperty.static_pos.y , m_CameraPrpperty.static_pos.z); \
D3DXVECTOR3 look(m_CameraPrpperty.static_look.x, m_CameraPrpperty.static_look.y, m_CameraPrpperty.static_look.z); \
D3DXVECTOR3 up(m_CameraPrpperty.static_up.x, m_CameraPrpperty.static_up.y, m_CameraPrpperty.static_up.z); \
D3DXVECTOR3 right(m_CameraPrpperty.static_right.x, m_CameraPrpperty.static_right.y, m_CameraPrpperty.static_right.z); \
a; \
assert(pm); \
D3DXMATRIX World(*pm); \
delete pm; \
m_pDevice->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0xffffffff, 1.0f, 0); \
m_pDevice->BeginScene(); \
m_pDevice->SetTransform(D3DTS_VIEW, &World); \
m_pDevice->SetStreamSource(0, m_VB, 0, sizeof(TerrainStruct)); \
m_pDevice->SetFVF(TerrainStruct::FVF); \
m_pDevice->SetIndices(m_IB); \
m_pDevice->SetTexture(0 , m_pTexture); \
m_pDevice->SetRenderState(D3DRS_LIGHTING , false); \
m_pDevice->DrawIndexedPrimitive( \
D3DPT_TRIANGLELIST, \
0, \
0, \
staticheight * staticwidth, \
0, \
(staticheight - 1) * (staticwidth - 1) * 2); \
m_pDevice->EndScene(); \
Sleep(1); \
m_pDevice->Present(0, 0, 0, 0);


Terrain::Terrain()
{
	m_VB = nullptr;
	m_IB = nullptr;
	m_pDevice = nullptr;
	D3DXVECTOR3 pos(554.0f, 0.0f, -708.0f);
	D3DXVECTOR3 look(0.0f, 0.0f, 1.0f);
	D3DXVECTOR3 up(0.0f, 1.0f, 0.0f);
	D3DXVECTOR3 right(-1.0f, 0.0f, 0.0f);
	CCamera::InitCamera(&m_CameraPrpperty);
	m_CameraPrpperty.static_pos.x = pos.x; m_CameraPrpperty.static_pos.y = pos.y; m_CameraPrpperty.static_pos.z = pos.z;
	m_CameraPrpperty.static_look.x = look.x; m_CameraPrpperty.static_look.z = look.z; m_CameraPrpperty.static_look.y = look.y;
	m_CameraPrpperty.static_right.x = right.x; m_CameraPrpperty.static_right.y = right.y; m_CameraPrpperty.static_right.z = right.z;
	m_CameraPrpperty.static_up.x = up.x; m_CameraPrpperty.static_up.y = up.y; m_CameraPrpperty.static_up.z = up.z;
	m_pTexture = nullptr;
}

Terrain::~Terrain()
{
	
}

void Terrain::Init(IDirect3DDevice9 * pDevice)
{
	if(pDevice)
	{
		/*CHeightMap hm;
		CHeightMapDataManager * hmdm = nullptr;
		int height = 0;
		int width = 0;
		hm.GetHeightMapFromFile("D:\\DIRECTX9.03D-.git\\trunk\\Project2\\heightmap.bmp", &hmdm, &height, &width);*/
		SetTheUpperLeftCornerCoordinates(0.0f, 0.0f, 1.5f, 1.5f, 1.0f);
		m_pDevice = pDevice;
		/*assert(hmdm);*/
		int pointsX = staticwidth + 1 - 1;
		int pointY = staticheight + 1 - 1;

		IDirect3DVertexBuffer9 * pVertex = nullptr;		
		pDevice->CreateVertexBuffer(pointsX * pointY * sizeof(TerrainStruct) , D3DUSAGE_WRITEONLY , TerrainStruct::FVF , D3DPOOL_MANAGED , &pVertex , 0);
		m_VB = pVertex;
		assert(pVertex);
		
		TerrainStruct * pTerrainStruct = nullptr;
		//顶点
		pVertex->Lock(0, 0, (void **)&pTerrainStruct, 0);
		for(int i = 0 ; i < pointsX * pointY ; i++)
		{
			int _x = i % staticwidth;
			int _y = (i - _x) / staticwidth;
			TerrainStruct * pData = (TerrainStruct *)m_TerrainData.GetDataInfo(_x, _y);
			pTerrainStruct[i] = *pData;
		}
		pVertex->Unlock();
		//索引
		/*B			C


		A			D*/
		/*三角形BCA   三角形ACD*/
		int numCellsPerRow = staticwidth - 1;
		int numCellsPerCol = staticheight - 1;
		IDirect3DIndexBuffer9 * pIndex = nullptr;
		pDevice->CreateIndexBuffer(numCellsPerRow * numCellsPerCol * 2 * 3 * sizeof(WORD), D3DUSAGE_WRITEONLY, D3DFMT_INDEX16, D3DPOOL_MANAGED, &pIndex, 0);
		m_IB = pIndex;
		assert(pIndex);
		WORD * indices = nullptr;
		pIndex->Lock(0, 0, (void **)&indices, 0);
		for(int i = 0 ;i < numCellsPerRow * numCellsPerCol ; i++)
		{
			int index = i * 2 * 3;
			int _i = i % numCellsPerRow;
			int _n = (i - _i) / numCellsPerRow;

			WORD B = (_n * (numCellsPerRow + 1)) + _i;
			WORD C = B + 1;
			WORD A = B + numCellsPerRow + 1;
			WORD D = A + 1;
			indices[index] = B;
			indices[index + 1] = C;
			indices[index + 2] = A;
			indices[index + 3] = A;
			indices[index + 4] = C;
			indices[index + 5] = D;
		}
		pIndex->Unlock();
		IDirect3DTexture9 * idt = nullptr;
		D3DXCreateTextureFromFile(pDevice, "D:\\DIRECTX9.03D-.git\\trunk\\Project2\\Debug\\texture.bmp", &idt);
		assert(idt);
		m_pTexture = idt;
		pDevice->SetTexture(0, idt);
		pDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
		pDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
		pDevice->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);
		
		
		
		
		

		D3DXVECTOR3 pos(0.0f, 0.f, -4.0f);
		D3DXVECTOR3 target(0.0f, 0.0f, 1.0f);
		D3DXVECTOR3 up(0.0f, 1.0f, 0.0f);
		D3DXVECTOR3 right(-1.0f, 0.0f, 0.0f);

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
			D3DX_PI * 0.25f, // 90 - degree
			(float)800.0 / (float)600.0,
			1.0f,
			1000.0f);
		pDevice->SetTransform(D3DTS_PROJECTION, &proj);
	}
}

void Terrain::Display(float timeDelta)
{
	if(m_pDevice && m_VB && m_IB && m_pTexture)
	{
		/*m_pDevice->SetTransform(D3DTS_WORLD, world);*/
		/*m_pDevice->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0x00000000, 1.0f, 0);
		m_pDevice->BeginScene();*/



		/*m_pDevice->SetTexture(0, _tex);*/

		// turn off lighting since we're lighting it ourselves
		/*m_pDevice->SetRenderState(D3DRS_LIGHTING, false);*/

		

		/*m_pDevice->SetRenderState(D3DRS_LIGHTING, true);*/

		/*m_pDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);*/

		//m_pDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
		/*m_pDevice->EndScene();*/
		/*m_pDevice->Present(0, 0, 0, 0);*/
		if (::GetAsyncKeyState('W'))
		{
			//后退
			PROC(CCamera::GetWalkMatrix(&pm, &angle, &right, &up, &look, &pos));
		}
		if (::GetAsyncKeyState('S'))
		{
			//前进
			timeDelta = -timeDelta;
			PROC(CCamera::GetWalkMatrix(&pm, &angle, &right, &up, &look, &pos));
		}
		if (::GetAsyncKeyState('A'))
		{
			//左移
			PROC(CCamera::GetLeftOrRightMoveMatrix(&pm, &angle, &right, &up, &look, &pos));
		}
		if (::GetAsyncKeyState('D'))
		{
			//右移
			timeDelta = -timeDelta;
			PROC(CCamera::GetLeftOrRightMoveMatrix(&pm, &angle, &right, &up, &look, &pos));
		}
		if (::GetAsyncKeyState('Q'))
		{
			//上升
			PROC(CCamera::GetUpOrDownMoveMatrix(&pm, &angle, &right, &up, &look, &pos));
		}
		if (::GetAsyncKeyState('E'))
		{
			//下降
			timeDelta = -timeDelta;
			PROC(CCamera::GetUpOrDownMoveMatrix(&pm, &angle, &right, &up, &look, &pos));
		}
		if (::GetAsyncKeyState('I'))
		{
			//仰头
			timeDelta = timeDelta * 0.01;
			PROC(CCamera::GetBobbingUpAndDownMatrix(&pm, &angle, &right, &up, &look, &pos));
		}
		if (::GetAsyncKeyState('K'))
		{
			//低头
			timeDelta = -timeDelta * 0.01;
			PROC(CCamera::GetBobbingUpAndDownMatrix(&pm, &angle, &right, &up, &look, &pos));
		}
		if (::GetAsyncKeyState('J'))
		{
			//左偏
			timeDelta = timeDelta * 0.01;
			PROC(CCamera::GetBobbingLeftAndRightMatrix(&pm, &angle, &right, &up, &look, &pos));
		}
		if (::GetAsyncKeyState('L'))
		{
			//右偏
			timeDelta = -timeDelta * 0.01;
			PROC(CCamera::GetBobbingLeftAndRightMatrix(&pm, &angle, &right, &up, &look, &pos));
		}
		if (::GetAsyncKeyState('U'))
		{
			//左翻
			timeDelta = timeDelta * 0.01;
			PROC(CCamera::GetRotateMatrix(&pm, &angle, &right, &up, &look, &pos));
		}
		if (::GetAsyncKeyState('O'))
		{
			//右翻
			timeDelta = -timeDelta * 0.01;
			PROC(CCamera::GetRotateMatrix(&pm, &angle, &right, &up, &look, &pos));
		}
	}



}

void Terrain::SetTheUpperLeftCornerCoordinates(float x, float y, float stepX , float stepY , float heightFactor)
{
	CHeightMap hm;
	CHeightMapDataManager * hmdm = nullptr;
	int height = 0;
	int width = 0;
	hm.GetHeightMapFromFile("D:\\DIRECTX9.03D-.git\\trunk\\Project2\\heightmap.bmp", &hmdm, &height, &width);
	assert(hmdm);
	m_TerrainData.SetInfo(width, height);
	int numCellsPerRow = width - 1;
	int numCellsPerCol = height - 1;
	staticheight = height;
	staticwidth = width;
	for(int i = 0 ; i < height * width ; i++)
	{
		TerrainStruct * data = new TerrainStruct;
		int _x = i % width;
		int _y = (i - _x) / width;
		m_TerrainData.SetDataInfo(_x, _y, (void *)data);
		float realityX = _x * stepX;
		float realityY = _y * stepY;
		data->_x = realityX + x;
		data->_z = y - realityY;
		int _height = 0;
		hm.GetHeightMapData(hmdm, _x, _y, &_height);
		data->_y = heightFactor * _height;
		data->_u = _x * (1.0f / (float)numCellsPerRow);
		data->_v = _y * (1.0f / (float)numCellsPerCol);
	}
}

void TerrainData::SetInfo(int nWidth, int nHeight)
{
	SetHeightMapDataManager(nHeight, nWidth);
}

void * TerrainData::GetDataInfo(int nWidth, int nHeight)
{
	void * data = (void *)(GetData(nWidth , nHeight));
	return data;
}

void TerrainData::SetDataInfo(int nWidth, int nHeight, void * data)
{
	int _data = (int)data;
	SetData(nWidth, nHeight, _data);
}
