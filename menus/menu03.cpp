#include <iostream.h>
#include <conio.h>

int criamenu(int pos)
{
/*
       menu[z][j][i] em que:
         s = 4, -> Submenus
         l = 2, -> Opções + 1 = 2 + 1 = 3
   		c = 8; -> Letras

      Submenu1		Submenu2		Submenu3		Submenu4
       opt11		 opt21		 opt31		 opt41
       opt12		 opt22		 opt32		 opt42
*/

	int const s = 5,
   			 l = 3;

   char menu[s][l][10] = {"Submenu1\0"," opt11  \0"," opt12  \0",
                          "Submenu2\0"," opt21  \0"," opt22  \0",
                          "Submenu3\0"," opt31  \0"," opt32  \0",
                          "Submenu4\0"," opt41  \0"," opt42  \0",
                          "0 - Sair\0","\0","\0"};

   cout << '\n';
   for (int i = 0; (i < l); i++)
   {
   	for (int z = 0; ( z < s); z++)
      {
      	cout << "\t";
         if ((z == (pos - 1)) || (i == 0))
         	cout << menu[z][i];
         else
         	cout << "\t";
      }
      cout << '\n';
   }
	int i = (getch() - 48);
   clrscr();
   return i;
}

void main()
{
   int i = criamenu(-1);
   while (i != 0)
   {
   	i = criamenu(i);
   }
}

