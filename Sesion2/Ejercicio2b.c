#include <stdio.h>
#include <string.h>

void ImprimirArreglo(int A[], int aTam){ 
    int i=0;
    printf("El arreglo es: ");
	do{
		printf("%d, ", A[i++]);
	}while(i<aTam);
}

int Pivote(int A[],int ini, int fin){
	int mid = (ini+fin)/2;  
	if (A[mid-1]<A[mid] && A[mid]>A[mid+1]) 
		return mid + 1;  
	else if(A[mid-1]<A[mid] && A[mid]<A[mid+1])
		return Pivote(A,mid+1,fin); 
	else
		return Pivote(A,ini,mid);    
	return -1;
}

int main(){
	int aTam, P;
	int A[]={1,5,9,12,26,32,41,38,20,19,1};
	aTam=sizeof(A)/sizeof(A[0]);
	ImprimirArreglo(A, aTam);
	P = Pivote(A, 0, aTam); 
	printf("\n\nEl valor del pivote es: %d \n", A[P]);
	printf("La posicion del pivote es: %d \n", P);
}

