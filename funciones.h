#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//Funcion para buscar producto por nombre
int BuscarProd(char entrada[], char *productos[][25])
{
    bool encontrado = false;
    for (int i = 0; i < 5; i++)
    {

        if (strcmp(entrada, *productos[i]) == 0)
        {
            encontrado = true;
            return i;
            break;
        }
    }
    if (encontrado == false)
    {
        return -1;
    }
}


//Funcion para eliminar productos
void EliminarProd(char entrada[],char *productos[][25], float *fabricacion[][2]){
    int encontrado = BuscarProd(entrada, productos); // Se busca el producto a eliminar
    if(encontrado != -1){
        *productos[encontrado] = "\0";
        fabricacion[encontrado][0] = 0;
        fabricacion[encontrado][1] = 0;
    }
}