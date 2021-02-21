/******************************************************************************
*	 File: line.h
*	Class: COP 2001
*  Author: Shanaz Ramsaroop
* Purpose: header file for a Line class for a slope intercept calculator
* that displays a line given other properties of the line
******************************************************************************/

#ifndef LINE_H
#define LINE_H

#include "point.h"

class Line
{
public:
	//-------------------------------------------------------------------------
	// constructors
	//-------------------------------------------------------------------------
	Line();	// default constructor
	Line(Point* one, Point* two);	// property constructor
	Line(Point* one, float slope);	// property constructor


	//*************************************************************************
	// accessors (getters and setters)
	//*************************************************************************
	Point* getPointOne();
	Point* getPointTwo();

	float getSlope();
	void setSlope(float value); 
	float getYIntercept();
	void setYIntercept(float value); 
	float getLength();
	void setLength(float value); 
	float getAngle();
	void setAngle(float value);

	//*************************************************************************
	// member methods
	//*************************************************************************

	void slopeFrom2Point();
	void slopeIntercept();
	void lineLength();
	void lineAngle();
	void calculate();

private:
	Point one;
	Point two;
	float slope;
	float yIntercept;
	float length;
	float angle;
	
};

#endif //line_h
