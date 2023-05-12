#ifndef LABIRINTO_H
#define LABIRINTO_H
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>
#include <math.h>

typedef struct Matriz{
char map[100][100];
char mapAux[100][100];	
	} Matriz;
	
	typedef struct Mapa{
  Matriz Matrizes;
	} Mapa;
			
int Initiation(Mapa *mat);
int GenerateMatrix(int n,Mapa *mat);
void PrintMatrix(int n,Mapa *mat);
void AtualizarMatriz(int n,Mapa *mat);
void ReadMatriz(Mapa *mat);
int Random(int n,Mapa *mat);
 
#endif
