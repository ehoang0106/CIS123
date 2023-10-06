#include <iostream>

using namespace std;

void practice2()
{	
	//declare number
	int num;
	// declare min = 0, max = 0
	int min = 0, max = 0;
	//while loop if number entered = -99 -> break

	// boolean flag to make sure whether or not user has entered their first num -> numEnterd = false
	bool numEntered = false;

	while (true)
	{
		// enter a number
		cout << "Enter a number (Enter -99 to stop): ";
		cin >> num;
		// if number entered == -99 -> break
		if (num == -99)
		{
			break;
		}

		// if (numEntered == false)
		if (numEntered == false)
		{
			// assigned min = num, max = num, numEntered = true
			max = num;
			min = num;
			numEntered = true;
		}
		else
		{
			//  if num > max -> max = num
			if (num > max)
			{
				max = num;
			}
			// if num < min - > min = num
			if (num < min)
			{
				min = num;
			}
		}
		
	}
	
	// if (numEntered == false)
	if (numEntered == false)
	{
		// cout << you did not enter any number
		cout << "You did not enter any numbers!" << endl;
	}
	else
	{
		
		// cout << largest number
		cout << "Max: " << max << endl;
		// cout << smallest number
		cout << "Min: " << min << endl;
	}
	
}