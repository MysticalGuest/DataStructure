#include<stdio.h>
#include<Windows.h>

/*
求1000以内的完全数（完全数指一个整数的值等于出它本身的所有因数和，比如6＝1+2+3）
*/

void main(){
  int a=1,b,c,d,i;
  for(d=0;a<1000;a++){
    for(i=1;i<a;i++){
      c=a%i;
      if(c==0)
      d=d+i;
    }
    if(a==d){
      printf("%d its factors are ",d);
      for(i=1;i<a;i++){
        c=a%i;
        if(c==0)
          printf("%d,",i);
      }
      printf("\n");
    }
    i=1;
    d=0;
  }
  
  system("pause");
}