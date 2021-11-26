int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
/*
 * brief se encarga de traer los datos del archivo en modo texto .csv
 * param Recibe como parametro el nombre del archivo
 * param Recibe como parametro el linkedlist
 * */


int controller_ListPerrito(LinkedList* pArrayListEmployee);
/*
 * Esta funcion se encarga de listar los empleados
 * param Recibe como parametro el linkedlist
 * */
int controller_sortPerrito(LinkedList* pArrayListEmployee);
/*
 * Esta funcion se encarga de ordenar los empleados
 * param Recibe como parametro el linkedlist
 * */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
/*
 * Esta funcion se encarga de guardar en texto los empleados
 * param Recibe como parametro el linkedlist
 * */


int controller_perritoRacion(LinkedList* this);
int controller_perritosList(LinkedList* pArrayListEmployee);
int controller_perritoFiltrar(LinkedList* this);
int controller_perritoMostrarFiltrado(LinkedList* this);
