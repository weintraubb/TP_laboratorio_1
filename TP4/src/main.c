/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "afiliado.h"


int main(void)
{
     /*startTesting(1);  // ll_newLinkedList
     startTesting(2);  // ll_len
     startTesting(3);  // getNode - test_getNode
     startTesting(4);  // addNode - test_addNode
     startTesting(5);  // ll_add
     startTesting(6);  // ll_get
     startTesting(7);  // ll_set
     startTesting(8);  // ll_remove
     startTesting(9);  // ll_clear
     startTesting(10); // ll_deleteLinkedList
     startTesting(11); // ll_indexOf
     startTesting(12); // ll_isEmpty
     startTesting(13); // ll_push
     startTesting(14); // ll_pop
     startTesting(15); // ll_contains
     startTesting(16); // ll_containsAll
     startTesting(17); // ll_subList
     startTesting(18); // ll_clone
     startTesting(19); // ll_sort*/

	    int indice;
	    eAfiliado * aux = NULL;
	    LinkedList* nominaReducida = NULL;
	    LinkedList* nominaDuplicada = NULL;

	    //Uso ll_newLinkedList()
	    LinkedList* nomina = ll_newLinkedList();
	    printf("Se ha creado la nomina\n\n");

	    //Uso ll_isEmpty()
	    if(ll_isEmpty(nomina))
	    {
	        printf("La nomina se encuentra vacia\n");
	    }
	    else
	    {
	        printf("La nomina NO se encuentra vacia\n");
	    }
	    printf("\n");

	    eAfiliado afiliado1 = {123, "Matias", 15, 'A'};
	    eAfiliado afiliado2 = {124, "Luisa", 4, 'A'};
	    eAfiliado afiliado3 = {125, "Alejandra", 3, 'B'};
	    eAfiliado afiliado4 = {126, "Maria", 8, 'C'};
	    eAfiliado afiliado5 = {127, "Octavio", 10, 'A'};

	    //Uso ll_add()
	    ll_add(nomina,&afiliado1);
	    ll_add(nomina,&afiliado2);
	    ll_add(nomina,&afiliado3);
	    ll_add(nomina,&afiliado4);
	    ll_add(nomina,&afiliado5);

	    mostrarAfiliados(nomina);

	    //Uso ll_len()
	    printf("El total de afiliados es %d\n\n", ll_len(nomina));

	    eAfiliado afiliado6 = {128, "Belen", 2, 'C'};

	    ll_add(nomina,&afiliado6);

	    //Uso ll_get()
	    printf("Se ha agregado siguiente afiliado:\n");
	    mostrarAfiliado((eAfiliado*)ll_get(nomina,5));

	    //Uso ll_len()
	    printf("El total de afiliados es %d\n\n", ll_len(nomina));

	    mostrarAfiliados(nomina);
	    printf("\n");

	    //Uso ll_set()
	    eAfiliado afiliado7 = {127, "Sebastian", 5, 'D'};

	    if(!ll_set(nomina,4,&afiliado7))
	    {
	        printf("Se ha modificado el afiliado.\n\n");
	    }

	    mostrarAfiliados(nomina);

	    //Uso ll_remove()
	    if(!ll_remove(nomina,5))
	    {
	        printf("Se ha eliminado el afiliado.\n\n");
	    }

	    mostrarAfiliados(nomina);

	    //Uso ll_indexOf()
	    indice=ll_indexOf(nomina,&afiliado3);
	    if(indice!=-1)
	    {
	        printf("La afiliada %s se encuentra en el indice %d.\n\n", afiliado3.nombre, indice);
	    }

	    //Uso ll_isEmpty()
	    if(ll_isEmpty(nomina))
	    {
	        printf("La nomina se encuentra vacia\n\n");
	    }
	    else
	    {
	        printf("La nomina NO se encuentra vacia\n\n");
	    }

	    //Uso ll_push()
	    if(!ll_push(nomina,3,&afiliado6))
	    {
	        printf("Se ha agregado a %s en el indice %d\n\n", afiliado6.nombre, ll_indexOf(nomina,&afiliado6));
	    }

	    mostrarAfiliados(nomina);

	    //Uso ll_pop()
	    aux = (eAfiliado*)ll_pop(nomina,2);

	    if(aux != NULL)
	    {
	        printf("Se ha eliminado al afiliado %s de la lista\n\n", aux->nombre);
	    }

	    mostrarAfiliados(nomina);

	    //Uso ll_contains()
	    if(ll_contains(nomina,&afiliado2)){
	        printf("%s se encuentra en la nomina\n\n", afiliado2.nombre);
	    }
	    else
	    {
	        printf("%s NO se encuentra en la nomina\n\n", afiliado2.nombre);
	    }

	    //Uso ll_subList()
	    nominaReducida = ll_subList(nomina,2,4);

	    if(nominaReducida != NULL)
	    {
	        printf("Se ha creado la nomina reducida\n\n");
	        mostrarAfiliados(nominaReducida);

	    }
	    else
	    {
	        printf("Ha ocurrido un error al crear la nomina reducida\n\n");
	    }

	    //Uso ll_containsAll()
	    if(ll_containsAll(nomina, nominaReducida))
	    {
	        printf("La nomina reducida se encuentra en la nomina\n\n");
	    }

	    //Uso ll_clone()
	    nominaDuplicada = ll_clone(nomina);
	    if(nominaDuplicada != NULL)
	    {
	        printf("La nomina se ha duplicado con exito\n\n");
	    }

	    //Uso ll_clear()
	    if(!ll_clear(nominaDuplicada))
	    {
	        printf("Se han eliminado todos los afiliados de la nomina\n\n");
	    }

	    //Uso ll_deleteLinkedList()
	    if(!ll_deleteLinkedList(nominaDuplicada))
	    {
	        printf("La nomina duplicada se ha eliminado con exito\n\n");
	    }

	        mostrarAfiliados(nomina);

	    //Uso ll_sort()
	    if(!ll_sort(nomina,compararId,1))
	    {
	        printf("La nomina se ha ordenado con exito\n\n");
	        mostrarAfiliados(nomina);
	    }

	    if(!ll_deleteLinkedList(nominaReducida))
	    {
	        printf("La nomina reducida se ha eliminado con exito\n\n");
	    }

	    if(!ll_deleteLinkedList(nomina))
	    {
	        printf("La nomina de afiliados se ha eliminado con exito\n\n");
	    }

    return 0;
}

































