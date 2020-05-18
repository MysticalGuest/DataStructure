#include<stdio.h>
#include<Windows.h>

void main(){
	int i, n=0;
	for(i=1; i<=200; i++){
		if(i%3 != 0){
			printf("%d\t", i);
			n++;
		}
		if(n%10==0)
			printf("\n");
	}
	printf("\n");
  
  system("pause");
}