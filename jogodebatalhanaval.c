#include <stdio.h>

// Definindo o tamanho do tabuleiro e o tamanho dos navios
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar um navio horizontalmente
int posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verifica se o navio cabe horizontalmente a partir da posição (linha, coluna)
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        return 0;  // Não cabe no tabuleiro
    }

    // Verifica se há sobreposição de navios
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != 0) {
            return 0;  // Há sobreposição
        }
    }

    // Posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = 3;
    }

    return 1;  // Navio posicionado com sucesso
}

// Função para posicionar um navio verticalmente
int posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verifica se o navio cabe verticalmente a partir da posição (linha, coluna)
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        return 0;  // Não cabe no tabuleiro
    }

    // Verifica se há sobreposição de navios
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != 0) {
            return 0;  // Há sobreposição
        }
    }

    // Posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 3;
    }

    return 1;  // Navio posicionado com sucesso
}

int main() {
    // Inicializando o tabuleiro com 0 (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Definindo as coordenadas dos navios
    int linhaNavioHorizontal = 2, colunaNavioHorizontal = 3;
    int linhaNavioVertical = 5, colunaNavioVertical = 7;

    // Posicionando os navios
    if (!posicionarNavioHorizontal(tabuleiro, linhaNavioHorizontal, colunaNavioHorizontal)) {
        printf("Falha ao posicionar o navio horizontal.\n");
    }
    if (!posicionarNavioVertical(tabuleiro, linhaNavioVertical, colunaNavioVertical)) {
        printf("Falha ao posicionar o navio vertical.\n");
    }

    // Exibindo o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
