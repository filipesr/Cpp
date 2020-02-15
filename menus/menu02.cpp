/*********************************************************
*                   __.............__                    *
*           .--""```                 ```""--.            *
*            ':--..___             ___..--:'             *
*              \      ```"""""""```      /               *
*            .-`  ___.....-----.....___  '-.             *
*          .:-""``     ~          ~    ``""-:.           *
*         /`-..___ ~        ~         ~___..-'\          *
*        /  ~    '`""---.........---""`        \         *
*       ;                                       ;        *
*      ; '::.   '          _,           _,       ;       *
*      |   ':::    '     .' (    ~   .-'./    ~  |       *
*      |~  .:'   .     _/..._'.    .'.-'/        |       *
*      | .:'       .-'`      ` '-./.'_.'         |       *
*      |  ':.     ( o)   ))      ;= <_           |       *
*      ; '::.      '-.,\\__ __.-;`\'. '.  .      ;       *
*       ;    ':         \) |`\ \)  '.'-.\       ;        *
*        \.:'.:':.         \_/       '-._\     /         *
*         \ ':.     ~                    `    /          *
*          '. '::..  _ . - - -- .~ _      ~ .'           *
*            '-._':'                 `'-_.-'             *
*               (``''--..._____...--''``)                *
*                `"--...__     __...--"`                 *
*                                                        *
*                                                        *
*   Sistema  : DOS                                       *
*                                                        *
*   Programa : Menu de opções                            *
*                                                        *
*   Autor    : Filipe                                    *
*                                                        *
*   Data     : 10/09/2004                                *
*                                                        *
*********************************************************/

#include <iostream.h> // cin e cout
#include <conio.h>    // getch() e clrscr()

const int COL = 7,
			 LIN = 8,
          CAM = 9;

char menu[CAM][LIN][COL] = {"Menu1\0","opt01\0","opt02\0","opt03\0","opt04\0","opt05\0","opt06\0","opt07\0",
   							 	 "Menu2\0","opt01\0","opt02\0","opt03\0","opt04\0","opt05\0","opt06\0","opt07\0",
                            "Menu3\0","opt01\0","opt02\0","opt03\0","opt04\0","opt05\0","opt06\0","opt07\0",
                            "Menu4\0","opt01\0","opt02\0","opt03\0","opt04\0","opt05\0","opt06\0","opt07\0",
                            "Menu5\0","opt01\0","opt02\0","opt03\0","opt04\0","opt05\0","opt06\0","opt07\0",
                            "Menu6\0","opt01\0","opt02\0","opt03\0","opt04\0","opt05\0","opt06\0","opt07\0",
                            "Menu7\0","opt01\0","opt02\0","opt03\0","opt04\0","opt05\0","opt06\0","opt07\0",
                            "Menu8\0","opt01\0","opt02\0","opt03\0","opt04\0","opt05\0","opt06\0","opt07\0",
                            "Menu9\0","opt01\0","opt02\0","opt03\0","opt04\0","opt05\0","opt06\0","opt07\0"};


void mostramenu();

void mostrasubmenu(int opt);

void main()
{
	mostramenu();
}

void mostramenu()
{
   cout << "\n\n";

   for (int i = 0; (i < CAM); i++)
   	cout << "\t" << menu[i][0];

   int opt = -1;
   while ((opt < 0) || (opt > LIN))
   {
   	opt = (getch() - 49);
   }

	mostrasubmenu(opt);

   getch();
}

void mostrasubmenu(int opt)
{
   for (int i = 1; (i < LIN); i++)
   {
   	cout << "\n\n\t";
      for (int j = 0; (j < opt); j++)
      {
      	cout << "\t";
      }
   	cout << menu[opt][i];
   }
}
