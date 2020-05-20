#include<stdio.h>
#include<string.h>
#include<Windows.h>

void tran(int *p, int a, int b){
	int i, j, n=0;
  // 上述矩阵的转置矩阵为
	printf("The transposed matrix of the above matrix is: \n");
	for(i=0; i<b; i++){
		for(j=0; j<a; j++)
			printf("%d\t", *((p+j*4)+i));
		printf("\n");
	}
}

void main(){
	int a[4][4] = {3,4,6,7,23,12,32,21,43,56,19,18,10,5,1,45}, i, j;
	for(i=0; i<4; i++){
		for(j=0; j<4; j++)
			printf("%d\t", a[i][j]);
		printf("\n");
	}
	tran(a, 4, 4);

  system("pause");
}
