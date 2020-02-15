/*  tadPilha.h e uma TAD que e derivada da TADPilha.h*/

#include "tadlista.h"

typedef tadlista tadpilha;

//FUNCOES CONSTRUTORAS

tadpilha IniciaPilha();
void InsereElemento(tadpilha);

//FUNCOES ANALIZADORAS
int VerificaPilhaVazia(tadpilha);
tinfo InfoPilha(tadpilha);

//FUNCOES DESTRUTORAS
void EliminaNoTopo(tadpilha);
tadpilha DestroiPilha(tadpilha);


 
