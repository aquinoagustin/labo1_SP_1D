#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Perritos.h"
#include "validaciones.h"

int main(void) {
	setbuf(stdout,NULL);
		int flag=0;
		int flag2=0;
	    int option = 0;
	    LinkedList* listaPerritos = ll_newLinkedList();
	    do{
	    	utn_getEntero(&option,100,
	    			   "1. Cargar los datos de los perritos desde el archivo data.csv (modo texto)\n"
	    	    	   "2. Leer los perritos de manera ASC por nombre\n"
	    	    	   "3. Calcular Racion de comida\n"
	    	    	   "4.Listar los perritos con sus raciones de comida.\n"
	    	    	   "5. Generar una lista con los perros raza Galgo\n\n"
	    	    	   "6. Guardar en un archivo llamado galgosFlaquitos.csv\n"
	    	    	   "Eliga una opcion:","Error\n",1,10);
	        switch(option)
	        {
	            case 1:
	            	clear();
	            	if(!flag)
	            	{
	                    if(!controller_loadFromText("perritos200.csv",listaPerritos))
	                    {
	                    	printf("Archivo cargado con exito!!!\n");
	                    	flag=1;
	                    }
	                    else
	                    {
	                    	printf("Error no se pudo cargar el archivo\n");
	                    }
	            	}
	            	else
	            	{
	            		printf("Ya cargo el archivo\n");
	            	}
	                systemPause();
	                break;
	            case 2:
	            	clear();
	            	if(flag)
	            	{
	            		controller_sortPerrito(listaPerritos);
	            		controller_ListPerrito(listaPerritos);
	            	}
	            	else
	            	{
	            		printf("Primero cargue el Archivo\n");
	            	}

	            	systemPause();
	            	break;
	            case 3:
	            	clear();
	            	if(flag)
	            	{
	            		if(!flag2)
	            		{
	            			printf("Raciones calculadas\n");
	            			controller_perritoRacion(listaPerritos);
	            			flag2=1;
	            		}
	            		else
	            		{
	            			printf("Ya cargo las raciones\n");
	            		}
	            	}
	            	else
	            	{
	            		printf("Primero cargue el Archivo\n");
	            	}

	            	systemPause();
	            	break;
	            case 4:
	            	clear();
	            	if(flag)
	            	{
	            		if(flag2)
	            		{
	            			controller_perritosList(listaPerritos);
	            		}
	            		else
	            		{
	            			printf("Primero tiene que calcular las raciones\n");
	            		}

	            	}
	            	else
	            	{
	            		printf("Primero cargue el Archivo\n");
	            	}
	            	systemPause();
	            	break;
	            case 5:
	            	clear();
	            	if(flag)
					{
	            		if(flag2)
	            		{
	            			controller_perritoFiltrar(listaPerritos);
	            			//controller_perritoMostrarFiltrado(ll_filter(this,pFuncionFiltrar));
	            		}
	            		else
	            		{
	            			printf("Primero tiene que calcular las raciones\n");
	            		}

					}
					else
					{
						printf("Primero cargue el Archivo\n");
					}
	            	systemPause();
	            	break;
	            case 6:
	            	clear();
					if(flag)
					{

					}
					else
					{
						printf("Primero cargue el Archivo\n");
					}
					systemPause();
	            	break;
	            case 8:
	            	clear();
	            	if(flag)
	            	{
	            		if(!controller_saveAsText("perritos.txt" ,listaPerritos))
						{
							printf("Archivo guardado con exito\n");
						}
						else
						{
							printf("Error, no se guardaron los cambios\n");
						}
	            	}
	            	else
	            	{
	            		printf("Primero cargue el archivo\n");
	            	}
	            	systemPause();
	            	break;
	        }
	    }
	    while(option != 11);
	    return 0;
	return EXIT_SUCCESS;
}
