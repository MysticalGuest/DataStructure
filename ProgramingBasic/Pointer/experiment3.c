#include<stdio.h>
#include<string.h>
#include<Windows.h>

void sort(char *p[], int len){
	char *temp;
	int i, j;
	for(i=0; i<len-1; i++)
		for(j=0; j<len-i-1; j++)
			if(strcmp(p[j], p[j+1])<0){
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
	for(i=0; i<len; i++)
		printf("%s\n", *(p+i));
}

void main(){
	char *place[6] = {"beijing", "shenzhen", "nanjing", "dalian", "shanghai", "qingdao"};
	sort(place, 6);

  system("pause");
}
