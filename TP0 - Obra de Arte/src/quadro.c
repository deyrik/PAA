#include "quadro.h"



void limparTerminalUnix() {

    // caso eu queira relizar um atraso, posso pausar/esperar o processo usando a função 
    // sleep(2) //parametro e em segundos ;
    //faz parte da biblioteca <unistd.h> e está disponível em sistemas operacionais Unix-like, como Linux e macOS

    // Limpa o buffer de saída
    printf("\033[H\033[J"); //posiciona o cursor no inicio do terminal (posiçao \033[h) e limpa a partir dai (\033[j)
}

//----------Figuras Principais----------------
void criaQuadro(char matriz[20][80]){

    //linha X coluna 20 por 80
    for (int i = 0; i < 20; i++){

        for (int j = 0; j < 80; j++){

            if (i == 0 || i == 19){
                matriz[i][j] = '-';
            }
            
            else if (j == 0 || j == 79){
                matriz[i][j] = '|';
            }
            
            else{
                //printf(" ");
                matriz[i][j] = ' ';
            }
        }
    } 
}

void limpaQuadro(char matriz[20][80]){

    for (int i = 1; i < 19; i++){

        for (int j = 1; j < 79; j++){

            matriz[i][j] = ' ';
        }
    }
}

void mostraQuadro(char matriz[20][80]){
    system("clear");
    for (int i = 0; i < 20; i++){

        for (int j = 0; j < 80; j++){

            printf("%c", matriz[i][j]);
        }
        printf("\n");
    }
}

int numeroAleatorioLinha(){
    int numeroI = 1 + (rand() % 18);
    return numeroI;
}

int numeroAleatorioColuna(){
    
    int nuemroJ = 1 + (rand() % 78);
    return nuemroJ;
}

void asteriscoSimples (char matriz[20][80],int numeroDeAsteriscos){
    
    int condicao = 0;

    srand(time(NULL));
    for (int i = 0; i < numeroDeAsteriscos; i++) {
        int numeroX = numeroAleatorioLinha(); 
        int numeroY = numeroAleatorioColuna();
    
        while (condicao == 0) {
            // Verifica se as coordenadas ao redor de (numeroX, numeroY) estão dentro da matriz
            if (numeroX > 0 && numeroX < 19 && numeroY > 0 && numeroY < 79) {
                // Verifica se todas as posições necessárias estão vazias
                if (matriz[numeroX][numeroY] == ' ' ) {
                    condicao = 1;
                } 
                else {
                    // Gera novos números aleatórios se não estiver vazio
                    numeroX = numeroAleatorioLinha(); 
                    numeroY = numeroAleatorioColuna();
                }
            } else {
                // Gera novos números aleatórios se as coordenadas estiverem fora dos limites
                numeroX = numeroAleatorioLinha(); 
                numeroY = numeroAleatorioColuna();
            }
        }

        // Desenha os asteriscos se a condição for atendida
        if (condicao == 1) {
            matriz[numeroX][numeroY] = '*';
        }

        // Reinicia a condicao para a próxima iteração
        condicao = 0;
    } 
}

void somaComAsteriscos(char matriz[20][80], int numeroDeAsteriscos) {
    int condicao = 0;

    srand(time(NULL));
    for (int i = 0; i < numeroDeAsteriscos; i++) {
        int numeroX = numeroAleatorioLinha(); 
        int numeroY = numeroAleatorioColuna();
    
        while (condicao == 0) {
            // Verifica se as coordenadas ao redor de (numeroX, numeroY) estão dentro da matriz
            if (numeroX > 0 && numeroX < 19 && numeroY > 0 && numeroY < 79) {
                // Verifica se todas as posições necessárias estão vazias
                if (matriz[numeroX][numeroY] == ' ' 
                    && matriz[numeroX][numeroY + 1] == ' ' 
                    && matriz[numeroX][numeroY - 1] == ' ' 
                    && matriz[numeroX + 1][numeroY] == ' ' 
                    && matriz[numeroX - 1][numeroY] == ' ') {
                    condicao = 1;
                } 
                else {
                    // Gera novos números aleatórios se não estiver vazio
                    numeroX = numeroAleatorioLinha(); 
                    numeroY = numeroAleatorioColuna();
                }
            } else {
                // Gera novos números aleatórios se as coordenadas estiverem fora dos limites
                numeroX = numeroAleatorioLinha(); 
                numeroY = numeroAleatorioColuna();
            }
        }

        // Desenha os asteriscos se a condição for atendida
        if (condicao == 1) {
            matriz[numeroX][numeroY] = '*';
            matriz[numeroX][numeroY + 1] = '*';
            matriz[numeroX][numeroY - 1] = '*';
            matriz[numeroX + 1][numeroY] = '*';
            matriz[numeroX - 1][numeroY] = '*';
        }

        // Reinicia a condicao para a próxima iteração
        condicao = 0;
    }
}

