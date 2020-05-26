/******************************************************
** Program: room.h
** Author: Akshat Lunia
** Date: 05/25/2020
** Description: header file for room class
** Input:
** Output:
******************************************************/
#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <string>
#include "./coordinates.h"
#include "./constants.h"

using namespace std;

class Room : public Coordinates{
    private:
        string *rows;
        int num_rows;
        bool has_player;
        void initialize_members();
        bool has_event;
        string event_name;
    public:
        Room();
        Room(int, int);
        //~Room();
        string get_row(int, bool);
        int get_num_rows();
        bool get_has_player();
        void set_has_player(bool);
        string get_event_name();
        void set_event_name(string);
        bool get_has_event();
        void set_has_event(bool);
        void set_has_event(bool, string);
};
#endif