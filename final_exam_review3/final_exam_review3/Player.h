#pragma once

#include <string>
using namespace std;
class Player
{
public:
	//constructor
	Player(const string& name, int health, int strength);

	int attack() const;
	bool takeDamage(int damageAmount);
	void heal();
	void printPlayer() const;

	//setter and getter

	void setHealth(int health);
	int getHealth() const;
	void setStrength(int strength);
	int getStrength() const;

private:
	string name;
	int currentHealth;
	int startingHealth;
	int strength;
};

