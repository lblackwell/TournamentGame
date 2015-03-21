//
//  Character.cpp is the Character class function implementation file.
//
//  Created by Lucia Blackwell on 2/8/15
//  Modified by Lucia Blackwell on 2/27/15
//

#include "Character.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>

// Roll dice function
int Character::rollDice(int numDice, int sides)
{
	// Int to keep track of total
	int diceTotal = 0;

	// For each die:
	for(int i = 0; i < numDice; i++)
	{
		// Add roll to dice total
		diceTotal += (rand() % sides) + 1;
	}

	// Return total
	return diceTotal;
}

// Attacking function
int Character::useAttack(Character* opponent)
{
	// Use rollDice function with attack dice to return damage dealt
	return this->rollDice(this->getNumAttDice(), this->getAttDiceSides());
}

// Defending function
int Character::useDefense()
{
	// Use rollDice function with defense dice to return damage withstood
	return this->rollDice(this->getNumDefDice(), this->getDefDiceSides());	
}

// Deal hit function
void Character::dealHit(Character* opponent)
{
	// Integers for SP to deduct, damage dealt, and damage withstood
	int damage = 0;
	int hit = 0;
	int withstood = 0;

	// Get hit and withstood
	hit = this->useAttack(opponent);
	withstood = opponent->useDefense();

	// Multiply hit by attack modifier
	// Subtract damage withstood and armor from damage dealt
	damage = (hit * this-> getAttMod()) - (withstood + opponent->getArmor());

	// If any damage is done, apply it to character's SP. Ignore negative damage.
	if(damage > 0)
	{
		opponent->setSP(opponent->getSP() - damage);
	}
}

// Damage recovery function
void Character::recoverDamage()
{
	// Recover 20% of total original SP
	this->setSP(this->getSP() + (0.2 * this->getOrigSP()));
}


// Get functions

std::string Character::getName() const
{
	return name;
}

std::string Character::getSpecies() const
{
	return species;
}

int Character::getNumAttDice() const
{
	return numAttDice;
}

int Character::getAttDiceSides() const
{
	return attDiceSides;
}

int Character::getNumDefDice() const
{
	return numDefDice;
}

int Character::getDefDiceSides() const
{
	return defDiceSides;
}

int Character::getArmor() const
{
	return armor;
}

int Character::getSP() const
{
	return strengthPoints;
}

double Character::getAttMod() const
{
	return attMod;
}

int Character::getOrigSP() const
{
	return origSP;
}

int Character::getScore() const
{
	return score;
}

std::string Character::getTeam() const
{
	return team;
}


// Set functions

void Character::setName(std::string charName)
{
	name = charName;
}

void Character::setSpecies(std::string specName)
{
	species = specName;
}

void Character::setNumAttDice(int numAD)
{
	numAttDice = numAD;
}

void Character::setAttDiceSides(int attSides)
{
	attDiceSides = attSides;
}

void Character::setNumDefDice(int numDD)
{
	numDefDice = numDD;
}

void Character::setDefDiceSides(int defSides)
{
	defDiceSides = defSides;
}

void Character::setArmor(int arm)
{
	armor = arm;
}

void Character::setSP(int newSP)
{
	strengthPoints = newSP;
}

void Character::setAttMod(double aMod)
{
	attMod = aMod;
}

void Character::setOrigSP(int oSP)
{
	origSP = oSP;
}

void Character::setScore(int newScore)
{
	score = newScore;
}

void Character::setTeam(std::string teamName)
{
	team = teamName;
}