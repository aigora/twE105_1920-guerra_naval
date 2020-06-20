#include<stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

int i,j;

int transformanumero(char num);
int transformaletra(char letra);
void iniciartablero(int m[10][10]);
int gameover(int m[10][10], int cont);
void posiciona(int m[10][10]);
void imprimetablero(int m[10][10]);
void turnoJugador(int m[10][10], int m2[10][10]);

void portaaviones(int m[10][10]);
void acorazado(int m[10][10]);
void submarino(int m[10][10]);
void crucero(int m[10][10]);
void destructor(int m[10][10]);


/* Esta funcion va a transformar letras a numeros */
int transformaletra(char letra)
{
   int coordenada;

   if(letra >= 'A' || letra < 'Z'){
       coordenada = letra - 65;// porque en el codigo ascii esa nueva posicion es un numero
   }

   return(coordenada);
}

int transformanumero(char num)
{
   int coordenada;

   if(num >= '0' || num < '9'){
       coordenada = num - 48;
   }

   return(coordenada);
}

/* Esta funcion va iniciar el tablero desde la posicion 0 */
void iniciartablero(int m[10][10]){

for(i = 0; i < 10; i++){
       for (j = 0; j < 10; j++){
           m[i][j]= 0;
}
}
}

/* Esta funcion va a detectar el fin del juego */

int gameover(int m[10][10], int cont2){

   int res = 0, cont1 = 0;

   for(i = 0; i < 10; i++){
       for (j = 0; j < 10; j++){
       if(m[i][j] == 2){
           cont1 += 1;
       }
       
       if(m[i][j] == 2 || m[i][j] == 1){
        cont2++;
}
   }
}

if(cont1 == cont2){
       res = 1;
}

return (res);
}
/* Esta funcion va a realizar la colocacion de cada barco en las posiciones pedidas */
void posiciona(int m[10][10]){

   int fila, columna2;
   char columna;

   imprimetablero(m);
   portaaviones(m);
   acorazado(m);
   submarino(m);
   crucero(m);
   destructor(m);


   system("cls");
}

/*Esta funcion va a mostrar el tablero de ambos jugadores */

void imprimetablero(int m[10][10]){

   for(i = 0; i <= 10; i++){
       if(i == 0){
           printf("  ");
       } else{
           printf("%c ", 'A'+i-1);
       }
   }

   printf("\n");

   for(i=0; i<10; i++){
       printf("%d ", i);

       for (j=0; j<10; j++){

           if(m[i][j] == 1){
               printf("# ");
           }else if(m[i][j] == 2){
            printf("X ");
}else{
               printf("~ ");
           }
       }
       printf("\n");
   }
}

/*Esta funcion va a hundir la flota del oponete a través de turnos */
void turnoJugador(int m[10][10], int m2[10][10]){
   char letra, fila;
   int filas, columna;

       do{
do{

       printf("Introduce una fila: ");
       fflush(stdin);
       scanf("%c", &fila);
       fflush(stdin);        
       filas = transformanumero(fila);
       
       }while(filas < 0 || filas > 10);
}while(!isdigit(fila));

       do{
        do{
           printf("Introduce una columna: ");
           fflush(stdin);
           scanf("%c", &letra);
           fflush(stdin);
           letra  = toupper(letra);
           columna = transformaletra(letra);
           }while(columna >= 10 || columna < 0);
       }while(isdigit(letra));

       columna = transformaletra(letra);

   if(m[filas][columna] > 0 && m[fila][columna] != 2){
       printf("\nBarco Hundido\n");
       m[filas][columna] = 2;
       system("COLOR 4f");

       if(m2[filas][columna] != 1){
           m2[filas][columna] = 2;
       }
       printf("\nPulsa enter para acabar el turno");
       getch();
       system("COLOR 07");

   }else{

       system("COLOR 30");
       printf("\nAgua\n");
       printf("\nPulsa enter para acabar el turno");
       getch();
       system("COLOR 07");
   }
}

/*Todas estas funciones auxiliares dibujan los barcos que se usaran */


/******************************Barcos*****************************************************/

