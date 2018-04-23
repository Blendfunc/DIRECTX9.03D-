#include ".\DX/Include/d3dx9.h"
class Test
{
	void TestCode()
	{
		D3DXVECTOR3 look;
		look.x = 12; look.y = 13; look.z = 14;
		D3DXVECTOR3 right;
		right.x = 21; right.y = 23; right.z = 12;
		D3DXVECTOR3 _look;
		_look.x = 0; _look.y = 0; _look.z = 0;
		D3DXVec3Normalize(&_look, &look);
		D3DXVECTOR3 result;
		result.x = 0; result.y = 0; result.z = 0;
		D3DXVECTOR3 _result;
		_result.x = 0; _result.y = 0; _result.z = 0;
		D3DXVec3Cross(&result, &look, &right);
		D3DXVec3Cross(&_result, &_look, &right);

		D3DXVECTOR3 v1(0.0f, 0.0f, 0.0f);
		D3DXVECTOR3 v2(0.0f, 0.0f, 0.0f);
		
		D3DXVec3Normalize(&v1, &result);
		D3DXVec3Normalize(&v2, &_result);
		/*检查v1和v2是否相等*/
		//经过测试v1和v2值如下
		/**((_D3DVECTOR*)&v1), nd{ x = -0.741892517 y = 0.670384824 z = 0.0134076960 }
		*((_D3DVECTOR*)&v2), nd{ x = -0.741892457 y = 0.670384765 z = 0.0134077007 }*/
	}
};
