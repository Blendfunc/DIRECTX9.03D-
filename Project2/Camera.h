#pragma once
#include "CameraProperty.h"
#include ".\DX/Include/d3dx9.h"
#include "Common.h"

//存储经过改变了的相机位置属性
//namespace camera
//{
//	static D3DXVECTOR3 static_right;
//	static D3DXVECTOR3 static_up;
//	static D3DXVECTOR3 static_look;
//	static D3DXVECTOR3 static_pos;
//}
//



class CCamera
{

//public:
	/*CCamera();*/
	/*~CCamera();*/
public:
	static void InitCamera(CCameraProperty * _property);
public:
	/*观察矩阵，取景变换矩阵*/
	static void GetViewTransformationMatrix(inparameter outparameter D3DXMATRIX ** pMatrix , inparameter D3DXVECTOR3 * pRight , inparameter D3DXVECTOR3 * pUp , inparameter D3DXVECTOR3 * pLook , inparameter D3DXVECTOR3 * pPos);
	
	/*上下摆动，俯仰*/
	static void GetBobbingUpAndDownMatrix(inparameter outparameter D3DXMATRIX ** pMatrix, inparameter float * angle, inparameter D3DXVECTOR3 * pRight, inparameter D3DXVECTOR3 * pUp, inparameter D3DXVECTOR3 * pLook, inparameter D3DXVECTOR3 * pPos);

	/*左右摆动，偏航*/
	static void GetBobbingLeftAndRightMatrix(inparameter outparameter D3DXMATRIX ** pMatrix, inparameter float * angle, inparameter D3DXVECTOR3 * pRight, inparameter D3DXVECTOR3 * pUp, inparameter D3DXVECTOR3 * pLook, inparameter D3DXVECTOR3 * pPos);

	/*滚动，旋转*/
	static void GetRotateMatrix(inparameter outparameter D3DXMATRIX ** pMatrix, inparameter float * angle, inparameter D3DXVECTOR3 * pRight, inparameter D3DXVECTOR3 * pUp, inparameter D3DXVECTOR3 * pLook, inparameter D3DXVECTOR3 * pPos);

	/*行走，沿着look方向*/
	static void GetWalkMatrix(inparameter outparameter D3DXMATRIX ** pMatrix, inparameter float * moving_distance_factor, inparameter D3DXVECTOR3 * pRight, inparameter D3DXVECTOR3 * pUp, inparameter D3DXVECTOR3 * pLook, inparameter D3DXVECTOR3 * pPos);

	/*扫视，right方向，左右移动*/
	static void GetLeftOrRightMoveMatrix(inparameter outparameter D3DXMATRIX ** pMatrix, inparameter float * moving_distance_factor, inparameter D3DXVECTOR3 * pRight, inparameter D3DXVECTOR3 * pUp, inparameter D3DXVECTOR3 * pLook, inparameter D3DXVECTOR3 * pPos);

	/*升降，上下移动，up方向*/
	static void GetUpOrDownMoveMatrix(inparameter outparameter D3DXMATRIX ** pMatrix, inparameter float * moving_distance_factor, inparameter D3DXVECTOR3 * pRight, inparameter D3DXVECTOR3 * pUp, inparameter D3DXVECTOR3 * pLook, inparameter D3DXVECTOR3 * pPos);
public:
	static CCameraProperty * property;
};
