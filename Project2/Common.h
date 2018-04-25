#pragma once
#define outparameter//函数返回值，输出参数
#define inparameter//输入参数，外部分配空间
#define inoutparameter//接收一个void**等输入参数，内部分配空间后输出到外部
#define _INTERFACE_ class//接口

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
	static const DWORD FVF = D3DFVF_XYZ;//这里结构体sizeof计算的时候，这个变量FVF是如何计算的
};

//const DWORD VERTEXCUBE::FVF = D3DFVF_XYZ;

struct LitPyramidVertex
{
	//顶点，法线，但是结构中没有包含表示颜色的成员变量
	//这是因为我们将用光照来计算顶点的颜色 
	float _x, _y, _z;//顶点
	float _nx, _ny, _nz;//法线，Direct3D需要知道顶点的法线方向，以确定光线到达表面时的入射角
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


