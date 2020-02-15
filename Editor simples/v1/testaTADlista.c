/*Programa para testar o TADlista*/
#include <stdio.h>
#include "tadlista.h"
#include <time.h>

//retorna uma lista que e um clone da que recebeu
tadlista CloneLista(tadlista List)
{
	tadlista aux;
	int i;
	aux=inicLista();//cria uma nova lista
	
	priLista(List);//coloca a janela no primeiro no
	
	for (i=1;i<=tamLista(List);i++)
	{
		inseriNOdep(aux,infoLista(List));//insere no depois da janela e coloca a janela no novo no
		proxNO(List);	//pula para o proximo no
	}
	return aux; //retorna um ponteiro para nova lista
}
void InseriNoOrdenado(tadlista List, tinfo Dado)
{
	int i,*aux1,*aux2;
	priLista(List);
	if(List->tam==0)
	{
		inseriNOdep(List,Dado);
	}
	else	
	{
		for(i=1;i<=List->tam;i++)	
		{
			aux1=(int*)infoLista(List);
			aux2=(int*)Dado;
			if(*aux1 >= *aux2 )
			{
				inseriNOant(List,Dado);
				break;
				
			}
			else
			{
				if(i==List->tam)
				{
					
					inseriNOdep(List,Dado);
					break;
				}	
			}
			proxNO(List);
		}
		
		
	}
	aux1=NULL;
	aux2=NULL;
}
//retorna 1 se tem o elemento Elem na lista e 0 caso contrario
int VerificaElem(tadlista List,tinfo Elem )
{
	int i;
	priLista(List);
	for (i=1;i<=tamLista(List);i++)
	{
		if(infoLista(List)==Elem)
		{
			return 1;
			break;
		}
		proxNO(List);
	}
	return 0;	
}
//
int ComparaDuasLista (tadlista List1, tadlista List2)
{
	int i;
	if(tamLista(List1)!=tamLista(List2))
	{
		return 0;
	}
	else
	{
		priLista(List1);
		priLista(List2);
		for(i=1;i<=tamLista(List1);i++)
		{
			if(infoLista(List1)!= infoLista(List2))
			{	
				return 0;
				break;
				
			}
			proxNO(List1);
			proxNO(List2);

		}
		

	}
	return 1;
}
//faz a uniao de duas listas. Porem, sem repeticao de elementos
tadlista UniaoDuasLista(tadlista List1, tadlista List2)
{
	int i,j,*aux1,*aux2;
	tadlista aux=inicLista();
	priLista(List1);
	priLista(List2);
	
	aux=CloneLista(List1);
	for(i=1;i<=tamLista(List2);i++)
	{
		
		priLista(aux);
		for(j=1;j<=tamLista(aux);j++)
		{	
			aux1=(int*)infoLista(aux);
			aux2=(int*)infoLista(List2);
			if(*aux1==*aux2)
				break; 
			if(j==tamLista(aux))
			{
				ultiLista(aux);	
				inseriNOdep(aux,infoLista(List2));		
				break;
			} 
			proxNO(aux);
		}
		proxNO(List2);
	}
	aux1=NULL;
	aux2=NULL;		
	return aux;
}
//funcao que cria uma lista que e a interceccao de outra duas listas e sem repetir elementos
tadlista IntersecaoDuasLista(tadlista List1, tadlista List2)
{
	int i,j,*aux1,*aux2;
	tadlista aux=inicLista();
	priLista(List1);
	priLista(List2);
	for(i=1;i<=tamLista(List1);i++)
	{
		priLista(List2);
		for(j=1;j<=tamLista(List2);j++)
		{
			aux1=(int*)infoLista(List1);;
			aux2=(int*)infoLista(List2);
			if( *aux1==*aux2 && ( VerificaElem(aux,aux2) !=1 )  )
			{
				inseriNOdep(aux,infoLista(List2));
				break; 
			}
			proxNO(List2);
		}
		proxNO(List1);
	}
	aux1=NULL;
	aux2=NULL;	
	return aux;
}
/************************funcao principal***********************************/

