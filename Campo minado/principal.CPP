#include <iostream.h>

void criaminas(int d);
	// Cria a tabela de minas. d é a dificuldade: 1 < d < 99

void verminas(int x, int y);
	// Verifica quantas minas existem ao redor. x e y são a posição

void marcaminas(int x, int y)
	// Verifica se acertou a mina e mostra a tabela. x e y são a posição
