#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>

void main(){
  int sum=100, num[20]={41, 67, 34, 0, 69, 24, 78, 58, 62, 64, 5, 45, 81, 27, 61, 91, 95, 42, 27, 36};
  printf("Give an array of 20 integers:\n");
  int i=0, j;
  for(i; i<20; i++){
    printf("%d  ", num[i]);
  }
  printf("\n");
  i=0;
  for(i; i<20; i++){
    int add=num[i];
    j= i+1;
    for(j; j<20; j++){
      if(add+num[j]==sum){
        printf("The sum of the two numbers found is 100, which are: %d and %d.\n", add, num[j]);
      }
    }
  }
  system("pause");
}