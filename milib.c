#include<stdio.h>
#include"lalibreria.h"
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
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
void iniciartablero(int m[NF][NC]){

for(int i = 0; i < NF; i++){
       for (int j = 0; j < NC; j++){
           m[i][j]= 0;
}
}
}

/* Esta funcion va a detectar el fin del juego */

int gameover(int m[NF][NC], int cont2){

   int res = 0, cont1 = 0;

   for(int i = 0; i < NF; i++){
       for (int j = 0; j < NC; j++){
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
void posiciona(int m[NF][NC]){

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

void imprimetablero(int m[NF][NC]){

   for(int i = 0; i <= NF; i++){
       if(i == 0){
           printf("  ");
       } else{
           printf("%c ", 'A'+i-1);
       }
   }

   printf("\n");

   for(int i=0; i<NF; i++){
       printf("%d ", i);

       for (int j=0; j<NC; j++){

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
void turnoJugador(int m[NF][NC], int m2[NF][NC]){
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
           }while(columna >= NC || columna < 0);
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


/******************************Barcos y soldado*****************************************************/

void portaaviones(int m[NF][NC]){

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

       printf("Introduce una fila: ");
       fflush(stdin);
       scanf("%c", &fila);
       fflush(stdin);        
       filas = transformanumero(fila);
       
       }while(filas < 0 || filas > 10);
}while(!isdigit(fila));

      system("cls");

       printf("Elije 5 columnas para ubicarlo: \n");
       for(int i = 0; i < 5; i++){
       
do{
   do{
       printf("Introduce una columna %d: ", i+1);
       fflush(stdin);
       scanf("%c", &letra);
       fflush(stdin);
       letra  = toupper(letra);
           
       columna = transformaletra(letra);
           
       if(m[filas][columna] == 1){
           printf("\nYa has colocado el barco en la posicion [%d][%c]\n", filas, letra);
           i--;
}

   }while(isdigit(letra));
}while ((columna >= NC) || (columna < 0));


       m[filas][columna] = 1;
       }


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
}while ((columna >= NC) || (columna < 0));

       system("cls");

       printf("Elije 5 filas para ubicarlo: \n");
       for(int i = 0; i < 5; i++){
       
           do{
            do{
       printf("Introduce una fila %: ", i+1);
       fflush(stdin);
       scanf("%c", &fila);
       fflush(stdin);        
       filas = transformanumero(fila);
       }while(!isdigit(fila));
           
           if(m[filas][columna] == 1){
            printf("\nYa has colocado el barco en la posicion [%d][%c]\n", filas, letra);
            i--;
}

           }while((filas < 0 && filas > 10) || !isdigit(fila));

           m[filas][columna] = 1;
       }

       imprimetablero(m);
       getch();
       system("cls");

       break;
   }
}

void acorazado(int m[NF][NC]){

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

      system("cls");

       printf("Elije 4 columnas para ubicarlo: \n");
       for(int i = 0; i < 4; i++){
       
       do{
           printf("Introduce una columna: ");
           fflush(stdin);
           scanf("%c", &letra);
           fflush(stdin);
           letra  = toupper(letra);
           
           columna = transformaletra(letra);
           
           if(m[filas][columna] == 1){
            printf("\nYa has colocado el barco en la posicion [%d][%c]\n", filas, letra);
            i--;
}

       }while((isdigit(letra) || columna >= NC || columna < 0));


       m[filas][columna] = 1;
       }


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
}while ((columna >= NC) || (columna < 0));

       system("cls");

       printf("Elije 4 filas para ubicarlo: \n");
       for(int i = 0; i < 4; i++){
       
           do{
           
            do{
       printf("Introduce una fila %d: ", i+1);
       fflush(stdin);
       scanf("%c", &fila);
       fflush(stdin);        
       filas = transformanumero(fila);
       }while(!isdigit(fila));
           
           if(m[filas][columna] == 1){
            printf("\nYa has colocado el barco en la posicion [%d][%c]\n", filas, letra);
            i--;
}

           }while(filas < 0 && filas > 10);

           m[filas][columna] = 1;
       }

       imprimetablero(m);
       getch();
       system("cls");

       break;
   }

}

void submarino(int m[NF][NC]){

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

      system("cls");

       printf("Elije 3 columnas para ubicarlo: \n");
       for(int i = 0; i < 3; i++){
       
       do{
           printf("Introduce una columna: ");
           fflush(stdin);
           scanf("%c", &letra);
           fflush(stdin);
           letra  = toupper(letra);
           
           columna = transformaletra(letra);
           
           if(m[filas][columna] == 1){
            printf("\nYa has colocado el barco en la posicion [%d][%c]\n", filas, letra);
            i--;
}

       }while(isdigit(letra) || columna >= NC || columna < 0);


       m[filas][columna] = 1;
       }


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
}while ((columna >= NC) || (columna < 0));

       system("cls");

       printf("Elije 3 filas para ubicarlo: \n");
       
       for(int i = 0; i < 3; i++){

       
           do{
           
            do{
       printf("Introduce una fila %d: ", i+1);
       fflush(stdin);
       scanf("%c", &fila);
       fflush(stdin);        
       filas = transformanumero(fila);
       }while(!isdigit(fila));
           
           if(m[filas][columna] == 1){
            printf("\nYa has colocado el barco en la posicion [%d][%c]\n", filas, letra);
            i--;
}

           }while(filas < 0 && filas > 10);

           m[filas][columna] = 1;
       }

       imprimetablero(m);
       getch();
       system("cls");

       break;
   }
}

