#include <iostream>
#include "../include/board.h"
#include "../include/rules.h"

using namespace std;

Cell::Cell(){
    orbs_num = 0, capacity = 4, color='w', explode = false;
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

bool Cell::get_explode(){
    return this->explode;
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

void Cell::set_explode(bool tof){
    this->explode = tof;
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
    cout << endl ;

}

bool Board::place_orb(int i, int j, Player * player){
    
    if(index_range_illegal(i, j) || !placement_illegal(*player, cells[i][j])){
        int temp = cells[i][j].get_orbs_num();
        temp += 1;
        cells[i][j].set_orbs_num(temp);
        cells[i][j].set_color(player->get_color());
    }
    else{
        player->set_illegal();
        return false;
    }

    if(cell_is_full(&cells[i][j])){
        first_explode(i, j);
        chain_reaction(*player);
    }

    return true;
}

bool Board::cell_is_full(Cell* cell){
    if(cell->get_orbs_num() >= cell->get_capacity()){
        cell->set_explode(true);
        return true;
    }
    else return false;
}

void Board::first_explode(int i, int j){
    int orb_num;
    char color = cells[i][j].get_color();

    cells[i][j].set_orbs_num(0);    // Set the explosion cell to zero
    cells[i][j].set_explode(false);
    cells[i][j].set_color('w');

    if( i + 1 < ROW){
        orb_num = cells[i+1][j].get_orbs_num();
        cells[i+1][j].set_orbs_num(orb_num + 1);
        cells[i+1][j].set_color(color);
    }

    if( j + 1 < COL){
        orb_num = cells[i][j+1].get_orbs_num();
        cells[i][j+1].set_orbs_num(orb_num + 1);
        cells[i][j+1].set_color(color);
    }

    if( i - 1 >= 0){
        orb_num = cells[i-1][j].get_orbs_num();
        cells[i-1][j].set_orbs_num(orb_num + 1);
        cells[i-1][j].set_color(color);
    }

    if( j - 1 >= 0){
        orb_num = cells[i][j-1].get_orbs_num();
        cells[i][j-1].set_orbs_num(orb_num + 1);
        cells[i][j-1].set_color(color);
    }

    mark_reaction_cell();
}

void Board::explode(int i, int j){

    // cout << "explosion : " << i << " " << j << endl;
    int orb_num;
    char color = cells[i][j].get_color();

    cells[i][j].set_orbs_num(0);    // Set the explosion cell to zero
    cells[i][j].set_explode(false);
    cells[i][j].set_color('w');

    if( i + 1 < ROW){
        orb_num = cells[i+1][j].get_orbs_num();
        cells[i+1][j].set_orbs_num(orb_num + 1);
        cells[i+1][j].set_color(color);
    }

    if( j + 1 < COL){
        orb_num = cells[i][j+1].get_orbs_num();
        cells[i][j+1].set_orbs_num(orb_num + 1);
        cells[i][j+1].set_color(color);
    }

    if( i - 1 >= 0){
        orb_num = cells[i-1][j].get_orbs_num();
        cells[i-1][j].set_orbs_num(orb_num + 1);
        cells[i-1][j].set_color(color);
    }

    if( j - 1 >= 0){
        orb_num = cells[i][j-1].get_orbs_num();
        cells[i][j-1].set_orbs_num(orb_num + 1);
        cells[i][j-1].set_color(color);
    }
}

void Board::mark_reaction_cell(){

    // Mark the next cell whose number of orbs is equal to the capacity
    for(int i = 0; i < ROW; i++){
            for(int j = 0; j < COL; j++){
                cell_is_full(&cells[i][j]);
            }
        }     
}

void Board::chain_reaction(Player player){
    
    bool chain_reac = true;

    while(chain_reac){

        chain_reac = false;

        for(int i = 0; i < ROW; i++){
            for(int j = 0; j < COL; j++){
                if(cells[i][j].get_explode()){
                    explode(i ,j);
                    cout << "Explosion:\n";
                    print_current_board();
                    chain_reac = true;
                }
            }
        }

        if(win_the_game(player)){
            return;
        }

        mark_reaction_cell();
    }
}

bool Board::win_the_game(Player player){

    char player_color = player.get_color();
    bool win = true;

    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            if(cells[i][j].get_color() == player_color || cells[i][j].get_color() == 'w') continue;
            else{
                win = false;
                break;
            }
        }
        if(!win) break;
    }
    return win;
}