void portaaviones(int m[10][10]){

   char pos, letra, fila;
   int filas, columna;

printf("Como quieres colocar el portaaviones *****\n");
   do{
       printf("Horizonal (H), Vertical(V): ");
       scanf("%s", &pos);
   }while(toupper(pos) != 'H' && toupper(pos) != 'V' );

   switch(toupper(pos)){
   
   case 'H':
   
       do{
do{

       printf("Introduce una fila (numero): ");
       fflush(stdin);
       scanf("%c", &fila);
       fflush(stdin);        
       filas = transformanumero(fila);
       
       }while(filas < 0 || filas > 10);
}while(!isdigit(fila));

      system("cls");
      printf("Jugador 1, coloca tus barcos:\n");
      imprimetablero(m);

       printf("Elije la primera columna para ubicarlo (letra): \n");
       
       
do{
   do{
       scanf("%c", &letra);
       fflush(stdin);
       letra  = toupper(letra);
           
       columna = transformaletra(letra);
           
       if(m[filas][columna] == 1){
           printf("\nYa has colocado el barco en la posicion [%d][%c]\n", filas, letra);
           i--;
}

   }while(isdigit(letra));
}while ((columna >= 10) || (columna < 0));

	for(i = 0; i < 5; i++){
       m[filas][columna + i] = 1;
   	}

		system("cls");
		printf("Jugador 1, coloca tus barcos:\n");
       imprimetablero(m);
       getch();
       

       break;

   case 'V':

       do{
        do{
       
           printf("En que columna lo quieres colocar (letra): ");
           fflush(stdin);
           scanf("%c", &letra);
           fflush(stdin);
           letra = toupper(letra);
           
           columna = transformaletra(letra);
           
		}while(isdigit(letra));
	   }while ((columna >= 10) || (columna < 0));

       system("cls");
       printf("Jugador 1, coloca tus barcos:\n");
       imprimetablero(m);

       printf("Elije la primera fila para ubicarlo (numero): \n");
       
       
           do{
            do{
       			scanf("%c", &fila);
       			fflush(stdin);        
       			filas = transformanumero(fila);
       		}while(!isdigit(fila));
           
           	if(m[filas][columna] == 1){
            	printf("\nYa has colocado el barco en la posicion [%d][%c]\n", filas, letra);
            	i--;
				}	

           }while((filas < 0 && filas > 10) || !isdigit(fila));

		for(i = 0; i < 5; i++){
           m[filas+i][columna] = 1;
       	}
		system("cls");

	   printf("Jugador 1, coloca tus barcos:\n");
       imprimetablero(m);
       getch();
    

       break;
   }
   
}

void acorazado(int m[10][10]){

   char pos, letra, fila;
   int filas, columna;

printf("Como quieres colocar el acorazado ****\n");
   do{
       printf("Horizonal (H), Vertical(V): ");
       scanf("%s", &pos);
   }while(toupper(pos) != 'H' && toupper(pos) != 'V' );

   switch(toupper(pos)){
   
   case 'H':
   
       do{
do{

       printf("En que fila lo quieres colocar: ");
       fflush(stdin);
       scanf("%c", &fila);
       fflush(stdin);        
       filas = transformanumero(fila);
       
       }while(filas < 0 || filas > 10);
}while(!isdigit(fila));

      

       printf("Elije la primera columna para ubicarlo: \n");
       
       
       do{
           fflush(stdin);
           scanf("%c", &letra);
           fflush(stdin);
           letra  = toupper(letra);
           
           columna = transformaletra(letra);
           
          			if(m[filas][columna] == 1 || m[filas][columna+1]==1 || m[filas][columna+2]==1 || m[filas][columna+3]==1){
            printf("\nYa has colocado el barco en la posicion [%d][%c]\n", filas, letra);
			}
            

       }while(isdigit(letra) || (columna >= 10) || (columna < 0) || m[filas][columna]==1 || m[filas][columna+1]==1 || m[filas][columna+2]==1 || m[filas][columna+3]==1);



       
       for(i = 0; i < 4; i++){
		 m[filas][columna+i] = 1;
		 }
		system("cls");
		printf("Jugador 1, coloca tus barcos:\n");
       	imprimetablero(m);
       getch();
       system("cls");

       break;

   case 'V':

       do{
        do{
       
           printf("En que columna lo quieres colocar: ");
           fflush(stdin);
           scanf("%c", &letra);
           fflush(stdin);
           letra = toupper(letra);
           
           columna = transformaletra(letra);
           
}while(isdigit(letra));
}while ((columna >= 10) || (columna < 0));


       printf("Elije la primera fila para ubicarlo: \n");
    
       
           do{
           
            do{
       fflush(stdin);
       scanf("%c", &fila);
       fflush(stdin);        
       filas = transformanumero(fila);
       }while(!isdigit(fila));
           
          	if(m[filas][columna] == 1 || m[filas+1][columna]==1 || m[filas+2][columna]==1 || m[filas+3][columna]==1){
            printf("\nYa has colocado el barco en la posicion [%d][%c]\n", filas, letra);
        }
            

			
           }while((columna >= 10) || (columna < 0) || m[filas][columna]==1 || m[filas+1][columna]==1 || m[filas+2][columna]==1 || m[filas+3][columna]==1 );

       
       for(i = 0; i < 4; i++){
		 m[filas+i][columna] = 1;
		 }

       system("cls");
		printf("Jugador 1, coloca tus barcos:\n");
       	imprimetablero(m);
       getch();
    

       break;
   }

}

