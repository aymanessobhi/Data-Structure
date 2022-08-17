#include<stdio.h>
#include<stdlib.h>
int ** alloue_triangle_pascal(int dimension){
	int i,j; 
	//int** triangle = (int**) malloc(dimension*sizeof(int *));
	int** triangle = (int**) calloc(dimension, sizeof(int *));
	for (i=0;i<dimension; i++)
		//triangle[i]= (int*) malloc(i*sizeof(int));
		triangle[i]= (int*) calloc(i, sizeof(int));
	return triangle;
}
int ** remplit_triangle_pascal(int dimension){
	int i, j;
	int** triangle = alloue_triangle_pascal(dimension);
		for (i=0;i<dimension; i++) {
			triangle[i][0]=1;
			triangle[i][i]=1;
	}
	for (i=2;i<dimension; i++)
		for(j=1;j<i; j++)
			triangle[i][j]= triangle[i-1][j-1]+ triangle[i-1][j];
	return triangle;
}
void affiche_vecteur(int * vecteur, int dimension){
	/*int i;
	for(i=0;i<dimension; i++)
	printf("%d ",vecteur[i]);*/
	for(int *p=vecteur; p<vecteur+dimension; p++)
	printf("%d ",*p);
	printf("\n");
}
void affiche_triangle_pascal(int ** triangle, int dimension){
	int i;
		for(i=0;i<dimension;i++)
			affiche_vecteur(triangle[i],i+1);
		printf("\n");
}
int main(){
	int n=6;
	int ** triangle= remplit_triangle_pascal(n);
	affiche_triangle_pascal(triangle, n);
system("pause");
return 0;
}
