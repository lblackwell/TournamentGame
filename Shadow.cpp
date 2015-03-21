//
//  Shadow.cpp is the Shadow class function implementation file.
//  Shadow is a subclass of the abstract class Character.
//
//  Created by Lucia Blackwell on 2/9/15
//  Modified by Lucia Blackwell on 2/27/15
//

#include "Character.h"
#include "Shadow.h"
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>

// Default constructor
Shadow::Shadow(std::string charName, std::string teamName)
{
	// Seed RNG
	srand(time(NULL));

	// Name of character
	this->setName(charName);

	// Type of character
	this->setSpecies("Shadow");

	// How many-sided die to roll for attack
	this->setAttDiceSides(10);

	// How many attack dice
	this->setNumAttDice(2);

	// How many-sided die to roll for defense
	this->setDefDiceSides(6);

	// How many defence dice
	this->setNumDefDice(1);

	// Armor value
	this->setArmor(0);

	// Health (strength points)
	this->setSP(12);

	// Attack strength modifier (for Achilles ability)
	this->setAttMod(1);

	// Original SP
	this->setOrigSP(12);

	// Tournament score
	this->setScore(0);

	// Team
	this->setTeam(teamName);
}

// Defending function
int Shadow::useDefense()
{
	// Flip a coin. If "heads," The Shadow takes no damage.
	int coinFlip = (rand() % 2);

	if(coinFlip == 0)
	{
		return 999;
	}

	else
	{
		// Use rollDice function with defense dice to return damage withstood
		return this->rollDice(this->getNumDefDice(), this->getDefDiceSides());
	}	
}