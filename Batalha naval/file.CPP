#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#include <conio.h>

void main()
{
	FILE *fp;

   if ((fp=fopen("base.txt", "r")) == NULL)
   {
   	cout << "O Arquivo nao pode ser aberto.\n";
      getch();
      exit(1);
   }

   while(!feof(fp))
   {
      char matriz[5];
   	if(fgets(matriz, 6, fp)) cout << matriz << '|';
   }
   fclose(fp);
   /*for ( ; (i >= 0); i--)
   {
   	cout << str[i] << '\n';
   } */
   getch();
}
