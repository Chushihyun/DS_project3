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
        void cell_reaction_marker();
        bool cell_is_full(Cell* cell);
        void add_orb(int i, int j, char color);
        void cell_reset(int i, int j);
        void cell_explode(int i, int j);
        void cell_chain_reaction(Player player);

    public:
        Board();
        int get_orbs_num(int i, int j);
        int get_capacity(int i, int j);
        char get_cell_color(int i, int j);
        bool place_orb(int i, int j, Player* player);

        void print_current_board(int i, int j, int round);
        bool win_the_game(Player player);
};

#endif