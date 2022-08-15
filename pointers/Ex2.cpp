#include<stdlib.h>
#include<stdio.h>
int main(){
	
int a,*p;
p=&a;

printf("Entrer un nombre :");scanf("%d",p);
	    if(*p % 2==0)
			printf("le Nombre de a est un nombre paire");
		else
			printf("le Nombre de a est un nombre impaire");

}