void xComAsteriscos(char matriz[20][80], int numeroDeAsteriscos){
    int condicao = 0;

    srand(time(NULL));
    for (int i = 0; i < numeroDeAsteriscos; i++) {
        int numeroX = numeroAleatorioLinha(); 
        int numeroY = numeroAleatorioColuna();
    
        while (condicao == 0) {
            // Verifica se as coordenadas ao redor de (numeroX, numeroY) estão dentro da matriz
            if (numeroX > 0 && numeroX < 19 && numeroY > 0 && numeroY < 79) {
                // Verifica se todas as posições necessárias estão vazias
                if (matriz[numeroX][numeroY] == ' ' 
                    && matriz[numeroX][numeroY + 1] == ' ' 
                    && matriz[numeroX][numeroY - 1] == ' ' 
                    && matriz[numeroX + 1][numeroY] == ' ' 
                    && matriz[numeroX - 1][numeroY] == ' ') {
                    condicao = 1;
                } 
                else {
                    // Gera novos números aleatórios se não estiver vazio
                    numeroX = numeroAleatorioLinha(); 
                    numeroY = numeroAleatorioColuna();
                }
            } else {
                // Gera novos números aleatórios se as coordenadas estiverem fora dos limites
                numeroX = numeroAleatorioLinha(); 
                numeroY = numeroAleatorioColuna();
            }
        }

        // Desenha os asteriscos se a condição for atendida
        if (condicao == 1) {
            matriz[numeroX][numeroY] = '*';
            matriz[numeroX-1][numeroY+1] = '*';
            matriz[numeroX+1][numeroY+1] = '*';
            matriz[numeroX-1][numeroY-1] = '*';
            matriz[numeroX+1][numeroY-1] = '*';
        }

        // Reinicia a condicao para a próxima iteração
        condicao = 0;
    }
}

void figurasAleatorias(char matriz[20][80], int numeroDeFiguras){
    
    srand(time(NULL));

    int figSimples = 0;
    int figSoma = 0;
    int figX = 0;

    while (numeroDeFiguras > 0)
    {
        int daVez = 1+ (rand() % 3);

        //faz obra simples
        if (daVez == 1)
        {
            asteriscoSimples(matriz,1);
            figSimples++;
        }
        //faz obra com soma 
        else if (daVez == 2)
        {
            somaComAsteriscos(matriz,1);
            figSoma++;
        }
        //faz obra com X 
        else if (daVez == 3)
        {
            xComAsteriscos(matriz,1);
            figX++;
        }
        numeroDeFiguras--;
    }


    //printf("\tastericos simples: %d\n\tsimbolo de soma: %d\n\tsimbolo de X: %d\n", figSimples, figSoma, figX);

}


//----------TESTES----------------
void testeAsteriscoSimples (char matriz[20][80], int numeroDeAsteriscos){

    int condicao = 0;

    srand(time(NULL));
    for (int i = 0; i < numeroDeAsteriscos; i++) {
        int numeroX = numeroAleatorioLinha(); 
        int numeroY = numeroAleatorioColuna();
    
        while (condicao == 0) {
            // Verifica se as coordenadas ao redor de (numeroX, numeroY) estão dentro da matriz
            if (numeroX > 0 && numeroX < 19 && numeroY > 0 && numeroY < 79) {
                // Verifica se todas as posições necessárias estão vazias
                if (matriz[numeroX][numeroY] == ' ' ) {
                    condicao = 1;
                } 
                else {
                    // Gera novos números aleatórios se não estiver vazio
                    numeroX = numeroAleatorioLinha(); 
                    numeroY = numeroAleatorioColuna();
                }
            } else {
                // Gera novos números aleatórios se as coordenadas estiverem fora dos limites
                numeroX = numeroAleatorioLinha(); 
                numeroY = numeroAleatorioColuna();
            }
        }

        // Desenha os asteriscos se a condição for atendida
        if (condicao == 1) {
            matriz[numeroX][numeroY] = '*';
        }

        // Reinicia a condicao para a próxima iteração
        condicao = 0;
    }
}

