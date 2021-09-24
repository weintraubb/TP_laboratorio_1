/*
 ============================================================================
 Name        : TP_1.c
 Author      : Lara Weintraub
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "funciones.h"

int main()
{
	setbuf(stdout, NULL);
    int primerNumero;
    int segundoNumero;
    int flagIngreso1=0;
    int flagIngreso2=0;
    int flagOperaciones=0;
    int suma;
    int resta;
    float division;
    int multiplicacion;
    int factorial1;
    int factorial2;
    char seguir='s';

    do
    {

        switch(menu(primerNumero, segundoNumero, flagIngreso1, flagIngreso2))
        {
        case 1:
            printf("Ingrese 1er operando: ");
            scanf("%d", &primerNumero);
            flagIngreso1=1;
            break;
        case 2:
            if(flagIngreso1==0)
            {
                printf("Todavia no ingreso el primer numero.\n");
                break;
            }
            else
            {
                printf("Ingrese 2do operando: ");
                scanf("%d", &segundoNumero);
                flagIngreso2=1;
                break;
            }

        case 3:
            if(flagIngreso1==0 || flagIngreso2==0)
            {
                printf("Ingrese los dos operandos\n");
                break;
            }
            else
            {
                suma = sumar(primerNumero, segundoNumero);
                resta = restar(primerNumero, segundoNumero);
                if(segundoNumero!=0)
                {
                    division = dividir(primerNumero, segundoNumero);
                }
                multiplicacion = multiplicar(primerNumero, segundoNumero);
                if(primerNumero>-1)
                {
                    factorial1 = factorialRecursivo(primerNumero);
                }
                if(segundoNumero>-1)
                {
                    factorial2 = factorialRecursivo(segundoNumero);
                }
                flagOperaciones=1;
                break;
            }

        case 4:
            if(flagOperaciones==0)
            {
                printf("Primero debe calcular las operaciones.\n");
                break;
            }
            else
            {
                printf("La suma es %d\n", suma);
                printf("La resta es %d\n", resta);
                if(segundoNumero==0)
                {
                    printf("No se pudo realizar la division porque no se puede dividir por 0\n");
                }
                else
                {
                    printf("La division es %.2f\n", division);
                }

                printf("La multiplicacion es %d\n", multiplicacion);
                if(primerNumero<0)
                {
                    printf("No se pudo calcular el factorial del primer operando porque es menor a 0.\n");
                }
                else
                {
                    printf("El factorial de %d es %d\n", primerNumero, factorial1);
                }
                if(segundoNumero<0)
                {
                    printf("no se pudo calcular el factorial del segundo operando porque es menor a 0.\n");
                }
                else
                {
                    printf("El factorial de %d es %d\n", segundoNumero, factorial2);
                }
                flagIngreso1=0;
                flagIngreso2=0;
                flagOperaciones=0;
                break;
            }

        case 5:
            printf("quiere cancelar la salida? (s/n) \n");
            fflush(stdin);
            scanf("%c", &seguir);
            break;
        default:
        	printf("Opcion invalida. Ingrese de nuevo.\n");
        	break;
        }
        system("pause");


    }while(seguir=='s');
    return 0;
}
