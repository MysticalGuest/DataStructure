#include<stdio.h>
#include<Windows.h>
// #include<stdlib.h> //itoa所需要的库函数

// 计算最大的n位十进制数
int maxDecimal(int n){
  int i=0, max=9, result=0;
  for(i; i<n; i++){
    result = result*10 + max;
  }
  return result;
}

void main(){
  // 输入数字n,按顺序打印输出从1到最大的n位十进制数
  printf("Enter the number n and print out the decimal digits from 1 to the largest n in order: ");
  int n;
  long int i=0, count=1;
  scanf("%d", &n);
  for(i; i<maxDecimal(n); i++){
    printf("%d\t", count);
    // 每10个数换行
    if(count%10==0){
      printf("\n");
    }
    count++;
  }

  system("pause");
}

