#include <stdio.h>

void moveUL(int *x, int *y){ //funcao para mover para cima e esquerda
    *x = *x - 1;
    *y = *y + 1;
}

void moveDL(int *x, int *y){//funcao para mover para baixo e esquerda
    *x = *x - 1;
    *y = *y - 1;
}

void moveR(int *x, int *y){//funcao para mover para direita
    *x = *x + 1;
}

void coordenada(int ponto, int *x, int *y){
    if(ponto == 0){
        return;
    }

    int k = 1;

    int pontos_k = 8 * k;
    int origem_k = 1;

    int origem_k_next = k + pontos_k;

    int x_origem = 1;
    int y_origem = 0;

    int sequencia[3] = {1, 2, 5}; //movimentos cima esquerda, baixo esquerda e direita

    //Loop para descobrir em qual camada esta o numero
    while(ponto > origem_k_next)
    {
        k++; //Atualizando a camada

        origem_k = origem_k_next; //Atualizando coordenadas do ponto de origem da camada
        x_origem = x_origem + 2;
        y_origem--;

        pontos_k = 8 * k;
        origem_k_next = origem_k_next + pontos_k; //Atualuzando ponto de origem da proxima camada

        sequencia[0] = sequencia[0] + 2; //atualizando numero de movimentos na sequencia
        sequencia[1] = sequencia[1] + 2;
        sequencia[2] = sequencia[2] + 4;
    }

    *x = x_origem; //igualando as coordenadas do ponto a coordenada da origem da camada
    *y = y_origem;

    if(ponto == origem_k) //verificando se o ponto eh o mesmo que da origem
    {
        return;
    }

    int offset = ponto - origem_k; //calculando quantos blocos percorrer

    //loop para percorrer a camada na sequencia certa e checar a cada iteracao se o ponto eh o correto
    while(1){
        for(int i = 0; i < sequencia[0]; i++)
        {
            moveUL(x, y);
            offset--;
            if(offset == 0){break;}
        }
        if(offset == 0){break;}
        for(int i = 0; i < sequencia[1]; i++)
        {
            moveDL(x, y);
            offset--;
            if(offset == 0){break;}
        }
        if(offset == 0){break;}
        for(int i = 0; i < sequencia[2]; i++)
        {
            moveR(x, y);
            offset--;
            if(offset == 0){break;}
        }
        if(offset == 0){break;}
    }
}

int main() {
    int ponto;
    while(ponto > -1)
    {
        int x = 0; int y = 0;
        scanf("%d", &ponto);

        if(ponto < 0){
            break;
        }
        else{
            coordenada(ponto, &x, &y);
        }

        printf("(%d, %d)\n", x, y);
    }
    return 0;
}
