





#include <stdio.h>

// Function to print the Tic Tac Toe board
void printBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---+---+---\n");
    }
}

// Function to check if the game is over
int isGameOver(char board[3][3]) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1;
    }
    
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return 1;
    }
    
    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' '))
        return 1;
    
    // Check for a draw
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return 0;
        }
    }
    
    return -1; // Draw
}

int main(void) {
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    int currentPlayer = 1; // Player 1 starts
    
    while (1) {
        printf("Tic Tac Toe\n");
        printBoard(board);
        
        int row, col;
        printf("Player %d, enter row and column (1-3) separated by a space: ", currentPlayer);
        scanf("%d %d", &row, &col);
        
        // Adjust for 0-based indexing
        row--;
        col--;
        
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }
        
        board[row][col] = (currentPlayer == 1) ? 'X' : 'O';
        
        if (isGameOver(board) == 1) {
            printf("Player %d wins!\n", currentPlayer);
            break;
        } else if (isGameOver(board) == -1) {
            printf("It's a draw!\n");
            break;
        }
        
        currentPlayer = (currentPlayer == 1) ? 2 : 1; // Switch players
    }
    
    return 0;
}

    
