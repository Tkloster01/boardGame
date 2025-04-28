#ifndef START_H
#define START_H

#include "Board.h"
#include <string>
#include <fstream>

using namespace std;

class Orange {
    private:
        int _player_count;
        int choice;
        Player _player[5];

    public:
        int totalPlayers();
        void CharInfo(int i, int selection);
        void setPlayerCount(int playerCount);
        void displayPlayers(int playerCount);
        Player getPlayer(int playerIndex);
};

#endif