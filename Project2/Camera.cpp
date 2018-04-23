#include "Camera.h"

CCameraProperty * CCamera::property = nullptr;

void CCamera::InitCamera(CCameraProperty * _property)
{
	property = _property;
}

void CCamera::GetViewTransformationMatrix(inparameter outparameter D3DXMATRIX ** pMatrix, inparameter D3DXVECTOR3 * pRight, inparameter D3DXVECTOR3 * pUp, inparameter D3DXVECTOR3 * pLook, inparameter D3DXVECTOR3 * pPos)
{
	/*没有对传进来的变量做标准化，而是复制了一份去做了*/
	if (pMatrix && pRight && pUp && pLook && pPos)
	{
		D3DXVECTOR3 _right(*pRight);
		D3DXVECTOR3 _up(*pUp);
		D3DXVECTOR3 _look(*pLook);
		D3DXVECTOR3 _pos(*pPos);
		//Keep camera's axes otthogonal to eachother
		D3DXVec3Normalize(&_look, &_look);
		D3DXVec3Cross(&_up, &_look, &_right);
		D3DXVec3Normalize(&_up, &_up);
		D3DXVec3Cross(&_right, &_up, &_look);
		D3DXVec3Normalize(&_right, &_right);

		//Build the view matrix:
		float x = -D3DXVec3Dot(&_right, &_pos);
		float y = -D3DXVec3Dot(&_up, &_pos);
		float z = -D3DXVec3Dot(&_look, &_pos);

		D3DXMATRIX * V = new D3DXMATRIX;
		*pMatrix = V;
		(*V)(0, 0) = _right.x;
		(*V)(0, 1) = _up.x;
		(*V)(0, 2) = _look.x;
		(*V)(0, 3) = 0.0f;

		(*V)(1, 0) = _right.y;
		(*V)(1, 1) = _up.y;
		(*V)(1, 2) = _look.y;
		(*V)(1, 3) = 0.0f;

		(*V)(2, 0) = _right.z;
		(*V)(2, 1) = _up.z;
		(*V)(2, 2) = _look.z;
		(*V)(2, 3) = 0.0f;

		(*V)(3, 0) = x;
		(*V)(3, 1) = y;
		(*V)(3, 2) = z;
		(*V)(3, 3) = 1.0f;
	}
}

void CCamera::GetBobbingUpAndDownMatrix(inparameter outparameter D3DXMATRIX ** pMatrix, inparameter float * angle, inparameter D3DXVECTOR3 * pRight, inparameter D3DXVECTOR3 * pUp, inparameter D3DXVECTOR3 * pLook, inparameter D3DXVECTOR3 * pPos)
{
	/*绕right旋转*/
	/*这是一种方法，计算出来相机坐标重新再算一遍观察矩阵*/
	/*或许有另外一种方法？这个方法里计算出来的旋转变换矩阵后直接在旧的观察矩阵当中应用旋转矩阵*/
	if(pMatrix && angle && pRight && pUp && pLook && pPos)
	{
		/*防止传进来的值有改变，这里复制一份*/
		D3DXVECTOR3 _right(pRight->x, pRight->y, pRight->z);
		D3DXVECTOR3 _up(pUp->x, pUp->y, pUp->z);
		D3DXVECTOR3 _look(pLook->x, pLook->y, pLook->z);
		D3DXVECTOR3 _pos(pPos->x, pPos->y, pPos->z);
		D3DXMATRIX T;
		D3DXMatrixRotationAxis(&T, &_right, *angle);
		//rotate up and look around right
		D3DXVec3TransformCoord(&_up, &_up, &T);
		D3DXVec3TransformCoord(&_look, &_look, &T);
		*pMatrix = nullptr;
		GetViewTransformationMatrix(pMatrix, &_right, &_up, &_look, &_pos);
		if(property)
		{
			property->static_look.x = _look.x; property->static_look.y = _look.y; property->static_look.z = _look.z;
			property->static_pos.x = _pos.x; property->static_pos.y = _pos.y; property->static_pos.z = _pos.z;
			property->static_right.x = _right.x; property->static_right.y = _right.y; property->static_right.z = _right.z;
			property->static_up.x = _up.x; property->static_up.y = _up.y; property->static_up.z = _up.z;
		}
		
	}
}

