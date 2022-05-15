/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <pthread.h>

#define const 5
void *filosofo (void *arg);

int comida = 429496;

char nombres[11][10];

int tenedores[11];

int estomagos[11];

int contador = 0;

pthread_mutex_t flag;

int main(void)
{
    int a;
    scanf("%d", &a);
    char nombres1[11][10] = {{"A"}, {"B"}, {"C"}, {"D"}, {"E"}, {"F"}, {"G"}, {"H"}, {"I"}, {"J"}, {"K"}};
    
    for(int i = 0; i<a; i++){
        for(int j = 0; j<10; j++){
            nombres[i][j] = nombres1[i][j];
        }
    }
    
    pthread_t filosofos[a];
    
    int identificadores[a];
    
    for(int i = 0; i<a; i++){
        tenedores[i] = false;
    }
    
    for(int i = 0; i<a; i++){
        estomagos[i] = 0;
    }
    
    pthread_mutex_init(&flag, NULL);
    
    for(int i = 0; i<a; i++){
        identificadores[i] = i + 1;
        pthread_create(&filosofos[i], NULL, &filosofo, identificadores[i]);
    }
    
    for(int i = 0; i<a; i++){
        pthread_join(filosofos[i], NULL);
    }
    
    pthread_mutex_destroy(&flag);

    return 0;
}

void *filosofo (void *arg){
    int arg2 = *((int *)arg);
    for(int i = 0; true; i++){
        if(comida = 0){
            printf("La comida se acabó. \n");
            comida = 429496;
            printf("Se acaba de restablecer la comida. \n");
            contador++;
        }
        if(tenedores[(arg2 - 1)] == false and tenedores[arg2] == false and comida > 0 and estomagos[arg2]) < 50){
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

