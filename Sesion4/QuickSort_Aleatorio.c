#include<stdio.h> 

void Intercambiar(int* a, int* b) { 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int Part(int A[], int Menor, int Mayor, int Rand){ 
    int Piv = A[Mayor];
    int i = (Menor-1), j;
    printf("A[%d]Contenido del pivote como tantas llamadas a la funcion hubo: ", Rand);
	printf("%d\n", Piv);
    for(j=Menor; j<=(Mayor-1); j++){
        if(A[j]<=Piv){ 
            i++;
            Intercambiar(&A[i], &A[j]); 
        } 
    } 
    Intercambiar(&A[i+1], &A[Mayor]); 
    return (i+1); 
} 

int PartR(int A[], int Menor, int Mayor){ 
    srand(time(NULL)); 
    int Rand = Menor + rand() % (Mayor-Menor); 
    Intercambiar(&A[Rand], &A[Mayor]); 
    return Part(A, Menor, Mayor, Rand); 
} 

void QuickSort(int A[], int Menor, int Mayor){ 
    if(Menor < Mayor){ 
        int Piv = PartR(A, Menor, Mayor);
        QuickSort(A, Menor, Piv-1); 
        QuickSort(A, Piv+1, Mayor); 
    } 
} 

void ImprimirA(int A[], int n){ 
    int i; 
    for (i=0; i<n; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 

int main(){ 
    int A[] = {200, 38, 4, 99, 22, 12, 31, 56, 87, 100}; 
    int n = sizeof(A)/sizeof(A[0]); 
    printf("***El pivote es un elemento al azar***\n");
    QuickSort(A, 0, n-1); 
    printf("\nArreglo ordenado: "); 
    ImprimirA(A, n); 
    return 0; 
}