void testeSomaAsteriscos(char matriz[20][80], int numeroDeAsteriscos) {
    int condicao = 0;

    srand(time(NULL));
    for (int i = 0; i < numeroDeAsteriscos; i++) {
        int numeroX = numeroAleatorioLinha(); 
        int numeroY = numeroAleatorioColuna();
    
        while (condicao == 0) {
            // Verifica se as coordenadas ao redor de (numeroX, numeroY) estão dentro da matriz
            if (numeroX > 0 && numeroX < 19 && numeroY > 0 && numeroY < 79) {
                // Verifica se todas as posições necessárias estão vazias
                if (matriz[numeroX][numeroY] == ' ' 
                    && matriz[numeroX][numeroY + 1] == ' ' 
                    && matriz[numeroX][numeroY - 1] == ' ' 
                    && matriz[numeroX + 1][numeroY] == ' ' 
                    && matriz[numeroX - 1][numeroY] == ' ') {
                    condicao = 1;
                } 
                else {
                    // Gera novos números aleatórios se não estiver vazio
                    numeroX = numeroAleatorioLinha(); 
                    numeroY = numeroAleatorioColuna();
                }
            } else {
                // Gera novos números aleatórios se as coordenadas estiverem fora dos limites
                numeroX = numeroAleatorioLinha(); 
                numeroY = numeroAleatorioColuna();
            }
        }

        // Desenha os asteriscos se a condição for atendida
        if (condicao == 1) {
            matriz[numeroX][numeroY] = '@';
            matriz[numeroX][numeroY + 1] = '@';
            matriz[numeroX][numeroY - 1] = '@';
            matriz[numeroX + 1][numeroY] = '@';
            matriz[numeroX - 1][numeroY] = '@';
        }

        // Reinicia a condicao para a próxima iteração
        condicao = 0;
    }
}

void testeXComAsteriscos(char matriz[20][80], int numeroDeAsteriscos) {
    int condicao = 0;

    srand(time(NULL));
    for (int i = 0; i < numeroDeAsteriscos; i++) {
        int numeroX = numeroAleatorioLinha(); 
        int numeroY = numeroAleatorioColuna();
    
        while (condicao == 0) {
            // Verifica se as coordenadas ao redor de (numeroX, numeroY) estão dentro da matriz
            if (numeroX > 0 && numeroX < 19 && numeroY > 0 && numeroY < 79) {
                // Verifica se todas as posições necessárias estão vazias
                if (matriz[numeroX][numeroY] == ' ' 
                    && matriz[numeroX][numeroY + 1] == ' ' 
                    && matriz[numeroX][numeroY - 1] == ' ' 
                    && matriz[numeroX + 1][numeroY] == ' ' 
                    && matriz[numeroX - 1][numeroY] == ' ') {
                    condicao = 1;
                } 
                else {
                    // Gera novos números aleatórios se não estiver vazio
                    numeroX = numeroAleatorioLinha(); 
                    numeroY = numeroAleatorioColuna();
                }
            } else {
                // Gera novos números aleatórios se as coordenadas estiverem fora dos limites
                numeroX = numeroAleatorioLinha(); 
                numeroY = numeroAleatorioColuna();
            }
        }

        // Desenha os asteriscos se a condição for atendida
        if (condicao == 1) {
            matriz[numeroX][numeroY] = 'X';
            matriz[numeroX-1][numeroY+1] = 'X';
            matriz[numeroX+1][numeroY+1] = 'X';
            matriz[numeroX-1][numeroY-1] = 'X';
            matriz[numeroX+1][numeroY-1] = 'X';
        }

        // Reinicia a condicao para a próxima iteração
        condicao = 0;
    }
}

