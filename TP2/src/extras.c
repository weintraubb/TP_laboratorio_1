#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "extras.h"
#include "ArrayEmployees.h"
#include "validaciones.h"


int menu()
{
    int opcion;

    system("cls");
    printf("      *** ABM Empleados ***\n");
	printf("--------------------------------\n");
	printf("    1. ALTAS\n");
	printf("    2. BAJA\n");
	printf("    3. MODIFICAR\n");
	printf("    4. INFORMAR\n");
	printf("    5. SALIR\n\n");
	printf("    Ingrese opcion: ");
	scanf("%d", &opcion);

    return opcion;
}

int buscarLibre(Employee* list, int tam)
{
    int indice=-1;

    if(list!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(list[i].isEmpty==1)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

Employee crearEmpleado(int id)
{
    Employee unEmpleado;

    if(id>0)
    {
        system("cls");
        printf("  *** ALTA EMPLEADO ***\n");
        printf("=========================\n\n");

        unEmpleado.id = id;
        ingresarCadena("Ingrese nombre del empleado: ", unEmpleado.name);
        printf("\n");
        ingresarCadena("ingrese apellido del empleado: ", unEmpleado.lastName);
        printf("\n");
        unEmpleado.salary = ingresarFlotante("Ingrese salario del empleado: ", 1, 1000000);
        printf("\n");
        unEmpleado.sector = ingresarEntero("Ingrese sector del empleado: ", 1, 100);

    }
    return unEmpleado;
}

void mostrarEmployee(Employee unEmpleado, int tam)
{
    printf(" %d     %7s, %-7s      %.2f      %-3d\n", unEmpleado.id, unEmpleado.lastName, unEmpleado.name, unEmpleado.salary, unEmpleado.sector);
}

float totalSalarios(Employee* list, int tam, int* totalEmpleados)
{
    float acumSalarios = 0;
    int contadorEmpleados = 0;

    for(int i=0; i<tam; i++)
    {
        if(list[i].isEmpty==0)
        {
            contadorEmpleados++;
            acumSalarios+=list[i].salary;
        }
    }
    *totalEmpleados = contadorEmpleados;
    return acumSalarios;
}
float calcularPromedio(float numero, int divisor)
{
    float promedio;
    if(divisor==0)
    {
        promedio=-1;
    }
    else{
        promedio=numero/divisor;
    }
    return promedio;
}

int salarioMayor(Employee* list, int tam, float salario)
{
    int retorno=0;
    for(int i=0;i<tam;i++)
    {
        if(list[i].salary>salario&&list[i].isEmpty==0)
        {
            retorno = 1;
        }
    }
    return retorno;
}

void mostrarSalarioMayor(Employee* list, int tam, float salario)
{

    printf("Los empleados con un salario mas alto que el promedio son: \n\n");
    printf("   ID           NOMBRE           SALARIO     SECTOR\n");
    printf("======================================================\n");
    for(int i=0;i<tam;i++)
    {
        if(list[i].salary>salario&&list[i].isEmpty==0)
        {
            mostrarEmployee(list[i],i);
        }
    }
}

int menuModificacion()
{
    int opcion;

    system("cls");
    printf("  *** MENU DE MODIFICACION ***\n\n");
    printf("   1. Modificar nombre\n");
    printf("   2. Modificar apellido\n");
    printf("   3. Modificar salario\n");
    printf("   4. Modificar sector\n");
    printf("   5. Terminar\n\n");
    printf("   Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}


int modificarEmployee(Employee* list, int indice, int tam)
{
    int retorno = 0;
    char opcion;

    if(list!=NULL)
    {
        system("cls");
        printf("                   *** EMPLEADO ***\n\n");
        printf("   ID           NOMBRE           SALARIO     SECTOR\n");
        printf("======================================================\n");
        mostrarEmployee(list[indice], tam);
        printf("\n\n");
        printf("Desea modificar? (s/n): ");
        fflush(stdin);
        scanf("%c", &opcion);
        printf("\n\n");


        while(opcion=='s')
        {
            switch(menuModificacion())
            {
             case 1:
                ingresarCadena("Ingrese nuevo nombre: ", list[indice].name);
                break;
             case 2:
                ingresarCadena("Ingrese nuevo apellido: ", list[indice].lastName);
                break;
             case 3:
                list[indice].salary = ingresarFlotante("Ingrese nuevo salario: ", 1, 1000000);
                break;
             case 4:
                list[indice].sector = ingresarEntero("Ingrese nuevo sector: ", 1, 100);
                break;
             case 5:
                printf("Desea cancelar salida? (s/n): ");
                fflush(stdin);
                scanf("%c", &opcion);
                break;
            }
        }
        retorno = 1;
    }

    return retorno;
}
