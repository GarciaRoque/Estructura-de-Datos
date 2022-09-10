#include<stdio.h>
#include<stdlib.h>

typedef struct nodob{
    char nombre[25];
    int edad;
    int calificacion;
}nodob;

int main()
{
    nodob base[20];
    int j= 19, i=0;
    
    for(i=0; i<20; i++){
        fflush(stdin);
        printf("\n Nombre %d: ", i+1);
        gets(base[i].nombre);
        printf("\n Edad : ");
        scanf("%d", &base[i].edad);
        printf("\n Calificacion : ");
        scanf("%d", &base[i].calificacion);
        printf("\n");
        fflush(stdin);
    }
    
    
    printf("Lista del grupo: \n\n");
    printf("| Nombre | Edad | Calificacion | \n");
    
    while(0<=j){
        printf("| %s |  %d  |  %d  | \n",base[j].nombre,base[j].edad,base[j].calificacion);
        j--;
    }
    /*
    for(int i=0; i<20; i++){
        printf("| %s |  %d  |  %d  | \n",base[i].nombre,base[i].edad,base[i].calificacion);
    }
    */
    
}
