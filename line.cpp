/******************************************************************************
*	 File: line.cpp
*	Class: COP 2001
*  Author: Shanaz Ramsaroop
* Purpose: Implementation file for a Line class for a slope intercept calculator
* that displays a line given other properties of the line
******************************************************************************/

#include <math.h>     
#include <iomanip>

#include "line.h"

//*****************************************************************************  
//Global space
//*****************************************************************************
const double PI = 3.14159265;

//-----------------------------------------------------------------------------
// constructors
//-----------------------------------------------------------------------------

/******************************************************************************
default constructor
******************************************************************************/
Line::Line()
{
	one = Point();
	two = Point();
	slope = 0.0f;
	yIntercept = 0.0f;
	length = 0.0f;
	angle = 0.0f;
}

/******************************************************************************
property constructor
******************************************************************************/
Line::Line(Point* one, Point* two)
{
	this->one = Point(one);
	this->two = Point(two);
	slope = 0.0f;
	yIntercept = 0.0f;
	length = 0.0f;
	angle = 0.0f;

}

Line::Line(Point* one, float slope)
{
	this->one = Point(one);
	this->two = Point();
	this->slope = slope;
	yIntercept = 0.0f;
	length = 0.0f;
	angle = 0.0f;
}


//*****************************************************************************
// accessors (getters and setters)
//*****************************************************************************

Point* Line::getPointOne(){ return &one; }
Point* Line::getPointTwo() { return &two; }

float Line::getSlope() { return slope; }
void  Line::setSlope(float value) { slope = value; }
float Line::getYIntercept() { return yIntercept; }
void  Line::setYIntercept(float value) { yIntercept = value; }
float Line::getLength() { return length; }
void  Line::setLength(float value) { length = value; }
float Line::getAngle() { return angle; }
void  Line::setAngle(float value) { angle = value; }

//*****************************************************************************
// member methods
//*****************************************************************************

/******************************************************************************
*draws the game objects
*Parameters:
*Returns:
*	void
******************************************************************************/
void Line::slopeFrom2Point()
{
	setSlope((two.getY() - one.getY()) / (two.getX() - one.getX()));
}

/******************************************************************************
*calculates the y - intercept of a line
*Parameters:
*Returns:
*	void
******************************************************************************/
void Line::slopeIntercept()
{
	setYIntercept(one.getY()  - (getSlope() * one.getX()));
}

/******************************************************************************
*calculates lenght of a line
*Parameters:
*Returns:
*	void
******************************************************************************/
void Line::lineLength()
{
	setLength(sqrt(std::pow((two.getX() - one.getX()), 2) + 
		std::pow((two.getY() - one.getY()), 2)));
}

/******************************************************************************
*calculates the angle between the line and the x-axis
*Parameters:
*Returns:
*	void
******************************************************************************/
void Line::lineAngle()
{
	float phi = std::atan2(two.getY() - one.getY(), two.getX() - one.getX());
	setAngle(std::fmod(90.0 - double(phi * 180.0 / PI), 360));
}

/******************************************************************************
*sets the slope, y-intercept, point two, length and angle
*Parameters:
*Returns:
*	void
******************************************************************************/
void Line::calculate()
{
	// calculate slope if two point form (slope is not given)
	if (!getPointOne()->isEmpty() || !getPointTwo()->isEmpty())
	{
		//calculate slope
		setSlope(slope);
	}

	//calculate y-intercept
	setYIntercept(yIntercept);

	// calculate the second point if one point is given
	if (getPointOne()->isEmpty() || getPointTwo()->isEmpty())
	{
		// calculate second point
		getPointTwo();
	}

	// calculate lenth of the line
	setLength(length);

	// calculate the angle the line makes with the x-axis
	setAngle(angle);

}