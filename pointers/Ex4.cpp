#include<stdlib.h>
#include<stdio.h>

void echange(int *x,int *y){
	int tmp;
	if(*x>0 && *y>0){
	tmp = *x;
	*x = *y;
	*y = tmp;
    }
    else{
    int *z;
	*z=*x;	
    *x = *x + *y;
	*y= *z * *y;	
	}
	
}

int main(){
	
int a,b,*p,*pt,tmp;
p=&a;
pt=&b;

printf("Entrer un nombre a :");scanf("%d",p);
printf("Entrer un nombre b :");scanf("%d",pt);

		echange(p,pt);
		printf("la valeur de a devient : %d\n",*p);
		printf("la valeur de b devient : %d\n",*pt);

}
