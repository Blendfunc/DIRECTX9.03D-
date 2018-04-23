#pragma once
#include "CameraProperty.h"
#include ".\DX/Include/d3dx9.h"
#include "Common.h"

//�洢�����ı��˵����λ������
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
	/*�۲����ȡ���任����*/
	static void GetViewTransformationMatrix(inparameter outparameter D3DXMATRIX ** pMatrix , inparameter D3DXVECTOR3 * pRight , inparameter D3DXVECTOR3 * pUp , inparameter D3DXVECTOR3 * pLook , inparameter D3DXVECTOR3 * pPos);
	
	/*���°ڶ�������*/
	static void GetBobbingUpAndDownMatrix(inparameter outparameter D3DXMATRIX ** pMatrix, inparameter float * angle, inparameter D3DXVECTOR3 * pRight, inparameter D3DXVECTOR3 * pUp, inparameter D3DXVECTOR3 * pLook, inparameter D3DXVECTOR3 * pPos);

	/*���Ұڶ���ƫ��*/
	static void GetBobbingLeftAndRightMatrix(inparameter outparameter D3DXMATRIX ** pMatrix, inparameter float * angle, inparameter D3DXVECTOR3 * pRight, inparameter D3DXVECTOR3 * pUp, inparameter D3DXVECTOR3 * pLook, inparameter D3DXVECTOR3 * pPos);

	/*��������ת*/
	static void GetRotateMatrix(inparameter outparameter D3DXMATRIX ** pMatrix, inparameter float * angle, inparameter D3DXVECTOR3 * pRight, inparameter D3DXVECTOR3 * pUp, inparameter D3DXVECTOR3 * pLook, inparameter D3DXVECTOR3 * pPos);

	/*���ߣ�����look����*/
	static void GetWalkMatrix(inparameter outparameter D3DXMATRIX ** pMatrix, inparameter float * moving_distance_factor, inparameter D3DXVECTOR3 * pRight, inparameter D3DXVECTOR3 * pUp, inparameter D3DXVECTOR3 * pLook, inparameter D3DXVECTOR3 * pPos);

	/*ɨ�ӣ�right���������ƶ�*/
	static void GetLeftOrRightMoveMatrix(inparameter outparameter D3DXMATRIX ** pMatrix, inparameter float * moving_distance_factor, inparameter D3DXVECTOR3 * pRight, inparameter D3DXVECTOR3 * pUp, inparameter D3DXVECTOR3 * pLook, inparameter D3DXVECTOR3 * pPos);

	/*�����������ƶ���up����*/
	static void GetUpOrDownMoveMatrix(inparameter outparameter D3DXMATRIX ** pMatrix, inparameter float * moving_distance_factor, inparameter D3DXVECTOR3 * pRight, inparameter D3DXVECTOR3 * pUp, inparameter D3DXVECTOR3 * pLook, inparameter D3DXVECTOR3 * pPos);
public:
	static CCameraProperty * property;
};
