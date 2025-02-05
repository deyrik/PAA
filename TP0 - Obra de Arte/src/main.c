#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "menu.h"
#include "quadro.h"


//AINDA preciso fazer a qtd ficar sempre entre 0 e 100, pq o usuario pode digitar um numero maior que 100

int main(int argc, char const *argv[])
{
  system("printf '\\e[8;50;100t'");
  //system("printf '\\e[3J'");
  system("clear");
  char matriz[20][80];
  criaQuadro(matriz);
  limpaQuadro(matriz);
  mostraTitulo();

  int opcao = 0;
  int qtdFiguras = 0;

  while (opcao != 7)
  {
    menu();
    scanf("%d", &opcao);
    switch (opcao)
    {
    case 1:
      limpaQuadro(matriz);
      perguntaQtdFiguras();
      scanf("%d", &qtdFiguras);
      qtdFiguras = formataQtdFiguras(qtdFiguras);
      asteriscoSimples(matriz,qtdFiguras);
      mostraQuadro(matriz);
      break;
    case 2:
      limpaQuadro(matriz);
      perguntaQtdFiguras();
      scanf("%d", &qtdFiguras);
      qtdFiguras = formataQtdFiguras(qtdFiguras);
      somaComAsteriscos(matriz, qtdFiguras);
      mostraQuadro(matriz);
      break;
    case 3:
      limpaQuadro(matriz);
      perguntaQtdFiguras();
      scanf("%d", &qtdFiguras);
      qtdFiguras = formataQtdFiguras(qtdFiguras);
      xComAsteriscos(matriz, qtdFiguras);
      mostraQuadro(matriz);
      break;
    case 4:
      limpaQuadro(matriz);
      perguntaQtdFiguras();
      scanf("%d", &qtdFiguras);      
      qtdFiguras = formataQtdFiguras(qtdFiguras);
      figurasAleatorias(matriz, qtdFiguras);
      mostraQuadro(matriz);
      break;
    case 5: 
        int opcao5 = 0;
        while (opcao5 != 5)
        {
          menuTestes();
          scanf("%d", &opcao5);
          switch (opcao5)
          {
          case 1:
            limpaQuadro(matriz);
            perguntaQtdFiguras();
            scanf("%d", &qtdFiguras);
            qtdFiguras = formataQtdFiguras(qtdFiguras);
            testeAsteriscoSimples(matriz, qtdFiguras);
            mostraQuadro(matriz);
            break;
          case 2:
            limpaQuadro(matriz);
            perguntaQtdFiguras();
            scanf("%d", &qtdFiguras);
            qtdFiguras = formataQtdFiguras(qtdFiguras);
            testeSomaAsteriscos(matriz, qtdFiguras);
            mostraQuadro(matriz);
            break;
          case 3:
            limpaQuadro(matriz);
            perguntaQtdFiguras();
            scanf("%d", &qtdFiguras);
            qtdFiguras = formataQtdFiguras(qtdFiguras);
            testeXComAsteriscos(matriz, qtdFiguras);
            mostraQuadro(matriz);
            break;
          case 4:
            limpaQuadro(matriz);
            perguntaQtdFiguras();
            scanf("%d", &qtdFiguras);
            qtdFiguras = formataQtdFiguras(qtdFiguras);
            testeFigurasAleatorias(matriz, qtdFiguras);
            mostraQuadro(matriz);
            break;
          case 5:
            printf("Saindo da area de Teste e voltando pra menu principal...\n");
            break;
          default:
            printf("Opção inválida\n");
            break;
          }
        }
      break;
    case 6:
      int opcao6 = 0;
      limpaQuadro(matriz);
      perguntaLorax();
      scanf("%d", &qtdFiguras);      
      qtdFiguras = formataQtdFigurasArvores(qtdFiguras);
      perguntaLorax2();

      scanf("%d", &opcao6);
      if (opcao6 == 1)
      {
        //arvoreCheia(matriz, qtdFiguras);//
        //arvoreDeMaca(matriz, qtdFiguras);//
        //arvore2galhos(matriz, qtdFiguras);//
        florestaSalva(matriz, qtdFiguras);
        mostraQuadroLorax(matriz);
        respostaLoraxBoa();
      }
      else if (opcao6 == 2)
      {
        florestaQueimada(matriz, qtdFiguras);
        mostraQuadroLorax(matriz);
        respostaLoraxRuim();
      }
      
      break;
    case 7:
      printf("Saindo...\n");
      break;
    default:
      printf("Opção inválida\n");
      break;
    }
  }
  
    
    return 0;
}