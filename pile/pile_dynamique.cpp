#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Etudiant{
	int cne;
	char *nom,*prenom;
	struct Etudiant *suivant;
}Etudiant; 
typedef struct Pile{
	struct Etudiant *sommet;
	int taille;
}Pile;
void initialiser (Pile *P){
	P->sommet= NULL;
	P->taille = 0;
}
int empiler(Pile *P, int nouveau_cne, char *nouveau_nom, char *nouveau_prenom){
	Etudiant *nouveau_element;
	nouveau_element = (Etudiant*)malloc(sizeof(Etudiant));
	if(nouveau_element==NULL) return -1;
	nouveau_element->nom = (char*)malloc(50*sizeof(char));
	nouveau_element->prenom = (char*)malloc(50*sizeof(char));
	if(nouveau_element->nom == NULL && nouveau_element->prenom == NULL) return -1;
	nouveau_element->cne = nouveau_cne;
	strcpy(nouveau_element->nom ,nouveau_nom);
	strcpy(nouveau_element->prenom ,nouveau_prenom);
	nouveau_element->suivant=P->sommet;
	P->sommet = nouveau_element;
	P->taille++;
	return 0;
}

int depiler (Pile * P){
	Etudiant *supp_etudiant;
		if (P->taille == 0) return -1;
	supp_etudiant = P->sommet;
	P->sommet = P->sommet->suivant;
	free (supp_etudiant->nom);
	free (supp_etudiant->prenom);
	free (supp_etudiant);
	P->taille--;
	return 0;
}
void afficher (Pile *P){
	Etudiant *courant;
	int i;
	courant = P->sommet;
	for(i=0;i<P->taille;i++){
		printf("\n %d\t %s\t%s\n", courant->cne, courant->nom, courant->prenom );
		courant = courant->suivant;
	}
}
int main(){
	Pile *p;
	int n, nouveau_cne;
	char * nouveau_nom, *nouveau_prenom;
	if ((p = (Pile *) malloc (sizeof (Pile))) == NULL) return -1;
	if ((nouveau_nom = (char *) malloc (50 * sizeof (char))) == NULL)return -1;
	if ((nouveau_prenom = (char *) malloc (50 * sizeof (char))) == NULL) return -1;
	initialiser(p);
	printf(" Donner le nombre de Etudiants que vous voulez empiler: \n");scanf("%d", &n);
	for(int i=0; i<n; i++) {
		printf("\n Donner les informations a empiler : cne, nom et prenom :\n");
		scanf("%d", &nouveau_cne);
		scanf("%s", nouveau_nom);
		scanf("%s", nouveau_prenom);
		int ajout=empiler(p, nouveau_cne, nouveau_nom, nouveau_prenom);
		if (ajout==-1)
			printf("\n L'empilement a echoué");
		else if (ajout==0)
			printf("\n L'empilement a reussi");
	}
	printf("\n \t le haut de la pile \n");
		afficher (p);
	printf("\t le bas de la pile \n");
	int sup=depiler(p);
	if (sup==-1)
		printf("\n Le depilement a echoué");
	else if (sup==0)
		printf("\n Le depilement a reussi");
		printf("\n \t le haut de la pile \n");
		afficher (p);
		printf("\t le bas de la pile \n");
	return 0;
}






