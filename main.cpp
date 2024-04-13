#include "FuncionesAjedrez.h"
#include <iostream>
#include <Windows.h>

#define FRAME_DURATION 150

using namespace std;

void main() {

	//inicializar tablero
	char tablero[LADO][LADO] = {
		't', 'h', 'b', 'k', 'q', 'b', 'h', 't',	//[0] -> 8
		'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
		'*', '*', '*', '*', '*', '*', '*', '*',
		'*', '*', '*', '*', '*', '*', '*', '*',
		'*', '*', '*', '*', '*', '*', '*', '*',
		'*', '*', '*', '*', '*', '*', '*', '*',
		'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
		'T', 'H', 'B', 'Q', 'K', 'B', 'H', 'T'	//[7] -> 1
	};
	imprimir_matriz(tablero);


	bool finDeJuego = false;
	bool turnoBlancas = true;
	while (!finDeJuego)
	{
		Posicion piezaElegida;

		//pedir inputs
		if (turnoBlancas)
		{
			//la funcion pide una posicion valida para el jugador del turno actual,
			// y almacena esa posicion en la variable piezaElegida 
			elige_pieza(tablero, turnoBlancas, &piezaElegida);
		}
		else
		{

		}


		//actualizar inputs (cambios en la matriz)


		//mostrar tablero
		imprimir_matriz(tablero);

		Sleep(FRAME_DURATION);
		system("cls");

	}



}