#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

#define ITER 300

// Función inicialización aleatoria del vector
void inicializar_vector(float *vector, int tam)
{
    int i = 0;
    for (i = 0; i < tam; i++)
    {
        vector[i] = rand() % 1000;
    }
}
void Imprimir_Vector(float *vector, int tam)
{
    int i = 0;
    for (i = 0; i < tam; i++)
    {
        printf("%.2f ", vector[i]);
    }
    printf("\n");
}

int main(int argc,char** argv)
{
    srand(1);
    int N= atoi(argv[1]);
    int i = 0, k = 0;
    float *x, *y;
    struct timeval inicio, final;
    double tiempo;

    // Reserva memoria dinámica
    x = (float *)malloc(N * sizeof(float));
    y = (float *)malloc(N * sizeof(float));

    // Inicializar a valores aleatorios
    inicializar_vector(x, N);
    inicializar_vector(y, N);


    //Imprimir_Vector(x, N);

    // CÓDIGO A MEDIR
    gettimeofday(&inicio,NULL);
    for (k = 0; k < ITER; k++)
        for (i = 0; i < N; i++)
        {
            x[i] = sqrt((float)i);
            y[i] = (float)i + 2.0;
            x[i] += sqrt(y[i]);
        }
    gettimeofday(&final,NULL);
    tiempo = (final.tv_sec-inicio.tv_sec+(final.tv_usec-inicio.tv_usec)/1.e6);
    printf("%.20lf",tiempo/ITER);

    // ESTADO FINAL VECTORES
    //Imprimir_Vector(x, N);
    //Imprimir_Vector(y, N);
}