#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "game.h"
#include "player.h"
#include "board.h"
#include "logic.h"
#include "screen.h"
#include "keyboard.h"

#define TEMPO_PERGUNTA 20

int ehCasaPergunta(int pos) {
    return (pos == 4 || pos == 9 || pos == 13);
}

// Mostra pergunta com timer; retorna 1 se acertou, 0 se errou
static int mostrarPerguntaComTimer(Pergunta *p, const char *jogador) {
    while (keyhit()) readch(); // limpa teclas pendentes

    time_t inicio = time(NULL);
    char resp = 0;
    while (1) {
        screenClear();
        printf("===== PERGUNTA - %s =====\n\n", jogador);
        printf("%s\n\n", p->pergunta);
        for (int i = 0; i < 4; i++) printf("%2d) %s\n", i+1, p->opcao[i]);
        int restante = TEMPO_PERGUNTA - (int)difftime(time(NULL), inicio);
        if (restante < 0) restante = 0;
        printf("\nTempo restante: %2d s  (digite 1-4)\n", restante);
        fflush(stdout);

        if (keyhit()) {
            resp = readch();
            if (resp >= '1' && resp <= '4') break;
        }

        if (difftime(time(NULL), inicio) >= TEMPO_PERGUNTA) return 0;
        usleep(100000);
    }

    int alternativa = resp - '1';
    if (alternativa == p->correta) {
        printf("\n✔ Resposta correta! Avança +1 casa!\n");
        sleep(2);
        return 1;
    } else {
        printf("\n✘ Resposta incorreta! Volta 2 casas!\n");
        sleep(2);
        return 0;
    }
}

int perguntar(Pergunta p, const char *jogador) {
    return mostrarPerguntaComTimer(&p, jogador);
}

// Imprime a pista com emojis, linhas separadas para cada jogador
void printBoardEmoji(Board *board, int pos1, int pos2) {
    screenClear();
    printf("===== PISTA =====\n\n");

    // Linha jogador 1
    for (int i = 0; i < board->tamanho; i++) {
        if (i == pos1)
            printf("🐎 ");
        else if (i == board->tamanho - 1)
            printf("🏁 ");
        else
            printf("⬜ ");
    }
    printf(" <- Jogador 1\n");

    // Linha jogador 2
    for (int i = 0; i < board->tamanho; i++) {
        if (i == pos2)
            printf("🐎 ");
        else if (i == board->tamanho - 1)
            printf("🏁 ");
        else
            printf("⬜ ");
    }
    printf(" <- Jogador 2\n\n");
}

void initGame(Player *p1, Player *p2, Board *board) {
    initBoard(board);
    initPlayer(p1, p1->nome);
    initPlayer(p2, p2->nome);
}

Player* iniciarJogo(Player *p1, Player *p2) {
    Board board;
    initBoard(&board);
    initPlayer(p1, p1->nome);
    initPlayer(p2, p2->nome);

    int totalPerg = 0;
    Pergunta *perguntas = carregarPerguntas(&totalPerg);
    srand((unsigned)time(NULL));
    time_t inicio = time(NULL);

    // Marca que nenhuma casa foi respondida
    for (int i = 0; i < board.tamanho; i++) {
        p1->respondeuCasa[i] = 0;
        p2->respondeuCasa[i] = 0;
    }

    keyboardInit();
    screenHideCursor();

    while (1) {
        printBoardEmoji(&board, p1->pos, p2->pos);

        // Vitória jogador 1
        if (p1->pos >= board.tamanho - 1) {
            p1->tempo = (int)difftime(time(NULL), inicio);
            printBoardEmoji(&board, p1->pos, p2->pos);
            printf("\n🏆 %s venceu! Tempo: %d segundos! 🏆\n", p1->nome, p1->tempo);
            printf("Pressione ENTER para voltar ao menu...");
            int c; while ((c = getchar()) != '\n' && c != EOF);
            getchar(); // espera ENTER real
            keyboardRestore();
            screenShowCursor();
            free(perguntas);
            return p1;
        }

        // Vitória jogador 2
        if (p2->pos >= board.tamanho - 1) {
            p2->tempo = (int)difftime(time(NULL), inicio);
            printBoardEmoji(&board, p1->pos, p2->pos);
            printf("\n🏆 %s venceu! Tempo: %d segundos! 🏆\n", p2->nome, p2->tempo);
            printf("Pressione ENTER para voltar ao menu...");
            int c; while ((c = getchar()) != '\n' && c != EOF);
            getchar(); // espera ENTER real
            keyboardRestore();
            screenShowCursor();
            free(perguntas);
            return p2;
        }

        // Leitura de teclas
        if (keyhit()) {
            char c = readch();
            if ((c == 'a' || c == 'A') && p1->penalidade == 0) processarClique(p1);
            if ((c == 'l' || c == 'L') && p2->penalidade == 0) processarClique(p2);
        }

        // Perguntas jogador 1
        if (ehCasaPergunta(p1->pos) && !p1->respondeuCasa[p1->pos]) {
            if (p1->pos < p2->pos || p2->pos != p1->pos) {
                int idx = sortearPergunta(perguntas, totalPerg);
                int ok = mostrarPerguntaComTimer(&perguntas[idx], p1->nome);
                p1->respondeuCasa[p1->pos] = 1;
                if (ok) p1->pos++;
                else {
                    p1->pos -= 2;
                    if (p1->pos < 0) p1->pos = 0;
                }
            }
        }

        // Perguntas jogador 2
        if (ehCasaPergunta(p2->pos) && !p2->respondeuCasa[p2->pos]) {
            if (p2->pos < p1->pos || p1->pos != p2->pos) {
                int idx = sortearPergunta(perguntas, totalPerg);
                int ok = mostrarPerguntaComTimer(&perguntas[idx], p2->nome);
                p2->respondeuCasa[p2->pos] = 1;
                if (ok) p2->pos++;
                else {
                    p2->pos -= 2;
                    if (p2->pos < 0) p2->pos = 0;
                }
            }
        }

        if (p1->penalidade > 0) p1->penalidade--;
        if (p2->penalidade > 0) p2->penalidade--;

        usleep(100000);
    }
}
