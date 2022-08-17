#include<stdio.h>
#include<stdlib.h>
int** allouer_matrice (int lignes, int colonnes, int val){
	int *pt,i,j;
	int **matrice = (int**)malloc(lignes*sizeof(int*));
	for(i=0;i<lignes;i++){
		matrice[i]=(int*)malloc(colonnes*sizeof(int));
	}
	pt=&matrice[0][0];// pt=matrice[0];
	for(i=0;i<lignes;i++){
		for(j=0;j<colonnes;j++){
			*(pt+i*colonnes+j)=val;
		}
	}
	return matrice;
}
void afficher_matrice(int** matrice, int lignes, int colonnes){
	int i, j, *pt;
	pt=&matrice[0][0];
	for(i=0; i<lignes; i++) {
		for(j=0; j<colonnes; j++)
			printf("%d\t", *(pt+i*colonnes+j));
		printf("\n");
	}
}
int ** modifier_matrice(int** matrice, int colonnes, int L, int C, int nouvelle_val){
	int *pt;
		pt=&matrice[0][0];
		*(pt+L*colonnes+C)=nouvelle_val;
	return matrice;
}
void rechercher_matrice(int** matrice, int lignes, int colonnes, int X, int *L, int *C){
// passage par adresse de L et C
	int i, j, *pt;
	pt=&matrice[0][0];
	for(i=0; i<lignes; i++)
		for(j=0; j<colonnes; j++)
			if( ( *(pt+i*colonnes+j) ) == X ) {
				*L=i;
				*C=j;
			return;
	}
}
int** liberer_matrice (int ** matrice, int lignes){
	int i;
	for (i=0;i<lignes;i++)
		free((int *)matrice[i]);
	return matrice;
}
int main(){
int lignes, colonnes, val, L, C, nouvelle_val, X;
int **matrice;
	printf("Donner les dimensions de la matrice ");
	printf("\n Donner le nbre de lignes ");scanf("%d", &lignes);
	printf("\n Donner le nbre de colonnes ");scanf("%d", &colonnes);
	printf("\n Donner une valeur ");scanf("%d", &val);
	matrice=allouer_matrice(lignes, colonnes, val);
	afficher_matrice(matrice, lignes, colonnes);
	printf("\n Donner les coordonnées de la valeur à modifier\t");scanf("%d %d", &L,&C);
	if(L>=0 && L<lignes && C>=0 && C<colonnes) {
	printf("\n Donner la nouvelle valeur\t");scanf("%d", &nouvelle_val);
	matrice=modifier_matrice(matrice, colonnes, L, C, nouvelle_val);
	}
	afficher_matrice(matrice, lignes, colonnes);
	printf("\n Donner la valeur à rechercher\t");scanf("%d", &X);
	L=C=-1;
	rechercher_matrice(matrice, lignes, colonnes, X, &L, &C);
		if(L==-1 || C==-1)
			printf("La valeur %d n'existe pas dans la matrice", X);
		else
		printf("\n La valeur %d a les coordonnées %d %d\n", X, L, C);
	matrice=liberer_matrice(matrice, lignes);
	printf("\n La matrice apres liberation de la mémoire\n");
	afficher_matrice(matrice, lignes, colonnes);
return 0;
}


