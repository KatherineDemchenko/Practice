#include <iostream>

using namespace std;

char board[3][3];
char currentPlayer;

void initializeBoard() {
    char start = '1';
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = start++;
        }
    }
}

void printBoard() {
    cout << "\n";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "--+---+--\n";
    }
    cout << "\n";
}

bool isValidMove(int move) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    return (board[row][col] != 'X' && board[row][col] != 'O');
}

void makeMove(int move) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    board[row][col] = currentPlayer;
}

bool isWinner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
    return false;
}

bool isDraw() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') return false;
        }
    }
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    initializeBoard();
    currentPlayer = 'X';
    int move;
    
    while (true) {
        printBoard();
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;
        
        if (move < 1 || move > 9 || !isValidMove(move)) {
            cout << "Invalid move. Try again.\n";
            continue;
        }
        
        makeMove(move);
        
        if (isWinner()) {
            printBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }
        
        if (isDraw()) {
            printBoard();
            cout << "The game is a draw!\n";
            break;
        }
        
        switchPlayer();
    }
    
    return 0;
}
