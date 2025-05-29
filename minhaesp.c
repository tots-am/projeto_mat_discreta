//Contem o codigo para a espiral "tornado" (octogono em 3d na direcao z positiva)

#include <stdio.h>

void moveR(int *x, int *y){//Funcao para mover para direita
    *x = *x + 1;
}

void moveL(int *x, int *y){//Funcao para mover para esquerda
    *x = *x - 1;
}

void moveU(int *x, int *y){//Funcao para mover para cima
    *y = *y + 1;
}

void moveD(int *x, int *y){//Funcao para mover para baixo
    *y = *y - 1;
}

void moveUL(int *x, int *y){ //funcao para mover para cima e esquerda
    *x = *x - 1;
    *y = *y + 1;
}

void moveDL(int *x, int *y){//funcao para mover para baixo e esquerda
    *x = *x - 1;
    *y = *y - 1;
}

void moveDR(int *x, int *y){//Funcao para mover para baixo e direita
    *x = *x + 1;
    *y = *y - 1;
}

void moveUR(int *x, int *y){//Funcao para cima e para direita
    *x = *x + 1;
    *y = *y + 1;
}

void coordenada(int ponto, int *x, int *y, float *z){//Funcao para encontrar a coordenada
    if(ponto == 0){ // Se o ponto é 0, retorne 0
        return;
    }
    //Faz as inicializacoes de camada e das variaveis base

    int k = 1;

    int pontos_k = 16*k - 4;
    int origem_k = 1;

    int origem_k_next = k + pontos_k;

    int x_origem = 1;
    int y_origem = 0;

    int sequencia[8] = {0, 1, 1, 1, 2, 2, 2, 2};

    //Loop para descobrir em qual camada esta o numero
    while(ponto > origem_k_next)
    {
        k++;

        origem_k = origem_k_next;
        x_origem = x_origem - 1;
        y_origem = y_origem - 3;

        pontos_k = 16*k - 4;
        origem_k_next = origem_k_next + pontos_k;

        for(int i = 0; i < 8; i++){
            sequencia[i] = sequencia[i] + 2;
        }
    }

    *x = x_origem; //igualando as coordenadas do ponto a coordenada da origem da camada
    *y = y_origem;

    int offset = ponto - origem_k; //calculando a distancia entre o ponto desejado e o inicio da camada

    *z = k; //inicializando z igual a k, e depois incrementando com base na regra estabelecida
    float diff = 100000/pontos_k;
    *z = *z + (diff / 100000) * offset;

    if(ponto == origem_k) //verificando se o ponto e o mesmo que da origem
    {
        return;
    }

    //Loop para percorrer a camada e checar se está no ponto desejado
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
    int ponto = 1;

    while(ponto != -1)
    {
        printf("=== Insira um ponto ===\n*Digite um ponto < -1 para rodar o script\n*Digite -1 para encerrar\n");
        //Loop para permitir o usuario fazer input de vários pontos sem encerrar o programa
        if(ponto > -1){
            while(ponto > -1)
            {
                scanf("%d", &ponto);
                int x = 0; int y = 0; float z = 0;

                if(ponto < 0){
                    break;
                }
                else{
                    coordenada(ponto, &x, &y, &z);
                }

                printf("(%d, %d, %.3f)\n", x, y, z);
            }
        }

        if(ponto == -1){
            return 0;
        }

        //Loop escondido para retornar os pontos no intervalo [0, ponto] em que y = 0
        if(ponto < -1){
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
        }
    }

    return 0;
}
