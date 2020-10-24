#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **initBoard(int len_dimension)
{
    char **board = malloc(sizeof(char *) * len_dimension);
    int i, j;

    // Board[x][ ]: Rows
    // Board[ ][x]: Cols
    for (i = 0; i < len_dimension; i++)
    {
        board[i] = malloc(sizeof(char) * (len_dimension + 1));
        for (j = 0; j < len_dimension; j++)
        {
            board[i][j] = 'O';
        }
        // Not necessary, since treating these char arrays as strings isn't planned
        board[i][j + 1] = '\0';
    }

    return board;
}

void printBoard(char **board)
{
    int i, j;
    int len_dimension = strlen(board[0]);

    for (i = 0; i < len_dimension; i++)
    {
        for (j = 0; j < len_dimension; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

char *solveBoard(char **board, int num_queens)
{

}

int main(void)
{
    int len_dimension = 0, num_queens = 0;
    char **board;

    printf("What is the chess board's dimensions? And the number of queens? (int int): ");
    scanf("%d %d", &len_dimension, &num_queens);

    board = initBoard(len_dimension);

    printBoard(board);
    solveBoard(board, num_queens);

    return 0;
}