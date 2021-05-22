#include "cliente.h"
#include "alquileres.h"
#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#endif // INFORMES_H_INCLUDED
void mostrarJuegosCategoriaMesa(eJuego juegos[],int tamj,eCategoria categorias[],int tamcat);
void mostrarAlquileresDeClientes(   eAlquiler alquiler[],int tama,
                                    eCliente clientes[],int tamc,
                                    eJuego juegos[],int tamj,
                                    eCategoria categoria[],int tamcat,
                                    eLocalidad localidades[],int taml);
void mostrarImporteDeCliente(   eAlquiler alquiler[],int tama,
                                eCliente clientes[],int tamc,
                                eJuego juegos[],int tamj,
                                eLocalidad localidades[],int taml);
void mostrarjuegosAlquiladosPorMujeres( eAlquiler alquiler[],int tama,
                                        eCliente clientes[],int tamc,
                                        eJuego juegos[],int tamj);
void mostrarClientesDeUnaLocalidad(eCliente clientes[],int tamc,eLocalidad localidades[],int taml);
