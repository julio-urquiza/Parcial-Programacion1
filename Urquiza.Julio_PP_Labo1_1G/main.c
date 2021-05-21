#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "categoria.h"
#include "cliente.h"
#include "alquileres.h"
#include "localidad.h"
#include "informes.h"

#define TAMC 10
#define TAMA 5
#define TAMJ 6
#define TAMCAT 5
#define TAML 5

int menu(void);

int main()
{
    int idC=200;
    int idA=300;

    eCategoria categorias[TAMCAT]={
        {70,"mesa"},
        {71,"azar"},
        {72,"estrategia"},
        {73,"salon"},
        {74,"magia"}};

    eJuego juegos[TAMJ]={
        {10,"ajedrez",200,70},
        {11,"bingo",250,71},
        {12,"batalla Naval",300,72},
        {13,"tejos",150,73},
        {14,"D&D",220,74},
        {15,"damas",500,70}};

    eLocalidad localidades[TAML]={
        {10,"Gerli"},
        {11,"Merlo"},
        {12,"Barela"},
        {13,"Avellaneda"},
        {14,"Lugano"},
    };

    eCliente clientes[TAMC];

    eAlquiler alquileres[TAMA];

    inicializarCliente(clientes,TAMC);
    inicializaraAlquileres(alquileres,TAMA);

    hardcodearClientes(clientes,TAMC,TAMC);
    hardcodearAlquileres(alquileres,TAMA,TAMA);

    int seguir=1;
    do
    {
        switch(menu())
        {
        case 1:
            system("cls");
            //alta cliente
            if(altaCliente(clientes,TAMC,&idC,localidades,TAML))
            {
                printf("el cliente ha sido cargado con exito\n");
            }
            break;
        case 2:
            system("cls");
            //modificar cliente
            if(modificarCliente(clientes,TAMC,localidades,TAML))
            {
                printf("el cliente ha sido modificado con exito\n");
            }
            break;
        case 3:
            system("cls");
            //baja cliente
            bajaCliente(clientes,TAMC,localidades,TAML);
            break;
        case 4:
            system("cls");
            //listar clientes y ordenar clientes
            ordenarClientes(clientes,TAMC);
            mostrarClientes(clientes,TAMC,localidades,TAML);
            break;
        case 5:
            system("cls");
            //alta alquiler
            altaAlquiler(&idA,alquileres,TAMA,clientes,TAMC,juegos,TAMJ,categorias,TAMCAT,localidades,TAML);
            break;
        case 6:
            system("cls");
            //listar alquileres
            mostrarAlquileres(alquileres,TAMA,clientes,TAMC,juegos,TAMJ,categorias,TAMCAT,localidades,TAML);
            break;
        case 7:
            system("cls");
            mostrarAlquileres(alquileres,TAMA,clientes,TAMC,juegos,TAMJ,categorias,TAMCAT,localidades,TAML);
            bajaAlquiler(alquileres,TAMA);
            break;
        case 8:
            system("cls");
            printf("Informes\n");
            //mostrarJuegosCategoriaMesa(juegos,TAMJ,categorias,TAMCAT);
            //mostrarAlquileresDeClientes(alquileres,TAMA,clientes,TAMC,juegos,TAMJ,categorias,TAMCAT,localidades,TAML);
            mostrarImporteDeCliente(alquileres,TAMA,clientes,TAMC,juegos,TAMJ,localidades,TAML);
            break;
        case 9:
            system("cls");
            printf("esta saliendo\n");
            seguir=0;
            break;
        }
        system("pause");
    }
    while(seguir);

    return 0;
}

int menu()
{
    int opcion;
    system("cls");
    printf("Lista de opciones\n");
    printf("1.Alta cliente\n");
    printf("2.Modificar cliente\n");
    printf("3.Baja cliente\n");
    printf("4.Listar y ordenar clientes\n");
    printf("5.Alta alquiler\n");
    printf("6.Listar alquileres\n");
    printf("7.Baja Alquiler\n");
    printf("8.Informes\n");
    printf("9.Salir\n");
    printf("ingrese una opcion: ");
    scanf("%d",&opcion);
    return opcion;
}
