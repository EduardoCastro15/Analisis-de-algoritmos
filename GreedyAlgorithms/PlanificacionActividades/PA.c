#include<stdio.h> 

void PA(int s[], int f[], int n){ 
    int i=0, j; 
    printf("\nLas siguientes actividades fueron seleccionadas: "); 
    printf("%d, ", i);  
    for(j=1; j<n; j++)
    	if(s[j]>=f[i]){ 
        	printf("%d, ", j); 
        	i=j; 
    	} 
} 
 
int main(){ 
    int s[]={1, 3, 0, 5, 8, 5, 9, 7, 2, 5, 11, 12}; 
    int f[]={2, 4, 6, 7, 9, 9, 12, 8, 3, 6, 12, 15}; 
    int n=sizeof(s)/sizeof(s[0]); 
    PA(s, f, n); 
    return 0; 
} 
