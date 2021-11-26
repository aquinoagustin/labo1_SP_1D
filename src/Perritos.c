#include "Perritos.h"
#include "LinkedList.h"
#include "validaciones.h"
ePerrito* perrito_new()
{
	ePerrito* perrito = NULL;
	perrito = (ePerrito*) malloc (sizeof(ePerrito));
	return perrito;
}

ePerrito* perrito_newParametros(char* idStr,char* nombreStr,char* razaStr,char* peso,char* edad)
{
	ePerrito* perrito = NULL;
	perrito = perrito_new();
	if(perrito != NULL)
	{
		perrito_setId(perrito,atoi(idStr));
		perrito_setNombre(perrito,nombreStr);
		perrito_setRaza(perrito,razaStr);
		perrito_setPeso(perrito,atof(peso));
		perrito_setEdad(perrito,atoi(edad));
	}
	return perrito;
}


int perrito_setId(ePerrito* this,int id)
{
	int ok=-1;
	if(this!=NULL)
	{
		this->id=id;
		ok=0;
	}
	return ok;
}


int perrito_getId(ePerrito* this,int* id)
{
	if(this!=NULL)
	{
		*id=this->id;
	}
	return* id;
}

int perrito_setNombre(ePerrito* this,char* nombre)
{
	int ok=-1;
	if(this!=NULL)
	{
		strcpy(this->nombre,nombre);
		ok=0;
	}
	return ok;
}

int perrito_getNombre(ePerrito* this,char* nombre)
{
	if(this!=NULL)
	{
		strcpy(nombre,this->nombre);
	}
	return *nombre;
}


int perrito_setRaza(ePerrito* this,char* raza)
{
	int ok=-1;
	if(this!=NULL)
	{
		strcpy(this->raza,raza);
		ok=0;
	}
	return ok;
}


int perrito_getRaza(ePerrito* this,char* raza)
{
	if(this!=NULL)
	{
		strcpy(raza,this->raza);
		raza=this->raza;
	}
	return *raza;
}



int perrito_setEdad(ePerrito* this,int edad)
{
	int ok=-1;
	if(this!=NULL)
	{
		this->edad=edad;
		ok=0;
	}
	return ok;
}

int perrito_getEdad(ePerrito* this,int* edad)
{
	if(this!=NULL)
	{
		*edad=this->edad;
	}
	return* edad;
}


int perrito_setPeso(ePerrito* this,float peso)
{
	int ok=-1;
	if(this!=NULL)
	{
		this->peso=peso;
		ok=0;
	}
	return ok;
}

int perrito_getPeso(ePerrito* this,float* peso)
{
	if(this!=NULL)
	{
		*peso=this->peso;
	}
	return* peso;
}



int perrito_setRacion(ePerrito* this,float racion)
{
	int ok=-1;
	if(this!=NULL)
	{
		this->cantidadComidaRacion=racion;
		ok=0;
	}
	return ok;
}

int perrito_getRacion(ePerrito* this,float* racion)
{
	if(this!=NULL)
	{
		*racion=this->cantidadComidaRacion;
	}
	return* racion;
}



int perrito_ordenarPorNombre(void* pUno,void* pDos)
{
	int ok=2;
	ePerrito* auxNombre = (ePerrito*)pUno;
	ePerrito* auxNombreDos = (ePerrito*)pDos;
	char nombre[21];
	char nombreDos[21];
	perrito_getNombre(auxNombre,nombre);
	perrito_getNombre(auxNombreDos,nombreDos);
	ok=strcmp(nombre,nombreDos);
	auxNombre=NULL;
	auxNombreDos=NULL;
	return ok;
}


int ePerrito_laQueMapea(void* pUno)
{
	int ok=1;
	float peso;
	float racion;
	ePerrito* perrito = (ePerrito*)pUno;

	perrito_getPeso(perrito,&peso);
	perrito_getRacion(perrito,&racion);
	if(perrito!=NULL)
	{
		racion=peso*23;
		perrito_setRacion(perrito,racion);

		ok=0;
	}
	return ok;
}



int ePerrito_laQueFiltra(void* pElement)
{
	int ok=0;
	char raza[21];
	int edad;
	float racion;
	ePerrito* perrito = (ePerrito*)pElement;
	perrito_getRaza(perrito,raza);
	perrito_getRacion(perrito,&racion);
	perrito_getEdad(perrito,&edad);
	if(perrito!=NULL)
	{
		if(strcmp(raza,"Galgo")==0&&edad>10&&racion<200)
		{
			ok=1;
		}
	}
	return ok;
}



