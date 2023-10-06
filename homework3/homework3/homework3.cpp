#include <iostream>
#include <string>
#include <fstream>

using namespace std;
ifstream inputFile;
ofstream outputFile;



string login();
void reviewRestaurant(string &username);
bool alreadyReviewed(string &username, string &restaurant);
void seeReview();
void seeAverage();


int main()
{
	string username = login();
	cout << "Welcome, " << username << "!" << endl;

	bool quit = false;

	while (!quit)
	{
		cout << endl;
		cout << "Enter (1) to review a Restaurant" << endl;
		cout << "Enter (2) to see reviews of all Restaurant" << endl;
		cout << "Enter (3) to see average review of a Restaurant" << endl;
		cout << "Enter (4) to quit" << endl;

		int choose;

		cout << "Choose: ";
		cin >> choose;

		if (choose == 1)
		{
			reviewRestaurant(username);
		}
		else if (choose == 2)
		{
			seeReview();
		}
		else if (choose == 3)
		{
			seeAverage();
		}
		else if (choose == 4)
		{
			quit = true;
		}

	}

	
	return 0;
}

string login()
{
	/*
	 call a function named login, which asks for a username and password. 
	 If you find a matching username / password pair in 'users.txt', return the username. Otherwise, ask the user to try again.
	*/

	// ask user name and password
	string userInput, passInput;
	bool loginSuccess = false;

	while (!loginSuccess)
	{
		inputFile.open("users.txt");

		cout << "Enter username: ";
		cin >> userInput;

		cout << "Enter password: ";
		cin >> passInput;

		string username, password;
		//loop thru the file, if the user name or password matching -> return user name
		while (inputFile >> username >> password)
		{

			if (username == userInput && password == passInput)
			{
				inputFile.close();
				loginSuccess = true;
				return username;
			}
		}
		inputFile.close();
		cout << "Invalid username or password" << endl;
	}

	

}

bool alreadyReviewed(string& username, string& restaurant)
{
	inputFile.open("reviews.txt");

	string userChecking, restaurantChecking;
	int rating;

	while (inputFile >> userChecking >> restaurantChecking >> rating)
	{
		

		if (userChecking == username && restaurantChecking == restaurant)
		{
			inputFile.close();
			return true;
		}
	}

	inputFile.close();
	return false;
}


void reviewRestaurant(string& username)
{
	string restaurant;
	int rating;

	cout << "Enter name of the restaurant: ";
	cin >> restaurant;

	outputFile.open("reviews.txt", ios::app);

	if (alreadyReviewed(username, restaurant))
	{
		cout << "You have already reviewed " << restaurant << endl;
		return;
	}

	do
	{
		cout << "Enter the star you want to rate (0-5): ";
		cin >> rating;

		if (rating < 0 || rating > 5)
		{
			cout << "Invalid rating. Try again!" << endl;
		}
	} while (rating < 0 || rating > 5);


	//append the rating to file

	outputFile << username << " " << restaurant << " " << rating << endl;
	outputFile.close();

	cout << "Review added successfully!" << endl;
	cout << "You rated " << restaurant << " " << rating << " stars" << endl;
}


void seeReview()
{
	inputFile.open("reviews.txt");
	
	string user, restaurant, rating;

	if (!inputFile)
	{
		cout << "There is no reviews yet!" << endl;
	}
	else
	{
		while (inputFile >> user)
		{
			inputFile >> restaurant >> rating;

			cout << endl;
			cout << "Restaurant: " << restaurant << endl;
			cout << "User: " << user << endl;
			cout << "Rating: " << rating << endl;
			cout << endl;

		}

		inputFile.close();
	}


	
}




void seeAverage()
{
	/*
	Find the average score for a restaurant. Call a function named seeAverage. 
	In this function, ask the user which restaurant they want to see the average rating for. 
	Calculate the restaurant's average star rating from all users if it has one or more reviews 
	or tell the user there are no reviews for it otherwise.
	*/

	string restaurant;

	cout << "Enter name of restaurant: ";
	cin >> restaurant;

	int totalRating = 0, numRating = 0;

	inputFile.open("reviews.txt");

	string username, restaurantName;
	int rating;

	while (inputFile >> username >> restaurantName >> rating)
	{
		if (restaurantName == restaurant)
		{
			totalRating += rating;
			numRating++;
		}
	}
	
	inputFile.close();

	if (numRating == 0)
	{
		cout << "There is no review for " << restaurant << endl;
	}
	else
	{
		double avg = double(totalRating) / numRating;
		cout << "The average rating for " << restaurant << " is " << avg << " stars" << endl;
	}

	
}