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

#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include "fbn.h"

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

