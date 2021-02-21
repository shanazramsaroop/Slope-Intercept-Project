/******************************************************************************
*	 File: point.h
*	Class: COP 2001
*  Author: Shanaz Ramsaroop
* Purpose: header file for a point class that represents a point on a line 
* with cordinates x and y
******************************************************************************/

#ifndef POINT_H
#define POINT_H

#include "opengl.h"

class Point
{
public:
	//-------------------------------------------------------------------------
	// constructors
	//-------------------------------------------------------------------------
	Point();	// default constructor
	Point(float x, float y);	// property constructor
	Point(Point* point);	// copy constructor

	//*************************************************************************
	// accessors (getters and setters)
	//*************************************************************************	
	float getX();
	void setX(float value);
	float getY();
	void setY(float value);

	//*************************************************************************
	// member methods
	//*************************************************************************

	bool isEmpty();
	

private:
	float x;
	float y;
	
};


#endif