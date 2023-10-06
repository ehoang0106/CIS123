#include <iostream>

using namespace std;

double getSales(int divison);
void findHighest(double div1, double div2, double div3, double div4);
void practice3()
{
	double div1 = getSales(1);
	double div2 = getSales(2);
	double div3 = getSales(3);
	double div4 = getSales(4);
	findHighest(div1, div2, div3, div4);
}


double getSales(int division)
{
	double sales;
	cout << "What are the sales for division " << division << "? ";
	cin >> sales;

	return sales;
}


void findHighest(double div1, double div2, double div3, double div4)
{
	
	double highestSales = div1;
	int highestDiv = 1;

	if (div2 >= highestSales)
	{
		highestSales = div2;
		highestDiv = 2;
	}

	if (div3 >= highestSales)
	{
		highestSales = div3;
		highestDiv = 3;
	}

	if (div4 >= highestSales)
	{
		highestSales = div4;
		highestDiv = 4;
	}

	cout << "The highest sales were in division " << highestDiv << " with $" << highestSales << endl;
}