#include<stdio.h>
#include<Windows.h>

int Cover(int n){
  if(n<=0){
    return 0;
  }
  else if(n==1||n==2){
    return n;
  }
  else{
    return Cover(n-1)+Cover(n-2);
  }
}

void main(){
  int n;
  printf("Please enter the number of 2 * 1 small rectangles: ");
  scanf("%d", &n);
  printf("There are %d ways to cover large rectangles \n", Cover(n));
  system("pause");
}
