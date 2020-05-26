/******************************************************
** Program: arrow.cpp
** Author: Akshat Lunia
** Date: 05/25/2020
** Description: Holds functions for arrow class
** Input:
** Output:
******************************************************/
#include "./arrow.h"

Arrow::Arrow(){

}

Arrow::Arrow(int x, int y):Coordinates(x, y){

}

 int Arrow::kill_wumpus(Coordinates wump, string direction, int max_x, int max_y){
    for(int i=0; i<c_arrow_travel; i++){
        cout << "Moving 1 space\n";
        if(direction == c_north){
            if(y-1 >= 0){
                y--;
            }else{
                break;
            }
        }
        if(direction == c_east){
            if(x+1 < max_x){
                x++;
            }else{
                break;
            }
        }
        if(direction == c_west){
            if(x-1 >= 0){
                x--;
            }else{
                break;
            }
        }
        if(direction == c_south){
            if(y+1 < max_y){
                y++;
            }else{
                break;
            }
        }

        cout << "Arrow is now @ x:" << x << " y:" << y << endl;
        cout << "Wumpus is in your: '" << check_adjacent_coordinates(wump) << "'\n";

        if(check_same_coordinates(wump) == true){
            return c_can_kill_wumpus;
        }
        else if(check_adjacent_coordinates(wump) == c_not_adjecent){
        }
        else if(check_adjacent_coordinates(wump) != direction
                //&& check_adjacent_coordinates(wump) != c_not_adjecent
                ){
                return c_wumpus_adjecent;
        }
    }
    return c_can_not_kill_wumpus;
} 