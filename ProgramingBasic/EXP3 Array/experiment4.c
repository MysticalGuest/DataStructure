#include<stdio.h>
#include<string.h>
#include<Windows.h>

void main(){
	int i, j, min;
	char name[5][20], temp[20];
	printf("Please enter the English names of 5 countries: \n");
	for(i=0; i<5; i++)
		gets(name[i]);
	// 选择排序法
	for(i=0; i<5; i++){
		min = i;
		for(j=i+1; j<5; j++)
			if(strcmp(name[j], name[min])<0)
				min = j;
		if(min!=i){
			strcpy(temp, name[i]);
			strcpy(name[i], name[min]);
			strcpy(name[min], temp);
		}
		
	}
  printf("After sorting: \n");
	for(i=0; i<5; i++)
		puts(name[i]);

  system("pause");
}