#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Employee.h"
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include "validaciones.h"


Employee* employee_new(){
	Employee* unEmpleado;

	unEmpleado = (Employee*)malloc(sizeof(Employee));

	return unEmpleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* unEmpleado;
	unEmpleado = employee_new();

	if(unEmpleado!=NULL)
	{
		employee_setId(unEmpleado, atoi(idStr));
		employee_setNombre(unEmpleado, nombreStr);
		employee_setHorasTrabajadas(unEmpleado, atoi(horasTrabajadasStr));
		employee_setSueldo(unEmpleado, atoi(sueldoStr));
	}
	return unEmpleado;
}


void employee_delete(Employee*this){
	free(this);
}


void employee_mostrar(Employee* this){

	if(this!=NULL){
		printf("| %5d | %20s | %5d | %10d |\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
	}
}

int employee_setId(Employee* this,int id){
	int check=0;
	if(this!=NULL){
		check=1;
		this->id=id;
	}
	return check;
}

int employee_setNombre(Employee* this,char* nombre){
	int check=0;

	if(this!=NULL){
		check=1;
		strcpy(this->nombre,nombre);
	}

	return check;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
	int check=0;

	if(this!=NULL){
		check=1;
		this->horasTrabajadas=horasTrabajadas;
	}

	return check;
}

int employee_setSueldo(Employee* this,int sueldo){
	int check=0;

	if(this!=NULL){
		check=1;
		this->sueldo=sueldo;
	}

	return check;
}
int sortEmployeeByName(void *empleado1, void *empleado2) {
	int check;
	Employee *emp1;
	Employee *emp2;

	if (empleado1 != NULL && empleado2 != NULL) {
		emp1 = (Employee*) empleado1;
		emp2 = (Employee*) empleado2;

		check = strcmp(emp1->nombre, emp2->nombre);
	}

	return check;
}

int sortEmployeeByHours(void *empleado1, void *empleado2) {
	int check;
	Employee *emp1;
	Employee *emp2;

	if (empleado1 != NULL && empleado2 != NULL) {
		check = 0;
		emp1 = (Employee*) empleado1;
		emp2 = (Employee*) empleado2;

		if (emp1->horasTrabajadas < emp2->horasTrabajadas) {
			check = -1;
		} else if (emp1->horasTrabajadas
				> emp2->horasTrabajadas) {
			check = 1;
		}
	}

	return check;
}

int sortEmployeeBySalary(void *empleado1, void *empleado2) {
	int check;
	Employee *emp1;
	Employee *emp2;

	if (empleado1 != NULL && empleado2 != NULL) {
		check = 0;
		emp1 = (Employee*) empleado1;
		emp2 = (Employee*) empleado2;

		if (emp1->sueldo < emp2->sueldo) {
			check = -1;
		} else if (emp1->sueldo > emp2->sueldo) {
			check = 1;
		}
	}

	return check;
}
int sortEmployeeById(void *empleado1, void *empleado2) {
	int check;
	Employee *emp1;
	Employee *emp2;

	if (empleado1 != NULL && empleado2 != NULL) {
		check = 0;
		emp1 = (Employee*) empleado1;
		emp2 = (Employee*) empleado2;

		if (emp1->id < emp2->id) {
			check = -1;
		} else if (emp1->id > emp2->id) {
			check = 1;
		}
	}

	return check;
}
