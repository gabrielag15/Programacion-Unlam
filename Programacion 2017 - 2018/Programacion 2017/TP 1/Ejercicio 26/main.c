#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vector[8] = {40, 30, 40, 50, 40, 10, 20, 30};
    int elemento, i;
    printf("Ingrese el elemento a borrar:");
    scanf("%d", &elemento);
    for(i=0;i<8;i++){
        if(elemento == vector[i]){
            vector[i] = 0;
        }
    }
    for(i=0;i<8;i++){
        printf("\n%d", vector[i]);
    }
}
