#include <iostream>
using namespace std;


//playerHealth and playStrength
int playerHealth = 0, playerStrength = 0;

int health();
int regularAttack();
int specialAttack();
void block();


int main()
{
	//initialize computer health to 100
	int computerHealth = 100;

	string name;
	cout << "Enter your name: ";
	cin >> name;
	cout << "Hello, " << name << "!" << " Let's play!" << endl;

	char choose = 'y';
	//choose option to perform action
	int option = 0;
	//count win
	int numWins = 0;

	//seed the random number
	srand(time(0));

	
	do
	{
		cout << "Enter player's Health: ";
		cin >> playerHealth;

		cout << "Enter player's Strength: ";
		cin >> playerStrength;


		
		while (playerHealth > 0 && computerHealth > 0)
		{
			cout << endl;
			cout << "Choose the option: " << endl;
			cout << "(1) to peform regular attack" << endl;
			cout << "(2) to perform special attack" << endl;
			cout << "(3) to perform heal" << endl;
			cout << "(4) to peform block" << endl;
			cout << "Option: ";
			cin >> option;

			int rglAttack = regularAttack();
			int spclAttack = specialAttack();
			int healing = health();

			if (option > 0 && option < 5)
			{
				if (option == 1)
				{
					cout << "You peformed regular attack for " << rglAttack << " points!" << endl;
				}

				else if (option == 2)
				{
					cout << "You peformed special attack for " << spclAttack << " points!" << endl;

				}

				else if (option == 3)
				{
					cout << "You performed heal for " << healing << " points!" << endl;
					playerHealth += healing;
					

				}
				else if (option == 4)
				{
					cout << "You performed block" << endl;

				}
				playerHealth -= 20;
				computerHealth -= 20;

				cout << "Your current HP is " << playerHealth << endl;
				cout << "Computer current HP is " << computerHealth << endl;

			}
			else
			{
				cout << "Wrong input. Choose again!" << endl;
			}

		}

		if (computerHealth <= 0)
		{
			numWins++;
			cout << endl;
			cout << "Computer is dead!" << endl;
			cout << "You win!" << endl;
			

		}
		else
		{
			cout << "You lose!" << endl;
		}

		//reset computerHealth = 100 before start a new loop
		computerHealth = 100;


		cout << "Would you like to play again? (y/n): ";
		cin >> choose;

	} while (choose != 'n' && choose != 'N');

	cout << "You won " << numWins << " games!" << endl;



	return 0;
}

//return 5 HP

int health()
{
	return 5;
}


/*

regularAttack: returns an int and empty parameter list
Generate a random value between 10 and the player's strength 
(so if the user entered '50' for their strength, return a random value between 10 and 50).

*/

int regularAttack() 
{
	int rglAttack;

	rglAttack = rand() % (playerStrength - 10 + 1) + 10;

	return rglAttack;
}

/*

specialAttack: returns an int and empty parameter list
2/3 of the time a special attack should be successful, and 1/3 of the time it will not be successful.
To do this, generate a random number between 0 and 2. If the result is 0, the special attack fails, and you should return 0 as the attack amount. 
If the result is 1 or 2, the special attack is successful. 
In this case, return a random number between the player's strength and twice the player's strength. 
For example, if the player's strength is '50', return a value between 50 and 100.

*/


int specialAttack()
{
	int spclAttack, chance;
	
	chance = rand() % 3;

	if (chance == 0)
	{
		spclAttack = 0;
	}
	else if (chance == 1 || chance == 2)
	{
		spclAttack = rand() % (playerStrength + 1) + playerStrength;
	}

	return spclAttack;
}

void block()
{
	/*
	block: returns nothing (a void function) and a single parameter which is an int. 
	The parameter variable will contain the amount of damage the computer is attacking the player for.
	*/
}
