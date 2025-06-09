#include <stdio.h>
#include <stdlib.h>
#define CONST 5
float sumaVec(float vec[]);
void cargar(int vec [CONST][CONST]);
void mostrar(int vec [CONST][CONST]);

float sumaVec(float vec[])
{
    float suma = 0;

    for (int i = 0; i < 4; i++)
    {
        suma += vec[i];
    }

    return suma;
}

void cargar(int vec [CONST][CONST])
{
    int i,j;
    for(i=0; i<CONST; i++)
    {
        for(j=0; j<CONST; j++)
        {
            vec[i][j]=13;
        }
    }
}

void mostrar (int vec [CONST][CONST])
{
    int i,j;
    for(i=0; i<CONST; i++)
    {
        for(j=0; j<CONST; j++)
        {
            printf("En la posicion [%d, %d] podemos encontrar el valor de: %d \n",i,j,vec[i][j]);
        }
    }
}
int main()
{
    int vec[5] = {1, 2, 3, 4, 5};
    float vec2[4] = { 1.2, 3.4, 5.6, 7.8};
    int mat[CONST][CONST];


    float resultado;

    printf("%d\n", vec[3]);
    printf("Apa, que esperabas? Acordate que contamos desde cero, crack\n");

    resultado = sumaVec(vec2);

    printf("Toma tu resultado, crack: %f \n", resultado);

    cargar(mat);
    mostrar(mat);

    return 0;
}