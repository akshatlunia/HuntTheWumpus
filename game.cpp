/******************************************************
** Program: game.cpp
** Author: Akshat Lunia
** Date: 05/25/2020
** Description: Holds all the functions for the game.
** Handles all objects on the board.
** Input:
** Output:
******************************************************/
#include "./game.h"

Game::Game(){

}

Game::Game(int x, int y, bool debug_flag){
    x_coordinate = x;
    y_coordinate = y;
    debug_mode = debug_flag;
    //player(true, 2, 1);
}

void Game::print_board(){
    //Loops through every row of rooms
    for (int i = 0; i < rooms.size(); i++) {
        //Loops through every row of console output because the
        //console cannot write in columns
        for(int k=0; k<rooms[i][0].get_num_rows(); k++){
            //Loops for every column of rooms in the row
            for (int j = 0; j < rooms[i].size(); j++){
                //cout << "y is " << i << " x is " << j << " and row is " << k << endl;
                cout << rooms[i][j].get_row(k, debug_mode) << ""; 
                //cout << rooms[i][j].get_has_player() << endl; 
            }
        cout << endl;
        }
    }
}

void Game::fillBoard(){
    for (int i=0; i<y_coordinate; i++){

        vector<Room> newRow;
        //board.push_back(vector<Room>());
        for (int j=0; j<x_coordinate; j++){
            Room newRoom(j,i);
            newRow.push_back(newRoom);
        }
        //cout << newRow[4].get_cell() << endl;
        rooms.push_back(newRow);
    }
}

void Game::place_player(){
    do{
        player.randomize_coordinates(x_coordinate,y_coordinate);
    }while(check_event_placement(player) == true);
    rooms[player.get_y()][player.get_x()].set_has_player(true);
    start.set_x(player.get_x());
    start.set_y(player.get_y());
}

void Game::move_player(int delta_x, int delta_y){
    if(player.get_x() + delta_x < 0 || player.get_x() + delta_x >= x_coordinate
            || player.get_y() + delta_y <0 || player.get_y() + delta_y >= y_coordinate){
        cout << "Invalid move, try something else\n";
        return;
    }
    else {
        //cout << "Setting has player to false\n";
        rooms[player.get_y()][player.get_x()].set_has_player(false);
        player.set_x(player.get_x()+delta_x);
        player.set_y(player.get_y()+delta_y);
        //cout << "Setting has player to true\n";
        rooms[player.get_y()][player.get_x()].set_has_player(true);
        //cout << ">>>Set has player to true\n";
    }
}

int Game::encounter(Room current_room){
    if(current_room.get_has_event() == true){
        //cout << "Found an event\n";
        if(current_room.get_event_name() == c_bats_event){
            //cout << "Event is bat\n";
            for(int i=0; i<c_num_bats; i++){
                if(bats[i].check_same_coordinates(current_room) == true){
                    //cout << "Moving player\n";
                    rooms[player.get_y()][player.get_x()].set_has_player(false);
                    player = bats[i].encounter(player, x_coordinate, y_coordinate);
                    place_player();
                    //cout << "New player coordinate is " << player.get_x() << ", " << player.get_y() << endl;
                    return 0;
                }
            }
        }
        else if(current_room.get_event_name() == c_pit_event){
            //cout << "Event is " << c_pit_event << endl;
            for(int i=0; i<c_num_pits; i++){
                if(pit[i].check_same_coordinates(current_room) == true){
                    cout << "You've walked into a bottomless pit\n\nGame Over!\n";
                    return 1;
                }
            }
        }
        else if(current_room.get_event_name() == c_gold_event){
            //cout << "Event is " << c_gold_event << endl;
            cout << "You're holding gold!\n";
            player.set_has_gold(true);
            return 0;
        }
        else if(current_room.get_event_name() == c_wumpus_event){
            //cout << "Event is " << c_wumpus_event << endl;
            cout << "The Wumpus has eaten you!\n\nGame Over!\n";
            return 1;
        }
    }
    return 0;
}

void Game::kill_wumpus(){
    wumpus.set_is_alive(false);
    rooms[wumpus.get_y()][wumpus.get_x()].set_has_event(false, "");
}

int Game::player_action(string input){
    //cout << "input is '" << input << "'\n";
    if(input == c_north){
        move_player(0,-1);
    }
    else if(input == c_west){
        move_player(-1,0);
    }
    else if(input == c_south){
        move_player(0,1);
    }
    else if(input == c_east){
        move_player(1,0);
    }
    else if(input.substr(0,1) == " "){
        //cout << "Trying to kill wumpus\n";
        int fire_return;
        fire_return = player.fire_arrow(wumpus,input.substr(1,1), x_coordinate, y_coordinate);
        if(fire_return ==c_can_kill_wumpus){
            cout << "You've killed the Wumpus!\n";
            kill_wumpus();
        }else if(fire_return == c_wumpus_adjecent){
            srand(time(NULL));
            int chance = rand() % 4;
            if(chance == 0){
                rooms[wumpus.get_y()][wumpus.get_x()].set_has_event(false, c_wumpus_event);
                cout << "Wumpus escaped to a new place!\n";
                place_wumpus();
            }
            else{
                cout << "Missed Wumpus, Wumpus heard arrow but didn't move\n";
            }
        }else{
            cout << "Missed Wumpus\n";
        }

    } 
    //cout << "Checking for encounter\n";
    int run_game_value = encounter(rooms[player.get_y()][player.get_x()]);
    //cout << "Checked encounter\n";
    return run_game_value;
}

