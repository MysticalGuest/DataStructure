#include<stdio.h>
#include<Windows.h>

void main(){
	int a[100], n, i, j, temp;
  // 请输入你将要输入的整数的个数
	printf("Please enter the number of integers you will enter: ");
  scanf("%d", &n);
  // 这些整数分别是
	printf("These integers are: \n");
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	for(i=0; i<n-1; i++)
		for(j=0; j<n-i-1; j++){
			if(a[j] > a[j+1]){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
  // 程序用冒泡法按从小到大排序为
	printf("The program uses bubble method to sort from small to large: ");
	for(i=0; i<n; i++)
		printf("\t%d", a[i]);
	printf("\n");

  system("pause");
}