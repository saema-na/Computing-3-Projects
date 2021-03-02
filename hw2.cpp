/***********************************************
Author: Saema Nazar
Date: 2/6/2020
Purpose: output text from a .txt file but replace any occurrence of "dislike"
		with "love".
Sources of Help: lecture notes, cplusplus.com reference page on strings
******

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
Date: 2/6/2019
Name: Saema Nazar
*/

#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) 
{
	string wordToReplace = "dislike";
	string word;

	ifstream inFile;

	inFile.open("input.txt");
	if (!inFile.is_open())
	{
		cout << "Error: Cannot open file." << endl;
		exit(1);
	}

	while (inFile >> word) 
	{
		if (word == wordToReplace) 
		{
			word = "love";
		}
		cout << word<< " ";
	}

	inFile.close();


	return 0;
}