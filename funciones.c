#include <stdio.h>
#include <string.h>

#define MAX 10

int ingresarDatos(char nombres[][30], float precios[]) {
    int n, len, val;
    int cantidadActual = 0;

    while (cantidadActual < MAX && strlen(nombres[cantidadActual]) > 0) {
        cantidadActual++;
    }

    printf("\n====================================\n");
    printf("   PRODUCTOS EN EL INVENTARIO (%d)\n", cantidadActual);
    printf("====================================\n");

    if (cantidadActual == 0) {
        printf("No hay productos ingresados actualmente.\n");
    } else {
        for (int i = 0; i < cantidadActual; i++) {
            printf("  %d. %s - $%.2f\n", i + 1, nombres[i], precios[i]);
        }
    }

    if (cantidadActual >= MAX) {
        printf("\n¡Ya alcanzó el limite de %d productos!\n", MAX);
        return cantidadActual;
    }

    int espacioDisponible = MAX - cantidadActual;
    printf("\n------------------------------------\n");
    printf("Puede ingresar hasta %d producto(s) mas.\n", espacioDisponible);
    printf("Cuantos productos desea agregar ahora? ");

    do {
        val = scanf("%d", &n);
        while (getchar() != '\n');
        if (val != 1 || n < 1 || n > espacioDisponible) {
            printf("Cantidad invalida. Ingrese un numero entre 1 y %d: ", espacioDisponible);
        }
    } while (val != 1 || n < 1 || n > espacioDisponible);

    for (int i = 0; i < n; i++) {
        int idx = cantidadActual + i;
        int nombreValido, nombreDuplicado;
        
        do {
            nombreValido = 1;
            nombreDuplicado = 0;
            
            printf("\n--- Ingresando producto %d ---\n", idx + 1);
            printf("  Nombre: ");
            fgets(nombres[idx], 30, stdin);

            len = strlen(nombres[idx]);
            if (len > 0 && nombres[idx][len - 1] == '\n') {
                nombres[idx][len - 1] = '\0';
            }
            
            int soloEspacios = 1;
            for (int k = 0; nombres[idx][k] != '\0'; k++) {
                if (nombres[idx][k] != ' ') {
                    soloEspacios = 0;
                    break;
                }
            }

            if (strlen(nombres[idx]) == 0 || soloEspacios) {
                printf("  El nombre no puede estar vacio o lleno solo de espacios.\n");
                nombreValido = 0;
            }

            
            for (int j = 0; j < cantidadActual + i; j++) {
                if (strcmp(nombres[j], nombres[idx]) == 0) {
                    printf("  Ese nombre ya fue ingresado. Ingrese otro.\n");
                    nombreDuplicado = 1;
                    break;
                }
            }
            

        } while (!nombreValido || nombreDuplicado);

        printf("  Precio: ");
        do {
            val = scanf("%f", &precios[idx]);
            while (getchar() != '\n');
            if (val != 1 || precios[idx] < 0) {
                printf("  Precio inválido. Ingrese un valor positivo: ");
            }
        } while (val != 1 || precios[idx] < 0);
    }

    printf("\n>>> Productos agregados exitosamente.\n");
    return cantidadActual + n;
}

int eliminarProducto(char nombres[][30], float precios[], int cantidad) {

    printf("\n--- Lista de productos ---\n");
    for (int i = 0; i < cantidad; i++) {
        printf("  %d. %s - $%.2f\n", i + 1, nombres[i], precios[i]);
    }

    int opcion, val;
    printf("\nIngrese el numero del producto que desea eliminar (1 a %d): ", cantidad);
    do {
        val = scanf("%d", &opcion);
        while (getchar() != '\n');
        if (val != 1 || opcion < 1 || opcion > cantidad) {
            printf("Entrada inválida. Intente nuevamente: ");
        }
    } while (val != 1 || opcion < 1 || opcion > cantidad);

    int idx = opcion - 1;
    for (int i = idx; i < cantidad - 1; i++) {
        strcpy(nombres[i], nombres[i + 1]);
        precios[i] = precios[i + 1];
    }

    nombres[cantidad - 1][0] = '\0';
    precios[cantidad - 1] = 0;

    printf(">>> Producto eliminado exitosamente.\n");
    return cantidad - 1;
}

float calcularTotal(float precios[], int cantidad) {
    float total = 0;
    for (int i = 0; i < cantidad; i++)
        total += precios[i];
    return total;
}

float calcularPromedio(float precios[], int cantidad) {
    return (cantidad > 0) ? calcularTotal(precios, cantidad) / cantidad : 0;
}

int encontrarMasCaro(float precios[], int cantidad) {
    int maxIndex = 0;
    for (int i = 1; i < cantidad; i++)
        if (precios[i] > precios[maxIndex])
            maxIndex = i;
    return maxIndex;
}

int encontrarMasBarato(float precios[], int cantidad) {
    int minIndex = 0;
    for (int i = 1; i < cantidad; i++)
        if (precios[i] < precios[minIndex])
            minIndex = i;
    return minIndex;
}

void buscarProducto(char nombres[][30], float precios[], int cantidad) {
    char nombreBuscado[30];
    int encontrados = 0;

    printf("\nIngrese nombre o parte del nombre del producto a buscar: ");
    fgets(nombreBuscado, 30, stdin);
    nombreBuscado[strcspn(nombreBuscado, "\n")] = '\0'; 

    printf("\nCoincidencias encontradas:\n");
    for (int i = 0; i < cantidad; i++) {
        int lenCadena = 0;
        while (nombres[i][lenCadena] != '\0') {
            lenCadena++;
        }

        int lenBusqueda = 0;
        while (nombreBuscado[lenBusqueda] != '\0') {
            lenBusqueda++;
        }

        int encontrada = 0;
        for (int j = 0; j <= lenCadena - lenBusqueda; j++) {
            int k = 0;
            while (k < lenBusqueda && nombres[i][j + k] == nombreBuscado[k]) {
                k++;
            }
            if (k == lenBusqueda) {
                encontrada = 1;
                break;
            }
        }

        if (encontrada) {
            printf("  %d. %s - $%.2f\n", i + 1, nombres[i], precios[i]);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("No se encontraron productos que coincidan con \"%s\".\n", nombreBuscado);
    }
