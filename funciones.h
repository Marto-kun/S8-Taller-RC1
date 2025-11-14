#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//Funcion para buscar producto por nombre
bool BuscarProd(char entrada[], char productos[][25])
{
    bool encontrado = false;
    for (int i = 0; i < 5; i++)
    {

        if (strcmp(entrada, productos[i]) == 0)
        {
            encontrado = true;
            return encontrado;
            break;
        }
    }
    if (encontrado == false)
    {
        return encontrado;
    }
}