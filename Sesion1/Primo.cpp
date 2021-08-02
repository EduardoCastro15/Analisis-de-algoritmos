#include <iostream>

using namespace std;

int Primo(int n){
	int a; //a-> Contador
	for(int i=1; i<(n+1); i++){ //Ciclo que nos permite recorrer el numero uno a uno
        if(n%i==0){
            	a++;
				// Condicion que obtiene el modulo del numero ingresado entre el iterador
				// Y si el resultado es igual a 0, entonces, incremente en 1 el contador
    	}
	}
	return a; //Retorna el valor a main
}

int main(){
   	int a, n;	//Variables a utilizar
   					//a-> Contador
   					//n-> Numero que va a ingresar el usuario
    cout<<"Ingrese numero"<<endl;
    cin>>n; //Almacena el numero ingresado, en la variable
    
    a=Primo(n); //Llamado a funcion, con paso de variable
    
    if(a!=2){ //En caso de que el contador sea distinto a 2, entonces, no es primo
      	cout<<"No es Primo";
    }
	else{ // En caso contrario, es primo
        cout<<"Si es Primo";
    }
    return 0;
}




