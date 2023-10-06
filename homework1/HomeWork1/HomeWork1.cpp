#include <iostream>
using namespace std;

int main()
{
	int choose;
	bool quit = false;
	double amountSale, amountRefund, totalSale = 0, runningTotal = 0;
	while (!quit)
	{
		
		cout << "Choose (1) to enter the amount of a sale." << endl;
		cout << "Choose (2) to enter the amount of a refund." << endl;
		cout << "Choose (3) to quit." << endl;
		cout << "Choose: ";
		cin >> choose;

		if (choose == 1)
		{
			cout << "Enter the amount of a sale: ";
			cin >> amountSale;
			totalSale = amountSale * 0.075 + amountSale;

			cout << "Total amount: $" << totalSale << endl;
			runningTotal += totalSale;
		}
		else if (choose == 2)
		{
			cout << "Enter the amount of a refund: ";
			cin >> amountRefund;
			if (runningTotal - amountRefund < 0)
			{
				cout << "The refund cannot be issued. Please speak to the manager" << endl;
			}
			else
			{
				runningTotal -= amountRefund;
				cout << "Refund successful!" << endl;
			}
			
		}
		else if (choose == 3)
		{
			cout << "Total amount entered: $" << totalSale << endl;
			quit = true;
		}
	}

	return 0;
}