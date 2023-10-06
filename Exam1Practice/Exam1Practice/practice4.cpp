#include <iostream>
using namespace std;

int main()
{
	char option;
	do
	{
		char player1, player2;
		cout << "Choose (p) for paper (r) for rock or (s) for scissors" << endl;
		cout << "Player 1 choose: ";
		cin >> player1;
		cout << "Player 2 choose: ";
		cin >> player2;

		if (player1 == player2)
		{
			cout << "It's a tie. Nobody win!" << endl;
		}

		else if (player1 == 'p' && player2 == 'r')
		{
			cout << "Paper covers rock!" << endl;
			cout << "Player 1 win!" << endl;

		}
		else if (player1 == 'r' && player2 == 'p')
		{
			cout << "Paper covers rock!" << endl;
			cout << "Player 2 win!" << endl;
		}
		else if (player1 == 'r' && player2 == 's')
		{
			cout << "Rock smashes scissors" << endl;
			cout << "Player 1 win!" << endl;
		}
		else if (player1 == 's' && player2 == 'r')
		{
			cout << "Rock smashes scissors" << endl;
			cout << "Player 2 win!" << endl;
		}
		else if (player1 == 's' && player2 == 'p')
		{
			cout << "Scissors cut paper" << endl;
			cout << "Player 1 win!" << endl;
		}
		else if (player1 == 'p' && player2 == 's')
		{
			cout << "Scissors cut paper" << endl;
			cout << "Player 2 win!" << endl;
		}

		cout << "Would you like to play again? (y/n)";
		cin >> option;

		if (option == 'n' || option == 'N')
		{
			cout << "Thank you for playing!" << endl;
		}
	} while (option != 'n' && option != 'N');
	
	

}