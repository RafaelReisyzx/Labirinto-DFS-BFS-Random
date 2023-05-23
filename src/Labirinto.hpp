#ifndef LABIRINTO_H
#define LABIRINTO_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <locale.h>
#include <unistd.h>
#include <ctype.h>
#include <math.h>

typedef struct Matriz{
char map[100][100];
int passos;	
int tam;
	} Matriz;
	
	typedef struct Mapa{
  Matriz Matrizes;
	} Mapa;
			
int Initiation(Mapa *mat);
int GenerateMatrix(Mapa *mat);
void PrintMatrix(Mapa *mat);
void AtualizarMatriz(Mapa *mat);
int ReadMatriz(Mapa *mat);
int Random(Mapa *mat);
 
#endif
