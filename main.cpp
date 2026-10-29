#include <iostream>
using namespace std;

char board[3][3];

void resetBoard() {
    char position = '1';

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = position++;
        }
    }
}

void displayBoard() {
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    cout << "---+---+---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    cout << "---+---+---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n\n";
}

bool checkWin(char mark) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == mark &&
            board[i][1] == mark &&
            board[i][2] == mark)
            return true;

        if (board[0][i] == mark &&
            board[1][i] == mark &&
            board[2][i] == mark)
            return true;
    }

    if (board[0][0] == mark &&
        board[1][1] == mark &&
        board[2][2] == mark)
        return true;

    if (board[0][2] == mark &&
        board[1][1] == mark &&
        board[2][0] == mark)
        return true;

    return false;
}

int main() {
    char playAgain = 'Y';

    while (playAgain == 'Y' || playAgain == 'y') {
        resetBoard();

        char currentPlayer = 'X';
        int moves = 0;

        cout << "===== TIC TAC TOE =====\n";
        cout << "Player 1: X | Player 2: O\n";
        cout << "Choose a position from 1 to 9.\n";

        while (moves < 9) {
            displayBoard();

            int move;

            cout << "Player " << currentPlayer << ", enter position: ";

            if (!(cin >> move)) {
                cout << "Invalid input! Enter a number.\n";
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }

            if (move < 1 || move > 9) {
                cout << "Invalid position! Choose 1-9.\n";
                continue;
            }

            int row = (move - 1) / 3;
            int col = (move - 1) % 3;

            if (board[row][col] == 'X' || board[row][col] == 'O') {
                cout << "Position already occupied! Try again.\n";
                continue;
            }

            board[row][col] = currentPlayer;
            moves++;

            if (checkWin(currentPlayer)) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }

            if (moves == 9) {
                displayBoard();
                cout << "It's a draw!\n";
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        cout << "Play again? (Y/N): ";
        cin >> playAgain;
    }

    cout << "Thanks for playing!\n";

    return 0;
}