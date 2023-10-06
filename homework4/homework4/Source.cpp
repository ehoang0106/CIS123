#include <iostream>
#include <vector>
#include "Date.h"
#include "Event.h"


using namespace std;

void cancelEvent(vector<Event*>& events, const string& eventName);

int main()
{
	vector<Event*> events;
	int option;

	while (true)
	{
		cout << "(1) Add event" << endl << "(2) Cancel event" << endl << "(3) View all events" << endl << "(4) Quit" << endl;
		cout << "Choose: ";
		cin >> option;
		cin.ignore();


		if (option == 1)
		{
			string eventName;
			int day, month, year, startHour, endHour;

			bool validHour = false;
			bool validDate = false;
			cout << "Enter name of the event: ";
			cin >> eventName;

			while (!validHour)
			{
				

				cout << "Enter day: ";
				cin >> day;
				cout << "Enter month: ";
				cin >> month;
				cout << "Enter year: ";
				cin >> year;

				

				if (day >= 1 && day <= 31 && month >= 1 && month <= 12 && year >= 1) 
				{
					validHour = true;
				}
				else 
				{
					cout << "Invalid input! Please try again." << endl;
				}
			}

			while (!validDate)
			{
				cout << "Enter start hour: ";
				cin >> startHour;
				cout << "Enter end hour: ";
				cin >> endHour;

				if (startHour >= 0 && startHour <= 23 && endHour >= 0 && endHour <= 23 && startHour < endHour)
				{
					validDate = true;
				}
				else
				{
					cout << "Invalid input! Please try again." << endl;
				}
			}

			

			Date* date = new Date(day, month, year);
			Event* newEvent = new Event(eventName, startHour, endHour, date);
			
			

			
			//check overlap
			bool overlap = false;
			for (int i = 0; i < events.size(); i++) 
			{
				
				if (events[i]->hasOverlap(*newEvent))
				{
					cout << "Cannot add, overlap with existing event: " << endl;
					events[i]->printEventName();
					overlap = true;
					break;
				}
			}
			
			if (!overlap)
			{
				events.push_back(newEvent);

			}
			else
			{
				delete newEvent;
				delete date;
			}
		}
		else if (option == 2)
		{
			string name;
			cout << "Enter event you wanted to cancel: ";
			getline(cin, name);
			cancelEvent(events, name);
		}
		else if (option == 3)
		{
			if (events.empty())
			{
				cout << "There is no events to see!" << endl;
			}
			else
			{
				for (int i = 0; i < events.size(); i++)
				{
					events[i]->printEvent();
				}
			}
			
		}
		else if (option == 4)
		{
			break;
		}
		else
		{
			cout << "Wrong option. Try again!" << endl;
		}
	}


	for (int i = 0; i < events.size(); i++)
	{
		delete events[i];
	}
	events.clear();


	return 0;
}


void cancelEvent(vector<Event*>& events, const string& eventName)
{
	int index = -1;

	for (int i = 0; i < events.size(); i++)
	{
		if (events[i]->getEventName() == eventName)
		{
			index = i;
			break;
		}
	}

	if (index != -1)
	{
		delete events[index];
		events.erase(events.begin() + index);
		cout << "Event " << eventName << " has been cancelled!" << endl;

	}
	else
	{
		cout << "Event not found!" << endl;
	}
}
