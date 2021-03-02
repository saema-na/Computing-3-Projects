/***********************************************
Author: Saema Nazar
Date: 4/27/20
Purpose: implement generate_permutations and print_permutations in givnen driver program to enable program to
         read strings from stdin and output all permutations of inputted strings.
Sources of Help: cplusplus.com, class ppts
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
Date: 4/27/20
Name:
*/


#include <iostream>
#include <algorithm>
#include <list>
#include <sstream>
#include <vector>
using namespace std;

/* Function to print generated permutations
    - parameter: vector of lists of strings, same data type as container that permutations are stored in
*/
void print_permutations(vector<list<string>> permuted){
    for (auto &each:permuted) {             //use nested forloop to print each string(permuation) in each list stored in vector container
        for (auto& each : each) {
            cout << each<<" ";
        }
        cout << endl;
    }
}

/* Function to generate permutations from given list of strings 
    returns vector of list of strings containing all possible permutations of given strings
*/
vector<list<string>> generate_permutations(list<string> inputList){
    auto b = inputList.begin();
    auto e = inputList.end();

    stable_sort(b, e);                      //sort elements in container before using unique() 
    //sort(b, e);                                       //function to ensure all possible duplicates are consecutive

    auto newEnd = unique(inputList.begin(), inputList.end());   //call unique() and store the iterator it returns as newEnd
                                                                //newEnd is the iterator referencing the new end of the list after duplicates are removed
    inputList.resize(distance(b,newEnd));       //list will have new size if duplicates have been removed, resize to ensure no unnecessary memory is still allocated

    vector<list<string>> permuted;              //store permutations of strings in this container
    permuted.push_back(inputList);              //put initial sorted list into vector
    
    while (next_permutation(b, e)) {            //iterate while next_permutation() returns true. Will return true while there is a next higher permuation. 
       permuted.push_back(inputList);      ///pushback permuted list into vector
      }
    
    return permuted;                //return vector of strings to main
}

int main(int argc, char* argv[])
{
    list<string> inputList;
    string aLine, aString;
    // read in strings from stdin
    cout << "Enter strings, separated by a space: ";
    getline(cin, aLine); //read a line from keyboard
    istringstream iss(aLine); //convert aLine to an istringstream obj

        //parse each string
        while (iss >> aString)
        {
            inputList.push_back(aString);
        }

    
    auto permutations = generate_permutations(inputList);

    //call print_permuations on what is returned from generate_permutations() function to print all possible permutations to stdout
    print_permutations(permutations);



    return 0;
}

