//tadpilha.c  

//IMPLEMENTACAO DE PILHA USANDO O TADLista
#include "tadpilha.h"

// FUNCOES CONSTRUTORAS

//Incia a Pilha
tadpilha IniciaPilha()
{
	return inicLista();
};

//Inseri um nó no noto da lista, considerando o topo sempre no primeiro da lista
void InsereNoTopo(tadpilha p, tinfo Elem)
{
	priLista(p);
	inseriNOant(p,Elem);
};

//FUNCOES ANALIZADORAS


//Retorna o elemento do topo da Pilha
tinfo InfoPilha(tadpilha p)
{
	priLista(p);
	return infoLista(p);
};

//retorna 1 se Pilha vazia e 0 caso contrario
int VerificaPilhaVazia(tadpilha p)
{
	return (tamLista(p)==0);
};


//FUNCOES DESTRUIDORAS

//Elimina Elemento do Topo

void EliminaNoTopo(tadpilha p)
{
	priLista(p);
	RetiraNO(p);
};

//Desaloca a  pilha

tadpilha DestroiPilha(tadpilha p)
{
	return DestroiList(p);
}
