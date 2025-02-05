#include "../Headers/progDinamica.h"

int main(int argc, char* argv[]) {

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
    calcularSubproblemas(pd, mapa, info,  info.linhaF, info.colunaF, info.linhaI, info.colunaI);
    constroiCaminho(pd, info, info.linhaF, info.colunaF, info.linhaI, info.colunaI);  

    return 0;
}





