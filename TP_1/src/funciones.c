/*
 * funciones.c
 *
 *  Created on: 23 sep. 2021
 *      Author: Lara
 */
#include "funciones.h"

int menu (int x, int y, int flag1, int flag2)
{
    int opcion;
    system("cls");
        printf("Menu de opciones\n\n");
        if(flag1&&!flag2)
        {
            printf("1. Ingresar 1er operando (A = %d)\n", x);
            printf("2. Ingresar 2do operando (B = y)\n");
        }
        else if(flag2)
        {
            printf("1. Ingresar 1er operando (A = %d)\n", x);
            printf("2. Ingresar 2do operando (B = %d)\n", y);
        }
        else
        {
            printf("1. Ingresar 1er operando (A = x)\n");
            printf("2. Ingresar 2do operando (B = y)\n");
        }
        printf("3. Calcular todas las operaciones\n");
        printf("4. Informar resultados\n");
        printf("5. Salir\n\n");
        printf("Ingrese opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);

    return opcion;
}
int sumar(int x, int y)
{
    int resultado;
    resultado = x + y;

    return resultado;
}
int restar (int x, int y)
{
    int resultado;
    resultado = x - y;

    return resultado;
}
float dividir (int x, int y)
{
    float resultado;
    resultado =(float) x / y;

    return resultado;
}
int multiplicar (int x, int y)
{
    int resultado;
    resultado = x * y;

    return resultado;
}
int factorialRecursivo(int x)
{
    int factorial;

    if(x==0 || x==1)
    {
        factorial=1;
    }
    else
    {
        factorial=x*factorialRecursivo(x-1);
    }

    return factorial;
}


