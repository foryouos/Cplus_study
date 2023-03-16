#pragma once
#ifndef _RECTANGLE_H
#define _RECTANGLE_H
#include "Point.h"
class Rectangle :public Point //派生类的定义
{
public:  //新添共有函数成员
	void initRectangle(float x, float y, float w, float h)
	{
		initPoint(x, y); //调用基类共有成员函数
		this->w = w;  //this此Rectangle指针，可以调用本类私有成员以及成成的派生类的共有函数
		this->h = h;
	}
	float getH() const
	{
		return h;
	}
	float getW() const
	{
		return w;
	}
private:	//新添私有函数成员
	float w, h;

};
#endif // !_RECTANGLE_H
