#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void loadData(vector<string>& teams, vector<string>& winners);
int countWins(vector<string>& team, string teamName);






int main()
{
	vector<string> teams;
	vector<string> wins;

	loadData(teams, wins);
	bool quit = false;
	
	for (int i = 0; i < teams.size(); i++)
	{
		cout << teams[i] << endl;
	}
	cout << endl;

	while(true)
	{
		
		string teamName;
		cout << "Enter name of a team: ";
		getline(cin, teamName);

		int w = countWins(wins, teamName);

		if (teamName == "q")
		{
			break;
		}

		if (w == 0)
		{
			cout << teamName << " never won the world series!" << endl;
		}
		else if(w == 1)
		{
			cout << teamName << " has won the world series " << w << " time!" << endl;
		}
		else
		{
			cout << teamName << " has won the world series " << w << " times!" << endl;
		}

		

	}



	return 0;
}


void loadData(vector<string>& teams, vector<string>& winners)
{
	string team;
	ifstream inputFile;
	inputFile.open("Teams.txt");

	while (!inputFile.eof())
	{
		getline(inputFile, team);
		teams.push_back(team);
	}

	inputFile.close();

	inputFile.open("WorldSeriesWinners.txt");

	while (!inputFile.eof())
	{
		getline(inputFile, team);
		winners.push_back(team);
	}

	inputFile.close();
}

int countWins(vector<string>& team, string teamName)
{
	int wins = 0;

	for (int i = 0; i < team.size(); i++)
	{
		if (team[i] == teamName)
		{
			wins++;
		}
	}
	return wins;
}