void submarino(int m[10][10]){

   char pos, letra, fila;
   int filas, columna;

printf("Como quieres colocar el submarino ***\n");
   do{
       printf("Horizonal (H), Vertical(V): ");
       scanf("%s", &pos);
   }while(toupper(pos) != 'H' && toupper(pos) != 'V' );

   switch(toupper(pos)){
   
   case 'H':
   
       do{
do{

       printf("En que fila lo quieres colocar: ");
       fflush(stdin);
       scanf("%c", &fila);
       fflush(stdin);        
       filas = transformanumero(fila);
       
       }while(filas < 0 || filas > 10);
}while(!isdigit(fila));

      

       printf("Elije la primera columna para ubicarlo: \n");
       
       
       do{
           fflush(stdin);
           scanf("%c", &letra);
           fflush(stdin);
           letra  = toupper(letra);
           
           columna = transformaletra(letra);
           
          			if(m[filas][columna] == 1 || m[filas][columna+1]==1 || m[filas][columna+2]==1){
            printf("\nYa has colocado el barco en la posicion [%d][%c]\n", filas, letra);
			}
            

       }while(isdigit(letra) || (columna >= 10) || (columna < 0) || m[filas][columna]==1 || m[filas][columna+1]==1 || m[filas][columna+2]==1);



       
       for(i = 0; i < 3; i++){
		 m[filas][columna+i] = 1;
		 }
		system("cls");
		printf("Jugador 1, coloca tus barcos:\n");
       	imprimetablero(m);
       getch();
    

       break;

   case 'V':

       do{
        do{
       
           printf("En que columna lo quieres colocar: ");
           fflush(stdin);
           scanf("%c", &letra);
           fflush(stdin);
           letra = toupper(letra);
           
           columna = transformaletra(letra);
           
}while(isdigit(letra));
}while ((columna >= 10) || (columna < 0));


       printf("Elije la primera fila para ubicarlo: \n");
    
       
           do{
           
            do{
       fflush(stdin);
       scanf("%c", &fila);
       fflush(stdin);        
       filas = transformanumero(fila);
       }while(!isdigit(fila));
           
          	if(m[filas][columna] == 1 || m[filas+1][columna]==1 || m[filas+2][columna]==1){
            printf("\nYa has colocado el barco en la posicion [%d][%c]\n", filas, letra);
        }
            

			
           }while((columna >= 10) || (columna < 0) || m[filas][columna]==1 || m[filas+1][columna]==1 || m[filas+2][columna]==1);

       
       for(i = 0; i < 3; i++){
		 m[filas+i][columna] = 1;
		 }

       system("cls");
		printf("Jugador 1, coloca tus barcos:\n");
       	imprimetablero(m);
       getch();
       

       break;
   }

}

