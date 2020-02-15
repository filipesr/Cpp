// Arquivo header
// Funções de matrizes

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

