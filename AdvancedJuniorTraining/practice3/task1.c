#include<stdio.h>
#include<string.h>
#include<Windows.h>

void main(){
  printf("Give a string: \n");
  char str[100] = "We are happy.";    // 假设空间足够大
  int length=0, blank=0, i, j;
  while(str[length]!='\0'){
    printf("%c", str[length]);
    if(str[length]==' '){
      blank++;
    }
    length++;
  }
  length += 2 * blank;

  i=length-2*blank;
  j=length;

  while(i>=0 && j>i){
    if(str[i]==' '){
      str[j--]='0';
      str[j--]='2';
      str[j--]='%';
    }
    else{
      str[j--]=str[i];
    }
    i--;
  }
  printf("\nThe replaced string is: \n");
  i=0;
  while(str[i]!='\0'){
    printf("%c", str[i]);
    i++;
  }
  printf("\n");
  system("pause");
}