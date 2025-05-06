#include <stdio.h>
#include <string.h>

int ingresarDatos(char nombres[][30], float precios[]) {
    int n, len, val;
    int cantidadActual = 0;

    while (cantidadActual < 10 && strlen(nombres[cantidadActual]) > 0) {
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

    if (cantidadActual >= 10) {
        printf("\n¡Ya alcanzó el limite de 10 productos!\n");
        return cantidadActual;
    }

    int espacioDisponible = 10 - cantidadActual;
    printf("\n------------------------------------\n");
    printf("Puede ingresar hasta %d producto(s) mas.\n", espacioDisponible);
    printf("Cuantos productos desea agregar ahora? ");
    
    do {
        val = scanf("%d", &n);
        if (val != 1 || n < 1 || n > espacioDisponible) {
            while (getchar() != '\n');
            printf("Cantidad invalida. Ingrese un numero entre 1 y %d: ", espacioDisponible);
        }
    } while (val != 1 || n < 1 || n > espacioDisponible);

    for (int i = 0; i < n; i++) {
        int idx = cantidadActual + i;
        printf("\n--- Ingresando producto %d ---\n", idx + 1);
        
        printf("  Nombre: ");
        while (getchar() != '\n'); 
        fgets(nombres[idx], 30, stdin);
        len = strlen(nombres[idx]) - 1;
        if (nombres[idx][len] == '\n')
            nombres[idx][len] = '\0';

        printf("  Precio: ");
        do {
            val = scanf("%f", &precios[idx]);
            if (val != 1 || precios[idx] < 0) {
                while (getchar() != '\n');
                printf("  Precio invalido. Ingrese un valor positivo: ");
            }
        } while (val != 1 || precios[idx] < 0);
    }

    printf("\n>>> Productos agregados exitosamente.\n");
    return cantidadActual + n;
}


float calcularTotal(float precios[], int cantidad) {
    float total = 0;
    for (int i = 0; i < cantidad; i++)
        total += precios[i];
    return total;
}

float calcularPromedio(float precios[], int cantidad) {
    return calcularTotal(precios, cantidad) / cantidad;
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
    char nombreBuscado[50];
    while (getchar() != '\n');
    fgets(nombreBuscado, 30, stdin);
    nombreBuscado[strcspn(nombreBuscado, "\n")] = '\0';  

    for (int i = 0; i < cantidad; i++) {
        if (strcmp(nombres[i], nombreBuscado) == 0) {
            printf("Producto encontrado: %s - Precio: %.2f\n", nombres[i], precios[i]);
            return;
        }
    }
    printf("Producto no encontrado.\n");
}
