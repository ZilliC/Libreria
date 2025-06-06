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
FILE *archivo;
struct libro activo;

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

    if ((archivo = fopen("libros.DAT", "ab")) == NULL) {
        printf("\nNo se pudo abrir el archivo");
        exit(0);
    }

    printf("Escribe la clave (Max 6)\n");
    if (fgets(activo.clave, sizeof activo.clave, stdin)) {
        if (strchr(activo.clave, '\n')) {
            quitarSaltoLinea(activo.clave);
        } else {
            limpiarBuffer(); // quedó '\n' pendiente
        }
    }

    printf("Escribe el ISBN (Max 13)\n");
    if (fgets(activo.isbn, sizeof activo.isbn, stdin)) {
        if (strchr(activo.isbn, '\n')) {
            quitarSaltoLinea(activo.isbn);
        } else {
            limpiarBuffer();
        }
    }

    printf("Escribe el titulo (Max 30)\n");
    if (fgets(activo.titulo, sizeof activo.titulo, stdin)) {
        if (strchr(activo.titulo, '\n')) {
            quitarSaltoLinea(activo.titulo);
        } else {
            limpiarBuffer();
        }
    }

    printf("Escribe el autor (Max 30)\n");
    if (fgets(activo.autor, sizeof activo.autor, stdin)) {
        if (strchr(activo.autor, '\n')) {
            quitarSaltoLinea(activo.autor);
        } else {
            limpiarBuffer();
        }
    }

    printf("Escribe el anio (Max 4)\n");
    if (fgets(activo.anio, sizeof activo.anio, stdin)) {
        if (strchr(activo.anio, '\n')) {
            quitarSaltoLinea(activo.anio);
        } else {
            limpiarBuffer();
        }
    }

    printf("Escribe el genero (Max 30)\n");
    if (fgets(activo.genero, sizeof activo.genero, stdin)) {
        if (strchr(activo.genero, '\n')) {
            quitarSaltoLinea(activo.genero);
        } else {
            limpiarBuffer();
        }
    }

    printf("Escribe la editorial (Max 30)\n");
    if (fgets(activo.editorial, sizeof activo.editorial, stdin)) {
        if (strchr(activo.editorial, '\n')) {
            quitarSaltoLinea(activo.editorial);
        } else {
            limpiarBuffer();
        }
    }

    printf("Escribe las unidades (entero)\n");
    scanf("%d", &activo.unidades);
    limpiarBuffer();

    fwrite(&activo, sizeof(activo), 1, archivo);
    fclose(archivo);
}

void consultaLibro(void) {
    char claveBusca[7];
    int encontrado = 0;

    printf("Seleccionaste la opción 2: Consultar libro\n");

    if ((archivo = fopen("libros.DAT", "rb")) == NULL) {
        printf("\nNo se pudo abrir el archivo de libros.\n");
        return;
    }

    // Pedir la clave a buscar
    printf("Escribe la clave del libro a consultar (Max 6 caracteres):\n");
    if (fgets(claveBusca, sizeof claveBusca, stdin)) {
        if (strchr(claveBusca, '\n')) {
            quitarSaltoLinea(claveBusca);
        } else {
            limpiarBuffer();
        }
    }

    // Recorrer el archivo hasta encontrar la clave
    while (fread(&activo, sizeof(activo), 1, archivo) == 1) {
        if (strcmp(activo.clave, claveBusca) == 0) {
            // Libro encontrado: mostrar todos los campos
            printf("\n--- Datos del libro encontrado ---\n");
            printf("Clave:     %s\n", activo.clave);
            printf("ISBN:      %s\n", activo.isbn);
            printf("Título:    %s\n", activo.titulo);
            printf("Autor:     %s\n", activo.autor);
            printf("Año:       %s\n", activo.anio);
            printf("Género:    %s\n", activo.genero);
            printf("Editorial: %s\n", activo.editorial);
            printf("Unidades:  %d\n\n", activo.unidades);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\nNo se encontró ningún libro con la clave \"%s\".\n\n", claveBusca);
    }

    fclose(archivo);
}
void listaLibro(void) {
    int contador = 0;
    printf("Seleccionaste la opción 3: Listar libros\n");

    if ((archivo = fopen("libros.DAT", "rb")) == NULL) {
        printf("\nNo se pudo abrir el archivo de libros.\n");
        return;
    }

    printf("\n%-7s %-14s %-30s %-30s %-4s %-30s %-30s %-8s\n",
        "CLAVE", "ISBN", "TITULO", "AUTOR", "AÑO", "GENERO", "EDITORIAL", "UNID");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    while (fread(&activo, sizeof(activo), 1, archivo) == 1) {
        printf("%-7s %-14s %-30s %-30s %-4s %-30s %-30s %-8d\n",
            activo.clave, activo.isbn, activo.titulo, activo.autor, activo.anio, activo.genero, activo.editorial, activo.unidades);
        contador++;
        if (contador % 5 == 0) {
            printf("\nPresiona Enter para ver más...");
            limpiarBuffer();
        }
    }

    if (contador == 0) {
        printf("\nNo hay libros registrados.\n");
    } else if (contador % 5 != 0) {
        printf("\nFin de la lista.\n");
    }

    fclose(archivo);
}
void bajaLibro(void) {
    char claveBusca[7];
    int encontrado = 0;

    printf("Seleccionaste la opción 4: Baja de libro\n");

    if ((archivo = fopen("libros.DAT", "rb")) == NULL) {
        printf("\nNo se pudo abrir el archivo de libros.\n");
        return;
    }

    FILE *temp = fopen("temp.DAT", "wb");
    if (temp == NULL) {
        printf("\nNo se pudo crear el archivo temporal.\n");
        fclose(archivo);
        return;
    }

    // Pedir la clave a eliminar
    printf("Escribe la clave del libro a eliminar (Max 6 caracteres):\n");
    if (fgets(claveBusca, sizeof claveBusca, stdin)) {
        if (strchr(claveBusca, '\n')) {
            quitarSaltoLinea(claveBusca);
        } else {
            limpiarBuffer();
        }
    }

    // Copiar registros excepto el que se quiere eliminar
    while (fread(&activo, sizeof(activo), 1, archivo) == 1) {
        if (strcmp(activo.clave, claveBusca) == 0) {
            encontrado = 1;
            printf("\nLibro eliminado:\nClave: %s, Título: %s\n", activo.clave, activo.titulo);
            continue; // No copiar este registro
        }
        fwrite(&activo, sizeof(activo), 1, temp);
    }

    fclose(archivo);
    fclose(temp);

    if (!encontrado) {
        printf("\nNo se encontró ningún libro con la clave \"%s\".\n\n", claveBusca);
        remove("temp.DAT");
    } else {
        remove("libros.DAT");
        rename("temp.DAT", "libros.DAT");
        printf("La baja se realizó correctamente.\n");
    }
}




int main(void) {
    do {
        printf("Menu\nSelecciona una opcion\n1. Alta de libro\n2. Consultar libro\n3. Listar libros\n4. Baja de libro\n0. Salir\n");
        scanf("%d",&select);
        limpiarBuffer();
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
