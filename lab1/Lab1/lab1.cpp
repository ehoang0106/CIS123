#include <iostream>

using namespace std;


int main()
{
	string firstName, lastName;
	int age = 0;
	int numOfDays;

	
	cout << "Enter First name: ";
	cin >> firstName;
	cout << "Enter Last name: ";
	cin >> lastName;
	cout << "Age: ";
	cin >> age;

	numOfDays = age * 365;
	

	cout << "Hello, " << firstName << " " << lastName << "!" << " You are " << age <<  " years old. " << "That's " << numOfDays << " days!";


	return 0;
}