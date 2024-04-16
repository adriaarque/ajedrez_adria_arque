#pragma once

#define LADO 8


struct Posicion
{
	int fila;
	int columna;		
};


void imprimir_matriz(char tablero[LADO][LADO]);

void elige_pieza(char tablero[LADO][LADO], bool turnoBlancas, Posicion* posPiezaElegida);

bool gestionar_movimiento_valido(char tablero[LADO][LADO], bool turnoBlancas, bool enroques[], bool puedeEnrocar[], Posicion posOrigen, Posicion& posDestino);

void gestionar_enroque(char tablero[LADO][LADO], bool turnoBlancas, Posicion posDestinoRey, Posicion posDestinoTorre);
void gestionar_promotion(char tablero[LADO][LADO], bool turnoBlancas, Posicion posDestino);

bool movimiento_peon(char tablero[LADO][LADO], bool turnoBlancas, Posicion posOrigen, Posicion posDestino);
bool movimiento_torre(char tablero[LADO][LADO], bool turnoBlancas, Posicion posOrigen, Posicion posDestino);
bool movimiento_caballo(char tablero[LADO][LADO], bool turnoBlancas, Posicion posOrigen, Posicion posDestino);
bool movimiento_alfil(char tablero[LADO][LADO], bool turnoBlancas, Posicion posOrigen, Posicion posDestino);
bool movimiento_rey(char tablero[LADO][LADO], bool turnoBlancas, Posicion posOrigen, Posicion& posDestino, bool enrocado[], bool puedeEnrocar[]);
bool movimiento_reina(char tablero[LADO][LADO], bool turnoBlancas, Posicion posOrigen, Posicion posDestino);

void elige_movimiento(char tablero[LADO][LADO], bool turnoBlancas, Posicion* posDestinoElegida);

void sustituir_casilla(char tablero[LADO][LADO], Posicion posOrigen, Posicion posDestino);

bool juego_acabado(char tablero[LADO][LADO]);