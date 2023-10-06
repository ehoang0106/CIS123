#include <iostream>
#include <string>



using namespace std;

const int MAX_SIZE = 20;


void getScore(int score[], int& numScore);
int findMin(int score[], int numScore);
int findMax(int score[], int numScore);
double findAverage(int score[], int numScore);




int main()
{
	int scores[MAX_SIZE];

	int numScores = 0; //logical size
	getScore(scores, numScores);

	for (int i = 0; i < numScores; i++)
	{
		cout << scores[i] << " ";
	}
	cout << endl;


	int min = findMin(scores, numScores);
	int max = findMax(scores, numScores);
	double avg = findAverage(scores, numScores);

	cout << "Min: " << min << endl;
	cout << "Max: " << max << endl;
	cout << "Average: " << avg << endl;

	return 0;
}

void getScore(int score[], int& numScore)
{
	cout << "How many games the player played: ";
	cin >> numScore;

	for (int i = 0; i < numScore; i++)
	{
		cout << "Enter score of game " << i + 1 << " : ";
		cin >> score[i];
	}
}


int findMin(int score[], int numScore)
{
	int minScore = score[0];

	for (int i = 1; i < numScore; i++)
	{
		if (score[i] < minScore)
		{
			minScore = score[i];
		}
	}
	return minScore;
}

int findMax(int score[], int numScore)
{
	int maxScore = score[0];

	for (int i = 1; i < numScore; i++)
	{
		if (score[i] > maxScore)
		{
			maxScore = score[i];
		}
	}
	return maxScore;
}

double findAverage(int score[], int numScore)
{
	int sum = 0;

	for (int i = 0; i < numScore; i++)
	{
		sum += score[i];
	}

	return (double)sum / numScore;
}


