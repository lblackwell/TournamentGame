/* *********************************************************************
 * Author:   Lucia Blackwell
 * Created:  February 27, 2015
 * Modified: February 27, 2015
 * Filename: assignment4.cpp
 *
 * Overview: This program simulates a battling tournament between two
 *           teams of fantasy creatures. The players decide the size of
 *           the teams, and then build rosters of that many creatures
 *           each. Each roster will battle the other in order, with the
 *           winner moving to the end of the line (and recovering 20% of
 *           its maximum health) and the loser being eliminated. Each
 *           type of creature has different attack, defense, armor, and
 *           health point values. In addition, the Goblin may cut the
 *           opponent's attack in half for the rest of the bout, and the
 *           Shadow has a 50% chance of taking no damage.
 *
 * Input:    Players will decide the team size together, then enter their
 *           creature lineups separately.
 *
 * Output:   Winners of each round are announced. At the end of the
 *           tournament, the winning team and team scores are displayed,
 *           as well as the top-performing individual creatures by score.
 *
 * ********************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include "Character.h"
#include "Barbarian.h"
#include "Reptile.h"
#include "BlueMen.h"
#include "Goblin.h"
#include "Shadow.h"

int main()
{
	// Seed RND
	srand(time(NULL));

	// Vectors for knocked-out fighters and teams
	std::vector<Character> loserPile;
	std::vector<Character> team1;
	std::vector<Character> team2;

	// Whose turn
	int whoseTurn = 1;

	// Team victories
	int team1Vic = 0;
	int team2Vic = 0;

	// Number of team members
	int numFighters;

	// Name of creature being created
	std::string charName;

	// Menu option
	int menuOpt = 0;

	// Largest personal scores
	int firstPlaceScore = 0;
	int secondPlaceScore = 0;
	int thirdPlaceScore = 0;

	// Welcome users
	std::cout << "Welcome to the Grand Melee Tournament!" << std::endl;

	// Get team sizes
	std::cout << "How many fighters will each team have? ";
	std::cin >> numFighters;
	std::cout << std::endl;

	// Confirm for user
	std::cout << numFighters << " participants per team it is!" << std::endl
		<< std::endl;

	// Get members for team 1
	std::cout << "Populating Team One." << std::endl << std::endl;

	for(int i = 0; i < numFighters; i++)
	{
		// Get type of creature
		while(menuOpt < 1 || menuOpt > 6)
		{
			std::cout << "Character " << (i + 1) << ":" << std::endl;

			std::cout << "Recruit which creature type?" << std::endl;
			std::cout << "1 - Barbarian" << std::endl;
			std::cout << "2 - Blue Men" << std::endl;
			std::cout << "3 - Goblin" << std::endl;
			std::cout << "4 - Reptile Person" << std::endl;
			std::cout << "5 - The Shadow" << std::endl;
			std::cout << "6 - Random" << std::endl;

			std::cin >> menuOpt;
		}

		// If user chooses random, set menuOpt to 1-5 randomly
		if(menuOpt == 6)
		{
			menuOpt = (rand() % 5) + 1;
		}

		// Confirm species for user
		std::cout << "Creating ";

		if(menuOpt == 1)
		{
			std::cout << "a Barbarian.";
		}
		else if(menuOpt == 2)
		{
			std::cout << "Blue Men.";
		}
		else if(menuOpt == 3)
		{
			std::cout << "a Goblin.";
		}
		else if(menuOpt == 4)
		{
			std::cout << "a Reptile Person.";
		}
		else
		{
			std::cout << "The Shadow.";
		}

		// Get name
		std::cout << " Name: ";
		std::cin.ignore();
		std::getline(std::cin, charName);
		std::cout << std::endl;

		// Create creature and add to team vector
		if(menuOpt == 1)
		{
			Barbarian newChar(charName, "Team One");
			team1.push_back(newChar);
		}
		else if(menuOpt == 2)
		{
			BlueMen newChar(charName, "Team One");
			team1.push_back(newChar);
		}
		else if(menuOpt == 3)
		{
			Goblin newChar(charName, "Team One");
			team1.push_back(newChar);
		}
		else if(menuOpt == 4)
		{
			Reptile newChar(charName, "Team One");
			team1.push_back(newChar);
		}
		else
		{
			Shadow newChar(charName, "Team One");
			team1.push_back(newChar);
		}

		// Confirm for user
		std::cout << team1[i].getName() << " the " << team1[i].getSpecies()
			<< " created and added to team." << std::endl << std::endl;

		// Reset menu option
		menuOpt = 0;
	}
	// Confirm team is filled
	std::cout << "Team One complete." << std::endl << std::endl;

	// Get members for team 2
	std::cout << "Populating Team Two." << std::endl << std::endl;

	for(int j = 0; j < numFighters; j++)
	{
		// Get type of creature
		while(menuOpt < 1 || menuOpt > 6)
		{
			std::cout << "Character " << (j + 1) << ":" << std::endl;

			std::cout << "Recruit which creature type?" << std::endl;
			std::cout << "1 - Barbarian" << std::endl;
			std::cout << "2 - Blue Men" << std::endl;
			std::cout << "3 - Goblin" << std::endl;
			std::cout << "4 - Reptile Person" << std::endl;
			std::cout << "5 - The Shadow" << std::endl;
			std::cout << "6 - Random" << std::endl;

			std::cin >> menuOpt;
		}

		// If user chooses random, set menuOpt to 1-5 randomly
		if(menuOpt == 6)
		{
			menuOpt = (rand() % 5) + 1;
		}

		// Confirm species for user
		std::cout << "Creating ";

		if(menuOpt == 1)
		{
			std::cout << "a Barbarian.";
		}
		else if(menuOpt == 2)
		{
			std::cout << "Blue Men.";
		}
		else if(menuOpt == 3)
		{
			std::cout << "a Goblin.";
		}
		else if(menuOpt == 4)
		{
			std::cout << "a Reptile Person.";
		}
		else
		{
			std::cout << "The Shadow.";
		}

		// Get name
		std::cout << " Name: ";
		std::cin.ignore();
		std::getline(std::cin, charName);
		std::cout << std::endl;

		// Create creature and add to team vector
		if(menuOpt == 1)
		{
			Barbarian newChar(charName, "Team Two");
			team2.push_back(newChar);
		}
		else if(menuOpt == 2)
		{
			BlueMen newChar(charName, "Team Two");
			team2.push_back(newChar);
		}
		else if(menuOpt == 3)
		{
			Goblin newChar(charName, "Team Two");
			team2.push_back(newChar);
		}
		else if(menuOpt == 4)
		{
			Reptile newChar(charName, "Team Two");
			team2.push_back(newChar);
		}
		else
		{
			Shadow newChar(charName, "Team Two");
			team2.push_back(newChar);
		}

		// Confirm for user
		std::cout << team2[j].getName() << " the " << team2[j].getSpecies()
			<< " created and added to team." << std::endl << std::endl;

		// Reset menu option
		menuOpt = 0;
	}
	// Confirm team is filled
	std::cout << "Team Two complete." << std::endl << std::endl;

	// Let players know battle will begin
	std::cout << "Commencing battle!" << std::endl << std::endl;

	// Loop while both teams still have living members
	while(team1.size() > 0 && team2.size() > 0)
	{
		// Announce who is fighting this round
		std::cout << team1[0].getName() << " the " << team1[0].getSpecies()
			<< " vs " << team2[0].getName() << " the " << team2[0].getSpecies()
			<< std::endl;

		// Loop while heads of both teams are alive
		while(team1[0].getSP() > 0 && team2[0].getSP() > 0)
		{
			if(whoseTurn == 1)
			{
				team1[0].dealHit(&team2[0]);
				whoseTurn = 2;
			}
			else
			{
				team2[0].dealHit(&team1[0]);
				whoseTurn = 1;
			}
		}

		// When one creature runs out of SP, process end of round
		if(whoseTurn == 1)
		{
			// Announce winner
			std::cout << team2[0].getName() << " wins!" << std::endl << std::endl;

			// Increment winning creature's personal score by one
			team2[0].setScore(team2[0].getScore() + 1);

			// Winning creature recovers some health
			team2[0].recoverDamage();

			// Winning creature regains 1.0 attack modifier
			team2[0].setAttMod(1.0);

			// Rotate winning team
			std::rotate(team2.begin(), team2.begin() + 1, team2.end());

			// Losing creature is added to loser pile
			loserPile.push_back(team1[0]);

			// Losing creature is removed from losing team
			team1.erase(team1.begin());

			// Increment winning team's victory count
			team2Vic++;
		}
		else
		{
			// Announce winner
			std::cout << team1[0].getName() << " wins!" << std::endl << std::endl;

			// Increment winning creature's personal score by one
			team1[0].setScore(team1[0].getScore() + 1);

			// Winning creature recovers some health
			team1[0].recoverDamage();

			// Winning creature regains 1.0 attack modifier
			team1[0].setAttMod(1.0);

			// Rotate winning team
			std::rotate(team1.begin(), team1.begin() + 1, team1.end());

			// Losing creature is added to loser pile
			loserPile.push_back(team2[0]);

			// Losing creature is removed from losing team
			team2.erase(team2.begin());

			// Increment winning team's victory count
			team1Vic++;
		}
	}

	// Team with members remaining is the winner
	if(team1.size() > 0)
	{
		std::cout << "Team Two has been defeated." << std::endl;
		std::cout << "Team One wins the tournament, " << team1Vic << " to " 
			<< team2Vic << std::endl << std::endl;

		// Add all remaining creatures to loser pile
		for(int k = 0; k < team1.size(); k++)
		{
			loserPile.push_back(team1[k]);
		}
	}
	else
	{
		std::cout << "Team One has been defeated." << std::endl;
		std::cout << "Team Two wins the tournament, " << team2Vic << " to " 
			<< team1Vic << std::endl << std::endl;

		// Add all remaining creatures to loser pile
		for(int l = 0; l < team2.size(); l++)
		{
			loserPile.push_back(team2[l]);
		}
	}

	// Create a vector to hold all of the creatures' personal scores
	std::vector<int> creatureScores;

	// Run through loser pile and add scores to creatureScores
	for(int m = 0; m < loserPile.size(); m++)
	{
		creatureScores.push_back(loserPile[m].getScore());
	}

	// Find the max of these scores
	firstPlaceScore = *std::max_element(creatureScores.begin(), creatureScores.end());

	// Run through loser pile and report creatures with this score
	std::cout << "First place creature(s) with a score of " << firstPlaceScore
		<< ": " << std::endl;
	for(int n = 0; n < loserPile.size(); n++)
	{
		if(loserPile[n].getScore() == firstPlaceScore)
		{
			std::cout << loserPile[n].getName() << " the " << loserPile[n].getSpecies()
				<< " of " << loserPile[n].getTeam() << std::endl;
		}
	}

	// Remove this score from creatureScores
	for(int o = 0; o < creatureScores.size(); o)
	{
		if(creatureScores[o] == firstPlaceScore)
		{
			creatureScores.erase(creatureScores.begin() + o);
		}
		else
		{
			++o;
		}
	}

	// If there are any scores left, repeat for second place
	if(!creatureScores.empty())
	{
		std::cout << std::endl;

		// Find the max of these scores
		secondPlaceScore = *std::max_element(creatureScores.begin(), creatureScores.end());

		// Run through loser pile and report creatures with this score
		std::cout << "Second place creature(s) with a score of " << secondPlaceScore
			<< ": " << std::endl;
		for(int p = 0; p < loserPile.size(); p++)
		{
			if(loserPile[p].getScore() == secondPlaceScore)
			{
				std::cout << loserPile[p].getName() << " the " << loserPile[p].getSpecies()
					<< " of " << loserPile[p].getTeam() << std::endl;
			}
		}

		// Remove this score from creatureScores
		for(int q = 0; q < creatureScores.size(); q)
		{
			if(creatureScores[q] == secondPlaceScore)
			{
				creatureScores.erase(creatureScores.begin() + q);
			}
			else
			{
				++q;
			}
		}
	}

	// If there are any scores left, repeat for third place
	if(!creatureScores.empty())
	{
		std::cout << std::endl;

		// Find the max of these scores
		thirdPlaceScore = *std::max_element(creatureScores.begin(), creatureScores.end());

		// Run through loser pile and report creatures with this score
		std::cout << "Third place creature(s) with a score of " << thirdPlaceScore
			<< ": " << std::endl;
		for(int r = 0; r < loserPile.size(); r++)
		{
			if(loserPile[r].getScore() == thirdPlaceScore)
			{
				std::cout << loserPile[r].getName() << " the " << loserPile[r].getSpecies()
					<< " of " << loserPile[r].getTeam() << std::endl;
			}
		}
	}

	// End program
	return 0;
}