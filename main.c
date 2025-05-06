#include <stdio.h>

#define MAX_PRODUCTOS 10

// Declaraciones de funciones (porque no se usará funciones.h)
void ingresarProductos(char nombres[][30], float precios[], int cantidad);
float calcularTotal(float precios[], int cantidad);
float calcularPromedio(float precios[], int cantidad);
int buscarProducto(char nombres[][30], float precios[], int cantidad, char nombreBuscado[]);
int encontrarMasCaro(float precios[], int cantidad);
int encontrarMasBarato(float precios[], int cantidad);

int main() {
    char nombres[MAX_PRODUCTOS][30];
    float precios[MAX_PRODUCTOS];
    int cantidad;

    printf("¿Cuántos productos desea ingresar? (máx 10): ");
    scanf("%d", &cantidad);

    if (cantidad < 1 || cantidad > MAX_PRODUCTOS) {
        printf("Cantidad in\'valida.\n");
        return 1;
    }

    ingresarProductos(nombres, precios, cantidad);

    printf("\nTotal del inventario: %.2f\n", calcularTotal(precios, cantidad));
    printf("Precio promedio: %.2f\n", calcularPromedio(precios, cantidad));

    int caro = encontrarMasCaro(precios, cantidad);
    int barato = encontrarMasBarato(precios, cantidad);

    printf("Producto \'mas caro: %s (%.2f)\n", nombres[caro], precios[caro]);
    printf("Producto \'mas barato: %s (%.2f)\n", nombres[barato], precios[barato]);

    char buscado[30];
    printf("\nIngrese el nombre del producto a buscar: ");
    scanf(" %[^\n]", buscado);
    buscarProducto(nombres, precios, cantidad, buscado);

    return 0;
}
