#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include "fbn.h"

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
