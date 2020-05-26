/******************************************************
** Program: bats.h
** Author: Akshat Lunia
** Date: 05/25/2020
** Description: header file for bats class
** Input:
** Output:
******************************************************/
#ifndef BATS_H
#define BATS_H
#include <iostream>
#include <string>
#include "./event.h"

using namespace std;

class Bats : public Event{
    private:

    public:
        Bats();
        //void percept(int, int);
        Player encounter(Player, int, int);
};
#endif