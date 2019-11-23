#ifndef INCLUDE_PLAYER_H_
#define INCLUDE_PLAYER_H_

/***************************************************
 * This header is about the data structure player
***************************************************/

#define RED 'r'
#define BLUE 'b'

class Player{
    private:
        char color;
        bool illegal;   // If yes, terminate the program and determine the playerwho violates the rules to be a loser

    public:
        Player(int col);
};

#endif