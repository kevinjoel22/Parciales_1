/*
 * Informes.c
 *
 *  Created on: 16 oct. 2021
 *      Author: KEVIN
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Biblioteca.h"
#include "Informes.h"
#include "Salon.h"
#include "Arcade.h"
#define OCUPADO 0
#define VACIO 1
#define LARGO_NOMBRE 63
#define JUEGOS_LEN 1000

typedef struct{
	char nombre[LARGO_NOMBRE];
	int isEmptyN;
}Juegos;

Juegos lista[1000];

int menu(void)
{
	int opcion;
	printf("1)ALTA DE SALÓN\n");
	printf("2)ELIMINAR SALÓN\n");
	printf("3)IMPRIMIR SALONES\n");
	printf("4)INCORPORAR ARCADE\n");
	printf("5)MODIFICAR ARCADE\n");
	printf("6)ELIMINAR ARCADE\n");
	printf("7)IMPRIMIR ARCADES\n");
	printf("8)IMPRIMIR JUEGOS\n");
	printf("9)IMPRIMIR JUEGOS\n");
	printf("10)Salir\n");

	utn_getNumeroInt(&opcion, "Ingrese opcion:  ", "Error",1, 10, 1);
	return opcion;
}

/*A) Listar los salones con más de 4 arcades. Indicando ID de salón, nombre, dirección y tipo de salón.
 * */

int InformesA(Arcade *listaArcade, int lenArcade, Salon *listaSalon, int lenSalon)
{
	int retorno=-1;
	int i;
	int j;
	int contador=0;
	if(listaArcade!=NULL && listaSalon !=NULL)
	{
		for(i=0; i<lenSalon ; i++)
		{
			if(listaSalon[i].flagEmpty==0)
			{
				contador=0;
				for(j=0; j<lenArcade;j++)
				{
					if(listaArcade[j].isEmpty==0 && listaSalon[i].id==listaArcade[j].idSalon)
					{
						contador++;
					}
				}
				if(contador>4)
				{
					retorno=0;

					printf("idSalon: %d - nombre: %s - direcions: %s - tipo: %d\n",listaSalon[i].id,listaSalon[i].nombre,listaSalon[i].direccion, listaSalon[i].tipo);
				}
			}
		}
	}
	return retorno;
}

/*B) Listar los arcades para más de 2 jugadores, indicando ID de arcade, cantidad de jugadores, nombre del juego y
nombre del salón al que pertenece.
 *
 */
int InformeB(Arcade *listaArcade, int lenArcade, Salon *listaSalon, int lenSalon)
{
	int i;
	int retorno=-1;
	int iddelSalon;
	if(listaArcade !=NULL && lenArcade>0)
	{
		for(i=0; i<lenArcade; i++)
		{
			if(listaArcade[i].isEmpty ==0 && listaArcade[i].jugadores >2 )
			{
				iddelSalon = salon_buscadorPID(listaSalon, lenSalon, listaArcade[i].idSalon);
				printf("%d", iddelSalon);
			printf("id: %d - jugadores: %d - nombre:%s - salon: %s:\n",listaArcade[i].idArcade, listaArcade[i].jugadores,listaArcade[i].nombre, listaSalon[iddelSalon].nombre);
			}
		}
		retorno=0;
	}
	return retorno;
}
/*C) Listar toda la información de un salón en específico ingresando su ID. Imprimir nombre, tipo y dirección y cantidad
de arcades que posee.*/

//
int InformeC(Salon * listaSalones, int lenSalones, Arcade *listaArcade, int lenArcade)
{
	int retorno=-1;
	int i;
	int j;
	int indexsalon;
	int auxSalon;
	//int auxArcade;
	int contador=0;
	if(listaSalones!=NULL && lenSalones>0)
	{
		for(i=0;i<lenSalones; i++)
		{
			if(utn_getNumeroInt(&indexsalon, "\nElegir ID de salon:\n", "Error\n", 1, 100, 2)==0)
			{
				auxSalon = salon_buscadorPID(listaSalones, lenSalones, indexsalon);
				break;
			}
		}
		for(j=0; j<lenArcade; j++)
		{
			if(listaArcade[j].isEmpty==0 && listaArcade[j].idSalon == listaSalones[auxSalon].id)
			{

				contador++;
			}
		}
			if(auxSalon>=0)
			{
				printf("nombre: %s - tipo: %d - direccion: %s - arcades: %d\n",listaSalones[auxSalon].nombre, listaSalones[auxSalon].tipo, listaSalones[auxSalon].direccion,contador);
			}
	}
	return retorno;
}

/*D) Listar todos los arcades de un salón determinado ingresando su ID. Informar nombre y tipo de salón, listar todos
los arcades con sus datos junto con el nombre del juego que lo compone.
 *
 */

int InformeD(Arcade *listaArcade, int lenArcade, Salon *listaSalones, int lenSalones)
{
	int retorno=-1;
	int i;
	int j;
	int indexsalon;
	int auxSalon;
	if(listaArcade != NULL && lenArcade>0)
	{
		for(i=0;i<lenSalones; i++)
		{
			if(utn_getNumeroInt(&indexsalon, "\nElegir ID de salon:\n", "Error\n", 1, 100, 2)==0)
			{
				auxSalon = salon_buscadorPID(listaSalones, lenSalones, indexsalon);
				break;
			}
		}
		printf("nombre: %s - tipo: %d \n",listaSalones[auxSalon].nombre, listaSalones[auxSalon].tipo);
		for(j=0; j<lenArcade; j++)
		{
			if(listaArcade[j].isEmpty==0 && listaArcade[j].idSalon == listaSalones[auxSalon].id)
			{
				if(auxSalon>=0)
				{
					 printf("arcades: %d - juego: %s \n",listaArcade[j].idSalon, listaArcade[j].nombre);
				}
			}
		}
	}
	return retorno;
}

