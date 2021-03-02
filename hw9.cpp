/***********************************************
Author: Saema Nazar
Date: 4/12/20
Purpose: number guessing game with human and computer player derived classes 
Sources of Help: lecture slides, cplusplus.com
Time Spent: 2 hrs

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
Date: 4/12/20
Name: Saema Nazar
*/


#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

class Player {
public:
    virtual int getGuess(void)const {
        return 0;
    }

    //virtual function that takes in arrays of guess/result for both players
    virtual void boundsAdjust(int arr[], int arr2[]) {
        return;
    }
};
	
class HumanPlayer :public Player {
public: 
	int getGuess(void)const override {
        int guess;
		cin >> guess;
        return guess;
	}	
};

class ComputerPlayer : public Player {
public:
	int getGuess(void)const override{
        int guess;
        srand(time(NULL));
       
        guess = (rand() % (upper - lower - 1)) + lower + 1;
        cout << " The computer guesses " << guess << endl;
        return guess;
	}

    //adjusts bounds computer player uses based on the recent guesses of itself and the other player
    void boundsAdjust(int arr[], int arr2[])override{
        if (arr[0] < upper && arr[0] > lower){
            if (arr[1] == 1) {
                lower = arr[0];
            }
            if (arr[1] == 0) {
                upper = arr[0];
            }
        }
        if (arr2[0] < upper && arr2[0] > lower) {
            if (arr2[1] == 1) {
                lower = arr2[0];
            }
            if (arr2[1] == 0) {
                upper = arr2[0];
            }
        }
    }

    void reset(void) {
        lower = 0;
        upper = 99;
    }

private:
        int lower = 0; 
        int upper = 99;
};


bool checkForWin(int guess, int answer)
{
    if (answer == guess)
    {
        cout << "You're right! You win!" << endl;
        return true;
    }
    else if (answer < guess)
        cout << "Your guess is too high." << endl;
    else
        cout << "Your guess is too low." << endl;
    return false;
}
// The play function takes as input two Player objects.
void play(Player& player1, Player& player2) {
    int answer = 0, guess = 0;
    answer = rand() % 100;
    bool win = false;
    int p1[2] = { -1, -1 };//[0] stores recent guess, [1] stores bool val indicating if guess is higher/lower than bound
    int p2[2] = { -1, -1 };

    while (!win)
    {
        cout << "Player 1's turn to guess." << endl;
        
        player1.boundsAdjust(p1, p2);
        guess = player1.getGuess();
        p1[0] = guess;
        p1[1] = guess > answer;

        
        win = checkForWin(guess, answer);
        if (win) return;

        cout << "Player 2's turn to guess." << endl;

        player2.boundsAdjust(p1, p2);
        guess = player2.getGuess();
        p2[0] = guess;
        p2[1] = guess > answer;

        win = checkForWin(guess, answer);
    }
}

int main(int argc, char* argv[]) {
    HumanPlayer hp1;
    HumanPlayer hp2;
    ComputerPlayer cp1;

    play(hp1, hp2);
    play(hp1, cp1);
    cp1.reset();


	return 0;
}