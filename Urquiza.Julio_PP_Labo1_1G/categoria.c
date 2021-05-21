#include "categoria.h"


int buscarCategoriaPorId(eCategoria categoria[],int tamcat,int id)
{
    int retorno=-1;

    for(int i=0; i<tamcat; i++)
    {
        if(categoria[i].id==id)
        {
            retorno=i;
            break;
        }
    }
    return retorno;

}
