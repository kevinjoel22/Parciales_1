#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Biblioteca.h"
#include "parser.h"
#include "Controller.h"
#include "string.h"
#include "Arcades.h"

#define LEN_CHAR 63
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListArcade)
{
	int retorno=-1;
	FILE *auxP;
	auxP = fopen(path,"r"); //abro y leo el archivo

	if(auxP!=NULL)
	{
		if(parser_ArcadeFromTextLectura(auxP, pArrayListArcade)==0) //les paso a parser el puntero a archivo para que los transforme
		{
		retorno=0;
		}
	}
	else
	{
		puts("hay un error");
		retorno=1;
	}
	fclose(auxP);
    return retorno;
}

int controller_saveAsText(char* path , LinkedList* pArrayListArcade)
{
	int retorno=-1;
	FILE* aux;

	if(pArrayListArcade != NULL && path !=NULL)
	{
		aux = fopen(path,"w");
		//puts("adebntro de controles");
		if(aux != NULL)
		{
			puts("adebntro de controles");
			if(parser_ArcadeFromTextEscritura(aux, pArrayListArcade)==0)
			{
			retorno=0;
			puts("salio todo bien");
			}
		}
	}
	fclose(aux);
    return retorno;
}

int controller_guardarJuegos(char* path , LinkedList* pArrayListArcade)
{
	int retorno=-1;
	int flagArcade;
	int i;
	int j;
	Arcades* arcadeI;
	Arcades* arcadeJ;
	char auxjuego1[63];
	char auxjuego2[63];

	FILE *auxP;
	auxP = fopen(path,"w"); //abro y leo el archivo

	if(auxP!=NULL)
	{
		if(pArrayListArcade != NULL)
		{
			retorno=0;
			for(i= 0; i < ll_len(pArrayListArcade); i++)
			{
				arcadeI = ll_get(pArrayListArcade, i);
				arcade_getJuego(arcadeI, auxjuego1);
				flagArcade=0;
				for(j = i+1; j < ll_len(pArrayListArcade); j++)
				{
					arcadeJ = ll_get(pArrayListArcade, j);
					arcade_getJuego(arcadeJ, auxjuego2);

					if(strcmp(auxjuego1,auxjuego2)== 0)
					{
						flagArcade = 1;
					}
				}
				if(flagArcade == 0)
				{
					fprintf(auxP,"%s\n", auxjuego1);
				}
			}
		}
	}
	fclose(auxP);
	return retorno;
}


int controller_addArcade(LinkedList* pArrayListArcade, int *id)
{
	int retorno=-1;
	char nacionalidadAux[128];
	//int id;
	int tiposAux;
	int jugadoresAux;
	int fichasAux;
	char salonAux[LEN_CHAR];
	char juegoAux[LEN_CHAR];
	char tipo1[LEN_CHAR]="MONO";
	char tipo2[LEN_CHAR]="ESTEREO";
	char valorF[LEN_CHAR];

	Arcades *nuevoArcade;
	//Arcades* auxid;
	if(pArrayListArcade!=NULL)
	{
		(*id)++;
		//id,nacionalidad,tipo_sonido,cant_jug,fichas_max,salon,game
		if(utn_getText(nacionalidadAux, LEN_CHAR , "Ingrese nacionalidad del arcade:\n", "Error\n",2)==0 &&
			utn_getNumeroInt(&tiposAux, "Ingrese tipo de sonido.\n 1)MONO\n 2)ESTEREO\n", "Error\n",1,2, 2)==0 &&
			utn_getNumeroInt(&jugadoresAux, "Ingrese cantidad de jugadores:\n  ", "Error\n",1, 100000, 2)==0 &&
			utn_getNumeroInt(&fichasAux, "Ingrese cantidad de fichas:\n  ", "Error\n",1, 1000, 2)==0 &&
			utn_getText(salonAux, LEN_CHAR , "Ingrese nombre del salon:\n", "Error\n",2)==0 &&
			utn_getText(juegoAux, LEN_CHAR , "Ingrese nombre del juego:\n", "Error\n",2)==0)
			{
				//controller_asignarId( pArrayListArcade,&id);

				/*auxid= ll_get(pArrayListArcade, ll_len(pArrayListArcade)-1);

				arcade_getId(auxid, &id);

				id++;*/
				switch(tiposAux)
				{
				case 1:
					strncpy(valorF,tipo1,LEN_CHAR);
					break;
				case 2:
					strncpy(valorF,tipo2,LEN_CHAR);
					break;
				}
				nuevoArcade = arcade_newParametrosAdd(*id,nacionalidadAux,valorF,jugadoresAux,fichasAux,salonAux,juegoAux);
				retorno=0;
			}
		if(nuevoArcade!=NULL)
		{
			ll_add(pArrayListArcade, nuevoArcade);
			retorno=0;
		}
	}
	return retorno;
}