void crucero(int m[NF][NC]){

   char pos, letra, fila;
   int filas, columna;

printf("Como quieres colocar al crucero **\n");
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

      system("cls");

       printf("Elije 2 columnas para ubicarlo: \n");
       for(int i = 0; i < 2; i++){
       
       do{
           printf("Introduce una columna: ");
           fflush(stdin);
           scanf("%c", &letra);
           fflush(stdin);
           letra  = toupper(letra);
           
           columna = transformaletra(letra);
           
           if(m[filas][columna] == 1){
            printf("\nYa has colocado el barco en la posicion [%d][%c]\n", filas, letra);
            i--;
}

       }while(isdigit(letra) || columna >= NC || columna < 0);


       m[filas][columna] = 1;
       }


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
}while ((columna >= NC) || (columna < 0));

       system("cls");

       printf("Elije 2 filas para ubicarlo: \n");
       for(int i = 0; i < 2; i++){
       
           do{
           
            do{
       printf("Introduce una fila %d: ", i+1);
       fflush(stdin);
       scanf("%c", &fila);
       fflush(stdin);        
       filas = transformanumero(fila);
       }while(!isdigit(fila));
           
           if(m[filas][columna] == 1){
            printf("\nYa has colocado el barco en la posicion [%d][%c]\n", filas, letra);
            i--;
}

           }while(filas < 0 && filas > 10);

           m[filas][columna] = 1;
       }

       imprimetablero(m);
       getch();
       system("cls");

       break;
   }
}

void destructor(int m[NF][NC]){

   char pos, letra, fila;
   int filas, columna, flag;

do{
flag = 0;

printf("Como quieres colocar donde quieres colocar al destructor*\n");

       do{
        do{
       
           printf("En que columna lo quieres colocar: ");
           fflush(stdin);
           scanf("%c", &letra);
           fflush(stdin);
           letra = toupper(letra);
           
           columna = transformaletra(letra);
           
}while(isdigit(letra));
}while ((columna >= NC) || (columna < 0));

       do{
do{

       printf("En que fila lo quieres colocar: ");
       fflush(stdin);
       scanf("%c", &fila);
       fflush(stdin);        
       filas = transformanumero(fila);
       
       }while(filas < 0 || filas > 10);
}while(!isdigit(fila));

   if(m[filas][columna] == 1){
       printf("\nNo puedes colocar al soldado sobre un barco en la posicion [%d][%c]\n", filas, letra);
       flag = 1;
}

}while(flag != 0);


   m[filas][columna] = 1;

   imprimetablero(m);
   getch();
   system("cls");
}
