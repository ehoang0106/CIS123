#pragma once

#include <iostream>
using namespace std;
class Date
{
private:
	int day, month, year;

public:
	
	Date(int day, int month, int year);

	
	int getDay() const;
	int getMonth() const;
	int getYear() const;

	
	void printDate() const;
};

