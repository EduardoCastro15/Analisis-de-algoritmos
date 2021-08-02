#include <math.h>
#include <iostream>
#include<stdio.h>
#include <cmath>
#include<stdlib.h>
// creamos una estructura donde se van a guardar los numeros primos que dividan al entero que se ingresa
struct nodo {
    int primo;
    struct nodo *sig;
}tipoNodo;
//variable global que apunta al primer nodo de la lista
struct nodo *raiz=NULL;
void insertar(int x)
{
    struct nodo *nuevo;
    	nuevo = (struct nodo*)malloc(sizeof(struct nodo));
    nuevo->primo = x;
    if (raiz == NULL)
    {
        raiz = nuevo;
        nuevo->sig = NULL;
    }
    else
    {
        nuevo->sig = raiz;
        raiz = nuevo;
    }
}
void imprimir()
{
    struct nodo *reco=raiz;
    printf("Factores del numero: \n");
    while (reco!=NULL)
    {
        printf("(%i)",reco->primo);
        reco=reco->sig;
    }
    printf("\n");
}
int extraer()
{
    if (raiz != NULL)
    {
        int primormacion = raiz->primo;
        struct nodo *bor = raiz;
        raiz = raiz->sig;
        free(bor);
        return primormacion;
    }
    else
    {
        return -1;
    }
}
void liberar()
{
    struct nodo *reco = raiz;
    struct nodo *bor;
    while (reco != NULL)
    {
        bor = reco;
        reco = reco->sig;
        free(bor);
    }
}
int siguientePrimo(int p){
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
int factoriza(int n){
float condicion;
int primo=2;
condicion=n/primo;
//se considera totalmente factorizado cuando "condicion" sea 1
while(condicion>=1){ //factorizado(data)!=final){

	if(n%primo==0){//si es divisible entre el primo que tenemos se mete
		insertar(primo);//se guarda nuestro primo
		imprimir();
		n=n/primo;//ahora N disminuye
		//cout<<"n= "<<n<<"\n ";
	}else{
	
	primo=siguientePrimo(primo);//si el primo ya no divide a N se busca otro primo que lo divida y así, hasta que n se haga 1
	
			}
	condicion=n/primo;
//	cout<<"div2= "<<n<<"/"<<primo<<"\n ";
	}
return NULL;
}
int main(){
	int numero;
	printf("Ingresa un numero que quieres factorizar: ");
	scanf("%d",&numero);
	factoriza(numero);
    imprimir();
    //printf("Extraemos de la pila:%i\n",extraer());
    //imprimir();
    liberar();
    return 0;
}
