#include<stdio.h>
#include<Windows.h>

void main(){
	int a[4][4] = {7,23,14,3,45,25,78,44,57,52,5,81,20,34,4,29}, i, j;
	printf("Give a matrix: \n");
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
  // 程序实现矩阵的转置：
	printf("The program realizes the transposition of the matrix: \n");
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			printf("%d\t", a[j][i]);
		}
		printf("\n");
	}

  system("pause");
}