#ifndef BOARD_H
#define BOARD_H

typedef struct {
    int tamanho;
} Board;

void initBoard(Board *b);
void printBoard(Board *b, int pos1, int pos2);

#endif // BOARD_H
