#include <iostream>
#include <string>

using namespace std;

string names[] = { "Sarah Smith", "Bob Williams", "Jennifer Thompson" };
string numbers[] = { "555-1234", "555-4321", "555-5555" };

void changeNumber();
void lookupNumber();

int main()
{
	int option;
	bool quit = false;
	
	while (!quit)
	{
		cout << "Enter (1) to change number" << endl;
		cout << "Enter (2) to lookup number" << endl;
		cout << "Enter (3) to quit" << endl;

		cout << "Choose: ";
		cin >> option;
		cin.ignore();

		if (option == 1)
		{
			changeNumber();

		}
		else if (option == 2)
		{
			lookupNumber();
		}
		else if (option == 3)
		{
			quit = true;
		}
		else
		{
			cout << "Wrong option. Choose again!" << endl;
		}
	}
	

	
	return 0;
}

void changeNumber()
{
	
	string name, newNumber;
	
	cout << "Enter name: ";
	getline(cin, name);
	
	for (int i = 0; i < 3; i++)
	{
		if (names[i] == name)
		{
			cout << "Name found!" << endl;
			cout << "Enter a new number: ";
			cin >> newNumber;

			numbers[i] = newNumber;

			cout << "Phone number updated!" << endl;
			cout << "New number of " << name << " is " << newNumber << endl;
			return;
		}

	
	}

	cout << "Name is not found!" << endl;
	
}

void lookupNumber()
{
	string name;

	cout << "Enter name: ";
	getline(cin, name);

	for (int i = 0; i < 3; i++)
	{
		if (names[i] == name)
		{
			cout << "Phone number of " << name << " is " << numbers[i] << endl;
			return;
		}
	}
	cout << "Name is not found!" << endl;
}