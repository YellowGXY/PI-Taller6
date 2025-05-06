#include <stdio.h>
#include <string.h>

void ingresarProductos(char nombres[][30], float precios[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf("Producto %d\n", i + 1);
        printf("Nombre: ");
        if (scanf(" %[^\n]", nombres[i]) != 1) {
            printf("Error al leer el nombre del producto.\n");
        if (scanf("%f", &precios[i]) != 1) {
            printf("Error al leer el precio del producto.\n");
            precios[i] = 0.0; // Set default price on error
        }
        }
        printf("Precio: ");
        scanf("%f", &precios[i]);
    }
}

float calcularTotal(float precios[], int cantidad) {
    float total = 0;
    for (int i = 0; i < cantidad; i++) {
        total += precios[i];
    }
    return total;
}

float calcularPromedio(float precios[], int cantidad) {
    return calcularTotal(precios, cantidad) / cantidad;
}

int buscarProducto(char nombres[][30], float precios[], int cantidad, char nombreBuscado[]) {
    for (int i = 0; i < cantidad; i++) {
        if (strcmp(nombres[i], nombreBuscado) == 0) {
            printf("El precio de %s es %.2f\n", nombres[i], precios[i]);
            return i;
        }
    }
    printf("Producto no encontrado.\n");
    return -1;
}

int encontrarMasCaro(float precios[], int cantidad) {
    int indice = 0;
    for (int i = 1; i < cantidad; i++) {
        if (precios[i] > precios[indice]) {
            indice = i;
        }
    }
    return indice;
}

int encontrarMasBarato(float precios[], int cantidad) {
    int indice = 0;
    for (int i = 1; i < cantidad; i++) {
        if (precios[i] < precios[indice]) {
            indice = i;
        }
    }
    return indice;
}
