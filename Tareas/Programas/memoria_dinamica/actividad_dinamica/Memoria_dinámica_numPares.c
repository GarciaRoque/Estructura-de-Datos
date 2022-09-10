#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptint;
    int fila, i=0, ulti;
    fila=10;
    
    ptint = (int *)malloc(sizeof(int)*fila);
    
    if(ptint == NULL){
    	return -1;
	}
    
    for(i=0; i<10; i++){
        (ptint[i])=(2*(i+1));
    }
    
    int j=9;
    
    while(0<=j){
        printf("p[%d]: %d ", j, ptint[j]);
        j--;
    }
    
    j=9;
    printf("\n\n");
    
    do{
    	printf("Ingresa el ultimo numero de tu cuenta: ");
    	scanf("%d", &ulti);
    	printf("\n");
	}while((ulti<0) || (ulti>9));
    
    while(0<=j){
        if(j==ulti){
            ptint[j]= -1;
            printf("p[%d]: %d ", j, ptint[j]);
            j--;
        }else{
            printf("p[%d]: %d ", j, ptint[j]);
            j--;
        }
        
    }
    
    free(ptint);
}