void CCamera::GetBobbingLeftAndRightMatrix(inparameter outparameter D3DXMATRIX ** pMatrix, inparameter float * angle, inparameter D3DXVECTOR3 * pRight, inparameter D3DXVECTOR3 * pUp, inparameter D3DXVECTOR3 * pLook, inparameter D3DXVECTOR3 * pPos)
{
	/*绕up旋转*/
	if(pMatrix && angle && pRight && pUp && pLook && pPos)
	{
		/*防止传进来的值有改变，这里复制一份*/
		D3DXVECTOR3 _right(pRight->x, pRight->y, pRight->z);
		D3DXVECTOR3 _up(pUp->x, pUp->y, pUp->z);
		D3DXVECTOR3 _look(pLook->x, pLook->y, pLook->z);
		D3DXVECTOR3 _pos(pPos->x, pPos->y, pPos->z);
		D3DXMATRIX T;
		D3DXMatrixRotationAxis(&T, &_up, *angle);
		//rotate _right and _look around _up
		D3DXVec3TransformCoord(&_right, &_right, &T);
		D3DXVec3TransformCoord(&_look, &_look, &T);
		*pMatrix = nullptr;
		GetViewTransformationMatrix(pMatrix, &_right, &_up, &_look, &_pos);
		property->static_look.x = _look.x; property->static_look.y = _look.y; property->static_look.z = _look.z;
		property->static_pos.x = _pos.x; property->static_pos.y = _pos.y; property->static_pos.z = _pos.z;
		property->static_right.x = _right.x; property->static_right.y = _right.y; property->static_right.z = _right.z;
		property->static_up.x = _up.x; property->static_up.y = _up.y; property->static_up.z = _up.z;
	}
}

void CCamera::GetRotateMatrix(inparameter outparameter D3DXMATRIX ** pMatrix, inparameter float * angle, inparameter D3DXVECTOR3 * pRight, inparameter D3DXVECTOR3 * pUp, inparameter D3DXVECTOR3 * pLook, inparameter D3DXVECTOR3 * pPos)
{
	/*绕look旋转*/
	if(pMatrix && angle && pRight && pUp && pLook && pPos)
	{
		/*防止传进来的值有改变，这里复制一份*/
		D3DXVECTOR3 _right(pRight->x, pRight->y, pRight->z);
		D3DXVECTOR3 _up(pUp->x, pUp->y, pUp->z);
		D3DXVECTOR3 _look(pLook->x, pLook->y, pLook->z);
		D3DXVECTOR3 _pos(pPos->x, pPos->y, pPos->z);
		D3DXMATRIX T;
		D3DXMatrixRotationAxis(&T, &_look, *angle);
		//rotate _right and _look around _up
		D3DXVec3TransformCoord(&_right, &_right, &T);
		D3DXVec3TransformCoord(&_up, &_up, &T);
		*pMatrix = nullptr;
		GetViewTransformationMatrix(pMatrix, &_right, &_up, &_look, &_pos);
		property->static_look.x = _look.x; property->static_look.y = _look.y; property->static_look.z = _look.z;
		property->static_pos.x = _pos.x; property->static_pos.y = _pos.y; property->static_pos.z = _pos.z;
		property->static_right.x = _right.x; property->static_right.y = _right.y; property->static_right.z = _right.z;
		property->static_up.x = _up.x; property->static_up.y = _up.y; property->static_up.z = _up.z;
	}
}

