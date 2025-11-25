#include <stdio.h>
#include "board.h"
#include "screen.h"

void initBoard(Board *b) {
    b->tamanho = 15;
}

void printBoard(Board *b, int pos1, int pos2) {
    screenClear();

    // Linha cabeçalho
    printf("Pista: (alvo = %d)  Casas de pergunta: 3,6,9,12\n\n", b->tamanho-1);

    // Imprime índices (0..)
    printf("   ");
    for (int i = 0; i < b->tamanho; i++) printf("%3d", i);
    printf("\n");

    // Linha jogadores com blocos fixos de 3 chars
    printf("P1 ");
    for (int i = 0; i < b->tamanho; i++) {
        if (i == pos1) printf("[1]");
        else printf("[ ]");
    }
    printf("\n");

    printf("P2 ");
    for (int i = 0; i < b->tamanho; i++) {
        if (i == pos2) printf("[2]");
        else printf("[ ]");
    }
    printf("\n");
}
