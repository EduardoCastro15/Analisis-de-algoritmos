#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<fstream>

using namespace std;

typedef struct point{
    double px; 
    double py; 
    point(double x, double y){ 
        px = x;
        py = y;
    }
}point;

double calculateD(point p1, point p2){
    double d;
    double dpx = p2.px - p1.px; 
    double dpy = p2.py - p1.py; 
    d = sqrt(pow(dpx, 2) + pow(dpy, 2));    
    return d;
}
void getDistances(point *p, int n){
    int p1, p2; 
    int i, j; 
    double d;
    double mind=1000; 
    for(i=0; i<n; i++){
        for (j=i+1; j<n; j++)
        {
            d=calculateD(p[i], p[j]);
            printf("Distancia entre P[%d] y P[%d]: %0.3lf \n", i+1, j+1, d);
            if (d < mind) 
            {
                mind = d;
                p1 = i;
                p2 = j;
            }
        }
    }
    printf("\nLa distancia mas corta es entre P[%d] y P[%d]", p1+1, p2+1);
}


point* create(int n){
    point* p; 
    p = (point* )calloc(n, (sizeof(point)));
    return p;
}
point* fill(point *p, int n){
    char delim; 
    int i;
    ifstream inData;  
    inData.open("input.txt"); 
    for (i=0; i<20; i++) {
        inData >> p[i].px >> delim >> p[i].py;
    }
    inData.close(); 
    return p;
}
void showArr(point *p, int n){
    for(int k = 0; k < n; k++){
        printf("\nP[%d]: (%0.3lf , %0.3lf)", k + 1, p[k].px, p[k].py);
    }
}

int main(){
    int n;
    point *p;
    printf("Numero de puntos que contiene el archivo: ");
    scanf("%d", &n);
    p = create(n);
    p = fill(p, n);
    showArr(p, n);
    printf("\n\n");
    getDistances(p, n);
    return 0;
}

