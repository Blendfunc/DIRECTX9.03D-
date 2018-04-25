#include "HeightMap.h"

CHeightMapDataManager::CHeightMapDataManager()
{
	m_Data = nullptr;
	m_Height = 0;
	m_Width = 0;
}

CHeightMapDataManager::~CHeightMapDataManager()
{
	if(m_Data)
	{
		free(m_Data);
		m_Data = nullptr;
	}
}

void CHeightMapDataManager::SetHeightMapDataManager(int height, int width)
{
	m_Data = malloc(sizeof(int) * height * width);
}

int CHeightMapDataManager::GetData(int x, int y)
{
	if(m_Data)
	{
		int index = (y * m_Width) + x;
		int * data = static_cast<int *>(m_Data) + index;
		return *data;
	}
	else
	{
		return -1;
	}
}

void CHeightMapDataManager::SetData(int x, int y, int number)
{
	if(m_Data)
	{
		int index = (y * m_Width) + x;
		int * data = static_cast<int *>(m_Data) + index;
		*data = number;
	}
}

CHeightMap::CHeightMap()
{
}

CHeightMap::~CHeightMap()
{
	for(auto iter = m_data.begin() ; iter != m_data.end() ; iter++)
	{
		delete *iter;
	}
}

void CHeightMap::GetHeightMap(inparameter outparameter CHeightMapDataManager ** data, inparameter int height, inparameter int width)
{
	CHeightMapDataManager * pData = new CHeightMapDataManager;
	*data = pData;
	pData->SetHeightMapDataManager(height, width);
	m_data.insert(pData);
}

void CHeightMap::GetHeightMapFromFile(inparameter std::string file, inparameter outparameter CHeightMapDataManager ** data ,/* int size*/inparameter outparameter int * height, inparameter outparameter int * width)
{
	if(data && height && width)
	{
		std::ifstream inFile(file.c_str(), std::ios_base::binary);
		/*inFile.read()*/
		LGBitMap lbm;
		LGBitMapId id;
		LGBitMapId outid;

		BITMAPCOLORDATA bitmapData;
		bitmapData.colorSpace = RGB;
		bitmapData.img = OTHERDATA;
		bitmapData.nMatrixHeight = 0;
		bitmapData.nMatrixWidth = 0;
		bitmapData.pMatrixColorData = nullptr;
		bitmapData.pMatrixColorTable = nullptr;

		USES_CONVERSION;
		lbm.LGLoadBitMap(A2T((LPSTR)file.c_str()), id);
		lbm.LGGray255Img(id, outid);
		lbm.LGGetColorData(outid, bitmapData);

		assert(bitmapData.pMatrixColorData);

		int start = (int)bitmapData.pMatrixColorData;

		CHeightMapDataManager * pchmm = nullptr;
		GetHeightMap(&pchmm, bitmapData.nMatrixHeight, bitmapData.nMatrixWidth);
		*data = pchmm;
		m_data.insert(pchmm);
		int _start = (int)pchmm->m_Data;
		*width = bitmapData.nMatrixWidth;
		*height = bitmapData.nMatrixHeight;

		for (int i = 0; i < bitmapData.nMatrixHeight * bitmapData.nMatrixWidth; i++)
		{
			int address = (i * sizeof(PixelData)) + start;
			PixelData * pPixelData = (PixelData *)address;
			int desAddress = (i * sizeof(int)) + _start;
			int * pDes = (int *)desAddress;
			*pDes = pPixelData->r;
		}
	}
}

bool CHeightMap::GetHeightMapData(inparameter CHeightMapDataManager * data, inparameter int x, inparameter int y, inparameter outparameter int *info)
{
	if(data && m_data.count(data) && info)
	{
		/*CHeightMapDataManager * pData = m_data[data];*/
		*info = data->GetData(x, y);
		return true;
	}
	else
	{
		return false;
	}
}

bool CHeightMap::SetHeightMapData(inparameter CHeightMapDataManager * data, inparameter int info, inparameter int x, inparameter int y)
{
	if(data && m_data.count(data))
	{
		data->SetData(x, y, info);
		return true;
	}
	return false;
}
