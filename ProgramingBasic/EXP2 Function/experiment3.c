#include<stdio.h>
#include<Windows.h>

long int plus(int a){
	long int sum;
	if(a>2){
		sum = plus(a-2) + plus(a-1);
		return sum;
	}
	else
		return 1;
}

void main(){
	int a=1, i, j=3, n, k;
	// 请输入你想输出的斐波那契数列的项数
	printf("Please enter the number of Fibonacci numbers you want to output n=");
	scanf("%d", &n);

	for(i=0; i<2; i++)
		printf("%d\n", a);
	for(k=2; k<n; k++){
		printf("%ld\n", plus(j));
		j++;
	}

	system("pause");
}