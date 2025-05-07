#include <stdio.h>
#include "funciones.h"

int main() {
    char nombres[10][30] = {"", "", "", "", "", "", "", "", "", ""};
    float precios[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int cantidad = 0;
    int opcion, val;

    do {
        printf("\n=== MENU DE INVENTARIO ===\n");
        printf("1. Ingresar datos\n");
        printf("2. Mostrar precio total\n");
        printf("3. Mostrar precio promedio\n");
        printf("4. Mostrar producto mas caro\n");
        printf("5. Mostrar producto mas barato\n");
        printf("6. Buscar producto por nombre\n");
        printf("7. Eliminar producto\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");

        do {
            val = scanf("%d", &opcion);
            while (getchar() != '\n'); 
            if (val != 1) {
                printf("El valor ingresado no es correcto. \nIngrese nuevamente: ");
            }
        } while (val != 1);

        printf("\n------------------------------\n");  

        switch (opcion) {
            case 1:
                cantidad = ingresarDatos(nombres, precios);
                break;
            case 2:
                if (cantidad > 0){
                    printf("Precio total del inventario: %.2f\n", calcularTotal(precios, cantidad));
                }else{
                    printf("Debe ingresar los datos primero.\n");
                }
                break;
            case 3:
                if (cantidad > 0){
                    printf("Precio promedio: %.2f\n", calcularPromedio(precios, cantidad));
                }else{
                    printf("Debe ingresar los datos primero.\n");
                }
                break;
            case 4:
                if (cantidad > 0) {
                    int indiceMax = encontrarMasCaro(precios, cantidad);
                    printf("Producto mas caro: %s (%.2f)\n", nombres[indiceMax], precios[indiceMax]);
                } else {
                    printf("Debe ingresar los datos primero.\n");
                }
                break;
            case 5:
                if (cantidad > 0) {
                    int indiceMin = encontrarMasBarato(precios, cantidad);
                    printf("Producto mas barato: %s (%.2f)\n", nombres[indiceMin], precios[indiceMin]);
                } else {
                    printf("Debe ingresar los datos primero.\n");
                }
                break;
            case 6:
                if (cantidad > 0){
                    buscarProducto(nombres, precios, cantidad);
                }else{
                    printf("Debe ingresar los datos primero.\n");
                }
                break;
            case 7:
                if (cantidad > 0){
                    cantidad = eliminarProducto(nombres, precios, cantidad);
                }else{
                    printf("Debe ingresar los datos primero.\n");
                }
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida. Intente nuevamente.\n");
                break;
        }

        printf("------------------------------\n");  

    } while (opcion != 0);

    return 0;
}
