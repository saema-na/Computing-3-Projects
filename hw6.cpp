/***********************************************
Author: Saema Nazar
Date: 3/7/20
Purpose: create a class called DynamicStringArray which performs the actions of
		a vector of strings. Contain member functions that allow adding/deleting/
		getting entries.
Sources of Help: cpp.com, lecture notes
Time Spent: 1 day
/////
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
Date: 3/7/20
Name: Saema Nazar

*/

#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;


class DynamicStringArray {
public:
	//function: default constructor setting array to nullptr and size = 0
	DynamicStringArray();

	//**copy constructor making copy of input object's dynarray	**
	DynamicStringArray(const DynamicStringArray& arr);

	//function: returns int value of private member variable size, takes no input
	int getSize(void)const;

	//function: adds string to dynamic array by creating new, larger array, copying old array to
			//	larger array, and adding new entry to the end
	//parameter: string being added to dynamic array
	void addEntry(string newString);

	//function: deletes entry from dynamic array by checking if there is a string in dynamic array that matches
	//			string input. If match is found, new smaller array is created and all elements except for matching
	//			string is copied into new array.
	//parameter: string that is being deleted
	//returns:	true if match is found and entry is deleted, false if no match found
	bool deleteEntry(string newString);

	//function: takes integer parameter of an index in the dynamic array and returns string located at that index
	string getEntry(int index)const;

	//function: copy assignment operator overload that allows object of dynamicstringarray class to be copied
	//parameter: reference to the target object, the object being copied to
	//returns:	reference to class object
	DynamicStringArray& operator=(const DynamicStringArray& targObj);

	//destructor that deletes dynamicstringarray object
	~DynamicStringArray();

private:
	int size;
	string* dynamicArray;

};

int main(int argc, char* argv[]) 
{
	DynamicStringArray test1;

	cout << "Size of declared DynamicStringArray Object: " << test1.getSize() << endl;

	test1.addEntry("apple");

	test1.addEntry("zebra");

	cout << "Size of DynamicStringArray Object after adding 2 entries: " << test1.getSize() << endl<<endl;

	cout << "Getting entry at index 1: " << test1.getEntry(1) << endl;

	cout << test1.deleteEntry("zebra") << endl<<endl;
	cout << "Size of DynamicStringArray Object after deleting 1 entry: " << test1.getSize() << endl;
	
	test1.addEntry("zebra");
	test1.addEntry("aardvark");
	test1.addEntry("elephant");

	DynamicStringArray arrCopy;
	arrCopy = test1;
	cout << "Entry at index 0 of arrCopy after using = operator overload: " << arrCopy.getEntry(0) << endl;
	
	//copy constructor implementation
	DynamicStringArray copyConstTest1(test1);
	cout << "\nAfter using copy constructor to copy test1 to copyConstTest1:\n";
	cout << "test1 index 0: " << test1.getEntry(0)<< "\t\t\ttest1 index 1: "<< test1.getEntry(1) <<endl;
	cout << "copyConstTest1 index 0: " << copyConstTest1.getEntry(0) << "\t\tcopyConstTest1 index 1: " << copyConstTest1.getEntry(1) <<endl;


	return 0;
}

DynamicStringArray::DynamicStringArray() 
{
	size = 0;
	dynamicArray = nullptr;
}

int DynamicStringArray::getSize(void)const
{
	return size;
}

void DynamicStringArray::addEntry(string newString){
	string* newArr;
	newArr = new string[size + 1];
	int i = 0;

	//copying elements into new array
	for (i = 0; i < size; i++) {
		newArr[i] = dynamicArray[i];
	}
	//adding newString to end of newArr and reassigning newArr
	size++;
	newArr[i] = newString;
	delete[] dynamicArray;
	dynamicArray = newArr;
}



bool DynamicStringArray::deleteEntry(string newString) 
{
	int i;
	int match = 0;

	//if iterate through entire array without finding match, noMatch should == size
	for (i = 0; i< size; i++) {
		if (dynamicArray[i] == newString) {
			//match is equal to the index where matching string is located in dynArray
			match = i;
		}
	}

	//if no match found:
	if (match == 0) 
	{
		return false;
	}

	//IF MATCH IS FOUND:
	//create new array one smaller than old array
	string* newArr;
	newArr = new string[size - 1];
	int j = 0;
	//copy all elements except match index to new array
	for (i = 0; i < size-1; i++) {
		if (i == match) {
			i++;
		}
		newArr[j] = dynamicArray[i];
		j++;
	}
	delete[] dynamicArray;
	size--;
	dynamicArray = newArr;

	return true;
}

string DynamicStringArray::getEntry(int index)const
{
	if ((index < 0) || (index > size - 1)) {
		return nullptr;
	}

	return dynamicArray[index];
}

//destructor
DynamicStringArray::~DynamicStringArray() {
	delete[] dynamicArray;
}

//= operator overload
DynamicStringArray& DynamicStringArray::operator=(const DynamicStringArray& targObj){
	int i = 0;
	if (this == &targObj) {
		return *this;
	}

	delete[] dynamicArray;
	size = targObj.getSize();
	dynamicArray = new string[size];

	for(i = 0; i<size-1; i++)
	{
		dynamicArray[i] = targObj.getEntry(i);
	}

	return *this;
}


DynamicStringArray::DynamicStringArray(const DynamicStringArray& arr) {

	size = arr.getSize();
	string* tmp = new string[size];

	//copy elements
	for (int i = 0; i < size; i++) {
		tmp[i] = arr.getEntry(i);
	}
	dynamicArray = tmp;
}