/*E) Imprimir el salón con más cantidad de arcades, indicando todos los datos del salón y la cantidad de
 arcades que posee.*/


int InformeE(Salon * listaSalones, int lenSalones, Arcade *listaArcade, int lenArcade)
{
	int retorno=-1;
	int i;
	int j;
	int idMaximo;
	int contador=0;
	int flagBandera=0;
	int maximo;
	if(listaSalones != NULL && lenSalones>0)
	{

		for(i=0; i<lenSalones; i++)
		{

			if(listaSalones[i].flagEmpty==0)
			{
				contador=0;
				for(j=0; j<lenArcade; j++)
				{
					if(listaArcade[j].isEmpty==0 && listaArcade[j].idSalon == listaSalones[i].id)
					{
					contador++;
					}
				}
				if(flagBandera==0 || contador > maximo)
				{
					idMaximo=i;
					maximo = contador;
					flagBandera=1;
				}
			}
		}
		retorno=0;
	}
	printf("id salon: %d - nombre: %s - direccion: %s - tipo: %d\n ",listaSalones[idMaximo].id, listaSalones[idMaximo].nombre, listaSalones[idMaximo].direccion, listaSalones[idMaximo].tipo);
	printf("cantidad de arcades: %d\n",maximo);

	return retorno;
}


/*F) Ingresar el ID de un salón, y el valor en pesos de una ficha, e imprimir el monto máximo en pesos que puede
recaudar el salón (sumar cantidad de fichas máximo de cada arcade del salón y multiplicarla por el valor en pesos
ingresado)
*/

int calcularValor(Arcade* listaArcade, int lenArcade, int id, int value)
{
	int retorno = 0;
	int i;
	int contador = 0;
	int valorMax;

	if(listaArcade != NULL && lenArcade > 0 && id != 0)
	{
		retorno = 1;
		for(i = 0; i < lenArcade; i++)
		{
			if(listaArcade[i].isEmpty == 0 && listaArcade[i].idSalon == id)
			{
				contador += listaArcade[i].fichas;
			}
		}
		valorMax = contador * value;
		printf("El salon: %d acumularía $%d\n", id, valorMax);

	}

	return retorno;
}

/*G) Ingresar el nombre de un juego e imprimir cuantos arcades lo contienen.
 */

int contadorJuegos (Arcade *listaArcade, int lenArcade, char textoIngresado[], int* pContador)
{
	int retorno = -1;
	int i;
	int contador = 0;
//	char auxTexto[63];
	if (listaArcade != NULL && lenArcade > 0 && pContador != NULL)
	{
		for (i=0; i<lenArcade;i++)
		{
			if (listaArcade[i].isEmpty == 0)
			{
			//	strcpy(textoIngresado, listaArcade[i].nombre);
				// strlwr(textoIngresado);

				if(strncmp(listaArcade[i].nombre, textoIngresado,sizeof(listaArcade[i].nombre))==0)
				{
					contador++;
					retorno = 0;
				}
			}
		}
	}
	*pContador = contador;
	return retorno;
}

int informesTotales(Arcade *listaArcade, int lenArcade, Salon *listaSalones, int lenSalones)
{
	int retorno=-1;
	int seleccion;
	char nameAux[63];
	int contadorretorno;
	int auxFichas;
	int idFichas;
	int auxValor;
		printf("1)\nLos salones con más de 4 arcades:\n");
		printf("2)Los arcades con más de 2 jugadores\n");
		printf("3)Toda la información de un salón en específico.\n");
		printf("4)Todos los arcades de un salón determinado\n");
		printf("5)Salón con más cantidad de arcades\n");
		printf("6)Monto máximo en pesos que puede recaudar el salón\n");
		printf("7)Cuantos arcades lo contienen el mismo juego\n");

	utn_getNumeroInt(&seleccion, "Ingrese opcion a informar:\n", "Error",1 , 7, 1);

		switch(seleccion)
			{
			case 1:
				InformesA(listaArcade,lenArcade, listaSalones, lenSalones);
				break;
			case 2:
				InformeB(listaArcade, lenArcade, listaSalones, lenSalones);
				break;
			case 3:
				arc_imprimir_Array(listaArcade, lenArcade);
				InformeC(listaSalones, lenSalones,listaArcade, lenArcade);
				break;
			case 4:
				InformeD(listaArcade, lenArcade, listaSalones, lenSalones);
				break;
			case 5:
				InformeE(listaSalones, lenSalones,listaArcade, lenArcade);
				break;
			case 6:
				utn_getNumeroInt(&auxFichas, "Ingrese id del salon: \n", "Error",1 , 10000, 1);
					idFichas = salon_buscadorPID(listaSalones, lenSalones, auxFichas);

				utn_getNumeroInt(&auxValor, "Ingrese valor por ficha: \n", "Error",1 , 10000, 1);
					calcularValor(listaArcade, lenArcade, idFichas, auxValor);
				break;
			case 7:
				if(utn_getText(nameAux, 63 , "Ingrese el nombre: ", "Error",3)==0)
				{
					if(contadorJuegos (listaArcade, lenArcade,nameAux, &contadorretorno)==0)
					{
						printf("arcades con mismo nombre de juego: %d\n",contadorretorno);
					}
				}
				else
				{
					printf("Nombre del juego no existe!!\n");
				}
				break;
				}
		return retorno;
}
