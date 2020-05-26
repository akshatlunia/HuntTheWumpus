/******************************************************
** Program: constants.h
** Author: Akshat Lunia
** Date: 05/25/2020
** Description: Header for constants used
** Input:
** Output:
******************************************************/
#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <string>
#include <iostream>

using namespace std;

const string c_bats_event = "Super bats";
const int c_num_bats = 2;
const int c_num_pits = 2;
const int c_max_arrows = 3;
const string c_wumpus_event = "Wumpus";
const string c_gold_event = "Gold";
const string c_pit_event = "Bottomless pit";
const string c_north = "w";
const string c_south = "s";
const string c_west = "a";
const string c_east = "d";
const string c_not_adjecent = "not adjecent";
const int c_arrow_travel = 4;
const int c_can_kill_wumpus = 1;
const int c_wumpus_adjecent = 2;
const int c_can_not_kill_wumpus = 0;

#endif