int controller_ListArcade(LinkedList* pArrayListArcade)
{
	int retorno=-1;
	Arcades* empleado;
	if(pArrayListArcade!=NULL)
	{
		for(int i=0; i<ll_len(pArrayListArcade); i++)
		{
			empleado= (Arcades*)ll_get(pArrayListArcade,i);
			arcade_imprimir(empleado,i);
			retorno=0;
		}
	}
	return retorno;
}

int arcade_imprimir(Arcades* pArrayListArcade, int indice)
{
	int retorno=-1;
	int idAux;
	char tipoAux[63];
	int jugadoresAux;
	int fichasAux;
	char nacionalidadAux[63];
	char juegoAux[63];
	char salonAux[63];

	arcade_getId(pArrayListArcade,&idAux);
	arcade_getNacionalidad(pArrayListArcade,nacionalidadAux);
	arcade_getTipo(pArrayListArcade,tipoAux);
	arcade_getJugadores(pArrayListArcade,&jugadoresAux);
	arcade_getFichas(pArrayListArcade,&fichasAux);
	arcade_getJuego(pArrayListArcade, juegoAux);
	arcade_getSalon(pArrayListArcade, salonAux);

		if(pArrayListArcade!=NULL && indice>=0)
		{
			//id,nacionalidad,tipo_sonido,cant_jug,fichas_max,salon,game
			printf("id:%d - nacionalidad:%s - tipo:%s - cantidad de jugadores:%d - fichas:%d - salon:%s - juego:%s\n\n",idAux,nacionalidadAux,tipoAux,jugadoresAux,fichasAux,salonAux,juegoAux);
			retorno=0;
		}

	return retorno;
}

int controller_editArcade(LinkedList* pArrayListArcade)
{
	int retorno=-1;
	int len;
	int idBuscado;
	int id;
	int jugadores;
	char juego[63];
	int opcion;
	Arcades* aux;

	if(pArrayListArcade!=NULL)
	{
		len = ll_len(pArrayListArcade);
		if(len>=0)
		{
			controller_ListArcade(pArrayListArcade);

			if(utn_getNumeroInt(&id,"Ingrese id del arcade a modificar\n" , "Error\n", 1, 2000, 2)==0)
			{
				idBuscado = Controller_buscarById(pArrayListArcade, id);

				if(idBuscado!=-1)
				{
					aux = (Arcades*)ll_get(pArrayListArcade, idBuscado);

					arcade_imprimir(aux, idBuscado);

					puts("1)Modificar jugadores");
					puts("2)Modificar juego");
					if(utn_getNumeroInt(&opcion, "Ingrese opcion a modificar\n", "Error, ingrese opcion a modificar", 1, 2, 2)==0)
					{

						switch(opcion)
						{
							case 1:
								if(utn_getNumeroInt(&jugadores, "Ingrese jugadores a modificar\n", "Error, ingrese jugadores a modificar", 1, 10000, 2)==0)
								{
									retorno=0;
									arcade_setJugadores(aux, jugadores);
								}
								else
								{
									puts("Error, cantidad de jugadores invalida");
									retorno=1;
								}
								break;
							case 2:
								Imprimir_Juegos(pArrayListArcade);
								if(utn_getText(juego,20 , "Ingrese juego a modificar\n", "Error, ingrese juego a modificar", 2)==0)
								{
									retorno=0;
									arcade_setJuego(aux, juego);
								}
								else
								{
									retorno=1;
									puts("Error, cantidad de jugadores invalida");
								}
								break;
						}
					}
					else
					{
						retorno=1;
						puts("Error, opcion no existe");
					}
				}
			}
			else
			{
				retorno=1;
				puts("NO existe ese id.");
			}
		}
		else
		{
			puts("No hay nada cargado.");
		}
	}
    return retorno;
}

int controller_removeArcade(LinkedList* pArrayListArcade)
{
	int retorno=-1;
	int idBuscado;
	int id;
	int len;
	int respuesta;
	Arcades* aux;
	if(pArrayListArcade!=NULL)
	{
		len = ll_len(pArrayListArcade);
		if(len>0)
		{
			controller_ListArcade(pArrayListArcade);

			if(utn_getNumeroInt(&idBuscado, "Ingrese id a a eliminar:\n", "id Invalido.\n",1, 2000, 2)==0)
			{
				id = buscarIndice(pArrayListArcade , idBuscado);//Controller_buscarById(pArrayListArcade, idBuscado);

				aux = (Arcades*)ll_get(pArrayListArcade, id);

				arcade_imprimir(aux, id);
				utn_getNumeroInt(&respuesta, "Esta seguro de querer aliminar?\n 1)SI\n 2)NO\n", "Error, Esta seguro de querer aliminar?\n 1)SI\n 2)NO\n",1,2,3);

					switch(respuesta)
					{
					case 1:
						ll_remove(pArrayListArcade, id);
						retorno =0;
						break;
					case 2:
						retorno=1;
						puts("No se elimino el arcade");
						break;
					}
			}
			else
			{
				puts("Error, id no existe");
			}
		}
		else
		{
			puts("No hay empleados ingresados.");
		}
	}
    return retorno;
}

