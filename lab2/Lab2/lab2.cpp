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
	char choose;

	do
	{
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

	} while (choose != 'n');

	cout << "Program ending. You won " << numWins << " rounds!" << endl;



	return 0;
}
