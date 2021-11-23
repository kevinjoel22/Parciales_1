
int controller_loadFromText(char* path , LinkedList* pArrayListArcade);
int controller_addArcade(LinkedList* pArrayListArcade, int *id);
int controller_editArcade(LinkedList* pArrayListArcade);
int controller_removeArcade(LinkedList* pArrayListArcade);
int controller_ListArcade(LinkedList* pArrayListArcade);
int controller_sortArcade(LinkedList* pArrayListArcade);
int controller_saveAsText(char* path , LinkedList* pArrayListArcade);


int Arcade_imprimirArray(LinkedList* pArrayListArcade);
int Controller_buscarById(LinkedList* pArrayListArcade, int IdBuscado);


int OrdenamientoPorNombre(void* empleadoZ, void*empleadoX);
int OrdenamientoPorhora(void* empleadoZ, void* empleadoX);
int OrdenamientoPorSueldo(void* empleadoZ,void* empleadoX);

int controller_guardarJuegos(char* path , LinkedList* pArrayListArcade);
int controlerFiltratumama(LinkedList* pArrayListArcade);
int archivoMultijugador(void*pArrayListArcade);
int actualizarCantidadFichas(LinkedList* pArrayListArcade);
void fichasDuplicadas(void* pArrayListArcade);
int OrdenamientoPorSueldo(void* empleadoZ,void* empleadoX);

int buscarIndice(LinkedList* pArrayListArcade, int id);
//sint controller_asignarId(LinkedList* pArrayListArcade,int* numeroId);
