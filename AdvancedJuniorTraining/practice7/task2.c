#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>

//求一个整型数组的连续子数组的最大和

int MaxSum(int a[], int size, int *s, int *e){
  if(a == NULL || size == 0){
    //非法输入
    return -1;
  }

  int sum = 0;//初始和为0
  int i = 0;
  int max = a[i];//最大值最初必为数组第一个元素
  for(i; i < size; i++){
    sum = sum + a[i];//遍历一个元素，累加一次
    if(sum < a[i]){//如果加上当前元素之后的和比当前元素还小，则舍弃之前的元素，从当前元素开始累加
      *s = i;
      sum = a[i];
    }
    //如果加上当前元素之后的和比当前元素大
    //说明可以继续累加
    //如果当前和比最大值大，则更新最大值为当前和
    //否则，不做更新
    if(sum > max){
      *e = i;
      max = sum;
    }
  }
  return max;
}

void main(){
  int num[8]={1, -2, 3, 10, -4, 7, 2, -5};
  printf("Give an integer array:\n");
  int i, sum=0, start=0, end=8, max;
  for(i=0; i<8; i++){
    printf("%d  ", num[i]);
  }
  max = MaxSum(num, 8, &start, &end);
  printf("\nThe sum of all sub-arrays and the largest sub-array is:\n");
  for(i=start; i<=end; i++){
    printf("%d  ", num[i]);
  }
  printf("\nThe maximum value of the sum of all sub-arrays is %d\n", max);
  system("pause");
}