void testeFigurasAleatorias(char matriz[20][80], int numeroDeFiguras){
    
    srand(time(NULL));

    int figSimples = 0;
    int figSoma = 0;
    int figX = 0;

    while (numeroDeFiguras > 0)
    {
        int daVez = 1+ (rand() % 3);

        //faz obra simples
        if (daVez == 1)
        {
            testeAsteriscoSimples(matriz,1);
            figSimples++;
        }
        //faz obra com soma 
        else if (daVez == 2)
        {
            testeSomaAsteriscos(matriz,1);
            figSoma++;
        }
        //faz obra com X 
        else if (daVez == 3)
        {
            testeXComAsteriscos(matriz,1);
            figX++;
        }
        numeroDeFiguras--;
    }


    printf("\tastericos simples: %d\n\tsimbolo de soma: %d\n\tsimbolo de X: %d\n", figSimples, figSoma, figX);

}


//----------Minhas Figuras----------------


void arvoreCheia  (char matriz[20][80],int numeroDeAsteriscos){
    
    int condicao = 0;

    srand(time(NULL));
    for (int i = 0; i < numeroDeAsteriscos; i++) {
        int numeroX = numeroAleatorioLinha(); 
        int numeroY = numeroAleatorioColuna();
    
        while (condicao == 0) {
            // Verifica se as coordenadas ao redor de (numeroX, numeroY) estão dentro da matriz
            if (numeroX > 0 && numeroX < 19 && numeroY > 0 && numeroY < 79) {
                // Verifica se todas as posições necessárias estão vazias
                if (matriz[numeroX][numeroY] == ' '
                && matriz[numeroX-1][numeroY] == ' '
                && matriz[numeroX][numeroY-1] == ' '
                && matriz[numeroX][numeroY+1] == ' '
                && matriz[numeroX+1][numeroY-1] == ' '
                && matriz[numeroX+1][numeroY] == ' '
                && matriz[numeroX+1][numeroY+1] == ' '
                && matriz[numeroX+2][numeroY] == ' ') 
                {
                    condicao = 1;
                } 
                else {
                    // Gera novos números aleatórios se não estiver vazio
                    numeroX = numeroAleatorioLinha(); 
                    numeroY = numeroAleatorioColuna();
                }
            } else {
                // Gera novos números aleatórios se as coordenadas estiverem fora dos limites
                numeroX = numeroAleatorioLinha(); 
                numeroY = numeroAleatorioColuna();
            }
        }

        // Desenha os asteriscos se a condição for atendida
        if (condicao == 1) {
            
            matriz[numeroX][numeroY] = '*';
            matriz[numeroX-1][numeroY] = '*';
            matriz[numeroX][numeroY-1] = '*';
            matriz[numeroX][numeroY+1] = '*';
            matriz[numeroX+1][numeroY-1] = '*';
            matriz[numeroX+1][numeroY] = '*';
            matriz[numeroX+1][numeroY+1] = '*';
            matriz[numeroX+2][numeroY] = '|';
        }
            ;

        // Reinicia a condicao para a próxima iteração
        condicao = 0;
    } 
}

