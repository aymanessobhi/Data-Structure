#include<stdlib.h>
#include<stdio.h>

int main(){
	
int a[50],b[50],m,n,*pa,*pb;
pa=a; //pa=&a[0];
pb=b; //pb=&b[0];
 
printf("Entrer la dimension de tableau a :");scanf("%d",&m);
printf("Entrer la dimension de tableau b :");scanf("%d",&n);
printf("Entrer les elements de tableau a :\n");
for(;pa<a+m;pa++){
	scanf("%d",pa);
}
printf("Entrer les elements de tableau b :\n");
for(;pb<b+n;pb++){
	scanf("%d",pb);
}
for(pa=a+m,pb=b;pa<a+m+n;pa++,pb++){	
	*pa=*pb;
}
printf("Entrer les elements de tableau b :\n");
for(pa=a;pa<a+n+m;pa++){
	printf(" %d ",*pa);
}
}

