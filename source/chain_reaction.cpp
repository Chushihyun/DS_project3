#include <iostream>
#include "../include/board.h"
#include "../include/player.h"
#include "../include/rules.h"

using namespace std;

void print_iteration(int& i){
    cout << "Iteration: " << i << endl;
    i++;
}

int main(){

    bool temp;
    Board board;
    Player Red_player(RED);
    Player Blue_player(BLUE);

    bool first_two_step = true;
    int iteration = 1;

    while(1){
        
        print_iteration(iteration);

        cout << "Red Player: " << endl;  
        board.place_orb(0, 0, &Red_player);

        if(rules_violation(Red_player)) return 0;

        board.print_current_board();

        if(board.win_the_game(Red_player) && !first_two_step){
            cout << "Red Player win the game !!!" << endl;
            return 0;
        }

        cout << "Blue_Player: " << endl;
        board.place_orb(4, 5, &Blue_player);

        if(rules_violation(Blue_player)) return 0;
        
        board.print_current_board();

        if(board.win_the_game(Blue_player) && !first_two_step){
            cout << "Blue Player win the game !!!" << endl;
            return 0;
        }

        first_two_step = false;
    }

    return 0;
} 