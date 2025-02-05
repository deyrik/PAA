#include "../Headers/tempoExecucao.h"

int main(int argc, char const *argv[])
{

    if (argc != 2){
        fprintf(stderr, "Use: %s MAPA=<nome_do_arquivo_mapa>\n", argv[0]);
        return 1;
    }
    string camihhoEntrada = (string) malloc(strlen("Lib/") + strlen(argv[1]) + strlen(".txt") + 1);
    strcpy(camihhoEntrada, "Lib/");
    strcat(camihhoEntrada, argv[1]);
    strcat(camihhoEntrada, ".txt");

    Mapa mapa;
    informacoes info;

    lerArquivo(camihhoEntrada,&info,&mapa);
    struct celulaProgD **pd = fazMatrizProgDinamica(info);

    clock_t inicio = clock();
    calcularSubproblemas(pd, mapa, info,  info.linhaF, info.colunaF, info.linhaI, info.colunaI);
    constroiCaminho(pd, info, info.linhaF, info.colunaF, info.linhaI, info.colunaI);
    clock_t fim = clock();

    double tempoExecucao = (double)(fim - inicio) / CLOCKS_PER_SEC; 

    printf("\n\n");
    MostrarMapa(mapa,info.linhas,info.colunas);
    printf("\n\n");
    printf("Dimensoes da matriz: %d x %d\n", info.linhas, info.colunas);
    printf("Tempo de execucao da Programação Dinamica: %.6f segundos\n", tempoExecucao);
    printf("\n\n");



    return 0;
}
