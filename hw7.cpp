/***********************************************
Author: Saema Nazar
Date: 3/29/20
Purpose: read from a file the names of movies and ratings for those movies.
		implement a map which will store the movie names as keys and ratings for
		movies as values. Compute average rating for each movie at end.
Sources of Help: lecture slides, cplusplus.com
Time Spent: 1 day

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
Date:	3/29/20
Name: Saema Nazar
***********************************************/


#include <iostream>
#include <cstdio>
#include <map>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[]) {
	
	ifstream inStream;
	inStream.open("HW07.txt");
	int numReviews = 0;

	if (inStream.fail())
	{
		cout << "Error: Could not open file." << endl;
		exit(1);
	}

	//read first value in file and input it as the number of reviews in the file
	inStream >> numReviews;
	string movieName; 
	int rating = 0;

	//declare map with string key and vector value.
	//string is the name of the movie
	//vector contains integer values of the ratings given to the movie it associates with
	map<string, vector<int>> movie_ratings;
	
	//loop to read each movie and review. Repeats numReviews amount of times
	for (int i = 0; i < numReviews; i++) {
		//read string of movie name
		getline(inStream, movieName);
		getline(inStream, movieName);
		
		//read rating given to that movie
		inStream >> rating;

		///check if movie exists in map
		//if movie already exists in the map, add the new rating to the vector associated with the movie
		if ((movie_ratings.find(movieName) != movie_ratings.end())) {
			movie_ratings[movieName].push_back(rating);
		}

		//if movie does not exist in map, insert it into map and pushback rating onto its associated vector
		else {
			movie_ratings[movieName];
			movie_ratings[movieName].push_back(rating);
		}
		
	}
	int sum = 0;
	double avg = 0;

	//iterate through map keys
	for(auto p = movie_ratings.begin(); p!=movie_ratings.end();p++){
		cout << (*p).first<<":\t ";
	
		//iterate through vector associated with key, add values in vector to find sum of ratings
		for (int i = 0; i < (*p).second.size(); i++) 
		{		
			sum = sum + (*p).second.at(i);
		}
		//if movie has >1 review, output the plural of review
		if ((*p).second.size() > 1) 
		{
			cout << (*p).second.size() << " reviews, ";
		}
		else 
		{
			cout << (*p).second.size() << " review, ";
		}

		//compute average by dividing sum by the # of reviews for that movie
		avg = static_cast<double>(sum)/ (*p).second.size();

		//set decimal precision of average to 2
		cout<< "average of " << setprecision(2)<<avg << " / 5" << endl;

		sum = 0;
	}

	
	inStream.close();
	return 0;
}