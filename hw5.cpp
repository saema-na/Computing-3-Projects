/***********************************************
Author: Saema Nazar
Date: 2/23/20
Purpose: create a program that can manipulate rational numbers using classes and operator overloading
Sources of Help: lectures and my own code from COMP1 for the GCD function
Time Spent: 4 hrs

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
Date: 2/23/2020
Name: Saema Nazar
*/


/*
Changes made in resubmission:	-added condition to check for a 0 denominator in constructor. User is asked
								to enter a non-zero denominator if a zero is entered initially.
								-GCD function is called and value is printed before other computations are done
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Rational {
public:
	Rational();
	Rational(int wholeNumber);
	Rational(int topVal, int bottomVal);
	void display(void);
	int getNumerator(void) const;
	int getDenominator(void)const;

private:
	int numerator = 0;
	int denominator = 1;
};

//function: overload addition operator to add numerators and denominators of given rational variables.
//			returns a simplified Rational object containing value of added fractions
//parameters: const value of address of 2 rational objects being added
Rational operator+(const Rational& r1, const Rational& r2);

/*	function: overload subtraction operator to subtract values in second rational object from
	value of first rational object .
	return: simplified rational fraction of the subtracted values.
	parameters: const values, addresses of 2 rational objects being subtracted
*/
Rational operator-(const Rational& r1, const Rational& r2); 

/*	function: overload == operator that returns true if value of first rational object is equal
	to value of second rational object
	return: boolean value, true if values equal, false if not
	parameters: const values, addresses of 2 rational objects being compared
*/
bool operator==(const Rational& r1, const Rational& r2);

/* function: overload less than operator that compares 2 rational objects to see if val of first is less than val
			of second
	returns: boolean value, true if first value < second value, false if not
	parameters: const values, addresses of 2 rational objects being compared

*/
bool operator<(const Rational& r1, const Rational& r2);

/* function: overload less than or equal to operator and compare 2 rational objects. Return true if 
			first value is less than or equal to second. Taking in 2 rational object values as parameters.
*/
bool operator<= (const Rational& r1, const Rational& r2);

/*function: overload greater than operator. Returns true if value of first parameter is greater than
			second parameter value. Takes in 2 rational object values as parameters.
*/
bool operator> (const Rational& r1, const Rational& r2);

/* function: overload greater than or equal to operator. Returns true if value of first parameter is
			greater than or equal to value of second operator. Taking in 2 rational object values as
			parameters. */
bool operator>= (const Rational& r1, const Rational& r2);


Rational operator>>(const Rational& r1, const Rational& r2);
Rational operator<<(const Rational& r1, const Rational& r2);

/*function: computes greatest common denominator for 2 numbers using Euclidian method.
  returns: int value of the greatest common divisor
  parameters: two integer values who's GCD will be found
*/
int getGCD(int num1, int num2);

/* function: if a value within a fraction is negative, places negative sign on numerator. It also
			simplifies fraction to its reduced form by dividing numerator and denominators by the GCD.
	parameters: address of denominator and numerator
*/
void normalize(int& num, int& den);


int main(int argc, char* argv[]) {


	Rational r1(1,4);
	Rational r2(2, 4);
	cout << "Rational r1: ";
	r1.display();
	cout << "GCD: "<<getGCD(r1.getNumerator(), r1.getDenominator());

	cout << "\nRational r2: ";
	r2.display();
	cout <<"GCD: "<<getGCD(r2.getNumerator(), r2.getDenominator());


	Rational addedResult = r1 + r2;
	cout << "\nAdded values of r1 and r2: ";
	addedResult.display();


	Rational result = r1 - r2;
	cout << "\nSubtracting value of rational 2 from rational 1: ";
	result.display();

	int compareVal = 0;

	cout << "Is r1 greater than r2? ";
	if (r1 > r2) {
		compareVal = 1;
	}
	cout << compareVal << endl;


	cout << "Is r1 greater than or equal to r2? ";
	if (r1 >= r2) {
		compareVal = 1;
	}
	cout << compareVal << endl;



	cout << "Is r1 less than to r2? ";
	if (r1 < r2) {
		compareVal = 1;
	}
	cout << compareVal << endl;
	

	cout << "Is r1 less than or equal to r2? ";
	if (r1 <= r2) {
		compareVal = 1;
	}
	cout << compareVal << endl;


	return 0;
}


