#include <stdio.h>
#include <stdlib.h>

int main() {
    char tabuleiro[3][3];
    int linha, coluna; 
    int i, j;
    int jogadas;
    int ganhou;
    char jogador;
    int opcao;

    opcao = 1; 

    while (opcao == 1) {
        
        // 1. ZERAR O TABULEIRO (Preenche com espacos vazios)
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                tabuleiro[i][j] = ' ';
            }
        }

        jogadas = 0;
        ganhou = 0;
        jogador = 'X'; 

        // 2. LOOP PRINCIPAL DO JOGO
        while (jogadas < 9 && ganhou == 0) {
            
            // Mostra o tabuleiro formatado no terminal
            printf("\n    0   1   2\n\n");
            printf("0   %c | %c | %c \n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
            printf("   ---+---+---\n");
            printf("1   %c | %c | %c \n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
            printf("   ---+---+---\n");
            printf("2   %c | %c | %c \n\n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);

            // Solicita as coordenadas para o usuario
            printf("Digite a proxima jogada do jogador %c (linha coluna): ", jogador);
            scanf("%d %d", &linha, &coluna);

            // VALIDACAO: Testa se a posicao esta dentro da matriz e se esta livre
            if (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3 && tabuleiro[linha][coluna] == ' ') {
                
                tabuleiro[linha][coluna] = jogador;
                jogadas = jogadas + 1; 

                // VERIFICAR SE ALGUEM GANHOU
                // Testando as linhas do tabuleiro
                if (tabuleiro[0][0] == jogador && tabuleiro[0][1] == jogador && tabuleiro[0][2] == jogador) ganhou = 1;
                if (tabuleiro[1][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[1][2] == jogador) ganhou = 1;
                if (tabuleiro[2][0] == jogador && tabuleiro[2][1] == jogador && tabuleiro[2][2] == jogador) ganhou = 1;

                // Testando as colunas do tabuleiro
                if (tabuleiro[0][0] == jogador && tabuleiro[1][0] == jogador && tabuleiro[2][0] == jogador) ganhou = 1;
                if (tabuleiro[0][1] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][1] == jogador) ganhou = 1;
                if (tabuleiro[0][2] == jogador && tabuleiro[1][2] == jogador && tabuleiro[2][2] == jogador) ganhou = 1;

                // Testando as duas diagonais
                if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) ganhou = 1;
                if (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador) ganhou = 1;

                // Verifica o fim do turno
                if (ganhou == 1) {
                    // Mostra o tabuleiro final com o vencedor
                    printf("\n    0   1   2\n\n");
                    printf("0   %c | %c | %c \n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
                    printf("   ---+---+---\n");
                    printf("1   %c | %c | %c \n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
                    printf("   ---+---+---\n");
                    printf("2   %c | %c | %c \n\n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
                    
                    printf("O jogador %c venceu!!\n", jogador);
                } else {
                    // Alterna o turno entre os jogadores X e O
                    if (jogador == 'X') {
                        jogador = 'O';
                    } else {
                        jogador = 'X';
                    }
                }

            } else {
                printf("\nJogada errada! Essa posicao nao vale ou ja esta ocupada.\n");
            }
        }

        // Se preencheu tudo e ninguem ganhou, deu empate
        if (ganhou == 0) {
            printf("Deu empate! O jogo acabou.\n");
        }

        // 3. CONTROLE POS-JOGO (Menu para reiniciar ou sair)
        printf("\nDeseja jogar de novo? (Digite 1 para Sim ou 0 para Nao): ");
        scanf("%d", &opcao);
    }

    printf("Fim do programa!\n");
    return 0;
}
