#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>

void main(){
  int random, num[20], i=0, max, min;
  printf("Give an array of 20 integers:\n");
  for(i; i<20; i++){    // 使用随机数初始化数组
    random = rand()%100;
    num[i] = random;
    printf("%d  ", num[i]);
  }
  if(num[0]<num[1]){
    max=num[1];
    min=num[0];
  }
  else{
    max=num[0];
    min=num[1];
  }
  i=2;    // 从2开始比较
  for(i; i<20; i++){
    if(num[i]>max)
      max=num[i];
    if(num[i]<min)
      min=num[i];
  }
  printf("\nThe maximum value of the array is: %d", max);
  printf("\nThe minimum value of the array is: %d\n", min);
  system("pause");
}