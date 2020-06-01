#include<stdio.h>
#include<Windows.h>

int min_num(int n1,int n2,int n3){
    int min=(n1<n2)?n1:n2;
    min=(min<n3)?min:n3;
    return min;
}

void solution(long int array[]){
	int i;
	int t2=0;//记录M2的下标
  int t3=0;
  int t5=0;

	for(i=1; i<1500; i++){
		while(array[t2]*2<=array[i-1])//查找到新的M2，即乘以2后第一个大于M的数
				t2++;
		while(array[t3]*3<=array[i-1])
				t3++;
		while(array[t5]*5<=array[i-1])
				t5++;
		int min=min_num(array[t2]*2, array[t3]*3, array[t5]*5);
		array[i]=min;
	}
}

void main(){
	long int uglynums[1500];
	uglynums[0]=1;
	solution(uglynums);
	printf("Find the 1500th ugly number from small to large is %d.\n", uglynums[1499]);
  system("pause");
}