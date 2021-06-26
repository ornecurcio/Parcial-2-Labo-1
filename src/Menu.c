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
	    char* path=NULL;
	    int flag2=0;
	    path=(char*)calloc(20,sizeof(char));
	    LinkedList* eLibros = ll_newLinkedList();
	    LinkedList* eLibros2=NULL;
	    printf("------------ /BIENVENIDO/ -------------\n");
	    do{
	    	if(utn_getNumero(&option,"-------- Seleccione una opcion --------\n"
	    			"1. Cargar Archivo\n"
	    			"2. Imprimir Ventas\n"
	    			"3. Generar Archivo de montos\n4. Informes\n5. Salir\n",
	    					"------- Error ingrese ------ \n"
					"1. Cargar Archivo\n"
				    "2. Imprimir Ventas\n"
				    "3. Generar Archivo de montos\n4. Informes\n5. Salir\n", 1, 11, 2)==0){
				switch(option)
				{
					case 1:
						if(flag==0)
						{
							utn_getNumero(&flag, "Desea abrir: \n1. Data.csv \n2. Otro", "Error, opcion incorrecta", 1, 2, 1);
							switch(flag)
							{
							case 1:
								controller_loadFromText("Datos.csv",eLibros);
								//controller_putInDisLibro(eLibros);
								break;
							case 2:
								if(utn_getArchivo(path)==0)
								{
									controller_loadFromText(path,eLibros);
									//controller_putInDisLibro(eLibros);
								}
								break;
							}
						}
						else
						{
							printf("El archivo ya fue cargado");
						}
						break;
//					case 2:
//						if(flag==0)
//						{
//							utn_getNumero(&flag, "Desea abrir: \n1. data.bin \n2.Chequeo.bin", "Error, opcion incorrecta", 1, 2, 1);
//							switch(flag)
//							{
//							case 1:
//								controller_loadFromBinary("data.bin",eLibros);
//								break;
//							case 2:
//								controller_loadFromBinary("Chequeo.bin",eLibros);
//								break;
//							}
//						}
//						else
//						{
//							printf("El archivo ya fue cargado\n");
//						}
//
//						break;
//					case 3:
//						controller_addLibro(eLibros);
//						break;
//					case 4:
//						controller_editLibro(eLibros);
//						break;
//					case 5:
//						controller_removeLibro(eLibros);
//						break;
					case 2:
						if(flag!=0)
						{
							controller_sortLibro(eLibros);
							controller_ListLibro(eLibros);
						}
						else
						{
							printf("Primero debe cargar un archivo\n");
						}
						break;
//					case 7:
//						controller_sortLibro(eLibros);
//						printf("Desea imprimir lista ordenada. ");
//						if(utn_getCaracterSN()==0)
//						{
//							controller_ListLibro(eLibros);
//						}
//						break;
					case 3:
						if(flag!=0)
						{
							utn_getNumero(&flag2, "Desea guardar en: \n1. Data.csv \n2. Nuevo archivo", "Error, opcion incorrecta", 1, 2, 1);
							switch(flag2)
							{
							case 1:
								controller_saveAsText("Data.csv",eLibros);
								break;
							case 2:
								if(utn_getArchivo(path)==0)
								{
									controller_saveAsText(path,eLibros);
								}
								else
								{
									flag2=0;
								}
								break;
							}
						}
						break;
					case 4:
						//controller_putInDisLibro(eLibros);
						//controller_contadorEntrada(eLibros);
//						eLibros2=ll_clone(eLibros);
//						controller_ListLibro(eLibros2);
//						controller_Sala(eLibros2);
//						//controller_PrintSala(eLibros2);
//						//controller_ListLibro(eLibros2);
						break;
//					case 9:
//						utn_getNumero(&flag2, "Desea guardar en: \n1. data.bin \n2. Chequeo.bin \n3. Nuevo archivo", "Error, opcion incorrecta", 1, 3, 1);
//						switch(flag2)
//						{
//						case 1:
//							controller_saveAsBinary("data.bin",eLibros);
//							break;
//						case 2:
//							controller_saveAsBinary("Chequeo.bin",eLibros);
//							break;
//						case 3:
//							if((utn_getArchivo(path, "Ingrese nombre de archivo","Error, no es valido caracter especial, no olvide el .bin", 2, 30))==0)
//							{
//								controller_saveAsBinary(path,eLibros);
//							}
//							else
//							{
//								flag2=0;
//							}
//							break;
//						}
//						break;
//					case 10:
//						controller_putInDisLibro(eLibros);
//						printf("Desea imprimir nueva lista?. ");
//						if(utn_getCaracterSN()==0)
//						{
//							controller_ListLibro(eLibros);
//						}
//						break;
//					case 11:
//						if(ll_isEmpty(eLibros)==0 && flag2==0)
//						{
//							printf("Se encuentra una lista con datos en ejecucion, desea salir sin guardar? ");
//							if(utn_getCaracterSN()==0)
//							{
//								controller_deleteLinkedList(eLibros);
//							}
//						}
//						else
//						{
//							controller_deleteLinkedList(eLibros);
//						}
//						break;
				}
	    	}
	    }while(option!=5);
	return 0;
}


