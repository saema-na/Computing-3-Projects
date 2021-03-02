/* //#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

const int MAX_NUM_DICE = 5;
using namespace std;


int main(int argc, char* argv[]) {
	int numDice = 0;
	int i;
	int* dieValue = 0;
	int sum = 0;
	double avg = 0.00;
	std::cout << "Please enter the number of dice (2-5): "
		//scanf("%d", &numDice);
		std::cin >> numOfDice;

	while (numDice > 5 || numDice < 2) {
		std::cout << "Please enter the number of dice (2-5): "
			//scanf("%d", &numDice);
			std::cin >> numDice;
	}

	dieValue = (int*)malloc(numDice * sizeof(int));
	srand(time(0));

	for (i = 0; i < numDice; i++) {
		dieValue[i] = (rand() % (5 + 1)) + 1;
	}

	for (i = 0; i < numDice; i++) {
		sum = sum + dieValue[i];
	}

	avg = (double)sum / (double)numDice;


	printf("Dice Values:\n");
	for (i = 0; i < numDice; i++) {
		printf("%d ", dieValue[i]);
	//c++ version:
		std::cout << "die value: "
		std::cout << dieValue[i];
		std::cout<<std::endl;	//new line character

		//OR: std::cout <<"die value: " << dieValue[i]<<std::endl;

	}
	//printf("\nSum: %d\nAverage: %.2lf\n", sum, avg);
	std::cout << "Sum: " << sum << ", Average: " << average << std::endl;
	

	return 0;
}
*/


/*
#include <iostream>
#include <ctime>
#include <cstdlib>

const int MAX_NUM_DICE = 5;
const int MIN_NUM_DICE = 2;
const int SIDES = 6;

int main(int argc, char* argv[]) {
	int numOfDice;

	while (numOfDice < MIN_NUM_DICE || numOfDice > MAX_NUM_DICE) {

		//fucntion that generataes output
		std::cout << "Please enter the number of dice (2-5): "


	}



}*/