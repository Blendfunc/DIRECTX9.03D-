#include "Terrain.h"
#include "HeightMap.h"
#include "Common.h"

Terrain::Terrain()
{
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
		m_pDevice = pDevice;
		assert(hmdm);
		int pointsX = staticwidth + 1 - 1;
		int pointY = staticheight + 1 - 1;

		IDirect3DVertexBuffer9 * pVertex = nullptr;
		pDevice->CreateVertexBuffer(pointsX * pointY * sizeof(TerrainStruct) , D3DUSAGE_WRITEONLY , TerrainStruct::FVF , D3DPOOL_MANAGED , &pVertex , 0);
		assert(pVertex);
		SetTheUpperLeftCornerCoordinates(0.0f, 0.0f, 15.0f, 15.0f, 1.5);
		TerrainStruct * pTerrainStruct = nullptr;
		pVertex->Lock(0, 0, (void **)&pTerrainStruct, 0);
		for(int i = 0 ; i < pointsX * pointY ; i++)
		{
			int _x = i % staticwidth;
			int _y = (i - _x) / staticwidth;
			TerrainStruct * pData = (TerrainStruct *)m_TerrainData.GetDataInfo(_x, _y);
			pTerrainStruct[i] = *pData;
		}
		pVertex->Unlock();
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
