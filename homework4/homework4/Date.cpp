#include "Date.h"
#include <iostream>
#include <string>

using namespace std;

Date::Date(int day, int month, int year)
{
	if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1)
	{
		//cout << "Invalid day or month or year!" << endl;
		exit(EXIT_FAILURE);
	}

	this->day = day;
	this->month = month;
	this->year = year;
}


int Date::getDay() const
{
	return day;
}

int Date::getMonth() const
{
	return month;
}

int Date::getYear() const
{
	return year;
}



void Date::printDate() const
{
	cout << month << "/" << day << "/" << year << endl;
}