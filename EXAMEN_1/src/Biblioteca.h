/*
 * Biblioteca.h
 *
 *  Created on: 7 oct. 2021
 *      Author: KEVIN
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_
int utn_getText(char pResultado[],int lenght, char* variableTexto, char* textoError,int reintentos);
int utn_getText(char pResultado[], int len, char* mensaje, char* mensajeError, int reintentos);
int utn_getNumeroInt (int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFloat (float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

#endif /* BIBLIOTECA_H_ */
