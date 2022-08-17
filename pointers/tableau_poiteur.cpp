#include<stdio.h>
#include<stdlib.h>
int* allouer_vecteur (int dimension, int val){
	int *pt;
	int  *vecteur= (int*)malloc(dimension*sizeof(int));
	for(pt=vecteur;pt<vecteur+dimension;pt++){
		*pt = val;
	}
	return vecteur;
}
void afficher_vecteur (int *vecteur, int dimension){
	int *pt;
	for(pt=vecteur;pt<vecteur+dimension;pt++){
		printf(" %d ",*pt);
	}
}
int* modifier_vecteur(int* vecteur, int indice, int nouvelle_val){
*(vecteur+indice)=nouvelle_val;
return vecteur;
}
int rechercher_vecteur(int* vecteur, int dimension, int X){
	int *pt, indice=-1;
	for(pt=vecteur; pt<vecteur+dimension; pt++)
		if(*pt==X)
			return pt-vecteur; 
	return indice; 
}
int* liberer_vecteur(int* vecteur, int dimension){
	for(int i=0; i<dimension; i++)

	*(vecteur+i)=NULL;
		free(vecteur);
	return vecteur;
}
int main(){
	int dimension, val, indice, nouvelle_val, X;
	int *vecteur;
	printf("Donner la dimension du vecteur :");scanf("%d", &dimension);
	printf("Donner une valeur : ");scanf("%d", &val);
	vecteur=allouer_vecteur(dimension, val);
	afficher_vecteur(vecteur,dimension);
	printf("\nDonner l'indice de la valeur que vous voulez modifier: \t");scanf("%d", &indice);
	if(indice>=0 && indice<dimension) {
		printf("\nDonner la nouvelle valeur: \t");scanf("%d", &nouvelle_val);
		vecteur=modifier_vecteur(vecteur, indice, nouvelle_val);
	}
	afficher_vecteur(vecteur, dimension);
	printf("\nDonner la valeur à rechercher: \t");scanf("%d", &X);
	indice=rechercher_vecteur(vecteur, dimension, X);
	if(indice==-1)
		printf("La valeur %d n'existe pas dans le vecteur", X);
	else
		printf("\nLa valeur %d se trouve dans la position : %d\n", X, indice);
	vecteur=liberer_vecteur(vecteur, dimension);
	printf("Affichage du vecteur après libération de ma mémoire:\n");
	afficher_vecteur(vecteur,dimension);
	return 0;
}

