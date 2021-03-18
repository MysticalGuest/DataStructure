#include <stdio.h>
#include <stdlib.h>
#include<Windows.h>

typedef union {double i; int k[5]; char e;} any; 

struct data {int cat; any cow; double dog;} max;

int main()
{
  /*
  假设为32位机器，any是一个联合型变量，联合型变量公用空间，
  里面最大的变量类型是int[5]，所以占用20个字节，而由于union中double占了8个字节，
  为了实现8字节对齐，所以union所占空间为24。
  */
  printf("sizeof(double): %d\n", sizeof(double)); // 8
  printf("sizeof(int): %d\n", sizeof(int)); //4
  printf("sizeof(char): %d\n", sizeof(char)); //1
  printf("sizeof(any): %d\n", sizeof(any)); //24
  /*
  而data是一个结构体变量，每个变量分开占用空间，依次为sizeof(int) + sizeof(DATE)+sizeof(double)=4+24+8=36，
  而double为8字节，为了8字节对齐，占用空间为40。
  所以打印结果是 24 + 40 = 64 个字节。
  */
  printf("sizeof(struct data): %d\n", sizeof(struct data)); //40
  printf("sizeof(max): %d\n", sizeof(max)); //40
  // 所以“对齐”可不可以理解为一定要是字节的倍数
  printf("%d\n", sizeof(struct data)+sizeof(any));
  system("pause");
  return 0;
}