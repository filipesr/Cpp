/*
  solução ótima usando o menor esforço com remoção de percurso
*/
#include <stdio.h>
#include <string.h>

# define MAX 100
# define TamNome 20

// estrutura do banco de dados sobre vôos
struct FL {
   char from[TamNome]; // de
   char to[TamNome];   // para
   int distance;
   char skip;     // usado para retorno
};

struct FL flight[MAX]; // matriz de estruturas do bd

int f_pos = 0; // número de entradas do bd dos vôos
int find_pos = 0; // índice de pesquisa no bd dos vôos

int tos = 0; // topo da pilha
int stos = 0; // topo da pilha de solução

struct stack {
   char from[TamNome];
   char to[TamNome];
   int dist;
};

struct stack bt_stack[MAX]; // pilha de retorno
struct stack solution[MAX]; // guarda soluções temporárias

void setup(void);
int route(void);
void assert_flight(char *from, char *to, int dist);
void push(char *from, char *to, int dist);
void pop(char *from, char *to, int *dist);
void isflight(char *from, char *to);
void spush(char *from, char *to, int dist);
int find(char *from, char *anywhere);
int match(char *from, char *to);

int main(int argc, char *argv[])
{
  char from[TamNome], to[TamNome];
  int t, d;
  
  setup();
  
  printf("De: A1\nPara: I9\n");
  strcpy(from, "A");
  strcpy(to, "I");
  
  do{
    isflight(from, to);
    d = route();
    tos = 0; // reinicializa a pilha de retorno
  } while(d != 0); // enquanto estiver encontrando soluções
  
  t = 0;
  printf("A solucao otima eh:\n");
  while (t < stos) {
     printf("%s para ", solution[t].from);
     d += solution[t].dist;
     t++;
  }
  printf("%s\n", to);
  printf("A distancia eh %d.\n", d);
  
  system("PAUSE");
  return 0;
}

// Iicializa o banco de dados de vôos
void setup(void)
{
   assert_flight("A", "B", 10);
   assert_flight("A", "C", 20);
   assert_flight("A", "D", 10);
   assert_flight("B", "A", 15);
   assert_flight("B", "C", 15);
   assert_flight("C", "A", 15);
   assert_flight("C", "C", 15);
   assert_flight("C", "D", 15);
   assert_flight("D", "E", 10);
   assert_flight("D", "F", 5);
   assert_flight("E", "F", 15);
   assert_flight("F", "G", 55);
   assert_flight("G", "H", 55);
   assert_flight("H", "A", 55);
   assert_flight("H", "I", 55);
}

// Coloca os fatos no banco de dados
void assert_flight(char *from, char *to, int dist)
{
   if(f_pos < MAX)
   {
      strcpy(flight[f_pos].from, from);
      strcpy(flight[f_pos].to, to);
      flight[f_pos].distance = dist;
      flight[f_pos].skip = 0;
      f_pos++;
   }
   else printf("Banco de dados de voos cheio.\n");
}

// encontra a menor distância
int route(void)
{
   int dist, t;
   static int old_dist = 32000;

   
   if(!tos) return 0; // feito

   t = 0;
   dist = 0;
   while(t < tos)
   {
      dist += bt_stack[t].dist;
      t++;
   }

   // se menor, então ache a nova solução
   if (dist < old_dist && dist)
   {
      t = 0;
      old_dist = dist;
      stos = 0; // limpa a rota antiga da pilha de posição
      while (t < tos)
      {
         spush(bt_stack[t].from, bt_stack[t].to, bt_stack[t].dist);
         t++;
      }
   }
   return dist;
}

// se há um vôo entre from e to, então devolve a distância do vôo;
// caso contrário, devolve 0
int match(char *from, char *to)
{
   register int t;
   
   for(t = f_pos - 1; t > -1; t--)
      if (!strcmp(flight[t].from, from) && !strcmp(flight[t].to, to)) return flight[t].distance;
   
   return 0; // não encontrou
}

// Dado um from, encontra um anywhere
int find(char *from, char *anywhere)
{
   find_pos = 0;
   while(find_pos < f_pos)
   {
      if(!strcmp(flight[find_pos].from, from) && !flight[find_pos].skip)
      {
         strcpy(anywhere, flight[find_pos].to);
         flight[find_pos].skip = 1;
         return flight[find_pos].distance;
      }
      find_pos++;
   }
   return 0;
}


// Determina se há uma rota entre from e to
void isflight(char *from, char *to)
{
   int d, dist;
   char anywhere[TamNome];
   
   if(d = match(from, to))
   {
      push(from, to, d); // distancia
      return;
   }
   
   if (dist = find( from, anywhere))
   {
      push(from, to, dist);
      isflight(anywhere, to);
   }
   else if(tos > 0)
   {
      pop(from, to, &dist);
      isflight(from, to);
   }
}

// rotinas de pilha
void push(char *from, char *to, int dist)
{
   if(tos < MAX)
   {
      strcpy(bt_stack[tos].from, from);
      strcpy(bt_stack[tos].to, to);
      bt_stack[tos].dist = dist;
      tos++;
   }
   else printf("Pilha cheia\n");
}

void pop(char *from, char *to, int *dist)
{
   if(tos > 0)
   {
      tos--;
      strcpy(bt_stack[tos].from, from);
      strcpy(bt_stack[tos].to, to);
      *dist = bt_stack[tos].dist;
   }
   else printf("Pilha cheia\n");
}

// Pilha e solução
void spush(char *from, char *to, int dist)
{
   if(stos < MAX)
   {
      strcpy(solution[stos].from, from);
      strcpy(solution[stos].to, to);
      solution[stos].dist = dist;
      stos++;
   }
   else printf("Pilha de menor distancia cheia\n");
}
