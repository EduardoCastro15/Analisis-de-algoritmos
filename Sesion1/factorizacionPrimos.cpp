
#include <math.h>
#include <iostream>
#include<stdio.h>
#include <cmath>
#include<stdlib.h>

struct nodo {
    int info;
    struct nodo *sig;
}tipoNodo;


//variable global que apunta al primer nodo de la lista
struct nodo *raiz=NULL;

void insertar(int x)
{
    struct nodo *nuevo;
    	nuevo = (struct nodo*)malloc(sizeof(struct nodo));
    nuevo->info = x;
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
        printf("(%i)",reco->info);
        reco=reco->sig;
    }
    printf("\n");
}

int extraer()
{
    if (raiz != NULL)
    {
        int informacion = raiz->info;
        struct nodo *bor = raiz;
        raiz = raiz->sig;
        free(bor);
        return informacion;
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

while(condicion>=1){ //factorizado(data)!=final){

	if(n%primo==0){
		insertar(primo);
		imprimir();
		n=n/primo;
		//cout<<"n= "<<n<<"\n ";
	}else{
	
	primo=siguientePrimo(primo);
	
			}
	condicion=n/primo;
//	cout<<"div2= "<<n<<"/"<<primo<<"\n ";
	}
return NULL;
}

int main()
{
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
