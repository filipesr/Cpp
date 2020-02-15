/*********************************************************
*                                                        *
*   Sistema  : DOS                                       *
*                                                        *
*   Programa : Campo Minado                              *
*                                                        *
*   Autor    : Filipe                                    *
*              Fernando                                  *
*                                                        *
*   Data     : 02/11/2004                                *
*                                                        *
*********************************************************/

#include <iostream.h> // cin, cout
#include <conio.h> // getch()
#include <stdlib.h> // random

const int tam = 16; // Tamanho da Matriz do Jogo
const int ship = 30; // Números de Navios do Jogo

// Nome da função: zeratabela
//						A função preenche com 0 todas as posições de uma camada numa matriz
// Parâmetros:
//			int mt[2][tam][tam] = matriz vazia, que será preenchida com 0
//			int cam = camada da matriz que será preenchida com 0
// Retorno da função: void
void zeratabela(int mt[2][tam][tam], int cam);

// Nome da função: geratabela
//						A função preenche com 1 um determinado numero de posições
// Parâmetros:
//			int mt[2][tam][tam] = matriz, já inicializado, que será preenchida com 1
//			int cam = camada da matriz que será preenchida com 1
//			int tipo = define se existe interação do usuário na escolha da posição onde:
// 			 tipo = 1, solicita uma posição do usuario
// 			 tipo = 0, gera uma posição válida aleatória
// Retorno da função: void
void geratabela(int mt[2][tam][tam], int cam, int tipo);

// Nome da função: mostratabela
//						A função que mostra, ao usuário, os elementos de uma matriz
// Parâmetros:
//			int mt[2][tam][tam] = matriz que será mostrada
//			int cam = camada da matriz que será mostrada
// Retorno da função: void
void mostratabela(int mt[2][tam][tam], int cam);

// Nome da função: checatiro
//						A função verifica se uma posição numa matriz é, ou não, zero
// Parâmetros:
//			int mt[2][tam][tam] = matriz quer será verificada a posição
//			int col = primeira coordenada, referente à coluna
//			int lin = segunda coordenada, referente a linha
// Retorno da função:
//				Retorna 0 se o valor for igual a zero e -1 se for diferente de zero
int checatiro(int mt[2][tam][tam], int col, int lin);

// Nome da função: tiro
//						A função que adiciona o valor 1 ou -1 na tabela de tiros do jogador
// Parâmetros:
//			int mt[2][tam][tam] = matriz de tiros do jogador
//			int mt2[2][tam][tam] = matriz de navios do adversário
//			int col = primeira coordenada, referente à coluna
//			int lin = segunda coordenada, referente a linha
//			int tipo = define se existe interação do usuário na escolha da posição onde:
// 			 tipo = 1, solicita uma posição do usuario
// 			 tipo = 0, gera uma posição válida aleatória
// Retorno da função:
//				Retorna 1, se o tiro acertar, e 0, se errar
int tiro(int mt[2][tam][tam], int mt2[2][tam][tam], int tipo);

void main()
{
   int jog1[2][tam][tam], jog2[2][tam][tam], pjog = 0, pcpu = 0, rodada = 0;
   	/*
         jog1[0] = mapa de tiro do jogador 1 - usuário
         jog1[1] = mapa de posição do jogador 1 - usuário
         jog2[0] = mapa de tiro do jogador 2 - cpu
         jog3[1] = mapa de posição do jogador 2 - cpu
         pjog = pontos do jogador
         pcpu = pontos do cpu
         rodada = numero de rodadas passadas
      */

   zeratabela(jog1, 0);
   zeratabela(jog1, 1);
   zeratabela(jog2, 0);
   zeratabela(jog2, 1);

   geratabela(jog1, 1, 0);
   geratabela(jog2, 1, 0);

   cout << "\n\tSeu mapa de navios ficou assim:\n\n";
   mostratabela(jog1, 1);

   cout << "\n\n\tPressione uma tecla para iniciar o jogo!";
	getch();
   cout << "\n\n\tCaro usuário, pode começar a jogar.";

	while ((pjog < ship)&&(pcpu < ship))
   	{
         clrscr();
         cout << "\n\n\tMapa de tiros:\n\n";
         mostratabela(jog1, 0);
      	pjog += tiro(jog1,jog2,1);
      	pcpu += tiro(jog2,jog1,0);

         cout << "\n\n\n\n\t\t\t   Rodada " << ++rodada
                   << ":\n\t\t\t +++++++++-+++\n"
         	          << "\t\t\t| Jogador | " << pjog
                  << " |\n\t\t\t|  C P U  | " << pcpu
                  << " |\n\t\t\t +++++++++-+++\n\n\n";

         getch();

         cout << "\n\n\tSeus mapas estao assim:\n\n\tMapa de navios:\n\n";
         mostratabela(jog1, 1);
         getch();
      }

   cout << "\n\n\t";
   if (pjog == pcpu)
   	cout << "Empate";
   else
   	cout << "Vitoria do " <<((pjog > pcpu)? "usuario": "cpu");
	cout << " em " << rodada << " rodadas.";

   getch();
}

void zeratabela(int mt[2][tam][tam], int cam)
{
   for (int i = 0; i < tam; i++)
   	for (int j = 0; j < tam; j++)
       	mt[cam][i][j] = 0;

}
void geratabela(int mt[2][tam][tam], int cam, int tipo)
{
   int lin, col;
   for (int i = 1; i <= ship;)
   {
   	if (tipo)
      {
   		if (i == 1)
         	cout << "\n\nEntre com as posicoes de seus navios (linha e coluna):\n";
         cout << "\n" << i <<") ";
      	cin >> lin >> col;
      }
      else
      {
			lin = random(tam);
      	col = random(tam);

      }
      if ((lin < tam) && (col < tam) && !(lin < 0) && !(col < 0))
      	if (mt[cam][lin][col] != 1)
         {
      		mt[cam][lin][col] = 1;
         	i++;
      	}
   }
}

void mostratabela(int mt[2][tam][tam], int cam)
{
	for (int lin = 0; lin < tam;lin ++)
   {
   	cout << "\n ";
   	for (int col = 0; col < tam; col ++)
      	cout << ((mt[cam][lin][col] != -1)?"  ":" ") << mt[cam][lin][col];
   }
   cout << "\n";
}

int checatiro(int mt[2][tam][tam], int lin, int col)
{
   if (mt[0][lin][col] == 0)
   	return 1;
	return 0;
}

int tiro(int mt[2][tam][tam], int mt2[2][tam][tam], int tipo)
{
	int tiro = 0, lin, col;
   while (tiro == 0)
   {
   	if (tipo)
      {
   		cout << "\n\n\tIndique a linha e coluna do seu tiro: ";
      	cin >> lin >> col;
      }
      else
      {
			lin = random(tam);
      	col = random(tam);
   		cout << "\n\tAgora eh a minha vez, meu tiro eh na posicao : " << lin << " e " << col;
      }
      tiro = checatiro(mt,lin,col);
   }

   if (mt2[1][lin][col])
	{
   	mt[0][lin][col] = 1;
      cout << "\n\t" << ((tipo)? "Oh, nao ! Voce acertou um navio!": "Eu acertei, agora eh sua vez denovo.");
      return 1;
   }

  	mt[0][lin][col] = -1;
   cout << "\n\t" << ((tipo)? "Caro usuario, voce errou :-)...": "Eu errei, agora eh a sua vez de novo.");
   return 0;
}
