#include "miLib.c"
/* Función que inicia el tablero con el simbolo desedo */
void IniciarTablero(char Tablero[10][10],char simbolo)
{
	int i,j;

	for(i=0;i<10;i++)
	{
		for (j=0;j<10;j++)
			Tablero[i][j]=simbolo;
	}
}

/* Función que genera el tablero del oponente aleatoriamente */
void IniciarTableroJ2()
{
	Casilla aleatoria;
	char pos,posicion[2]={'v','h'};
	int i;

	IniciarTablero(TableroJ2,AGUA); // Primero se rellena el tablero con el símoblo de agua (^).
	srand(time(NULL));
	for (i=0;i<5;i++)
	{
		do
		{
			aleatoria.letra=(rand()%10)+65; // Casilla
			aleatoria.numero=(rand()%10)+1; // aleatoria.
			pos=posicion[rand()%2]; // Posición aleatoria.
		}while(!VerificarCasilla(TableroJ2,aleatoria,Barcos[i],pos)); // Verificar si la casilla es válida.
		Almacenar(TableroJ2,Barcos[i],aleatoria,pos); // Se almacena el barco en el tablero.
	}
}
