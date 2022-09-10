#include <stdio.h>
#include <stdlib.h> 

typedef struct Datos{
char nombre[25];
int edad;
int calificacion;
}Alumnos;

int CantidadAlumnos(Alumnos *);

void IngresarDatos(int, Alumnos *);

void ImprimirDatos(int, Alumnos *);

void PromedioEdades(int, Alumnos *);

void PromedioCalif(int, Alumnos *);

int main (){
	int num, j=0,n,op;
	Alumnos *P=NULL;
	P=(Alumnos*)malloc(n*sizeof(Alumnos));

do{	
system("cls");	
printf ("\nElige la opcion deseada del 1 al 3: \n 1.Ingresar Alumnos \n 2.Imprimir alumnos registrados \nOpcion:");
scanf ("%i", &num);

system("cls"); 

		switch (num){
			case 1: printf ("Opcion 1: Ingresar Alumnos \n");
			j=CantidadAlumnos(P);
			IngresarDatos(j, P);
			break;
		
			case 2: printf ("Opcion 2: Imprimir datos \n ");
			ImprimirDatos(j, P);
			PromedioEdades(j, P);
			PromedioCalif(j, P);
			break;
			default: printf ("No se eligio una opcion correcta \n");
			break;
			}
	printf("\n\nDesea volver al menu? \nSi = 1 \tNo = 0:\n ");
		scanf("%d",&op);
		
		if(op==0) {
			printf("\nGracias por venir :)");
		}
		
}while(op!=0);

}

int CantidadAlumnos(Alumnos *P){
	int n;
	printf("\nCuantos alumnos desea ingresar?");
	scanf("%d", &n);
	P=(Alumnos*)malloc(n*sizeof(Alumnos));
	return n;
}
void IngresarDatos(int n, Alumnos *P){
	int i;
	printf("\nAlumnos:");
	for(i=0;i<n;i++){
		setbuf(stdin, NULL);
		printf("\n Nombre completo:");
		gets(P[i].nombre);
		printf("\n Edad:");
		scanf("%d", &P[i].edad);
		printf("\n Calificacion: ");
		scanf("%d", &P[i].calificacion);
	}

}
void ImprimirDatos(int n, Alumnos *P){
	int i;
	printf("\n Los alumnos registrados son:");
	for(i=n-1;i>=0;i--){
	printf("\n Nombre: %s", P[i].nombre);
	printf("\n Edad: %d", P[i].edad);
	printf("\n Calificaion: %d", P[i].calificacion);	
	}

		
}
void PromedioEdades(int n, Alumnos *P){
float promEdad = 0;
int i;
	for(i=0;i<n;i++){
	promEdad+=P[i].edad;}
	promEdad/=n;
	printf("\n El promedio de las edades es: %.2f", promEdad);
}

void PromedioCalif(int n, Alumnos *P){
float promCal=0;
int i;
	for(i=0;i<n;i++){
		promCal+=P[i].calificacion;
	}
	promCal/=n;
	printf("\n El promedio grupal es: %.2f", promCal);
}

