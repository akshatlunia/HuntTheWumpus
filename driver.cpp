/******************************************************
** Program: driver.cpp
** Author: Akshat Lunia
** Date: 05/25/2020
** Description: Holds main() function
** Input:
** Output:
******************************************************/
#include "./game.h"
#include <stdlib.h>

int main(int argc, char** argv){
    if (argc != 3){
        cout << "Error, only one number and a 'true' or 'false' is acceptable\n";
        return 1;
    }
    int x = atoi(argv[1]);
    int y = atoi(argv[1]);
    bool debug_flag;
    string debug = argv[2];
    if(debug == "true"){debug_flag = true;}
    else {debug_flag = false;}
    if (x < 4 || y < 4){
        cout << "Error, minimum size for grid is 4x4\n";
        return 1;
    }
    Game game(x, y, debug_flag);
    game.run_game();
}