#include "../Headers/progDinamica.h"

int main(int argc, char const *argv[])
{
    Mapa mapa;
    informacoes info;
    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    int linhaF, colunaF, linhaI, colunaI;
    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    lerArquivo("Lib/test.txt",&info,&mapa);
    MostrarMapa(mapa,info.linhas,info.colunas);

    printf("\n\n%d ",mapa[0][0]);
    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

    printf("\n\nF: %d %d\nI: %d %d\n\n",info.linhaF, info.colunaF, info.linhaI, info.colunaI);

    struct celulaProgD **pd = fazMatrizProgDinamica(info);
    calcularSubproblemas(pd, mapa, info,  info.linhaF, info.colunaF, info.linhaI, info.colunaI);
    //printf("LINHA F: %d\n", pd[1][0]);
    constroiCaminho(pd, info, info.linhaF, info.colunaF, info.linhaI, info.colunaI);  


    return 0;
}
