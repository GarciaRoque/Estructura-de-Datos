#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int *pv =(int*)malloc(10*sizeof(int));
	 int i, j;
	for( i = 0 ; i<20; i++){
	
		if(i%2==0){
			
			pv[i/2]= i; 
			printf("| %d ",pv[i/2]);
		} 
		
		
	}
	
	pv[7] = -1;
	
	printf("\n");
	for( j = 10-1 ; j>=0; j--){
	
		printf("| %d ",pv[j]);

	}
	
	free(pv);
}
