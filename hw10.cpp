/***********************************************
Author: Saema Nazar
Date: 4/27/20
Purpose: finish implementation of class that handles dynamic array (implement big 3).
        Add functionality where specified exceptions will be thrown if array is not
        being handled properly
Sources of Help: class lectures, cplusplus.com
Time Spent: 2 hrs
--------                         //RESUBMISSION: added comments and changed PFArrayD(const PFArrayD& pfaObject) function to loop until used value, not capacity


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
Name: Saema Nazar
*/


//
// HW10.cpp
//

#include <iostream>
#include <string>
#include <exception>
using namespace std;

void testPFArrayD(void);

//Exception Class
class OutOfRange {
public:
//OutOfRange exception class constructor. Initializing member variables with value of offending index and string indicating error
    OutOfRange(int index, string msg) {     
        offendingIndex = index;
        errorMsg = msg;
    }

//assigns offending index member variable with given value
    void index(int index) {
        offendingIndex = index;
    }

//function that prints message describing error
    void err(void) {
        cout << errorMsg << " Bad Index: " << offendingIndex << endl;
    }

private:
    int offendingIndex;
    string errorMsg;
};



//Objects of this class are partially filled arrays of doubles.
class PFArrayD
{
public:
 //Initializes with a capacity of 50.
    PFArrayD() {
        used = 0;
        capacity = 50;
        a = new double[capacity];
    }

 //constructor for PFArrayD object initializing capacity with given value and allocating array based on given capacity value
    PFArrayD(int capacityValue) {
        capacity = capacityValue;
        used = 0;
        a = new double[capacity];
    }

 //copy constructor
    PFArrayD(const PFArrayD& pfaObject) {
        capacity = pfaObject.getCapacity();
        used = pfaObject.getNumberUsed();
        a = new double[capacity];
        
        int i;
        for (i = 0; i < used; i++) {
            a[i] = pfaObject.a[i];
        }
    }


    //Precondition: The array is not full.
    //Postcondition: The element has been added.
    void addElement(double element) {       //specification: throw(OutOfRange)
        if (capacity <= used) 
        {
            throw OutOfRange(capacity, "Attempting to write to an out of range index.");    //throw OutOfRange object exception
        }
        *(a + used) = element; 
        used++;
    }

    bool full() const { return (capacity == used); }
    //Returns true if the array is full, false otherwise.

    int getCapacity() const { return capacity; }

    int getNumberUsed() const { return used; }

    void emptyArray() { used = 0; }
    //Empties the array.


    //Read and change access to elements 0 through numberUsed - 1.
    double& operator[](int index) {             //specification: throw(OutOfRange)
            if (index >= used || index < 0) {
                throw OutOfRange(index, "Out of range index attempting to be accessed."); //initialize OutOfRange object and throw it as an exception
            }

        return a[index];
    }

    PFArrayD& operator =(const PFArrayD& rightSide) {
        //if current capacity != capacity being assigned, delete and make 
        // new appropriately sized array
        if (capacity != rightSide.capacity) {
            delete[] a;
            a = new double[rightSide.capacity];
        }

        capacity = rightSide.getCapacity();
        used = rightSide.getNumberUsed();
        for (int i = 0; i < used; i++) {
            a[i] = rightSide.a[i];
        }
        return* this;
    }

//destructor
    ~PFArrayD() {
        delete[] a;
    }

private:
    double* a; //for an array of doubles.
    int capacity; //for the size of the array.
    int used; //for the number of array positions currently in use.

};

//function to test exception class and make sure exceptions are being thrown when they should be
void testException(void);


int main(int argc, char* argv[])
{
    cout << "This program tests the class PFArrayD.\n";

    char ans;
    do
    {
        testPFArrayD();
        testException();
        cout << "Test again? (y/n) ";
        cin >> ans;
    } while ((ans == 'y') || (ans == 'Y'));

    return 0;
}

void testPFArrayD()
{
    int cap;
    cout << "Enter capacity of this super array: ";
    cin >> cap;
    PFArrayD temp(cap);

    cout << "Enter up to " << cap << " nonnegative numbers.\n";
    cout << "Place a negative number at the end.\n";

    double next;
    cin >> next;
    while ((next >= 0) && (!temp.full()))
    {
        temp.addElement(next);
        cin >> next;
    }

    cout << "You entered the following "
        << temp.getNumberUsed() << " numbers:\n";
    int index;
    int count = temp.getNumberUsed();
    for (index = 0; index < count; index++)
        cout << temp[index] << " ";
    cout << endl;
    cout << "(plus a sentinel value.)\n";
}

void testException(void) {
    cout << "TestException Function" << endl << endl;
    int cap;
    double inputVal = 0;
    cout << "Enter a capacity for array to test exception: " << endl;
    cin >> cap;
    PFArrayD temp(cap);                         //<-- initializing PFArrayD object with user given capacity
    cout << "Enter more than " << cap << " nonnegetive numbers\nPlace a negative number at then end.\n";
    cin >> inputVal;                           //<-- asking user to input #of elements greater than available capacity for array
    
    while (inputVal > 0) 
    {
        try {                                //adding elements to array, calling .addElement(). Exception should be thrown in .addElement() that is caught by catch block
            temp.addElement(inputVal);
        }
        catch (OutOfRange ex){              //when exception is caught, error message should be printed
            ex.err();
        }
        cin >> inputVal;
    }
    
    cout << "Accessing invalid index value:" << endl;   //attempting to access an invalid index value using index operator
    try                                             //index operator overload function should throw error message due to attempted invalid index access
    {
        temp[cap];
    }
    catch (OutOfRange ex)                   //exception should be caught by catch block and error msg should be printed
    {
        ex.err();
    }

}
