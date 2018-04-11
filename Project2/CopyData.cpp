#include "CopyData.h"

#define _CUBEDATA_(d,p1,p2,p3) \
d->_x = *p1 ; \
d->_y = *p2 ; \
d->_z = *p3

#define _PYRAMID_(d,p1,p2,p3,p4,p5,p6) \
_CUBEDATA_(d,p1,p2,p3) ; \
d->_nx = *p4 ; \
d->_ny = *p5 ; \
d->_nz = *p6 ;

#define _TEXTURE_(d,p1,p2,p3,p4,p5,p6,p7,p8) \
_PYRAMID_(d,p1,p2,p3,p4,p5,p6) \
d->_u = *p7 ; \
d->_v = *p8 ; \


//#define GETDATA(n,v) \
//for(int i = 0 ; i < n ; i++) \
//{ \

#define _ONE_STEP_ \
p,v->at(0),v->at(1),v->at(2)

#define _TWO_STEP_ \
v->at(3),v->at(4),v->at(5),v->at(6)

#define _THREE_STEP_ \
v->at(7),v->at(8)

#define GETDATA(n,v,p) \
if(n == 3) \
{ \
_CUBEDATA_(p,v->at(0),v->at(1),v->at(2)) \
} \
if(n == 6) \
{ \
_PYRAMID_(p,v->at(0),v->at(1),v->at(2),v->at(3),v->at(4),v->at(5),v->at(6)) \
} \
if(n == 8) \
{ \
_TEXTURE_(p,v->at(0),v->at(1),v->at(2),v->at(3),v->at(4),v->at(5),v->at(6),v->at(7),v->at(8)) \
}

#define _GETDATA_(n,v,p) \
if(n == 3) \
{ \
_CUBEDATA_(_ONE_STEP_) \
} \
if(n == 6) \
{ \
_PYRAMID_(_ONE_STEP_,_TWO_STEP_) \
} \
if(n == 8) \
{ \
_TEXTURE_(_ONE_STEP_,_TWO_STEP_,_THREE_STEP_) \
}



BOOL CCopyData::InitD3DVertexData(int count, inparameter void * pVertex, ...)
{
	/*return 0;*//*return 0;*//*return 0;*//*return 0;*//*return 0;*//*return 0;*//*return 0;*//*return 0;*//*return 0;*/
	/*return 0;*//*return 0;*//*return 0;*//*return 0;*//*return 0;*//*return 0;*//*return 0;*//*return 0;*//*return 0;*/
	/*return 0;*//*return 0;*//*return 0;*//*return 0;*//*return 0;*//*return 0;*//*return 0;*//*return 0;*//*return 0;*/
	/*return 0;*//*return 0;*//*return 0;*//*return 0;*//*return 0;*//*return 0;*//*return 0;*//*return 0;*//*return 0;*/
	/*return 0;*//*return 0;*//*return 0;*//*return 0;*//*return 0;*//*return 0;*//*return 0;*//*return 0;*//*return 0;*/
	/*return 0;*//*return 0;*//*return 0;*//*return 0;*//*return 0;*//*return 0;*//*return 0;*//*return 0;*//*return 0;*/
	if (nullptr == pVertex)
	{
		return FALSE;
	}
	va_list vl;
	va_start(vl, count);
	int i = 0;
	std::vector<std::shared_ptr<float>> vec;
	for (int _i = 0; _i < count; _i++)
	{
		std::shared_ptr<float> pf = std::make_shared<float>(va_arg(vl, float));
		vec.push_back(pf);
	}
	//switch type
	vertextype * pvt = (vertextype *)pVertex;
	if (pvt->type == cubetype)
	{
		VERTEXCUBE * pv = static_cast<VERTEXCUBE *>(pvt->data);
		_GETDATA_(3, &vec, pv);
	}
	if (pvt->type == litpyramidtype)
	{
		LitPyramidVertex * plpv = (LitPyramidVertex *)(pvt->data);
		/*LitPyramidVertex * plpv = static_cast<LitPyramidVertex *>(plpv->data);*/
		_GETDATA_(6, &vec, plpv);
	}
	if (pvt->type == texturedemo)
	{
		TextureStruct * pts = (TextureStruct *)(pvt->data);
		/*TextureStruct * pts = static_cast<TextureStruct *>(pvt->data);*/
		_GETDATA_(8, &vec, pts);
	}
}
