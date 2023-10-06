#include <iostream>
using namespace std;

int main()
{
	string name;
	cout << "Enter your name: ";
	cin >> name;
	cout << "Hello, " << name << "!" << " Let's play!" << endl;

	int numGames = 0;
	int numWins = 0;
	char choose = 'y'; // I changed a little bit from lab 2. I don't know is it okay with you
	int option = 0;

	
	
	do
	{
		// I assumed user will enter integer only. If user enter different number from 1 to 4, they will be asked to enter again. 
		// If user input a character. It will lead to infiniti loop. I don't know if you wanted us to solve this problem or not.
		cout << "Choose the option: " << endl;
		cout << "(1) to peform regular attack" << endl;
		cout << "(2) to perform special attack" << endl;
		cout << "(3) to perform heal" << endl;
		cout << "(4) to peform block" << endl;
		cout << "Option: ";
		cin >> option;

		if (option > 0 && option < 5)
		{
			if (option == 1)
			{
				cout << "You peformed regular attack" << endl;
			}

			else if (option == 2)
			{
				cout << "You peformed special attack" << endl;

			}

			else if (option == 3)
			{
				cout << "You performed heal" << endl;

			}
			else if (option == 4)
			{
				cout << "You performed block" << endl;

			}

			if (numGames % 2 == 0)
			{
				cout << "You win!" << endl;
				numWins++;
			}
			else
			{
				cout << "You lose!" << endl;
			}


			numGames++;
			cout << "Would you like to play again? (y/n): ";
			cin >> choose;
		}
		else
		{
			cout << "Wrong input. Choose again!" << endl;
		}



	} while (choose != 'n' && choose!= 'N');

	cout << "Program ending. You won " << numWins << " rounds!" << endl;



	return 0;
}