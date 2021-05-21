#include "categoria.h"
#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

typedef struct{
    int codigo;
    char descripcion[51];
    float importe;
    int idCategoria;
}eJuego;

#endif // JUEGO_H_INCLUDED

void mostrarJuegos(eJuego juegos[],int tamj,eCategoria categoria[],int tamcat);
void mostrarUnJuego(eJuego juegos,eCategoria categoria);
int buscarJuegoPorCodigo(eJuego juegos[],int tamj,int codigo);