void arvoreDeMaca(char matriz[20][80],int numeroDeAsteriscos){

    int condicao = 0;

    srand(time(NULL));
    for (int i = 0; i < numeroDeAsteriscos; i++) {
        int numeroX = numeroAleatorioLinha(); 
        int numeroY = numeroAleatorioColuna();
    
        while (condicao == 0) {
            // Verifica se as coordenadas ao redor de (numeroX, numeroY) estão dentro da matriz
            if (numeroX > 0 && numeroX < 19 && numeroY > 0 && numeroY < 79) {
                // Verifica se todas as posições necessárias estão vazias
                if (matriz[numeroX][numeroY] == ' '
                /*&&matriz[numeroX-1][numeroY-1] == ' '
                  &&matriz[numeroX-1][numeroY] == ' '
                  &&matriz[numeroX-1][numeroY+1] == ' '*/
                &&matriz[numeroX][numeroY-1] == ' '
                &&matriz[numeroX][numeroY+1] == ' '
                &&matriz[numeroX+1][numeroY-1] == ' '
                &&matriz[numeroX+1][numeroY] == ' '
                &&matriz[numeroX+1][numeroY+1] == ' '
                &&matriz[numeroX+2][numeroY] == ' ') 
                {
                    condicao = 1;
                } 
                else {
                    // Gera novos números aleatórios se não estiver vazio
                    numeroX = numeroAleatorioLinha(); 
                    numeroY = numeroAleatorioColuna();
                }
            } else {
                // Gera novos números aleatórios se as coordenadas estiverem fora dos limites
                numeroX = numeroAleatorioLinha(); 
                numeroY = numeroAleatorioColuna();
            }
        }

        // Desenha os asteriscos se a condição for atendida
        if (condicao == 1) {
            
            matriz[numeroX][numeroY] = '@';
            // matriz[numeroX-1][numeroY-1] = '@';
            // matriz[numeroX-1][numeroY] = '@';
            // matriz[numeroX-1][numeroY+1] = '@';
            matriz[numeroX][numeroY-1] = '@';
            matriz[numeroX][numeroY+1] = '@';
            matriz[numeroX+1][numeroY-1] = '@';
            matriz[numeroX+1][numeroY] = '@';
            matriz[numeroX+1][numeroY+1] = '@';
            matriz[numeroX+2][numeroY] = '|';
        }
            ;

        // Reinicia a condicao para a próxima iteração
        condicao = 0;
    }     
    
}

void arvore2galhos(char matriz[20][80],int numeroDeAsteriscos){
    
    int condicao = 0;

    srand(time(NULL));
    for (int i = 0; i < numeroDeAsteriscos; i++) {
        int numeroX = numeroAleatorioLinha(); 
        int numeroY = numeroAleatorioColuna();
    
        while (condicao == 0) {
            // Verifica se as coordenadas ao redor de (numeroX, numeroY) estão dentro da matriz
            if (numeroX > 0 && numeroX < 19 && numeroY > 0 && numeroY < 79) {
                // Verifica se todas as posições necessárias estão vazias
                if (matriz[numeroX][numeroY] == ' '
                &&matriz[numeroX-1][numeroY-1] == ' '
                &&matriz[numeroX-1][numeroY] == ' '
                &&matriz[numeroX-1][numeroY+1] == ' '
                &&matriz[numeroX][numeroY-2] == ' '
                &&matriz[numeroX][numeroY-1] == ' '
                &&matriz[numeroX][numeroY+1] == ' '
                &&matriz[numeroX][numeroY+2] == ' '
                &&matriz[numeroX+1][numeroY] == ' '
                &&matriz[numeroX+1][numeroY+1] == ' '
                &&matriz[numeroX+2][numeroY] == ' ')
                {
                    condicao = 1;
                } 
                else {
                    // Gera novos números aleatórios se não estiver vazio
                    numeroX = numeroAleatorioLinha(); 
                    numeroY = numeroAleatorioColuna();
                }
            } else {
                // Gera novos números aleatórios se as coordenadas estiverem fora dos limites
                numeroX = numeroAleatorioLinha(); 
                numeroY = numeroAleatorioColuna();
            }
        }

        // Desenha os asteriscos se a condição for atendida
        if (condicao == 1) {
            
            matriz[numeroX][numeroY] = 'o';
            matriz[numeroX-1][numeroY-1] = 'o';
            matriz[numeroX-1][numeroY] = 'o';
            matriz[numeroX-1][numeroY+1] = 'o';
            matriz[numeroX][numeroY-2] = 'o';
            matriz[numeroX][numeroY-1] = 'o';
            matriz[numeroX][numeroY+1] = 'o';
            matriz[numeroX][numeroY+2] = 'o';
            matriz[numeroX+1][numeroY] = '|';
            matriz[numeroX+1][numeroY+1] = '/';
            matriz[numeroX+2][numeroY] = '|';
        }

        // Reinicia a condicao para a próxima iteração
        condicao = 0;
    } 
}

