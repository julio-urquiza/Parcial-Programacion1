#ifndef CATEGORIA_H_INCLUDED
#define CATEGORIA_H_INCLUDED

typedef struct{
    int id;
    char descripcion[21];
}eCategoria;

#endif // CATEGORIA_H_INCLUDED
int buscarCategoriaPorId(eCategoria categoria[],int tamcat,int id);
