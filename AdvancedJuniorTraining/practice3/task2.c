#include<stdio.h>
#include<Windows.h>

void sort(int a[], int length){
  int i, j, min, temp;
  for(i=0; i<length; i++){
    min=i;
    for(j=i; j<length; j++){
      if(a[min]>a[j])
        min=j;
    }
    if(min!=i){
      temp=a[min];
      a[min]=a[i];
      a[i]=temp;
    }
  }
}

void main(){
  int array[9] = {1,2,3,2,2,2,5,4,2}, i, k;
  printf("Give an array: \n");
  for(i=0; i<9; i++){
    printf("%d\t", array[i]);
  }
  sort(array, 8);
  printf("\nElements that occur more than half the length of the array are :");
  
  printf("%d\n", array[9/2]);
  system("pause");
}