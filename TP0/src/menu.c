#include "menu.h"
#include "quadro.h"


void mostraTitulo(){

    printf("\n");
    printf(" @@@@@@   @@@@@@@@@@         @@@@@@   @@@@@@@   @@@@@@@       \n");
    printf("@@@@@@@   @@@@@@@@@@@       @@@@@@@@  @@@@@@@@  @@@@@@@       \n");
    printf("!@@       @@! @@! @@!       @@!  @@@  @@!  @@@    @@!         \n");
    printf("!@!       !@! !@! !@!       !@!  @!@  !@!  @!@    !@!         \n");
    printf("!!@@!!    @!! !!@ @!@       @!@!@!@!  @!@!!@!     @!!         \n");
    printf(" !!@!!!   !@!   ! !@!       !!!@!!!!  !!@!@!      !!!         \n");
    printf("     !:!  !!:     !!:       !!:  !!!  !!: :!!     !!:         \n");
    printf("    !:!   :!:     :!:  :!:  :!:  !:!  :!:  !:!    :!:    :!:  \n");
    printf(":::: ::   :::     ::   :::  ::   :::  ::   :::     ::    :::  \n");
    printf(":: : :     :      :    :::   :   : :   :   : :     :     :::  \n");
    printf("\n");


}

void menu(){
    printf("\n");
    printf("Escolha o tipo de figura  que deseja para criar sua obra:\n\t");
    printf("1 - Asteriscos Simples\n\t");//-------------------------------------FEITO 
    printf("2 - Simbolo de soma com asteriscos\n\t");
    printf("3 - Letra X com asteriscos\n\t");
    printf("4 - Gerar Figura aleatoria com todos\n\t");
    printf("5 - Area de testes:\n\t");
    printf("6 - Conversa com LORAX\n\t");
    printf("7 - Sair\n");
    printf("Digite a opção desejada: ");
}

void menuTestes(){
    printf("\n");
    // system("clear");
    printf("Escolha o teste que deseja realizar:\n\t");
    printf("1 - Teste asterisco simples\n\t");
    printf("2 - Teste soma com asteriscos\n\t");
    printf("3 - Teste x com asteriscos\n\t");
    printf("4 - Teste figuras aleatorias\n\t");
    printf("5 - Sair\n");
    printf("Digite a opção desejada de teste: ");
}

void perguntaQtdFiguras(){
    printf("Quantas figuras deseja criar? ");
    //printf("\n");
}

int formataQtdFiguras(int qtdFiguras){
    
    srand(time(NULL));

    if (qtdFiguras <= 0){
        qtdFiguras =  1+(rand() % 100);
    }
    else if (qtdFiguras >=100){
        qtdFiguras = 100;
    }
    return qtdFiguras;
}


//--------Area da criatividade -------------
void perguntaLorax(){
    system("clear");
    printf("\x1b[33m");
    printf("----------------------------------------------------------------------------------------\n");
    printf("Você acaba de acordar e olha para a janela\n");
    printf("...\n");
    printf("Quantas arvores voce ve? ");
    printf("\x1b[0m");

}

int formataQtdFigurasArvores(int qtdFiguras){
    
    srand(time(NULL));

    if (qtdFiguras <= 0){
        qtdFiguras =  1+(rand() % 80);
    }
    else if (qtdFiguras >=100){
        qtdFiguras = 80;
    }
    return qtdFiguras;
}

void perguntaLorax2(){
    printf("\x1b[33m");
    printf("----------------------------------------------------------------------------------------\n");
    printf("\nUm ser pequeno e peludo, de um laranja brilhante, aparece diante de voce\n");
    printf("...\n");
    printf("ELe se apresenta como LORAX e faz a seguinte pergunta: \n\n");
    printf("    __Se eu lhe desse duas escolha, Dinheiro ou arvores, o que voce escolheria?\n\n");
    printf("Ele lhe estende a mão ,segurando uma semente e uma moeda de ouro\n\n");
    printf("    __Qual voce escolhe? \n\n");
    printf("1 - Arvores\n");
    printf("2 - Dinheiro\n");
    printf("Digite a opção desejada: ");
    printf("\x1b[0m");
}

void respostaLoraxBoa(){
    printf("\x1b[33m");
    printf("----------------------------------------------------------------------------------------\n");
    printf("Voce escolheu a opção 1, LORAX sorri e lhe entrega a semente...\n");
    printf("Voce olha novamente a janela e se vê em um mundo repleto de Arvores e Natureza!!!\n");
    printf("\x1b[0m");
}

void respostaLoraxRuim(){
    printf("\x1b[33m");
    printf("----------------------------------------------------------------------------------------\n");
    printf("Voce escolheu a opção 2, LORAX se enche com tristeza e amargura...\n");
    printf("Lhe entrega a moeda que representa sua ganancia, enquanto voce o vê, indo embora e sumindo no horizonte repleto de \narvores queimadas e uma natureza decadente e desmatada...o mundo no qual vc conhece agr tem os dias contados!!!\n");
    printf("\x1b[0m");
}