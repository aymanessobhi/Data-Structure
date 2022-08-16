#include<stdlib.h>
#include<stdio.h>

int main(){
	
int t[50],x,n,*p,*pt;
p=t; //p=&t[0];
pt=t;

printf("Entrer la dimension de tableau :");scanf("%d",&n);

printf("Entrer les elements de tableau :\n");
for(;p<t+n;p++){
	scanf("%d",p);
}
for(p=t;p<t+n;p++){
	for(pt=p+1;pt<t+n;pt++){
	if(*p>*pt){
		int tmp = *p;
		*p = *pt;
		*pt = tmp;
	}  
  }
}

printf("les elements du tableau dans l'ordre croissant: \n");
for(p=t;p<t+n;p++){
	printf(" %d ",*p);
}
printf("\nles elements du tableau dans l'ordre decroissant: \n");
for(p=t+n-1;p>=t;p--){
	printf(" %d ",*p);
}
}
