#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

#define ITER 1000

// Función inicialización aleatoria del vector
void inicializar_valor(float *v)
{
    *v=rand();
}

int main(int argc,char** argv)
{
    srand(21);
    int i = 0, j = 0;
    struct timeval inicio, final;
    double tiempo;
    int N= atoi(argv[1]);

    float a=0.0,b=0.0,c=0.0,d=0.0,e=0.0,v=0.0,x=0.0,y=0.0;

    // Inicializar a valores aleatorios
    inicializar_valor(&x);
    inicializar_valor(&y);
    inicializar_valor(&v);


    for(i=0; i<N; i++){ 
            x = (float)i+1.1;
            y = (float)j+x;
            b = 1.0/(x*y);
            a = y * b;
            c = x * b;
            d = v * b;
            e = 2.0*d; 
        }
    //CÓDIGO A MEDIR
    gettimeofday(&inicio,NULL);
    for (j = 0; j < ITER; j++)
    {
        for(i=0; i<N; i++){ 
            x = (float)i+1.1;
            y = (float)j+x;
            b = 1.0/(x*y);
            a = y * b;
            c = x * b;
            d = v * b;
            e = 2.0*d; 
        }
    }
    gettimeofday(&final,NULL);

    tiempo = (final.tv_sec-inicio.tv_sec+(final.tv_usec-inicio.tv_usec)/1.e6);
    printf("%.20lf",tiempo/ITER);


}