#include <stdio.h>
#include <string.h>
#define MAX 10

void mostrarMenu() {
    printf("\n==============================\n");
    printf("   MENU DE INVENTARIO\n");
    printf("==============================\n");
    printf("  1. Ingresar productos\n");
    printf("  2. Calcular precio total\n");
    printf("  3. Calcular precio promedio\n");
    printf("  4. Encontrar producto mas caro\n");
    printf("  5. Encontrar producto mas barato\n");
    printf("  6. Buscar producto por nombre\n");
    printf("  7. Eliminar producto\n");
    printf("  8. Agregar stock a un producto\n");
    printf("  0. Salir\n");
    printf("==============================\n");
    printf("  Seleccione una opcion: ");
}

int ingresarDatos(char nombres[][30], float precios[], int stocks[]) {
    int n, val;
    int cantidadActual = 0;

    while (cantidadActual < MAX && strlen(nombres[cantidadActual]) > 0) {
        cantidadActual++;
    }

    printf("\n====================================\n");
    printf("   PRODUCTOS EN EL INVENTARIO (%d)\n", cantidadActual);
    printf("====================================\n");

    for (int i = 0; i < cantidadActual; i++) {
        printf("  %d. \t%s - $%.2f (Stock: %d)\n", i + 1, nombres[i], precios[i], stocks[i]);
    }

    if (cantidadActual >= MAX) {
        printf("\nYa alcanzaste el limite de %d productos\n", MAX);
        return cantidadActual;
    }

    int espacioDisponible = MAX - cantidadActual;
    printf("\nPuede ingresar hasta %d producto(s) mas.\n", espacioDisponible);
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
        char nombreTemp[30];

        do {
            nombreValido = 1;
            nombreDuplicado = 0;

            printf("\n--- Ingresando producto %d ---\n", idx + 1);
            printf("  Nombre: ");
            fgets(nombreTemp, 30, stdin);
            int len = strlen(nombreTemp);
            if (len > 0 && nombreTemp[len - 1] == '\n') {
                nombreTemp[len - 1] = '\0';
            }

            int soloEspacios = 1;
            for (int k = 0; nombreTemp[k] != '\0'; k++) {
                if (nombreTemp[k] != ' ') {
                    soloEspacios = 0;
                    break;
                }
            }

            if (strlen(nombreTemp) == 0 || soloEspacios) {
                printf("  El nombre no puede estar vacio o lleno solo de espacios.\n");
                nombreValido = 0;
            }

            for (int j = 0; j < cantidadActual + i; j++) {
                if (strcmp(nombres[j], nombreTemp) == 0) {
                    printf("  Ese nombre ya fue ingresado. Ingrese otro.\n");
                    nombreDuplicado = 1;
                    break;
                }
            }

        } while (!nombreValido || nombreDuplicado);

        strcpy(nombres[idx], nombreTemp);

        printf("  Precio: ");
        do {
            val = scanf("%f", &precios[idx]);
            while (getchar() != '\n');
            if (val != 1 || precios[idx] < 0) {
                printf("  Precio invalido. Ingrese un valor positivo: ");
            }
        } while (val != 1 || precios[idx] < 0);

        printf("  Stock (cantidad de unidades): ");
        do {
            val = scanf("%d", &stocks[idx]);
            while (getchar() != '\n');
            if (val != 1 || stocks[idx] < 0) {
                printf("  Stock invalido. Ingrese un valor positivo: ");
            }
        } while (val != 1 || stocks[idx] < 0);
    }

    printf("\n>>> Productos agregados exitosamente.\n");
    return cantidadActual + n;
}

