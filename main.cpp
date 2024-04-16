#include "FuncionesAjedrez.h"
#include <Windows.h>
#include <iostream>

#define FRAME_DURATION 100

using namespace std;

int main() {

	//inicializar tablero
	char tablero[LADO][LADO] = {
		't', 'h', 'b', 'q', 'k', 'b', 'h', 't',	//[0] -> 8
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
	bool enrocado[2] = { false, false }; //0-> blancas
	bool puedeEnrocar[2] = { true, true }; //0-> blancas

	while (!finDeJuego)
	{
			//pedir inputs		
		Posicion posicionPiezaElegida;
		//la funcion pide una posicion valida para el jugador del turno actual,
		// y almacena esa posicion en la variable piezaElegida 
		elige_pieza(tablero, turnoBlancas, &posicionPiezaElegida);
		
		Posicion destinoElegido;
		do
		{
			//la funcion pide una posicion destino valida para el jugador del turno actual,
			// y almacena esa posicion en la variable destinoElegido
			elige_movimiento(tablero, turnoBlancas, &destinoElegido);
			
			//gestionar_movimiento_valido() evalua si el movimiento esta permitido 
			// en funcion de la pieza que se encuentra en la posicion origen elegida
		} while (!gestionar_movimiento_valido(tablero, turnoBlancas, enrocado, puedeEnrocar, posicionPiezaElegida, destinoElegido));
			
			//actualizar inputs (cambios en la matriz)
			//Los movimientos especiales se aplican directamente en sus funciones correspondientes
		sustituir_casilla(tablero, posicionPiezaElegida, destinoElegido);
		
			//comprobar fin del juego
		finDeJuego = juego_acabado(tablero);

			//cambiar el turno
		turnoBlancas = !turnoBlancas;

			//mostrar tablero
		imprimir_matriz(tablero);


		Sleep(FRAME_DURATION);
		system("cls");
	}

	//fin del juego
	imprimir_matriz(tablero);
	cout << endl;
	cout << "Fin del juego!\n";
	if (turnoBlancas)	
	{
		//el turno se invierte al final de la ronda, 
		//de modo que el ganador es el otro en esta comprobacion
		cout << "Ganan las piezas negras.\n";
	}
	else
		cout << "Ganan las piezas blancas.\n";

	cout << endl;
	system("pause");

	return 0;
}