/*
 * UTN_Biblioteca.c
 *
 *  Created on: 7 sep. 2021
 *      Author: KEVIN
 */
#include "Salon.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Biblioteca.h"

static int dameUnIdNuevo(void) ;
#define OCUPADO 0
#define VACIO 1
#define INTENTOS 3
#define NAME_AND_ADDRESS_LEN 128

int salon_Inicializar(Salon pSalon[],int len)
{
	int index;
	int bandera = -1;

	if(pSalon != NULL && len > 0)
	{
		for(index=0; index < len; index++)
		{
			pSalon[index].flagEmpty = 1;
		}
		bandera=1;
	}
	return bandera;
}

int salon_bucarLibre(Salon* pSalon, int len)
{
	int retorno=-1;
	int i;

	if(pSalon!=NULL && len>0)
	{
		for(i=0; i<len ;i++)
		{
			if(pSalon[i].flagEmpty==VACIO)
			{
				retorno= i;
				break;
			}
		}
	}
	return retorno;
}

int salon_cargar(Salon *pSalon)
{
	int retorno=-1;
	int typeAux;
	char nameAux[128];
	char addressAux[60];

	if(pSalon!=NULL)
	{
		if(utn_getNumeroInt(&typeAux, "Elija tipo de salon: \n 0-shopping\n 1-local\n ", "Error\n",0,1 , 1)==0)
		{
			if(utn_getText(nameAux, 128 , "Ingrese el nombre: ", "Error",3)==0)
			{
				if(utn_getText(addressAux,60, "Ingrese la direccion: ", "Error",3)==0)
				{
				pSalon->tipo = typeAux;
				pSalon->id = dameUnIdNuevo();
				strncpy(pSalon->nombre,nameAux,sizeof(pSalon->nombre));
				strncpy(pSalon->direccion,addressAux,sizeof(pSalon->direccion));
				pSalon->flagEmpty = 0;
				retorno=0;
				}
			}
		}
	}
	return retorno;
}

static int dameUnIdNuevo(void) //privada del archivo
{
	static int contador=0;
	contador++;//es global : mantiene su valor
	return contador;
}

int salon_imprimir(Salon* pSalon)
{
	int retorno=-1;
	if(pSalon!= NULL && pSalon->flagEmpty==0)
	{
		if(pSalon->flagEmpty ==0)
		{
printf("id: %d - Salon:%s - Tipo de salon:%d - Direccion:%s\n",pSalon->id, pSalon->nombre, pSalon->tipo, pSalon->direccion);
			retorno=0;
		}
	}
	return retorno;
}

int salon_imprimir_Array(Salon* pSalon, int len)
{
	int retorno=-1;
	int i;
	if(pSalon != NULL && len>0)
	{
		retorno=0;
		for(i=0; i<len ; i++)
		{
			salon_imprimir(&pSalon[i]);
			retorno=0;
		}
	}
	return retorno;
}

int salon_buscadorPID(Salon* pSalon, int len, int IdBuscado)
{
	int status=-1;
	int index;

	if(pSalon!=NULL && len>0 && IdBuscado>=0)
	{
		for(index=0; index<len ; index++)
		{
			if( pSalon[index].id==IdBuscado && pSalon[index].flagEmpty==OCUPADO)
			{
				status = index;
				break;
			}
		}
	}
	return status;
}

int salon_EliminarPor_Id(Salon pSalon[], int len, int IdBuscado)
{
	int status = -1;

		status =1;
		pSalon[IdBuscado].flagEmpty=1;

	return status;
}


int salon_pedirID(void)
{
	int retorno=-1;
	utn_getNumeroInt(&retorno , "Ingrese id:  ", "Error",0, 1000, 2);
	return retorno;
}


int salon_altaForazada(Salon *array, int len, int indice, int *id, int typee, char *name, char *address)
{
	int retorno=-1;
	Salon bufferSalon;

	if(array != NULL && len >0 && indice < len && indice >= 0 && id !=NULL)
	{
		bufferSalon.tipo = typee;
		bufferSalon.id = dameUnIdNuevo();

		strncpy(bufferSalon.nombre,name,NOMBRE_DIRECCION_LEN);
		strncpy(bufferSalon.direccion,address,NOMBRE_DIRECCION_LEN);
		bufferSalon.flagEmpty = 0;
		retorno=1;
		array[indice]=bufferSalon;
		*id=bufferSalon.id;
	}
	return retorno;
}



