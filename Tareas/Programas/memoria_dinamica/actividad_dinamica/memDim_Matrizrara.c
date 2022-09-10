#include <stdlib.h>
#include <stdio.h>

int main(){
	int **casi= NULL;
	int i=0, j=9, k= 0, num[9], digi= 0;
	
	casi= (int**)malloc(sizeof(int*) * 9);
	
	if(casi == NULL){
    	return -1;
	}
	
	
	for(i=0; i<9; i++){
		do{
			printf("\nIngrese el digito %d de tu cuenta UNAM: ", i+1);
			scanf("%d", &num[i]);
		}while(digi<0 || digi>9);
	}
	
	for(i= 0; i<9; i++){
		
		if(num[i]==0){
			casi[i]= (int*)malloc(sizeof(int));
		}else{
			casi[i]= (int*)malloc(sizeof(int) * (num[i]));
		}
		
		if(casi[i] == NULL){
			return -1;
		}
	}
	
	for(i= 0; i<9; i++){	
		for(k= 0; k<num[i]; k++){
			casi[i][k]= num[i];
		}
	}
			
			
	for(i= 0; i<9; i++){
		
		for(k= 0; k<num[i]; k++){
			
			if((casi[i][k])==0){
				printf("NULL");
			}else{
				printf(" %d ", casi[i][k]);	
			}
		}
		
		printf("\n");
	}
	
	while(j>=9){
		free(casi[i]);
		j--;
	}
	
	free(*casi);
	
}
