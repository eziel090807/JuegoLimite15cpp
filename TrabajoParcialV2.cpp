#include "pch.h"
#include "iostream"
#include "conio.h"
#include "cstdlib"
#include "ctime"

using namespace std;
using namespace System;

int main()
{
	srand((unsigned)time(NULL));
	int puntos[3] = { 0, 0, 0 };

	system("cls");
	cout << "*******************************************\n";
	cout << "*                                         *\n";
	cout << "*          JUEGO DEL DADO  (10 - 15)      *\n";
	cout << "*                                         *\n";
	cout << "*******************************************\n\n";

	cout << "               +---------+\n";
	cout << "               | o     o |\n";
	cout << "               |    o    |\n";
	cout << "               | o     o |\n";
	cout << "               +---------+\n\n";

	/*cout << "  TABLA ASCII DEL DADO\n";
	cout << "  +--------+----------+-----------------+\n";
	cout << "  | Codigo | Caracter | Se usa para     |\n";
	cout << "  +--------+----------+-----------------+\n";
	cout << "  |   32   | espacio  | vacio del dado  |\n";
	cout << "  |   43   |    +     | esquinas        |\n";
	cout << "  |   45   |    -     | arriba y abajo  |\n";
	cout << "  |  111   |    o     | puntos          |\n";
	cout << "  |  124   |    |     | lados           |\n";
	cout << "  +--------+----------+-----------------+\n\n";*/

	cout << "Presiona cualquier tecla para continuar...\n";
	_getch();

	system("cls");
	cout << "  REGLAS:\n\n";
	cout << "  - Juegan 3 jugadores, uno despues del otro.\n";
	cout << "  - Presiona 's' para lanzar el dado.\n";
	cout << "  - Presiona 'n' para plantarte.\n";
	cout << "  - Si sumas de 10 a 15 puntos, GANAS.\n";
	cout << "  - Si sumas menos de 10 o mas de 15, PIERDES.\n\n";
	cout << "  Presiona cualquier tecla para comenzar...\n";
	_getch();

	for (int jugador = 1; jugador <= 3; jugador++)
	{
		char tecla = ' ';
		int puntosJugador = 0;

		system("cls");
		cout << "=== Turno del jugador " << jugador << "===\n";
		cout << "Presiona s para tirar el dado o n para plantarte\n";
		cout << "gana de 10 a 15 puntos, menos de 10 o mas de 15 pierdes\n";

		do
		{
			tecla = _getch();

			if (tecla == 's')
			{
				int cara = rand() % 6 + 1;
				puntosJugador += cara;

				system("cls");

				switch (cara)
				{
				case 1:
					cout << "+---------+\n"
						"|         |\n"
						"|    o    |\n"
						"|         |\n"
						"+---------+\n";
					break;
				case 2:
					cout << "+---------+\n"
						"| o       |\n"
						"|         |\n"
						"|       o |\n"
						"+---------+\n";
					break;
				case 3:
					cout << "+---------+\n"
						"| o       |\n"
						"|    o    |\n"
						"|       o |\n"
						"+---------+\n";
					break;
				case 4:
					cout << "+---------+\n"
						"| o     o |\n"
						"|         |\n"
						"| o     o |\n"
						"+---------+\n";
					break;
				case 5:
					cout << "+---------+\n"
						"| o     o |\n"
						"|    o    |\n"
						"| o     o |\n"
						"+---------+\n";
					break;
				case 6:
					cout << "+---------+\n"
						"| o     o |\n"
						"| o     o |\n"
						"| o     o |\n"
						"+---------+\n";
					break;
				}

				cout << "\nSalio: " << cara << "\n";
				cout << "puntos acumulados: " << puntosJugador << "\n";

				if (puntosJugador < 15)
					cout << "\nPresiona s para lanzar de nuevo el dado o n para plantarte\n";
			}
			else if (tecla != 'n')
			{
				cout << "\nTecla invalida. Usa 's' para lanzar o 'n' para plantarte.\n";
			}

		} while (tecla != 'n' && puntosJugador < 15);

		puntos[jugador - 1] = puntosJugador;

		cout << "\nFin del turno del jugador " << jugador
			<< " con " << puntosJugador << " puntos.\n";
		cout << "Presiona una tecla para continuar...\n";
		_getch();
	}

	system("cls");
	cout << "=== RESULTADOS ===\n\n";

	for (int i = 0; i < 3; i++)
	{
		cout << "Jugador " << (i + 1) << ": " << puntos[i] << " puntos - ";
		if (puntos[i] > 15)
			cout << "PERDIO (se paso de 15)\n";
		else if (puntos[i] >= 10)
			cout << "GANO\n";
		else
			cout << "PERDIO (menos de 10)\n";
	}

	cout << "\nPresiona cualquier tecla para salir y mostrar los creditos...\n";
	_getch();
	system("cls");
	cout << "\n=== CREDITOS ===\n";
	cout << "Desarrollado por: Rodrigo Luciano Vivanco Diaz\n";
	cout << "Omar Eziel Siguas Rios\n";
	cout << "Alejandro Martin Pilco Sanchez\n";

	return 0;
}