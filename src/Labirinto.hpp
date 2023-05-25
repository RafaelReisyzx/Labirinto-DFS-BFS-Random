#ifndef LABIRINTO_HPP
#define LABIRINTO_HPP
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

typedef struct Matriz{
char map[100][100];
int passos;	
int tam;
} Matrix;
	
typedef struct Mapa{
Matrix Matriz;
} Mapa;
			
int Initiation(Mapa *mat);
int GenerateMatrix(Mapa *mat);
void PrintMatrix(Mapa *mat);
int ReadMatrix(Mapa *mat);
int Random(Mapa *mat);
void Finalization(Mapa *mat);
 
#endif
