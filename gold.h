/******************************************************
** Program: gold.h
** Author: Akshat Lunia
** Date: 05/25/2020
** Description: Header file for gold class
** Input:
** Output:
******************************************************/
#ifndef GOLD_H
#define GOLD_H
#include <iostream>
#include "./event.h"

using namespace std;

class Gold : public Event{
    public:
        Gold();
        Player encounter(Player, int, int);
};
#endif