# 🐎 Corrida dos Cavalos

Um jogo de corrida de cavalos para terminal, com perguntas de lógica proposicional, ranking de vencedores e pista com emojis.

---

## 🎮 Contexto do Jogo

Dois jogadores competem numa corrida de cavalos. O objetivo é chegar primeiro à linha de chegada, avançando casas ao pressionar teclas específicas. Algumas casas são especiais e possuem perguntas de lógica proposicional. Se o jogador acertar, avança mais uma casa. Se errar, recua duas casas.

O jogo é baseado em cliques, onde os jogadores podem apertar suas teclas a qualquer momento. A cada 3 cliques o cavalo anda uma casa.
 O tempo de resposta para perguntas é limitado, e o ranking é persistente, salvando apenas o vencedor de cada partida.

---

## 🏁 Mecânica do Jogo

- Cada jogador tem uma tecla específica para avançar:  
  - Jogador 1: `A`  
  - Jogador 2: `L`  
- Casas de pergunta: **4, 9 e 13**  
- Quando um jogador chega em uma casa de pergunta:
  - Aparece uma pergunta de lógica proposicional **identificando o jogador**  
  - Timer de **20 segundos** visível  
  - Aceita apenas teclas `1..4` para resposta  
  - Acertando: avança 1 casa  
  - Errando ou tempo esgotado: recua 2 casas  
- A pista é mostrada com **emojis**:
  - 🐎 para o jogador  
  - ⬜ para casas livres  
  - 🏁 linha de chegada  
- O jogo termina quando um jogador alcança a última casa da pista.  
- Ao final, mostra o **vencedor e o tempo** da corrida, aguardando ENTER para voltar ao menu.

---

## 🏆 Sistema de Pontuação

- Apenas o vencedor da corrida tem seu resultado salvo no ranking.  
- Ranking persistente no arquivo `ranking.txt`.  
- Exibe nome e tempo do vencedor em segundos.

---

## 🛠️ Como Rodar

1. Clone o repositório:
   ```bash
   git clone https://github.com/seuusuario/projeto.git
   cd projeto
2. Compile 
    make
3. Execute
    ./build/jogo