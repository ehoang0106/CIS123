#include <iostream>
#include "Question.h"

using namespace std;


int main()
{
	vector<Question> questions =
	{
		Question("What is 1 + 1?", {"2","3","4","5"},0),
		Question("V-Tec is the technology of which car manufacturer?",{"Toyota","Honda","Mazda","BMW"},1),
		Question("Which language is most use in AI?", {"Java", "C++", "Python", "CSS"},2),
		Question("How many points is this exam?", {"40","50","70","100"},3)
	};

	int p1Score = 0, p2Score = 0;
	int p1Guess, p2Guess;

	for (int i = 0;i < questions.size();i++)	
	{
		Question& q = questions[i];

		q.printQuestion();

		cout << "Player 1's answer: ";
		cin >> p1Guess;

		cout << "Player 2's answer: ";
		cin >> p2Guess;

		if (q.guess(p1Guess - 1))
		{
			cout << "Player 1 got the correct answer!" << endl;
			p1Score++;
		}
		else
		{
			cout << "Player 1 got the incorrect answer!" << endl;
		}

		if (q.guess(p2Guess - 1))
		{
			cout << "Player 2 got the correct answer!" << endl;
			p2Score++;
		}
		else
		{
			cout << "Player 2 got the incorrect answer!" << endl;
		}

		cout << endl;
	}
	cout << "--Final score--" << endl;
	cout << "Player 1: " << p1Score << endl;
	cout << "Player 2: " << p2Score << endl;


	return 0;
}