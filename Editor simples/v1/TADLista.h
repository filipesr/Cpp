#include <stdio.h>
#include <stdlib.h>
#include "tinfo.h"

typedef struct NO *apontaNO;

typedef struct NO {
        apontaNO prox;
        apontaNO ant;
        tinfo elem;
}NO;


typedef struct tcabecalho {
        apontaNO primeiro;
        apontaNO ultimo;
        apontaNO janela;
        int tam;        
}*tadlista;



//FUNÇÔES CONSTRUTORAS
tadlista inicLista();

//FUNÇÔES MODIFICADORAS
void inseriNOdep(tadlista, tinfo);
void inseriNOant(tadlista, tinfo);
void priLista(tadlista);
void ultiLista(tadlista);
void tirarNO(tadlista);
void destroiLista(tadlista*);
void posLista(tadlista, int);
void proxNO(tadlista);
tadlista DestroiList(tadlista);
void RetiraNO(tadlista);


//FUNÇÕES ANALISADORAS
tinfo infoLista(tadlista);
int tamLista(tadlista);



 







