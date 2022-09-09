#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int *pv =(int*)malloc(10*sizeof(int));
	
	for(int i = 0 ; i<20; i++){
	
		if(i%2==0){
			
			pv[i/2]= i; 

		}
	}
	
	pv[7] = -1;
	
	printf("\n");
	for(int j = 0 ; j<10; j++){
	
		printf("| %d ",pv[j]);

	}
	
	free(pv);
}


