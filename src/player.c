#include <string.h>
#include "player.h"

void initPlayer(Player *p, const char *nome) {
    strncpy(p->nome, nome, MAX_NOME-1);
    p->nome[MAX_NOME-1] = '\0';
    p->pos = 0;
    p->penalidade = 0;
    p->cliques = 0;
    p->tempo = 0;
    for (int i = 0; i < MAX_PISTE; i++) p->respondeuCasa[i] = 0;
}

void processarClique(Player *p) {
    if (p->penalidade > 0) return;
    p->cliques++;
    if (p->cliques >= 3) {
        p->pos++;
        p->cliques = 0;
    }
}
