#include <stdio.h>
#include "funciones.h"

int main() {
    char nombres[10][30] = {"", "", "", "", "", "", "", "", "", ""};
    float precios[10] = {0};
    int stocks[10] = {0};
    int cantidad = 0;
    int opcion, val;

    do {
        mostrarMenu();
        do {
            val = scanf("%d", &opcion);
            while (getchar() != '\n');
            if (val != 1 || opcion < 0 || opcion > 8) {
                printf("El valor ingresado no es correcto. \nIngrese nuevamente: ");
            }
        } while (val != 1 || opcion < 0 || opcion > 8);

        printf("\n------------------------------\n");

        switch (opcion) {
            case 1:
                cantidad = ingresarDatos(nombres, precios, stocks);
                break;
            case 2:
                if (cantidad > 0) {
                    printf("Precio total del inventario: %.2f\n", calcularTotal(precios, stocks, cantidad));
                } else {
                    printf("Debe ingresar los datos primero.\n");
                }
                break;
            case 3:
                if (cantidad > 0) {
                    printf("Precio promedio ponderado: %.2f\n", calcularPromedio(precios, stocks, cantidad));
                } else {
                    printf("Debe ingresar los datos primero.\n");
                }
                break;
            case 4:
                if (cantidad > 0) {
                    int indiceMax = encontrarMasCaro(precios, stocks, cantidad);
                    printf("Producto más caro: %s (%.2f, stock: %d)\n", nombres[indiceMax], precios[indiceMax], stocks[indiceMax]);
                } else {
                    printf("Debe ingresar los datos primero.\n");
                }
                break;
            case 5:
                if (cantidad > 0) {
                    int indiceMin = encontrarMasBarato(precios, stocks, cantidad);
                    printf("Producto más barato: %s (%.2f, stock: %d)\n", nombres[indiceMin], precios[indiceMin], stocks[indiceMin]);
                } else {
                    printf("Debe ingresar los datos primero.\n");
                }
                break;
            case 6:
                if (cantidad > 0) {
                    buscarProducto(nombres, precios, stocks, cantidad);
                } else {
                    printf("Debe ingresar los datos primero.\n");
                }
                break;
            case 7:
                if (cantidad > 0) {
                    cantidad = eliminarProducto(nombres, precios, stocks, cantidad);
                } else {
                    printf("Debe ingresar los datos primero.\n");
                }
                break;
            case 8:
                if (cantidad > 0) {
                    agregarStock(nombres, precios, stocks, cantidad);
                } else {
                    printf("Debe ingresar los datos primero.\n");
                }
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Intente nuevamente.\n");
                break;
        }

        printf("------------------------------\n");

    } while (opcion != 0);

    return 0;
}
