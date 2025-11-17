#include <stdio.h>
#include "funciones.h"

int main(){
    char nombres[MAX][STR];
    int cantidades[MAX];
    float tiempos[MAX];
    int recursos[MAX];

    float tiempoDisp;
    int recursosDisp;
    int opcion;

    printf("Tiempo disponible en horas: ");
    tiempoDisp = leerFloatPositivo();

    printf("Recursos disponibles: ");
    recursosDisp = leerEnteroPositivo();

    ingresarProductos(nombres, cantidades, tiempos, recursos);

    do {
        printf("\nMENU\n");
        printf("1. Editar producto\n");
        printf("2. Eliminar producto\n");
        printf("3. Calcular totales\n");
        printf("4. Salir\n");
        printf("Opcion: ");

        opcion = leerEnteroPositivo();

        if(opcion == 1){
            editarProducto(nombres, cantidades, tiempos, recursos);
        }
        else if(opcion == 2){
            eliminarProducto(nombres, cantidades, tiempos, recursos);
        }
        else if(opcion == 3){
            float tiempoTotal;
            int recursosTotales;

            calcularTotales(cantidades, tiempos, recursos, &tiempoTotal, &recursosTotales);

            printf("\nTiempo total requerido: %.2f\n", tiempoTotal);
            printf("Recursos totales requeridos: %d\n", recursosTotales);

            if(puedeProducir(tiempoTotal, recursosTotales, tiempoDisp, recursosDisp)){
                printf("La fabrica PUEDE cumplir con la demanda.\n");
            } else {
                printf("La fabrica NO PUEDE cumplir con la demanda.\n");
            }
        }
        else if(opcion != 4){
            printf("Opcion invalida. Intente nuevamente.\n");
        }

    } while(opcion != 4);

    return 0;
}
