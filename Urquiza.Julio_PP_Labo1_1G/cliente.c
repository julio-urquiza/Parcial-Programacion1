#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "datawarehouseClientes.h"
#include "localidad.h"


int altaCliente(eCliente clientes[],int tamc,int* codigo,eLocalidad localidades[],int taml)
{
    int retorno=0;
    int indice;
    eCliente auxCliente;
    if (clientes!=NULL && tamc>0 && codigo!=NULL && localidades!=NULL && taml>0)
    {
        indice=buscarClienteLibre(clientes,tamc);
        if (indice==-1)
        {
            printf("no hay lugar en el sisteman\n");
        }
        else
        {
            printf("Carga de clientes:\n\n");
            mostrarLocalidades(localidades,taml);
            printf("Ingrese la localidad: ");
            scanf("%d",&auxCliente.idLocalidad);
            printf("id: %d\n",*codigo);
            auxCliente.codigo=*codigo;
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(auxCliente.nombre);
            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(auxCliente.apelldio);
            printf("Ingrese el genero: ");
            fflush(stdin);
            scanf("%c",&auxCliente.sexo);
            printf("Ingrese el numero de telefono: ");
            fflush(stdin);
            gets(auxCliente.telefono);
            auxCliente.isEmpty=1;
            clientes[indice]=auxCliente;
            (*codigo)++;
            retorno=1;
        }
    }
    return retorno;
}

int buscarClienteLibre(eCliente clientes[],int tamc)
{
    int retorno=-1;
    if (clientes!=NULL && tamc>0)
    {
        for(int i=0; i<tamc; i++)
        {
            if(!clientes[i].isEmpty)
            {
                retorno=i;
                break;
            }
        }
    }

    return retorno;
}

void inicializarCliente(eCliente clientes[],int tamc)
{
    for(int i=0; i<tamc; i++)
    {
        clientes[i].isEmpty=0;
    }
}

int modificarCliente(eCliente clientes[],int tamc,eLocalidad localidades[],int taml)
{
    int retorno=0;
    int codigo;
    int i;
    int opcion;
    eCliente auxCliente;
    if (clientes!=NULL && tamc>0 && localidades!=NULL && taml>0)
    {
        printf("lista de clientes");
        mostrarClientes(clientes,tamc,localidades,taml);
        printf("\n");
        printf("ingrese el codigo del cliente que desea modificar: ");
        scanf("%d",&codigo);
        i=buscarClientePorId(clientes,tamc,codigo);
        auxCliente=clientes[i];
        if (i==-1)
        {
            printf("no existe el empleado que deseea modificar\n");
        }
        else
        {
            printf("opciones a modificar:\n");
            printf("1.Nombre\n2.Apellido\n3.Sexo\n4.Telefono\n");
            printf("ingrese lo que desea modificar:");
            scanf("%d",&opcion);
            switch(opcion)
            {
                case 1:
                    printf("Ingrese nuevo nombre: ");
                    fflush(stdin);
                    gets(auxCliente.nombre);
                    break;
                case 2:
                    printf("Ingrese nuevo apellido: ");
                    fflush(stdin);
                    gets(auxCliente.apelldio);
                    break;
                case 3:
                    printf("Ingrese el nuevo genero: ");
                    fflush(stdin);
                    scanf("%c",&auxCliente.sexo);
                    break;
                case 4:
                    printf("Ingrese el nuevo numero de telefono: ");
                    fflush(stdin);
                    gets(auxCliente.telefono);
                    break;
                case 5:
                    mostrarLocalidades(localidades,taml);
                    printf("Ingrese la nueva localidad: ");
                    scanf("%d",&auxCliente.idLocalidad);
                    break;
            }
            clientes[i]=auxCliente;
            retorno=1;
        }
    }
    return retorno;
}

int buscarClientePorId(eCliente clientes[],int tamc,int codigo)
{
    int retorno=-1;

    for(int i=0; i<tamc; i++)
    {
        if(clientes[i].codigo==codigo && clientes[i].isEmpty)
        {
            retorno=i;
            break;
        }
    }
    return retorno;

}

int bajaCliente(eCliente clientes[],int tamc,eLocalidad localidades[],int taml)
{
    int retorno=0;
    int codigo;
    int indice;
    if (clientes!=NULL && tamc>0)
    {
        printf("lista de clientes");
        mostrarClientes(clientes,tamc,localidades,taml);
        printf("\n");
        printf("\nIngrese el codigo del cliente que desea dar de baja:");
        scanf("%d",&codigo);
        indice=buscarClientePorId(clientes,tamc,codigo);
        if(indice==-1)
        {
            printf("no hay un cliente con ese codigo\n");
        }
        else
        {
            clientes[indice].isEmpty=0;
            retorno=1;
            printf("cliente eliminado exitosamente\n");
        }
    }
    return retorno;
}

void mostrarClientes(eCliente clientes[],int tamc,eLocalidad localidades[],int taml)
{
    int indiceLocalidad;
    int flag=0;
    printf("lista de clientes:\n");
    printf("%10s %10s %10s %5s %10s %15s \n"
           ,"codigo"
           ,"apellido"
           ,"nombre"
           ,"sexo"
           ,"telefono"
           ,"localiadad");

    for(int i=0; i<tamc; i++)
    {
        if(clientes[i].isEmpty)
        {
            indiceLocalidad=buscarLocalidadPorId(localidades,taml,clientes[i].idLocalidad);
            mostrarUnCliente(clientes[i],localidades[indiceLocalidad]);
            flag=1;
        }
    }
    if(!flag)
    {
        printf("no hay clientes que mostrar\n");
    }
}

void mostrarUnCliente(eCliente clientes,eLocalidad localidad)
{
    printf("%10d %10s %10s %5c %10s %15s \n"
           ,clientes.codigo
           ,clientes.apelldio
           ,clientes.nombre
           ,clientes.sexo
           ,clientes.telefono
           ,localidad.descripcion);
}

void ordenarClientes(eCliente clientes[],int tamc)
{
    eCliente auxCliente;
    for(int i=0; i<tamc-1; i++)
    {
        for(int j=i+1; j<tamc; j++)
        {
            //apellido alfaveticamente
            if(strcmp(clientes[i].apelldio,clientes[j].apelldio)<0)
            {
                auxCliente=clientes[i];
                clientes[i]=clientes[j];
                clientes[j]=auxCliente;
            }
        }
    }
}

int hardcodearClientes(eCliente clientes[],int tamc,int cantidad)
{
    int retorno=0;
    if(clientes!=NULL && tamc>0 && cantidad<=tamc && cantidad>0)
    {
        for(int i=0;i<cantidad;i++)
        {
            clientes[i]=dataClientes[i];
        }
        retorno=1;
    }
    return retorno;
}
