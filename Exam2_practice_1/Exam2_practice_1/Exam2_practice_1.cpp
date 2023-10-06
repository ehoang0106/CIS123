#include <iostream>
#include <string>

using namespace std;


int getNum();
void printLarger(int arr[], int size, int n);
int main()
{
	const int MAX_SIZE = 5;

	int numbers[MAX_SIZE];

	for (int i = 0; i < MAX_SIZE; i++)
	{
		numbers[i] = getNum();		
	}

	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << numbers[i] << " ";
	}

	cout << endl;

	int n;

	cout << "Enter a number: ";
	cin >> n;

	printLarger(numbers, MAX_SIZE, n);

	return 0;
}

int getNum()
{
	string enterNum;
	int num;

	
	while (true)
	{
		bool isInteger = true;

		cout << "Enter an integer: ";
		getline(cin, enterNum);

		for (int i = 0; i < enterNum.length(); i++)
		{
			if (!isdigit(enterNum[i]))
			{
				isInteger = false;
				break;
			}
			
		}

		if (isInteger)
		{
			num = stoi(enterNum);
			break;
		}
		else
		{
			cout << "You did not enter an integer. Try again!" << endl;
		}
	}
	
	

	return num;
}

void printLarger(int arr[], int size, int n)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > n)
		{
			cout << arr[i] << " ";
		}
	}
}
