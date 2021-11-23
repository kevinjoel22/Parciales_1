#include <stdio.h>
#include <stdlib.h>

#include "Arcades.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Biblioteca.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
#define CANTIDAD_EMPLEADOS 1000
int main()
{
	setbuf(stdout, NULL);

    int option = 0;
    int idmax;
    Arcades* arcade;
    LinkedList* listaArcades = ll_newLinkedList();

    do{
    	puts("1. Cargar los datos de los arcades desde el archivo data.csv (modo texto).");
		puts("2. Alta de arcade");
		puts("3. Modificar arcade");
		puts("4. Eliminar arcade");
		puts("5. Imprimir arcade");
		puts("6. Generar archivo con juegos");
		puts("7. Generar un archivo con arcades MULTIJUGADOR");
		puts("8. actualizar cantidad de fichas");
		puts("9. Salir");
    	utn_getNumeroInt (&option, "Ingrese una opcion:\n", "Error, opcion invalidad\n", 1, 9, 2);

        switch(option)
        {
            case 1:
                if(controller_loadFromText("arcades.csv",listaArcades)==0)
                {
                	printf("se cargaron los datos\n");
                	arcade=(Arcades*)ll_get(listaArcades,ll_len(listaArcades)-1 );
                	arcade_getId(arcade, &idmax);
                }
                else
                {
                	puts("No hay datos que guardados");
                }
                break;
           case 2:
            	//alta de empleados
				if(controller_addArcade(listaArcades,&idmax)==0)
				{
					puts("Se cargo correctamente el empleado");

					if(controller_saveAsText("arcades.csv", listaArcades)==0)
					{
						puts("Se guardo correctamente");
					}
					else
					{
						puts("error, en guardar arcades");
					}
				}
				else
				{
					puts("No se pudo carfar el empleado");
				}
            	break;
           case 3:
            	if(controller_editArcade(listaArcades)==0)
            	{
            		puts("Se modifico correctamente");
            		if(controller_saveAsText("arcades.csv", listaArcades)==0)
					{
						puts("Se guardo correctamente");
					}
					else
					{
						puts("error, en guardar arcades");
					}
            	}
            	else
            	{
            		puts("No se pudo modificar");
            	}
            	break;
           case 4:
        	   if(controller_removeArcade(listaArcades)==0)
        	   {
        		   puts("se elimino correctamente");

        		   if(controller_saveAsText("arcades.csv", listaArcades)==0)
					{
						puts("Se guardo correctamente");
					}
					else
					{
						puts("error, en guardar arcades");
					}
        	   }
        	   else
        	   {
        		   puts("no se pudo eliminar");
        	   }
        	   break;
           case 5:
            	if(controller_sortArcade(listaArcades)==0)
            	{
            		puts("Se listo correctamente");
            	}
            	else{
            		puts("No hay nada que listar");
            	}
            	break;
            case 6:
            	if(controller_guardarJuegos("juegos.txt",listaArcades)==0)
            	{
            		puts("Se guardo los juegos correctamente");
            	}
            	else
            	{
            		puts("no se pudo guardar los juegos");
            	}
            	break;
            case 7:
            	if(controlerFiltratumama(listaArcades)==0)
            	{
            		puts("salio guardar en text del multijugador");
            	}
            	else
            	{
            		puts("No se pudo guardar el multijugador");
            	}
            	break;
            case 8:
            	actualizarCantidadFichas(listaArcades);
            	break;
            case 9:
            	puts("Salir");
            	break;
        }
    }while(option != 10);
    return 0;
}
