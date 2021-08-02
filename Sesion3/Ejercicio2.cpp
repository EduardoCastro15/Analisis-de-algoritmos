#include <iostream>
using namespace std; 

int Horner(int P[], int n, int x){
	if (n<0) return 0;
	int Res = P[n-1];
	n--;
	Res += Horner(P, n, x) * x;
	return Res;
}

int main() { 
    int P[] = {1, 3, 5, 7, 9}; //P(x) = x^4 + 3x^3 + 5x^2 + 7x + 9 
    int x = 2; //P(2)=83
    int n = sizeof(P)/sizeof(P[0]); 
    cout << "El valor del polinomio es: " << Horner(P, n, x); 
    return 0; 
} 
