// Comentário
#include <iostream>	// biblioteca para usar cin e cout - não precisa de .h
#include <conio>		// biblioteca para usar getch e getche

void main()	// função principal do programa - não retorna nada
{ 				// início da função

	cout << "Saída de texto:";	// observar o <<
   char str[6] = "Filipe";    // definindo tipo e inicializando a variável str
   cout << ":\n\n" << str;		// imprimindo o valor de str
   cout << "\n\ndigite o número de letras desse nome: ";
   int n;
   cin >> n;						// pede ao usuário que digite um número
   if (n == 6)						// compara o número digitado
   {                          // executa se a comparação for verdadeira
   	cout << "\n Acertou!!";
   }
   else								// executa se a comparação for falsa
   {
   	cout << "\n Como você é burro!! rs...";
   }
   str[5] = 'i';	 				// redefine a variável str
   while ((str[0] != 'F') || (str[1] != 'i') || (str[2] != 'l')
   	 || (str[3] != 'i') || (str[4] != 'p') || (str[5] != 'e'))// verifica a comparação
   {									// executa enquanto a comparação for verdadeira

   	cout << "\n\nFilipe - Reescreva o nome: ";
      for (int i=0;i<6;i++)	// executa um laço
      {
      	str[i] = getch();	// guarda a tecla digitada
         cout << str[i];
      }
   }
   cout << "\n\nParabens!!";
   getch();							// aguarda uma tecla sem mostrala.

}				// fim da função
