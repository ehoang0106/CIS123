#include "Player.h"
#include <iostream>
#include <cstdlib> 
using namespace std;



Player::Player(const string& name, int health, int strength) : name(name), currentHealth(health), startingHealth(health), strength(strength)
{
	if (health < 1 || health > 100 || strength < 1 || strength > 100)
	{
		exit(EXIT_FAILURE);
	}
}


int Player::attack() const
{
	return rand() % strength + 1;
}

bool Player::takeDamage(int damageAmount)
{
	if (damageAmount < 1 || damageAmount > 100)
	{
		exit(EXIT_FAILURE);
	}

	int block = rand() % damageAmount + 1;
	currentHealth -= (damageAmount - block);
	return currentHealth <= 0;
}


void Player::heal()
{
	currentHealth += 10;
	if (currentHealth > startingHealth)
	{
		currentHealth = startingHealth;
	}
}

int Player::getHealth() const
{
	return currentHealth;
}


void Player::setStrength(int strength)
{
	if (strength < 1 || strength>100)
	{
		exit(EXIT_FAILURE);
	}

	this->strength = strength;
}


int Player::getStrength() const
{
	return strength;
}