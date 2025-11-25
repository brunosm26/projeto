#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "board.h"
#include "logic.h"

// Inicializa o jogo (tabuleiro e jogadores)
void initGame(Player *p1, Player *p2, Board *board);

// Retorna o vencedor após jogar o jogo completo
Player* iniciarJogo(Player *p1, Player *p2);

// Verifica se a casa é de pergunta
int ehCasaPergunta(int pos);

// Exibe a pergunta com timer visível e indica para qual jogador
// Retorna 1 se acertou, 0 se errou
//int mostrarPerguntaComTimer(Pergunta *p, const char *jogador);

// Exibe o tabuleiro com emojis de cavalos
void printBoard(Board *board, int pos1, int pos2);

#endif
