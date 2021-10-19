/*
 * Informes.h
 *
 *  Created on: 16 oct. 2021
 *      Author: KEVIN
 */

#include <stdio.h>
#include <stdlib.h>
#ifndef INFORMES_H_
#define INFORMES_H_
#include "Salon.h"
#include "Arcade.h"
#define LARGO_NOMBRE 63

int menu(void);
void informe_listajuegos( Arcade listaArcade[], int lenArcade);
int InformeA(Salon listaSalon[], int lensalon, Arcade listaArcade[], int lenArcade, int id);
int InformesA(Arcade *listaArcade, int lenArcade, Salon *listaSalon, int lenSalon);
int InformeB(Arcade *listaArcade, int lenArcade, Salon *listaSalon, int lenSalon);
int InformeC(Salon * listaSalones, int lenSalones, Arcade *listaArcade, int lenArcade);
int InformeD(Arcade *listaArcade, int lenArcade, Salon *listaSalones, int lenSalones);
int InformeE(Salon * listaSalones, int lenSalones, Arcade *listaArcade, int lenArcade);
int imprimirFacturacionPorCliente (Salon *listaSalones, int lenSalones,Arcade *listaArcade,int lenArxace);
int contadorJuegos (Arcade *listaArcade, int lenArcade, char textoIngresado[], int* pContador);
int calcularValor(Arcade* listaArcade, int lenArcade, int id, int value);
int informesTotales(Arcade *listaArcade, int lenArcade, Salon *listaSalones, int lenSalones);

#endif /* INFORMES_H_ */
