/*
 * afiliado.c
 *
 *  Created on: 24 nov. 2021
 *      Author: Lara
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "afiliado.h"


void mostrarAfiliados(LinkedList * this)
{
    printf("    NOMINA DE AFILIADOS\n");
    for(int i=0;i<ll_len(this);i++)
    {
        mostrarAfiliado((eAfiliado*) ll_get(this, i));
    }
    printf("\n");
}

void mostrarAfiliado(eAfiliado * afiliado)
{
    printf("%4d | %10s | %c | %2d\n", afiliado->id, afiliado->nombre, toupper(afiliado->plan), afiliado->antiguedad);
}

int compararId(void* a, void* b)
{
    int retorno = 0;
    eAfiliado * a1 = NULL;
    eAfiliado * a2 = NULL;

    if( a != NULL && b != NULL){
         a1 = (eAfiliado*) a;
         a2 = (eAfiliado*) b;

        if(a1->id > a2 -> id){
            retorno = 1;
        }else if(a1-> id < a2 -> id){
            retorno = -1;
        }
    }
    return retorno;
}
