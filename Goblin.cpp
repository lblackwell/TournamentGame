//
//  Goblin.cpp is the Goblin class function implementation file.
//  Goblin is a subclass of the abstract class Character.
//
//  Created by Lucia Blackwell on 2/9/15
//  Modified by Lucia Blackwell on 2/27/15
//

#include "Character.h"
#include "Goblin.h"
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>

// Default constructor
Goblin::Goblin(std::string charName, std::string teamName)
{
	// Seed RNG
	srand(time(NULL));

	// Name of character
	this->setName(charName);

	// Type of character
	this->setSpecies("Goblin");

	// How many-sided die to roll for attack
	this->setAttDiceSides(6);

	// How many attack dice
	this->setNumAttDice(2);

	// How many-sided die to roll for defense
	this->setDefDiceSides(6);

	// How many defence dice
	this->setNumDefDice(1);

	// Armor value
	this->setArmor(3);

	// Health (strength points)
	this->setSP(8);

	// Attack strength modifier (for Achilles ability)
	this->setAttMod(1);


	// Original SP
	this->setOrigSP(8);

	// Tournament score
	this->setScore(0);

	// Team
	this->setTeam(teamName);
}

// Attacking function
int Goblin::useAttack(Character* opponent)
{
	// Use rollDice function with attack dice to get roll value
	int roll = this->rollDice(this->getNumAttDice(), this->getAttDiceSides());

	// If roll was 12 and Goblin is fighting a non-Goblin, inflict Achilles
	if(roll == 12 && opponent->getName() != "Goblin")
	{
		opponent->setAttMod(0.5);
	}

	// Return roll value
	return roll;
}