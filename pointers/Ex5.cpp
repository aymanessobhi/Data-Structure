#include<stdlib.h>
#include<stdio.h>

int main(){
	
int t[10],n,*p;
p=t; //p=&t[0];

printf("Entrer la dimension de tableau :");scanf("%d",&n);

printf("Entrer les elements de tableau :\n");
for(;p<t+n;p++){

	scanf("%d",p);
}
printf("les elements de tableau :");
for(p=t;p<t+n;p++){
	printf(" %d ",*p);
}


}
