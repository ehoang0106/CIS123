#include <iostream>
using namespace std;

/*
	pseudo code

	initialize playerHeath and computerHeath = 100
	while playHealth and computerHeath > 0
	ask user to enter peform action
	at the end loop playerHealth and computerHealth -=20
	after loop, if computerHealth == 0 -> you win, else you lose

*/

int main()
{
	int playerHeath = 100, computerHealth = 100;
	string name;
	cout << "Enter your name: ";
	cin >> name;
	cout << "Hello, " << name << "!" << " Let's play!" << endl;
	
	char choose = 'y'; 
	int option = 0;
	int numWins = 0;
	do
	{
		while (playerHeath > 0 && computerHealth > 0)
		{
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
				playerHeath -= 20;
				computerHealth -= 20;

			}
			else
			{
				cout << "Wrong input. Choose again!" << endl;
			}

		}

		if (computerHealth <= 0)
		{
			cout << endl;
			cout << "Computer's health = 0" << endl;
			cout << "You win!" << endl;
			numWins++;

		}
		else
		{
			cout << "You lose!" << endl;
		}

		//reset playerHealth and computerHealth = 100 before start a new loop
		playerHeath = 100;
		computerHealth = 100;


		cout << "Would you like to play again? (y/n): ";
		cin >> choose;

	} while (choose != 'n' && choose != 'N');

	cout << "You won " << numWins << "games!" << endk;

	

	return 0;
}