//
//  Reptile.h
//
//  Created by Lucia Blackwell on 2/13/15
//  Modified by Lucia Blackwell on 2/27/15
//

#ifndef REPTILE_H
#define REPTILE_H

#include <string>

class Reptile: public Character
{
public:
	// Constructor
	Reptile(std::string charName, std::string teamName);

private:
	// Character name
	std::string name;

	// Species name
	std::string species;

	// How many-sided die to roll for attack
	int attDiceSides;

	// How many attack dice
	int numAttDice;

	// How many-sided die to roll for defense
	int defDiceSides;

	// How many defence dice
	int numDefDice;

	// Armor value
	int armor;

	// Health (strength points)
	int strengthPoints;

	// Attack strength modifier (for Achilles ability)
	double attMod;

	// Original SP
	int origSP;

	// Tournament score
	int score;

	// Team
	std::string team;
};

#endif