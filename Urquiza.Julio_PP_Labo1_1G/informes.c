#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"
#include "cliente.h"
#include "alquileres.h"

void mostrarJuegosCategoriaMesa(eJuego juegos[],int tamj,eCategoria categorias[],int tamcat)
{
    if(juegos!=NULL && tamj>0 && categorias!=NULL && tamcat>0)
    {
        printf("1.Lista de juegos de mesa: ");
        for (int i=0;i<tamj;i++)
        {
            if(juegos[i].idCategoria==categorias[0].id)
            {
             printf("%s,",juegos[i].descripcion);
            }
        }
        printf("\n");
    }
}

void mostrarAlquileresDeClientes(   eAlquiler alquiler[],int tama,
                                    eCliente clientes[],int tamc,
                                    eJuego juegos[],int tamj,
                                    eCategoria categoria[],int tamcat,
                                    eLocalidad localidades[],int taml)
{
    if(clientes!=NULL && tamc>0 && alquiler!=NULL && tama>0)
    {
        int indiceJuego;
        int indiceCategoria;
        int indiceCliente;
        int indiceLocalidad;
        int idCliente;
        printf("2.listar alquileres de un cliente: \n");
        mostrarClientes(clientes,tamc,localidades,taml);
        printf("ingrese un cliente: ");
        scanf("%d",&idCliente);
        printf("alquileres: \n");
        for(int i=0;i<tama;i++)
        {
            if(alquiler[i].codigoCliente==idCliente && alquiler[i].isEmpty)
            {
                indiceJuego=buscarJuegoPorCodigo(juegos,tamj,alquiler[i].codigoJuego);
                indiceCategoria=buscarCategoriaPorId(categoria,tamcat,juegos[indiceJuego].idCategoria);
                indiceCliente=buscarClientePorId(clientes,tamc,alquiler[i].codigoCliente);
                indiceLocalidad=buscarLocalidadPorId(localidades,taml,clientes[indiceCliente].idLocalidad);
                mostrarUnAlquiler(alquiler[i],juegos[indiceJuego],categoria[indiceCategoria],clientes[indiceCliente],localidades[indiceLocalidad]);
            }
        }

    }
}

void mostrarImporteDeCliente(   eAlquiler alquiler[],int tama,
                                eCliente clientes[],int tamc,
                                eJuego juegos[],int tamj,
                                eLocalidad localidades[],int taml)
{
    if(clientes!=NULL && tamc>0 && alquiler!=NULL && tama>0)
    {
        int indiceJuego;
        float AcumuladorImporte=0;
        int idCliente;
        printf("3.listar importe pagado por un cliente: \n");
        mostrarClientes(clientes,tamc,localidades,taml);
        printf("ingrese un cliente: ");
        scanf("%d",&idCliente);
        for(int i=0;i<tama;i++)
        {
            if(alquiler[i].codigoCliente==idCliente && alquiler[i].isEmpty)
            {
                indiceJuego=buscarJuegoPorCodigo(juegos,tamj,alquiler[i].codigoJuego);
                AcumuladorImporte+=juegos[indiceJuego].importe;

            }
        }
        printf("Deve pagar en total: %.2f\n ",AcumuladorImporte);
    }
}

void mostrarjuegosAlquiladosPorMujeres( eAlquiler alquiler[],int tama,
                                        eCliente clientes[],int tamc,
                                        eJuego juegos[],int tamj)
{
    if(clientes!=NULL && tamc>0 && alquiler!=NULL && tama>0 && juegos!=NULL && tamj>0)
    {
        //7- Listar los juegos alquilados por mujeres
        int indiceCliente;
        int indiceJuego;
        int flag=0;
        printf("7.Juegos alquilados por mujeres: \n");
        for(int i=0;i<tama;i++)
        {
            indiceCliente=buscarClientePorId(clientes,tamc,alquiler[i].codigoCliente);
            if(clientes[indiceCliente].sexo=='f' && alquiler[i].isEmpty)
            {
                indiceJuego=buscarJuegoPorCodigo(juegos,tamj,alquiler[i].codigoJuego);
                printf("%s\n",juegos[indiceJuego].descripcion);
                flag=1;
            }
        }
        if(!flag)
        {
            printf("no hay juegos alquilados por mujeres\n");
        }
    }
}

void mostrarClientesDeUnaLocalidad(eCliente clientes[],int tamc,eLocalidad localidades[],int taml)
{
    if(clientes!=NULL && tamc>0 && localidades!=NULL && taml>0)
    {
        int flag=0;
        int idLocalidad;
        printf("11.Mostrar Empleados por localidad elegida\n");
        mostrarLocalidades(localidades,taml);
        printf("ingrese una localidad: ");
        scanf("%d",&idLocalidad);
        for(int i=0;i<tamc;i++)
        {
            if(clientes[i].idLocalidad==idLocalidad)
            {
                printf("%10d %10s %10s %5c %10s\n"
                       ,clientes[i].codigo
                       ,clientes[i].apelldio
                       ,clientes[i].nombre
                       ,clientes[i].sexo
                       ,clientes[i].telefono);
                flag=1;
            }
        }
        if (!flag)
        {
            printf("no hay empleado en esa localidad\n");
        }
    }
}
