#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5
#define NAVIOS 3

void mostrar(char t[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%c ", t[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char tab[TAM][TAM];
    int ln[NAVIOS], col[NAVIOS], acertos = 0, tent = 0;

    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tab[i][j] = '~';

    srand(time(NULL));
    for (int i = 0; i < NAVIOS; i++) {
        ln[i] = rand() % TAM;
        col[i] = rand() % TAM;
        for (int j = 0; j < i; j++)
            if (ln[i] == ln[j] && col[i] == col[j]) { i--; break; }
    }

    printf("🚢 Batalha Naval em C!\n");

    while (acertos < NAVIOS) {
        int l, c, ac = 0;
        mostrar(tab);
        printf("\nLinha (0-%d): ", TAM-1);
        scanf("%d", &l);
        printf("Coluna (0-%d): ", TAM-1);
        scanf("%d", &c);

        if (l < 0 || l >= TAM || c < 0 || c >= TAM) {
            printf("❌ Fora do tabuleiro!\n");
            continue;
        }

        tent++;
        for (int i = 0; i < NAVIOS; i++) {
            if (l == ln[i] && c == col[i]) {
                printf("💥 Acertou!\n");
                tab[l][c] = 'X';
                ln[i] = col[i] = -1;
                acertos++;
                ac = 1;
                break;
            }
        }
        if (!ac) {
            printf("🌊 Água...\n");
            tab[l][c] = 'O';
        }
    }

    printf("\n🎉 Você afundou todos os navios em %d tentativas!\n", tent);
    return 0;
}