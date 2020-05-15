#include<stdio.h>
#include<Windows.h>

void main(){
  int n, factorial=1, i=1, numOfZero=0;
  printf("Please enter an integer and the program will calculate its factorial:");
  scanf("%d", &n);
  for(i ; i<=n; i++){
    factorial *= i;
  }
  printf("The factorial of n is %d\n", factorial);
  while(factorial>0){
    if(factorial%10==0)
      numOfZero++;
  else
    break;
    factorial = factorial / 10;
  }
  printf("The number of zeros at the end of n! is: %d\n", numOfZero);
  system("pause");
}
