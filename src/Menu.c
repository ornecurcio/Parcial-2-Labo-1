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
	    			"2. Ordenar lista de Libros\n"
	    			"3. Imprimir listado de Libros\n4. Informes\n5. Guardar listado en archivo\n6. Salir",
	    					"------- Error ingrese ------ \n"
					"1. Cargar Archivo\n"
				    "2. Ordenar lista de Libros\n"
				    "3. Imprimir listado de Libros\n4. Informes\n5. Guardar listado en archivo\n6. Salir\n", 1, 6, 2)==0){
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
							controller_ListLibro(eLibros);
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


