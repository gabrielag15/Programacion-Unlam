#include <stdio.h>
#include <stdlib.h>
#include "auxiliares_arbol.h"
#include "arbol.h"

int main()
{
    ///MANEJO DE ARCHIVO.
    T_arbol arbol;
    crear_arbol(&arbol);
    FILE* arch = fopen("arbol_arch_bin.dat", "rb");
    if(arch)
        cargar_arbol_archivo(&arbol, arch);
    fclose(arch);

    ///-------------------------------
    T_dato aux = 50;
    int encontrado = buscar_en_arbol_ite(&arbol, &aux, comp_int);
    printf("ENCONTRADO: %d\n", encontrado);
    printf("ALTURA: %d\n", altura_arbol(&arbol));
    //eliminar_arbol(&arbol);
    eliminar_dato_arbol(&arbol, &aux, comp_int);
    //podar_arbol_dde_nivel(&arbol, 2);
    //recorrer_preorden(&arbol, show_int);
    //printf("La cantidad de nodos del arbol es: %d", mostrar_nodo_y_cantidad(&arbol));
    //mostrar_y_contar_nohojas(&arbol);
    imprimir_arbol(&arbol);
    printf("Es arbol completo: %d", es_arbol_completo(&arbol));
    return 0;
}
