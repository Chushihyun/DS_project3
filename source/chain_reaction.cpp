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

    board.place_orb(0, 0, &Red_player);
    board.place_orb(0, 0, &Red_player);
    board.place_orb(0, 0, &Red_player);
    board.place_orb(0, 0, &Blue_player);
    board.place_orb(1, 1, &Red_player);
    board.place_orb(2, 2, &Red_player);
    board.place_orb(3, 4, &Red_player);
    board.place_orb(4, 5, &Red_player);
    board.print_current_board();

    if(rules_violation(Red_player) || rules_violation(Blue_player)) return 0;

    return 0;
} 