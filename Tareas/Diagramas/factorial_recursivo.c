#include <stdio.h>

int factorial_ite(int n, int a){
	if(n<0){
		printf("\n Ingrese un numero diferente");
		return 0;
	}else if(n==0){
		return 1;
	}else if(n==1){
		return 1;
	}else{
		return n*factorial_ite(n-1, n*a);
	}
}

int main(){
	int n,a, resultado;
	a=1;
	
	printf("Factorial Recursivo, usando la iteratividad");
	printf("\n Introdusca un numero: ");
	scanf("%d", &n);
	
	resultado= factorial_ite(n,a);
	
	printf("El resultado del factorial %d, es: %d ", n, resultado);
	
	return 0;
}