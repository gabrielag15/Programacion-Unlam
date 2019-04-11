#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    T_pila pila; // Pila.
    T_dato mensaje = "Hola"; // T_dato #1
    T_dato mensaje2 = "Saludos"; // T_dato #2
    T_dato mensaje3 = "Cordiales"; //T_dato #3
    T_dato aux[20]; //T_dato utilizado para ver_tope_de_pila y demas.
    crear_pila(&pila);
    poner_en_pila(&pila, &mensaje);
    ver_tope_de_pila(&pila, aux);
    printf("Tope de pila: %s", *aux); //Porque tengo que desreferenciar aux ?
    //-----------------------------------------------
    poner_en_pila(&pila, &mensaje2);
    poner_en_pila(&pila, &mensaje3);
    ver_tope_de_pila(&pila, aux);
    printf("\nTope de pila: %s", *aux); //Porque tengo que desreferenciar aux ?
    //------------------------------------------------
    sacar_de_pila(&pila, aux);
    sacar_de_pila(&pila, aux);
    printf("\nTope de pila: %s", *aux); //Porque tengo que desreferenciar aux ?
    printf("\n0)Pila con espacio: %d", pila_llena(&pila));

}
