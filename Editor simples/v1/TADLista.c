#include "tadlista.h"

tadlista inicLista(){
     tadlista list;
     list = (tadlista)malloc(sizeof(struct tcabecalho));
     list->primeiro = NULL;
     list->ultimo = NULL;
     list->janela = NULL;
     list->tam = 0;
     return list;         
};

/*Inseri NO depois da Janela*/
void inseriNOdep(tadlista list, tinfo dados){
     
     apontaNO aux;
     aux = (apontaNO)malloc(sizeof(NO));
     aux->elem = dados;
     
     if(list->tam == 0){
         aux->prox=NULL;
         aux->ant=NULL;
         list->primeiro=aux;
         list->ultimo=aux;                                 
     }else{
         aux->ant=list->janela;
         aux->prox=list->janela->prox;
         list->janela->prox=aux;
         if(aux->prox == NULL){
             list->ultimo=aux;             
         }else{
             aux->prox->ant = aux;      
         }
     }

     list->janela=aux;
     list->tam++;
             
};

/*Inseri NO antes da Janela*/
void inseriNOant(tadlista list, tinfo dados){
     
     apontaNO aux;
     aux = (apontaNO)malloc(sizeof(NO));
     aux->elem = dados;
     
     if(list->tam == 0){
         aux->prox=NULL;
         aux->ant=NULL;
         list->primeiro=aux;
         list->ultimo=aux;                                 
     }else{
         aux->prox=list->janela;
         aux->ant=list->janela->ant;
         list->janela->ant=aux;
         if(aux->ant == NULL){
             list->primeiro=aux;             
         }else{
             aux->ant->prox = aux;      
         }
     }

     list->janela=aux;
     list->tam++;
             
};


int tamLista(tadlista list){
	return list->tam;
};

//Janela passa a apontar para o primeiro da lista
void priLista(tadlista list){
     list->janela=list->primeiro;    
};

//Janela passa a apontar para o ultimo da lista
void ultiLista(tadlista list){
     list->janela=list->ultimo;
};

//retorna o elemento que esta na janela
tinfo infoLista(tadlista list){
      return list->janela->elem;     
};

/*move a janela para o proximo NO - se chegar no ultimo fica no ultimo*/
void proxNO(tadlista list){
	if(list->janela != list->ultimo)
	    list->janela=list->janela->prox;     
};

//fazer a janela apontar para a posição (pas) da lista
void posLista(tadlista list, int pos){	
    if( (pos > 0) && (pos <= list->tam) ){
		int i=1;
		priLista(list);
		while(pos!=i){
	    	proxNO(list);
			i++;		
		}	
    }else
		printf("\nlista vazia ou posição invalida\n");
};

//retira um NO da lista (esteja a janela em qualquer posição)
void tirarNO(tadlista list){  
   
    if(list->tam != 0){

	    apontaNO aux;
	    aux = list->janela;
				
	    list->tam--;
		if(list->primeiro != list->ultimo){		//se não for o unico NO

			if(list->janela == list->primeiro){ ///quando janela no 1º
				aux->prox->ant=NULL;
        		list->primeiro=aux->prox;
				list->janela=aux->prox;
			}else{
				if(list->janela == list->ultimo){///quando janela no ultimo
					list->ultimo=aux->ant;
					aux->ant->prox=NULL;
					list->janela=aux->ant;
				}else{							///quando janela no meio
					aux->ant->prox=aux->prox;
					aux->prox->ant=aux->ant;
					list->janela=aux->prox;
				}
			}

		}else{							//quando for o unico NO
			list->primeiro=NULL;			
			list->ultimo=NULL;		
			list->janela=NULL;
		}
		free(aux);
	}
	
};
//Coloca a janela no pr�ximo e retira o no que a janela apontava , retorna -1 se lista vazia e zero caso contr�rio
void RetiraNO(tadlista List)
{
	 apontaNO aux;
	 aux = List->janela;
	if(List->tam==0)
	{
		printf("\n A lista esta vazia \n");
	}	
	else
	{
		if(List->janela==List->primeiro)
		{
			if(List->tam==1)
			{
				aux=List->janela;
				List->primeiro=NULL;
				List->janela=NULL;
				List->ultimo=NULL;
				free(aux);
				List->tam--;
			}else
			{
				aux=List->janela;
				List->janela=List->janela->prox;
				List->janela->ant=NULL;
				List->primeiro=List->janela;
				free(aux);
				List->tam--;
			}
		}else
		{
			if(List->janela==List->ultimo)
			{ 
				aux=List->janela;
				List->janela=List->janela->ant;
				List->janela->prox=NULL;
				List->ultimo=List->janela;
				free(aux);
				List->tam--;
			}else
			{
				aux=List->janela;
				List->janela->ant->prox=List->janela->prox;
				List->janela->prox->ant=List->janela->ant;
				List->janela=List->janela->prox;
				free(aux);
				List->tam--;

			}	

		}	
	}
	 
};
//Elimina a lista inteira
tadlista DestroiList(tadlista List)
{
	int i;
	priLista(List);
	for (i=1;i<=(List)->tam;i++)
		RetiraNO(List);
	free(List);
	List=NULL;
	return List;
};
//retira todos os NOs da lista (deixando a lista vazia)
void destroiLista(tadlista *list){
	int i;
	priLista(*list);
	for(i=1;i<=tamLista(*list);i++)				
		tirarNO(*list);
	free(*list);
	*list=NULL;
	
};



