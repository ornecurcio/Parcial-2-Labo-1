#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Libro.h"
#include "UTN.h"
int menu(void)
{
		int option;
	    int flag=0;


	    LinkedList* eLibros = ll_newLinkedList();

	    printf("------------ /BIENVENIDO/ -------------\n");
	    do{
	    	if(utn_getNumero(&option,"-------- Seleccione una opcion --------\n"
	    			"1. Cargar Archivo\n"
	    			"2. Imprimir Listado\n"
	    			"3. Generar Archivo de montos\n4. Informes\n5. Salir\n",
	    					"------- Error ingrese ------ \n"
					"1. Cargar Archivo\n"
				    "2. Imprimir Ventas\n"
				    "3. Generar Archivo de montos\n4. Informes\n5. Guardar Listado\n6. Salir\n", 1, 6, 2)==0){
				switch(option)
				{
					case 1:
						if(flag==0)
						{
							if(controller_loadFromText("Datos.csv",eLibros)!=0)
							{
								//controller_putInDisLibro(eLibros);
								flag=0;
							}
							else
							{
								flag=1;
							}
						}
						else
						{
							printf("El archivo ya fue cargado");
						}
						break;
					case 2:
						if(flag!=0)
						{
							controller_sortLibro(eLibros);
						}
						else
						{
							printf("Primero debe cargar un archivo\n");
						}
						break;
					case 3:
						if(flag!=0)
						{
							controller_ListLibro(eLibros);
						}
						else
						{
							printf("Primero debe cargar un archivo\n");
						}
						break;
					case 4:
						if(flag!=0)
						{
							controller_putInDisLibro(eLibros);
						}
						else
						{
							printf("Primero debe cargar un archivo\n");
						}
						break;
					case 5:
						if(flag!=0)
						{
							controller_saveAsText("mapeado.csv",eLibros);
						}
						break;
				}
	    	}
	    }while(option!=6);
	return 0;
}


