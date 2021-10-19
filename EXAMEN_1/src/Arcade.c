/*
 * Employe.c
 *
 *  Created on: 11 oct. 2021
 *      Author: KEVIN
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Salon.h"
#include "Arcade.h"
#include "Biblioteca.h"

static int selecionarcampoaModificar(int*selectedField);
static int jugadores_getPedirInt(int *juegadores);
static int Nombre_getPedirchar (char Nombre[]);
static int dameUnIdNuevo(void);
#define OCUPADO 0
#define VACIO 1
#define INTENTOS 3
#define NAME_AND_ADDRESS_LEN 63

int arc_Inicializar(Arcade lista[],int len)
{
	int index;
	int bandera = -1;

	if(lista != NULL && len > 0)
	{
		for(index=0; index < len; index++)
		{
			lista[index].isEmpty = VACIO;
		}
		bandera=1;
	}
	return bandera;
}

int arc_Cargar(Arcade *pArcade,int len, int indice,int *idArcade, int idSalon)
{
	int retorno=-1;
	Arcade bufeerarcade;

	if(pArcade!=NULL && len > 0 && indice < len &&indice >=0 && idArcade != NULL )
	{
		if(utn_getNumeroInt(&bufeerarcade.tipoA, "tipo:\n 0)Mono:\n 1)Estereo: \n", "Error",0, 1, 2)==0)
		{
		  if(utn_getNumeroInt(&bufeerarcade.fichas, "cantidad de fichas:  \n", "Error",1, 100, 2)== 0)
		  {
		   if(utn_getText(bufeerarcade.nombre,NOMBRE_Y_APELLIDO_LEN , "Ingrese nombre: \n", "Error\n",2)== 0)
		   {
		   if(utn_getText(bufeerarcade.nacionalidad,NOMBRE_Y_APELLIDO_LEN, "nacionalidad: \n", "Error",2)== 0)
		   {
		   if(utn_getNumeroInt(&bufeerarcade.jugadores, "cantidad de jugadores:  \n", "Error",1, 200, 2)== 0)
			  {
				bufeerarcade.idArcade = dameUnIdNuevo();
				bufeerarcade.idSalon = idSalon;
				bufeerarcade.isEmpty = 0;
				pArcade[indice]=bufeerarcade;
				*idArcade= bufeerarcade.idArcade;
				retorno=0;
			  }
		   }
		   }
		  }
		}
	}
	return retorno;
}

int arc_imprimir(Arcade* pArcade)
{
	int retorno=-1;
	if(pArcade!= NULL && pArcade->isEmpty==0)
	{
		if(pArcade->isEmpty ==0)
		{
printf("idSalon: %d idArcade: %d - %s - %s - Fichas:%d - Tipo de arcade:%d - Jugadores:%d\n", pArcade->idSalon,pArcade->idArcade, pArcade->nombre,pArcade->nacionalidad, pArcade->fichas, pArcade->tipoA,pArcade->jugadores );
			retorno=0;
		}
	}
	return retorno;
}

int arc_imprimir_Array(Arcade* pArcade, int len)
{
	int retorno=-1;
	int i;
	if(pArcade != NULL && len>0)
	{
		retorno=0;
		for(i=0; i<len ; i++)
		{
		arc_imprimir(&pArcade[i]);
		retorno=0;
		}
	}
	return retorno;
}

int arc_buscadorPorID(Arcade* pArcade, int len, int IdBuscado)
{
	int status=-1;
	int index;

	if(pArcade!=NULL && len>0 && IdBuscado>=0)
	{
		for(index=0; index<len ; index++)
		{
			if( pArcade[index].idArcade == IdBuscado && pArcade[index].isEmpty == 0)
			{
			status = index;
			break;
			}
		}
	}
	return status;
}

int bucarLibre(Arcade* pArcade, int len)
{
	int retorno=-1;
	int i;

	if(pArcade!=NULL && len>0)
	{
		for(i=0; i<len ;i++)
		{
			if(pArcade[i].isEmpty== 1)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

int arc_EliminarPor_Id(Arcade pArcade[], int len, int IdBuscado)
{
	int status = -1;
		status =1;
		pArcade[IdBuscado].isEmpty=1;
	return status;
}

int selecionarOpcion(void)
{
	int status;
	int auxSelecionItem;

	if(utn_getNumeroInt(&auxSelecionItem, "Esta segugo de elimnar?\n 1)Si:\n 2)No\n", "Error",1 , 2, 1)==0)
	{
		status = auxSelecionItem;
	}
	return status;
}

int arc_modificar(Arcade* pArcade,int len,int idModificar)
{
	int status=-1;
	int opcion;
	int auxjugadores;
	char auxnombre[NAME_AND_ADDRESS_LEN];

	if(pArcade !=NULL)
	{
		if(selecionarcampoaModificar(&opcion)==1)
		{
			status=1;
			switch (opcion)
			{
			case 1:
				arcJuegos_imprimir_Array(pArcade, len);
				if(Nombre_getPedirchar(auxnombre)==1)
				{
					strncpy(pArcade[idModificar].nombre, auxnombre, NAME_AND_ADDRESS_LEN);
				}
				break;
			case 2:
				if(jugadores_getPedirInt(&auxjugadores)==1)
				{
					pArcade[idModificar].jugadores=auxjugadores;
				}
				break;
			}
		}
	}
	return status;
}

static int selecionarcampoaModificar(int*selectedField)
{
	int status=-1;
	int auxSelecionItem;

	if(utn_getNumeroInt(&auxSelecionItem, "\nElegi la opcion:\n 1-nombre del juego\n 2-jugadores\n ", "Error",1 , 2, 2)==0)
	{
		status =1;
		*selectedField= auxSelecionItem;
	}
	return status;
}

static int Nombre_getPedirchar (char Nombre[])
{
	int status =-1;
	char mensaje[180];
	char auxName[NAME_AND_ADDRESS_LEN];
	strncpy(mensaje, "\nIngrese nombre del juego: ",sizeof(mensaje));
	if(utn_getText(auxName, NAME_AND_ADDRESS_LEN , mensaje, "Error",1)==0)
	{
		status =1;
		strncpy(Nombre, auxName, NAME_AND_ADDRESS_LEN);
	}
	return status;
}

static int jugadores_getPedirInt(int *juegadores)
{
	int status =-1;
	char mensaje[NAME_AND_ADDRESS_LEN];
	int auxjugadores;
	strncpy(mensaje,"\nIngrese cantidad de jugadores:", sizeof(mensaje));
	if(utn_getNumeroInt(&auxjugadores, mensaje, "Error",1, 1000, 3)==0)
	{
		status=1;
		*juegadores = auxjugadores;
	}
	return status;
}

int Arc_cargarForzada(Arcade* pArcade,int len, int indice,int *IdArcade, int IdSalon, char *NombreJ, char *nacionalidad, int fichas,int tipo,int jugadores)
{
	int retorno=-1;
	Arcade bufeercontrato;
	if(pArcade!=NULL && len > 0 && indice < len && indice >=0 && IdArcade != NULL )
	{
		strncpy(bufeercontrato.nombre, NombreJ,NOMBRE_Y_APELLIDO_LEN );
		strncpy(bufeercontrato.nacionalidad, nacionalidad,NOMBRE_Y_APELLIDO_LEN );
		bufeercontrato.fichas =fichas;
		bufeercontrato.jugadores =jugadores;
		bufeercontrato.tipoA =tipo;
		bufeercontrato.idSalon = IdSalon;
		bufeercontrato.idArcade = dameUnIdNuevo();
		bufeercontrato.isEmpty = 0;
		pArcade[indice]=bufeercontrato;
		*IdArcade= bufeercontrato.idArcade;
		retorno=0;
	}
	return retorno;
}

static int dameUnIdNuevo(void) //privada del archivo
{
	static int contador=0;
	contador++;//es global : mantiene su valor
	return contador;
}

int Imprimir_Juegos(Arcade* listaArcade, int lenArcade)
{
    int status = OCUPADO;
    int i;
    int j;
    int flagArcade;

    if(listaArcade != NULL && lenArcade > 0)
    {
        status = VACIO;
        for(i = 0; i < lenArcade; i++)
        {
            if(listaArcade[i].isEmpty == OCUPADO)
            {
                flagArcade = OCUPADO;
                for(j = i+1; j < lenArcade; j++)
                {
                    if(strcmp(listaArcade[i].nombre, listaArcade[j].nombre) == 0)
                    {
                        flagArcade = VACIO;
                    }
                }
                if(flagArcade == OCUPADO)
                {
                    printf("%s\n", listaArcade[i].nombre);
                }
            }
        }
    }
    return status;
}

int arcJuegos_imprimir(Arcade* pArcade)
{
	int retorno=-1;
	if(pArcade!= NULL && pArcade->isEmpty==0)
	{
		if(pArcade->isEmpty ==0)
		{
printf("idArcade: %d - %s \n",pArcade->idArcade, pArcade->nombre);
			retorno=0;
		}
	}
	return retorno;
}

int arcJuegos_imprimir_Array(Arcade* pArcade, int len)
{
	int retorno=-1;
	int i;
	if(pArcade != NULL && len>0)
	{
		retorno=0;
		for(i=0; i<len ; i++)
		{
		arcJuegos_imprimir(&pArcade[i]);
		retorno=0;
		}
	}
	return retorno;
}

