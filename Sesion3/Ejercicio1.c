#include <stdio.h>

int MCD(int a, int b){
	return b ? MCD(b, a % b) : a;
}

/*int MCD(int a, int b){
	if(b==1) return a;
	else if((a%2 == 0) && (b%2 == 0))
		return MCD(a/2, b/2)*2;
	else if((a%2 != 0) && (b%2 == 0))
		return MCD(a, b/2);
	else if((a%2 != 0) && (b%2 != 0))
		return MCD((a-b)/2, b);
}*/

int main(){
	int a, b, mcd;
	printf("Ingrese el valor de a: ");
	scanf("%d", &a);
	printf("Ingrese el valor de b: ");
	scanf("%d", &b);
	if (b > a) mcd=MCD(b, a);
	else mcd=MCD(a, b);
	printf("El MCD de %d y %d es: %d", a, b, mcd);
	return 0;
}
