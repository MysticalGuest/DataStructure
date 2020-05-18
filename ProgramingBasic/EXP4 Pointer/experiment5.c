#include<stdio.h>
#include<Windows.h>

int mystrcmp(char *p, char *q){
	int i=0;
	while(*(p+i)!='\0' || *(q+i)!='\0'){
		if(*(p+i) != *(q+i))
			break;
		i++;
	}
	if(*(p+i) > *(q+i))
		return 1;
	else if(*(p+i) < *(q+i))
		return -1;
	else
		return 0;
}

void main(){
	char p[10] = "baijing", q[10]="beijing";
	printf("%d\n", mystrcmp(p, q));

  system("pause");
}