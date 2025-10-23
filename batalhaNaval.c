#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // 1. Tabuleiro 10x10 e inicializando com 0 (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // 2. Coordenadas iniciais dos navios
    // Navio horizontal
    int linhaNavioH = 2; 
    int colunaNavioH = 3; 
    // Navio vertical
    int linhaNavioV = 5; 
    int colunaNavioV = 7; 

    // 3. Posicionando navio horizontal 
    if (colunaNavioH + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaNavioH][colunaNavioH + i] = 3; 
        }
    } else {
        printf("Navio horizontal não cabe nessa posição!\n");
    }

    // 4. Posicionando navio vertical 
    if (linhaNavioV + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaNavioV + i][colunaNavioV] = 3; 
        }
    } else {
        printf("Navio vertical não cabe nessa posição!\n");
    }

    // 5. Exibindo o tabuleiro
    printf("Tabuleiro Batalha Naval:\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
