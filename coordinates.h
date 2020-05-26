/******************************************************
** Program: coordinates.h
** Author: Akshat Lunia
** Date: 05/25/2020
** Description: header file for coordinates class
** Input:
** Output:
******************************************************/
#ifndef COORDINATES_H
#define COORDINATES_H
#include <iostream>
#include <string>
#include <cstdlib>
#include "./constants.h"

using namespace std;

class Coordinates{
    protected:
        int x;
        int y;
    public:
        Coordinates();
        Coordinates(int, int);
        Coordinates(bool, int, int);
        Coordinates(const Coordinates&);
        void set_x(int);
        void set_y(int);
        int get_x();
        int get_y();
        //Coordinates randomize_coordinates(int, int);
        void randomize_coordinates(int, int);
        bool check_same_coordinates(Coordinates);
        string check_adjacent_coordinates(Coordinates);
};
#endif