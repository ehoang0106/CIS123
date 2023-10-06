#include <iostream>
#include <string>
#include <fstream>
using namespace std;


//playerHealth and playStrength
int playerHealth = 0, playerStrength = 0;
int numWins = 0, numLosses = 0;


int health();
int regularAttack();
int specialAttack();
void block(int attackAmount, int& blockAmount, int& hitAmount);

int main()
{

	/*
	When the program runs for the first time, the file will not exist. 
	Initialize numWins and numLosses to 0 in this case.

	Otherwise, load the data from the file into variables. 
	Update these variables as the game is played and save the results to 
	the file when the program ends. 
	The original data will be deleted from the file (which is what we want).
	
	*/

	ofstream outFile;
	ifstream inFile;

	
	inFile.open("data.txt");
	

	if (!inFile)
	{
		//cout << "Reset" << endl;
		numWins = 0;
		numLosses = 0;
	}
	else
	{
		//cout << "Load file" << endl;
		inFile >> numWins;
		inFile >> numLosses;
		//cout << numWins << endl;
		//cout << numLosses << endl;
	}

	inFile.close();
	outFile.open("data.txt");

	//initialize computer health to 100
	int computerHealth = 100;
	

	string name;
	cout << "Enter your name: ";
	getline(cin, name);
	cout << "Hello, " << name << "!" << " Let's play!" << endl;

	char choose = 'y';
	//choose option to perform action
	int option = 0;
	//count win
	

	//seed the random number
	srand(time(0));


	
	do
	{
		cout << "Enter player's Health: ";
		cin >> playerHealth;

		cout << "Enter player's Strength: ";
		cin >> playerStrength;

		//starting playerHealth
		int startedPlayerHealth = playerHealth;

		cout << "Player Health: " << startedPlayerHealth << endl;
		cout << "Computer Health: " << computerHealth << endl;

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
			
			//computerAttack

			//random number between 0 and 1/2 playerHealth
			int computerAttack;
			computerAttack = rand() % ((startedPlayerHealth / 2) + 1);
			cout << "Computer attack: " << computerAttack << " points" << endl;
			

			int blockAmount, hitAmount;

			if (option > 0 && option < 5)
			{
				if (option == 1)
				{
					cout << endl;

					cout << "You peformed regular attack for " << rglAttack << " points!" << endl;
					computerHealth -= rglAttack;
				}

				else if (option == 2)
				{
					cout << endl;

					cout << "You peformed special attack for " << spclAttack << " points!" << endl;
					computerHealth -= spclAttack;

				}

				else if (option == 3)
				{
					cout << endl;

					cout << "You performed heal for " << healing << " points!" << endl;
					playerHealth += healing;


				}
				else if (option == 4)
				{

					cout << endl;

					
					block(computerAttack, blockAmount, hitAmount);

					cout << "You performed block" << endl;
					//cout << "ComputerAttack: " << computerAttack << endl;
					cout << "Block Amount: " << blockAmount << endl;
					cout << "Hit amount: " << hitAmount << endl;
				}
				
				/*
				* 
				// if option == 4:playerhealth -= hitamount
				if (option == 4){
					playerhealth -= hitamount
				}
				// else: playerhealth -= computerAttack
				else {
					playerhealth -= computerAttack;
				}

				*/

				if (option == 4)
				{
					playerHealth -= hitAmount;
				}
				else
				{
					playerHealth -= computerAttack;
				}
		

				


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
			numLosses++;
		}

		//reset computerHealth = 100 before start a new loop
		computerHealth = 100;


		cout << "Would you like to play again? (y/n): ";
		cin >> choose;

	} while (choose != 'n' && choose != 'N');

	outFile << numWins << endl;
	outFile << numLosses << endl;

	cout << "You won: " << numWins << " games" << endl;
	cout << "You lost: " << numLosses << " games" << endl;

	
	outFile.close();

	return 0;
}

//return 5 HP

int health()
{
	return 5;
}




int regularAttack()
{
	int rglAttack;

	rglAttack = rand() % (playerStrength - 10 + 1) + 10;

	return rglAttack;
}



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

void block(int attackAmount, int &blockAmount, int &hitAmount)
{
	//attackAmount random number in (0-attackAmount)
	blockAmount = rand() % (attackAmount + 1);
	
	//assign remaining amount of the attack to hitAmount;
	hitAmount = attackAmount - blockAmount;

}
