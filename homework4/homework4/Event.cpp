#include "Event.h"
#include <iostream>

using namespace std;


Event::Event(string eventName, int startHour, int endHour, Date* eventDate)
{
    if (startHour < 0 || startHour > 23 || endHour < 0 || endHour > 23 || startHour >= endHour)
    {
        //cout << "Invalid hour!" << endl;
        exit(EXIT_FAILURE);
    }


    this->eventName = eventName;
    this->startHour = startHour;
    this->endHour = endHour;
    this->eventDate = eventDate;
}

string Event::getEventName() const
{
    return eventName;
}

int Event::getStartHour() const
{
    return startHour;
}


int Event::getEndHour() const
{
    return endHour;
}


void Event::setEventName(const string& name)
{
     eventName = name;
}

void Event::setStartHour(int startH)
{
    startHour = startH;
}

void Event::setEndHour(int endH)
{
    endHour = endH;
}

void Event::printEventName() const
{
    cout << "Event name: " << eventName << endl;
}

void Event::printEvent() const
{
   
    cout << "Event name: " << eventName << endl;
    cout << "Event start from: " << startHour << ":00" << " to " << endHour << ":00" << endl;
    cout << "Event date: ";

    eventDate->printDate();
    
    cout << endl;
} 


bool Event::hasOverlap(const Event& other) const
{
    if (eventDate->getDay() == other.eventDate->getDay() && eventDate->getMonth() == other.eventDate->getMonth() && eventDate->getYear() == other.eventDate->getYear())
        
    {
        return other.getStartHour() <= endHour && startHour <= other.getEndHour();
    }
    return false;
}