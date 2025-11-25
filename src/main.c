#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "game.h"
#include "ranking.h"
#include "player.h"
#include "board.h"

#define ARQUIVO_RANKING "ranking.txt"
#define MAX_NOME 50

void limparTela() { system("clear"); }
void pausar() { printf("\nPressione ENTER para continuar..."); getchar(); }

void telaInicial() {
    printf("=========================================\n");
    printf("         🐎 Horses's Logic Race 🐎       \n");
    printf("=========================================\n");
    printf("1 - Iniciar Jogo\n");
    printf("2 - Mostrar Ranking\n");
    printf("3 - Sair\n");
    printf("=========================================\n");
}

int main(void) {
    setlocale(LC_ALL, "");
    int opcao;
    char reiniciar = 1;

    while (reiniciar) {
        limparTela();
        telaInicial();
        if (scanf("%d", &opcao) != 1) { getchar(); continue; }
        getchar();

        if (opcao == 1) {
            limparTela();
            printf("===== INICIAR JOGO =====\n\n");

            char nome1[MAX_NOME], nome2[MAX_NOME];
            printf("Digite o nome do Jogador 1: ");
            fgets(nome1, MAX_NOME, stdin);
            nome1[strcspn(nome1, "\n")] = '\0';

            printf("Digite o nome do Jogador 2: ");
            fgets(nome2, MAX_NOME, stdin);
            nome2[strcspn(nome2, "\n")] = '\0';

            Player p1, p2;
            initPlayer(&p1, nome1);
            initPlayer(&p2, nome2);

            Player *vencedor = iniciarJogo(&p1, &p2); // mensagem de vencedor já exibida dentro do jogo

            // Salva apenas o vencedor no ranking
            Ranking r = carregarRanking(ARQUIVO_RANKING);
            adicionarResultado(&r, vencedor->nome, vencedor->tempo);
            salvarRanking(&r, ARQUIVO_RANKING);
            liberarRanking(&r);

        }
        else if (opcao == 2) {
            limparTela();
            printf("===== RANKING =====\n\n");
            Ranking r = carregarRanking(ARQUIVO_RANKING);
            exibirRanking(&r);
            liberarRanking(&r);
            pausar();
        }
        else if (opcao == 3) {
            printf("Saindo...\n");
            reiniciar = 0;
        }
        else {
            printf("Opção inválida!\n");
            pausar();
        }
    }

    return 0;
}
