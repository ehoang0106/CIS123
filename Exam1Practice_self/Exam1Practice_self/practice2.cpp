#include <iostream>
using namespace std;

int practice2()
{
	int num;
	int max = 0, min = 0;
	bool firstEntered = false;

	while (true)
	{
		cout << "Enter a number (enter -99 to stop): ";
		cin >> num;

		if (num == -99)
		{
			break;
		}

		if (firstEntered == false)
		{
			max = num;
			min = num;
			firstEntered = true;
		}

		else
		{
			if (num > max)
			{
				max = num;
			}
			
			if (num < min)
			{
				min = num;
			}
		}
		
	}

	if (firstEntered == false)
	{
		cout << "You did not enter any number!" << endl;
	}
	else 
	{
		cout << "Max: " << max << endl;
		cout << "Min: " << min << endl;
	}
	return 0;
}