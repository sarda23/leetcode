//  Tic-Tac-Toe Game

// Problem: Design a Tic-Tac-Toe game that allows two players to play the game on a 3x3 board. The game should support:

//     Two players taking turns.
//     Declaring a winner when one player achieves three consecutive marks either in a row, column, or diagonal.
//     Detecting a draw if the board is full with no winner.


#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {
private:
    vector<vector<char>> board;
    char currentPlayer;

    // Check if the current player has won
    bool checkWinner() {
        // Check rows and columns
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
                return true;
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
                return true;
        }

        // Check diagonals
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
            return true;
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
            return true;

        return false;
    }

    // Check if the board is full (draw)
    bool isBoardFull() {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[i][j] == ' ')
                    return false;
        return true;
    }

public:
    // Initialize the game
    TicTacToe() {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        currentPlayer = 'X';
    }

    // Print the board
    void printBoard() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j];
                if (j < 2) cout << " | ";
            }
            cout << endl;
            if (i < 2) cout << "---------" << endl;
        }
    }

    // Play a turn at a specific position
    bool playTurn(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move!" << endl;
            return false;
        }

        board[row][col] = currentPlayer;
        printBoard();

        if (checkWinner()) {
            cout << "Player " << currentPlayer << " wins!" << endl;
            return true;
        }

        if (isBoardFull()) {
            cout << "It's a draw!" << endl;
            return true;
        }

        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        return false;
    }

    // Add a function to get the current player
    char getCurrentPlayer() {
        return currentPlayer;
    }
};

// Main function
int main() {
    TicTacToe game;

    // Example game sequence
    game.printBoard();

    while (true) {
        int row, col;
        cout << "Enter row and column (0-2) for player " << game.getCurrentPlayer() << ": ";
        cin >> row >> col;

        if (game.playTurn(row, col))
            break;
    }

    return 0;
}




// Explanation:

//     TicTacToe Class: Manages the game board, the current player, and the game logic to check for winners or draws.
//     The main() function runs a loop to take player inputs, update the board, and check for game-over conditions.