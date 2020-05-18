#include<stdio.h>
#include<Windows.h>

void main(){
	int i, j, a[10] = {12,56,9,23,21,33,18,36,55,6}, *p, temp;
	p=a;
	for(i=0; i<9; i++)
		for(j=0; j<9-i; j++)
			if(*(p+j) > *(p+j+1)){
				temp = *(p+j);
				*(p+j) = *(p+j+1);
				*(p+j+1) = temp;
			}
	for(i=0; i<10; i++)
		printf("%d\n", *(p+i));

  system("pause");
}