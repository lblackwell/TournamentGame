//
//  BlueMen.cpp is the BlueMen class function implementation file.
//  BlueMen is a subclass of the abstract class Character.
//
//  Created by Lucia Blackwell on 2/9/15
//  Modified by Lucia Blackwell on 2/27/15
//

#include "Character.h"
#include "BlueMen.h"
#include <ctime>
#include <cstdlib>
#include <string>

// Default constructor
BlueMen::BlueMen(std::string charName, std::string teamName)
{
	// Seed RNG
	srand(time(NULL));

	// Name of character
	this->setName(charName);

	// Type of character
	this->setSpecies("Blue Men");

	// How many-sided die to roll for attack
	this->setAttDiceSides(10);

	// How many attack dice
	this->setNumAttDice(2);

	// How many-sided die to roll for defense
	this->setDefDiceSides(6);

	// How many defence dice
	this->setNumDefDice(3);

	// Armor value
	this->setArmor(3);

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