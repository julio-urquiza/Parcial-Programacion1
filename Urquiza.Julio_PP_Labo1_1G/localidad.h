#ifndef LOCALIDAD_H_INCLUDED
#define LOCALIDAD_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];
}eLocalidad;

#endif // LOCALIDAD_H_INCLUDED

int buscarLocalidadPorId(eLocalidad localidades[],int taml,int id);
void mostrarLocalidades(eLocalidad localidades[],int taml);
void mostrarUnaLocalidad(eLocalidad localidad);


