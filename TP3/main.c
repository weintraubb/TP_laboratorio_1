#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "validaciones.h"
/****************************************************
 Menu:
 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
 3. Alta de empleado
 4. Modificar datos de empleado
 5. Baja de empleado
 6. Listar empleados
 7. Ordenar empleados
 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
 10. Salir
 *****************************************************/

int main() {
	setbuf(stdout, NULL);
	int option = 0;
	int check = 0;
	int idEmpleado = 1;
	int cerrar=0;
	int flagLoad = 0;
	int flagSave = 1;

	LinkedList *listaEmpleados = ll_newLinkedList();
	do {
		system("cls");
		printf("    MENU DE OPCIONES:\n\n");
		printf(
				"   1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
		printf(
				"   2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
		printf("   3. Alta de empleado.\n");
		printf("   4. Modificar datos de empleado.\n");
		printf("   5. Baja de empleado.\n");
		printf("   6. Listar empleados.\n");
		printf("   7. Ordenar empleados\n");
		printf(
				"   8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
		printf(
				"   9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n\n");
		printf("   10. Salir.\n\n");
		printf("   Ingrese una opcion: ");
		scanf("%d", &option);
		switch (option) {
		case 1:
			check = controller_loadFromText("data.csv", listaEmpleados);
			if (check) {

				printf("Carga desde texto exitosa!.\n");
				idEmpleado = controller_loadID("id.csv");
				flagLoad = 1;
				if (idEmpleado == -1) {
					printf("Error en la carga del ID\n");
				} else {
					printf("ID incializado en %d\n", idEmpleado);
				}
			}
			system("pause");
			break;
		case 2:
			check = controller_loadFromBinary("data.bin", listaEmpleados);
			if (check) {
				printf("Carga desde binario exitosa!\n");
				idEmpleado = controller_loadID("id.csv");
				flagLoad = 1;
				if (idEmpleado == -1) {
					printf("Error en la carga del ID\n");
				} else {
					printf("ID incializado en %d\n", idEmpleado);
				}
			}
			system("pause");
			break;
		case 3:
			check = controller_addEmployee(listaEmpleados);
			if (check) {
				idEmpleado++;
				controller_setIDUpdate("id.csv", idEmpleado);
				flagSave = 0;
				flagLoad = 1;
			}
			system("pause");
			break;
		case 4:
			system("cls");
			if (flagLoad == 1) {
				check = controller_editEmployee(listaEmpleados);
				if (check) {
					printf("Empleado modificado con exito!\n");
					flagSave = 0;
				}
			} else {
				printf("Todavia no se cargaron empleados\n");
			}
			system("pause");
			break;
		case 5:
			if (flagLoad == 1) {
				check = controller_removeEmployee(listaEmpleados);
				if (check) {
					printf("Empleado removido con exito!\n");
					flagSave = 0;
				}
			} else {
				printf("Todavia no se cargaron empleados\n");
			}
			system("pause");
			break;
		case 6:
			if (flagLoad == 1) {
				system("cls");
				controller_ListEmployee(listaEmpleados);
			} else {
				printf("Todavia no se cargaron empleados\n");
			}
			system("pause");

			break;
		case 7:
			if (flagLoad == 1) {
				system("cls");
				check = controller_sortEmployee(listaEmpleados);
				if (check == 1) {
					printf("Empleados ordenados por ID\n");
				} else if (check == 2) {
					printf("Empleados ordenados por nombre\n");
				} else if (check == 3) {
					printf("Empleados ordenados por horas de trabajo\n");
				} else if (check == 4) {
					printf("Empleados ordenados por sueldo\n");
				} else {
					printf("Empleados sin ordenar\n");
				}
			} else {
				printf("Todavia no se cargaron empleados");
			}
			system("pause");
			break;
		case 8:
			if (flagLoad == 1) {
				check = controller_saveAsText("data.csv", listaEmpleados);
				if (check) {
					printf("Guardado como texto exitoso!\n");
					controller_setIDUpdate("id.csv", idEmpleado);
					flagSave = 1;
				}
			} else {
				printf("Todavia no se cargaron empleados");
			}
			system("pause");
			break;
		case 9:
			if (flagLoad == 1) {
				check = controller_saveAsBinary("data.bin", listaEmpleados);
				if (check) {
					printf("Guardado como binario exitoso!\n");
					controller_setIDUpdate("id.csv", idEmpleado);
					flagSave = 1;
				}
			} else {
				printf("Todavia no se cargaron empleados.\n");
			}
			system("pause");
			break;
		case 10:
			if (flagSave) {
				cerrar = 1;
			} else {
				printf("Los cambios no fueron guardados, desea salir sin guardar?\n");
				printf("1.Si\n");
				printf("2.No\n");
				option = ingresarEntero("Ingrese una opcion: \n", 1, 2);
				switch (option) {
				case 1:
					cerrar = 1;
					break;
				}
			}
			system("pause");
			break;
		default:
			printf("Opcion invalida, seleccione una correcta\n");
			system("pause");
			break;
		}

	} while (cerrar == 0);
	return 0;
}

