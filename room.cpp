/******************************************************
** Program: room.cpp
** Author: Akshat Lunia
** Date: 05/25/2020
** Description: contains functions for room class
** Input:
** Output:
******************************************************/
#include "./room.h"

void Room::initialize_members(){
      num_rows = 5;
    rows = new string[num_rows];
    for (int i=0; i<num_rows; i++){
        if (i==0 || i == num_rows-1){
            rows[i] = "*+++*";
        }
        else {
            rows[i] = "|   |";
        }
    }
    has_player = false;
    has_event = false;
    event_name = "";
}
Room::Room(){
  initialize_members();
}

Room::Room(int new_x, int new_y){
    x = new_x;
    y = new_y;
    initialize_members();
}

/* Room::~Room(){
    delete [] rows;
    rows = NULL;
} */

string Room::get_row(int i, bool debug_flag){
/*     if(has_player == true){
        return "| P |";
    } */
    if(debug_flag == true && i == 1){
        if(get_has_event() == true){
            return "| " + event_name.substr(0,1) + " |";
            
        }
    }
    return rows[i];
}

int Room::get_num_rows(){
    return num_rows;
}

bool Room::get_has_player(){
    return has_player;
}

void Room::set_has_player(bool x){
    has_player = x;
    
    //cout << " Setting has player: " << x << endl;

    if(has_player == true){
        rows[2] = "| P |";
    }
    else{
        rows[2] = "|   |";
    }
}

bool Room::get_has_event(){
    return has_event;
}

void Room::set_has_event(bool x){
    has_event = x;
}

string Room::get_event_name(){
    return event_name;
}

void Room::set_event_name(string new_name){
    event_name = new_name;
}

void Room::set_has_event(bool x, string new_name){
    event_name = new_name;
    has_event = x;
}