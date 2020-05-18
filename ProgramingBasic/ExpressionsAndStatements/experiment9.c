#include<stdio.h>
#include<Windows.h>

void main(){
	float grade;

	printf("Please input your grade!\n");
	scanf("%f",&grade);

	if(grade >= 90)
		printf("You get an A.\n");
	else if(grade >= 80)
		printf("You get a B.\n");
	else if(grade >= 70)
		printf("You get a C.\n");
	else if(grade >= 60)
		printf("You get a D.\n");
	else
		printf("You get an E.\n");

  system("pause");
}