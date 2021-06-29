#ifndef libro_H_INCLUDED
#define libro_H_INCLUDED
typedef struct
{
    int id;
    char titulo[128];
	char autor[128];
	int precio;
	int editorialId;
}eLibro;

eLibro* libro_new();
eLibro* libro_newParametros(char* idStr,char* tituloStr,char* autorStr,char* precioStr, char* editorialIdStr);
void libro_delete();

int libro_setId(eLibro* this,int id);
int libro_getId(eLibro* this,int* id);

int libro_setTitulo(eLibro* this,char* titulo);
int libro_getTitulo(eLibro* this,char* titulo);

int libro_setPrecio(eLibro* this,int precio);
int libro_getPrecio(eLibro* this,int* precio);

int libro_setAutor(eLibro* this,char* autor);
int libro_getAutor(eLibro* this,char* autor);

int libro_setEditorialId(eLibro* this,int editorialId);
int libro_getEditorialId(eLibro* this,int* editorialId);

int libro_EditorialToId(int* id, char* editorialIdStr);
int libro_IdToEditorial(int id, char* editorialIdStr);

//int libro_setSala(eLibro* this,int sala);
//int libro_getSala(eLibro* this,int* sala);
//
//int libro_setCantidad(eLibro* this,int cantidad);
//int libro_getCantidad(eLibro* this,int* cantidad);
//
//int libro_setFacturacion(eLibro* this,float facturacion);
//int libro_getFacturacion(eLibro* this,float* facturacion);

void libro_print(eLibro* this);

//int libro_sortId(void* thisOne, void* thisTwo);
//int libro_sortSueldo(void* thisOne, void* thisTwo);
//int libro_sortHoras(void* thisOne, void* thisTwo);
int libro_sortTitulo(void* thisOne, void* thisTwo);
int libro_sortAutor(void* thisOne, void* thisTwo);
void libro_putDis(void* this);
//void libro_putDis(void* this);
int libro_putSala(void* this, int sala);
int libro_putEntradas4(void* this);
#endif // libro_H_INCLUDED
