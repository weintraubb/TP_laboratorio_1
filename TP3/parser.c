#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	char idStr[50];
	char nombreStr[50];
	char horasStr[50];
	char sueldoStr[50];
	Employee* aux;


	fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr, horasStr, sueldoStr);

	do
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr, horasStr, sueldoStr);
		aux = employee_newParametros(idStr, nombreStr, horasStr, sueldoStr);
		if(aux!=NULL)
		{
			ll_add(pArrayListEmployee, aux);
		}
	}while(!feof(pFile));

    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int check=0;
	Employee* aux;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		while(!feof(pFile))
		{
			check=1;
			aux = employee_new();
			fread(aux, sizeof(Employee), 1, pFile);
			if(feof(pFile))
			{
				break;
			}

			check=ll_add(pArrayListEmployee,aux);
		}
	}
	return check;
}
