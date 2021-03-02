// README: not finished

/***********************************************
Author: Saema Nazar
Date: 2/12/2020
Purpose: when finished, this program should use class structure to read
		a zipcode from main and then encode/decode it to barcode format or
		as an integer. Should also verify that zipcode inputs are valid
		and follow the correct format
Sources of Help: lectures from lab, cplusplus.com
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
Date: 2/12/2020
Name: Saema Nazar
*/




#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

class ZipCode
{
public:
	//Constructor that takes barcode in as a string and converts to an integer value to be stored
	//in private member variable
	ZipCode(string barcode);

	//Constructor that takes zipcode and stores it in private member variable
	ZipCode(int zipcode);


	//accessor function which obtains value of private int member variable iZipCode and returns int
	int getZipCode(void)const;

	//accessor function which takes int variable iZipCode, converts to string/barcode format, and returns string to main
	string getBarCode(void)const;

private:
	int iZipCode = 0;

	//contains possible values of each digit in zipcode from 11 to 9, used as a key to convert from integer to string barcode representation
	string moddedZip[10] = { "11000", "00011", "00101", "00110", "01001", "01010", "01100", "10001", "10010", "10100" };
};



int main(int argc, char* argv[]) {
	ZipCode zip(99504),
		zip2("100101010011100001100110001"),
		zip3(12345),
		zip4(67890);

	cout << zip.getZipCode() << "'s bar code is '"
		<< zip.getBarCode() << "'" << endl;
	cout << zip2.getZipCode() << "'s bar code is '"
		<< zip2.getBarCode() << "'" << endl;
	cout << zip3.getZipCode() << "'s bar code is '"
		<< zip3.getBarCode() << "'" << endl;
	cout << zip4.getZipCode() << "'s bar code is '"
		<< zip4.getBarCode() << "'" << endl;

	cout << endl;

	// Test a range of values by first constructing a zip code
	// with an integer, then retrieving the bar code and using
	// that to construct another ZipCode.
	int zip_int = 0;
	for (int i = 0; i < 25; i++)
	{
		// Make an aribrary 5-digit zip code integer, and use it
		// to construct a ZipCode
		int five_digit_zip = (zip_int * zip_int) % 100000;
		ZipCode z1(five_digit_zip);

		// Construct a second ZipCode from the first's bar code
		string z1_barcode = z1.getBarCode();
		ZipCode z2(z1_barcode);

		cout.width(3);
		cout << (i + 1) << ": ";
		cout.width(5);
		cout << z2.getZipCode() << " has code '"
			<< z1_barcode << "'";

		if ((z1_barcode == z2.getBarCode()) &&
			(z1.getZipCode() == z2.getZipCode()) &&
			(z2.getZipCode() == five_digit_zip))
		{
			cout << " [OK]" << endl;
		}
		else
		{
			cout << " [ERR]" << endl;
		}

		// Increment the test value arbitrarily
		zip_int += (233 + zip_int % 7);
	}
	cout << endl;

	// Test some error conditions. This test assumes that
	// ZipCode will simply set its value to a flag that indicates
	// an error, and will not exit the program.
	int BAD_ZIP_COUNT = 2;
	string bad_zips[][2] = {
		{ "100101010011100001100110000", "bad start/end character" },
		{ "100101010011100001100110021", "bad digit" },
	};
	for (int i = 0; i < BAD_ZIP_COUNT; i++)
	{
		cout << "Testing: " << bad_zips[i][1] << " " << bad_zips[i][0] << endl;
		ZipCode test(bad_zips[i][0]);
		cout << endl;
	}

	cout << "Enter a character to quit." << endl;
	char c;
	cin >> c;
	return 0;
}



//CONSTRUCTOR 1
//take in barcode string and convert into integer
ZipCode::ZipCode(string barcode) {
	//check for valid zipcode --> first and last must == 1
	if (barcode[0] != '1' || barcode[26] != '1')
	{
		cout << "Wrong start/end character in the barcode!\n";
		iZipCode = 0;
	}

	else
	{
		int index = 1;
		//split 25 digits into 5 groups
		for (int i = 4; i >= 0; i--) {

			int sum = 0;

			//read each digit in a group and assign int value based on index location in group array
			for (int k = 0; k < 5; k++) {

				int tmp = barcode[index] - '0';

				if (tmp != 1 && tmp != 0) {
					cout << "Bad digit read\n";
				}

				//assign sum based on index value
				if (k == 0)
				{
					sum = sum + 7 * tmp;
				}
				if (k == 1)
				{
					sum = sum + 4 * tmp;
				}
				if (k == 2)
				{
					sum = sum + 2 * tmp;
				}
				if (k == 3)
				{
					sum = sum + 1 * tmp;
				}
				if (k == 4)
				{
					sum = sum + 0 * tmp;
				}

				index++;
			}

			if (sum != 11) {
				iZipCode = iZipCode + sum * pow(10, i);
			}
		}
	}
	cout << iZipCode << endl;
}


//CONSTRUCTOR 2
//take in zipcode int and initialize
ZipCode::ZipCode(int zipcode)
{
	iZipCode = zipcode;
}


//return zipcode integer to main
int ZipCode::getZipCode(void)const {
	return iZipCode;
}


////take zipCode int stored internally, convert to string, return to main
string ZipCode::getBarCode(void)const {
	string barString = "1";
	int tmp = iZipCode;
	int num;
	int i;

	for (i = 0; i < 5; i++) {
		num = tmp % 10;

		tmp = tmp / 10;
		barString = moddedZip[num] + barString;
	}
	barString = barString + "1";

	return barString;

}

