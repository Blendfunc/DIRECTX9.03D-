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