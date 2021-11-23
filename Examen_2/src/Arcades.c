#include "Arcades.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Biblioteca.h"
#include "LinkedList.h"

#define  NOMBRE_LEN 63

Arcades* arcade_new(void)
{
	Arcades* aux;

	aux = (Arcades*)malloc(sizeof(Arcades));
	return aux;
}

//id,nacionalidad,tipo_sonido,cant_jug,fichas_max,salon,game

Arcades* arcade_newParametros(char* idStr,char* nacionalidadStr,char* tipoStr, char* jugadoresStr, char* fichasStr,char* salonStr, char* juegoStr)
{
    int auxId;
    int auxJugadores;
    int auxFichas;
    Arcades* aux = arcade_new();

    if(idStr != NULL && nacionalidadStr!=NULL && tipoStr!=NULL && jugadoresStr!=NULL && fichasStr!=NULL && salonStr!=NULL && juegoStr!=NULL)
    {
        auxId=atoi(idStr);
        auxJugadores=atoi(jugadoresStr);
        auxFichas =atoi(fichasStr);

        if(aux != NULL)
        {
            if(arcade_setId(aux, auxId)==1 ||
            arcade_setNacionalidad(aux, nacionalidadStr)==1 ||
            arcade_setTipo(aux, tipoStr)==1 ||
            arcade_setJugadores(aux, auxJugadores)==1 ||
            arcade_setFichas(aux, auxFichas)==1 ||
			arcade_setSalon(aux, salonStr)==1 ||
			arcade_setJuego(aux, juegoStr)==1)
            {
            	free(aux);
            	printf("algo salio mal\n");
            }
        }
    }
    return aux;
}

Arcades* arcade_newParametrosAdd(int idStr,char* nacionalidadStr,char* tipoStr, int jugadoresStr, int fichasStr,char* salonStr,char* juegoStr)
{
	Arcades* aux = arcade_new();
	if(idStr>=0 && nacionalidadStr != NULL && tipoStr !=NULL && jugadoresStr>0 && fichasStr>0 && salonStr !=NULL && juegoStr !=NULL)
	{
		if(aux != NULL)
		{
			if(arcade_setId(aux, idStr)==1 ||
			arcade_setNacionalidad(aux, nacionalidadStr)==1 ||
			arcade_setTipo(aux, tipoStr)==1 ||
			arcade_setJugadores(aux, jugadoresStr)==1 ||
			arcade_setFichas(aux, fichasStr)==1 ||
			arcade_setSalon(aux, salonStr)==1 ||
			arcade_setJuego(aux, juegoStr)==1)
			{
				free(aux);
				printf("algo salio mal\n");
			}
		}
    }
    return aux;
}

int arcade_setId(Arcades* this, int id)
{
    int retorno=1;
    if(this!=NULL && id>=0 )
    {

        this->id=id;
        retorno=0;
    }

    return retorno;
}

int arcade_getId(Arcades* this, int* id)
{
    int retorno=1;
    if(this!=NULL)
    {
        *id = this->id;
        retorno=0;
    }

    return retorno;
}

int arcade_setNacionalidad(Arcades* this,char* nacionalidad)
{
    int retorno=1;
    if(this!=NULL &&  nacionalidad!=NULL)
    {
        strncpy(this->nacionalidad,nacionalidad,NOMBRE_LEN);

        retorno=0;
    }
    return retorno;
}

int arcade_getNacionalidad(Arcades* this,char* nacionalidad)
{
    int retorno=1;
    if(this!=NULL)
    {
        strncpy(nacionalidad,this->nacionalidad,NOMBRE_LEN);
        retorno=0;
    }
    return retorno;
}

int arcade_setTipo(Arcades* this,char* tipo)
{
	 int retorno=1;
	if(this!=NULL && tipo!=NULL)
	{
		strncpy(this->tipo,tipo,NOMBRE_LEN);

		retorno=0;
	}
	return retorno;

}

int arcade_getTipo(Arcades* this,char* tipo)
{
	int retorno=1;
	if(this!=NULL && tipo!=NULL)
	{
		strncpy(tipo,this->tipo,NOMBRE_LEN);
		retorno=0;
	}
	return retorno;
}

int arcade_setFichas(Arcades* this,int fichas)
{
    int retorno=1;
    if(this!=NULL && fichas>=0)
    {
        this->fichas=fichas;
        retorno=0;
    }
    return retorno;
}

int arcade_getFichas(Arcades* this,int* fichas)
{
    int retorno=1;
    if(this!=NULL && fichas>=0)
    {
        *fichas=this->fichas;
        retorno=0;
    }
    return retorno;
}

int arcade_setJugadores(Arcades* this,int jugadores)
{
	int retorno=1;
	if(this!=NULL && jugadores >=0)
	{
		this->jugadores=jugadores;
		retorno=0;
	}
    return retorno;
}

int arcade_getJugadores(Arcades* this,int* jugadores)
{
	int retorno=1;
	if(this!=NULL && jugadores >=0)
	{
		*jugadores=this->jugadores;
		retorno=0;
	}
	return retorno;
}

int arcade_setSalon(Arcades* this,char* salon)
{
    int retorno=1;
    if(this!=NULL && salon!=NULL)
    {
        strncpy(this->salon,salon,NOMBRE_LEN);

        retorno=0;
    }
    return retorno;
}

int arcade_getSalon(Arcades* this,char* salon)
{
    int retorno=1;
    if(this!=NULL && salon!=NULL)
    {
        strncpy(salon,this->salon,NOMBRE_LEN);
        retorno=0;
    }
    return retorno;
}


int arcade_setJuego(Arcades* this,char* juego)
{
    int retorno=1;
    if(this!=NULL && juego!=NULL)
    {
    	strMinuscula(juego);
        strncpy(this->game,juego,NOMBRE_LEN);

        retorno=0;
    }
    return retorno;
}

int arcade_getJuego(Arcades* this,char* juego)
{
    int retorno=1;
    if(this!=NULL && juego!=NULL)
    {
        strncpy(juego,this->game,NOMBRE_LEN);
        retorno=0;
    }
    return retorno;
}

int Imprimir_Juegos(LinkedList* listaArcade)
{
    int status = -1;
    int flagArcade;
    int i;
    int j;
    Arcades* arcadeI;
    Arcades* arcadeJ;
    char auxjuego1[63];
    char auxjuego2[63];

    if(listaArcade != NULL)
    {
        status = 0;
        for(i= 0; i < ll_len(listaArcade); i++)
        {
        	arcadeI = ll_get(listaArcade, i);
            arcade_getJuego(arcadeI, auxjuego1);
            flagArcade=0;
			for(j = i+1; j < ll_len(listaArcade); j++)
			{
				arcadeJ = ll_get(listaArcade, j);
				arcade_getJuego(arcadeJ, auxjuego2);

				if(strcmp(auxjuego1,auxjuego2)== 0)
				{
					flagArcade = 1;
				}
			}
			if(flagArcade == 0)
			{
				printf("%s\n", auxjuego1);
			}
        }
    }
    return status;
}




