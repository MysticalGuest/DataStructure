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

void move1(int n,char A,char B,char C){
  if(n==1){
    printf("%c-->%c\n",A,C);	
  }
  else{
    move1(n-1,A,C,B);
    move1(1,A,B,C);
    move1(n-1,B,A,C);
  }	
}

void main(){
	int n;
	printf("This is a Hanoi Problme.\nPlease input how many plates you want: ");
	scanf("%d",&n);
	// hanoi(n,'A','B','C');

	move1(n, 'A', 'B', 'C');

	system("pause");
}