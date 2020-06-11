#include<stdio.h>
#include<Windows.h>

#define N 100

int arrange(int n){ 
  int array[N][N];
  int i, j;
  // 当100元和50元人数不相等，100元0人，则只有1中解决方案
  for(i=0; i<n; i++){
    array[i][0]=1;
  }
  // 若50元人数小于100元人数，则没有解决方案
  // 则二维数组的上三角的值都为0，不用初始化赋值
  // 开始递推，填满下三角矩阵数组
  for(i=1; i<=n; i++){
    for(j=0; j<=i; j++)
      array[i][j]=array[i-1][j]+array[i][j-1];
  }
  return array[n][n];
}

void main(){
  int n;
  printf("Please enter the number of people queuing to purchase tickets: n=");
  scanf("%d", &n);
  printf("%d people have %d queuing methods\n", 2*n, arrange(n));
  system("pause");
}