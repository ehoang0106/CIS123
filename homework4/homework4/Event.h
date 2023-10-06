#pragma once
#include "Date.h"
#include <string>
using namespace std;


class Event
{

private:
    string eventName;
    int startHour, endHour;
    Date* eventDate;

public:
	
    void printEvent() const;
    Event(string eventName, int startHour, int endHour, Date* evenDate);
    bool hasOverlap(const Event& other) const;

    

    int getStartHour() const;

    int getEndHour() const;
    string getEventName() const;
    
    void printEventName() const;
    void setEventName(const string& name);
    void setStartHour(int startH);
    void setEndHour(int endH);

    

};

