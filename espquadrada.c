#include <stdio.h>

void coordenada(int ponto, int *x, int *y) {
    // se ponto eh a origem da espiral
    if (ponto == 0) {
        *x = 0;
        *y = 0;
        return;
    }

    int k = 0;
    int total_pontos = 0;

    //Loop para descobrir em qual camada esta o numero
    while (1) {
        k++;
        int pontos_k = 8 * k;
        if (total_pontos + pontos_k >= ponto)
        {
            break;
        }
        total_pontos = total_pontos + pontos_k;
    }

    // Resta saber a posicao dentro da camada
    int resto = ponto - total_pontos;
    int lado = resto / (2 * k); // lado da espiral
    int offset = resto % (2 * k);

    switch (lado) {
        case 0: // cima
            *x = k - offset;
            *y = k;
            break;
        case 1: // esquerda
            *x = -k;
            *y = k - offset;
            break;
        case 2: // baixo
            *x = -k + offset;
            *y = -k;
            break;
        case 3: // direita
            *x = k;
            *y = -k + offset;
            break;
    }
}

int main() {
    int ponto;
    while(ponto > -1)
    {
        int x = 0; int y = 0;
        scanf("%d", &ponto);

        if(ponto < 0){break;}
        else
        {
            coordenada(ponto, &x, &y);
        }

        printf("(%d, %d)\n", x, y);
    }
    return 0;
}
