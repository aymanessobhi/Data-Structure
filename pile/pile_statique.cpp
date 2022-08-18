#include<stdio.h>
#include<stdlib.h>
#define dimension 100
typedef struct pile{
	int sommet;
	int tab[dimension];
}Pile;
void init_pile (Pile *P){
	P->sommet=0;
}
int pile_vide (Pile *P){
	if(P->sommet==0) 
 		return 1; 
 	else 
 		return 0; 	
}
int pile_pleine (Pile *P){
	if(P->sommet==dimension) 
 		return 1; 
 	else 
 		return 0; 
}
 int empiler (Pile *P, int x){
 	 if(!pile_pleine (P)){ 
	    P->tab[P->sommet]=x;
	    P->sommet++;
	    return 1;
	}
	else {
		printf("Pile saturée") ;
	    return(0) ;
	}
}
void remplir (Pile *P){
	int n, x;
	printf(" Donner le nombre d'elements que vous voulez empiler :\n");scanf("%d", &n);
	for(int i=0; i<n; i++) {
		printf("\n Donner l'information a empiler :\t");scanf("%d", &x);
		int ajout=empiler (P, x);
			if (ajout==0)
				printf("\n L'empilement a echoue :");
			else if (ajout==1)
				printf("\n L'empilement a reussi");
	}
}
int depiler (Pile *P) {
	if(!pile_vide(P)){
		P->sommet--;
		return (P->tab[P->sommet]);
	}
	else
		puts("Pile vide"); 
 		return(-1); 
}
void affichage(Pile *P){
	int i;
	if (pile_vide(P))
		printf("La pile est vide.\n");
	else {
	printf("Le contenu de la pile: \n");
		for(i=0;i<P->sommet;i++){
			printf("%d\t",P->tab[i]);
			printf("\n");
		}	
	}
}
int rechercher (Pile * P, int x){
	int i;
	for(i=0;i<P->sommet;i++){
		if(P->tab[i]==x){
			return i;
		}		
	}
	return -1;
}
void menu(Pile *p){
	int a,x;
	while(a!=5){
		printf("\n Menu :\n0-Initialiser la pile \n1-Remplir la pile");
		printf("\n2-Depiler\n3-Afficher la pile\n");
		printf("4-rechercher dans la pile\n5-Quitter\n");
		scanf("%d",&a);
		switch (a){
			case 0:init_pile(p);break;
			case 1:remplir(p); break;
			case 2:{
					int sup=depiler(p);
						if (sup==0)
							printf("\n Le depilement a echoué");
						else
							printf("\n Le depilement a reussi"); break;
					}
			case 3:affichage(p); break;
			case 4:{
					printf("\t Entrer la valeur à rechercher :\n");scanf("%d", &x);
					int pos = rechercher (p, x);
					if (pos==-1)
						printf("\t La valeur %d ne se trouve pas dans la pile.\n", x);
					else
						printf("\t La valeur %d trouve dans la position %d.\n", x, pos); break; 
					}
			default : break;
			}
			
	}
}
int main(){
	Pile *p;
		if ((p = (Pile *) malloc (sizeof (Pile))) == NULL)
			return -1;
		menu(p);
	return 0;
	}

