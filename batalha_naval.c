#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 5
#define NAVIOS 3

void mostrarTabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char tabuleiro[TAMANHO][TAMANHO];
    int naviosLinha[NAVIOS];
    int naviosColuna[NAVIOS];
    int acertos = 0, tentativas = 0;

    // Inicializar tabuleiro com água
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = '~';
        }
    }

    // Gerar posições aleatórias dos navios
    srand(time(NULL));
    for (int i = 0; i < NAVIOS; i++) {
        naviosLinha[i] = rand() % TAMANHO;
        naviosColuna[i] = rand() % TAMANHO;
        // Evitar navios na mesma posição
        for (int j = 0; j < i; j++) {
            if (naviosLinha[i] == naviosLinha[j] && naviosColuna[i] == naviosColuna[j]) {
                i--; // repete a geração dessa posição
                break;
            }
        }
    }

    printf("🚢 Bem-vindo ao Batalha Naval em C!\n");
    printf("Tente encontrar %d navios no tabuleiro %dx%d.\n\n", NAVIOS, TAMANHO, TAMANHO);

    while (acertos < NAVIOS) {
        int linha, coluna;
        mostrarTabuleiro(tabuleiro);

        printf("\nDigite a linha (0-%d): ", TAMANHO - 1);
        scanf("%d", &linha);
        printf("Digite a coluna (0-%d): ", TAMANHO - 1);
        scanf("%d", &coluna);

        if (linha < 0 || linha >= TAMANHO || coluna < 0 || coluna >= TAMANHO) {
            printf("❌ Fora do tabuleiro! Tente novamente.\n");
            continue;
        }

        tentativas++;

        int acertou = 0;
        for (int i = 0; i < NAVIOS; i++) {
            if (linha == naviosLinha[i] && coluna == naviosColuna[i]) {
                printf("💥 Você acertou um navio!\n");
                tabuleiro[linha][coluna] = 'X';
                naviosLinha[i] = -1; // marca como destruído
                naviosColuna[i] = -1;
                acertos++;
                acertou = 1;
                break;
            }
        }

        if (!acertou) {
            printf("🌊 Água...\n");
            tabuleiro[linha][coluna] = 'O';
        }
    }

    printf("\n🎉 Parabéns! Você afundou todos os navios em %d tentativas.\n", tentativas);

    return 0;
}
