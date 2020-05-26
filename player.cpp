/******************************************************
** Program: player.cpp
** Author: Akshat Lunia
** Date: 05/25/2020
** Description: Contains functions for player class.
** Also handles player's arrows
** Input:
** Output:
******************************************************/
#include "./player.h"

Player::Player(){
    has_gold = false;
    initialize_arrows();
}

Player::Player(bool random, int x, int y):Coordinates(random, x, y){
    has_gold = false;
    initialize_arrows();
}
void Player::initialize_arrows(){
    for(int i=0; i<c_max_arrows; i++){
            Arrow new_arrow(get_x(),get_y());
            arrows.push_back(new_arrow);
    }
}

void Player::set_has_gold(bool x){
    has_gold = x;
}

bool Player::get_has_gold(){
    return has_gold;
}

int Player::fire_arrow(Coordinates wump, string direction, int max_x, int max_y){
    cout << "You now have: " << arrows.size() -1 << " arrows\n";
    if(arrows.size() > 0){
        Arrow fired_arrow;
        fired_arrow = arrows[arrows.size()-1];
        fired_arrow.set_x(x);
        fired_arrow.set_y(y);
        arrows.pop_back();
        return fired_arrow.kill_wumpus(wump, direction, max_x, max_y);
    }
    else{
        cout << "You cannot kill wumpus anymore.\n";
        return c_can_not_kill_wumpus;}
}