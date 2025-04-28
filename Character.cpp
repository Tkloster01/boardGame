#include "Character.h"
#include "Board.h"
#include "Start.h"
#include <iostream>

void Apple::setUp(){ // Code to duplicate the regular character text file to be modified
    ofstream creation("characters.txt");
    creation.open("characters.txt");

    fstream character2("characters.txt");

    character.open("charbase.txt");
    
    while(!character.eof()){
        getline(character, line);
        character2 << line << endl;
    }
}

void Apple::displayCharFile(){
    fstream character2("characters.txt");

    getline(character2, line);
    cout << line << endl;

    int j = 0;

    for(int i = 0; i < 7; i++){
        getline(character2, line);
        cout << "(" << j << ")  " << line << endl;
        j++;
    }
}

void Apple::updateCharFile(int selection){
    fstream character2("characters.txt");
    fstream character3("characters.txt");
    int i = 0;

    for(int j = 0; j < 8; ++j){
        getline(character2, line);
        if(i == (selection + 1)){
            character3 << "(Taken)" << endl;
        }
        else{
        character3 << line << endl;
        }
        ++i;
    }
}

void Apple::saveCharacter(int player_count, Orange *CharList) {
    int selection;
    int flag = 0;
    int purple = 0;
    
    int taken[4] = {-10, -10, -10, -10};

    for(int i = 0; i < player_count; ++i){
        cout << "Player " << (i + 1) << " please select a character" << endl;
        cin >> selection;

        for(int j = 0; j < 4; ++j){
            if (taken[j] == selection){
                cout << "Character already taken. Please choose another" << endl;
                j = 4;
                --i;
            }
            // Because we are using a reference to the address, you use a -> instead of a .
            else if (taken[j] != selection && flag == 3){
                CharList -> CharInfo(i, selection); // set the player value in Apple
                _player[i] = CharList -> getPlayer(i); // set the player value in Orange
                

                taken[i] = selection;

                flag = 0;
                ++purple;
                cout << _player[0].stamina << endl;

                updateCharFile(selection);
                if (purple < player_count){
                    displayCharFile();
                }
            }
            else {
                ++flag;
            }
        }
    }
}

void Apple::updateCharacter(){

}

void Apple::displayPlayers(int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        cout << "Apple Players: " << _player[i].stamina << endl;
    }
}