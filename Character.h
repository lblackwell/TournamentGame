//
//  Character.h
//
//  Created by Lucia Blackwell on 2/8/15
//  Modified by Lucia Blackwell on 2/27/15
//

#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character
{
public:
	// Roll dice function
	virtual int rollDice(int numDice, int sides);

	// Attacking function
	virtual int useAttack(Character* opponent);

	// Defending function
	virtual int useDefense();

	// Deal hit function
	virtual void dealHit(Character* opponent);

	// Damage recovery function
	virtual void recoverDamage();

	// Get functions
	virtual std::string getName() const;
	virtual std::string getSpecies() const;
	virtual int getNumAttDice() const;
	virtual int getAttDiceSides() const;
	virtual int getNumDefDice() const;
	virtual int getDefDiceSides() const;
	virtual int getArmor() const;
	virtual int getSP() const;
	virtual double getAttMod() const;
	virtual int getOrigSP() const;
	virtual int getScore() const;
	virtual std::string getTeam() const;

	// Set functions
	virtual void setName(std::string charName);
	virtual void setSpecies(std::string specName);
	virtual void setNumAttDice(int numAD);
	virtual void setAttDiceSides(int attSides);
	virtual void setNumDefDice(int numDD);
	virtual void setDefDiceSides(int defSides);
	virtual void setArmor(int arm);
	virtual void setSP(int newSP);
	virtual void setAttMod(double aMod);
	virtual void setOrigSP(int oSP);
	virtual void setScore(int newScore);
	virtual void setTeam(std::string teamName);

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

	// Current strength points (health)
	int strengthPoints;

	// Attack strength modifier (for Achilles ability)
	double attMod;

	// Original SP
	int origSP;

	// Personal score
	int score;

	// Team
	std::string team;
};

#endif