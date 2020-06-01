#include<stdio.h>
#include<Windows.h>

void main(){
  int matrix[4][5] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}, i, j;
  int obj;
	printf("Give a matrix: \n\t[1]\t[2]\t[3]\t[4]\t[5]\n==========================================\n");
	for(i=0; i<4; i++){
    printf("[%d]\t", i+1);
		for(j=0; j<5; j++){
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
	printf("Please enter the elements of the array you want to locate:");
  scanf("%d", &obj);
  for(i=0; i<4; i++){   // 定位行坐标i
    if(obj <= matrix[i][4])
      break;
  }
  for(j=0; j<5; j++){   // 定位列坐标j
    if(obj <= matrix[i][j])
      break;
  }
  printf("The position of the element %d you want to locate is: (%d, %d)\n", obj, i+1, j+1);
  system("pause");
}