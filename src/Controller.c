#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Perritos.h"
#include "validaciones.h"
#include "parser.h"
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int ok=-1;
	if(pArrayListEmployee!=NULL&&path!=NULL)
	{
		FILE* pFile;
		pFile= fopen(path, "r");
		if(pFile!=NULL)
		{
			ok=parser_EmployeeFromText(pFile,pArrayListEmployee);
		}
		fclose(pFile);
		pFile=NULL;
	}
    return ok;
}


int controller_ListPerrito(LinkedList* pArrayListEmployee)
{
	int ok=-1;
	int tam;
	int id;
	char nombre[128];
	char raza[21];
	int edad;
	float peso;
	ePerrito* perrito;
	tam=ll_len(pArrayListEmployee);
	printf( "-----------------------------------------------------------------------------------\n"
			"ID		NOMBRE  	PESO		EDAD		RAZA  -\n "
			"-----------------------------------------------------------------------------------\n");

	for(int i=0;i<tam;i++)
	{
		perrito=(ePerrito*)ll_get(pArrayListEmployee,i);
		perrito_getId(perrito,&id);
		perrito_getNombre(perrito,nombre);
		perrito_getEdad(perrito,&edad);
		perrito_getRaza(perrito,raza);
		perrito_getPeso(perrito,&peso);
		printf("%-10d	%-10s	%-10.2f	%-10d	%-10s\n",id,nombre,peso,edad,raza);
		ok=0;
	}
    return ok;
}


int controller_sortPerrito(LinkedList* pArrayListEmployee)
{
	printf("Acomodando espere esto puede tardar algunas horas\n");
	int (*pFuncionOrdenarNombre) (void* ,void* );
	pFuncionOrdenarNombre = &perrito_ordenarPorNombre;
	ll_sort(pArrayListEmployee,pFuncionOrdenarNombre,1);
    return 1;
}


int controller_perritosList(LinkedList* pArrayListEmployee)
{
	ePerrito* perrito;
	int ok=-1;
	int id;
	char nombre[128];
	char raza[21];
	int edad;
	float peso;
	float racion;
	int tam=ll_len(pArrayListEmployee);
	printf( "-----------------------------------------------------------------------------------\n"
				"ID		NOMBRE  	PESO		EDAD		RAZA 			RACION -\n "
				"-----------------------------------------------------------------------------------\n");
	for(int i=0;i<tam;i++)
	{
		perrito=(ePerrito*)ll_get(pArrayListEmployee,i);
		perrito_getId(perrito,&id);
		perrito_getNombre(perrito,nombre);
		perrito_getEdad(perrito,&edad);
		perrito_getRaza(perrito,raza);
		perrito_getPeso(perrito,&peso);
		perrito_getRacion(perrito,&racion);
		printf("%-10d	%-10s	%-10.2f	%-10d	%-10s			%-10.2f\n",id,nombre,peso,edad,raza,racion);
		ok=0;
	}
	return ok;
}

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int ok=-1;
	int len;
	int id;
	int edad;
	char nombre[128];
	char raza[21];
	ePerrito* perrito=NULL;
	perrito_getId(perrito,&id);
	perrito_getNombre(perrito,nombre);
	perrito_getRaza(perrito,raza);
	perrito_getEdad(perrito,&edad);
	FILE* pFile= fopen(path,"w");
	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		len=ll_len(pArrayListEmployee);
		if(pFile!=NULL)
		{
			fprintf(pFile, "%s", "id,nombre,raza,edad\n");
			for(int i=0;i<len;i++)
			{
				perrito=(ePerrito*)ll_get(pArrayListEmployee, i);
				fprintf(pFile, "%d,%s,%s,%d\n",perrito->id,perrito->nombre,perrito->raza,perrito->edad);
			}
			fclose(pFile);
			pFile=NULL;
			perrito=NULL;
			ok=0;
		}
	}

    return ok;
}




int controller_perritoRacion(LinkedList* this)
{
	int ok=-1;
	if(this!=NULL)
	{
		int (*pFuncionOrdenarRacion) (void*);
		pFuncionOrdenarRacion = &ePerrito_laQueMapea;
		ll_map(this,pFuncionOrdenarRacion);
		ok=0;
	}
	return ok;

}



int controller_perritoFiltrar(LinkedList* this)
{
	//int (*pFuncionFiltrar) (void*);
	int (*pFuncionOrdenarNombre) (void* );
	pFuncionOrdenarNombre = &ePerrito_laQueFiltra;
	int ok=-1;
	LinkedList* aux=NULL;
	if(this!=NULL)
	{
		printf("Acomodando espere esto puede tardar algunas horas\n");
		//pFuncionFiltrar = &ePerrito_laQueFiltra;
		aux=ll_filter(this,pFuncionOrdenarNombre);
		int id;
		char nombre[128];
		char raza[21];
		int edad;
		float peso;
		float racion;
		ePerrito* perrito;
		int tam=ll_len(aux);
		printf( "-----------------------------------------------------------------------------------\n"
		"ID		NOMBRE  	PESO		EDAD		RAZA 			RACION -\n "
		"-----------------------------------------------------------------------------------\n");
		for(int i=0;i<tam;i++)
		{
			perrito=(ePerrito*)ll_get(aux,i);
			perrito_getId(perrito,&id);
			perrito_getNombre(perrito,nombre);
			perrito_getEdad(perrito,&edad);
			perrito_getRaza(perrito,raza);
			perrito_getPeso(perrito,&peso);
			perrito_getRacion(perrito,&racion);
			printf("%-10d	%-10s	%-10.2f	%-10d	%-10s			%-10.2f\n",id,nombre,peso,edad,raza,racion);
		}
		ok=0;
	}
	return ok;

}



