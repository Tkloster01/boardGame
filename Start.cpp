#include "Start.h"
#include "CharInfo.h"
#include "Character.cpp"
#include <iostream>

int Orange::totalPlayers(){
    int flag1 = -5;

    while (flag1 == -5){
        int flag2 = -5;
        cout << "How many total players will be playing?" << endl;
        cin >> _player_count;

        if(_player_count > 4){
            cout << "Too many players. Defaulting to 4 total players." << endl;
            _player_count = 4;
        }

        while (flag2 == -5){
            cout << "The Total players for this game is " << _player_count << ". Is that correct?" << endl;
            cout << "(0) No (1) Yes" << endl;
            cin >> choice;

            switch(choice){
                case 0:
                    flag1 = -5;
                    flag2 = 5; //reprompt user with number of players
                    break;
                case 1:
                    flag1 = 5;
                    flag2 = 5; //set both flags to true
                    break;
                default:
                    cout << "Invalid selection. Please try again." << endl;
                    flag1 = -5;
                    flag2 = -5;
                    break;
            }
        }
    }
    setPlayerCount(_player_count); // sets the private variable
    return _player_count;
}

void Orange::CharInfo(int i, int selection){
    Character list;

    _player[i].character = selection;
    _player[i].pride_point = list.pride_point[0];
    _player[i].stamina = list.stamina[selection];
    cout << _player[0].stamina << endl;
    _player[i].strength = list.strength[selection];
    _player[i].wisdom = list.wisdom[selection];
}

Player Orange::getPlayer(int playerIndex) {
    return _player[playerIndex];
}

void Orange::setPlayerCount(int playerCount) {
    _player_count = playerCount;
}

void Orange::displayPlayers() {
    for (int i = 0; i < _player_count; i++) {
        cout << "Orange Players: " << _player[i].stamina << endl;
    }
}