void Rational:: display(void) {
	cout << numerator <<"/"<< denominator<<endl;
}

int Rational::getNumerator(void) const {
	return numerator;
}

int Rational::getDenominator(void)const {
	return denominator;
}

Rational::Rational() {
	numerator = 0;
	denominator = 1;
}
Rational::Rational(int wholeNumber) {
	numerator = wholeNumber;
	denominator = 1;
}
Rational::Rational(int topVal, int bottomVal) {
	numerator = topVal;
	while (bottomVal == 0) {
		cout << "Please enter a non-zero denominator value:" << endl;
		cin >> bottomVal;
	}
	denominator = bottomVal;

}

Rational operator+(const Rational& r1, const Rational& r2) {
	int newNum = (r1.getNumerator() * r2.getDenominator()) + r1.getDenominator() * r2.getNumerator();
	int newDen = r1.getDenominator() * r2.getDenominator();

	int gcdVal = getGCD(newNum, newDen);
	
	normalize(newNum, newDen);

	Rational result(newNum, newDen);
	return result;

}

Rational operator-(const Rational& r1, const Rational& r2) {
	int newNum = (r1.getNumerator() * r2.getDenominator()) - r1.getDenominator() * r2.getNumerator();
	int newDen = r1.getDenominator() * r2.getDenominator();

	int gcdVal = getGCD(newNum, newDen);
	normalize(newNum, newDen);
	Rational result(newNum, newDen);

	return result;
}

bool operator==(const Rational& r1, const Rational& r2) {
	if ((r1.getDenominator() * r2.getNumerator()) == r1.getNumerator() * r2.getDenominator()) {
		return true;
	}
	else
		return false;

}

bool operator<(const Rational& r1, const Rational& r2) {
	
	double rationalDecimal1 = r1.getNumerator() / r1.getDenominator();
	double rationalDecimal2 = r2.getNumerator() / r2.getDenominator();

	if (rationalDecimal1 < rationalDecimal2)
		return true;
	else
		return false;
}


bool operator<=(const Rational& r1, const Rational& r2) {
	double rationalDecimal1 = r1.getNumerator() / r1.getDenominator();
	double rationalDecimal2 = r2.getNumerator() / r2.getDenominator();

	if (rationalDecimal1 <= rationalDecimal2)
		return true;
	else
		return false;
}
bool operator>(const Rational& r1, const Rational& r2) {
	double rationalDecimal1 = r1.getNumerator() / r1.getDenominator();
	double rationalDecimal2 = r2.getNumerator() / r2.getDenominator();
	
	if (rationalDecimal1 > rationalDecimal2)
		return true;
	else
		return false;

}

bool operator>=(const Rational& r1, const Rational& r2) {
	double rationalDecimal1 = r1.getNumerator() / r1.getDenominator();
	double rationalDecimal2 = r2.getNumerator() / r2.getDenominator();

	if (rationalDecimal1 >= rationalDecimal2)
		return true;
	else
		return false;
}


int getGCD(int integer1, int integer2) {
	int divisor;
	int dividend;
	int remainder = 1;
	int GCDval;
	if (integer1 < integer2) {
		divisor = integer1;
		dividend = integer2;
	}
	else if (integer2 < integer1) {
		divisor = integer2;
		dividend = integer1;
	}
	else if (integer1 == integer2) {
		GCDval = integer1;
		return GCDval;
	}

	while (remainder > 0) {
		remainder = dividend % divisor;

		if (remainder == 0) {
			return divisor;
		}

		dividend = divisor;
		divisor = remainder;
	}
	
	return divisor;
}


void normalize(int& num, int& den) {
	if (den < 0) {
		den = -den;
		num = -num;
	}

	int GCD = getGCD(num, den);
	num = num / GCD;
	den = den / GCD;
}






/*Rational operator>>(const Rational& r1, const Rational& r2) {


}

Rational operator<<(const Rational& r1, const Rational& r2) {

}*/
