/*********************************************************
*                                                        *
*   Sistema  : DOS                                       *
*                                                        *
*   Programa : Editor de texto Simples                   *
*                                                        *
*   Autor    :                                           *
*                                                        *
*   Data     : 15/04/2007                                *
*                                                        *
*********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*********************************************************
/* Todas as funções de lista encadeada serão usadas a    *
/* partir da biblioteca tadlista.h, que implementa uma   *
/* lista encadeada usando o conceito TAD.                *
/********************************************************/
#include "tadlista.h"
#define strTam  80

/*
  Esta função copia a linha pos para a linha atual
*/
void funcI(tadlista l, int pos);

/*
  Esta função apaga a linha i ou todas as linhas entre i e f
*/
void funcD(tadlista l, int i, int f);

/*
  Esta função lista a linha i ou todas as linhas entre i e f ou todas as linhas do arquivo
*/
void funcL(tadlista l, int i, int f);

/*
  Esta função anexa um texto t na linha pos
*/
void funcA(tadlista l, int pos, string t);

/*
  Esta função salva o arquivo e sai.
*/
int funcE(tadlista l, string arq);

/*
  Funções auxiliares
*/
// Loop de leitura da entrada do menu
// Quando vc digita o comando é essa função que se incarrega de interpretar
int menu(tadlista l);
// Faz a leitura do arquivo
int ArquivoLe(string arq, tadlista l);
// Adiciona a linha que vc digita e que não é comando
int LinhaAdd(tadlista l, string linha);

/************************funcao principal***********************************/
int main(int argc, char *argv[])
{
  // Lista ligada/Encadeada
  tadlista l = inicLista();
  int s = 0;
  
  // testa se o nome do arquivo a ser editado foi passado por parâmetro
  if (argc != 2)
  {
     printf("\n\n\tVocê esqueceu de digitar o nome do arquivo.\n\n");
     exit(1);
  }
  
  // testa se o nome corresponde a um arquivo que pode ser editado
  if (!ArquivoLe(argv[1],l))
  {
     printf("\n\n\tErro! O arquivo não pode ser aberto!\n\n");
     exit(1);
  }
  
  while (s == 0){
     s = menu(l);
  };

  // Salva o arquivo e sai
  funcE(l, argv[1]);
  l = DestroiList(l);
  return 0;
}

void funcI(tadlista l, int pos)
{
  // cria variável e aloca espaço na memoria
  string str = malloc(sizeof(string) * strTam);
  //move para a linha pos
  posLista(l, pos);
  // copia o a linha para a variável temporaria
  strcpy(str, infoLista(l));
  // vai para a ultima linha
  ultiLista(l);
  // adiciona o texto copiado
  inseriNOdep(l, str);
  // exibe
  printf("%d>%s", tamLista(l), str);
}

void funcD(tadlista l, int i, int f)
{
  // numero de linhas
  int tam = tamLista(l);
  if ((f == 0) && (i == 0))
  {
    i = 1;
    f = tam;
  }

  if (i == 0)
    i = 1;

  if (i > tam)
    i = tam;
  
  if  (f < i)
    f = i;
    
  if ((f > tam) || (f == 0))
    f = tam;
    
  posLista(l, i);

  if (i)
    for(;i<=f;i++)
       RetiraNO(l); // remove a(s) linha(s)
   
  
}

void funcL(tadlista l, int i, int f)
{
  int tam = tamLista(l);
  if ((f == 0) && (i == 0))
  {
    i = 1;
    f = tam;
  }

  if (i == 0)
    i = 1;

  if (i > tam)
    i = tam;
  
  if  (f < i)
    f = i;
    
  if ((f > tam) || (f == 0))
    f = tam;
    
  if (i)
    for(;i<=f;i++)
    {
       posLista(l, i);
       printf("%d>%s",i,infoLista(l));
    }
   
}

void funcA(tadlista l, int pos, string t)
{
  string str;
  int i = 4, j;
  posLista(l, pos);
  str = infoLista(l);
  j = strlen(str) - 1;
  while(t[i] != '\0')
  {
    str[j] = t[i];
    i++;
    j++;
    str[j] = '\n';
  }
  j++;
  str[j] = '\0';
  printf("%d>%s", pos, str);
}

int funcE(tadlista l, string arq)
{
  // Ponteiro de arquivo
  FILE *fp;
  
  if (tamLista(l))
  {
    priLista(l);
    fp = fopen(arq,"w+");
  	while(tamLista(l))
  	{
       fputs(infoLista(l),fp);
       RetiraNO(l);
    }
    fclose(fp);
  
    return 1;
  }
}

/*
  Funções auxiliares
*/
int menu(tadlista l)
{
  string str = malloc(sizeof(string) * strTam);
  char c = 'L';
  int i = 0, f = 0, ret = 0;
  printf("%d>", tamLista(l) + 1);
  gets(str);
  
  switch (str[0]) {
    case 76:
      if (strlen (str) > 2)
         i = str[2] - 48;
      if (strlen (str) == 5)
         f = str[4] - 48;
      funcL(l, i, f);
      break;

    case 65:
      if (strlen (str) >= 5)
         funcA(l, str[2] - 48, str);
      break;

    case 73:
      if (strlen (str) == 3)
         funcI(l, str[2] - 48);
      break;

    case 68:
      if (strlen (str) > 2)
         i = str[2] - 48;
      if (strlen (str) == 5)
         f = str[4] - 48;
      funcD(l, i, f);
      break;

    case 69:
        ret = 1;
      break;

    default:
      LinhaAdd(l, str);
  }
  free(str);
  return ret;
}

int ArquivoLe(string arq, tadlista l)
{
  // Ponteiro de arquivo
  FILE *fp;
  int i = 0, j;
  string t;

  // testa se o arquivo foi aberto
  if((fp = fopen(arq,"w+")) != NULL)
  {
    t = malloc(sizeof(string) * strTam);
  	//Le o conteudo do arquivo
  	while(fgets(t, strTam, fp)!=NULL)
  	{
      inseriNOdep(l,t);
      t = malloc(sizeof(string) * strTam);
    }
    // fecha o arquivo
    fclose(fp);
    // desaloca o espaço alocado para a variavel temporaria
    free(t);
    return 1;
  }

  return 0;
}

int LinhaAdd(tadlista l, string linha)
{
  // Ponteiro de arquivo
  string t = malloc(sizeof(string) * strTam);
  strcpy(t, linha);
  strcat (t, "\n");
  inseriNOdep(l, t);
  
  return 1;
  
  
}


