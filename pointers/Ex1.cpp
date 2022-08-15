#include<stdlib.h>
#include<stdio.h>
int main(){
float a,b,*p,*pt;
p=&a;
pt=&b;

printf("Entrer un nombre :");scanf("%f",p);
printf("Entrer un nombre :");scanf("%f",pt);
//calcule la somme
printf("/nla somme est :%.2f\n",*p + *pt);
//calcule le produit
printf("le produit est :%.2f\n",*p * *pt);
//la difference
printf("la difference est :%.2f\n",*p - *pt);
//devision de deux nombre rell
	if(*pt!=0)
		printf("la devision est :%.2f\n",*p / *pt);
	else{
		printf("Impossible de deviser par 0 !!!");
	}

}
