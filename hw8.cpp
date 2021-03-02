/***********************************************
Author: Saema Nazar
Date: 4/4/20
Purpose: create base vehicle class with truck derived class and create test cases
		ensuring proper function of constructors/operator overloads/etc
Sources of Help: cplusplus.com, lecture slides
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
Date: 4/4/20
Name: Saema Nazar
*/


#include <iostream>
#include <cstdio>
#include <string>

using namespace std;


class Person
{
public:
	//default constructor for Person object
	Person() {
		name = "none";
	}
	//constructor assigning name to Person object
	Person(string theName) {
		name = theName;
	}

	//copy constructor
	Person(const Person& theObject) {
		name = theObject.getName();
	}

	//accessor function 
	string getName(void) const {
		return name;
	}
	
	//copy assignment overload function 
	Person& operator=(const Person& rtSide) {
		name = rtSide.name;
		return *this;
	}

	//>> operator overload
	friend istream& operator >>(istream& inStream, Person& personObject) {
		getline(cin, personObject.name);
		return inStream;
	}

	//<< operator overload
	friend ostream& operator <<(ostream& outStream, const Person&
		pObject) {
		cout << pObject.name;
		return outStream;
	}
private:
	string name;
};


class Vehicle {
public:
	//default constructor to initialize Vehicle object
	Vehicle(){
		manufacturerName = "Unknown Manufactory";
		numCylinders = 0;
		Person owner("Unknown Owner");
	}

	//constructor for Vehicle object taking arguments
	Vehicle(string mfName, int cyls, Person theOwner) {
		manufacturerName = mfName;
		numCylinders = cyls;
		owner = theOwner;
	}
	//copy constructor
	Vehicle(const Vehicle& vehicleObj) {
		manufacturerName = vehicleObj.manufacturerName;
		numCylinders = vehicleObj.numCylinders;
		owner = vehicleObj.owner;
	}

	//getters
	string getManufName(void)const{
		return manufacturerName;
	}
	int getNumCyl(void)const {
		return numCylinders;
	}
	
	Person getOwner(void)const {
		return owner;
	}

//insertion << operator overload
	friend ostream& operator <<(ostream& outStream, Vehicle vehicleObj) {
		cout << vehicleObj.manufacturerName << ", ";
		return outStream;
	}

protected:
	string manufacturerName;
	int numCylinders;
	Person owner;
};


//derived class
class Truck : public Vehicle {
public:
	//default constructor to initialize Truck object, also explicitly calling Vehicle class constructor
	Truck():Vehicle(){
		towCapacityLbs = 0;
		loadCapacityTons = 0;
	}

	//constructor for Truck class taking arguments, also calling arg constructor for Vehicle parent class
	Truck(string name, int cyls, Person ownerName, double loadCapTons, int towCapLbs):Vehicle(name, cyls, ownerName){
		loadCapacityTons = loadCapTons;
		towCapacityLbs = towCapLbs;
	}

	//getters
	double getLoadCap(void)const {
		return loadCapacityTons;
		}
	int getTowCap(void)const {
		return towCapacityLbs;
	}

	//copy constructor
	Truck(const Truck& truckObj) {
		manufacturerName = truckObj.manufacturerName;
		numCylinders = truckObj.numCylinders;
		owner = truckObj.owner;
		loadCapacityTons = truckObj.loadCapacityTons;
		towCapacityLbs = truckObj.towCapacityLbs;
	}

	// = operator overload
	Truck& operator=(const Truck& truckObj) {
		manufacturerName = truckObj.manufacturerName;
		numCylinders = truckObj.numCylinders;
		owner = truckObj.owner;
		loadCapacityTons = truckObj.loadCapacityTons;
		towCapacityLbs = truckObj.towCapacityLbs;

		return *this;
	}

private:
	double loadCapacityTons;
	int towCapacityLbs;
};



int main(int argc, char* argv[]) {

	cout << "///////////////// Testing Person Class ////////////////" << endl;
	Person person1;
	Person person2("Sirong Lin");
	cout << "Testing default constructor: the person is: " << person1.getName() << endl;
	cout << "Testing constructor(string): I am: " << person2.getName() << endl;

	Person person3(person2);
	cout << "Testing copy constructor: another me is: " << person3.getName() << endl;

	cout << "Testing >> overloading: Enter your name: ";
	cin >> person1;
	cout << "You're: " << person1.getName() << endl;

	person2 = person1;
	cout << "Testing = overloading: Another you is: " << person2.getName() << endl;





	cout << "\n///////////////// Testing Vehicle Class ////////////////" << endl;
	Vehicle v1;
	cout << "Testing default constructor: The Vehicle is: \n\t"<< v1.getManufName()
		<< ", " << v1.getNumCyl() << " cylinders, belongs to: " << v1.getOwner() << endl;
	
	Person p4("Sirong Lin");
	Vehicle v2("Ford Van", 8, p4);
	cout<<"Testing constructor(args): for my car:\n\t"<< v2.getManufName()
		<< ", " << v2.getNumCyl() << " cylinders, belongs to: " << v2.getOwner() << endl;
	
	Vehicle v3(v2);
	cout<<"Testing copy constructor: my second same car:\n\t"<< v3.getManufName()
		<< ", " << v3.getNumCyl() << " cylinders, belongs to: " << v3.getOwner() << endl;
	
	Person p5("James Smith");
	Vehicle v4("Ford", 6, p5);
	v3 = v4;
	cout << "Testing = overloading:\n\t";
	cout << "Your Car is: " << v3.getManufName() << ", " << v3.getNumCyl() << " cylinders, belongs to: "
		<< v3.getOwner() << endl;
	cout << "\tYourSecondCar is: " << v4.getManufName() << ", " << v4.getNumCyl() << " cylinders, belongs to: "
		<< v4.getOwner() << endl;



	cout << "\n///////////////// Testing Truck Class ////////////////" << endl;
	Truck truck1;
	cout << "Testing default constructor: the Truck is: \n\t" <<
		truck1.getManufName() << ", " << truck1.getNumCyl() << " cylinders, belongs to: "
		<< truck1.getOwner() << ", load capacity: " << truck1.getLoadCap() << ", " <<
		"towing capacity: " << truck1.getTowCap() << endl;
	
	Person t2Owner("Mike Elf");
	Truck truck2("Mac", 8, t2Owner, 250, 2000);
	cout << "Testing constructor(args): for a truck: \n\t" <<
		truck2.getManufName() << ", " << truck2.getNumCyl() << " cylinders, belongs to: "
		<< truck2.getOwner() << ", load capacity: " << truck2.getLoadCap() << ", " <<
		"towing capacity: " << truck2.getTowCap() << endl;

	
	Truck truck3("Toyota Truck", 8, p5, 200, 5000);
	truck2 = truck3;

	cout << "Testing = overloading\n\t";
	cout<< "hisTruck is: "<< truck2.getManufName() << ", " << truck2.getNumCyl() << " cylinders, belongs to: "
		<< truck2.getOwner() << ", load capacity: " << truck2.getLoadCap() << ", " <<
		"towing capacity: " << truck2.getTowCap() << endl;
	cout<<"\this same Truck is: "<< truck3.getManufName() << ", " << truck3.getNumCyl() << " cylinders, belongs to: "
		<< truck3.getOwner() << ", load capacity: " << truck3.getLoadCap() << ", " <<
		"towing capacity: " << truck3.getTowCap() << endl;

	return 0;
}