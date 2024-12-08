/**************************************************************
 * Nome do arquivo: menu.c
 * Projeto: Labirinto-PAA
 * Descrição: Definçoes de funcionalidades  para manipulação do menu
 * 
 * Autor(es): Gabriel de Pádua
 * Data de criação: 27/11/2024
 * 
 * Histórico de versões:
 *    - v1.0 (gabriel)- 27/11/2024: criada todas as funções do menu
 *    - v1.1 (gabriel)- 28/11/2024: modificada a função opcao1 (agora ela apaga o mapa anterior)  
 * 
 * Dependências:
 *    - mapa.h
 *    - backtracking.h"
 *    - coordenadas.h"
 *    - estudante.h"
 *    - pilha.h"
 *    - utilites.h"
 * 
 * Observações:
 *    - Nao é preciso colocar na ordem de dependencias as funções , ja que a declaração delas ja foi feita
 * no arquivo .h, e aqui apenas são as  definições e atribuiçoes de valores 
 * 
 * 
 **************************************************************/

#include "../headers/menu.h"
#include "../headers/analise.h"

void logo(){
   printf("                                                                                \n");
    printf("@@@        @@@@@@   @@@@@@@   @@@  @@@@@@@   @@@  @@@  @@@  @@@@@@@   @@@@@@   \n");
    printf("@@@       @@@@@@@@  @@@@@@@@  @@@  @@@@@@@@  @@@  @@@@ @@@  @@@@@@@  @@@@@@@@  \n");
    printf("@@!       @@!  @@@  @@!  @@@  @@!  @@!  @@@  @@!  @@!@!@@@    @@!    @@!  @@@  \n");
    printf("!@!       !@!  @!@  !@   @!@  !@!  !@!  @!@  !@!  !@!!@!@!    !@!    !@!  @!@  \n");
    printf("@!!       @!@!@!@!  @!@!@!@   !!@  @!@!!@!   !!@  @!@ !!@!    @!!    @!@  !@!  \n");
    printf("!!!       !!!@!!!!  !!!@!!!!  !!!  !!@!@!    !!!  !@!  !!!    !!!    !@!  !!!  \n");printf("\033[0;32m"); //verde
    printf("!!:       !!:  !!!  !!:  !!!  !!:  !!: :!!   !!:  !!:  !!!    !!:    !!:  !!!  \n");
    printf(" :!:      :!:  !:!  :!:  !:!  :!:  :!:  !:!  :!:  :!:  !:!    :!:    :!:  !:!  \n");
    printf(" :: ::::  ::   :::   :: ::::   ::  ::   :::   ::   ::   ::     ::    ::::: ::  \n");
    printf(": :: : :   :   : :  :: : ::   :     :   : :  :    ::    :      :      : :  :  \n");
    printf("\033[0;37m"); //branco


}

void menuPrincipal(){
    int opcao;

    //instanciei o mapa, aluno e dimensoes 
    ApontadorMapa guardaMapa = NULL;
    Mapa mapa = NULL;
    guardaMapa = &mapa;

    estudante aluno;
    coordenadas dimensao;
    //ApontadorMapa mapa = NULL; //inicialmente nao guarda mapa nenhum

    do{
        printf("\n\n");
        printf("Opcoes do programa:\n");
        printf("1) Carregar novo arquivo de dados.\n");
        printf("2) Mostrar Graficamente o arquivo.\n");
        printf("3) Processar e exibir resposta.\n");
        printf("4) Gerar novo arquivo.\n");
        printf("5) Encerrar o programa.\n");

        printf("\nDigite um numero: ");
        scanf("%d", &opcao);

        switch(opcao){    
            case 1:
                CarregarArquivo(guardaMapa, &aluno, &dimensao);
                break;
            case 2:
                VerGraficamente(guardaMapa, aluno, dimensao);
                break;
            case 3:
                ProcessarDados(guardaMapa, aluno, dimensao);
                break;
            case 4:
                GerarArquivo();
                break;  
            case 5:
                printf("Saindo do sistema...\n");
                break;
            default:
                limparTerminalUnix();
                printf("Opcao invalida! tente outra\n");
        }

    }while(opcao != 5);
}

