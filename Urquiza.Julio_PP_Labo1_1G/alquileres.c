#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alquileres.h"
#include "juego.h"
#include "cliente.h"
#include "categoria.h"
#include "datawarehouseAlquileres.h"



void inicializaraAlquileres(eAlquiler alquiler[],int tama)
{
    for(int i=0; i<tama; i++)
    {
        alquiler[i].isEmpty=0;
    }
}

int altaAlquiler(int* codigo,
                 eAlquiler alquiler[],int tama,
                 eCliente clientes[],int tamc,
                 eJuego juegos[],int tamj,
                 eCategoria categoria[],int tamcat,
                 eLocalidad localidades[],int taml)
{
    int retorno=0;
    int indice;
    eAlquiler auxAlquiler;
    if (alquiler!=NULL && tama>0 && codigo!=NULL)
    {
        indice=buscarClienteLibre(clientes,tamc);
        if (indice==-1)
        {
            printf("no hay lugar en el sistema\n");
        }
        else
        {
            printf("Nuevo alquiler:\n\n");
            printf("id: %d\n",*codigo);
            auxAlquiler.codigoAlquiler=*codigo;
            //mostrar juegos
            mostrarJuegos(juegos,tamj,categoria,tamcat);
            printf("Ingrese el codigo del jueogo que desea rentar: ");
            scanf("%d",&auxAlquiler.codigoJuego);
            //mostrar clientes
            mostrarClientes(clientes,tamc,localidades,taml);
            printf("Ingrese el codigo del cliente que lo desea rentar: ");
            scanf("%d",&auxAlquiler.codigoCliente);
            printf("Ingrese la fecha: ");
            scanf("%d/%d/%d",&auxAlquiler.fecha.dia
                            ,&auxAlquiler.fecha.mes
                            ,&auxAlquiler.fecha.anio);
            auxAlquiler.isEmpty=1;
            alquiler[indice]=auxAlquiler;
            (*codigo)++;
            retorno=1;
        }
    }
    return retorno;
}

int buscarAlquilerLibre(eAlquiler alquiler[],int tama)
{
    int retorno=-1;
    if (alquiler!=NULL && tama>0)
    {
        for(int i=0; i<tama; i++)
        {
            if(!alquiler[i].isEmpty)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

void mostrarAlquileres( eAlquiler alquiler[],int tama,
                        eCliente clientes[],int tamc,
                        eJuego juegos[],int tamj,
                        eCategoria categoria[],int tamcat,
                        eLocalidad localidades[],int taml)
{
    int indiceJuego;
    int indiceCliente;
    int indiceLocalidad;
    int indiceCategoria;
    int flag=0;
    printf("lista de alquileres:\n");
    printf("%10s %10s %10s %10s %10s %10s %15s \n"
           ,"codigo"
           ,"juego"
           ,"categoria"
           ,"nombre"
           ,"apellido"
           ,"fecha"
           ,"localidad");

    for(int i=0; i<tama; i++)
    {
        if(alquiler[i].isEmpty)
        {
            indiceJuego=buscarJuegoPorCodigo(juegos,tamj,alquiler[i].codigoJuego);
            indiceCategoria=buscarCategoriaPorId(categoria,tamcat,juegos[indiceJuego].idCategoria);
            indiceCliente=buscarClientePorId(clientes,tamc,alquiler[i].codigoCliente);
            indiceLocalidad=buscarLocalidadPorId(localidades,taml,clientes[indiceCliente].idLocalidad);
            mostrarUnAlquiler(alquiler[i],juegos[indiceJuego],categoria[indiceCategoria],clientes[indiceCliente],localidades[indiceLocalidad]);
            flag=1;
        }
    }
    if(!flag)
    {
        printf("no hay alquileres que mostrar\n");
    }
}

void mostrarUnAlquiler(eAlquiler alquiler,eJuego juego,eCategoria categoria,eCliente cliente,eLocalidad localidad)
{
    printf("%10d %10s %10s %10s %10s %02d/%02d/%4d %15s\n"
           ,alquiler.codigoAlquiler
           ,juego.descripcion
           ,categoria.descripcion
           ,cliente.nombre
           ,cliente.apelldio
           ,alquiler.fecha.dia
           ,alquiler.fecha.mes
           ,alquiler.fecha.anio
           ,localidad.descripcion);
}

int bajaAlquiler(eAlquiler alquiler[],int tama)
{
    int retorno=0;
    int codigo;
    int indice;
    if (alquiler!=NULL && tama>0)
    {
        printf("\n");
        printf("\nIngrese el codigo del alquiler que desea dar de baja:");
        scanf("%d",&codigo);
        indice=buscarAlquilerPorId(alquiler,tama,codigo);
        if(indice==-1)
        {
            printf("No hay un alquiler con ese codigo\n");
        }
        else
        {
            alquiler[indice].isEmpty=0;
            retorno=1;
            printf("Alquiler eliminado exitosamente\n");
        }
    }
    return retorno;
}

int buscarAlquilerPorId(eAlquiler alquiler[],int tama,int codigo)
{
    int retorno=-1;

    for(int i=0; i<tama; i++)
    {
        if(alquiler[i].codigoAlquiler==codigo && alquiler[i].isEmpty)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

int hardcodearAlquileres(eAlquiler alquileres[],int tama,int cantidad)
{
    int retorno=0;
    if(alquileres!=NULL && tama>0 && cantidad<=tama && cantidad>0)
    {
        for(int i=0;i<cantidad;i++)
        {
            alquileres[i]=dataAlquileres[i];
        }
        retorno=1;
    }
    return retorno;
}

int buscarAlquilerPorCodigoCliente(eAlquiler alquiler[],int tama,int codigoCliente)
{
    int retorno=-1;

    for(int i=0; i<tama; i++)
    {
        if(alquiler[i].codigoCliente==codigoCliente && alquiler[i].isEmpty)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
