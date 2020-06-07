#include <stdio.h>
#include <stdlib.h>
#include<Windows.h>

#define MAX 32767

int merge(int *array, int p,int q,int r) { 
	//归并array[p...q] 与 array[q+1...r]
	int tempSum=0;
	int n1 = q-p+1;
	int n2 = r-q;
	int* left = NULL;
	int* right = NULL;
	int i, j, k, l;

	left = ( int *)malloc(sizeof(int) * (n1+1));
	right = ( int *)malloc(sizeof(int) * (n2+1));
	
	for(i=0; i<n1; i++)
		left[i] = array[p+i];

	for(j=0; j<n2; j++)
		right[j] = array[q+1+j];

	left[n1] = MAX; //哨兵，避免检查每一部分是否为空
	right[n2] = MAX;
	i=0;
	j=0;

	for(k=p; k<=r; k++) {
		if(left[i] <= right[j]) {
			array[k] = left[i];
			i++;
		}
    else {
			if(array[k]>right[j]){
				l=k+1;
				for(l; l<n1; l++)
					printf("(%d, %d)\t", array[l], right[j]);
			}
      printf("(%d, %d)\t", left[i], right[j]);
			array[k] = right[j];
			j++;
			tempSum += n1 - i;
		}
	}
	return tempSum;

}

int mergeSort(int *array, int start, int end ) {
	int sum=0;
	if(start < end) {
		int mid = (start + end) /2;
		sum += mergeSort(array, start, mid);
		sum += mergeSort(array, mid+1, end);
		sum += merge(array,start,mid,end);
	}
	return sum;
}

void main() {
	int array[4] = {7, 5, 6, 4};
	int inversePairNum;
	int i;
	printf("Give an array: ") ;
	for(i=0;i<4;++i)
    printf("%d ",array[i]);
	printf("\nThe reverse order is: ");
	inversePairNum = mergeSort(array,0,3);
	printf("\nInverse pair num = %d\n", inversePairNum);
	system("pause");
}