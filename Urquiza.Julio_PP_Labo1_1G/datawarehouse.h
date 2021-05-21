#ifndef DATAWAREHOUSE_H_INCLUDED
#define DATAWAREHOUSE_H_INCLUDED

#include "alquileres.h"
#include "cliente.h"

eCliente dataClientes[10]={
        {300,"ale","alem",'f',"1235464",1},
        {301,"manu","perez",'m',"1235464",1},
        {302,"gian","urquiza",'m',"1235464",1},
        {303,"julio","gomez",'m',"1235464",1},
        {304,"pepe","altamira",'m',"1235464",1},
        {305,"lola","ortiz",'f',"1235464",1},
        {306,"maria","sanchez",'f',"1235464",1},
        {307,"cande","fernandez",'f',"1235464",1},
        {308,"may","cansiani",'f',"1235464",1},
        {309,"lucia","escudero",'f',"1235464",1}};

eAlquiler dataAlquileres[5]={
        {400,15,309,{7,5,2021},1},
        {401,10,301,{10,6,2021},1},
        {403,13,305,{9,7,2021},1},
        {404,14,303,{8,10,2021},1},
        {405,11,300,{10,12,2021},1}};

#endif // DATAWAREHOUSE_H_INCLUDED
