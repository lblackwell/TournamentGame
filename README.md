# TournamentGame
A two-player text-based creature battling game in C++. Intro to CS 2 project focused on containers and polymorphism.

Note that game is intentionally unbalanced for testing purposes, per the assignment prompt, and is not actually much fun to play!

Original notes from assignment4.cpp (main function file):

Author:   Lucia Blackwell

Created:  February 27, 2015

Modified: February 27, 2015


Overview: This program simulates a battling tournament between two teams of fantasy creatures. The players decide the size of the teams, and then build rosters of that many creatures each. Each roster will battle the other in order, with the winner moving to the end of the line (and recovering 20% of its maximum health) and the loser being eliminated. Each type of creature has different attack, defense, armor, and health point values. In addition, the Goblin may cut the opponent's attack in half for the rest of the bout, and the Shadow has a 50% chance of taking no damage.

Input:    Players will decide the team size together, then enter their creature lineups separately.

Output:   Winners of each round are announced. At the end of the tournament, the winning team and team scores are displayed, as well as the top-performing individual creatures by score.
