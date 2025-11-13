#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//Funcion para buscar producto por nombre
bool BuscarProd(char entrada[], char fabricacion[][25])
{
    bool encontrado = 0;
    for (int i = 0; i < 5; i++)
    {

        if (strcmp(entrada, fabricacion[i]) == 0)
        {
            encontrado = 1;
            return encontrado;
            break;
        }
    }
    if (encontrado == 0)
    {
        printf("\n Producto no encontrado.");
        return encontrado;
    }
}