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