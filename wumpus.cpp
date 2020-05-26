/******************************************************
** Program: wumpus.cpp
** Author: Akshat Lunia
** Date: 05/25/2020
** Description: Contains functions for wumpus class.
** Input:
** Output:
******************************************************/
#include "./wumpus.h"

Wumpus::Wumpus(){
    is_alive = false;
    heard_arrow = false;
}

Wumpus::Wumpus(const Wumpus &wump){
    x = wump.x;
    y = wump.y;
    is_alive = wump.is_alive;
    heard_arrow = wump.heard_arrow;
}

Player Wumpus::encounter(Player p, int x_size, int y_size){

}

void Wumpus::set_is_alive(bool x){
    is_alive = x;
}

bool Wumpus::get_is_alive(){
    return is_alive;
}

void Wumpus::set_heard_arrow(bool x){
    heard_arrow = x;
}

bool Wumpus::get_heard_arrow(){
    return heard_arrow;
}