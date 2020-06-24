#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>

void print(char *number, int n){
  int i = 0;
  for(i; i<n; i++){
    if (number[i] != '0')
      break;
  }
  if(i == n)
    return;
  for(i; i<n; i++)
    printf("%c", number[i]);
  printf(" ");
}

void printRecursively(char *number, int n, int index){
  int i;
	if(index == n){
		print(number, n);
		return;
	}
	for(i = 0; i<10; i++){
		number[index] = i + '0';
		// printf("NUMBER: %s\n", number);
		printRecursively(number, n, index + 1);
	}
}

void printToMaxOfNDigits(int n){
	if (n <= 0)
		return;
	char *number = (char *)malloc((n+1)*sizeof(char));	
  memset(number, '0', (n+1)*sizeof(char));    // 在一段内存块中填充某个给定的值,初始化为0   
	number[n] = '\0';
	printRecursively(number, n, 0);
  
  free(number);
}

void main(){
	int n;
  // 输入数字n,按顺序打印输出从1到最大的n位十进制数
  printf("Enter the number n and print out the decimal digits from 1 to the largest n in order: ");
	scanf("%d", &n);
	printToMaxOfNDigits(n);

  printf("\n");
	system("pause");
}