#include <iostream>
#include <string>

using namespace std;


int alreadyInArray(int arr[], int numItemsInArray, int target);

int main()
{
	//create 2 integer arrays of size seven
	int lottery[7], guess[7];
	
	//add random number into lottery[7]
	srand(time(0));
	int randomNumber;
	for (int i = 0; i < 7; i++)
	{
		
		//if i is the first index in array -> put it in array
		// else
		// if random number is duplicate -> generate another random # and add to array
		
		do
		{
			randomNumber = rand() % 20 + 1;

		} while (alreadyInArray(lottery, i, randomNumber));

		lottery[i] = randomNumber;
	}

	//ask user to enter seven guesses and make sure no duplicate

	int userGuess;
	cout << "Enter your 7 guess between 1 and 20 " << endl;
	
	for (int i = 0; i < 7; i++)
	{
		do
		{
			cout << "Guess " << i + 1 << ": ";
			cin >> userGuess;
			if (alreadyInArray(guess, i, userGuess))
			{
				cout << "Duplicated number. Please enter another number!" << endl;
			}
		} while (alreadyInArray(guess, i, userGuess));

		guess[i] = userGuess;
	}
	// int numCorrect = 0
	
	int numCorrect = 0;

	//if lottery[i] == guess[j]
	// {
	//  numCorrect++;
	//	}

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (lottery[i] == guess[j])
			{
				numCorrect++;
				break;
			}
		}
	}

	//display lottery number
	cout << "Lottery numbers: ";
	for (int i = 0; i < 7; i++)
	{
		cout << lottery[i] << " ";
	}

	cout << endl;

	//display user guess numbers
	cout << "Guess numbers: ";
	for (int i = 0; i < 7; i++)
	{
		cout << guess[i] << " ";
	}
	cout << endl;

	//determine how many numbers user got correct
	cout << "You guessed " << numCorrect << " correctly." << endl;

	return 0;
}


//write a function alreadyInArray

int alreadyInArray(int arr[], int numItemsInArray, int target)
{
	for (int i = 0; i < numItemsInArray; i++)
	{
		if (arr[i] == target)
		{
			return true;
		}
	}

	return false;
}
