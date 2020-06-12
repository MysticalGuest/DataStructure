#include<stdio.h>
#include<Windows.h>

void perfect_shuffle(char *a[],int n) {
  int n2 = n * 2, i, j;
  char *b[20];
  for (i = 1; i < n2-1; i++) {
    j=(i * 2) % (n2 -1);
    b[j] = a[i];
  }
  for (i = 1; i < n2-1; i++) {
    a[i] = b[i];
  }
}

void main(){
  char *array[20] = {"a1", "a2", "a3", "a4", "a5", "a6", "a7", "a8", "a9", "a10",
  "b1", "b2", "b3", "b4", "b5", "b6", "b7", "b8", "b9", "b10"};
  int i, j;
  char *temp;
  printf("Give an array of length 20: \n");
  for(i=0; i<20; i++){
    printf("%s  ", array[i]);
  }
  printf("\n");
  perfect_shuffle(array, 10);
  printf("After \"sort\": \n");
  for(i=0; i<20; i++){
    printf("%s  ", array[i]);
  }
  printf("\n");
  system("pause");
}