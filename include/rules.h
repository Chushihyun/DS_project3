#ifndef INCLUDE_RULES_H_
#define INCLUDE_RULES_H_

#include <iostream>
#include "player.h"
#include "board.h"

/******************************************************
 * This header is about the data structure of the Rules
 * which includes all the rules detection functions
******************************************************/

#define LEGAL true
#define ILLEGAL false

bool check_placement(int i, int j, Player player, Cell cell);

#endif