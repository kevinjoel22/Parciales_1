/*
 * parser.h
 *
 *  Created on: 1 nov. 2021
 *      Author: Usuario
 */

#ifndef PARSERH
#define PARSERH


#endif /* PARSERH */
#include "Controller.h"
#include "LinkedList.h"
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_ArcadeFromTextLectura(FILE* pFile , LinkedList* pArrayListArcade);
/**\brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_ArcadeFromTextEscritura(FILE* pFile , LinkedList* pArrayListArcade);

int parser_ArcadeFromTextLecturaJuegos(FILE* pFile , LinkedList* pArrayListArcade);
