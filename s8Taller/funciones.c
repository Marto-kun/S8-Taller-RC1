#include <stdio.h>
#include <string.h>
#include "funciones.h"

int leerEnteroPositivo(){
    int x;
    while(1){
        if(scanf("%d", &x) != 1 || x < 0){
            printf("Error: ingrese un entero positivo valido: ");
            while(getchar() != '\n'); 
        } else {
            while(getchar() != '\n');
            return x;
        }
    }
}

float leerFloatPositivo(){
    float x;
    while(1){
        if(scanf("%f", &x) != 1 || x < 0){
            printf("Error: ingrese un numero positivo valido: ");
            while(getchar() != '\n');
        } else {
            while(getchar() != '\n');
            return x;
        }
    }
}

void leerCadena(char *str){
    while(1){
        scanf("%s", str);

        if(esVacia(str)){
            printf("Error: el nombre no puede estar vacío. Intente de nuevo: ");
            continue;
        }
        return;
    }
}

void ingresarProductos(char nombres[][STR], int cantidades[], float tiempos[], int recursos[]) {
    for(int i = 0; i < MAX; i++){
        while(1){
            printf("Producto %d nombre: ", i+1);
            leerCadena(nombres[i]);

            if(existeNombre(nombres, nombres[i]) == 1){
                int rep = 0;
                for(int j = 0; j < i; j++){
                    if(strcmp(nombres[i], nombres[j]) == 0){
                        rep = 1;
                        break;
                    }
                }

                if(rep){
                    printf("Error: ya existe un producto con ese nombre. Intente otro.\n");
                    continue;
                }
            }

            break;
        }

        printf("Cantidad demandada: ");
        cantidades[i] = leerEnteroPositivo();

        printf("Tiempo de fabricacion (horas): ");
        tiempos[i] = leerFloatPositivo();

        printf("Recursos requeridos: ");
        recursos[i] = leerEnteroPositivo();

        printf("\n");
    }
}

int buscarProducto(char nombres[][STR], char nombreBuscado[]){
    for(int i = 0; i < MAX; i++){
        if(strcmp(nombres[i], nombreBuscado) == 0){
            return i;
        }
    }
    return -1;
}

void editarProducto(char nombres[][STR], int cantidades[], float tiempos[], int recursos[]) {
    char buscar[STR];
    printf("Nombre del producto a editar: ");
    leerCadena(buscar);

    int pos = buscarProducto(nombres, buscar);
    if(pos == -1){
        printf("Producto no encontrado.\n");
        return;
    }

    char nuevo[STR];

    while(1){
        printf("Nuevo nombre: ");
        leerCadena(nuevo);

        int existe = 0;
        for(int i = 0; i < MAX; i++){
            if(i != pos && strcmp(nombres[i], nuevo) == 0){
                existe = 1;
                break;
            }
        }

        if(existe){
            printf("Error: ya existe un producto con ese nombre. Intente otro.\n");
        } else {
            break;
        }
    }

    strcpy(nombres[pos], nuevo);

    printf("Nueva cantidad: ");
    cantidades[pos] = leerEnteroPositivo();

    printf("Nuevo tiempo: ");
    tiempos[pos] = leerFloatPositivo();

    printf("Nuevo recurso: ");
    recursos[pos] = leerEnteroPositivo();
}

void eliminarProducto(char nombres[][STR], int cantidades[], float tiempos[], int recursos[]) {
    char buscar[STR];
    printf("Nombre del producto a eliminar: ");
    leerCadena(buscar);

    int pos = buscarProducto(nombres, buscar);
    if(pos == -1){
        printf("Producto no encontrado.\n");
        return;
    }

    nombres[pos][0] = '\0';
    cantidades[pos] = 0;
    tiempos[pos] = 0;
    recursos[pos] = 0;

    printf("Producto eliminado.\n");
}

void calcularTotales(int cantidades[], float tiempos[], int recursos[], float *tiempoTotal, int *recursosTotales){
    *tiempoTotal = 0;
    *recursosTotales = 0;

    for(int i = 0; i < MAX; i++){
        *tiempoTotal += cantidades[i] * tiempos[i];
        *recursosTotales += cantidades[i] * recursos[i];
    }
}

int puedeProducir(float tiempoTotal, int recursosTotales, float tiempoDisp, int recursosDisp){
    return (tiempoTotal <= tiempoDisp && recursosTotales <= recursosDisp);
}

int existeNombre(char nombres[][STR], char nombre[]){
    for(int i = 0; i < MAX; i++){
        if(strcmp(nombres[i], nombre) == 0){
            return 1;
        }
    }
    return 0;
}

int esVacia(char *str){
    if(str[0] == '\0') return 1;
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] != ' ' && str[i] != '\t') return 0; 
    }
    return 1;
}
