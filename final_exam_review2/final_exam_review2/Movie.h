#pragma once

#include <string>
using namespace std;

class Movie
{
public:
	// constructor

	Movie(const string& name);

	//setter & getter
	void setName(const string& name);
	string getName() const;

	//members function
	
	void addRating(int rating);
	void printRatings() const;
	double getAverage() const;

private:
	string name;
	int ratings[5];
	int numRatings;
};

