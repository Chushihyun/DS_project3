#include "../include/board.h"
#include <iostream>

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
    
}