#include<stdio.h>
#include<Windows.h>

void move(char x,char y){
	printf("%c-->%c\n",x,y);
}
void hanoi(int n,char x,char y,char z){
	if(n==1)
		move(x,z);
	else{
	}
}
void main(){
	int n;
	char A,B,C;
	printf("This is a Hanoi Problme.Please input how many plates you want: ");
	scanf("%d",&n);
	hanoi(n,'A','B','C');

	system("pause");
}