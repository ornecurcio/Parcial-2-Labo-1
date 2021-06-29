#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Libro.h"
#include "LinkedList.h"
#include "parser.h"
#include "UTN.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListLibro LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListLibro)
{
	int retorno=-1;
	if(path!=NULL && pArrayListLibro!=NULL)
	{
		retorno=0;
		if(ll_isEmpty(pArrayListLibro)==1)
		{
			FILE *pFile=fopen(path,"r");
			if(parser_LibroFromText(pFile,pArrayListLibro)!=0)
			{
				printf("No se pudo leer el archivo\n");
			}
			else
			{
				printf("Archivo bien leido. Cerrado correctamente\n");
			}
			fclose(pFile);
		}
		else
		{
			printf("\t###########################################################################################################\n");
			printf("\t#\t Atencion! Se detectaron datos en su LinkedList                                                   #\n");
			printf("\t#\t Si procede con la apertura del archivo se borraran los datos actuales cargados en memoria        #\n");
			printf("\t#\t Desea continuar y borrar los archivos guardados en memoria presione SI                           #\n");
			printf("\t#\t Desea continuar usando la LinkedList actual presione NO                                          #\n");
			printf("\t###########################################################################################################\n");
			if(utn_getCaracterSN()==0 && ll_clear(pArrayListLibro)==0)
			{
				FILE *pFile=fopen(path,"r");
				if(parser_LibroFromText(pFile,pArrayListLibro)!=0)
				{
					printf("No se pudo leer el archivo\n");
				}
				else
				{
					printf("Archivo bien leido. Cerrado correctamente\n");
				}
				fclose(pFile);
			}
		}
	}
	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListLibro LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListLibro)
{
	int retorno=-1;
	if(path!=NULL && pArrayListLibro!=NULL)
	{
		retorno=0;
		if(ll_isEmpty(pArrayListLibro)==1)
		{
			FILE *pFile=fopen(path,"rb");
			if(pFile!=NULL)
			{
				if(parser_LibroFromBinary(pFile,pArrayListLibro)!=0)
				{
					printf("No se pudo leer el archivo\n");
				}
				else
				{
					printf("Archivo bien leido. Cerrado correctamente\n");
				}
			}
			fclose(pFile);
		}
		else
		{
			printf("\t###########################################################################################################\n");
			printf("\t#\t Atencion! Se detectaron datos en su LinkedList                                                   #\n");
			printf("\t#\t Si procede con la apertura del archivo se borraran los datos actuales cargados en memoria        #\n");
			printf("\t#\t Desea continuar y borrar los archivos guardados en memoria presione SI                           #\n");
			printf("\t#\t Desea continuar usando la LinkedList actual presione NO                                          #\n");
			printf("\t###########################################################################################################\n");
			if(utn_getCaracterSN()==0 && ll_clear(pArrayListLibro)==0)
			{
				FILE *pFile=fopen(path,"rb");
				if(pFile!=NULL)
				{
					if(parser_LibroFromBinary(pFile,pArrayListLibro)!=0)
					{
						printf("No se pudo leer el archivo\n");
					}
					else
					{
						printf("Archivo bien leido. Cerrado correctamente\n");
					}
				}
				fclose(pFile);
			}
		}
	}
	return retorno;
}

/** \brief Busca Id Maximo
 *
 * \param path char*
 * \param pArrayListLibro LinkedList*
 * \return int
 *
 */
