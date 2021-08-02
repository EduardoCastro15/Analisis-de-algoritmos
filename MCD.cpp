#include <math.h>
#include <iostream>
#include<stdio.h>
#include <cmath>
#include<stdlib.h>

//Creamos una estructura que usaremos para crear pilas de los elementos
//primos que dividan a los numeros que ingrese el usuario
struct nodo {
    int primo;
    struct nodo *sig;
}tipoNodo;
struct nodo* insertar( struct nodo *raiz, int x)//agrega el primo a la pila que se seleccionó
{
    struct nodo *nuevo;
    nuevo = (struct nodo*)malloc(sizeof(struct nodo));
    nuevo->primo = x;
    if (raiz == NULL){
        raiz = nuevo;
        nuevo->sig = NULL;
    }
    else{
        nuevo->sig = raiz;
        raiz = nuevo;
    }
    return raiz;
}
int imprimir(struct nodo *raiz){
    struct nodo *reco=raiz;
    int mult=1;
//    printf("Factores del numero: \n");
    while (reco!=NULL){
        printf("(%i)",reco->primo);
        mult=mult*(reco->primo);
        reco=reco->sig;
    }
    return mult;
}
int extraer(struct nodo *raiz){
    if(raiz != NULL){
        int primormacion = raiz->primo;
        struct nodo *bor = raiz;
        raiz = raiz->sig;
        free(bor);
        return primormacion;
    }
    else{
        return -1;
    }
}
void liberar(struct nodo *raiz){
    struct nodo *reco = raiz;
    struct nodo *bor;
    while (reco != NULL){
        bor = reco;
        reco = reco->sig;
        free(bor);
    }
}
int siguientePrimo(int p){//calcula el numero primo que le sigue al numero que le pasen al parametro
	p++;
	while(true){
		int a=0;
		for(int i=1; i<=p; i++){ //Ciclo que nos permite recorrer el numero uno a uno
        if(p%i==0){
            	a++;
				// Condicion que obtiene el modulo del numero ingresado entre el iterador
				// Y si el resultado es igual a 0, entonces, incremente en 1 el contador
    		}
    	}
    	//printf("P: %d y a= %d\n",p,a);
    	if(a==2) return p;
    	else{
    	//	printf("P: %d\n",p);
    		p++;
		}
	}
}
int mcd(int n1, int n2){
	struct nodo *raiz=NULL;//el nodo raiz es la pila raiz donde se guardaran los primos para calcular el mcd
	struct nodo *p1=NULL;//guarda los numeros primos de n1
	struct nodo *p2=NULL;//** de n2
	int condicion1, condicion2, cont=0;
	int primo=2, num1=n1,num2=n2;
	condicion1=n2/primo;
	condicion2=n2/primo;
	while( true){ //factorizado(data)!=final){
			//con el contador checamos hasta que ambos numeros den 0 para que se pare el ciclo
			if (condicion1==0) cont++;
			if(condicion2==0)cont++;
			if(cont==2)break;
			if(n1%primo==0 || n2%primo==0){
				if(n1%primo==0 && n2%primo==0){
					raiz=insertar(raiz, primo);
				}	
				if(n1%primo==0){
					p1=insertar(p1, primo);
					n1=n1/primo;
				}
				if(n2%primo==0){
					p2=insertar(p2, primo);
					n2=n2/primo;
				}
			}
			else{
				primo=siguientePrimo(primo);
			}
				
		condicion1=n1/primo;
		condicion2=n2/primo;
		cont=0;
	}
	printf("el mcd es: ");
	printf(" =%d", imprimir(raiz));
	printf("\nla factorizacion de %d es: ", num1);
	imprimir(p1);
	printf("\nla factorizacion de %d es: ", num2);
	imprimir(p2);
    liberar(raiz);
    liberar(p1);
    liberar(p2);
}
int main(){
	int numero1, numero2;
	printf("Ingresa un numero que quieres factorizar: ");
	scanf("%d",&numero1);
	printf("Ingresa otro numero que quieres factorizar: ");
	scanf("%d",&numero2);	
	mcd(numero1,numero2);
	return 0;
}
