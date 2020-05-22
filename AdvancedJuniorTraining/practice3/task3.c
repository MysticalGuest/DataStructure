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
  int array[8] = {4, 5, 1, 6, 2, 7, 3, 8}, i, k;
  printf("Give an array: \n");
  for(i=0; i<8; i++){
    printf("%d\t", array[i]);
  }
  sort(array, 8);
  printf("\nEnter the value k and output the smallest k number among them, k = ");
  scanf("%d", &k);
  printf("The smallest %d number in the array is: \n", k);
  for(i=0; i<k; i++){
    printf("%d\t", array[i]);
  }
  printf("\n");
  system("pause");
}