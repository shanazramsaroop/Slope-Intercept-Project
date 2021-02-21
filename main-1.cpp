/******************************************************************************
*	 File: main.cpp
*	Class: COP 2001
*  Author: Shanaz Ramsaroop
* Purpose: program to calculate the slope, y-intercept, lenght and
*angle the line makes with the x-axis. The point-slope, two-point and
*slope-intercept form of the line is also generated.
******************************************************************************/

#include <iostream>
#include <math.h>     
#include <iomanip>
#include <string>
#include <istream>

#include "opengl.h"  //graphics library
#include "point.h"
#include "point.cpp"
#include "line.h"
#include "line.cpp"


//*****************************************************************************  
//Global space
//*****************************************************************************
//const double PI = 3.14159265;
const int WINDOW_HEIGHT = 400;
const int WINDOW_WIDTH = 400;
const char* WINDOW_TITLE = "Graph\0";

enum Mode
{
	TWO_POINT = 1,
	POINT_SLOPE = 2,
	EXIT = 3,
};


//*****************************************************************************
//Function Prototyes
//*****************************************************************************
int getProblem();
Line get2Point();
Line getPointSlope();
Point getPoint();
void displayLine(Line line);
void display2Point(Line line);
void displayPointSlope(Line line);
void displaySlopeIntercept(Line line);
void drawLine(Line line);

int main()
{

	Line line = Line();

	// initialize the user's choice
	int choice;
	do
	{
		// gets the user's choice
		choice = getProblem();

		// if user's choice is equal to the two point option
		if (choice == Mode::TWO_POINT)
			line = get2Point();

		// if user's choice is equal to the point slope option
		else if (choice == Mode::POINT_SLOPE)
			line = getPointSlope();

		// calculate the properties of the line
		line.calculate();

		// display the lines in different formats
		displayLine(line);
		display2Point(line);
		displayPointSlope(line);
		displaySlopeIntercept(line);

		// display the line on a graph
		drawLine(line);

	} while (choice != 3); // repeat until user enters 3 (Exit)

	char pause;
	std::cin >> pause;

	return 0;
}

/******************************************************************************
*Prompts user to select an option
*returns:
*	 choice - user's selection from the menu
******************************************************************************/
int getProblem()
{
	// print the menu
	std::cout << "\n	Select the form that you would like to "
		<< "convert to slope-intercept form: \n";
	std::cout << "		1) Two-point form (you know two points on the line)\n";
	std::cout << "		2) Point-slope form (you know the line's slope "
		<< "and one point) \n";
	std::cout << "		3) Exit ";

	int choice;
	std::cin >> choice;

	return choice;
}

/******************************************************************************
*Gets two points that define a line from the user and gets other
*properties of a line
*Returns:
*	line - properties of a line (x, y, slope, y-intercept, length, angle)
******************************************************************************/
Line get2Point()
{
	Line line = Line();

	// get two points from the user
	std::cout << "\n	Enter the first point \n";
	Point one = getPoint();

	std::cout << "\n	Enter the second point \n";
	Point two = getPoint();

	Line(&one, &two);

	return line;
}

/******************************************************************************
*Gets one point and the slope that define a line and gets other properties
*of a line
*Returns:
*	line - properties of a line (x, y, slope, y-intercept, length, angle)
******************************************************************************/
Line getPointSlope()
{
	Line line = Line();

	float slope;

	// prompt the user for a point
	std::cout << "\n	Enter a point on the line \n";
	Point one = getPoint();

	// prompt the user for the slope of the line
	std::cout << "\n	Enter the slope of the line: ";
	std::cin >> slope;

	line.setSlope(slope);

	Line(&one, line.getSlope());

	return line;
}

/******************************************************************************
*Gets point from user
*Return:
*	point - properties of a point(x and y cordinates)
******************************************************************************/
Point getPoint()
{
	Point point = Point();

	//prompt user for cordinate
	std::cout << "	Enter X and Y cordinates separated by spaces: ";

	float x, y;
	std::cin >> x;
	std::cin >> y;

	Point(x, y);	

	return point;
}


