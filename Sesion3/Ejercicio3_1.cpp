#include <bits/stdc++.h> 
using namespace std; 

int NumInv(int A[], int Aux[], int Izq, int Der);
int Merge(int A[], int Aux[], int Izq, int Mid, int Der);

int MergeSort(int A[], int n){ 
    int Aux[n]; 
    return NumInv(A, Aux, 0, n-1); 
} 

int NumInv(int A[], int Aux[], int Izq, int Der){ 
    int Mid, Cont=0; 
    if(Der > Izq){ 
        Mid = (Der + Izq) / 2;
        Cont += NumInv(A, Aux, Izq, Mid); 
        Cont += NumInv(A, Aux, Mid+1, Der); 
        Cont += Merge(A, Aux, Izq, Mid+1, Der); 
    } 
    return Cont; 
} 

int Merge(int A[], int Aux[], int Izq, int Mid, int Der){ 
    int i=Izq, j=Mid, k=Izq, Cont=0;
    while((i <= Mid-1) && (j <= Der)){ 
        if(A[i] <= A[j])
            Aux[k++] = A[i++];
        else{
            Aux[k++] = A[j++];
            Cont = Cont + (Mid-i);
        } 
    }
    while (i <= Mid-1) 
        Aux[k++] = A[i++];
    while (j <= Der)
        Aux[k++] = A[j++];
    for (i=Izq; i <= Der; i++) 
        A[i] = Aux[i]; 
    return Cont; 
}

int main() { 
    int A[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}; 
    int n = sizeof(A) / sizeof(A[0]);
    cout << "El numero de inversiones es: " << MergeSort(A, n); 
    return 0; 
}
