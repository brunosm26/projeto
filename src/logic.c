#include "logic.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

Pergunta* carregarPerguntas(int *total) {
    *total = 10; // mínimo 10 perguntas

    Pergunta *perguntas = malloc(sizeof(Pergunta) * (*total));
    if (!perguntas) return NULL;

    // Perguntas de lógica proposicional
    strcpy(perguntas[0].pergunta, "Se P é verdadeiro e Q é falso, P ∧ Q é?");
    strcpy(perguntas[0].opcao[0], "Verdadeiro");
    strcpy(perguntas[0].opcao[1], "Falso");
    strcpy(perguntas[0].opcao[2], "Indefinido");
    strcpy(perguntas[0].opcao[3], "Nenhum");
    perguntas[0].correta = 1;

    strcpy(perguntas[1].pergunta, "Se P é falso e Q é verdadeiro, P ∨ Q é?");
    strcpy(perguntas[1].opcao[0], "Verdadeiro");
    strcpy(perguntas[1].opcao[1], "Falso");
    strcpy(perguntas[1].opcao[2], "Indefinido");
    strcpy(perguntas[1].opcao[3], "Nenhum");
    perguntas[1].correta = 0;

    strcpy(perguntas[2].pergunta, "Negação de (P ∧ Q) é equivalente a?");
    strcpy(perguntas[2].opcao[0], "¬P ∨ ¬Q");
    strcpy(perguntas[2].opcao[1], "¬P ∧ ¬Q");
    strcpy(perguntas[2].opcao[2], "P ∨ Q");
    strcpy(perguntas[2].opcao[3], "P ∧ Q");
    perguntas[2].correta = 0;

    strcpy(perguntas[3].pergunta, "Se P → Q é verdadeiro e P é verdadeiro, Q é?");
    strcpy(perguntas[3].opcao[0], "Verdadeiro");
    strcpy(perguntas[3].opcao[1], "Falso");
    strcpy(perguntas[3].opcao[2], "Indefinido");
    strcpy(perguntas[3].opcao[3], "Nenhum");
    perguntas[3].correta = 0;

    strcpy(perguntas[4].pergunta, "Se ¬P é verdadeiro, P é?");
    strcpy(perguntas[4].opcao[0], "Verdadeiro");
    strcpy(perguntas[4].opcao[1], "Falso");
    strcpy(perguntas[4].opcao[2], "Indefinido");
    strcpy(perguntas[4].opcao[3], "Nenhum");
    perguntas[4].correta = 1;

    strcpy(perguntas[5].pergunta, "A tautologia é uma proposição que é?");
    strcpy(perguntas[5].opcao[0], "Sempre falsa");
    strcpy(perguntas[5].opcao[1], "Sempre verdadeira");
    strcpy(perguntas[5].opcao[2], "Depende de P");
    strcpy(perguntas[5].opcao[3], "Indefinida");
    perguntas[5].correta = 1;

    strcpy(perguntas[6].pergunta, "Contradição é uma proposição que é?");
    strcpy(perguntas[6].opcao[0], "Sempre falsa");
    strcpy(perguntas[6].opcao[1], "Sempre verdadeira");
    strcpy(perguntas[6].opcao[2], "Depende de P");
    strcpy(perguntas[6].opcao[3], "Indefinida");
    perguntas[6].correta = 0;

    strcpy(perguntas[7].pergunta, "Lei de De Morgan: ¬(P ∨ Q) é equivalente a?");
    strcpy(perguntas[7].opcao[0], "¬P ∧ ¬Q");
    strcpy(perguntas[7].opcao[1], "¬P ∨ ¬Q");
    strcpy(perguntas[7].opcao[2], "P ∧ Q");
    strcpy(perguntas[7].opcao[3], "P ∨ Q");
    perguntas[7].correta = 0;

    strcpy(perguntas[8].pergunta, "Lei de De Morgan: ¬(P ∧ Q) é equivalente a?");
    strcpy(perguntas[8].opcao[0], "¬P ∨ ¬Q");
    strcpy(perguntas[8].opcao[1], "¬P ∧ ¬Q");
    strcpy(perguntas[8].opcao[2], "P ∨ Q");
    strcpy(perguntas[8].opcao[3], "P ∧ Q");
    perguntas[8].correta = 0;

    strcpy(perguntas[9].pergunta, "P ↔ Q é verdadeiro se e somente se?");
    strcpy(perguntas[9].opcao[0], "P e Q têm o mesmo valor");
    strcpy(perguntas[9].opcao[1], "P ou Q é verdadeiro");
    strcpy(perguntas[9].opcao[2], "P e Q são falsos");
    strcpy(perguntas[9].opcao[3], "P ou Q é falso");
    perguntas[9].correta = 0;

    return perguntas;
}

int sortearPergunta(Pergunta *perguntas, int total) {
    return rand() % total;
}

// Wrapper antigo