void CCamera::GetWalkMatrix(inparameter outparameter D3DXMATRIX ** pMatrix, inparameter float * moving_distance_factor, inparameter D3DXVECTOR3 * pRight, inparameter D3DXVECTOR3 * pUp, inparameter D3DXVECTOR3 * pLook, inparameter D3DXVECTOR3 * pPos)
{
	/*当前位置向量加上look向量乘上因子后的向量*/
	if(pMatrix && moving_distance_factor && pRight && pUp && pLook && pPos)
	{
		/*防止传进来的值有改变，这里复制一份*/
		D3DXVECTOR3 _right(pRight->x , pRight->y , pRight->z);
		D3DXVECTOR3 _up(pUp->x , pUp->y , pUp->z);
		D3DXVECTOR3 _look(pLook->x , pLook->y , pLook->z);
		D3DXVECTOR3 _pos(pPos->x , pPos->y , pPos->z);
		_pos += _look * (*moving_distance_factor);
		*pMatrix = nullptr;
		GetViewTransformationMatrix(pMatrix, &_right, &_up, &_look, &_pos);
		property->static_look.x = _look.x; property->static_look.y = _look.y; property->static_look.z = _look.z;
		property->static_pos.x = _pos.x; property->static_pos.y = _pos.y; property->static_pos.z = _pos.z;
		property->static_right.x = _right.x; property->static_right.y = _right.y; property->static_right.z = _right.z;
		property->static_up.x = _up.x; property->static_up.y = _up.y; property->static_up.z = _up.z;
	}
}

void CCamera::GetLeftOrRightMoveMatrix(inparameter outparameter D3DXMATRIX ** pMatrix, inparameter float * moving_distance_factor, inparameter D3DXVECTOR3 * pRight, inparameter D3DXVECTOR3 * pUp, inparameter D3DXVECTOR3 * pLook, inparameter D3DXVECTOR3 * pPos)
{
	/*当前位置向量加上right向量乘上因子后的向量*/
	if (pMatrix && moving_distance_factor && pRight && pUp && pLook && pPos)
	{
		/*防止传进来的值有改变，这里复制一份*/
		D3DXVECTOR3 _right(pRight->x, pRight->y, pRight->z);
		D3DXVECTOR3 _up(pUp->x, pUp->y, pUp->z);
		D3DXVECTOR3 _look(pLook->x, pLook->y, pLook->z);
		D3DXVECTOR3 _pos(pPos->x, pPos->y, pPos->z);
		_pos += _right * (*moving_distance_factor);
		*pMatrix = nullptr;
		GetViewTransformationMatrix(pMatrix, &_right, &_up, &_look, &_pos);
		property->static_look.x = _look.x; property->static_look.y = _look.y; property->static_look.z = _look.z;
		property->static_pos.x = _pos.x; property->static_pos.y = _pos.y; property->static_pos.z = _pos.z;
		property->static_right.x = _right.x; property->static_right.y = _right.y; property->static_right.z = _right.z;
		property->static_up.x = _up.x; property->static_up.y = _up.y; property->static_up.z = _up.z;
	}
}

void CCamera::GetUpOrDownMoveMatrix(inparameter outparameter D3DXMATRIX ** pMatrix, inparameter float * moving_distance_factor, inparameter D3DXVECTOR3 * pRight, inparameter D3DXVECTOR3 * pUp, inparameter D3DXVECTOR3 * pLook, inparameter D3DXVECTOR3 * pPos)
{
	/*当前位置向量加上up向量乘上因子后的向量*/
	if (pMatrix && moving_distance_factor && pRight && pUp && pLook && pPos)
	{
		/*防止传进来的值有改变，这里复制一份*/
		D3DXVECTOR3 _right(pRight->x, pRight->y, pRight->z);
		D3DXVECTOR3 _up(pUp->x, pUp->y, pUp->z);
		D3DXVECTOR3 _look(pLook->x, pLook->y, pLook->z);
		D3DXVECTOR3 _pos(pPos->x, pPos->y, pPos->z);
		_pos += _up * (*moving_distance_factor);
		*pMatrix = nullptr;
		GetViewTransformationMatrix(pMatrix, &_right, &_up, &_look, &_pos);
		property->static_look.x = _look.x; property->static_look.y = _look.y; property->static_look.z = _look.z;
		property->static_pos.x = _pos.x; property->static_pos.y = _pos.y; property->static_pos.z = _pos.z;
		property->static_right.x = _right.x; property->static_right.y = _right.y; property->static_right.z = _right.z;
		property->static_up.x = _up.x; property->static_up.y = _up.y; property->static_up.z = _up.z;
	}
}
