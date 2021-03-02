/***********************************************
Author: Saema Nazar
Date: 2/9/2020
Purpose: Use concept of classes and create member functions that can
		manipulate coordinates by setting, getting, moving, rotating a point.
Sources of Help: lecture notes
Time Spent: 45 mins

Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining
good order in the classroom, providing an enriching learning
experience for students, and as training as a practicing computing
professional upon graduation. This practice is manifested in the
University’s Academic Integrity policy. Students are expected to
strictly avoid academic dishonesty and adhere to the Academic
Integrity policy as outlined in the course catalog. Violations will
be dealt with as outlined therein.
All programming assignments in this class are to be done by the
student alone. No outside help is permitted except the instructor and
approved tutors.
I certify that the work submitted with this assignment is mine and was
generated in a manner consistent with this document, the course
academic policy on the course website on Blackboard, and the UMass
Lowell academic code.
Date: 2/9/2020
Name: Saema Nazar
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Point {
public:

	//function: outputs values of member variables x & y to screen
	//parameters: void
	void display(void);

	//function: MUTATOR function, takes in values for x and y from stdin/from main and sets equal to private member variables.
	//parameters: integer values of x and y from main
	void setCoord(int xCoord, int yCoord);

	//function: move member variables along vertical and horizontal 
	//			axes by the amounts specified when calling the function in main. 
	//parameters: moveX: horizontal move value, moveY: vertical move value
	void moveCoord(int moveX, int moveY);

	//function: rotate point clockwise along plane by taking x,y values as parameters and
			//	calling setCoord function to change their values to their clockwise locations
	//parameters: values of x and y member variables
	void rotateClockwise(int xCoord, int yCoord);

	//function: ACCESSOR function, that accesses private member variable x's value
	//parameters: void
	//return value: value of member variable x is returned
	int getCoordX(void);

	//function: ACCESSOR function, that accesses private member variable y's value
	//parameters: void
	//return value: value of member variable y is returned
	int getCoordY(void);

private:
	int x;
	int y;

};


int main(int argc, char* argv[]) {

	Point testPoint;

	///////CASE #1
	cout << "Case #1\n";
	testPoint.setCoord(1, 2);
	testPoint.display();

	testPoint.rotateClockwise(testPoint.getCoordX(), testPoint.getCoordY());
	testPoint.rotateClockwise(testPoint.getCoordX(), testPoint.getCoordY());
	testPoint.rotateClockwise(testPoint.getCoordX(), testPoint.getCoordY());
	testPoint.rotateClockwise(testPoint.getCoordX(), testPoint.getCoordY());

	cout << "Point (1,2) after 4 clockwise rotations:" << endl;
	testPoint.display();

	//////CASE #2
	testPoint.setCoord(3, 4);
	testPoint.moveCoord(1, 1);
	cout << "Case #2\nPoint (3,4) after moving (1,1):" << endl;
	testPoint.display();

	/////CASE #3
	Point testPoint2;
	testPoint2.setCoord(5, -4);
	testPoint2.moveCoord(-5, 4);

	cout << "Case #3\nPoint (5,-4) after moved back to origin:" << endl;
	testPoint2.display();

	return 0;
}

void Point::display(void) {
	cout << "x: " << x << "\ty: " << y << endl << endl;
}

void Point::setCoord(int xCoord, int yCoord) {
	x = xCoord;
	y = yCoord;
}


void Point::moveCoord(int moveX, int moveY) {
	x = x + moveX;
	y = y + moveY;
}
void Point::rotateClockwise(int xCoord, int yCoord) {

	setCoord(yCoord, -xCoord);

}

int Point::getCoordX(void) {
	return x;
}
int Point::getCoordY(void) {
	return y;
}
