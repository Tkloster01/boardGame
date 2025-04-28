#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <fstream>

using namespace std;

class Apple
{
private:
    string line;
    ifstream character;
    Player _player[4];

public:
    void setUp();
    void displayCharFile();
    void updateCharFile(int selection);
    void saveCharacter(int player_count);
    void updateCharacter();
};

#endif