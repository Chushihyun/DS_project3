#include <iostream>
#include "../include/board.h"
#include "../include/player.h"
#include "../include/rules.h"

using namespace std;


int main(){
    bool temp;
    Board board;
    Player Red_player(RED);
    Player Blue_player(BLUE);

    while(1){

        board.place_orb(2, 2, &Red_player);
        board.print_current_board();
        system("pause");

        if(rules_violation(Red_player) || rules_violation(Blue_player)) return 0;
        if(board.win_the_game(Red_player)) return 0;
    }

    return 0;
} 