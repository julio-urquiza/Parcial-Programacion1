#include "fecha.h"
#include "cliente.h"
#include "juego.h"
#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED

typedef struct{
    int codigoAlquiler;
    int codigoJuego;
    int codigoCliente;
    eFecha fecha;
    int isEmpty;
}eAlquiler;

#endif // ALQUILERES_H_INCLUDED

void inicializaraAlquileres(eAlquiler alquiler[],int tama);
int altaAlquiler(int* codigo,
                 eAlquiler alquiler[],int tama,
                 eCliente clientes[],int tamc,
                 eJuego juegos[],int tamj,
                 eCategoria categoria[],int tamcat,
                 eLocalidad localidades[],int taml);
int buscarAlquilerLibre(eAlquiler alquiler[],int tama);
void mostrarAlquileres( eAlquiler alquiler[],int tama,
                        eCliente clientes[],int tamc,
                        eJuego juegos[],int tamj,
                        eCategoria categoria[],int tamcat,
                        eLocalidad localidades[],int taml);
void mostrarUnAlquiler(eAlquiler alquiler,eJuego juego,eCategoria categoria,eCliente cliente,eLocalidad localidad);
int bajaAlquiler(eAlquiler alquiler[],int tama);
int buscarAlquilerPorId(eAlquiler alquiler[],int tama,int codigo);
int hardcodearAlquileres(eAlquiler alquileres[],int tama,int cantidad);
int buscarAlquilerPorCodigoCliente(eAlquiler alquiler[],int tama,int codigoCliente);