/******************************************************************************
*displayed the properties of a line
*Parameters:
*	line - properties of a line (x, y, slope, y-intercept, length, angle)
******************************************************************************/
void displayLine(Line line)
{
	//prints the properties of the line
	std::cout << "\n	Line: \n";
	std::cout << std::setprecision(3) << "			Point-1 = ("
		<< line.getPointOne()->getX() << "," << line.getPointOne()->getY() << ")\n";
	std::cout << std::setprecision(3) << "			Point-2 = ("
		<< line.getPointTwo()->getX() << "," << line.getPointTwo()->getY() << ")\n";
	std::cout << std::setprecision(3) << "			  Slope = "
		<< line.getSlope() << "\n";
	std::cout << std::setprecision(3) << "		    Y-intercept = "
		<< line.getYIntercept() << "\n";
	std::cout << std::setprecision(3) << "			 Lenght = "
		<< line.getLength() << "\n";
	std::cout << std::setprecision(3) << "			  Angle = "
		<< line.getAngle() << "\n";
}

/******************************************************************************
*displays the 2-point form of a line
*Parameters:
*	line - properties of a line (x, y, slope, y-intercept, length, angle)
******************************************************************************/
void display2Point(Line line)
{
	std::cout << "\n	Two-point form:\n";
	std::cout << "				(" << line.getPointTwo()->getY()<< " - " 
		<< line.getPointOne()->getY() << ")\n";
	std::cout << "			m = --------------------\n";
	std::cout << "				(" << line.getPointTwo()->getX() << " - " 
		<< line.getPointOne()->getX() << ")\n";
}

/******************************************************************************
*displays the point-slope form of a line
*Parameters:
*	line - properties of a line (x, y, slope, y-intercept, length, angle)
******************************************************************************/
void displayPointSlope(Line line)
{
	std::cout << "\n	Point-slope form: \n";
	std::cout << std::setprecision(3) << "			y - " << line.getPointOne()->getY()
		<< " = " << line.getSlope() << "(x  - " << line.getPointOne()->getX() << ")\n";
}

/******************************************************************************
*display slope-intercept of a line
*Parameters:
*	line - properties of a line (x, y, slope, y-intercept, length, angle)
******************************************************************************/
void displaySlopeIntercept(Line line)
{
	std::cout << "\n	Slope-intercept form:\n";
	std::cout << "			y = " << line.getSlope() << "x + " << line.getYIntercept()
		<< "\n";
}

/******************************************************************************
*draws the line on a graph
*Parameters:
*	line - properties of a line (x, y, slope, y-intercept, length, angle)
******************************************************************************/

void drawLine(Line line)
{
	OpenGL window = OpenGL(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

	// initialization of variables for y-axis
	float xYAxis = 0;
	float yYAxis = WINDOW_HEIGHT / 2;
	float widthYAxis = 2;
	float heightYAxis = WINDOW_HEIGHT;
	float angleYAxis = 90;
	int colorY = 0x00000000;

	float positionY[2] = { xYAxis, yYAxis };
	float sizeY[2] = { widthYAxis, heightYAxis };

	float rotationYAxis = angleYAxis + 180;

	// initialization of variables for x-axis
	float xXAxis = WINDOW_WIDTH / 2;
	float yXAxis = WINDOW_HEIGHT;
	float widthXAxis = WINDOW_WIDTH;
	float heightXAxis = 2;
	float angleXAxis = 0;
	int colorX = 0x00000000;

	float positionX[2] = { xXAxis, yXAxis };
	float sizeX[2] = { widthXAxis, heightXAxis };

	float rotationXAxis = angleYAxis + 180;

	// initialization for line based on user's input
	float x = line.getPointOne()->getX();
	float y = line.getPointOne()->getY();
	float width = 2;
	float height = line.getLength();
	float angle = line.getAngle();
	int color = 0x0000FF00;

	x += WINDOW_WIDTH / 2;
	y += WINDOW_HEIGHT / 2 - y;

	float position[2] = { x, y };
	float size[2] = { width, height };

	float rotation = angle - 180;

	while (!window.isClosing())
	{
		// clear window memory buffer
		window.clearWindow();

		// draw vertical y-axis line
		window.DrawSprite(positionY, sizeY,
			reinterpret_cast<unsigned char*>(&colorY),
			rotationYAxis, false);

		// draw horizontal x-axis line
		window.DrawSprite(positionX, sizeX,
			reinterpret_cast<unsigned char*>(&colorX),
			rotationXAxis, false);

		// draw line based on user's input
		window.DrawSprite(position, size,
			reinterpret_cast<unsigned char*>(&color),
			rotation, false);

		// repaint the window
		window.paintWindow();

		window.pollEvents();

	}
}

