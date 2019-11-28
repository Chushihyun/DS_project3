#ifndef INCLUDE_BOARD_H_
#define INCLUDE_BOARD_H_

#include "player.h"

/******************************************************
 * This header is about the data structure of the Board
 * which is composed of the data structure of the Cell.
******************************************************/


/******************************************************
 * !!!!!!WARNING!!!!!!
 * You "should not" call or modify the functions in the
 * data strucutre of Cell.
 * !!!!!!WARNING!!!!!!
******************************************************/

#define ROW 5
#define COL 6

class Cell{
    private:
        int orbs_num;   // The number of the orbs on the cell 
        int capacity;   // The max number of the orbs of a cell
        char color;     // The color of the cell, 'w'(No one has placed the orbs), 'r'(Red Player) and 'b'(Blue player)
        bool explode;

    public:
        Cell();
        int get_orbs_num();
        int get_capacity();
        char get_color();
        bool get_explode();

        void set_orbs_num(int orbs);
        void set_capacity(int cap);
        void set_color(char col);
        void set_explode(bool tof);
};

class Board{
    private:
        Cell cells[ROW][COL];   // The 5*6 board whose index (0,0) is start from the upper left corner

    public:
        Board();
        void print_current_board();
        bool place_orb(int i, int j, Player* player);
        bool cell_is_full(Cell* cell);
        void first_explode(int i, int j);
        void explode(int i, int j);
        void chain_reaction(Player player);
        void mark_reaction_cell();
        bool win_the_game(Player player);
};

#endif