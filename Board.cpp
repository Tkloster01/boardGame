#include "Board.h"
#include <string>
#include <iostream>

#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

#define RED "\033[48;2;230;10;10m"
#define GREEN "\033[48;2;34;139;34m"  /* Grassy Green (34,139,34) */
#define BLUE "\033[48;2;10;10;230m"
#define PINK "\033[48;2;255;105;180m"
#define BROWN "\033[48;2;139;69;19m"
#define PURPLE "\033[48;2;128;0;128m"
#define ORANGE "\033[48;2;230;115;0m" /* Orange (230,115,0) */
#define GREY "\033[48;2;128;128;128m" /* Grey (128,128,128) */
#define RESET "\033[0m"

using namespace std;

Board::Board()
{
    _player_count = 1;
    setPlayerList();
    initializeTiles(0);
}

void Board::setPlayerList(){ // Sets the players and their lanes
    for (int i = 0; i < 5; ++i){
        _player[i].player_num = (i + 1);
        _player[i].lane = -1;
        _player[i].pos = 0;
        _player[i].character = 0;
        _player[i].pride_point = 10;
        _player[i].stamina = 0;
        _player[i].strength = 0;
        _player[i].wisdom = 0;
        _player[i].advisor = 0; //Sets ALL possible player arrays to 0. Avoids issues if _player_count < 4
    }

    // _player[5].pos[0] = -1; 
    _player[4].pos = -1; 
    //Creates an extra player for displaying the board. 
    // pos is invalid so the displayed board won't include any players
}

void Board::initializeTiles(int lane)
{
    Tile temp;
    int green_count = 0;
    int total_tiles = _BOARD_SIZE;

    // Keep track of green tile positions to ensure we place exactly 30 greens
    for (int i = 0; i < total_tiles; i++)
    {
        if (i == total_tiles - 1) {
            // Set the last tile as Orange for "Pride Rock"
            temp.color = 'O';
        } 
        else if (i == 0) {
            // Set the first tile as Grey for the starting point
            temp.color = 'Y';
        } 
        else if (green_count < 30 && (rand() % (total_tiles - i) < 30 - green_count)) {
            temp.color = 'G';
            green_count++;
        }
        else
        {
            // Randomly assign one of the other colors: Blue, Pink, Brown, Red, Purple
            int color_choice = rand() % 5;
            switch (color_choice)
            {
                case 0:
                    temp.color = 'B'; // Blue
                    break;
                case 1:
                    temp.color = 'P'; // Pink
                    break;
                case 2:
                    temp.color = 'N'; // Brown
                    break;
                case 3:
                    temp.color = 'R'; // Red
                    break;
                case 4:
                    temp.color = 'U'; // Purple
                    break;
            }
        }

        // Assign the tile to the board for the specified lane
        _tiles[lane][i] = temp;
    }
}

void Board::initializeBoard()
{
    // Seed random number generator in your main function once
    for (int i = 0; i < 2; i++)
    {
        initializeTiles(i);  // This ensures each lane has a unique tile distribution
    }
}



Board::Board(int player_count)
{
    if (player_count > _MAX_PLAYERS)
    {
        _player_count = _MAX_PLAYERS;
    }
    else
    {
        _player_count = player_count;
    }

    setPlayerList();
    initializeBoard(); // Initialize tiles
}



bool Board::isPlayerOnTile(int slot, int pos, int lane)
{
    if(_player[slot].lane == lane){
        if (_player[slot].pos == pos){
            return true;
        }
    }
    return false;
}

void Board::displayTile(int slot, int pos, int lane)
{
    // string space = "                                       ";
    string color = "";
    int player = isPlayerOnTile(slot, pos, lane);

    // Template for displaying a tile: <line filler space> <color start> |<player symbol or blank space>| <reset color> <line filler space> <endl>

    // Determine color to display
    if (_tiles[lane][pos].color == 'R')
    {
        color = RED;
    }
    else if (_tiles[lane][pos].color == 'G')
    {
        color = GREEN;
    }
    else if (_tiles[lane][pos].color == 'B')
    {
        color = BLUE;
    }
    else if (_tiles[lane][pos].color == 'U')
    {
        color = PURPLE;
    }
    else if (_tiles[lane][pos].color == 'N')
    {
        color = BROWN;
    }
    else if (_tiles[lane][pos].color == 'P')
    {
        color = PINK;
    }
    else if (_tiles[lane][pos].color == 'O')
    {
        color = ORANGE;
    }
    else if (_tiles[lane][pos].color == 'Y')
    {
        color = GREY;
    }

     if (player == true)
    {
        cout << color << "|" << _player[slot].player_num << "|" << RESET;
    }
    else
    {
        cout << color << "| |" << RESET;
    }
}

void Board::displayTrack(int slot, int lane)
{
    for (int i = 0; i < _BOARD_SIZE; i++)
    {
        displayTile(slot, i, lane);
    }
    cout << endl;
}

void Board::displayBoard()
{
    int slot = (_player_count + 1);
    for (int i = 0; i < 2; i++)
    {
        displayTrack(slot, i);
        if (i == 0) {
            cout << endl;  // Add an extra line between the two lanes
        }
    }
}

void Board::updateStats(int slot){
    //Keeps the "slot" integer saved during a person's whole turn and uses that to update their stats
}

bool Board::movePlayer(int slot, int roll)
{
    _player[slot].pos += roll;
    if (_player[slot].pos == _BOARD_SIZE - 1){
    return true;
    }
    return false;
}

int Board::getPlayerPosition(int slot)
{
    if (slot >= 0 && slot <= _player_count){
    return _player[slot].pos;
    }
    return -1;
}