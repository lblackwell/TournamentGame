//
//  Barbarian.cpp is the Barbarian class function implementation file.
//  Barbarian is a subclass of the abstract class Character.
//
//  Created by Lucia Blackwell on 2/9/15
//  Modified by Lucia Blackwell on 2/27/15
//

#include "Character.h"
#include "Barbarian.h"
#include <ctime>
#include <cstdlib>
#include <string>

// Default constructor
Barbarian::Barbarian(std::string charName, std::string teamName)
{
	// Seed RNG
	srand(time(NULL));

	// Name of character
	this->setName(charName);

	// Type of character
	this->setSpecies("Barbarian");

	// How many-sided die to roll for attack
	this->setAttDiceSides(6);

	// How many attack dice
	this->setNumAttDice(2);

	// How many-sided die to roll for defense
	this->setDefDiceSides(6);

	// How many defence dice
	this->setNumDefDice(2);

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