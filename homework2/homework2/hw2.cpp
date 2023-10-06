#include <iostream>
using namespace std;



double getGrowthRate();
void showGrowth(string city, int currentPopulation, double rate, int years);



int main()
{
	string city;
	int population, years;
	cout << "Enter city's name: ";
	cin >> city;
	cout << "Enter population: ";
	cin >> population;
	cout << "How many year? ";
	cin >> years;

	double rate = getGrowthRate();
	showGrowth(city, population, rate, years);
}

double getGrowthRate()
{
	double rate;

	do
	{
		cout << "Enter rate: ";
		cin >> rate;

		if (rate < 1 || rate > 100)
		{
			cout << "Wrong input. Rate should be between 1 and 100!" << endl;
		}
	} while (rate < 1 || rate > 100);
	
	
	rate = (rate / 100) + 1;

	return rate;

}

/*
	pseudo code
	loop from the currentYear = 2023 until the year entered -> endYear = currentYear + year entered
	and print projectedPopulation for that year.

	projectedPopulation = currentPopulation * rate;
	if projectedPopulation >= 1,000,000. Stop the loop the print the year will reach 1M population.
	if projectedPopulation never reached 1M population, tell the user this.
	
*/


void showGrowth(string city, int currentPopulation, double rate, int years)
{

	cout << "Population growth for " << city << endl;

	bool reachedMillion = false;
	int currentYear = 2023;
	int endYear = currentYear + years;

	for (currentYear; currentYear <= endYear; currentYear++)
	
	{
		cout << currentYear << ": " << currentPopulation << endl;
		
		int projectedPopulation = currentPopulation * rate;


		if (projectedPopulation > 1000000)
		{
			cout << "Population will reach 1,000,000 in " << currentYear << endl; 
			reachedMillion = true;
			break;
		}
		// update current population
		currentPopulation = projectedPopulation;
	
	}

	if (!reachedMillion)
	{
		cout << "Population will not reach 1,000,000 by " << currentYear - 1 << endl;

	}
	
	
}


