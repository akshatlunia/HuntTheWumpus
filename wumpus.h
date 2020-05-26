/******************************************************
** Program: wumpus.h
** Author: Akshat Lunia
** Date: 05/25/2020
** Description: Header file for wumpus class
** Input:
** Output:
******************************************************/
#ifndef WUMPUS_H
#define WUMPUS_H
#include <iostream>
#include <string>
#include "./event.h"

using namespace std;

class Wumpus : public Event{
    private:
        bool is_alive;
        bool heard_arrow;
    public:
        Wumpus();
        Wumpus(const Wumpus&);
        bool get_is_alive();
        void set_is_alive(bool);
        void set_heard_arrow(bool);
        bool get_heard_arrow();
        Player encounter(Player, int, int);
};
#endif