int main()
{
	tadlista List1,List2,Ordenado,Clone,Uniao,Intersecao;
	int i,*Ptr;
	//inicia a lista
	List1=inicLista();
	List2=inicLista();
	Ordenado=inicLista();
	//anexa o conteudo das Listas
	for(i=1;i<=12;i++)
	{
		Ptr=(int*)malloc(sizeof(int));
		*Ptr=i;
		inseriNOdep(List1,(void*)Ptr);
		
	}
	for(i=11;i<=20;i++)
	{
		Ptr=(int*)malloc(sizeof(int));
		*Ptr=i;
		inseriNOdep(List2,(void*)Ptr);
		
	}	
	
	/* Imprimi as listas*/
	priLista(List1);//coloca a janela no primeiro no
	printf("\n\t********Lista 1***********\n");
	for(i=1;i<=tamLista(List1);i++)
	{
		
		Ptr=(int*)infoLista(List1);
		printf("\n %d",*Ptr);
		proxNO(List1);  
	}
	printf("\n\t********Lista 2***********\n");
	priLista(List2);
	for(i=1;i<=tamLista(List2);i++)
	{
		
		Ptr=(int*)infoLista(List2);
		printf("\n %d",*Ptr);
		proxNO(List2);  
	}	
	//Cria listas derivadas	
	Clone=CloneLista(List2);

	priLista(Clone);
	printf("\n\t********Lista Clone da Lista 2***********\n");
	for(i=0;i<tamLista(Clone);i++)
	{
		
		Ptr=(int*)infoLista(Clone);
		printf("\n %d",*Ptr);
		proxNO(Clone);  
	}
	//---TESTANDO A FUNCAO QUE COMPARA AS LITAS---//
  	printf("\nLista 1 igual a Lista 2?\n");
  	if(ComparaDuasLista(List1, List2))
  		printf("Verdadeiro\n");
  	else
  		printf("Falso\n");

  	printf("\nLista 2 igual a Clone de Lista 2?\n");
  	if(ComparaDuasLista(List2, Clone))
  		printf("Verdadeiro\n");
  	else
  		printf("Falso\n");
	
	printf("\nInserindo o valor 2 no inicio da Lista 2, e retirando o ultimo da lista (20)\n");
  	priLista(List2);
 	Ptr=(int*)malloc(sizeof(int));
	*Ptr=2;
  	inseriNOant(List2,(void*)Ptr);
  	ultiLista(List2);
  	RetiraNO(List2);
	
	printf("\n\t********Nova Lista 2***********\n");
	priLista(List2);
	for(i=0;i<tamLista(List2);i++)
	{
		
		Ptr=(int*)infoLista(List2);
		printf("\n %d",*Ptr);
		proxNO(List2);  
	}
	
	priLista(Clone);
	printf("\n\t********Clone após auteração na Lista 2***********\n");
	for(i=0;i<tamLista(Clone);i++)
	{
		
		Ptr=(int*)infoLista(Clone);
		printf("\n %d",*Ptr);
		proxNO(Clone);  
	}	

	//Compara se clone e igual lista 2
	printf("\ne agora Lista 2 igual a clone de lita 2?\n");
  	if(ComparaDuasLista(List2,Clone))
  		printf("Verdadeiro\n");
  	else
  		printf("Falso\n");
	
	for(i=0;i<10;i++)
	{
		Ptr=(int*)malloc(sizeof(int));
		*Ptr=rand()%100;
		InseriNoOrdenado(Ordenado,(void*)Ptr);
	}
	printf("\n\t********Lista Ordenada***********\n");
	priLista(Ordenado);
	for(i=0;i<Ordenado->tam;i++)
	{
		
		Ptr=(int*)infoLista(Ordenado);
		printf("\n %d",*Ptr);
		proxNO(Ordenado);
	}

	//testa funcao UniaoDuasLista
	Uniao=UniaoDuasLista(List1,List2);
	printf("\n\t********Uniao Lista1 com Lista2***********\n");
	priLista(Uniao);
	for(i=0;i<tamLista(Uniao);i++)
	{
		
		Ptr=(int*)infoLista(Uniao);
		printf("\n %d",*Ptr);
		proxNO(Uniao);  
	}
	
	//testa funcao IntersecaoDuasLista
	Intersecao=IntersecaoDuasLista(List1,List2);
	printf("\n\t********Intersecao Lista1 com Lista2***********\n");
	priLista(Intersecao);
	for(i=1;i<=tamLista(Intersecao);i++)
	{
		
		Ptr=(int*)infoLista(Intersecao);
		printf("\n %d",*Ptr);
		proxNO(Intersecao);  
	}


		printf("\n\n");
/***********Desalocamento das listas***************/
	
	priLista(List1);
	//desaloca o conteudo de elem
	for(i=0;i<tamLista(List1);i++)
	{
		Ptr=(int*)infoLista(List1);
		free(Ptr);
		proxNO(List1);
	}
	priLista(List2);
	//desaloca o conteudo de elem
	for(i=0;i<tamLista(List2);i++)
	{
		Ptr=(int*)infoLista(List2);
		free(Ptr);
		proxNO(List2);
	}
	priLista(Ordenado);
	for(i=0;i<tamLista(Ordenado);i++)
	{
		Ptr=(int*)infoLista(Ordenado);
		free(Ptr);
		proxNO(Ordenado);
	}
	



	//apaga a lista inteira
	 
	List1=DestroiList(List1);
	List2=DestroiList(List2);
	Clone=DestroiList(Clone);
	Ordenado=DestroiList(Ordenado);
	Intersecao=DestroiList(Intersecao);
	Uniao=DestroiList(Uniao);
	return 0;
}