int Controller_buscarById(LinkedList* pArrayListArcade, int IdBuscado)
{
	int status=-1;
	int index;
	int idAux;
	Arcades* aux;

	if(pArrayListArcade!=NULL && ll_len(pArrayListArcade)>0 && IdBuscado>=0 && IdBuscado<=ll_len(pArrayListArcade))
	{
		for(index=0; index< ll_len(pArrayListArcade) ; index++)
		{
			aux = (Arcades*)ll_get(pArrayListArcade, index);

			arcade_getId(aux, &idAux);
			if(IdBuscado==idAux)
			{
				status = index;
				break;
			}
		}
	}
	return status;
}

int buscarIndice(LinkedList* pArrayListArcade, int id)
{
	int retorno=-1;
	int i;
	int idEmp;
	Arcades* arcade;
	if(pArrayListArcade!=NULL && id>=0)
	{
		for(i=0;i<ll_len(pArrayListArcade);i++)
		{
			arcade=(Arcades*)ll_get(pArrayListArcade, i);
			arcade_getId(arcade, &idEmp);
			if(id==idEmp)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}




int controller_sortArcade(LinkedList* pArrayListArcade)
{
	int retorno=-1;
	if(pArrayListArcade!=NULL)
	{
		if(ll_len(pArrayListArcade)>=0)
		{
			if(ll_sort(pArrayListArcade, OrdenamientoPorNombre, 1)==0)
			{
				controller_ListArcade(pArrayListArcade);
				retorno=0;
				ll_sort(pArrayListArcade, OrdenamientoPorSueldo, 1);
			}
		}
	}
    return retorno;
}

int OrdenamientoPorSueldo(void* empleadoZ,void* empleadoX)
{
	int retorno=0;
	if(((Arcades*)empleadoZ)->id > ((Arcades*)empleadoX)->id)
		{
			retorno=1;
		}
		else
		{
			if(((Arcades*)empleadoZ)->id < ((Arcades*)empleadoX)->id)
			{
				retorno=-1;
			}
			else
			{
				retorno=0;
			}
		}
	return retorno;
}
int OrdenamientoPorNombre(void* juegoZ, void* juegoX)
{
	int retorno=0;
	Arcades* auxZ=juegoZ;
	Arcades* auxX=juegoX;
	char aux1[63];
	char aux2[63];

	arcade_getJuego(auxZ, aux1);
	arcade_getJuego(auxX, aux2);

	retorno = stricmp(aux1,aux2);

	return retorno;
}
int controlerFiltratumama(LinkedList* pArrayListArcade)
{
	int retorno=-1;
	LinkedList* aux;

	if(pArrayListArcade!=NULL)
	{
		aux = ll_filter(pArrayListArcade, archivoMultijugador);

		if(aux!=NULL)
		{
			if(controller_saveAsText("multijugador.csv",aux)==0)
			{
				retorno=0;
			}
		}
	}
	return retorno;
}

int archivoMultijugador(void* pArrayListArcade)
{
	int retorno=1;
	Arcades* aux;
	int  cantidad;

	aux = (Arcades*)pArrayListArcade;
	if(aux!=NULL)
	{
		arcade_getJugadores(aux, &cantidad);
		if(cantidad>1)
		{
			retorno=0;
		}
	}
	return retorno;
}

int actualizarCantidadFichas(LinkedList* pArrayListArcade)
{
	int retorno=1;
	if(pArrayListArcade!=NULL)
	{
		ll_map(pArrayListArcade, fichasDuplicadas);
		retorno=0;
	}
	return retorno;
}

void fichasDuplicadas(void* pArrayListArcade)
{
	Arcades* aux;
	int auxF;
	int auxFinal;
	aux = (Arcades*)pArrayListArcade;
	if(pArrayListArcade!=NULL && aux!=NULL)
	{
		arcade_getFichas(aux, &auxF);

		auxFinal = auxF*2;

		arcade_setFichas(aux, auxFinal);
	}
}

int controller_asignarId(LinkedList* pArrayListArcade,int* numeroId)
{
	int rtn=-1;
	Arcades* pArcade;
	int i;
	int idAux;
	if(pArrayListArcade!=NULL)
	{
		if(ll_len(pArrayListArcade)==0)
		{
			*numeroId=501;
		}else
		{
			for(i=0;i<ll_len(pArrayListArcade);i++)
			{
				pArcade=ll_get(pArrayListArcade, i);
				arcade_getId(pArcade, &idAux);
				if(i==0||*numeroId<idAux)
				{
					*numeroId=idAux;
				}
			}
			*numeroId+=1;
			rtn=0;
		}
	}
	return rtn;
}
