#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arcades.h"
#include "LinkedList.h"
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_ArcadeFromTextLectura(FILE* pFile , LinkedList* pArrayListArcade)
{
	int retorno=-1;
	int cantidad;
	char buffer1[1024];//id
	char buffer2[1024];//nacionalidad
	char buffer3[1024];//tipo
	char buffer4[1024];//jugadores
	char buffer5[1024];//fichas
	char buffer6[1024];//salon
	char buffer7[1024];//juego
	Arcades* nuevoArcade;

	if(pFile !=NULL && pArrayListArcade != NULL)
	{
		//id,nacionalidad,tipo_sonido,cant_jug,fichas_max,salon,game
	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer1,buffer2,buffer3,buffer4,buffer5,buffer6,buffer7);

		while(!feof(pFile))//recorre cada linea del archivo
		{
			cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer1,buffer2,buffer3,buffer4,buffer5,buffer6,buffer7); // verifico que se pudieron levantar cada campo

			if(cantidad < 7)
			{
				break;
			}
			nuevoArcade = arcade_newParametros(buffer1,buffer2,buffer3,buffer4,buffer5,buffer6,buffer7); // contruyo un nuevo empleado con los datos que tengo en buffer

			ll_add(pArrayListArcade,nuevoArcade); // agredo al linkedlist

			retorno=0;
		}
	}
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */


int parser_ArcadeFromTextEscritura(FILE* pFile , LinkedList* pArrayListArcade)
{
	Arcades* auxEmpleado;
	int retorno=-1;
	int id;
	char nacionalidad[63];
	char tipo[63];
	int jugadores;
	int fichas;
	char salon[63];
	char juego[63];

	if(pFile!=NULL && pArrayListArcade !=NULL)
	{
		fprintf(pFile, "id,nacionalidad,tipo_sonido,cant_jug,fichas_max,salon,game\n");

		for(int i=0; i<ll_len(pArrayListArcade); i++)
		{
			auxEmpleado = (Arcades*)ll_get(pArrayListArcade, i);
			if(auxEmpleado!=NULL)
			{
				//id,nacionalidad,tipo_sonido,cant_jug,fichas_max,salon,game
				if(arcade_getId(auxEmpleado, &id)==0 &&
				arcade_getNacionalidad(auxEmpleado, nacionalidad)==0 &&
				arcade_getTipo(auxEmpleado, tipo)==0 &&
				arcade_getJugadores(auxEmpleado, &jugadores)==0 &&
				arcade_getFichas(auxEmpleado, &fichas)==0 &&
				arcade_getSalon(auxEmpleado, salon)==0 &&
				arcade_getJuego(auxEmpleado, juego)==0)
				{
					fprintf(pFile,"%d,%s,%s,%d,%d,%s,%s\n", id, nacionalidad, tipo, jugadores, fichas, salon, juego);
					retorno=0;
				}
				else
				{
					puts("error en los gets");
					retorno=1;
				}
			}
		}
	}
	return retorno;
}

int parser_ArcadeFromTextLecturaJuegos(FILE* pFile , LinkedList* pArrayListArcade)
{
	int retorno=1;
	int cantidad;
	char buffer1[63];

	if(pFile!=NULL && pArrayListArcade!=NULL)
	{
		while(!feof(pFile))//recorre cada linea del archivo
		{
			cantidad = fscanf(pFile,"%[^\n]\n",buffer1); // verifico que se pudieron levantar cada campo

			if(cantidad < 1)
			{
				break;
			}
			// contruyo un nuevo empleado con los datos que tengo en buffer

			retorno=0;
		}
	}
	return retorno;
}

