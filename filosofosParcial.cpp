/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <pthread.h>

//Definimos la función que crea a los Filósofos
void *filosofo (void *arg);

//definicion de la variable comida que va a ser global
int comida = 429496;

//definicion del array de los nombres de los científicos, en este caso son máximo 11
//pero se puede aumentar dependiendo al máximo que se requiera
char nombres[11][10];

//definicion del array que tendrá el estado de los tenedores
int tenedores[11];

//definicion del array que tendrá los estómagos de los científicos
int estomagos[11];

//definicion del contador de veces que se rellenará la comida
int contador = 0;

//se crea un flag
pthread_mutex_t flag;

int main(void)
{
    //recibimos el número de filósofos que se van a crear
    int a;
    scanf("%d", &a);
    
    //creamos el array de los nombres de los filósofos y en un for llenamos el array global
    //con los valores de este array
    char nombres1[11][10] = {{"A"}, {"B"}, {"C"}, {"D"}, {"E"}, {"F"}, {"G"}, {"H"}, {"I"}, {"J"}, {"K"}};
    
    for(int i = 0; i<a; i++){
        for(int j = 0; j<10; j++){
            nombres[i][j] = nombres1[i][j];
        }
    }
    
    //creamos un array de threads que representarán a los filósofos
    pthread_t filosofos[a];
    
    //creamos un array con identificadores para poder tener la referencia de los filósofos
    int identificadores[a];
    
    //llenamos el array de los tenedores con false ya que no se estan utilizando
    for(int i = 0; i<a; i++){
        tenedores[i] = false;
    }
    
    //llenamos el array de estómagos con 0 ya que así se inicializarán los filósofos
    for(int i = 0; i<a; i++){
        estomagos[i] = 0;
    }
    
    //se inicializa el flag
    pthread_mutex_init(&flag, NULL);
    
    //en este for llenamos los valores de los identificadores y vamos creando los filósofos
    for(int i = 0; i<a; i++){
        identificadores[i] = i + 1;
        pthread_create(&filosofos[i], NULL, &filosofo, identificadores[i]);
    }
    
    //dormimos los hilos para que no suceda el famoso death lock
    for(int i = 0; i<a; i++){
        pthread_join(filosofos[i], NULL);
    }
    
    //se finaliza el flag
    pthread_mutex_destroy(&flag);

    return 0;
}

//describimos lo que hará nuestra función que crea a los filósofos
//recibe normalmente el identificador de filósofo
void *filosofo (void *arg){
    int arg2 = *((int *)arg);
    //acá comienza el for infinito que reprecenta el ciclo de acción de los filósofos
    for(int i = 0; true; i++){
        //creamos un condicional en caso se acabe la comida
        if(comida = 0){
            printf("La comida se acabó. \n");
            comida = 429496;
            printf("Se acaba de restablecer la comida. \n");
            contador++;
        }
        //creamos el condicional que hace el filósofo para corroborar si los dos tenedores
        // a sus costados están sin usar, si lo están comen y sino piensan
        if(tenedores[(arg2 - 1)] == false and tenedores[arg2] == false and comida > 0 and estomagos[arg2] < 50){
            pthread_mutex_lock(&flag);
            tenedores[(arg2 - 1)] = true;
            tenedores[arg2] = true;
            printf("Filósofo %s está comiendo \n", nombres[arg2]);
            comida--;
            estomagos[arg2]++;
            tenedores[(arg2 - 1)] = false;
            tenedores[arg2] = false;
            pthread_mutex_unlock(&flag);
        }
        else{
            estomagos[arg2]--;
            printf("Filósofo %s está pensando \n", nombres[arg2]);
        }
    }
    return NULL;
}

