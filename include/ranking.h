#ifndef RANKING_H
#define RANKING_H

#define MAX_NOME_RANKING 50

typedef struct {
    char nome[MAX_NOME_RANKING];
    int tempo; // segundos (menor é melhor)
} RankingEntry;

typedef struct {
    RankingEntry *entries;
    int quantidade;
} Ranking;

Ranking carregarRanking(const char *arquivo);
void adicionarResultado(Ranking *ranking, const char *nome, int tempo);
void salvarRanking(const Ranking *ranking, const char *arquivo);
void exibirRanking(const Ranking *ranking);
void liberarRanking(Ranking *ranking);

#endif // RANKING_H
