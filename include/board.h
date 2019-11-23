#ifndef INCLUDE_BOARD_H_
#define INCLUDE_BOARD_H_

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

class Cell{
    private:
        int orbs_num;   // The number of the orbs on the cell 
        int capacity;   // The max number of the orbs of a cell
        char color;     // The color of the cell, 'w'(No one has placed the orbs), 'r'(Red Player) and 'b'(Blue player)

    public:
        Cell();
        int get_orbs_num();
        int get_capacity();
        char get_color();

        void set_orbs_num(int orbs);
        void set_capacity(int cap);
        void set_color(char col);
};

class Board{
    private:
        Cell board[5][6];
    public:
        Board();
};

#endif