#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // Representa água
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]); // Exibe cada posição do tabuleiro
        }
        printf("\n");
    }
}

// Função para verificar se uma posição está dentro dos limites do tabuleiro
int posicaoValida(int x, int y) {
    return (x >= 0 && x < TAMANHO_TABULEIRO && y >= 0 && y < TAMANHO_TABULEIRO);
}

// Função para verificar se há sobreposição de navios
int sobrepoeNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int posicoes[][2], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        int x = posicoes[i][0];
        int y = posicoes[i][1];
        if (tabuleiro[x][y] != 0) {
            return 1; // Há sobreposição
        }
    }
    return 0; // Não há sobreposição
}

// Função para posicionar um navio horizontal ou vertical
void posicionarNavioHV(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y, int horizontal) {
    int posicoes[TAMANHO_NAVIO][2];
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        posicoes[i][0] = x + (horizontal ? 0 : i);
        posicoes[i][1] = y + (horizontal ? i : 0);
    }
    
    if (!sobrepoeNavio(tabuleiro, posicoes, TAMANHO_NAVIO)) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[posicoes[i][0]][posicoes[i][1]] = 3; // Marca o navio
        }
    } else {
        printf("Erro: Sobreposição de navio!\n");
    }
}

// Função para posicionar um navio diagonal (crescente ou decrescente)
void posicionarNavioDiagonal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y, int crescente) {
    int posicoes[TAMANHO_NAVIO][2];
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        posicoes[i][0] = x + i;
        posicoes[i][1] = y + (crescente ? i : -i);
    }
    
    if (!sobrepoeNavio(tabuleiro, posicoes, TAMANHO_NAVIO)) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[posicoes[i][0]][posicoes[i][1]] = 3; // Marca o navio
        }
    } else {
        printf("Erro: Sobreposição de navio!\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    
    // Inicializando o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Posicionando navios horizontais e verticais
    posicionarNavioHV(tabuleiro, 2, 3, 1); // Horizontal
    posicionarNavioHV(tabuleiro, 5, 5, 0); // Vertical

    // Posicionando navios diagonais
    posicionarNavioDiagonal(tabuleiro, 0, 0, 1); // Diagonal crescente
    posicionarNavioDiagonal(tabuleiro, 6, 9, 0); // Diagonal decrescente

    // Exibindo o tabuleiro com os navios posicionados
    exibirTabuleiro(tabuleiro);

    return 0;
}