void crucero(int m[10][10]){

   char pos, letra, fila;
   int filas, columna;

printf("Como quieres colocar el crucero ***\n");
   do{
       printf("Horizonal (H), Vertical(V): ");
       scanf("%s", &pos);
   }while(toupper(pos) != 'H' && toupper(pos) != 'V' );

   switch(toupper(pos)){
   
   case 'H':
   
       do{
do{

       printf("En que fila lo quieres colocar: ");
       fflush(stdin);
       scanf("%c", &fila);
       fflush(stdin);        
       filas = transformanumero(fila);
       
       }while(filas < 0 || filas > 10);
}while(!isdigit(fila));

      

       printf("Elije la primera columna para ubicarlo: \n");
       
       
       do{
           fflush(stdin);
           scanf("%c", &letra);
           fflush(stdin);
           letra  = toupper(letra);
           
           columna = transformaletra(letra);
           
          			if(m[filas][columna] == 1 || m[filas][columna+1]==1 || m[filas][columna+2]==1){
            printf("\nYa has colocado el barco en la posicion [%d][%c]\n", filas, letra);
			}
            

       }while(isdigit(letra) || (columna >= 10) || (columna < 0) || m[filas][columna]==1 || m[filas][columna+1]==1 || m[filas][columna+2]==1);



       
       for(i = 0; i < 3; i++){
		 m[filas][columna+i] = 1;
		 }
		system("cls");
		printf("Jugador 1, coloca tus barcos:\n");
       	imprimetablero(m);
       getch();
       

       break;

   case 'V':

       do{
        do{
       
           printf("En que columna lo quieres colocar: ");
           fflush(stdin);
           scanf("%c", &letra);
           fflush(stdin);
           letra = toupper(letra);
           
           columna = transformaletra(letra);
           
}while(isdigit(letra));
}while ((columna >= 10) || (columna < 0));


       printf("Elije la primera fila para ubicarlo: \n");
    
       
           do{
           
            do{
       fflush(stdin);
       scanf("%c", &fila);
       fflush(stdin);        
       filas = transformanumero(fila);
       }while(!isdigit(fila));
           
          	if(m[filas][columna] == 1 || m[filas+1][columna]==1 || m[filas+2][columna]==1){
            printf("\nYa has colocado el barco en la posicion [%d][%c]\n", filas, letra);
        }
            

			
           }while((columna >= 10) || (columna < 0) || m[filas][columna]==1 || m[filas+1][columna]==1 || m[filas+2][columna]==1);

       
       for(i = 0; i < 3; i++){
		 m[filas+i][columna] = 1;
		 }

       system("cls");
		printf("Jugador 1, coloca tus barcos:\n");
       	imprimetablero(m);
       getch();
       

       break;
   }

}

void destructor(int m[10][10]){

   char pos, letra, fila;
   int filas, columna;

printf("Como quieres colocar el destructor **\n");
   do{
       printf("Horizonal (H), Vertical(V): ");
       scanf("%s", &pos);
   }while(toupper(pos) != 'H' && toupper(pos) != 'V' );

   switch(toupper(pos)){
   
   case 'H':
   
       do{
do{

       printf("En que fila lo quieres colocar: ");
       fflush(stdin);
       scanf("%c", &fila);
       fflush(stdin);        
       filas = transformanumero(fila);
       
       }while(filas < 0 || filas > 10);
}while(!isdigit(fila));

      

       printf("Elije la primera columna para ubicarlo: \n");
       
       
       do{
           fflush(stdin);
           scanf("%c", &letra);
           fflush(stdin);
           letra  = toupper(letra);
           
           columna = transformaletra(letra);
           
          			if(m[filas][columna] == 1 || m[filas][columna+1]==1){
            printf("\nYa has colocado el barco en la posicion [%d][%c]\n", filas, letra);
			}
            

       }while(isdigit(letra) || (columna >= 10) || (columna < 0) || m[filas][columna]==1 || m[filas][columna+1]==1);



       
       for(i = 0; i < 2; i++){
		 m[filas][columna+i] = 1;
		 }
		system("cls");
		printf("Jugador 1, coloca tus barcos:\n");
       	imprimetablero(m);
       getch();
       

       break;

   case 'V':

       do{
        do{
       
           printf("En que columna lo quieres colocar: ");
           fflush(stdin);
           scanf("%c", &letra);
           fflush(stdin);
           letra = toupper(letra);
           
           columna = transformaletra(letra);
           
}while(isdigit(letra));
}while ((columna >= 10) || (columna < 0));


       printf("Elije la primera fila para ubicarlo: \n");
    
       
           do{
           
            do{
       fflush(stdin);
       scanf("%c", &fila);
       fflush(stdin);        
       filas = transformanumero(fila);
       }while(!isdigit(fila));
           
          	if(m[filas][columna] == 1 || m[filas+1][columna]==1){
            printf("\nYa has colocado el barco en la posicion [%d][%c]\n", filas, letra);
        }
            

			
           }while((columna >= 10) || (columna < 0) || m[filas][columna]==1 || m[filas+1][columna]==1);

       
       for(i = 0; i < 2; i++){
		 m[filas+i][columna] = 1;
		 }

       system("cls");
		printf("Jugador 1, coloca tus barcos:\n");
       	imprimetablero(m);
       getch();
       

       break;
   }

}
