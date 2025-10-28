#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função auxiliar para verificar se uma posição está livre
int posicaoLivre(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    return tabuleiro[linha][coluna] == 0;
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Navio horizontal
    int linhaNavioH = 1;
    int colunaNavioH = 2;

    // Navio vertical
    int linhaNavioV = 4;
    int colunaNavioV = 6;

    // Navio diagonal descendente (\)
    int linhaNavioD1 = 0;
    int colunaNavioD1 = 0;

    // Navio diagonal ascendente (/)
    int linhaNavioD2 = 9;
    int colunaNavioD2 = 2;

    // 2. Posicionando navio horizontal
    if (colunaNavioH + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (!posicaoLivre(tabuleiro, linhaNavioH, colunaNavioH + i)) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaNavioH][colunaNavioH + i] = 3;
            }
        }
    }

    // 3. Posicionando navio vertical
    if (linhaNavioV + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (!posicaoLivre(tabuleiro, linhaNavioV + i, colunaNavioV)) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaNavioV + i][colunaNavioV] = 3;
            }
        }
    }

    // 4. Posicionando navio diagonal descendente (\)
    if (linhaNavioD1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        colunaNavioD1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (!posicaoLivre(tabuleiro, linhaNavioD1 + i, colunaNavioD1 + i)) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaNavioD1 + i][colunaNavioD1 + i] = 3;
            }
        }
    }

    // 5. Posicionando navio diagonal ascendente (/)
    if (linhaNavioD2 - TAMANHO_NAVIO + 1 >= 0 &&
        colunaNavioD2 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (!posicaoLivre(tabuleiro, linhaNavioD2 - i, colunaNavioD2 + i)) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaNavioD2 - i][colunaNavioD2 + i] = 3;
            }
        }
    }

    // 6. tabuleiro
    printf("Tabuleiro Batalha Naval (0=água, 3=navio):\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
