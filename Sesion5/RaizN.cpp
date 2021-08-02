#include <bits/stdc++.h> 
using namespace std; 
  
void nRaizPrincipal(int n){ 
    double Teta = (M_PI*2)/n;  
    for(int k=0; k<n; k++){ 
        double Real = cos(k*Teta); 
        double Img = sin(k*Teta); 
        printf("\t%.5f", Real); 
        if(Img >= 0) printf(" + i");
        else printf(" - i");
        printf("%.5f\n", abs(Img)); 
    } 
} 

int main(){ 
	char n;
	cout << "Ingresa el entero: ";
	cin >> n;
    cout << endl << "Las raices principales de " << n << " son:" << endl;
	nRaizPrincipal(n); 
    cout << endl; 
    return 0; 
}
