#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "extras.h"
#include "validaciones.h"

int initEmployees(Employee* list, int len)
{
    int retorno = -1;
    if(list!=NULL && len>0)
    {
        retorno = 0;
        for(int i=0; i<len; i++)
        {
            list[i].isEmpty = 1;
        }
    }
    return retorno;
}

int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
    int retorno = -1;

    if(list!=NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty==1)
            {
                list[i].id = id;
                strcpy(list[i].name, name);
                strcpy(list[i].lastName, lastName);
                list[i].salary = salary;
                list[i].sector = sector;
                list[i].isEmpty = 0;
                break;
            }
        }
        retorno = 0;
    }
    return retorno;
}

int printEmployees(Employee* list, int length)
{
    int retorno = 0;

    if(list!=NULL && length>0)
    {
        system("cls");
        printf("             *** Listado de empleados ***\n");
        printf("   ID           NOMBRE           SALARIO     SECTOR\n");
        printf("======================================================\n");
        for(int i=0; i<length; i++)
        {
            if(list[i].isEmpty==0)
            {
               mostrarEmployee(list[i], length);
            }
            retorno = 1;
        }
    }
    return retorno;
}

int sortEmployees(Employee* list, int len, int order)
{
 int todoOk=-1;
 Employee auxEmployee;
 if(list!=NULL&&len>0)
{
    for(int i=0; i<len; i++)
        {
			for(int j=0; j<len; j++)
			{
				if(order==1 && list[i].isEmpty==0 && ((strcmp(list[i].lastName,list[j].lastName)<0)  || (strcmp(list[i].lastName,list[j].lastName)==0 && list[i].sector > list[j].sector)))
                {
					auxEmployee = list[i];
					list[i]=list[j];
					list[j]=auxEmployee;
				}
				if(order==0 && list[i].isEmpty==0 && ((strcmp(list[i].lastName,list[j].lastName)>0) || (strcmp(list[i].lastName,list[j].lastName)==0 && list[i].sector < list[j].sector)))
				{
					auxEmployee = list[i];
					list[i]=list[j];
					list[j]=auxEmployee;
				}
			}
		}
	}

    return todoOk;
}

int findEmployeeById(Employee* list, int len, int id)
{
    int indice = -1;
    if(list!=NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].id==id && list[i].isEmpty==0)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int removeEmployee(Employee* list, int len, int id)
{
    int retorno = -1;
    int indice;
    char opcion;

    if(list!=NULL && len>0)
    {
        system("cls");
        printf("                      *** BAJA ***\n\n");
        indice=findEmployeeById(list, len, id);

        if(indice==-1)
        {
            printf("No existe una persona con id %d\n", id);
        }
        else
        {
            printf("   ID           NOMBRE           SALARIO     SECTOR\n");
            printf("======================================================\n");
            mostrarEmployee(list[indice], len);
            printf("\n\n");
            printf("Confirma baja?(s/n): ");
            fflush(stdin);
            scanf("%c", &opcion);
            printf("\n");

            while(opcion!='s' && opcion!='n')
            {
                printf("Opcion invalida - Confirma baja?(s/n): ");
                fflush(stdin);
                scanf("%c", &opcion);
            }
            if(opcion=='n')
            {
                printf("Se ha cancelado la baja\n");
            }
            else if(opcion=='s')
            {
                list[indice].isEmpty=1;
                retorno = 0;
            }
        }
    }
    return retorno;
}
