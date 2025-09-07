#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer;

// Function to initialize the board with numbers 1-9
void initializeBoard() {
    char num = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = num++;
        }
    }
    currentPlayer = 'X';
}

// Function to display the board
void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

// Function to switch players
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Function to make a move
bool makeMove(int cell) {
    int row = (cell - 1) / 3;
    int col = (cell - 1) % 3;
    if (cell < 1 || cell > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Invalid move! Try again.\n";
        return false;
    }
    board[row][col] = currentPlayer;
    return true;
}

// Function to check for a win
bool checkWin() {
    for (int i = 0; i < 3; i++) {
        // Check rows and columns
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer))
            return true;
    }
    // Check diagonals
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer))
        return true;

    return false;
}

// Function to check for a draw
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

int main() {
    char playAgain;
    do {
        initializeBoard();
        bool gameOver = false;
        cout << "=== Tic-Tac-Toe Game ===\n";
        displayBoard();
        while (!gameOver) {
            int cell;
            cout << "Player " << currentPlayer << ", enter a cell number (1-9): ";
            cin >> cell;
            if (makeMove(cell)) {
                displayBoard();

                if (checkWin()) {
                    cout << " Player " << currentPlayer << " wins!\n";
                    gameOver = true;
                } else if (checkDraw()) {
                    cout << "It's a draw! \n";
                    gameOver = true;
                } else {
                    switchPlayer();
                }
            }
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing! \n";
    return 0;
}
