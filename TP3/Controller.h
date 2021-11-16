/*
 * Controller.h
 *
 *  Created on: 15 nov. 2021
 *      Author: Lara
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "LinkedList.h"


int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
int controller_loadID(char* path);
int controller_setIDUpdate(char* path, int idEmpleado);
#endif /* CONTROLLER_H_ */


