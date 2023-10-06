#include "Movie.h"
#include <iostream>

using namespace std;

Movie::Movie(const string& name) : name(name), numRatings(0)
{
	for (int i = 0; i < 5; i++)
	{
		ratings[i] = 0;
	}
}

void Movie::setName(const string& name)
{
	this->name = name;
}

void Movie::addRating(int rating)
{
	if (rating >= 1 && rating <= 5)
	{
		ratings[rating - 1]++;
		numRatings++;
	}
}

string Movie::getName() const
{
	return this->name;
}

void Movie::printRatings() const
{
	for (int i = 0; i < 5; i++)
	{
		cout << (i + 1) << " Star: " << ratings[i] << endl;
	}
}

double Movie::getAverage() const
{
	int total = 0;
	for (int i = 0; i < 5; i++)
	{
		total += (i + 1) * ratings[i];
	}

	return total / numRatings;
}