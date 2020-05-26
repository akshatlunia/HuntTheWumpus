/******************************************************
** Program: coordinates.cpp
** Author: Akshat Lunia
** Date: 05/25/2020
** Description: Holds functions for coordinates class.
** Handles the coordinates for objects in the gameboard.
** Input:
** Output:
******************************************************/
#include "./coordinates.h"

Coordinates::Coordinates(){
    x = 0;
    y = 0;
}

Coordinates::Coordinates(int new_x, int new_y){
    x = new_x;
    y = new_y;
}

Coordinates::Coordinates(bool random, int x_coordinate, int y_coordinate){
    randomize_coordinates(x_coordinate, y_coordinate);
}

Coordinates::Coordinates(const Coordinates &coords){
    x = coords.x;
    y = coords.y;
}

string Coordinates::check_adjacent_coordinates(Coordinates k){
    if(k.get_x() == x-1){
        return c_west;
    }
    else if (k.get_x() == x+1){
        return c_east;
    }
    else if (k.get_y() == y-1){
        return c_north;
    }
    else if (k.get_y() == y+1){
        return c_south;
    }
    else{return c_not_adjecent;}
}

bool Coordinates::check_same_coordinates(Coordinates k){
    /* cout << "checking if coordinates are the same\n" 
    << " k.x is " << k.get_x() << " k.y is " << k.get_y() << " x is " << x << " y is " << y << endl; */
    if(k.get_x() == x && k.get_y() == y){
        //cout << "coordinates are same\n";
        return true;
    }
    else{return false;}
}

void Coordinates::randomize_coordinates(int x_coordinate, int y_coordinate){
    srand(time(NULL));
    //cout << "Previous x is " << x << " and previous y is " << y << endl;
    int k;
    do{
        k = rand() % x_coordinate;
    }while(k == x);
    set_x(k);
    y = rand() % y_coordinate;
    //cout << "New x is " << x << " and new y is " << y << endl;
}

void Coordinates::set_x(int new_x){
    x = new_x;
}

void Coordinates::set_y(int new_y){
    y = new_y;
}

int Coordinates::get_x(){
    return x;
}

int Coordinates::get_y(){
    return y;
}