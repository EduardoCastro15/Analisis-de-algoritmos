#include <iostream> 
using namespace std; 
  
int NumInv(int A[], int n){ 
    int Cont = 0;
    for (int i = 0; i < n - 1; i++) 
        for (int j = i + 1; j < n; j++) 
            if ((A[i] > A[j]) || (A[i] > (2*A[j]))) 
                Cont++;
  
    return Cont; 
} 

int main(){
    int A[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}; 
    int n = sizeof(A) / sizeof(A[0]); 
    cout << "El numero de inversiones es: " << NumInv(A, n); 
    return 0; 
}
