#include <stdio.h> 
#include <stdlib.h> 
main() { 
 /* Déclarations */ 
 int m, n; /* dimensions de la matrice */ 
 int i, j;  
 
 printf("Nombre de lignes (max.50) : "); 
 scanf("%d", &m ); 
 printf("Nombre de colonnes (max.50) : "); 
 scanf("%d", &n ); 
 int t[m][n]; /* matrice */

 for (i=0; i<m; i++) 
 for (j=0; j<n; j++) { 
 printf("t[%d][%d] : ",i,j); 
 scanf("%d", &t[i][j]); // (int *)t+i*n+j; // cast sur j 
 } 
 
 printf("Matrice :\n"); 
 for (i=0; i<m; i++) { 
  for (j=0; j<n; j++) 
 printf("%7d", t[i][j]); // *((int *)A+I*N+J); 
 printf("\n"); 
 } 
}
