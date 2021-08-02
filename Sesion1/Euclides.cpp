#include <stdio.h>

int mcd(int a, int b){//Funcion recursiva que obtiene el mcd
    if(b==0){//En caso de que b se identica a 0
    	return a;//Retorna el valor de a
	}
	else{//En caso contrario
		return mcd(b, a%b);//Manda a llamarse a si mismo
	}
}

int main(){
	int a, b; //Variables que van a almacenar los numeros enteros
	printf("Ingrese a: ");
	scanf("%d", &a); //Leemos a
	printf("Ingrese b: ");
	scanf("%d", &b); //Leemos
	printf("\nEl Maximo Comun Divisor es: %d", mcd(a,b));
	//Manda a llamar a la funcion e imprime el resultado
}
