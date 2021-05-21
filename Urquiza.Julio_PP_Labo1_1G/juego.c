#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "juego.h"
#include "categoria.h"


void mostrarJuegos(eJuego juegos[],int tamj,eCategoria categoria[],int tamcat)
{
    int indiceC;
    int flag=0;
    printf("lista de clientes:\n");
    printf("%10s %10s %10.2s %10s\n"
           ,"codigo"
           ,"descripcion"
           ,"importe"
           ,"categoria");

    for(int i=0; i<tamj; i++)
    {
        indiceC=buscarCategoriaPorId(categoria,tamcat,juegos[i].codigo);
        mostrarUnJuego(juegos[i],categoria[indiceC]);
        flag=1;
    }
    if(!flag)
    {
        printf("no hay alquileres que mostrar\n");
    }
}

void mostrarUnJuego(eJuego juegos,eCategoria categoria)
{
    printf("%10d %10s %10.2f %5s \n"
           ,juegos.codigo
           ,juegos.descripcion
           ,juegos.importe
           ,categoria.descripcion);
}

int buscarJuegoPorCodigo(eJuego juegos[],int tamj,int codigo)
{
    int retorno=-1;

    for(int i=0; i<tamj; i++)
    {
        if(juegos[i].codigo==codigo)
        {
            retorno=i;
            break;
        }
    }
    return retorno;

}
