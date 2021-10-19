/*
 * UTN_Biblioteca.h
 *
 *  Created on: 7 sep. 2021
 *      Author: KEVIN
 */
#include <stdio.h>
#include <stdlib.h>

#ifndef SALON_H_
#define SALON_H_

#define NOMBRE_DIRECCION_LEN 128

typedef struct {
	char nombre[NOMBRE_DIRECCION_LEN];
	char direccion[NOMBRE_DIRECCION_LEN];
	int tipo;
	int id;
	int flagEmpty;
}Salon;

int salon_Inicializar(Salon pSalon[],int len);
int salon_bucarLibre(Salon* pSalon, int len);
int salon_cargar(Salon *pSalon);
int salon_imprimir(Salon* pSalon);
int salon_imprimir_Array(Salon* pSalon, int len);
int salon_buscadorPID(Salon* pSalon, int len, int IdBuscado);
int salon_EliminarPor_Id(Salon pSalon[], int len, int IdBuscado);
int salon_pedirID(void);
int salon_altaForazada(Salon *array, int len, int indice, int *id, int typee, char *name, char *address);

#endif /* PANTALLA_H_ */