void florestaSalva(char matriz[20][80],int numeroDeArvores){
    srand(time(NULL));

    int arvVerde = 0;
    int arvVermelha = 0;
    int arvRoxa = 0;

    arvVerde = 1 + (rand() % numeroDeArvores);
    arvVermelha = rand () % (numeroDeArvores - arvVerde);
    arvRoxa = numeroDeArvores - arvVerde - arvVermelha;

    arvoreCheia(matriz,arvVerde);
    arvoreDeMaca(matriz,arvVermelha);
    arvore2galhos(matriz,arvRoxa);

    printf("\tArvores verdes: %d\n\tArvores vermelhas: %d\n\tArvores roxas: %d\n", arvVerde, arvVermelha, arvRoxa);
}

void florestaQueimada(char matriz[20][80],int numeroDeAsteriscos){
        
    int condicao = 0;

    srand(time(NULL));
    for (int i = 0; i < numeroDeAsteriscos; i++) {
        int numeroX = numeroAleatorioLinha(); 
        int numeroY = numeroAleatorioColuna();
    
        while (condicao == 0) {
            // Verifica se as coordenadas ao redor de (numeroX, numeroY) estão dentro da matriz
            if (numeroX > 0 && numeroX < 19 && numeroY > 0 && numeroY < 79) {
                // Verifica se todas as posições necessárias estão vazias
                if (matriz[numeroX][numeroY] == ' '
                && matriz[numeroX-1][numeroY] == ' '
                /*&& matriz[numeroX][numeroY-1] == ' '
                && matriz[numeroX][numeroY+1] == ' '
                && matriz[numeroX+1][numeroY-1] == ' '*/
                && matriz[numeroX+1][numeroY] == ' '
                /*&& matriz[numeroX+1][numeroY+1] == ' '*/
                && matriz[numeroX+2][numeroY] == ' ') 
                {
                    condicao = 1;
                } 
                else {
                    // Gera novos números aleatórios se não estiver vazio
                    numeroX = numeroAleatorioLinha(); 
                    numeroY = numeroAleatorioColuna();
                }
            } else {
                // Gera novos números aleatórios se as coordenadas estiverem fora dos limites
                numeroX = numeroAleatorioLinha(); 
                numeroY = numeroAleatorioColuna();
            }
        }

        // Desenha os asteriscos se a condição for atendida
        if (condicao == 1) {
            matriz[numeroX][numeroY] = '|';
            matriz[numeroX-1][numeroY] = '|';
            //matriz[numeroX][numeroY-1] = '*';
            //matriz[numeroX][numeroY+1] = '*';
            //matriz[numeroX+1][numeroY-1] = '*';
            matriz[numeroX+1][numeroY] = '|';
            //matriz[numeroX+1][numeroY+1] = '*';
            matriz[numeroX+2][numeroY] = '|';
        }

        // Reinicia a condicao para a próxima iteração
        condicao = 0;
    } 
}

void mostraQuadroLorax(char matriz[20][80]){
    system("clear");
    for (int i = 0; i < 20; i++){

        for (int j = 0; j < 80; j++){

            //printf("%c", matriz[i][j]);
            if (matriz[i][j] == '*'){
                printf("\x1b[32m");
                printf("%c", matriz[i][j]);
                printf("\x1b[0m");
            }
            else if (matriz[i][j] == '@'){
                printf("\033[31m");
                printf("%c", matriz[i][j]);
                printf("\x1b[0m");
            }
            else if (matriz[i][j] == 'o'){
                printf("\x1b[35m");
                printf("%c", matriz[i][j]);
                printf("\x1b[0m");
                // printf("\033[36m");
                // printf("%c", matriz[i][j]);
                // printf("\x1b[0m");
            }
            else if (matriz[i][j] == '|'){
                printf("\x1b[0m");
                printf("%c", matriz[i][j]);
            }
            else if (matriz[i][j] == '-'){
                printf("\x1b[0m");
                printf("%c", matriz[i][j]);
            }
            else if (matriz[i][j] == ' ')
            {
                printf("%c", matriz[i][j]);
            }
            else
            {
                printf("\x1b[0m");
                printf("%c", matriz[i][j]);
            }
        }
            
        printf("\n");
        
    }
}

