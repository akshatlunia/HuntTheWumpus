/******************************************************
** Program: player.h
** Author: Akshat Lunia
** Date: 05/25/2020
** Description: Header file for player class
** Input:
** Output:
******************************************************/
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include <vector>
#include "./coordinates.h"
#include "./arrow.h"

using namespace std;

class Player : public Coordinates{
    private:
        vector<Arrow> arrows;
        bool has_gold;
        void initialize_arrows();
    public:
        Player();
        Player(bool, int, int);
        void set_has_gold(bool);
        bool get_has_gold();
        int fire_arrow(Coordinates, string, int, int);
};
#endif