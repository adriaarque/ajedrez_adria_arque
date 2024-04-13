#include "FuncionesAjedrez.h"
#include <iostream>

using namespace std;

void imprimir_matriz(char tablero[LADO][LADO])
{
	cout << "  1 2 3 4 5 6 7 8" << endl;

	for (int i = 0; i < LADO; i++)
	{
		cout << LADO - i << ' ';
		for (int j = 0; j < LADO; j++)
		{
			cout << tablero[i][j] << ' ';
		}
		cout << endl;
	}
}

void elige_pieza(char tablero[LADO][LADO], bool turnoBlancas, Posicion* posPiezaElegida)
{
	bool posicionValida = false;
	do {

		int inputFila;
		int inputColumna;
		do
		{
			system("cls");
			imprimir_matriz(tablero);
			cout << endl << endl;
			cout << "Elige una pieza (introduce su posicion)" << endl;
			cout << " Introduce la fila: ";
			cin >> inputFila;
		} while ((inputFila < 0 || inputFila > 8));
		cout << endl;
		do
		{
			system("cls");
			imprimir_matriz(tablero);
			cout << endl << endl;
			cout << "Elige una pieza (introduce su posicion)" << endl;
			cout << " Introduce la fila: " << inputFila;
			cout << endl;
			cout << " Introduce la columna: ";
			cin >> inputColumna;
			cout << endl;
		} while (inputColumna < 0 || inputColumna > 8);

		if (turnoBlancas)
		{
			switch (tablero[LADO - inputFila][inputColumna])
			{
			case 'T':
			case 'H':
			case 'B':
			case 'Q':
			case 'K':
			case 'P':
				(*posPiezaElegida).fila = LADO - inputFila;
				(*posPiezaElegida).columna = inputColumna;
				posicionValida = true;
				break;

			default: break;
			}

			/*if (tablero[inputFila][inputColumna] == 'T')
			if (tablero[inputFila][inputColumna] == 'H')
			if (tablero[inputFila][inputColumna] == 'Q')*/
		}
		else
		{
			switch (tablero[LADO - inputFila][inputColumna])
			{
			case 't':
			case 'h':
			case 'b':
			case 'q':
			case 'k':
			case 'p':
				(*posPiezaElegida).fila = LADO - inputFila;
				(*posPiezaElegida).columna = inputColumna;
				posicionValida = true;
				break;

			default: break;
			}
		}

	} while (!posicionValida);

}
