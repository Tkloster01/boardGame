#ifndef BOARD_H
#define BOARD_H
#include "Tile.h"
#include "Player.h"

class Board {
    private:
        static const int _BOARD_SIZE = 52;
        Tile _tiles[2][_BOARD_SIZE];
        static const int _MAX_PLAYERS = 4;
        int _player_count;
        Player _player[5];
        void setPlayerList();
        void displayTile(int slot, int pos, int lane);
        void initializeTiles(int lane);
        bool isPlayerOnTile(int slot, int pos, int lane);

    public:
        Board();
        Board(int player_count);
        void displayTrack(int slot, int lane);
        void initializeBoard();
        void displayBoard();
        void updateStats(int slot);
        bool movePlayer(int slot, int roll);
        int getPlayerPosition(int slot);
};

#endif