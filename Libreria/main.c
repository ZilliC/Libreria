//Inclusion de librerias
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

// Definicion de estructuras
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

// Definicion de variables
int select=0;

// Funcion para limpiar el buffer del teclado
void limpiarBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Funcion para eliminar el salto de linea (\n) que deja fgets
void quitarSaltoLinea(char *cadena) {
    cadena[strcspn(cadena, "\n")] = '\0';
}


//Funcioines del menu
void altaLibro(void){
    printf("Seleccionaste la opcion 1 Alta de libro\n");
    struct libro nuevoLibro;
        FILE *archivo;

        limpiarBuffer(); // Limpia buffer antes de pedir datos con fgets

        printf("Ingresa la clave: ");
        fgets(nuevoLibro.clave, sizeof(nuevoLibro.clave), stdin);
        quitarSaltoLinea(nuevoLibro.clave);

        printf("Ingresa el ISBN: ");
        fgets(nuevoLibro.isbn, sizeof(nuevoLibro.isbn), stdin);
        quitarSaltoLinea(nuevoLibro.isbn);

        printf("Ingresa el titulo: ");
        fgets(nuevoLibro.titulo, sizeof(nuevoLibro.titulo), stdin);
        quitarSaltoLinea(nuevoLibro.titulo);

        printf("Ingresa el autor: ");
        fgets(nuevoLibro.autor, sizeof(nuevoLibro.autor), stdin);
        quitarSaltoLinea(nuevoLibro.autor);

        printf("Ingresa el anio: ");
        fgets(nuevoLibro.anio, sizeof(nuevoLibro.anio), stdin);
        quitarSaltoLinea(nuevoLibro.anio);

        printf("Ingresa el genero: ");
        fgets(nuevoLibro.genero, sizeof(nuevoLibro.genero), stdin);
        quitarSaltoLinea(nuevoLibro.genero);

        printf("Ingresa la editorial: ");
        fgets(nuevoLibro.editorial, sizeof(nuevoLibro.editorial), stdin);
        quitarSaltoLinea(nuevoLibro.editorial);

        printf("Ingresa el numero de unidades: ");
        scanf("%d", &nuevoLibro.unidades);
        limpiarBuffer();

        // Abrir el archivo para agregar
        archivo = fopen("libros.txt", "a");
        if (archivo == NULL) {
            printf("Error al abrir el archivo.\n");
            return;
        }

        // Guardar los datos en una sola línea separados por tabuladores
        fprintf(archivo, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\n",
                nuevoLibro.clave,
                nuevoLibro.isbn,
                nuevoLibro.titulo,
                nuevoLibro.autor,
                nuevoLibro.anio,
                nuevoLibro.genero,
                nuevoLibro.editorial,
                nuevoLibro.unidades);

        fclose(archivo);

        printf("Libro guardado correctamente en el archivo.\n");
}
void consultaLibro(void){
    printf("Seleccionaste la opcion 2 Consultar libro\n");
}
void listaLibro(void){
    printf("Seleccionaste la opcion 3 Listar libros\n");
}
void editaLibro(void){
    printf("Seleccionaste la opcion 4 Editar libro\n");
}
void bajaLibro(void){
    printf("Seleccionaste la opcion 5 Baja de libro\n");
}




int main(void) {
    do {
        printf("Menu\nSelecciona una opcion\n1. Alta de libro\n2. Consultar libro\n3. Listar libros\n4. Editar libro\n5. Baja de libro\n0. Salir\n");
        scanf("%d",&select);
        switch (select) {
            case 1:
                altaLibro();
                break;
            case 2:
                consultaLibro();
                break;
            case 3:
                listaLibro();
                break;
            case 4:
                editaLibro();
                break;
            case 5:
                bajaLibro();
                break;
            case 0:
                break;
            default:
                printf("Opcion no valida, intenta de nuevo\n");
                break;
        }
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
