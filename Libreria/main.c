#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>


// Funcion para limpiar el buffer del teclado
void limpiarBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Funcion para eliminar el salto de linea (\n) que deja fgets
void quitarSaltoLinea(char *cadena) {
    cadena[strcspn(cadena, "\n")] = '\0';
}

// Definicion de estructura
struct libro {
    char clave[7];
    char isbn[14];
    char titulo[31];
    char autor[31];
    char anio[5];
    char genero[31];
    char editorial[31];
    int unidades;
};
int select=0;


int main(void) {
    do {
        printf("Menu\nSelecciona una opcion\n1. Alta de libro\n2. Consultar libro\n3. Listar libros\n4. Editar libro\n5. Baja de libro\n0. Salir\n\n");
        
    } while (select!=0);
    printf("Gracias por tu visita\n¡Vuelve pronto!\n\n");
    return 0;
}





/*
struct libro emp;

printf("Ingresa el nombre: ");
fgets(emp.nombre, sizeof(emp.nombre), stdin);
quitarSaltoLinea(emp.nombre);

printf("Ingresa el apellido paterno: ");
fgets(emp.apaterno, sizeof(emp.apaterno), stdin);
quitarSaltoLinea(emp.apaterno);

printf("Ingresa el apellido materno: ");
fgets(emp.amaterno, sizeof(emp.amaterno), stdin);
quitarSaltoLinea(emp.amaterno);

printf("Ingresa el departamento: ");
fgets(emp.depto, sizeof(emp.depto), stdin);
quitarSaltoLinea(emp.depto);

printf("Ingresa el puesto: ");
fgets(emp.puesto, sizeof(emp.puesto), stdin);
quitarSaltoLinea(emp.puesto);

printf("Ingresa el salario diario: ");
scanf("%f", &emp.sdiario);
limpiarBuffer();

printf("Ingresa el numero de dias trabajados: ");
scanf("%d", &emp.diastrab);
limpiarBuffer();

printf("Ingresa la fecha de nacimiento (dd mm aaaa): ");
scanf("%d %d %d", &emp.nac.dia, &emp.nac.mes, &emp.nac.anhos);
limpiarBuffer();

printf("Ingresa la fecha de ingreso (dd mm aaaa): ");
scanf("%d %d %d", &emp.ings.dia, &emp.ings.mes, &emp.ings.anhos);
limpiarBuffer();

Mostrar los datos
printf("\n--- Datos del Empleado ---\n");
printf("Nombre: %s\n", emp.nombre);
printf("Apellido Paterno: %s\n", emp.apaterno);
printf("Apellido Materno: %s\n", emp.amaterno);
printf("Departamento: %s\n", emp.depto);
printf("Puesto: %s\n", emp.puesto);
printf("Salario Diario: %.2f\n", emp.sdiario);
printf("Dias trabajados: %d\n", emp.diastrab);
printf("Fecha de nacimiento: %02d/%02d/%04d\n", emp.nac.dia, emp.nac.mes, emp.nac.anhos);
printf("Fecha de ingreso: %02d/%02d/%04d\n", emp.ings.dia, emp.ings.mes, emp.ings.anhos);
*/
