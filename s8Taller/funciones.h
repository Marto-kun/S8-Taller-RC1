#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX 5
#define STR 30

int leerEnteroPositivo();
float leerFloatPositivo();
void leerCadena(char *str);

void ingresarProductos(char nombres[][STR], int cantidades[], float tiempos[], int recursos[]);
void editarProducto(char nombres[][STR], int cantidades[], float tiempos[], int recursos[]);
void eliminarProducto(char nombres[][STR], int cantidades[], float tiempos[], int recursos[]);
int buscarProducto(char nombres[][STR], char nombreBuscado[]);
void calcularTotales(int cantidades[], float tiempos[], int recursos[], float *tiempoTotal, int *recursosTotales);
int puedeProducir(float tiempoTotal, int recursosTotales, float tiempoDisp, int recursosDisp);
int existeNombre(char nombres[][STR], char nombre[]);
int esVacia(char *str);

#endif
