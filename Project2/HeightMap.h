#pragma once
#include ".\DX/Include/d3dx9.h"
#include "Common.h"
#include <string>
#include <set>
#include <fstream>
#include "LGImgCommon.h"

class CHeightMapDataManager
{
public:
	friend class CHeightMap;
	CHeightMapDataManager();
	~CHeightMapDataManager();
protected:
	void SetHeightMapDataManager(int height, int width);
	int GetData(int x , int y);
	void SetData(int x , int y , int number);
protected:
	void * m_Data;
	int m_Height;
	int m_Width;
};

typedef CHeightMapDataManager _CArrayBase_;

class CHeightMap
{
public:
	CHeightMap();
	~CHeightMap();
public:
	//获取高度图，每个元素代表着顶点的高度值
	void GetHeightMap(inparameter outparameter CHeightMapDataManager ** data, inparameter int height, inparameter int width);
	void GetHeightMapFromFile(inparameter std::string file, inparameter outparameter CHeightMapDataManager ** data ,/* inparameter int size*/inparameter outparameter int * height , inparameter outparameter int * width);

	bool GetHeightMapData(inparameter CHeightMapDataManager * data, inparameter int x, inparameter int y , inparameter outparameter int * info);
	bool SetHeightMapData(inparameter CHeightMapDataManager * data, inparameter int info , inparameter int x , inparameter int y);
private:
	std::set<CHeightMapDataManager *> m_data;
};