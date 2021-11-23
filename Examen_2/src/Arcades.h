#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#define NOMBRELEN 63
#include "LinkedList.h"
//id,nacionalidad,tipo_sonido,cant_jug,fichas_max,salon,game
typedef struct
{
    int id;
    char nacionalidad[NOMBRELEN];
    char tipo[NOMBRELEN];
    int jugadores;
    int fichas;
    char salon[NOMBRELEN];
    char game[NOMBRELEN];
}Arcades;

Arcades* arcade_new(void);
Arcades* arcade_newParametros(char* idStr,char* nacionalidadStr,char* tipoStr, char* jugadoresStr, char* fichasStr,char* salonStr, char* juegoStr);

Arcades* arcade_newParametrosAdd(int idStr,char* nacionalidadStr,char* tipoStr, int jugadoresStr, int fichasStr,char* salonStr,char* juegoStr);

void arcade_delete();

int arcade_setId(Arcades* this,int id);
int arcade_getId(Arcades* this,int* id);

int arcade_setNacionalidad(Arcades* this,char* nacionalidad);
int arcade_getNacionalidad(Arcades* this,char* nacionalidad);

int arcade_setTipo(Arcades* this,char* tipo);
int arcade_getTipo(Arcades* this,char* tipo);

int arcade_setFichas(Arcades* this,int fichas);
int arcade_getFichas(Arcades* this,int* fichas);

int arcade_setJugadores(Arcades* this,int jugadores);
int arcade_getJugadores(Arcades* this,int* jugadores);

int arcade_setSalon(Arcades* this,char* salon);
int arcade_getSalon(Arcades* this,char* salon);

int arcade_setJuego(Arcades* this,char* juego);
int arcade_getJuego(Arcades* this,char* juego);


int arcade_imprimir(Arcades* auxEmpleado, int indice);
int Imprimir_Juegos(LinkedList* listaArcade);

#endif // arcade_H_INCLUDED
