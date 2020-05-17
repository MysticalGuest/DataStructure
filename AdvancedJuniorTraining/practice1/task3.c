#include<stdio.h>
#include<Windows.h>

int convert(int x){  // 十进制转二进制
  int binary=0b0, i=0;
  for(i; i<x; i++){
    binary++;
  }
  return binary;
}

void main(){
  int n,factorial=1, i=1, numOfZero=0;
  printf("Please enter an integer and the program will calculate its factorial:");
  scanf("%d", &n);
  for(i ; i<=n; i++){   // 求阶乘
    factorial *= i;
  }
  printf("The factorial of n is %d\n", factorial);
  int binary = convert(factorial);
  while(1){   // 求位置
    numOfZero++;
    if(binary%2==1)
      break;
    binary = binary>>1;
  }
  printf("When representing n! In binary, the position of the lowest bit 1 is (from right to left): %d\n", numOfZero);
  system("pause");
}
