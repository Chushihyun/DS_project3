#include <iostream>
#include "../include/board.h"
#include "../include/rules.h"

using namespace std;

Cell::Cell(){
    orbs_num = 0, capacity = 4, color='w';
}

int Cell::get_capacity(){
    return this->capacity;
}

int Cell::get_orbs_num(){
    return this->orbs_num;
}

char Cell::get_color(){
    return this->color;
}

void Cell::set_orbs_num(int orbs){
    this->orbs_num = orbs;
}

void Cell::set_capacity(int cap){
    this->capacity = cap;
}

void Cell::set_color(char col){
    this->color = col;
}

Board::Board(){

    ////// Initialize the borad with correct capacity //////
    // The corners of the board
    cells[0][0].set_capacity(2), cells[0][5].set_capacity(2),
    cells[4][0].set_capacity(2), cells[4][5].set_capacity(2);

    // The edges of the board
    cells[0][1].set_capacity(3), cells[0][2].set_capacity(3), cells[0][3].set_capacity(3), cells[0][4].set_capacity(3),
    cells[1][0].set_capacity(3), cells[2][0].set_capacity(3), cells[3][0].set_capacity(3),
    cells[1][5].set_capacity(3), cells[2][5].set_capacity(3), cells[3][5].set_capacity(3),
    cells[4][1].set_capacity(3), cells[4][2].set_capacity(3), cells[4][3].set_capacity(3), cells[4][4].set_capacity(3);

}

void Board::print_current_board(){
    
    ////// Print out the current state of the board //////
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            cout << cells[i][j].get_orbs_num() << " ";
        }
        cout << endl;
    }

}

bool Board::place_orb(int i, int j, Player player){
    
    if(check_placement(i, j, player, cells[i][j])){

        int temp = cells[i][j].get_orbs_num();
        temp += 1;
        cells[i][j].set_orbs_num(temp);

        return true;
    }
    else{

    }
}

