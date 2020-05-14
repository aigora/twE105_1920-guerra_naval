#define AGUA '^'
#define TOCADO '*'
#define OCULTA 'O'
#define PORTAVIONES 5
#define ACORAZADO 4
#define SUBMARINO 3
#define CRUCERO 3
#define DESTRUCTOR 2
/* Funciones */
void IniciarTablero(char[10][10],char);
void IniciarTableroJ2();
void DibujarTablero(char[10][10]);
void PedirCasilla(int);
int VerificarCasilla(char[10][10],Casilla,int,char);
void Almacenar(char[10][10],int,Casilla,char);
void TurnoJ1();
void TurnoJ2();
char AtacarCasilla(char[10][10],Casilla);
void GenerarLista();
