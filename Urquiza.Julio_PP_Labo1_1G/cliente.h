#include "localidad.h"
#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{
    int codigo;
    char nombre[51];
    char apelldio[51];
    char sexo;
    char telefono[21];
    int isEmpty;
    int idLocalidad;
}eCliente;

#endif // CLIENTE_H_INCLUDED


int altaCliente(eCliente clientes[],int tamc,int* codigo,eLocalidad localidades[],int taml);
int buscarClienteLibre(eCliente clientes[],int tamc);
void inicializarCliente(eCliente clientes[],int tamc);
int modificarCliente(eCliente clientes[],int tamc,eLocalidad localidades[],int taml);
int buscarClientePorId(eCliente clientes[],int tamc,int codigo);
int bajaCliente(eCliente clientes[],int tamc,eLocalidad localidades[],int taml);
void mostrarClientes(eCliente clientes[],int tamc,eLocalidad localidades[],int taml);
void mostrarUnCliente(eCliente clientes,eLocalidad localidad);
void ordenarClientes(eCliente clientes[],int tamc);
int hardcodearClientes(eCliente clientes[],int tamc,int cantidad);