int controller_getMaxId(LinkedList* pArrayListLibro)
{
	int retorno=-1;
	int cantidadLinkedList;
	int id;

	eLibro* pAuxLibro=NULL;
	if(pArrayListLibro!=NULL && ll_isEmpty(pArrayListLibro)==0)
	{
		cantidadLinkedList=ll_len(pArrayListLibro);
		for(int i=0; i<cantidadLinkedList ; i++)
		{
			pAuxLibro = (eLibro*)ll_get(pArrayListLibro, i);
			libro_getId(pAuxLibro, &id);
			if(id>retorno)
			{
				retorno=id;
			}
		}
	}
	return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListLibro LinkedList*
 * \return int
 *
 */
//int controller_addLibro(LinkedList* pArrayListLibro)
//{
//	int retorno=-1;
//	Libro* pAuxLibro=NULL;
//	int auxId;
//	char auxTitulo[128];
//	int auxHoras;
//	int auxSueldo;
//	int respuesta;
//	if(pArrayListLibro!=NULL)
//	{
//		if(ll_isEmpty(pArrayListLibro)==1)
//		{
//			printf("\t########################################################################################\n");
//			printf("\t#\t Atencion! Esta por cargar datos en una nueva LinkedList                       #\n");
//			printf("\t#\t Recuerde que luego debe guardar estos datos en un archivo                     #\n");
//			printf("\t#\t Desea continuar e inicializar un Id o generar un Id propio presione SI        #\n");
//			printf("\t#\t Desea salir y abrir volver al menu para abrir un archivo presione NO          #\n");
//			printf("\t########################################################################################\n");
//			if(utn_getCaracterSN()==0)
//			{
//				utn_getNumero(&respuesta, "Desea\n1. Crear una nueva lista inicializando el ID en 1\n2. Inicializar el ID en otro numero\n",
//						                   "Error, opcion no valida", 1, 2, 1);
//					switch(respuesta)
//					{
//						case 1:
//							auxId=1;
//							break;
//						case 2:
//							utn_getNumero(&auxId, "En que numero quiere inicializar el ID?\n", "Error, ingrese valor numerico\n", 1, 100000000, 2);
//							break;
//					}
//					pAuxLibro=libro_new();
//					if(pAuxLibro!=NULL)
//					{
//						if(utn_getTitulo(auxTitulo, "Ingrese titulo del empleado", "Error ingrese titulo valido\n", 2, 128)==0 &&
//						   utn_getNumero(&auxHoras, "Ingrese horas trabajadas", "Error ingrese numero valido, maximo 745\n", 0, 745, 2)==0 &&
//						   utn_getNumero(&auxSueldo, "Ingrese sueldo", "Error ingrese numero valido, maximo 999999\n", 0, 999999, 2)==0)
//						{
//							if(libro_setId(pAuxLibro, auxId)==0 &&
//							   libro_setTitulo(pAuxLibro, auxTitulo)==0 &&
//							   libro_setHorasTrabajadas(pAuxLibro, auxHoras)==0 &&
//							   libro_setSueldo(pAuxLibro, auxSueldo)==0)
//							{
//								ll_add(pArrayListLibro, pAuxLibro);
//								libro_print(pAuxLibro);
//								printf("Carga exitosa\n");
//								retorno=0;
//							}
//							else
//							{
//								printf("Error al cargar empleado\n");
//							}
//						}
//					}
//				}
//		}
//		else
//		{
//			auxId=controller_getMaxId(pArrayListLibro);
//			pAuxLibro=libro_new();
//			if(pAuxLibro!=NULL)
//			{
//				if(utn_getTitulo(auxTitulo, "Ingrese titulo del empleado", "Error, ingrese titulo valido\n", 2, 128)==0 &&
//				   utn_getNumero(&auxHoras, "Ingrese horas trabajadas", "Error ingrese numero valido, maximo 745\n", 0, 745, 2)==0 &&
//				   utn_getNumero(&auxSueldo, "Ingrese sueldo", "Error numero valido, maximo 999999", 0, 999999, 2)==0)
//				{
//						if(libro_setId(pAuxLibro, (auxId+1))==0 &&
//						   libro_setTitulo(pAuxLibro, auxTitulo)==0 &&
//						   libro_setHorasTrabajadas(pAuxLibro, auxHoras)==0 &&
//						   libro_setSueldo(pAuxLibro, auxSueldo)==0)
//						{
//							ll_add(pArrayListLibro, pAuxLibro);
//							libro_print(pAuxLibro);
//							printf("Carga exitosa\n");
//							retorno=0;
//						}
//						else
//						{
//							printf("Error al cargar empleado\n");
//						}
//				}
//			}
//		}
//	}
//    return retorno;
//}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListLibro LinkedList*
 * \return int
 *
 */
//int controller_editLibro(LinkedList* pArrayListLibro)
//{
//	int retorno=-1;
//	eLibro* pAuxLibro=NULL;
//	int cantidadLinkedList;
//	int auxId, auxHoras, auxSueldo, id, auxInt;
//	int numMax=0;
//	char auxTitulo[128];
//
//	if(pArrayListLibro!=NULL && ll_isEmpty(pArrayListLibro)==0)
//	{
//		cantidadLinkedList=ll_len(pArrayListLibro);
//		for(int i=0; i<cantidadLinkedList ; i++)
//		{
//			pAuxLibro = (Libro*)ll_get(pArrayListLibro, i);
//			libro_getId(pAuxLibro, &auxId);
//			if(auxId>numMax)
//			{
//				numMax=auxId;
//			}
//		}
//		utn_getNumero(&id, "Ingrese Id de persona a modificar\n", "Error, ingrese valor numerico\n", 0, auxId, 2);
//		for(int i=0; i<cantidadLinkedList ; i++)
//		{
//			pAuxLibro = (Libro*)ll_get(pArrayListLibro, i);
//			libro_getId(pAuxLibro, &auxId);
//			if(auxId==id)
//			{
//				printf("Desea modificar este empleado?\n");
//				libro_print(pAuxLibro);
//				if(utn_getCaracterSN()==0)
//				{
//					utn_getNumero(&auxInt, "------Modificar-------\n1. Titulo \n2. Horas trabajadas \n3. Sueldo", "Error, opcion incorrecta\n", 1, 3, 2);
//					switch(auxInt)
//					{
//						case 1:
//							if((utn_getTitulo(auxTitulo, "Ingrese titulo del empleado", "Error, ingrese Titulo valido\n", 2, 128)==0) &&
//							  (libro_setTitulo(pAuxLibro, auxTitulo)==0))
//							{
//								printf("Datos modificados correctamente\n");
//								libro_print(pAuxLibro);
//							}
//							break;
//						case 2:
//							if((utn_getNumero(&auxHoras, "Ingrese horas trabajadas", "Error ingrese numero valido, maximo 745\n", 0, 100000, 2)==0) &&
//							   (libro_setHorasTrabajadas(pAuxLibro, auxHoras)==0))
//							{
//								printf("Datos modificados correctamente\n");
//								libro_print(pAuxLibro);
//							}
//							break;
//						case 3:
//							if((utn_getNumero(&auxSueldo, "Ingrese sueldo", "Error, maximo 999999\n", 0, 999999, 2)==0) &&
//							   (libro_setSueldo(pAuxLibro, auxSueldo)==0))
//							{
//								printf("Datos modificados correctamente\n");
//								libro_print(pAuxLibro);
//							}
//							break;
//					}//FIN SWITCH
//					retorno=0;
//				}
//			}
//		 }//FIN FOR
//		}
//	return retorno;
//}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListLibro LinkedList*
 * \return int
 *
 */
//int controller_removeLibro(LinkedList* pArrayListLibro)
//{
//	int retorno=-1;
//	eLibro* pAuxLibro=NULL;
//	int cantidadLinkedList;
//	int auxId, id, i;
//	int numMax;
//
//	if(pArrayListLibro!=NULL && ll_isEmpty(pArrayListLibro)==0)
//	{
//		numMax=controller_getMaxId(pArrayListLibro);
//		cantidadLinkedList=ll_len(pArrayListLibro);
//		utn_getNumero(&id, "Ingrese Id de persona a borrar", "Error, ingrese valor numerico\n", 0, numMax, 2);
//		for(i=0; i<cantidadLinkedList ; i++)
//		{
//			pAuxLibro = (eLibro*)ll_get(pArrayListLibro, i);
//			libro_getId(pAuxLibro, &auxId);
//			if(auxId==id)
//			{
//				printf("Desea borrar este empleado?\n");
//				libro_print(pAuxLibro);
//				if(utn_getCaracterSN()==0)
//				{
//					if(ll_remove(pArrayListLibro, i)==0)
//					{
//						printf("Operacion exitosa\n");
//						retorno=0;
//						break;
//					}
//				}
//			}
//		}
//		printf("Empleado no encontrado\n");
//	}
//    return retorno;
//}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListLibro LinkedList*
 * \return int
 *
 */
int controller_ListLibro(LinkedList* pArrayListLibro)
{
	int retorno = -1;
	int auxId, auxPrecio, auxEditorialId ;
	char auxTitulo[128], auxAutor[128], auxEditorialStr[128];
	eLibro* pAuxLibro=NULL;
	int cantidadLinkedList;
	if(pArrayListLibro != NULL)
	{
		if(ll_isEmpty(pArrayListLibro)==0)
		{
			cantidadLinkedList=ll_len(pArrayListLibro);
			printf("-----------------------------------------------------------------------------------------------------------------------------------------------------\n");
			printf("ID				TITULO		        		AUTOR	        PRECIO	  EDITORIAL\n");
			printf("------------------------------------------------------------------------------------------------------------------------------------------------------\n");
			for(int i=0; i<cantidadLinkedList ; i++)
			{
				pAuxLibro = (eLibro*)ll_get(pArrayListLibro, i);
				if(libro_getId(pAuxLibro, &auxId)!=0 || libro_getTitulo(pAuxLibro, auxTitulo)!=0 ||
				   libro_getAutor(pAuxLibro, auxAutor)!=0 || libro_getPrecio(pAuxLibro, &auxPrecio)!=0 ||
				   libro_getEditorialId(pAuxLibro, &auxEditorialId)!=0 ||
				   libro_IdToEditorial(auxEditorialId, auxEditorialStr)!=0)
				{
					retorno=-1;
					printf("Error, al imprimir lista\n");
					break;
				}
				else
				{
					//utn_putDay(auxPrecio, auxPrecioStr);
					printf("%-4d %-50s	%-15s 	%5d  	  %-20s\n",auxId, auxTitulo, auxAutor, auxPrecio, auxEditorialStr);
					retorno=0;
				}
			}
		}
		else
		{
			printf("No hay lista para imprimir\n");
		}
	}
	return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListLibro LinkedList*
 * \return int
 *
 */
int controller_sortLibro(LinkedList* pArrayListLibro)
{
	int retorno=-1;
	int option;
	int(*pOrden)(void*,void*);

	if(pArrayListLibro!=NULL)
	{
		utn_getNumero(&option, "-----ORDENAMIENTO POR-----\n1. Autor \n2. Titulo", "Error, opcion incorrecta\n", 1, 2, 2);
		switch(option)
		{
			case 1:
				pOrden=libro_sortAutor;
				break;
			case 2:
				pOrden=libro_sortTitulo;
				break;
		}
		ll_sort(pArrayListLibro, pOrden, 1);
	}
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListLibro LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListLibro)
{
	int retorno = -1;
	int auxCantLink, auxId, auxPrecio, auxEditorialId;
	char auxTitulo[128], auxAutor[128], auxEditorial[128];
	FILE* pFile;
	eLibro* pAuxLibro=NULL;
	if(path!=NULL && pArrayListLibro!=NULL)
	{
		if((pFile=fopen(path,"w"))==NULL)
		{
			printf("No se pudo escribir el archivo\n");
		}
		else
		{
			auxCantLink=ll_len(pArrayListLibro);
			fprintf(pFile,"id,titulo,autor,precio,editorialId\n");
			for(int i=0; i<auxCantLink; i++)
			{
				pAuxLibro = (eLibro*)ll_get(pArrayListLibro, i);
				if(libro_getId(pAuxLibro, &auxId)==0 &&
				   libro_getTitulo(pAuxLibro, auxTitulo)==0 &&
				   libro_getAutor(pAuxLibro, auxAutor)==0 &&
				   libro_getPrecio(pAuxLibro, &auxPrecio)==0 &&
				   libro_getEditorialId(pAuxLibro, &auxEditorialId)==0 &&
				   libro_IdToEditorial(auxEditorialId, auxEditorial)==0)
				{
				   fprintf(pFile,"%d,%s,%s,%d,%s\n",auxId, auxTitulo, auxAutor, auxPrecio, auxEditorial);
				   retorno=0;
				}
			}
			printf("Archivo bien escrito. Guardado correctamente\n");
		}
		fclose(pFile);
	}
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListLibro LinkedList*
 * \return int
 *
 */
//int controller_saveAsBinary(char* path , LinkedList* pArrayListLibro)
//{
//	int retorno = -1;
//	int auxCantLink, retornoLeido;
//	FILE* pFile=NULL;
//	eLibro* pAuxLibro=NULL;
//	if(path!=NULL && pArrayListLibro!=NULL)
//	{
//		if((pFile=fopen(path,"wb"))==NULL)
//		{
//			printf("No se pudo escribir el archivo\n");
//		}
//		else
//		{
//			auxCantLink=ll_len(pArrayListLibro);
//			for(int i=0; i<auxCantLink; i++)
//			{
//				pAuxLibro = (Libro*)ll_get(pArrayListLibro, i);
//				retornoLeido=fwrite(pAuxLibro, sizeof(Libro),1,pFile);
//				if(retornoLeido!=1)
//				{
//					libro_delete(pAuxLibro);
//					break;
//					retorno=-1;
//				}
//				else
//				{
//					retorno=0;
//				}
//			}
//			if(retorno==0)
//			{
//				printf("Archivo bien escrito. Guardado correctamente\n");
//			}
//		}
//		fclose(pFile);
//	}
//    return retorno;
//}
/** \brief Borra la LinkedList
 *
 * \param pArrayListLibro LinkedList*
 * \return int
 *
 */
//int controller_deleteLinkedList(LinkedList* pArrayListLibro)
//{
//	int retorno=-1;
//	if(pArrayListLibro!=NULL)
//	{
//		if(ll_deleteLinkedList(pArrayListLibro)==0)
//		{
//			printf("-----------------------------------------------");
//			printf("/ PROGRAMA FINALIZADO, HASTA PRONTO /");
//			printf("-----------------------------------------------");
//			retorno=0;
//		}
//	}
//	return retorno;
//}
int controller_putInDisLibro(LinkedList* pArrayListLibro)
{
	int retorno=-1;
	void (*pFunc)(void* element);
	if(pArrayListLibro!=NULL)
	{
		pFunc=libro_putDis;
		ll_map(pArrayListLibro, pFunc);
	}
    return retorno;
}
//int controller_informes(LinkedList* pArrayListLibro)
//{
//	int retorno=-1;
//	eLibro* pAuxLibro=NULL;
//	eLibro* pAuxLibro2=NULL;
//	eLibro* pAuxLibro3=NULL;
//	int cantidadLinkedList;
//	int auxCant, intSala, auxSala;
//	float auxFac;
//	int acumuladorEntradas=0;
//	float montoSala=0;
//	int(*pOrden)(void*,void*);
//
//	if(pArrayListLibro!=NULL && ll_isEmpty(pArrayListLibro)==0)
//	{
//		utn_getNumero(&intSala, "Ingrese numero de sala de 1 a 5", "Error, ingrese numero valido", 1, 5, 2);
//		cantidadLinkedList=ll_len(pArrayListLibro);
//		pOrden=libro_sortTitulo;
//		ll_sort(pArrayListLibro, pOrden, 1);
//		for(int i=0; i<cantidadLinkedList ; i++)
//		{
//				pAuxLibro = (eLibro*)ll_get(pArrayListLibro, i);
////				pAuxLibro2 = (eLibro*)ll_get(pArrayListLibro, j);
//				libro_getSala(pAuxLibro, &auxSala);
//				if(auxSala==intSala)
//				{
//					libro_getCantidad(pAuxLibro, &auxCant);
//					libro_getFacturacion(pAuxLibro, &auxFac);
//					acumuladorEntradas=acumuladorEntradas+auxCant;
//					montoSala=montoSala+auxFac;
//					libro_print(pAuxLibro);
//					continue;
////					if(stricmp(pAuxLibro->titulo,pAuxLibro2->titulo)==0)
////					{
////						ll_remove(pArrayListLibro, i);
////					}
////				}
//				}
//				else
//				{
//					ll_remove(pArrayListLibro, i);
//				}
//		}
//		printf("###########################################################################################################\n");
//		printf("#\t\t\t\t\t SALA %d                                                \n", intSala);
//		printf("###########################################################################################################\n");
//		printf("#\t Entradas Vendidas: %d        \n", acumuladorEntradas);
//		printf("#\t Monto total facturado: %.2f                           \n", montoSala);
//		printf("#\t Listado de peliculas proyectadas:                                           \n");
//		for(int i=0; i<ll_len(pArrayListLibro); i++)
//		{
//			printf("%d nueva cantidad de Len\n", ll_len(pArrayListLibro));
//			pAuxLibro = (eLibro*)ll_get(pArrayListLibro, i);
//			printf("Titulo1: %s\n", pAuxLibro->titulo);
//			pAuxLibro2 = (eLibro*)ll_get(pArrayListLibro, i+1);
//			printf("Titulo2: %s\n", pAuxLibro2->titulo);
//			pAuxLibro3 = (eLibro*)ll_get(pArrayListLibro, i+2);
//			printf("Titulo3: %s\n", pAuxLibro3->titulo);
//			if(stricmp(pAuxLibro->titulo,pAuxLibro2->titulo)==0)
//			{
//				//ll_remove(pArrayListLibro, i+1);
//				printf("Borra: ");
//				libro_print(ll_pop(pArrayListLibro, i+1));
//				//for(int j=i+1; j<cantidadLinkedList; j++)
//				//{
//					//ll_set(pArrayListLibro, j, pAuxLibro2);
//					//ll_add(pArrayListLibro, ll_pop(pArrayListLibro, i+1));
//				//}
////				if(ll_remove(pArrayListLibro, i+1)==0)
////				{
////					printf("anda el remove\n");
////					libro_print(pAuxLibro);
////				}
////				else
////				{
////					printf("rompe el remove\n");
////				}
//			}
//			if(stricmp(pAuxLibro2->titulo,pAuxLibro3->titulo)==0)
//			{
//				//ll_remove(pArrayListLibro, i+1);
//				printf("Borra: ");
//				libro_print(ll_pop(pArrayListLibro, i+2));
//			}
////			else
////			{
////				continue;
////			}
//		}
//		cantidadLinkedList=ll_len(pArrayListLibro);
//		printf("%d nueva cantidad de Len\n", cantidadLinkedList);
//		for(int i=0; i<cantidadLinkedList; i++)
//		{
//			pAuxLibro = (eLibro*)ll_get(pArrayListLibro, i);
//			libro_print(pAuxLibro);
//		}
//		printf("###########################################################################################################\n");
//	}
//	return retorno;
//}
//int controller_contadorEntrada(LinkedList* pArrayListLibro)
//{
//	int retorno=-1;
//	void (*pFunc)(void* element);
//	int contador;
//	if(pArrayListLibro!=NULL)
//	{
//		pFunc=libro_putEntradas4;
//		contador=ll_count(pArrayListLibro, pFunc);
//		printf("#\t Entradas Vendidas: %d        \n", contador);
//		retorno=0;
//	}
//    return retorno;
//}
//int controller_Sala(LinkedList* pArrayListLibro)
//{
//	int retorno=-1;
//	eLibro* pAuxLibro=NULL;
//	int auxCant, intSala, auxSala;
//	float auxFac;
//	int acumuladorEntradas=0;
//	float montoSala=0;
//	void (*pFunc)(void* element);
//	if(pArrayListLibro!=NULL && ll_isEmpty(pArrayListLibro)==0)
//	{
//		pFunc=libro_putEntradas4;
//		retorno=0;
//		utn_getNumero(&intSala, "Ingrese numero de sala de 1 a 5", "Error, ingrese numero valido", 1, 5, 2);
//		for(int i=0; i<ll_len(pArrayListLibro); i++)
//		{
//			pAuxLibro = (eLibro*)ll_get(pArrayListLibro, i);
//			libro_getSala(pAuxLibro, &auxSala);
//			if(auxSala!=intSala)
//			{
//				if(ll_remove(pArrayListLibro, i)==0)
//				{
//					printf("Borra Sala %d", pAuxLibro->sala);
//					continue;
//				}
//			}
//			else
//			{
//				libro_getCantidad(pAuxLibro, &auxCant);
//				libro_getFacturacion(pAuxLibro, &auxFac);
//				//acumuladorEntradas=acumuladorEntradas+auxCant;
//				acumuladorEntradas=ll_count(pArrayListLibro, pFunc);
//				montoSala=montoSala+auxFac;
//				//libro_print(pAuxLibro);
//			}
//		}
//		printf("###########################################################################################################\n");
//		printf("#\t\t\t\t\t SALA %d                                                \n", intSala);
//		printf("###########################################################################################################\n");
//		printf("#\t Entradas Vendidas: %d        \n", acumuladorEntradas);
//		printf("#\t Monto total facturado: %.2f                           \n", montoSala);
//		printf("#\t Listado de peliculas proyectadas: \n");
//		//controller_ListLibro(pArrayListLibro);
//	}
//	return retorno;
//}
//int controller_PrintSala(LinkedList* pArrayListLibro)
//{
//	int retorno=-1;
//	eLibro* pAuxLibro=NULL;
//	eLibro* pAuxLibro2=NULL;
//	eLibro* pAuxLibro3=NULL;
//	int(*pOrden)(void*,void*);
//	if(pArrayListLibro!=NULL && ll_isEmpty(pArrayListLibro)==0)
//	{
//		pOrden=libro_sortTitulo;
//		ll_sort(pArrayListLibro, pOrden, 1);
//		for(int i=0; i<ll_len(pArrayListLibro); i++)
//		{
//			pAuxLibro = (eLibro*)ll_get(pArrayListLibro, i);
//			pAuxLibro2 = (eLibro*)ll_get(pArrayListLibro, i+1);
//			pAuxLibro3 = (eLibro*)ll_get(pArrayListLibro, i+2);
//			if(stricmp(pAuxLibro->titulo,pAuxLibro2->titulo)==0)
//			{
//				ll_remove(pArrayListLibro, i+1);
//			}
//			else
//			{
//				if(stricmp(pAuxLibro2->titulo,pAuxLibro3->titulo)==0)
//				{
//					ll_remove(pArrayListLibro, i+2);
//				}
//				else
//				{
//					continue;
//				}
//			}
//		}
//	}
//	return retorno;
//}
//
