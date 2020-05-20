#include<stdio.h>
#include<Windows.h>

int timer=0;

void BestTime(int x,int y){
	if(2*x<=y){
		timer++;
		BestTime(2*x,y);
	}
	else
		timer=timer+y-x;
}

void main(){
	int cOffarmer,cOfcow,temp;

	printf("Input the coordinates of the farmer and the cow in turn: ");

	scanf("%d%d",&cOffarmer,&cOfcow);
	if(cOffarmer>cOfcow){
		temp=cOffarmer;
		cOffarmer=cOfcow;
		cOfcow=temp;
	}

	printf("%d%d",cOffarmer,cOfcow);
	
	BestTime(cOffarmer,cOfcow);

	printf("The shortest time is %d\n",timer);

	system("pause");
}