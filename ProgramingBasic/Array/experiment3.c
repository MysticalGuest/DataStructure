#include<stdio.h>
#include<Windows.h>

void main(){
	int a[5][4]={7,23,14,3,45,25,78,44,57,52,5,81,20,34,4,29,56,61,2,37}, i, j, k, max, min=0, num=0;
	printf("Give a matrix: \n");
	for(i=0; i<5; i++){
		for(j=0; j<4; j++){
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
  // 其鞍点有
	printf("Its saddle point has: ");
	for(i=0; i<5; i++){
		max = 0;
    // 在其行最大
		for(j=1; j<4; j++)
			if(a[i][max] < a[i][j])
				max = j;
    // 在其列最小
		for(k=0; k<5; k++)
			if(a[i][max] > a[k][max]){
				min = 1;
				num++;
				break;
			}
			if(min==0)
				printf("%d\t", a[i][max]);
	}
	if(num==5)
		printf("0!");
  printf("\n");

  system("pause");
}