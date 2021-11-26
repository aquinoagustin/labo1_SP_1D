#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Perritos.h"
#include "parser.h"
#include "validaciones.h"
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int ok=-1;
	char id[10];
	char nombre[128];
	char raza[21];
	char edad[10];
	char peso[10];
	if(pFile != NULL){
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]",id,nombre,peso,edad,raza);
		while(!feof(pFile)){
			ePerrito* perrito;
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]",id,nombre,peso,edad,raza);
			if(feof(pFile))
			{
				break;
			}
			perrito=perrito_newParametros(id,nombre,raza,peso,edad);
			ll_add(pArrayListEmployee,perrito);
		}
		ok=0;
		fclose(pFile);
	}
	pFile=NULL;

return ok;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int ok=-1;
	if(pFile != NULL){
		while(!feof(pFile))
		{
			ePerrito* perrito=perrito_new();
			fread(perrito,sizeof(ePerrito),1,pFile);
			if(feof(pFile))
			{
				break;
			}
			ll_add(pArrayListEmployee,perrito);
		}

		fclose(pFile);
		ok=0;
	}
	pFile = NULL;
    return ok;
}
