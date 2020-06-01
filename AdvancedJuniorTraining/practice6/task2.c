#include<stdio.h>
#include<Windows.h>

#define N 10

void PrintMatrix(int (*num)[4], int col, int row, int layer){
  int i;
	int new_col = col - layer;
	int new_row = row - layer;
  for(i=layer; i<new_col; i++){		// 从左至右打印第一行
    printf("%d   ", num[layer][i]);
  }
	if(new_row>layer){
		for(i=layer+1; i<new_row; i++){		// 从上至下打印最右一列
			printf("%d   ", num[i][new_row-1]);
		}
	}
	if(new_col-1>layer && new_row-1>layer){
		for(i=new_col-2; i>=layer; i--){		// 从右至左打印最后一行
			printf("%d   ", num[new_col-1][i]);
		}
	}
	if(new_col-1>layer && new_row-1>layer+1){
		for(i=new_row-2; i>layer; i--){		// 从下至上打印最左一列
			printf("%d   ", num[i][layer]);
		}
	}
}

// 顺时针打印矩阵
void main(){
	int matrix[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16}, i, j;
	printf("Give a matrix: \n");
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
  /* a[0][0] a[0][1] a[0][2] a[0][3] a[1][3] a[2][3] a[3][3] a[3][2] a[3][1] a[3][0] a[2][0] a[1][0] */
	printf("Print matrix clockwise: \n");
	int layer = 0; 	
	while( 2 * layer<4 && 2 * layer<4){ 	//圈数循环
		PrintMatrix(matrix, 4, 4, layer);	
		layer++; 	
	}
  printf("\n");
  system("pause");
}