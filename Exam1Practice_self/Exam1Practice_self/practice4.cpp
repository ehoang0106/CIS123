#include <iostream>

using namespace std;

int main()
{
	int num, temp = 0;
	int sum = 0;
	
	while (true)
	{
		cout << "Enter a number: ";
		cin >> num;

		if (num == -99)
		{
			break;
		}

		sum += num;
		temp++;

		
	}
	
	double avg = (double)sum / (temp);
	
	cout << "Average: " << avg;
	
}