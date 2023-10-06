#include <iostream>
using namespace std;


void practice1()
{
	srand(time(0));

	int guess, num1, num2, sum;

	num1 = (rand() % 1000);
	num2 = (rand() % 1000);
	sum = num1 + num2;
	cout << "Number 1: " << num1 << endl;
	cout << "Number 2: " << num2 << endl;

	cout << "Enter guess number: ";
	cin >> guess;

	if (guess == sum)
	{
		cout << "Congratz!";
	}
	else
	{
		cout << "Wrong answer!";
	}

}