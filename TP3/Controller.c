#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "validaciones.h"
#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayListEmployee) {
	FILE *f;
	if (path != NULL && pArrayListEmployee != NULL) {
		f = fopen(path, "r");
		if (f != NULL) {
			ll_clear(pArrayListEmployee);
			parser_EmployeeFromText(f, pArrayListEmployee);
		} else {
			printf("No se pudo abrir el archivo\n");
			return 0;
		}

		fclose(f);
	}

	return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee) {
	if (path != NULL && pArrayListEmployee != NULL) {
		FILE *f = fopen("path", "rb");
		if (f != NULL) {
			parser_EmployeeFromText(f, pArrayListEmployee);
		}
	}
	return 1;
}
int controller_findEmployee(LinkedList *pArrayListEmployee) {
	int i;
	int largo;
	int id;

	Employee *aux = employee_new();

	if (pArrayListEmployee != NULL) {
		largo = ll_len(pArrayListEmployee);

		id = ingresarEntero("Ingrese el ID del Empleado: ", 1, 10000000);

		for (i = 0; i < largo; i++) {
			aux = ll_get(pArrayListEmployee, i);

			if (id == aux->id) {
				break;
			}

		}

		if (i == largo) {
			i = -1;
		}
	}
	return i;
}
int controller_setIDUpdate(char *path, int idEmpleado) {
	int check = 0;
	char aux[100];

	FILE *pFile;
	if (path != NULL && idEmpleado != -1) {
		pFile = fopen(path, "w");

		sprintf(aux, "%d", idEmpleado);

		if (pFile != NULL) {
			fprintf(pFile, "%s", aux);
			//fwrite(&idEmpleado, sizeof(int), 1, pFile);
			check = 1;
			//printf("Creaste el archivo ID\n");
		}

		fclose(pFile);
	}
	return check;
}

