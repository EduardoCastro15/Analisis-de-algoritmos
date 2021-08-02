#include <stdio.h>
#include <string.h>

void ImprimirArreglo(int A[], int aTam){ 
    int i=0;
    printf("El arreglo es: ");
	do{
		printf("%d, ", A[i++]);
	}while(i<aTam);
}
int Pivote(int A[], int aTam){
	int i, diferencia=0;
    for (i=0; i < aTam-1; i++){
    	diferencia=A[i]-A[i+1];
    	if(diferencia > 0){
    		return i+1;
    	} 
    }
}
int main(){
	int aTam, P;
	int A[]={1,5,9,12,26,32,41,38,20,19,1};
	aTam=sizeof(A)/sizeof(A[0]);
	ImprimirArreglo(A, aTam);
	P = Pivote(A, aTam);
	printf("\n\nEl valor del pivote es: %d \n", A[P]);
	printf("La posicion del pivote es: %d \n", P);
}

