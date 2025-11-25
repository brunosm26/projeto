#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ranking.h"

#define MAX_RANKING 200

Ranking carregarRanking(const char *arquivo) {
    Ranking r;
    r.entries = malloc(sizeof(RankingEntry) * MAX_RANKING);
    r.quantidade = 0;
    FILE *f = fopen(arquivo, "r");
    if (!f) return r;
    while (fscanf(f, "%49s %d", r.entries[r.quantidade].nome, &r.entries[r.quantidade].tempo) == 2) {
        r.quantidade++;
        if (r.quantidade >= MAX_RANKING) break;
    }
    fclose(f);
    return r;
}

void adicionarResultado(Ranking *ranking, const char *nome, int tempo) {
    // se já existe, atualiza se tempo melhor
    for (int i = 0; i < ranking->quantidade; i++) {
        if (strcmp(ranking->entries[i].nome, nome) == 0) {
            if (tempo < ranking->entries[i].tempo) ranking->entries[i].tempo = tempo;
            return;
        }
    }
    // adiciona novo
    strcpy(ranking->entries[ranking->quantidade].nome, nome);
    ranking->entries[ranking->quantidade].tempo = tempo;
    ranking->quantidade++;
    // ordenar por tempo ascendente (simples bubble)
    for (int i = 0; i < ranking->quantidade - 1; i++) {
        for (int j = i + 1; j < ranking->quantidade; j++) {
            if (ranking->entries[i].tempo > ranking->entries[j].tempo) {
                RankingEntry tmp = ranking->entries[i];
                ranking->entries[i] = ranking->entries[j];
                ranking->entries[j] = tmp;
            }
        }
    }
}

void salvarRanking(const Ranking *ranking, const char *arquivo) {
    FILE *f = fopen(arquivo, "w");
    if (!f) return;
    for (int i = 0; i < ranking->quantidade; i++) {
        fprintf(f, "%s %d\n", ranking->entries[i].nome, ranking->entries[i].tempo);
    }
    fclose(f);
}

void exibirRanking(const Ranking *ranking) {
    if (ranking->quantidade == 0) {
        printf("Nenhum registro ainda.\n");
        return;
    }
    for (int i = 0; i < ranking->quantidade; i++) {
        printf("%dº - %s : %d s\n", i+1, ranking->entries[i].nome, ranking->entries[i].tempo);
    }
}

void liberarRanking(Ranking *ranking) {
    if (ranking->entries) free(ranking->entries);
    ranking->entries = NULL;
    ranking->quantidade = 0;
}
