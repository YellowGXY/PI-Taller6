#ifndef INVENTARIO_H
#define INVENTARIO_H

int ingresarDatos(char nombres[][30], float precios[]);
float calcularTotal(float precios[], int cantidad);
float calcularPromedio(float precios[], int cantidad);
int encontrarMasCaro(float precios[], int cantidad);
int encontrarMasBarato(float precios[], int cantidad);
void buscarProducto(char nombres[][30], float precios[], int cantidad);

#endif
