#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Question
{
private:
	string question;
	vector<string> answers;
	int correctAnswer;

public:
	Question(string question, vector<string> answers, int correctAnswer);
	void printQuestion() const;
	bool guess(int answer) const;
};

