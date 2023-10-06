#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Date
{
public:
	int day;
	int month;
	int year;
};


class Event
{
public:
	Date eventDate;
	string name;
	string sponsor;
};

int main()
{
	
	
	vector<Event> events;
	char option;

	do
	{
		Event e;

		cout << "Enter name of event: ";
		getline(cin, e.name);

		cout << "Enter name of sponsor: ";
		getline(cin, e.sponsor);

		bool validFormat = false;

		while (!validFormat)
		{
			cout << "Enter day: ";
			cin >> e.eventDate.day;
			cout << "Enter month: ";
			cin >> e.eventDate.month;
			cout << "Enter year: ";
			cin >> e.eventDate.year;

			if (e.eventDate.day < 1 || e.eventDate.day > 31 || e.eventDate.month < 1 || e.eventDate.month > 12 || e.eventDate.year < 0)
			{
				cout << "Invalid format date. Enter again!" << endl;
			}
			else
			{
				validFormat = true;
			}
		}
		cout << endl;
		cout << "Event added!" << endl;
		cout << endl;
		cout << "Enter any character to continue or 'q' to stop add event: ";
		cin >> option;
		cin.ignore();

		events.push_back(e);

	} while(option != 'q');

	cout << endl;

	cout << "Events: " << endl;

	for (int i = 0; i < events.size(); i++)
	{
		cout << "-------------------------------" << endl;
		cout << "Event name: " << events[i].name << endl;
		cout << "Sponsored by: " << events[i].sponsor << endl;
		cout << "Date: " << events[i].eventDate.month << "/" << events[i].eventDate.day << "/" << events[i].eventDate.year << endl;
		
	}


	return 0;
}