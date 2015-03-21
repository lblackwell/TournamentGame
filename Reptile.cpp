//
//  Reptile.cpp is the Reptile class function implementation file.
//  Reptile is a subclass of the abstract class Character.
//
//  Created by Lucia Blackwell on 2/9/15
//  Modified by Lucia Blackwell on 2/27/15
//

#include "Character.h"
#include "Reptile.h"
#include <ctime>
#include <cstdlib>
#include <string>

// Default constructor
Reptile::Reptile(std::string charName, std::string teamName)
{
	// Seed RNG
	srand(time(NULL));

	// Name of character
	this->setName(charName);

	// Type of character
	this->setSpecies("Reptile Person");

	// How many-sided die to roll for attack
	this->setAttDiceSides(6);

	// How many attack dice
	this->setNumAttDice(3);

	// How many-sided die to roll for defense
	this->setDefDiceSides(6);

	// How many defence dice
	this->setNumDefDice(1);

	// Armor value
	this->setArmor(7);

	// Health (strength points)
	this->setSP(18);

	// Attack strength modifier (for Achilles ability)
	this->setAttMod(1);

	// Original SP
	this->setOrigSP(18);

	// Tournament score
	this->setScore(0);

	// Team
	this->setTeam(teamName);
}