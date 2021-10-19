/*
 * Employe.h
 *
 *  Created on: 11 oct. 2021
 *      Author: KEVIN
 */

#include <stdio.h>
#include <stdlib.h>
#ifndef ARCADE_H_
#define ARCADE_H_

#define NOMBRE_Y_APELLIDO_LEN 63
typedef struct{
	char nacionalidad[NOMBRE_Y_APELLIDO_LEN];
	char nombre[NOMBRE_Y_APELLIDO_LEN];
	int idArcade;
	int idSalon;
	int fichas;
	int jugadores;
	int tipoA;
	int isEmpty;
}Arcade;

int arc_Inicializar(Arcade lista[],int len);
int arc_Cargar(Arcade *pArcade,int len, int indice,int *idArcade, int idSalon);
int arc_buscadorPorID(Arcade* pArcade, int len, int IdBuscado);
int arc_Imprimir(Arcade* pArcade);
int bucarLibre(Arcade* pArcade, int len);
int arc_EliminarPor_Id(Arcade pArcade[], int len, int IdBuscado);
int arc_modificar(Arcade* pArcade,int len,int idModificar);
int arc_imprimir_Array(Arcade* pArcade, int len);
int arc_imprimir(Arcade* pArcade);
int Arc_cargarForzada(Arcade* pArcade,int len, int indice,int *IdArcade, int IdSalon, char *NombreJ, char *nacionalidad, int fichas,int jugadores,int tipo);
int arcJuegos_imprimir(Arcade* pArcade);
int arcJuegos_imprimir_Array(Arcade* pArcade, int len);
int selecionarOpcion(void);
int Imprimir_Juegos(Arcade* list, int len);
int arc_probarimprimir(Arcade* pArcade,int len);
#endif /* EMPLOYE_H_ */
