#include "Question.h"
#include <iostream>

using namespace std;




Question::Question(string question, vector<string> answers, int correctAnswer)
{
	this->question = question;
	this->answers = answers;
	this->correctAnswer = correctAnswer;
}



void Question::printQuestion() const
{
	cout << "Questions:" << endl;
	cout << question << endl;

	for (int i = 0; i < answers.size(); i++)
	{
		cout << (i + 1) << ". " << answers[i] << endl;
	}

	
}

bool Question::guess(int answer) const
{
	if (answer == correctAnswer)
	{
		return true;
	}
	else
	{
		return false;
	}
}