/*
 ============================================================================
 Name        : EXAMEN_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Salon.h"
#include "Biblioteca.h"
#include "Arcade.h"
#include "Informes.h"
#define LEN_SALONES 100
#define LEN_ARCADE 1000
#define LEN_JUEGOS 1000
int main(void) {
	setbuf(stdout,NULL);
	int opcion1;
	int idarcade;
	int indexarcade;
	int idauxarcade;
	int idSalon=0;
	int idArcade=0;
	int indexModificar;
	int idModificar;
	int indexEliminar;
	int idAEliminar;
	int contadorSalon=0;
	int contadorArcade=0;

	Salon salon[LEN_SALONES];
	Arcade arcade[LEN_ARCADE];

	salon_Inicializar(salon ,LEN_SALONES);
	arc_Inicializar(arcade, LEN_ARCADE);



	salon_altaForazada(salon ,LEN_SALONES, 0, &idSalon, 0 , "salon 1","zapiolaasd");
	salon_altaForazada(salon ,LEN_SALONES, 1, &idSalon, 1  , "salon 2","9 de julio");
	salon_altaForazada(salon ,LEN_SALONES, 2, &idSalon, 0, "salon 3","corrientes");
	salon_altaForazada(salon ,LEN_SALONES, 3, &idSalon, 1 , "salon 4","montiel");
	salon_altaForazada(salon ,LEN_SALONES, 4, &idSalon, 0  , "salon 5","bragado");

	Arc_cargarForzada(arcade, LEN_ARCADE, 0, &idArcade, 1, "metal slug", "Argentina", 10, 1, 68);
	Arc_cargarForzada(arcade, LEN_ARCADE, 1, &idArcade, 2, "contra", "China", 5, 0, 3);
	Arc_cargarForzada(arcade, LEN_ARCADE, 2, &idArcade, 3, "cars", "chile", 20, 1,9);
	Arc_cargarForzada(arcade, LEN_ARCADE, 3, &idArcade, 4, "pacman", "uruguay", 3, 0, 15);
	Arc_cargarForzada(arcade, LEN_ARCADE, 4, &idArcade, 5, "circus", "colombia", 15, 1, 10);

	Arc_cargarForzada(arcade, LEN_ARCADE, 5, &idArcade, 1, "metal slug", "Argentina", 10, 1, 68);
	Arc_cargarForzada(arcade, LEN_ARCADE, 6, &idArcade, 1, "contra", "China", 5, 0, 3);
	Arc_cargarForzada(arcade, LEN_ARCADE, 7, &idArcade, 1, "cars", "chile", 20, 1,9);
	Arc_cargarForzada(arcade, LEN_ARCADE, 8, &idArcade, 1, "pacman", "uruguay", 3, 0, 15);
	Arc_cargarForzada(arcade, LEN_ARCADE, 9, &idArcade, 1, "circus", "colombia", 15, 1, 10);

		do{
			opcion1 = menu();

			int libre;
			int libreArc;


			switch(opcion1)
			{
			case 1:
					libre = salon_bucarLibre(salon, LEN_SALONES);
					if(libre>=0)
					{
						salon_cargar(&salon[libre]);
						contadorSalon++;
					}
					else
					{
						printf("No hay mas espacio\n");
					}
				break;
			case 2:
				//if(contadorSalon > 0)
				{
					for(int i=0; i< LEN_SALONES ;i++)
					{
						salon_imprimir(&salon[i]);
					}
						int idDarBaja;
						int indexBaja;
						if(utn_getNumeroInt(&idDarBaja, "Ingrese ID a dar baja:  ", "Error",0,100 , 3)==0)
						{
							indexBaja = salon_buscadorPID(salon, LEN_SALONES, idDarBaja);
							if(indexBaja >=0)
							{
							salon_EliminarPor_Id(salon, LEN_SALONES, indexBaja);
							contadorSalon--;
							}
							else
							{
								printf("ID NO EXISTE!!");
							}
						}
						else
						{
							printf("ID fuera de rango!!\n");
						}
				}
				/*else
				{
					printf("No hay salones cagados\n");
				}*/
				break;
			case 3:
				//if(contadorSalon>0)
				{
					salon_imprimir_Array(salon, LEN_SALONES);
				}
				/*else
				{
					printf("No hay Salones ingresados\n");
				}*/
				break;
			case 4:
				//if( contadorArcade < LEN_ARCADE && contadorSalon>0)
				{
					libreArc = bucarLibre(arcade, LEN_ARCADE);
					if(libreArc >= 0)
					{
						salon_imprimir_Array(salon, LEN_SALONES);
						if(utn_getNumeroInt(&idarcade , "Elija ID:  ", "Error",0,100 , 3)==0)
						{
							indexarcade= salon_buscadorPID(salon, LEN_SALONES, idarcade );
							if(indexarcade>=0)
							{
							arc_Cargar(arcade, LEN_ARCADE, libreArc, &idauxarcade ,idarcade);
							contadorArcade++;
							}
							else
							{
								printf("ERROR, ID NO EXISTE!!\n");
							}
						}
						else
						{
							printf("ERROR, ID fuera de rango!!");
						}
					}
					else
					{
						printf("No hay mas espacio!!\n");
					}
				}
				/*else
				{
					printf("ERROR, No hay salones ingresados\n");
				}*/
				break;
			case 5:
				//if(contadorArcade>0)
				{
					arc_imprimir_Array(arcade, LEN_ARCADE);
					if(utn_getNumeroInt(&indexModificar, "Elija ID: \n", "Error\n",0,100 , 3)==0)
					{
					idModificar = arc_buscadorPorID(arcade, LEN_ARCADE, indexModificar);

						if(idModificar >= 0)
						{
						arc_modificar(arcade ,LEN_ARCADE, idModificar);
						}
						else
						{
							printf("ERROR, ID NO EXISTE!!\n");
						}
					}
					else
					{
						printf("ERROR, ID fuera de rango!!\n");
					}
				}
			/*	else
				{
				printf("No hay arcades ingresados!!\n");
				}*/
				break;
			case 6:
				//if(contadorArcade>0)
				{
					arc_imprimir_Array(arcade, LEN_ARCADE);
					if(utn_getNumeroInt(&indexEliminar, "Elija ID: \n", "Error\n",0,100 , 3)==0)
					{
					idAEliminar = arc_buscadorPorID(arcade, LEN_ARCADE, indexEliminar);
						if(idModificar >= 0)
						{
							if(selecionarOpcion()==1)
							{
							arc_EliminarPor_Id(arcade, LEN_ARCADE, idAEliminar);
							contadorArcade--;
							}
							else
							{
							printf("No se dio la baja\n");
							}
						}
						else
						{
							printf("ID no existe!!\n");
						}
					}
					else
					{
						printf("Error, id fuera de rango!!\n");
					}
				}
				/*else
				{
					printf("No hay arcades ingresados!!\n");
				}*/
				break;
			case 7:
				//if(contadorArcade>0)
				{
					arc_imprimir_Array(arcade, LEN_ARCADE);
				}
				/*else
				{
					printf("No hay arcades ingresados!!\n");
				}*/
				break;
			case 8:
			//	if(contadorArcade>0)
				{
					Imprimir_Juegos(arcade, LEN_ARCADE);
				}
			/*	else
				{
					printf("no hay arcades ingresados!!\n");
				}*/
				break;
			case 9:
			//	if(contadorArcade > 0  )
				{
					informesTotales(arcade, LEN_ARCADE, salon, LEN_SALONES);
				}
				/*else
				{
					printf("No hay salones ni arcades ingresados!!\n");
				}*/
				break;
			case 10:
				printf("Salir\n");
				 break;
			}
		}while(opcion1 != 10);

	return EXIT_SUCCESS;
}