int controller_loadID(char *path) {
	int id = -1;
	char aux[100];

	FILE *pFile;

	if (path != NULL) {
		pFile = fopen(path, "r");

		if (pFile != NULL) {
			fread(&aux, sizeof(aux), 1, pFile);

		}

		fclose(pFile);

		id = atoi(aux);
	}

	return id;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList *pArrayListEmployee) {
	int check = 0;
	Employee *aux;
	int idEmpleado;
	Employee Empleado;
	char idStr[50];
	char hsTrabajadasStr[50];
	char sueldoStr[50];

	if (pArrayListEmployee != NULL) {
		if (ll_len(pArrayListEmployee) == 0) {
			idEmpleado = 1;
			controller_setIDUpdate("id.csv", idEmpleado);
		} else {
			idEmpleado = controller_loadID("id.csv");
		}

		if (idEmpleado != -1) {
			check = 1;
			Empleado.id = idEmpleado;
			ingresarCadena("Ingrese nombre del empleado: ", Empleado.nombre);
			Empleado.horasTrabajadas = ingresarEntero(
					"Ingrese horas trabajadas por el empleado: ", 1, 10000000);
			Empleado.sueldo = ingresarEntero("Ingrese sueldo del empleado: ", 1,
					100000000);
			itoa(Empleado.id, idStr, 10);
			itoa(Empleado.horasTrabajadas, hsTrabajadasStr, 10);
			itoa(Empleado.sueldo, sueldoStr, 10);
			aux = employee_newParametros(idStr, Empleado.nombre,
					hsTrabajadasStr, sueldoStr);

			ll_add(pArrayListEmployee, aux);
		}
	}

	return check;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList *pArrayListEmployee) {
	int indice;
	int todoOk = 0;
	Employee *aux;
	int opcion;

	if (pArrayListEmployee != NULL) {
		indice = controller_findEmployee(pArrayListEmployee);

		if (indice != -1) {

			aux = (Employee*) ll_get(pArrayListEmployee, indice);
			do {
				employee_mostrar(aux);
				printf("===========================================\n");
				printf("              Modificar empleado           \n");
				printf("===========================================\n");
				printf("1. Modificar nombre.\n");
				printf("2. Modificar horas de trabajo.\n");
				printf("3. Modificar sueldo.\n");
				printf("4. Volver.\n");
				opcion = ingresarEntero("\n\tIngrese una opcion: ", 1, 4);
				switch (opcion) {
				case 1:
					ingresarCadena("Ingrese el nuevo nombre del empleado: ",
							aux->nombre);
					todoOk = 1;
					break;

				case 2:
					aux->horasTrabajadas =
							ingresarEntero(
									"Ingrese las nuevas horas trabajadas del empleado: ",
									1, 1000000);
					todoOk = 1;
					break;

				case 3:
					aux->sueldo = ingresarEntero(
							"Ingrese el nuevo salario del empleado: ", 1,
							100000000);
					todoOk = 1;
					break;
				}
			} while (opcion != 4);
			todoOk = 1;
			if (todoOk == 1) {

				ll_set(pArrayListEmployee, indice, aux);
			}

		}
	}
	return todoOk;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList *pArrayListEmployee) {
	int index;
	int check = 0;
	Employee *aux;

	if (pArrayListEmployee != NULL) {
		index = controller_findEmployee(pArrayListEmployee);
		if (index != -1) {
			check = 1;
			aux = (Employee*) ll_get(pArrayListEmployee, index);
			ll_remove(pArrayListEmployee, index);
			employee_delete(aux);
		}
	}
	return check;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList *pArrayListEmployee) {
	int check = 0;
	int largo;

	if (pArrayListEmployee != NULL) {
		largo = ll_len(pArrayListEmployee);
		printf("=====================================================\n");
		printf("|   ID  |        NOMBRE        | HORAS |   SUELDO   |\n");
		printf("=====================================================\n");
		for (int i = 0; i < largo; i++) {
			employee_mostrar(ll_get(pArrayListEmployee, i));
		}
		printf("=====================================================\n");
		check = 1;
	}
	return check;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList *pArrayListEmployee) {
	int opcion;
	int verificar = 0;
	int check;
	int orden;
	int retorno;

	if (pArrayListEmployee != NULL) {
		do {
			printf("===========================================\n");
			printf("              Ordenar empleados            \n");
			printf("===========================================\n");
			printf("1.Ordenar por ID\n");
			printf("2.Ordenar por nombre\n");
			printf("3.Ordenar por horas trabajadas\n");
			printf("4.Ordenar por salarios.\n");
			printf("5. Salir.\n");
			opcion = ingresarEntero("\nIngrese una opcion: ", 1, 5);
			if (opcion != 5) {
				printf("1. Ascendente.\n");
				printf("2. Descendente.\n");
				orden =
						ingresarEntero(
								"Desea ordenar de manera ascendente o descendente? : ",
								1, 2);
				if (orden != 1) {
					orden = 0;
				}
				printf("La lista esta siendo ordenada.\n");
				switch (opcion) {
				case 1:
					check = ll_sort(pArrayListEmployee, sortEmployeeById,
							orden);
					if (check) {
						verificar = 1;
					}
					retorno = 1;
					break;

				case 2:
					check = ll_sort(pArrayListEmployee,
							sortEmployeeByName, orden);
					if (check) {
						verificar = 2;
					}
					retorno = 2;
					break;

				case 3:
					check = ll_sort(pArrayListEmployee,
							sortEmployeeByHours, orden);
					if (check) {
						verificar = 3;
					}
					retorno = 3;
					break;
				case 4:
					check = ll_sort(pArrayListEmployee,
							sortEmployeeBySalary, orden);
					if (check) {
						verificar = 4;
					}
					retorno = 4;
					break;
				}
			}
		} while (verificar != 0);
	}
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayListEmployee) {
	int todoOk = 0;
	int largo;

	FILE *pFile;
	Employee *aux;

	if (path != NULL && pArrayListEmployee != NULL) {
		largo = ll_len(pArrayListEmployee);

		pFile = fopen(path, "w");

		if (pFile != NULL) {
			fprintf(pFile, "ID,Nombre,HorasTrabajadas,Salario\n");
			for (int i = 0; i < largo; i++) {
				aux = (Employee*) ll_get(pArrayListEmployee, i);
				if (aux != NULL) {
					fprintf(pFile, "%d,%s,%d,%d\n", aux->id, aux->nombre,
							aux->horasTrabajadas, aux->sueldo);
				}
			}
			todoOk = 1;
		}
		fclose(pFile);
	}
	return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee) {
	int todoOk = 0;
	int largo;

	FILE *pFile;
	Employee *aux;

	if (path != NULL && pArrayListEmployee != NULL) {
		largo = ll_len(pArrayListEmployee);

		pFile = fopen(path, "wb");

		if (pFile != NULL) {

			for (int i = 0; i < largo; i++) {
				aux = (Employee*) ll_get(pArrayListEmployee, i);
				fwrite(aux, sizeof(Employee), 1, pFile);
			}
			todoOk = 1;
		}
		fclose(pFile);
	}
	return todoOk;
}

