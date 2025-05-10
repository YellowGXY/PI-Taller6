void mostrarMenu();

int ingresarDatos(char nombres[][30], float precios[], int stocks[]);
int eliminarProducto(char nombres[][30], float precios[], int stocks[], int cantidad);

float calcularTotal(float precios[], int stocks[], int cantidad);
float calcularPromedio(float precios[], int stocks[], int cantidad);

int encontrarMasCaro(float precios[], int stocks[], int cantidad);
int encontrarMasBarato(float precios[], int stocks[], int cantidad);

int buscarProducto(char nombres[][30], float precios[], int stocks[], int cantidad);
void agregarStock(char nombres[][30], float precios[], int stocks[], int cantidad);
