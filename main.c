#include <stdio.h>
#include "validaciones.h"

int main(int argc, char *argv[])
{

    char entrada[25];
    char productos[5][25];   // Inicializacion de matriz para nombres de productos
    float fabricacion[5][2]; // Inicializacion de matriz para tiempo y recursos de fabricacion

    printf("### Programa de Fabricacion y Gestion de Recursos ###");

    // Ingreso de nombres al programa:
    for (int i = 0; i < 5; i++)
    {

        int nombreValido = 0;
        do
        {
            printf("\nIngresar el nombre del producto #%i: ", i + 1);
            if (fgets(entrada, 25, stdin) == NULL)
            {
                LimpiarBuffer();
                nombreValido = 0;
                continue;
            }

            // Eliminar el salto de línea al final de la cadena
            entrada[strcspn(entrada, "\n")] = '\0';

            if (VerificacionChar(entrada) == 1)
            {
                strcpy(productos[i], entrada);
                nombreValido = 1;
            }
            else
            {
                printf("\nSolo se permiten letras. Intentelo de nuevo.");
                nombreValido = 0;
            }

        } while (nombreValido == 0);
    }

    // Ingreso de tiempos de fabricacion -> fabricacion[i][0]
    for (int i = 0; i < 5; i++)
    {
        int tiempoValido = 0;
        do
        {
            printf("\nIngrese el tiempo de fabricacion de %s: ", productos[i]);
            if (fgets(entrada, 25, stdin) == NULL)
            {
                LimpiarBuffer();
                continue;
            }

            // Eliminar el salto de línea al final de la cadena
            entrada[strcspn(entrada, "\n")] = '\0';

            if (VerificacionFloat(entrada) == 1)
            {
                float tiempoIngresado = atof(entrada);

                if (tiempoIngresado > 0)
                {
                    fabricacion[i][0] = tiempoIngresado;
                    tiempoValido = 1;
                }
            }
            else
            {
                printf("\nSolo se permiten numeros positivos. Intentelo de nuevo.");
            }

        } while (tiempoValido == 0);
    }
    
    //Ingreso de recursos de fabricacion -> fabricacion[i][1]
    for (int i = 0; i < 5; i++)
    {
        int recursosValido = 0;
        do
        {
            printf("\nIngrese los recursos de fabricacion de %s: ", productos[i]);
            if (fgets(entrada, 25, stdin) == NULL)
            {
                LimpiarBuffer();
                continue;
            }

            // Eliminar el salto de línea al final de la cadena
            entrada[strcspn(entrada, "\n")] = '\0';

            if (VerificacionFloat(entrada) == 1)
            {
                float recursosIngresados = atof(entrada);

                if (recursosIngresados > 0)
                {
                    fabricacion[i][1] = recursosIngresados;
                    recursosValido = 1;
                }
            }
            else
            {
                printf("\nSolo se permiten numeros positivos. Intentelo de nuevo.");
            }

        } while (recursosValido == 0);
    }

    return 0;
}