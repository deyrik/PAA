
#include "../Headers/arquivo.h"

int main(int argc, char const *argv[])
{
    Mapa mapa;
    informacoes info;
    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    //lerArquivo("Lib/test.txt",&info,&mapa);


    //MostrarMapa(mapa,info.linhas,info.colunas);

    //printf("\n\n%d ",mapa[0][0]);
    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

    // teste de conversao ASCII
    // char c;
    // printf("Digite um caractere: ");
    // scanf("%c",&c);
    // printf("valor de %c em ASCII: %d\n",c,c);

    // printf("Digite um número: ");
    // int n;
    // scanf("%d",&n);
    // printf("valor de %d em ASCII: %c\n",n,n);

    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    int linhaF, colunaF, linhaI, colunaI;
    int qtdLinhas, qtdColunas, vidaInicial;
    char nomeArquivo[100];

    // Solicita ao usuário as dimensões e vida inicial
    printf("Digite o número de linhas: ");
    scanf("%d", &qtdLinhas);
    printf("Digite o número de colunas: ");
    scanf("%d", &qtdColunas);
    printf("Digite os pontos de vida iniciais: ");
    scanf("%d", &vidaInicial);
    printf("Digite nome do arquivo: ");
    scanf("%s", nomeArquivo);

//    gerarArquivo("foi",8, 8, 20);
    gerarArquivo(nomeArquivo,qtdLinhas,qtdColunas,vidaInicial);
    //gerarArquivo("foi3",8, 9, 20);

    return 0;
}
