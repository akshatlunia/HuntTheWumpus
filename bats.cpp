/******************************************************
** Program: bats.cpp
** Author: Akshat Lunia
** Date: 05/25/2020
** Description: Holds functions for bats class
** Input:
** Output:
******************************************************/
#include "./bats.h"

Bats::Bats(){

}

Player Bats::encounter(Player p, int x_size, int y_size){
    Player k = p;
    k.randomize_coordinates(x_size,y_size);
    return k;
}