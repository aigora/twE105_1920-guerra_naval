#define NF 10
#define NC 10


int transformanumero(char num);
int transformaletra(char letra);
void iniciartablero(int m[NF][NC]);
int gameover(int m[NF][NC], int cont);
void posiciona(int m[NF][NC]);
void imprimetablero(int m[NF][NC]);
void turnoJugador(int m[NF][NC], int m2[NF][NC]);

void portaaviones(int m[NF][NC]);
void acorazado(int m[NF][NC]);
void submarino(int m[NF][NC]);
void crucero(int m[NF][NC]);
void destructor(int m[NF][NC]);

