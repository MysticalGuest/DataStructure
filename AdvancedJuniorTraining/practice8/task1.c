#include<stdio.h>
#include<Windows.h>

#define RED 0
#define WHITE 1
#define BLUE 2

void swap(int *p, int *q){
  int temp;
  temp = *p;
  *p = *q;
  *q = temp;
}

void sort(int array[], int start, int end, int collor){
  int i=start, j=end;
  while(i < j){
    while(array[i]==collor){
      i++;
    }
    while(array[j]!=collor){
      j--;
    }
    swap(&array[i], &array[j]);
    i++;
  }
}

void main(){
  int ball[20]={1,2,2,0,1,0,1,2,0,0,0,1,2,1,0,1,2,0,0,1};
  int i, num_red=0;
  printf("There are 20 red, blue and white balls in three different colors, arranged together in disorder:\n");
  for(i=0; i<20; i++){
    if(ball[i]==RED){
      num_red++;
      printf("Red  ");
    }
    if(ball[i]==WHITE)
      printf("White  ");
    if(ball[i]==BLUE)
      printf("Blue  ");
  }
  printf("\n");
  sort(ball, 0, 20, RED); // 把红色球排好序
  sort(ball, num_red, 20, WHITE); // 把白色球排好序
  printf("\nAfter sorting: \n");
  for(i=0; i<20; i++){
    if(ball[i]==RED)
      printf("Red  ");
    if(ball[i]==WHITE)
      printf("White  ");
    if(ball[i]==BLUE)
      printf("Blue  ");
  }
  printf("\n");
  system("pause");
}