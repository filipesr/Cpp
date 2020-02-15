  // Verifica se o número digitado é um quadrado perfeito

  #include <iostream>	//para cin e cout
  #include <conio>		//para getch();

  void main()
  {
  	  cout << "\n\n   Digite um numero para ser testado: ";
     int i1 = 0 /* Número e resto do cálculo */ , i2 = 2/* Ímpares e base da função exponencial */;
     cin >> i1;
     if (i1 > 1) // Todo número digitado igual ou menor que 1 retorna 1.
     {
        i2 = 1;
        while (i1 > 0)
        {
           cout << "\n\ti1 = " << i1 << "  \ti2 = " << i2;
           i1 -= i2;
           i2 += 2;
        }
     }
     else i1 = 0;
     if (i1 == 0) // Resultado e mostragem de dados
     {
        i2 = (i2 -1)/2 ;
        i1 = i2 * i2 ;
     	  cout << "\n\n   " << i1 << " eh o quadrado perfeito de: " << i2;
     }
     else
     	  cout << "\n\n   Nao eh um quadrado perfeito.";

     cout << "\n\n";
     getch();
  }
