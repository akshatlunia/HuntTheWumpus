/******************************************************
** Program: event.h
** Author: Akshat Lunia
** Date: 05/25/2020
** Description: Definition for abstract event class
** Input:
** Output:
******************************************************/
#ifndef EVENT_H
#define EVENT_H
#include <iostream>
#include "./player.h"

class Event : public Coordinates{
    public:
        virtual Player encounter(Player, int, int) = 0;
};
#endif