#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
typedef struct
{
	int id;
	char nombre [21];
	float peso;
	int edad;
	char raza [21];
	float cantidadComidaRacion;
}ePerrito;

typedef struct
{
	int id;
	char nombre [21];
	float peso;
	int edad;
	char raza [21];
	float cantidadComidaRacion;
}ePerritoDos;

ePerrito* perrito_new();
ePerrito* perrito_newParametros(char* idStr,char* nombreStr,char* razaStr,char* peso,char* edad);

void perrito_delete();

int perrito_setId(ePerrito* this,int id);
/*
 * brief Esta funcion se encarga de ingresar un id a la estructura employee
 * param Recibe un puntero a la estructura employee
 * param Recibe el id que se le debe ingresar
 * return Retorna 0 si salio bien o -1 si salio mal
 * */
int perrito_getId(ePerrito* this,int* id);
/*
 * brief Esta funcion se encarga de mostrar el ID de la estructura
 * param Recibe como puntero a la estructura employee
 * param Recibe como puntero la id
 * return Retorna el id
 * */

int perrito_setNombre(ePerrito* this,char* nombre);

/*
 * brief Esta funcion se encarga de ingresar un nombre a la estructura employee
 * param Recibe un puntero a la estructura employee
 * param Recibe el nombre que se le debe ingresar
 * return Retorna 0 si salio bien o -1 si salio mal
 * */
int perrito_getNombre(ePerrito* this,char* nombre);

/*
 * brief Esta funcion se encarga de mostrar el nombre de la estructura
 * param Recibe como puntero a la estructura employee
 * param Recibe como puntero el nombre
 * return Retorna el nombre
 * */


int perrito_setRaza(ePerrito* this,char* nombre);

/*
 * brief Esta funcion se encarga de ingresar un nombre a la estructura employee
 * param Recibe un puntero a la estructura employee
 * param Recibe el nombre que se le debe ingresar
 * return Retorna 0 si salio bien o -1 si salio mal
 * */
int perrito_getRaza(ePerrito* this,char* nombre);

/*
 * brief Esta funcion se encarga de mostrar el nombre de la estructura
 * param Recibe como puntero a la estructura employee
 * param Recibe como puntero el nombre
 * return Retorna el nombre
 * */


int perrito_setEdad(ePerrito* this,int edad);

/*
 * brief Esta funcion se encarga de ingresar horas a la estructura employee
 * param Recibe un puntero a la estructura employee
 * param Recibe la cantidad de horas que se le debe ingresar
 * return Retorna 0 si salio bien o -1 si salio mal
 * */

int perrito_getEdad(ePerrito* this,int* edad);

/*
 * brief Esta funcion se encarga de mostrar las horas de la estructura
 * param Recibe como puntero a la estructura employee
 * param Recibe como puntero las horas
 * return Retorna las horas
 * */




int perrito_setPeso(ePerrito* this,float peso);

/*
 * brief Esta funcion se encarga de ingresar horas a la estructura employee
 * param Recibe un puntero a la estructura employee
 * param Recibe la cantidad de horas que se le debe ingresar
 * return Retorna 0 si salio bien o -1 si salio mal
 * */

int perrito_getPeso(ePerrito* this,float* peso);

/*
 * brief Esta funcion se encarga de mostrar las horas de la estructura
 * param Recibe como puntero a la estructura employee
 * param Recibe como puntero las horas
 * return Retorna las horas
 * */


int ePerrito_laQueMapea(void* pUno);
/*
 * brief Esta funcion se encarga de mostrar las horas de la estructura
 * param Recibe como puntero a la estructura employee
 * param Recibe como puntero las horas
 * return Retorna las horas
 * */
int perrito_setRacion(ePerrito* this,float racion);

/*
 * brief Esta funcion se encarga de mostrar las horas de la estructura
 * param Recibe como puntero a la estructura employee
 * param Recibe como puntero las horas
 * return Retorna las horas
 * */

int perrito_getRacion(ePerrito* this,float* racion);

/*
 * brief Esta funcion se encarga de mostrar las horas de la estructura
 * param Recibe como puntero a la estructura employee
 * param Recibe como puntero las horas
 * return Retorna las horas
 * */

int perrito_ordenarPorNombre(void* pUno,void* pDos);

/*
 * brief Esta funcion se encarga de ordenar por nombre
 * param recibe como parametro pUno
 * param recibe como parametro pDos
 * return Puede retornar -1, 1 o 0 segun el orden
 * */

int ePerrito_laQueFiltra(void* pElement);

int perrito_ordenarPorNombreDos(void* pUno);
#endif // employee_H_INCLUDED
