#include "../include/player.h"

Player::Player(int col){
    color = col;
    illegal = false;
}

void Player::set_illegal(){
    illegal = true;
}

char Player::get_color(){
    return this->color;
}