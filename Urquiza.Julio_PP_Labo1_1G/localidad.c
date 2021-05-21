#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "localidad.h"

int buscarLocalidadPorId(eLocalidad localidades[],int taml,int id)
{
    int retorno=-1;
    for(int i=0; i<taml; i++)
    {
        if(localidades[i].id==id)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

void mostrarLocalidades(eLocalidad localidades[],int taml)
{
    int flag=0;
    printf("lista de localidades:\n");
    printf("%10s %10s \n"
           ,"id"
           ,"descripcion");

    for(int i=0; i<taml; i++)
    {
        mostrarUnaLocalidad(localidades[i]);
        flag=1;
    }
    if(!flag)
    {
        printf("no hay alquileres que mostrar\n");
    }
}

void mostrarUnaLocalidad(eLocalidad localidad)
{
    printf("%10d %10s \n"
           ,localidad.id
           ,localidad.descripcion);
}
