/******************************************************
** Program: game.h
** Author: Akshat Lunia
** Date: 05/25/2020
** Description: header file for game class
** Input:
** Output:
******************************************************/
#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "./player.h"
#include "./room.h"
#include "./bats.h"
#include "./pit.h"
#include "./gold.h"
#include "./wumpus.h"
//#include "./constants.h"


using namespace std;

class Game{
    private:
        bool debug_mode;
        vector<vector<Room> > rooms;
        vector<Bats> bats;
        vector<Pit> pit;
        Gold gold;
        Wumpus wumpus;
        int x_coordinate;
        int y_coordinate;
        int end_game;
        Coordinates start;
        Player player;
        void move_player(int, int);
        void place_bats();
        bool check_event_placement(Coordinates);
        int encounter(Room);
        void place_pits();
        void place_gold();
        int won_game();
        void place_wumpus();
        void check_adjacent_rooms();
        void kill_wumpus();
    public:
        Game();
        Game(int, int, bool);
        void fillBoard();
        void run_game();
        void print_board();
        void place_player();
        void place_events();
        int player_action(string);
        Coordinates get_random_coordinate();
};
#endif