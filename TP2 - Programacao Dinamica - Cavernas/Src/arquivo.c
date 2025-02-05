/**************************************************************
 * Nome do arquivo: arquivo.c
 * Projeto: Caverna-PAA
 * Descrição: definições de funcionalidades para lidar com arquivos
 * 
 * Autor(es): Gabriel de Pádua 
 * Data de criação: 04/01/2025
 * 
 * Histórico de versões:
 *    - v1.0 (gabriel)- 04/01/2025: criada função lerArquivo
 *    - v1.0 (matheus)- 06/01/2025: criada função gerarArquivo
 * 
 * Dependências:
 *    - mapa.h
 * 
 * Observações:
 *    - 
 **************************************************************/
#include "../Headers/arquivo.h"

void lerArquivo(const char* nomeArquivo, ponteiroInformçaoes informacoes, ApontadorMapa mapa) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    // Ler a primeira linha do arquivo (dimensões e HP)
    fscanf(arquivo, "%d %d %d\n", &informacoes->linhas, &informacoes->colunas, &informacoes->HP);

    // Criar o mapa com base nas dimensões
    CriaMapa(mapa, informacoes->linhas, informacoes->colunas);

    // Ler as linhas restantes do arquivo e preencher o mapa
    char linha[1000]; // Buffer para armazenar a linha do arquivo
    for (int i = 0; i < informacoes->linhas; i++) {
        // Ler uma linha inteira do arquivo
        if (fgets(linha, sizeof(linha), arquivo) != NULL) {
            // Remover a quebra de linha, se presente
            linha[strcspn(linha, "\n")] = '\0';

            // Processar os valores da linha
            int coluna = 0;
            char* token = strtok(linha, " ");
            while (token != NULL) {
                // Verificar se o valor é um caractere ou número
                if (token[0] == 'F' || token[0] == 'I' || token[0] == 'B') {
                    (*mapa)[i][coluna] = token[0]; // Armazenar caracteres
                    
                    if (token[0] == 'F') {
                        informacoes->linhaF = i;
                        informacoes->colunaF = coluna;
                    } else if (token[0] == 'I') {
                        informacoes->linhaI = i;
                        informacoes->colunaI = coluna;
                    } //else if (token[0] == 'B') {
                    //     informacoes->HP += 10; // Baú
                    // }
                } else {
                    (*mapa)[i][coluna] = atoi(token); // Converter strings numéricas em inteiros
                }
                coluna++;
                token = strtok(NULL, " ");
            }

            // Verificação de segurança para número de colunas
            if (coluna != informacoes->colunas) {
                printf("Aviso: Linha %d tem número inesperado de colunas (%d em vez de %d).\n", 
                        i + 1, coluna, informacoes->colunas);
            }
        } else {
            printf("Erro ao ler a linha %d do arquivo.\n", i + 1);
        }
    }

    fclose(arquivo);

}

void gerarArquivo(const string nomeArquivo,int linhas, int colunas, int vidaInicial) {
    
    //calculei a memoria necessaria tanto dos valores literais quanto do nome do arquivo
    string caminhoArquivo = (string) malloc( strlen("Lib/") + strlen(nomeArquivo) + strlen(".txt") + 1);
    strcpy(caminhoArquivo, "Lib/");
    strcat(caminhoArquivo, nomeArquivo);
    strcat(caminhoArquivo, ".txt");

    FILE* arquivo = fopen(caminhoArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo!\n");
        exit(1);
    }

    fprintf(arquivo, "%d %d %d\n", linhas, colunas, vidaInicial);

    // Possíveis valores para as células
    int valores[] = {0, 20, -10, 10};
    int tamanhoValores = sizeof(valores) / sizeof(valores[0]);

    srand(time(NULL)); // semente para números aleatórios

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (i == 0 && j == 0) {
                fprintf(arquivo, "F "); 
            } else if (i == linhas - 1 && j == colunas - 1) {
                fprintf(arquivo, "I "); 
            } else {
                
                int valorAleatorio = valores[rand() % tamanhoValores];

                if (valorAleatorio > 0) {
                    fprintf(arquivo, "+%d ", valorAleatorio);
                } else {
                    fprintf(arquivo, "%d ", valorAleatorio);
                }
                
            }
        }
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
    printf("Mapa gerado com sucesso em: %s\n", caminhoArquivo);
}

int valorDaMatriz(int valorAleatorio){
    switch (valorAleatorio)
    {
    case 0:
        return 0;
        break;
    case 1:
        return -10;
        break;
    case 2:
        return 20;
        break;
    case 3:
        return (int)'B';
    case 4:
        return -20;
        break;
   
    default:
        return 0;
        break;
    }
   
}

void gerarAquivosComArmadilhas(const string nomeArquivo,int linhas, int colunas, int vidaInicial){

    string caminhoArquivo = (string) malloc( strlen("Lib/") + strlen(nomeArquivo) + strlen(".txt") + 1);
    strcpy(caminhoArquivo, "Lib/");
    strcat(caminhoArquivo, nomeArquivo);
    strcat(caminhoArquivo, ".txt");

    FILE* arquivo = fopen(caminhoArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo!\n");
        exit(1);
    }

    fprintf(arquivo, "%d %d %d\n", linhas, colunas, vidaInicial);

    // Possíveis valores para as células
    int valores[] = {0, 20, -10};
    int tamanhoValores = sizeof(valores) / sizeof(valores[0]);

    srand(time(NULL)); // semente para números aleatórios

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (i == 0 && j == 0) {
                fprintf(arquivo, "F "); 
            } else if (i == linhas - 1 && j == colunas - 1){
                fprintf(arquivo, "I "); 
            } else {
                int valorAleatorio = rand() % 5;//gera um valor aleatorio entre 0 e 3
                //escreve um valor no arquivo(0-0, 1-10, 2-20, 3-B em ASCII)
                if (valorDaMatriz(valorAleatorio) == (int)'B'){  
                    fprintf(arquivo, "%c ",'B'); //escreve B no arquivo se valor for 3
                }
                else{
                    fprintf(arquivo, "%d ", valorDaMatriz(valorAleatorio)); //escreve o valor no arquivo
                }
            }
        }
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
    printf("Mapa gerado com sucesso em: %s\n", caminhoArquivo);

}