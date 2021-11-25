/*
 * afiliado.h
 *
 *  Created on: 24 nov. 2021
 *      Author: Lara
 */

#ifndef AFILIADO_H_INCLUDED
#define AFILIADO_H_INCLUDED
#include "../inc/LinkedList.h"

typedef struct{
    int id;
    char nombre[20];
    int antiguedad;
    char plan;
}eAfiliado;


/** \brief Muestra el listado de afiliados de la LinkedList
 *
 * \param this LinkedList* lista de afiliados
 * \return void
 *
 */
void mostrarAfiliados(LinkedList * this);


/** \brief Muestra un afiliado
 *
 * \param afiliado eAfiliado* afiliado a mostrar
 * \return void
 *
 */
void mostrarAfiliado(eAfiliado * afiliado);


/** \brief Compara Id de 2 afiliados
 *
 * \param a void* Puntero a afiliado A
 * \param b void* Puntero a afiliado B
 * \return int Devuelve 1 si el afiliado A es menor al afiliado B.
 *
 */
int compararId(void* a, void* b);

#endif // AFILIADO_H_INCLUDED
