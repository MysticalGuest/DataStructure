#include<stdio.h>
#include<math.h>
#include<Windows.h>

void main(){	
  char c;
	int i=0, j=0, m=0, n=0;
	printf("Please enter some characters: ");
	while(1){
    c=getchar();
		if((c>='a' && c<='z') || (c>='A' && c<='Z'))
			i++;
		else{
			if(c>='0' && c<='9')
				m++;
			else{
				if(c==' ')
					j++;
				else{
					if(c=='\n')
						break;
					else
						n++;
        }
      }
    }
  }
  // 英文字符的数量
  printf("The number of English characters entered is %d\n", i);
  // 空格的数量
  printf("The number of spaces entered is %d\n", j);
  // 数字字符的数量
  printf("The number of numeric characters entered is %d\n", m);
  // 其他字符的数量
  printf("The number of other characters entered is %d\n", n);

  system("pause");
}