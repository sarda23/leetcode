// . Snake and Ladder Game (OOP Design)

// Problem: Design a Snake and Ladder game for two players. Implement the following features:

//     A board with 100 cells.
//     Several snakes and ladders placed on the board.
//     Two players should be able to roll a die and move forward.
//     If a player lands on a snake, they should move down to the snake's tail.
//     If they land on a ladder, they move up to the ladder's top.
//     The first player to reach the 100th cell wins.

// Approach:

//     Classes: You'll need classes for:
//         Player: Stores player information like name and current position.
//         Board: Handles the setup of the board, positions of snakes and ladders, and the die rolls.
//         Game: Manages the game flow, checking for the winner, and taking turns.

//     Steps:
//         Roll the die to get a random number between 1 and 6.
//         Move the player according to the die roll.
//         Check if the player landed on a snake or a ladder and update their position.
//         Continue until one of the players reaches the last cell.



#include <iostream>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Player class representing a player in the game
class Player {
public:
    string name;
    int position;

    Player(string playerName) {
        name = playerName;
        position = 0;  // All players start at position 0
    }
};

// Board class representing the snake and ladder game board
class Board {
private:
    map<int, int> snakes;  // Snake positions (key: snake head, value: snake tail)
    map<int, int> ladders; // Ladder positions (key: ladder base, value: ladder top)
    
public:
    Board() {
        // Define the snake positions
        snakes[16] = 6;
        snakes[48] = 26;
        snakes[49] = 11;
        snakes[56] = 53;
        snakes[62] = 19;
        snakes[64] = 60;
        snakes[87] = 24;
        snakes[93] = 73;
        snakes[95] = 75;
        snakes[98] = 78;

        // Define the ladder positions
        ladders[1] = 38;
        ladders[4] = 14;
        ladders[9] = 31;
        ladders[21] = 42;
        ladders[28] = 84;
        ladders[36] = 44;
        ladders[51] = 67;
        ladders[71] = 91;
        ladders[80] = 100;
    }

    int movePlayer(Player &player, int roll) {
        int newPosition = player.position + roll;

        if (newPosition > 100) {
            return player.position; // Player can't move beyond 100
        }

        // Check for snake or ladder
        if (snakes.find(newPosition) != snakes.end()) {
            cout << player.name << " bitten by a snake! Moving down to " << snakes[newPosition] << endl;
            return snakes[newPosition];
        }

        if (ladders.find(newPosition) != ladders.end()) {
            cout << player.name << " climbed a ladder! Moving up to " << ladders[newPosition] << endl;
            return ladders[newPosition];
        }

        return newPosition;
    }
};

// Game class to manage the flow of the game
class Game {
private:
    Board board;
    vector<Player> players;

public:
    Game(vector<Player> playersList) {
        players = playersList;
        srand(time(0));  // Seed for random number generation
    }

    void play() {
        while (true) {
            for (Player &player : players) {
                int roll = (rand() % 6) + 1;
                cout << player.name << " rolls a " << roll << endl;
                player.position = board.movePlayer(player, roll);
                cout << player.name << " is now on position " << player.position << endl;

                if (player.position == 100) {
                    cout << player.name << " wins the game!" << endl;
                    return;
                }
            }
        }
    }
};

// Main function
int main() {
    // Create two players
    Player player1("Alice");
    Player player2("Bob");

    // Add players to the game
    vector<Player> players = { player1, player2 };

    // Start the game
    Game game(players);
    game.play();

    return 0;
}


// Explanation:

//     Player class: Holds the player's name and position.
//     Board class: Manages the snakes and ladders and updates the player's position based on their roll.
//     Game class: Handles the game flow, including taking turns, rolling the dice, and checking for a winner.
//     Main function: Initializes two players and starts the game.

// This is a basic implementation of the Snake and Ladder game using object-oriented principles in C++. You can extend this further by adding features like:

//     Allowing more players.
//     Letting players choose their dice rolls or have different win conditions.