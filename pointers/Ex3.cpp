#include<stdlib.h>
#include<stdio.h>
int main(){
int i;	
int a,*p;
p=&a;
do{
	printf("Entrer un nombre :");scanf("%d",p);
}while(*p<=0);

printf("les deviseurs de %d est: ",*p);	
for(i=1;i<*p;i++){
	
	if(*p%i==0){
		printf("%d\t",i);
	}
		
}

}
