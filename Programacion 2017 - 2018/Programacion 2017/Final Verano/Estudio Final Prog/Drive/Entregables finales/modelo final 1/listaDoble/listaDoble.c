#include "listaDoble.h"
#define LISTA_LLENA 1
#define TODO_OK 0

void mostrarLista(const t_info *i)
{
    printf("%s\t\t%s\t%.3lf\t\t\t%s\n",i->codigo,i->descripcion,i->cantidad,i->uniMedida);
}

void mostrarBaja(int cantElem,double cantProd,char codigo[])
{
    printf("\n\nSe eliminaron %d nodos con la clave: %s - Cantidad de productos: %lf",cantElem,codigo,cantProd);
}

void crearLista(t_lista*l)
{
    *l=NULL;
}

int insertarEnListaDesordenada(t_lista*l,const t_info*i)
{
    t_nodo*nue=(t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
        return LISTA_LLENA;

    nue->info=*i;
    nue->ant=*l;
    if(*l)
        (*l)->sig=nue;
    nue->sig=NULL;
    *l=nue;
    return TODO_OK;
}

void recorrerLista(const t_lista*l)
{
    if(!*l)
    {
        puts("sin lista viejo");
        return;
    }
    while((*l)->ant)
        l=&(*l)->ant;

    puts("ESTADO DE LA LISTA:\n\n");
    puts("CODIGO\t\tDESCRIPCION\t\tCANTIDAD\t\tMEDIDA\n\n");

    while(*l)
    {
        mostrarLista(&(*l)->info);
        l=&(*l)->sig;
    }
}

void eliminarDuplicados(t_lista*p)
{
    long unsigned int sumatoria;
    int nodos,nodos_totales=0;
    t_nodo* actual,
          * recorrido,
          * sig,
          * ant;

    if(!*p)
        return;
    while((*p)->ant)
        *p=(*p)->ant;

    actual=*p;
    while(actual)
    {

        nodos=sumatoria=0;
        recorrido=actual->sig;
        while(recorrido)
        {

            if(strcmpi(actual->info.codigo,recorrido->info.codigo)==0)
            {

                nodos++;
                sumatoria+=recorrido->info.cantidad;
                ant=recorrido->ant;
                sig=recorrido->sig;
                if(sig)
                    sig->ant=ant;

                if(ant)
                    ant->sig=sig;
                free(recorrido);
                recorrido=sig;
            }
            else
            {
                *p=recorrido;
                recorrido=recorrido->sig;
            }
        }
        if(nodos>0)
        {
            nodos++;
            sumatoria+=actual->info.cantidad;
            ant=actual->ant;
            sig=actual->sig;
            printf("Clave eliminada: %s \tCantidad de nodos eliminados: %d \tTotal de unidades=%ld\n",actual->info.codigo,nodos,sumatoria);
            free(actual);
            actual=sig;
            if(sig)
                sig->ant=ant;

            if(ant)
                ant->sig=sig;
            if(!sig && !ant)
                *p=NULL;
        }
        else
            actual=actual->sig;


        nodos_totales+=nodos;
    }
    printf("NODOS TOTALES:%d\n",nodos_totales);
}
