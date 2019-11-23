#include "../include/rules.h"

// Check all the rules when player places the orb
bool placement_illegal(Player player, Cell cell){

    bool illegal = false;
    // Check wether the cell has be placed or not
    if(cell.get_color() == 'w') return illegal;

    // Check cell capacity
    if(cell.get_orbs_num() > cell.get_capacity()) illegal = true;

    //Check color
    if(cell.get_color() != player.get_color()) illegal = true;

    return illegal;

}

//Check wether the idnex is over the boundary of board
bool index_range_illegal(int i, int j){

    bool illegal = false;
    if(i > 4 || j > 5) illegal = true;
    return illegal;

}