#include<stdio.h>

int Multiply(int x, int y){
	if (y==0) return 0;
	int z=Multiply(x, y/2);
	if (y%2==0) return (2*z);
	else  return (x+(2*z));
}

int main(){
	int x, y;
	printf("Ingresa el valor de x: ");
	scanf("%d", &x);
	printf("Ingresa el valor de y: ");
	scanf("%d", &y);
	
	printf("Resultado de %d * %d = %d", x, y, Multiply(x, y));
}
