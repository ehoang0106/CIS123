#include <iostream>

using namespace std;
void findHighest(double div1, double div2, double div3, double div4);
double getSales(int div);

int practice3()
{
	double div1, div2, div3, div4;

	div1 = getSales(1);
	div2 = getSales(2);
	div3 = getSales(3);
	div4 = getSales(4);
	findHighest(div1, div2, div3, div4);
	return 0;
}

double getSales(int div)
{
	int sales;
	cout << "What are the sales for division " << div << "?";
	cin >> sales;

	return sales;
}

void findHighest(double div1, double div2, double div3, double div4)
{
	double highestDiv = 1;
	double highestSales = div1;

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

	cout << "Highest sales is from division " << highestDiv << " with $" << highestSales;
}