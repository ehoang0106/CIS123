#include <iostream>
#include "Movie.h"

using namespace std;

int main() 
{
    
    Movie movie1("Fast and Furious");
    Movie movie2("John Wick 3");

    
    movie1.addRating(5);
    movie1.addRating(4);
    movie1.addRating(3);
    movie1.addRating(4);
    movie1.addRating(5);

    movie2.addRating(4);
    movie2.addRating(3);
    movie2.addRating(2);
    movie2.addRating(4);
    movie2.addRating(3);

    
    cout << movie1.getName() << " Average Rating: " << movie1.getAverage() << endl;
    cout << movie2.getName() << " Average Rating: " << movie2.getAverage() << endl;

    return 0;
}