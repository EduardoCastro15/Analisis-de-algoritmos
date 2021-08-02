#include<stdio.h>
#include <stdlib.h>

void merge(int *A, int s, int e){
    int mid = (s+e)/2;
    
    int i = s;
    int j = mid+1;
    int k = s;
    int temp[100];
    
    while(i<=mid && j<=e){
        if(A[i] < A[j])
            temp[k++] = A[i++];
        else
            temp[k++] = A[j++];
    }
    while(i<=mid)
        temp[k++] = A[i++];
    while(j<=e)
        temp[k++]  = A[j++];    
    for(i=s; i<=e; i++)
        A[i] = temp[i];
}

void mergeSort(int A[], int s, int e){
    if(s>=e){
        return;
    }
    int mid=(s+e)/2;
    
    mergeSort(A, s, mid);
    mergeSort(A, mid+1, e);
    
    merge(A, s, e);
}

void unir(int *C, int *A, int *B, int n, int m){
	int j=0, i;
	for(i=0; i<n; i++ ){
		C[i]=A[i];
	}
	for(i=n; i<(n+m);i++){
		C[i]=B[j];
		j++;
	}
}
    
   


int main(){
//Para arreglar obtenemos los dos primeros arreglos y despues los unimos
	int n, m, i, *A, *B, *C;
	printf("Ingresa el tamaño del arreglo A: ");
    scanf("%d", &n);
	A=(int *)calloc(n, sizeof(int));
	for (i=0; i<n; i++){
        printf("[%d] = ", i);
        scanf("%d", &A[i]);
    }
	mergeSort(A, 0, n-1);
	
	printf("Ingresa el tamaño del arreglo B: ");
    scanf("%d", &m);
    B=(int *)calloc(m, sizeof(int));
    for (i=0; i<m; i++){
        printf("[%d] = ", i);
        scanf("%d", &B[i]);
    }
	mergeSort(B, 0, m-1);
	
	printf("\nArreglo A: ");
    for(i=0; i<n; i++) printf(" %d,", A[i]);
    printf("\nArreglo B: ");
    for(i=0; i<m; i++) printf(" %d,", B[i]);
	
	C=(int *)calloc(m+n, sizeof(int));
	unir(C, A, B, n, m);
	mergeSort(C, 0, n+m-1);
	
	printf("\nArreglo ordenado y mezclado C: ");
    for(i=0; i<m+n; i++) printf(" %d,", C[i]);
	
	free(A);
    free(B);
    free(C);
}
