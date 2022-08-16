#include<stdlib.h>
#include<stdio.h>

int main(){
	
int t[50],d[50],x,n,*p,*pt;
p=t; //p=&t[0];
pt=t;
printf("Entrer le nombre x :");scanf("%d",&x);

printf("Entrer la dimension de tableau :");scanf("%d",&n);

printf("Entrer les elements de tableau :\n");
for(;p<t+n;p++){
	scanf("%d",p);
}
for(p=t;p<t+n;p++){
	*pt = *p;
	if(*pt !=x)
	    pt++;
}
n=n-*pt;

printf("les elements du tableau apres l'elemination des occurences de %d sont: \n",x);
for(p=t;p<t+n;p++){
	printf(" %d ",*p);
}
}
