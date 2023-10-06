#include "Player.h"
#include <iostream>

using namespace std;


int main()
{


	Player player1("Player1", 80, 50);
	Player player2("Player2", 90, 30);


	while (true)
	{
		if (player2.takeDamage(player1.attack()))
		{
			cout << "Player 1 won, player 2 lost!" << endl;
			break;
		}

		if (player1.takeDamage(player2.attack()))
		{
			cout << "Player 2 won, player 1 lost!" << endl;
			break;
		}

		player1.heal();
		player2.heal();
	}
}