void CarregarArquivo(ApontadorMapa mapa,ApontadorEstudante aluno, ApontadorCoordenadas dimensao){

    //se o mapa nao existir, eu crio um novo
    if (*mapa == NULL){

        limparTerminalUnix();
        printf("Por favor, digite o nome do arquivo sem extensao: ");
        char nomeArquivo[50];
        scanf("%s", nomeArquivo);

        limparTerminalUnix();
        InsereLabirinto(&(*mapa),nomeArquivo , &(*aluno), &(*dimensao));
        pressEnter();

        // printf("Deseja visualizar o mapa? (1 -> SIM, 0 -> NAO): ");
        // int opcao;
        // scanf("%d", &opcao);

        // if (opcao == 1){
        //     printf("\n\n");
        //     MostrarMapa((*mapa), (*dimensao).x, dimensao->y);
        //     pressEnter();
        //     limparTerminalUnix();
        //     return;
        // }
        // else return;
        return;
 
    }
    
    //se o mapa ja existir, eu apago o que ja existe e crio um novo
    if (*mapa != NULL)
    {
        limparTerminalUnix();
        printf("Por favor, digite o nome do arquivo sem extensao: ");
        char nomeArquivo[50];
        scanf("%s", nomeArquivo);

        limparTerminalUnix();
        ApagaMapa(&(*mapa),(*dimensao).x); //DIFERENÇA QUE TA APAGANDO O MAPA ANTERIOR DO HEAP E NAO SO O PONTEIRO
        InsereLabirinto(&(*mapa),nomeArquivo , &(*aluno), &(*dimensao));

        printf("Deseja visualizar o mapa? (1 -> SIM, 0 -> NAO): ");
        int opcao;
        scanf("%d", &opcao);

        if (opcao == 1){
            printf("\n\n");
            MostrarMapa((*mapa), (*dimensao).x, dimensao->y);
            pressEnter();
            limparTerminalUnix();
            return;
        }
        else return;
    }
}

void ProcessarDados(ApontadorMapa guardaMapa, estudante aluno, coordenadas dimensao) {
    limparTerminalUnix();
    if (*guardaMapa != NULL) {
        #ifndef ANALISE 
            ExploraLabirinto(*guardaMapa, dimensao.x, dimensao.y, aluno);
            ApagaMapa(guardaMapa, dimensao.x); 
            #else
            ExploraLabirinto(*guardaMapa, dimensao.x, dimensao.y, aluno);
                resultadoAnalise();
            ApagaMapa(guardaMapa, dimensao.x); 
        #endif
        return;
    } else {
        printf("Sem labirinto a ser explorado! Carregue um arquivo.\n");
        return;
    }
}

void GerarArquivo(){

    limparTerminalUnix();
    int largura, altura, chaves, dificuldade, chavesPerdidas;
    char nomeArquivo[50];

    printf("Digite o nome do arquivo sem extensao: ");
    scanf("%s", nomeArquivo);
    printf("Digite a largura do labirinto: ");
    scanf("%d", &largura);
    printf("Digite a altura do labirinto: ");
    scanf("%d", &altura);
    printf("Digite a quantidade de chaves iniciais: ");
    scanf("%d", &chaves);
    printf("Digite a dificuldade (0-100, onde valores altos geram mais paredes): ");
    scanf("%d", &dificuldade);
    printf("Digite quantas chaves estão perdidas no labirinto: ");
    scanf("%d", &chavesPerdidas);

    gerarLabirinto(nomeArquivo, largura, altura, chaves, dificuldade,chavesPerdidas);

    return;
}

void VerGraficamente(ApontadorMapa guardaMapa, estudante aluno, coordenadas dimensao){
    limparTerminalUnix();
    if (*guardaMapa != NULL) {
        MostrarMapa(*guardaMapa, dimensao.x, dimensao.y);
        pressEnter();
        return;
    } else {
        printf("Sem labirinto a ser explorado! Carregue um arquivo.\n");
        pressEnter();
        return;
    }
}