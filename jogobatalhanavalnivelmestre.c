#include <stdio.h>

#define N 10 // Tamanho do tabuleiro
#define M 5  // Tamanho das matrizes de habilidade

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("0 ");  // Água
            } else if (tabuleiro[i][j] == 3) {
                printf("3 ");  // Navio
            } else if (tabuleiro[i][j] == 5) {
                printf("5 ");  // Área afetada pela habilidade
            }
        }
        printf("\n");
    }
}

// Função para gerar a matriz de habilidade em cone
void habilidadeCone(int habilidade[M][M]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j <= i; j++) {
            habilidade[i][j] = 1;
        }
    }
}

// Função para gerar a matriz de habilidade em cruz
void habilidadeCruz(int habilidade[M][M]) {
    int meio = M / 2;
    for (int i = 0; i < M; i++) {
        habilidade[meio][i] = 1;  // Linha central
        habilidade[i][meio] = 1;  // Coluna central
    }
}

// Função para gerar a matriz de habilidade em octaedro
void habilidadeOctaedro(int habilidade[M][M]) {
    int meio = M / 2;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            if (abs(i - meio) + abs(j - meio) <= meio) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Função para aplicar a habilidade sobre o tabuleiro
void aplicarHabilidade(int tabuleiro[N][N], int habilidade[M][M], int origemX, int origemY) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            int x = origemX + i - M / 2;
            int y = origemY + j - M / 2;

            if (x >= 0 && x < N && y >= 0 && y < N && habilidade[i][j] == 1) {
                tabuleiro[x][y] = 5;  // Marca a área afetada pela habilidade
            }
        }
    }
}

int main() {
    // Criando o tabuleiro 10x10
    int tabuleiro[N][N] = {0};

    // Colocando alguns navios no tabuleiro (valor 3)
    tabuleiro[2][3] = 3;
    tabuleiro[4][6] = 3;
    tabuleiro[6][8] = 3;
    
    // Matrizes de habilidade
    int habilidadeCone[M][M] = {0};
    int habilidadeCruz[M][M] = {0};
    int habilidadeOctaedro[M][M] = {0};

    // Gerar as matrizes de habilidade
    habilidadeCone(habilidadeCone);
    habilidadeCruz(habilidadeCruz);
    habilidadeocOtaedro(habilidadeOctaedro);

    // Aplicar as habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, habilidadeCone, 4, 4);  // Origem do cone em (4,4)
    aplicarHabilidade(tabuleiro, habilidadeCruz, 2, 2);  // Origem da cruz em (2,2)
    aplicarHabilidade(tabuleiro, habilidadeOctaedro, 7, 7);  // Origem do octaedro em (7,7)

    // Exibir o tabuleiro com as áreas afetadas
    printf("Tabuleiro com habilidades aplicadas:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
