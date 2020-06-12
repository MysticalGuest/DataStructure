#include<stdio.h>
#include<Windows.h>

void main(){
  char *array[20] = {"a1", "a2", "a3", "a4", "a5", "a6", "a7", "a8", "a9", "a10",
  "b1", "b2", "b3", "b4", "b5", "b6", "b7", "b8", "b9", "b10"};
  int i, j, k;
  char *temp;
  printf("Give an array of length 20: \n");
  for(i=0; i<20; i++){
    printf("%s  ", array[i]);
  }
  printf("\n");
  /*
    依次考察每个位置的变化规律
    a1: 0->不变
    a2: 1->2
    a3: 2->4
    a4: 3->6
    ...
    an: n-1 -> 2n-2
    b1: n -> 1
    b2: n+1 -> 3
    b3: n+2 -> 5
    ...
    bn-1: 2n-2 -> 2n-3
    bn: 2n-1 -> 不变
  */
  i=0;
  j=1;
  while(i<20){
    k=j;
    temp=array[j];
    if(array[j][0]=='a')
      j=2*j;
    else
      j=2*j-3;
    array[k]=array[j];
    array[j]=temp;
    i++;
  }
  printf("After \"sort\": \n");
  for(i=0; i<20; i++){
    printf("%s  ", array[i]);
  }
  printf("\n");
  system("pause");
}