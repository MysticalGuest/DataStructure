#include<stdio.h>
#include<Windows.h>

void main(){
  float sum=0, i=1, j=1, m=2, n;
  while(j <= 20){
    sum = m/i + sum;
    n = i;
    i = m;
    m = n+m;
    j++;
  }
  printf("sum=%f\n",sum);
  
  system("pause");
}