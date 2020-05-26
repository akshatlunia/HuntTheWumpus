/******************************************************
** Program: pit.h
** Author: Akshat Lunia
** Date: 05/25/2020
** Description: Header file for pit class
** Input:
** Output:
******************************************************/
#ifndef PIT_H
#define PIT_H
#include <iostream>
#include "./event.h"

using namespace std;

class Pit : public Event{
    public:
        Pit();
        Player encounter(Player, int, int);
};
#endif