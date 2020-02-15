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
*   Programa : Controle financeiro simples               *
*                                                        *
*   Autor    : Filipe                                    *
*                                                        *
*   Data     : 10/09/2004                                *
*                                                        *
*********************************************************/

#include <iostream.h> // cin e cout
#include <conio.h>    // getch() e clrscr()

void logo(); // função que insere o logo

int menu();

void main()
{
	int pos = -1;
   float ganhos = 0, gastos = 0;
   while (pos != 0)
   {
      pos = menu();
      if (pos == 0)
      {
      	cout << "\n\n\t\tTecle Enter para confirmar? ";
	      char conf;
   	   conf = getch();
      	if (conf != '\r') pos = -1;
      }
   }
}

int menu()
{
   clrscr();
   char opt[][22] = {"FIM\0",
   			"ENTRAR SALDO INICIAL\0",
            "ENTRAR COM GASTOS\0",
            "ENTRAR COM GANHOS\0",
            "MOSTRAR SALDO ATUAL\0",
            "MOSTRAR RESUMO\0"};


   logo();
	for (int i = 1; (i <= 5); i++)
   {

      cout << "\n\t"<< i << " - " << opt[i];
   }
   cout << "\n\t0 - " << opt[0];
   cout << "\n\n\tOPCAO: ";
   int r;
   r = (getche() - 48);	// os números de 1 a 5 equivalem a 48 a 53 na tabela ASCII
   if ((r < 0) || (r > 5))
   {
   	cout << "\n\n\tOPCAO INVALIDA!!!";
      getch();
   }
   return r;
}

void logo()
{

cout << "\n\t           _.-;;-._ ";
cout << "\n\t    '-..-'|   ||   |";
cout << "\n\t    '-..-'|_.-;;-._|";
cout << "\n\t    '-..-'|   ||   |";
cout << "\n\t    '-..-'|_.-''-._|\n";
cout << "\n\t          MEU BOLSO\n";

}

