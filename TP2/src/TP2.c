#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "extras.h"
#include "validaciones.h"
#define TAM 10

int main(void)
{
	setbuf(stdout, NULL);

	Employee lista[TAM];
	    Employee unEmpleado;
	    int verificar;
	    int nextId=10000;
	    int id;
	    char seguir = 's';
	    int flagCarga=0;
	    int contadorEmpleados=0;
	    int opcion;
	    float salario;
	    float promedioSalario;

	    if(initEmployees(lista, TAM)==-1)
	    {
	        printf("No se pudo inicializar.\n");
	    }

	    do
	    {
	        switch(menu())
	        {
	        case 1:
	            unEmpleado = crearEmpleado(nextId);
	            verificar = addEmployee(lista, TAM, unEmpleado.id, unEmpleado.name, unEmpleado.lastName, unEmpleado.salary, unEmpleado.sector);
	            if(verificar==-1)
	            {
	                printf("Error, empleado no ingresado\n");
	            }
	            else
	            {
	                flagCarga=1;
	                nextId++;
	            }
	            break;
	        case 2:
	            if(flagCarga==1)
	            {
	                system("cls");
	                printf("   *** BAJA ***\n");
	                printf("===================\n");
	                printf("\n");
	                id = ingresarEntero("Ingrese id a dar de baja: ", 10000, 11000);
	                verificar=removeEmployee(lista, TAM, id);
	                if(verificar==0)
	                {
	                    printf("Baja exitosa.\n");
	                }
	            }
	            else
	            {
	                printf("Debe dar de alta algun empleado.\n");
	            }
	            break;
	        case 3:
	            if(flagCarga==1)
	            {
	                system("cls");
	                printf("   *** MODIFICACIONES ***");
	                printf("===========================\n\n");
	                id = ingresarEntero("Ingrese id del empleado a modificar: ", 10000, 11000);
	                verificar=findEmployeeById(lista, TAM, id);
	                modificarEmployee(lista, verificar, TAM);
	            }

	            break;
	        case 4:
	            if(flagCarga==1)
	            {
	                do
	                {
	                  system("cls");
	                  printf("   *** Informe de Empleados *** \n");
	                  printf("====================================\n");
	                  printf("   1. Listado de empleados\n");
	                  printf("   2. Informe de salarios\n");
	                  printf("   3. Volver\n");
	                  opcion=ingresarEntero("Ingrese una opcion: ", 1, 3);
	                  switch(opcion)
	                  {
	                case 1:
	                    system("cls");
	                    printf("    ***Listado de empleados***  \n");
	                    printf("----------------------------------\n");
	                    printf("En que orden desea mostrar los empleados?\n");
	                    printf("1. Ascendente.\n");
	                    printf("2. Descendente.\n");
	                    opcion=ingresarEntero("Ingrese una opcion: ", 1, 2);
	                    if(opcion == 2)
	                    {
	                        opcion = 0;
	                    }
	                    sortEmployees(lista, TAM, opcion);
	                    printEmployees(lista, TAM);
	                    system("pause");
	                    break;
	                  case 2:
	                    system("cls");
	                    printf("   *** Informe de Salarios ***\n");
	                    printf("==================================\n\n");
	                    salario = totalSalarios(lista, TAM, &contadorEmpleados);
	                    printf("La suma total de los salarios es: %.2f\n", salario);
	                    promedioSalario=calcularPromedio(salario, contadorEmpleados);
	                    printf("El promedio de los salarios es: %.2f\n\n\n", promedioSalario);
	                    if(salarioMayor(lista, TAM, promedioSalario))
	                    {
	                        mostrarSalarioMayor(lista, TAM, promedioSalario);
	                    }
	                    system("pause");
	                    break;
	                  case 3:
	                    printf("Regreso al menu principal \n");
	                    break;
	                  default:
	                    printf("Ingrese una opcion del 1 al 3\n");
	                    break;
	                  }
	                }while(opcion != 3);
	            }
	            else
	            {
	                    printf("No hay empleados para mostrar");
	            }
	            break;
	        case 5:
	            printf("Hasta luego!");
	            seguir = 'n';
	            break;
	        default:
	            printf("Opcion invalida, ingrese una correcta\n");
	        }
	        system("pause");
	    }while(seguir == 's');
	return EXIT_SUCCESS;
}
