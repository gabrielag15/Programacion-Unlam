#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct{

    int num;
}t_info;

typedef struct s_nodo{

    struct s_nodo *izq;

    t_info info;

    struct s_nodo *der;
}t_nodo;

typedef t_nodo* t_arbol;

void cargarInfo(t_info*d);

int insertarIterativa(t_arbol*p,t_info*d);
int insertarrecursiva(t_arbol*p,t_info*d);
void mostrarPreOrden(t_arbol*p);
void mostrarInOrden(t_arbol*p);
void mostrarPosOrden(t_arbol*p);


#endif // HEADER_H_INCLUDED
