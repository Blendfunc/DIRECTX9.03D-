#pragma once
#define outparameter//��������ֵ���������
#define inparameter//����������ⲿ����ռ�
#define inoutparameter//����һ��void**������������ڲ�����ռ��������ⲿ
#define _INTERFACE_ class//�ӿ�

#define _VARIABLE_NAME_(name,type) \
type name;

#define _USE_PUBLIC_ \
public:

#define _USE_PROTECTED_ \
protected:

#define _USE_PRIVATE_ \
private:

#define _BEGIN_INTERFACE_(interfacename) \
class interfacename \
{

#define _END_INTERFACE_ \
};

#define _FUNCTION_NAME_(name,rv,...) \
virtual rv name (__VA_ARGS__) = 0 ;

struct VERTEXCUBE
{
	VERTEXCUBE() {}
	VERTEXCUBE(float x, float y, float z)
	{
		_x = x; _y = y; _z = z;
	}
	float _x, _y, _z;
	static const DWORD FVF = D3DFVF_XYZ;//����ṹ��sizeof�����ʱ���������FVF����μ����
};

//const DWORD VERTEXCUBE::FVF = D3DFVF_XYZ;

struct LitPyramidVertex
{
	//���㣬���ߣ����ǽṹ��û�а�����ʾ��ɫ�ĳ�Ա����
	//������Ϊ���ǽ��ù��������㶥�����ɫ 
	float _x, _y, _z;//����
	float _nx, _ny, _nz;//���ߣ�Direct3D��Ҫ֪������ķ��߷�����ȷ�����ߵ������ʱ�������
	static const DWORD FVF = D3DFVF_XYZ | D3DFVF_NORMAL;
};

typedef struct TextureStruct
{
	float _x, _y, _z;
	float _nx, _ny, _nz;
	float _u, _v;
	static const DWORD FVF = D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1;
};

typedef struct CubeExStruct
{
	float _x, _y, _z;
	float _nx, _ny, _nz;
	float _u, _v;
	static const DWORD FVF = D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1;
	CubeExStruct() {}
	CubeExStruct(float x, float y, float z, float nx, float ny, float nz, float u, float v)
	{
		_x = x; _y = y; _z = z; _nx = nx; _ny = ny; _nz = nz; _u = u; _v = v;
	}
};

struct TerrainStruct
{
	float _x, _y, _z;
	float _u, _v;
	static const DWORD FVF = D3DFVF_XYZ | D3DFVF_TEX1;
};

enum _type_
{
	cubetype = 0 ,
	litpyramidtype = 1 ,
	texturedemo = 2 ,
	cubeextype
};

struct vertextype
{
	_type_ type;
	void * data;
};


