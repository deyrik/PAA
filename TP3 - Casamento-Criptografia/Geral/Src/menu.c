#include "../Headers/menu.h"

//Função tarefaA
void funcA(){

    //TarefaB - Chave aleatória
    srand(time(NULL));
    int chaveAleatoria = (rand()%1000)+1;

    //TarefaB - criptografia e descriptografia padrão
    //Arquivo -> string
    char nome[TAM_CAMINHO] = "Geral/Lib/test2.txt";
    char* texto;
    arquivoParaString(nome, &texto); 

    //Criptografia e descriptografia padrão
    char criptografia[50];
    char decriptografia[50];
    printf("Entre com o nome do arquivo de criptografia sem extensão: ");
    scanf("%s",criptografia);
    printf("\nEntre com o nome do arquivo de decriptografia sem extensão: ");
    scanf("%s",decriptografia);

    char* crypto = criptografar(100, texto, criptografia);
    char* decrypto = descriptografar(100, texto, decriptografia);

    FILE* criptografado = fopen(crypto,"r");
    FILE* descriptografado = fopen(decrypto,"r");

    //Exibição do conteúdo do arquivo criptografado e descriptografado padrão
    char cripto,decripto;
    printf("\nTexto criptografado:\n");
    printf("=======================================================\n");
    while((cripto = fgetc(criptografado))!= EOF)printf("%c",cripto);
    printf("=======================================================\n");

    printf("\nTexto descriptografado:\n");
    printf("=======================================================\n");
    while((decripto=fgetc(descriptografado))!=EOF)printf("%c",decripto);
    printf("=======================================================\n");

    //Chave aleatória
    char KRYPTO[50];
    printf("\nEntre com o nome do arquivo de criptografia sem extensão para chave aleatória: ");
    scanf("%s",KRYPTO);
    adivinhaChave(chaveAleatoria, texto, KRYPTO);

    //Liberação de memória
    free(texto);
    free(crypto);
    free(decrypto);

    pressEnter();

}

//Função tarefaB
void funcB(){

    char nome[TAM_CAMINHO] = "Geral/Lib/teste3.txt";
    char* texto;
    char padrao[100];
    int resultado_forcaBruta, resultado_shiftAnd;

    clock_t inicio, fim;

    arquivoParaString(nome, &texto);
    

    //printf(texto);
    //printf("\n\n\n");

    printf("Digite o padrao: ");
    scanf("%s", padrao);


    inicio = clock();
    resultado_forcaBruta = forcaBruta(texto, padrao);
    fim = clock();
    printf("Tempo de execucao do forcaBruta: %f\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    inicio = clock();
    resultado_shiftAnd = shiftAnd(texto, padrao);
    fim = clock();
    printf("Tempo de execucao do shiftAnd: %f\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    printf("-----Forca Bruta:-----\n");
    if(resultado_forcaBruta){
        printf("Padrao encontrado!\n");
    }else{
        printf("Padrao nao encontrado!\n");
    }
    printf("-----Shift And:-----\n");
    if(resultado_shiftAnd){
        printf("Padrao encontrado!\n");
    }else{
        printf("Padrao nao encontrado!\n");
    }

    pressEnter();
}

//Função menu
void menu() {
    int condicao;
    
    do {
        printf("\nMenu:\n");
        printf("1 - Criptografia e Descriptografia padrão\n");
        printf("2 - Casamento de cadeias\n");
        printf("3 - Sair\n");
        printf("Escolha uma opção: ");

        // Verifica se o usuário digitou um número válido
        if (scanf("%d", &condicao) != 1) {
            printf("ENTRADA INAVLIDA! Digite um número.\n");

            // Limpa o buffer para evitar loop infinito
            while (getchar() != '\n');
            continue;  // Volta ao início do loop
        }

        switch (condicao) {
            case 1:
                funcA();
                break;
            case 2:
                funcB();
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }

    } while (condicao != 3);
}

void limparTerminalUnix() {

    // caso eu queira relizar um atraso, posso pausar/esperar o processo usando a função 
    // sleep(2) //parametro e em segundos ;
    //faz parte da biblioteca <unistd.h> e está disponível em sistemas operacionais Unix-like, como Linux e macOS

    printf("\033[2J\033[H"); //limpa a tela
    printf("\033[H\033[J"); //posiciona o cursor no inicio do terminal (posiçao \033[h) e limpa a partir dai (\033[j)
    system("clear");
}

void pressEnter(){
while (getchar() != '\n'); // Limpa o buffer até o Enter
printf("\n\nPressione Enter para continuar...");
getchar();
limparTerminalUnix();
}