int eliminarProducto(char nombres[][30], float precios[], int stocks[], int cantidad) {
    printf("\n--- Lista de productos ---\n");
    for (int i = 0; i < cantidad; i++) {
        printf("  %d. \t%s - $%.2f (Stock: %d)\n", i + 1, nombres[i], precios[i], stocks[i]);
    }

    int opcion, val;
    printf("\nIngrese el numero del producto que desea eliminar (1 a %d): ", cantidad);
    do {
        val = scanf("%d", &opcion);
        while (getchar() != '\n');
        if (val != 1 || opcion < 1 || opcion > cantidad) {
            printf("Entrada invalida. Intente nuevamente: ");
        }
    } while (val != 1 || opcion < 1 || opcion > cantidad);

    int idx = opcion - 1;
    for (int i = idx; i < cantidad - 1; i++) {
        strcpy(nombres[i], nombres[i + 1]);
        precios[i] = precios[i + 1];
        stocks[i] = stocks[i + 1];
    }

    nombres[cantidad - 1][0] = '\0';
    precios[cantidad - 1] = 0;
    stocks[cantidad - 1] = 0;

    printf(">>> Producto eliminado exitosamente.\n");
    return cantidad - 1;
}

float calcularTotal(float precios[], int stocks[], int cantidad) {
    float total = 0;
    for (int i = 0; i < cantidad; i++) {
        total += precios[i] * stocks[i];
    }
    return total;
}

float calcularPromedio(float precios[], int stocks[], int cantidad) {
    int totalUnidades = 0;
    float total = 0;
    for (int i = 0; i < cantidad; i++) {
        total += precios[i] * stocks[i];
        totalUnidades += stocks[i];
    }

    if (totalUnidades > 0) {
        return total / totalUnidades;
    } else {
        return 0;
    }
}


int encontrarMasCaro(float precios[], int stocks[], int cantidad) {
    int maxIndex = 0;
    for (int i = 1; i < cantidad; i++) {
        if (precios[i] > precios[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int encontrarMasBarato(float precios[], int stocks[], int cantidad) {
    int minIndex = 0;
    for (int i = 1; i < cantidad; i++) {
        if (precios[i] < precios[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

int buscarProducto(char nombres[][30], float precios[], int stocks[], int cantidad) {
    char nombreBuscado[30];
    int encontrados = 0;

    printf("\nIngrese nombre o parte del nombre del producto a buscar: ");
    fgets(nombreBuscado, 30, stdin);
    nombreBuscado[strcspn(nombreBuscado, "\n")] = '\0';

    printf("\nCoincidencias encontradas:\n");
    for (int i = 0; i < cantidad; i++) {
        if (strstr(nombres[i], nombreBuscado) != NULL) {
            printf("  %d. \t%s - $%.2f (Stock: %d)\n", i + 1, nombres[i], precios[i], stocks[i]);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("No se encontraron productos que coincidan con \"%s\".\n", nombreBuscado);
    }

    return encontrados;
}

void agregarStock(char nombres[][30], float precios[], int stocks[], int cantidad) {
    char nombreBuscado[30];
    int encontrado = 0;

    printf("\nIngrese el nombre del producto al que desea agregar stock: ");
    fgets(nombreBuscado, 30, stdin);
    nombreBuscado[strcspn(nombreBuscado, "\n")] = '\0';

    for (int i = 0; i < cantidad; i++) {
        if (strcmp(nombres[i], nombreBuscado) == 0) {
            int adicional, val;
            printf("Stock actual de %s: %d\n", nombres[i], stocks[i]);
            printf("Cuantas unidades desea agregar? ");
            do {
                val = scanf("%d", &adicional);
                while (getchar() != '\n');
                if (val != 1 || adicional < 1) {
                    printf("Cantidad invalida. Ingrese un numero positivo: ");
                }
            } while (val != 1 || adicional < 1);

            stocks[i] += adicional;
            printf(">>> Stock actualizado. Nuevo stock de %s: %d\n", nombres[i], stocks[i]);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf(">>> El producto \"%s\" no existe. Use la opcion 'Ingresar productos' para agregarlo.\n", nombreBuscado);
    }
}
