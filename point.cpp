/******************************************************************************
*	 File: Point.cpp
*	Class: COP 2001
*  Author: Shanaz Ramsaroop
* Purpose: Implementation file for a Point class that represents a rectangle
* game object with position, size and velocities.
******************************************************************************/

#include "point.h"

//-----------------------------------------------------------------------------
// constructors
//-----------------------------------------------------------------------------

/******************************************************************************
default constructor
******************************************************************************/
Point::Point()
{
	x = 0.0f;
	y = 0.0f;
}

/******************************************************************************
property constructor
******************************************************************************/
Point::Point(float x, float y)
{
	this->x = x;
	this->y = y;
	
}

/******************************************************************************
copy constructor
******************************************************************************/
Point::Point(Point* point)
{
	x = point->x;
	y = point->y;
}

//*****************************************************************************
// accessors (getters and setters)
//*****************************************************************************	
float	Point::getX() { return x; }
void	Point::setX(float value) { x = value; }
float	Point::getY() { return y; }
void	Point::setY(float value) { y = value; }


//*****************************************************************************
// member methods
//*****************************************************************************

/******************************************************************************
*determine if both values are zero
*Return:
*	bool	- true if both values are zero
******************************************************************************/
bool Point::isEmpty()
{
	bool empty = false;

	// truncate floats to integer for comparison
	empty =  int(x == 0) && int(y == 0);

	return empty;
}