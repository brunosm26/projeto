#ifndef PLAYER_H
#define PLAYER_H

#define MAX_NOME 50
#define MAX_PISTE 15

typedef struct {
    char nome[MAX_NOME];
    int pos;
    int penalidade;
    int cliques; // opcional (se quiser contar cliques)
    int respondeuCasa[MAX_PISTE]; // marca se já respondeu naquela casa (1) ou não (0)
    int tempo; // tempo de corrida (s)
} Player;

void initPlayer(Player *p, const char *nome);
void processarClique(Player *p);

#endif // PLAYER_H
