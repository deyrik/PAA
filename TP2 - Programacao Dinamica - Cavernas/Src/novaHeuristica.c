#include "../Headers/novaHeuristica.h"


resultado melhorPosicao(Mapa mapa,posicao atual,int linhaFinal,int colunaFinal){
    
    resultado r;
    

    //se tem como ir pra tres direçoes :
    if (atual.x > linhaFinal && atual.y > colunaFinal){

        //se o valor que tiver na posiçao for um Baú, fica mais interessante ir para ele, tendo o  maior valor sempre
        //se tiver um Baú, ele vai ter um valor de 66 em ASCII

        int a = mapa[atual.x-1][atual.y];//cima
        int b = mapa[atual.x][atual.y-1];//esquerda 
        int c = mapa[atual.x-1][atual.y-1];//noroeste

        int melhorValor = (a > b) ? a : b;
        melhorValor = (melhorValor > c) ? melhorValor : c;

        if(melhorValor == a){
            r.pos.x = atual.x-1;
            r.pos.y = atual.y;
            r.valor = a;
        }else if(melhorValor == b){
            r.pos.x = atual.x;
            r.pos.y = atual.y-1;
            r.valor = b;
        }else{
            r.pos.x = atual.x-1;
            r.pos.y = atual.y-1;
            r.valor = c;
        }

    }
    
    //se tem como ir para esquerda
    if (atual.x == linhaFinal && atual.y > colunaFinal){
            int b = mapa[atual.x][atual.y-1];//esquerda 
            r.pos.x = atual.x;
            r.pos.y = atual.y-1;
            r.valor = b;
        }
    
    //se tem como ir para cima
    if (atual.x > linhaFinal && atual.y == colunaFinal){
        int a = mapa[atual.x-1][atual.y];//cima
        r.pos.x = atual.x-1;
        r.pos.y = atual.y;
        r.valor = a;
 
    }

    //pode retonar valor ASCII de B 
    return r;
}

ponteiroLista progamaçaoD(Mapa mapa,informacoes info,caminhando aluno){

    aluno.pos.x = info.linhaI;
    aluno.pos.y = info.colunaI;

    ponteiroLista lista = criaLista(aluno.pos);
    resultado proximaPosicao;

 
    //vou fazer o trajeto enquanto a vida dele for positiva e X e Y forem diferentes do final
    while(info.HP > 0 && (aluno.pos.x != info.linhaF || aluno.pos.y != info.colunaF)){

        proximaPosicao = melhorPosicao(mapa,aluno.pos,info.linhaF,info.colunaF);

        //atualizar a posiçao do aluno
        aluno.pos.x = proximaPosicao.pos.x;
        aluno.pos.y = proximaPosicao.pos.y;
        insereLista(lista,aluno.pos);

        //atualizar a vida do aluno
        if (proximaPosicao.valor != 'F' && proximaPosicao.valor != 'I'|| proximaPosicao.valor != 'B'){
            //info.HP += proximaPosicao.valor;
        }

        if (proximaPosicao.valor == (int)'B'){//se a proxima posição for um Baú
            int valorAleatorio = rand() % 2;
            if (valorAleatorio == 0){
                //info.HP -= 20;//poção de vida
            }else{
                //info.HP -= 10;// uma aranha venenosa
            }
            
        }
        
    }

    //verifica se ele morreu
    if(info.HP <= 0){
        return NULL;
    }
    //verifica se ele chegou ao final
    if(info.HP >10 && aluno.pos.x == info.linhaF && aluno.pos.y == info.colunaF){
        return lista;
    }
}

void guardarInformacoes(ponteiroLista lista) {

    FILE *arquivo;
    arquivo = fopen("Out/resultado2.txt", "w");

    if (lista == NULL){
        fprintf(arquivo, "impossivel\n");
        return;
    }

    while (lista != NULL) { 
        fprintf(arquivo, "%d %d\n", lista->posicao.x, lista->posicao.y);
        lista = lista->prox;
    }

    fclose(arquivo);
}

