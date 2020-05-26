/******************************************************
** Program: arrow.h
** Author: Akshat Lunia
** Date: 05/25/2020
** Description: Header file for arrow class
** Input:
** Output:
******************************************************/
#ifndef ARROW_H
#define ARROW_H
#include <iostream>
#include "./coordinates.h"
//#include "./wumpus.h"
#include "./constants.h"

using namespace std;

class Arrow : public Coordinates{
    public:
        Arrow();
        Arrow(int, int);
        int kill_wumpus(Coordinates, string, int, int);
};
#endif