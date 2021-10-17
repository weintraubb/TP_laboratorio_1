#ifndef EXTRAS_H_INCLUDED
#define EXTRAS_H_INCLUDED



#endif // EXTRAS_H_INCLUDED
#include "ArrayEmployees.h"
#include "validaciones.h"

int menu();
Employee crearEmpleado(int id);
int buscarLibre(Employee* list, int tam);
void mostrarEmployee(Employee unEmpleado, int tam);
int menuModificacion();
float totalSalarios(Employee* list, int tam, int* totalEmpleados);
float calcularPromedio(float numero, int divisor);
int salarioMayor(Employee* list, int tam, float salario);
void mostrarSalarioMayor(Employee* list, int tam, float salario);
int modificarEmployee(Employee* list, int indice, int tam);
