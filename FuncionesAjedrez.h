#pragma once

#define LADO 8


struct Posicion
{
	int fila;
	int columna;
};


void imprimir_matriz(char tablero[LADO][LADO]);

void elige_pieza(char tablero[LADO][LADO], bool turnoBlancas, Posicion* posPiezaElegida);
