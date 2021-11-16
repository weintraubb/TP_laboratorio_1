#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "validaciones.h"
#define TAM 1000



void correccionCadena(char cadena[])
{
    int largo;
    largo = strlen(cadena);
    strlwr(cadena);
    for(int i=0; i<largo; i++)
    {
        if(i==0 || cadena[i-1]==' ')
        {
            cadena[i] = toupper(cadena[i]);
        }
    }
}

void ingresarCadena(char mensaje[], char cadena[])
{
    int flag = 0;
    int largo;

    do
    {
        printf("%s", mensaje);
        fflush(stdin);
        gets(cadena);
        largo = strlen(cadena);
        if(cadena==NULL || largo<2)
        {
            flag = 1;
        }
        else
        {
            for(int i=0; i<largo; i++)
            {
                if((cadena[i]!= ' ' )&& (cadena[i]<'a' || cadena[i]>'z') && (cadena[i] < 'A' || cadena[i]>'Z'))
                {
                    flag = 1;
                }
                else
                {
                    flag = 0;
                }
            }
        }
        if(flag)
        {
            printf("Dato invalido - ");
        }


    } while(flag);

    correccionCadena(cadena);
}

float validarFlotante(char mensaje[], char error[])
{
	char numeroSolicitado[TAM];
	int largo;
	int fallo;
	int flag;
	float resultado;

	do{
		flag=1;
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]",numeroSolicitado);

		largo = strlen(numeroSolicitado);

		for (int i=0;i<largo;i++)
        {
			if (isdigit(numeroSolicitado[i]) || (numeroSolicitado[i] == '.' && flag==1) || numeroSolicitado[0] == '-')
            {
                if(numeroSolicitado[i] == '.')
                {
					flag=0;
				}
				fallo=0;
            }
			else
			{
				fallo=1;
				printf("%s",error);
				break;
			}
		}
	} while(fallo==1);

	resultado = atof(numeroSolicitado);

	return resultado;
}

float ingresarFlotante(char mensaje[], int min, int max)
{
    float num;

    num = validarFlotante(mensaje, "Dato invalido - ");
    while(num < min || num > max)
    {
        printf("Entre %d y %d - ", min, max);
        num = validarFlotante(mensaje, "Dato invalido - ");
    }
    return num;
}

int validarEntero(char mensaje[], char error[])
{
    char pedido[TAM];
    int largo;
    int fallo;
    int resultado;

    do
    {
        printf("%s", mensaje);
        fflush(stdin);
        gets(pedido);

        largo = strlen(pedido);

        for(int i=0; i<largo; i++)
        {
            if(isdigit(pedido[i]) || pedido[0] == '-')
            {
                fallo = 0;
            }
            else
            {
                fallo = 1;
                printf("Dato invalido - ");
            }
        }
    }while(fallo==1);

    resultado = atoi(pedido);

    return resultado;
}

int ingresarEntero(char mensaje[], int min, int max)
{
    int numero;

    numero = validarEntero(mensaje, "Dato invalido - ");

    while(numero<min || numero>max)
    {
        printf("Entre %d y %d - ", min, max);

        numero = validarEntero(mensaje, "Dato invalido - ");
    }
    return numero;
}
