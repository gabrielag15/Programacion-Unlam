#include <stdio.h>
#include <stdlib.h>

int main()
{
    int orden = 0;
    int i, j;
    int identidad = 0;
    printf("Ingrese el orden de la matriz cuadrada:");
    scanf("%d", &orden);
    float matriz[orden][orden];
    for(i=0;i<orden;i++){
        for(j=0;j<orden;j++){
            printf("\nIngrese un numero:");
            scanf("%f", &matriz[i][j]);
            if((i!=j) && (matriz[i][j]!=0)){
                identidad++;
            }
            if((i==j) && (matriz[i][j] != 1)){
                identidad++;
            }
        }
    }
    if(identidad == 0){
        printf("La matriz es identidad");
    }
    else{
        printf("La matriz no es identidad");
    }
}
