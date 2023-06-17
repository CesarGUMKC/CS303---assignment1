#include <iostream>
#include <fstream>
#include <string>
#include "Functions.h"

using namespace std;


void modifyArray(int* array) {                                       //function to modify an index value to new user inputed value

	int number, newNum;

	cout << "Enter index you want to change: ";
	cin >> number;

	int val = array[number];

	cout << endl << "What would you like to change it to?: ";
	cin >> newNum;

	array[number] = newNum;

	cout << "The new value has been changed from " << val << " to " << newNum << ".";


}

void addToArray(int* array) {          //adds new value to end of array

	int number, endIndex;

	cout << "Enter integer: ";
	cin >> number;

	for (int i = 0; i < 150; i++) {

		if (array[i] == 0) {

			endIndex = i;
			array[endIndex] = number;
			break;
		}

	}
}

void valResetArray(int* array) {      //resets an a value of an index provided by user to 0

	int number;

	cout << "Enter index: ";
	cin >> number;

	array[number] = 0;


}












int main()
{
	string userFile, currVal, userInput;                      //variable declaration
	int array[150], number;
	bool inArray;

	for (int i = 0; i < 150; i++) {                   //set array to size of 150 elements of zero
		
		array[i] = 0;
	
	}


	cout << "Enter the name of the file you want to read(include '.txt'): ";                //ask user file what they would like to read and insert into array
	cin >> userFile;

	ifstream fin(userFile);
	if (!fin.is_open()) {
		cout << "Error. File is not open." << endl;
		return 1;
	}

	int position = 0;

	while (fin.good()) {                                     //inserts values from file into array

		fin >> currVal;
		array[position] = stoi(currVal);

		position += 1;
	}

	cout << "Would you like to check for a certain integer?(Y/N): ";            //asks user to see if a value is in array
	cin >> userInput;
	
	int valid = 0;

	while (valid == 0) {

		if ((userInput == "Y") || (userInput == "y")) {

			valid = 1;

			cout << "What number: ";
			cin >> number;

			inArray = false;

			for (int i = 0; i < 150; i++) {

				if (array[i] == number) {

					inArray = true;
					position = i;
				}

			}

			if (inArray == true) {

				cout << "The number is present and is in index " << position << " of the array.";

			}

			else {

				cout << "Number is not present.";

			}

		}

		else if ((userInput == "N") || (userInput == "n")) {
			
			valid = 1;

		}

		else {
			
			cout << endl << "Invalid input, please enter 'y' or 'n': ";
			cin >> userInput;

		}
	}

	cout << endl << "Would you like to change a value in the array?(Y/N): ";                 //asks user if they would like to modify an index value 
	cin >> userInput;
	
	valid = 0;

	while (valid == 0) {

		if ((userInput == "Y") || (userInput == "y")) {

			valid = 1;

			modifyArray(array);

		}

		else if ((userInput == "N") || (userInput == "n")) {

			valid = 1;

		}

		else {

			cout << endl << "Invalid input, please enter 'y' or 'n': ";
			cin >> userInput;

		}
	}

	
	cout << endl << "Would you like to add an integer to the end of the array?(Y/N): ";           //asks user if they would like to add value to end of array
	cin >> userInput;

	valid = 0;

	while (valid == 0) {

		if ((userInput == "Y") || (userInput == "y")) {

			valid = 1;

			addToArray(array);

		}

		
		else if ((userInput == "N") || (userInput == "n")) {

			valid = 1;

		}

		else {

			cout << endl << "Invalid input, please enter 'y' or 'n': ";
			cin >> userInput;

		}
	}


	cout << endl << "Would you like to reset a value of an index in the array?(Y/N): ";               //asks user if they would like to resets index value to zero
	cin >> userInput;

	valid = 0;

	while (valid == 0) {

		if ((userInput == "Y") || (userInput == "y")) {

			valid = 1;

			valResetArray(array);

		}


		else if ((userInput == "N") || (userInput == "n")) {

			valid = 1;

		}

		else {

			cout << endl << "Invalid input, please enter 'y' or 'n': ";
			cin >> userInput;

		}
	}


	cout << endl << endl << "Thanks!";
}

