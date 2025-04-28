#include "Board.cpp"
#include "Start.cpp"
#include "Turn.cpp"

using namespace std;

int main() {
    srand(time(0));

    Apple characterSheet;
    Orange setUpGame;
    //Lemon normalTurn;

    characterSheet.setUp(); //Creates the duplicate character sheet to read and write to
    int _player_count = setUpGame.totalPlayers(); //Prompts user and stores total players
    characterSheet.displayCharFile(); //Displays initial character choices

    Board gameBoard; // runs the constructor to set up the board

    // Because we want to reference the setUpGame created above, we need to be explicit
    // in how you reference it, the & means that you are passing the address of the object you just created
    characterSheet.saveCharacter(_player_count, &setUpGame);
    gameBoard.fillPlayerList(setUpGame, _player_count);

    setUpGame.displayPlayers();
    characterSheet.displayPlayers(_player_count);
    gameBoard.displayPlayers();

    //First prompt the user for the total number of players >> _player_count
    //Go one by one and ask for their character choice from the text file and path choice (0 for cub, 1 for pride)
    //Use the updateStats function to set up their initial stats. Remove/Add stats based on starting path
    //If they chose the cub path, prompt for advisor choice. Store within the player array

    //Set up a for loop to run through all 5 options to give to each player at a time.
    //1) Check player progress >> use slot integer to display pride points and stats
    //2) Review character >> use slot to display specific character information from the text file
    //3) check position >> prompt full board or path >> display the option using display functions
    //4) Review advisor >> use player.advisor to get advisor information to display
    //5) Move forward >> rand function to roll a random number of spaces to add to player.pos

    //Check once a player has hit the orange tile >> then tally up points and announce the winner
    //Store the winner and their stats onto a .txt file

}