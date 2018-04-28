#pragma once
#include "_GraphInterface_.h"
#include "Camera.h"
static int staticheight = 0;
static int staticwidth = 0;
//坐标系
//		z轴
//		^
//		|
//		|
//		|
//------|------------>x轴
//		|
//		|
//		|
#include "HeightMap.h"
class TerrainData : public _CArrayBase_
{
public:
	void SetInfo(int nWidth, int nHeight);
	void * GetDataInfo(int nWidth, int nHeight);
	void SetDataInfo(int nWidth, int nHeight, void * data);
};

class Terrain : public _CGraphInterface_
{
public:
	Terrain();
	~Terrain();
public:
	void Init(IDirect3DDevice9 * pDevice);
	void Display(float timeDelta);
	

private:
	IDirect3DVertexBuffer9 * m_VB;
	IDirect3DIndexBuffer9 * m_IB;
	IDirect3DDevice9 * m_pDevice;
	//x y左上角坐标
	//stepX stepY 方格的长宽
	//heightFactor 高度因子 应该大于1？
	void SetTheUpperLeftCornerCoordinates(float x, float y, float stepX , float stepY , float heightFactor);//从左到右，从上到下
	TerrainData m_TerrainData;
	void GetTexture(float height);

	CCameraProperty m_CameraPrpperty;

	IDirect3DTexture9 * m_pTexture;
};