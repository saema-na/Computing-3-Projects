/***********************************************
Author: Saema Nazar
Date: 1/31/2020
Purpose: chooses a random value within a user-defined range and allows the user to guess what the value is
Sources of Help: PPTs from lecture
Time Spent: ~3 hrs

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
Date: 1/31/2020
Name: Saema Nazar
***********************************************/

#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std;

//function: obtains a max value from the user that is within range (greater than min, less than 1000)
//parameters: address of variable "max" (using pass-by-reference), and variable "min" to use for verifying appropriate max value
void getMax(int& max, int min);

//function: obtains a valid minimum value from the user
//paramters: address of variable containing minimum value
void getMin(int& min);

//function: obtains the number of guesses that the user would like
//parameters: address of variable containing the number of guesses (using pass-by-reference)
void getNumGuesses(int& numGuesses);

//function:	compares the users guess with the correct value and displays clues to user if their guess is incorrect
//parameters: variable "guess" containing user's guess, and variable "actual" containing the correct value
//return value: returns 1 if user's guess is correct, 0 if their guess is incorrect
int checkGuess(int guess, int actual);



int main(int argc, char* argv[]) 
{
	int max;
	int min;
	int numGuesses;
	int guess;
	int guessCorrect;
	int correctGuess;
	char playAgain = 'y';
	int nthGuess = 0;
	int correct_boolean = 0;


	cout << "************ Welcome to the Game! ************\nFirst, let's set up the game.\n";
	
	getMin(min);
	getMax(max, min);
	getNumGuesses(numGuesses);
	

	while (playAgain == 'y') 
	{
		srand(time(0));
		correctGuess = (rand() % max) + min;
		cout << "Now, I have a number between " << min << " and " << max << ". Can you guess my number? Please type your first guess.\n";
		nthGuess = 0;
		correct_boolean = 0;
		while (nthGuess < numGuesses && correct_boolean == 0) 
		{
			cin >> guess;
			correct_boolean = checkGuess(guess, correctGuess);
			nthGuess++;
		}
			if (correct_boolean == 1) 
			{
				cout << "Excellent! You guessed the number!" << endl;
			}
			if (correct_boolean == 0) 
			{
				cout << "Sorry, you can't guess any more. The number is: " << correctGuess << endl;
			}

		cout << "Would you like to play again (y or n)?";
		cin >> playAgain;
	}	

	return 0;
}

int checkGuess(int guess, int actual) 
{
	if (guess == actual) 
	{
		return 1;
	}

	if (guess > actual) 
	{
		cout << "Too high!" << endl;
	}
	if (guess < actual) 
	{
		cout << "Too low!" << endl;
	}
	return 0;
}

void getMin(int& min) 
{
	cout << "Please enter a minimum number, a positive integer:\n";
	cin >> min;
	while (min < 0) 
	{
		cout << "Please enter a number greater than 0:\n";
		cin >> min;
	}
}

void getMax(int& max, int min) 
{
	cout << "Please enter the maximum number, a positive integer: " << endl;
	cin >> max;
	while (max < min || max > 1000) 
	{
		cout << "Please enter a number greater than the minimum value and less than 1000:\n";
		cin >> max;
	}
}

void getNumGuesses(int& numGuesses)
{
	cout << "Please enter the number of guesses allowed (less than 10):\n";
	cin >> numGuesses;

	while (numGuesses <= 0 || numGuesses > 10) 
	{
		cout << "Please enter a number greater than 0 and less than 10:\n";
		cin >> numGuesses;
	}
}