#ifndef LOGIC_H
#define LOGIC_H

#define MAX_PERGUNTA 256
#define MAX_OPCAO 100

typedef struct {
    char pergunta[MAX_PERGUNTA];
    char opcao[4][MAX_OPCAO];
    int correta;
} Pergunta;

// Carrega perguntas de lógica proposicional
Pergunta* carregarPerguntas(int *quantidade);

// Função de pergunta que recebe jogador
int perguntar(Pergunta p, const char *jogador);

// Sorteia uma pergunta aleatória
int sortearPergunta(Pergunta *perguntas, int total);

#endif