bool Game::check_event_placement(Coordinates coordinates){
    //cout << "checking if an event exists at given coordinate\n";
    return rooms[coordinates.get_y()][coordinates.get_x()].get_has_event();
}

void Game::place_bats(){
    for (int i=0; i<c_num_bats; i++){
        Bats new_bat;
        //cout << "Created new bat\n";
        do{
            new_bat.randomize_coordinates(x_coordinate,y_coordinate);
        }while(check_event_placement(new_bat) == true);
        bats.push_back(new_bat);
        rooms[new_bat.get_y()][new_bat.get_x()].set_has_event(true, c_bats_event);
        //cout << "Bat is in " << bats[i].get_x() << ", " << bats[i].get_y() << endl;
    }
}

void Game::place_pits(){
    for (int i=0; i<c_num_pits; i++){
        Pit new_pit;
        //cout << "Created a new pit\n";
        do{
            new_pit.randomize_coordinates(x_coordinate,y_coordinate);
        }while(check_event_placement(new_pit) == true);
        pit.push_back(new_pit);
        rooms[new_pit.get_y()][new_pit.get_x()].set_has_event(true, c_pit_event);
        //cout << "Pit is in " << pit[i].get_x() << ", " << pit[i].get_y() << endl;
    }
}

void Game::place_gold(){
    Gold new_gold;
    //cout << "Created pile of gold\n";
    do{
        new_gold.randomize_coordinates(x_coordinate,y_coordinate);
    }while(check_event_placement(new_gold) == true);
    gold = new_gold;
    rooms[new_gold.get_y()][new_gold.get_x()].set_has_event(true, c_gold_event);
    //cout << "Gold is in " << gold.get_x() << ", " << gold.get_y() << endl;
}

void Game::place_wumpus(){
    Wumpus new_wumpus;
    //cout << "Created a Wumpus\n";
    do{
        new_wumpus.randomize_coordinates(x_coordinate,y_coordinate);
    }while(check_event_placement(new_wumpus) == true);
    wumpus = new_wumpus;
    rooms[new_wumpus.get_y()][new_wumpus.get_x()].set_has_event(true, c_wumpus_event);
    //cout << "Wumpus is in " << wumpus.get_x() << ", " << wumpus.get_y() << endl;
}

void Game::place_events(){
    place_bats();
    place_pits();
    place_gold();
    place_wumpus();
}

int Game::won_game(){
    cout << "Congratulations!\nYou've found the gold and the exit successfully!\nYou win!\n";
    end_game = 1;
}

void percept(string event_name){
    if(event_name == c_bats_event){
        cout << "You hear wings flapping.\n";
    }
    else if(event_name == c_wumpus_event){
        cout << "You smell a terrible stench.\n";
    }
    else if(event_name == c_gold_event){
        cout << "You see a glimmer nearby.\n";
    }
    else if(event_name == c_pit_event){
        cout << "You feel a breeze.\n";
    }
}

void Game::check_adjacent_rooms(){
    //cout << "Checking adjecent rooms\n";
    if(player.get_x()+1 < x_coordinate){
        if(rooms[player.get_y()][player.get_x()+1].get_has_event() == true){
            percept(rooms[player.get_y()][player.get_x()+1].get_event_name());
        }
    }
    if(player.get_y()+1 < y_coordinate){
        if(rooms[player.get_y()+1][player.get_x()].get_has_event() == true){
            percept(rooms[player.get_y()+1][player.get_x()].get_event_name());
        }
    }
    if(player.get_x()-1 >= 0){
        if(rooms[player.get_y()][player.get_x()-1].get_has_event() == true){
            percept(rooms[player.get_y()][player.get_x()-1].get_event_name());
        }
    }
    if(player.get_y()-1 >= 0){
        if(rooms[player.get_y()-1][player.get_x()].get_has_event() == true){
            percept(rooms[player.get_y()-1][player.get_x()].get_event_name());
        }
    }
    //cout << "Checked adjecent rooms\n";
}

void Game::run_game(){
    fillBoard();
    place_events();
    place_player();
    print_board();
    string input;
    do{
        getline(cin, input);
        end_game = player_action(input);
        print_board();
        check_adjacent_rooms();
        if(player.get_x() == start.get_x() && player.get_y() == start.get_y()
                && player.get_has_gold() == 1){
                    won_game();
        }
    }while(input != "q" && end_game == 0);
}