//Contem o código para a espiral "tornado" (octogono em 3d na direcao z)

#include <stdio.h>

void moveR(int *x, int *y){
    *x = *x + 1;
}

void moveL(int *x, int *y){
    *x = *x - 1;
}

void moveU(int *x, int *y){
    *y = *y + 1;
}

void moveD(int *x, int *y){
    *y = *y - 1;
}

void moveUL(int *x, int *y){ //função para mover para cima e esquerda
    *x = *x - 1;
    *y = *y + 1;
}

void moveDL(int *x, int *y){//função para mover para baixo e esquerda
    *x = *x - 1;
    *y = *y - 1;
}

void moveDR(int *x, int *y){
    *x = *x + 1;
    *y = *y - 1;
}

void moveUR(int *x, int *y){
    *x = *x + 1;
    *y = *y + 1;
}

void coordenada(int ponto, int *x, int *y, float *z){
    if(ponto == 0){
        return;
    }

    int k = 1;

    int pontos_k = (12*k) + (4*(k-1));
    int origem_k = 1;

    int origem_k_next = k + pontos_k;

    int x_origem = 1;
    int y_origem = 0;

    int sequencia[8] = {0, 1, 1, 1, 2, 2, 2, 2};

    while(ponto > origem_k_next)
    {
        k++;

        origem_k = origem_k_next;
        x_origem = x_origem - 1;
        y_origem = y_origem - 3;

        pontos_k = (12*k) + (4*(k-1));
        origem_k_next = origem_k_next + pontos_k;

        for(int i = 0; i < 8; i++){
            sequencia[i] = sequencia[i] + 2;
        }
    }

    *x = x_origem; //igualando as coordenadas do ponto a coordenada da origem da camada
    *y = y_origem;

    int offset = ponto - origem_k;

    *z = k;
    float diff = 100000/pontos_k;
    *z = *z + (diff / 100000) * offset;

    if(ponto == origem_k) //verificando se o ponto é o mesmo que da origem
    {
        return;
    }

    while(1){
        for(int i = 0; i < sequencia[0]; i++)
        {
            moveR(x, y);
            offset--;
            if(offset == 0){break;}
        }
        if(offset == 0){break;}
        for(int i = 0; i < sequencia[1]; i++)
        {
            moveUR(x, y);
            offset--;
            if(offset == 0){break;}
        }
        if(offset == 0){break;}
        for(int i = 0; i < sequencia[2]; i++)
        {
            moveU(x, y);
            offset--;
            if(offset == 0){break;}
        }
        if(offset == 0){break;}
        for(int i = 0; i < sequencia[3]; i++)
        {
            moveUL(x, y);
            offset--;
            if(offset == 0){break;}
        }
        if(offset == 0){break;}
        for(int i = 0; i < sequencia[4]; i++)
        {
            moveL(x, y);
            offset--;
            if(offset == 0){break;}
        }
        if(offset == 0){break;}
        for(int i = 0; i < sequencia[5]; i++)
        {
            moveDL(x, y);
            offset--;
            if(offset == 0){break;}
        }
        if(offset == 0){break;}
        for(int i = 0; i < sequencia[6]; i++)
        {
            moveD(x, y);
            offset--;
            if(offset == 0){break;}
        }
        if(offset == 0){break;}
        for(int i = 0; i < sequencia[7]; i++)
        {
            moveDR(x, y);
            offset--;
            if(offset == 0){break;}
        }
        if(offset == 0){break;}
        moveR(x, y);
        offset--;
        if(offset == 0){break;}
    }
}

int main() {

    int ponto;

    while(ponto > -1)
    {
        int x = 0; int y = 0; float z = 0;
        scanf("%d", &ponto);

        if(ponto < 0){
            break;
        }
        else{
            coordenada(ponto, &x, &y, &z);
        }

        printf("(%d, %d, %.3f)\n", x, y, z);
    }

    ponto = ponto * (-1);
    int ref = ponto;
    ponto = 0;

    while(ponto < ref){
        int x = 0;
        int y = 0;
        float z = 0;

        coordenada(ponto, &x, &y, &z);

        if(y == 0){
            printf("(%d, %d, %.6f)\n", x, y, z);
        }
        ponto++;
    }

    return 0;
}
