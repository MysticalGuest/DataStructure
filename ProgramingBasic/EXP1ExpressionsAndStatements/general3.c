#include<stdio.h>
#include<stdlib.h>

/// 位运算
void main(){
  // 位取反的操作符为“~”，0变成1，1变成0
  // unsigned是将数字类型无符号化，例如 int型的范围：-2^31 ~ 2^31 - 1，而unsigned int的范围：0 ~ 2^32。
	unsigned char ch = 15; //0000 1111
	unsigned char ch1 = ~ch; //1111 0000
	unsigned char ch2 = ~ch1;//0000 1111

  int in = 15; // 0000 1111
  int in1 = ~in; //=
  int in2 = ~in1; // 0000 1111

  unsigned int uin = 15; // 0000 1111
  unsigned int uin1 = ~uin; //
  unsigned int uin2 = ~uin1; // 0000 1111

	printf("%d, %d, %d\n", ch, ch1, ch2); // 15, 240, 15
  printf("%d, %d, %d\n", in, in1, in2); // 15, -16, 15
  printf("%d, %d, %d\n", uin, uin1, uin2); // 15, -16, 15

  /*
  取反操作，
  不管是 8 位 16位 清除最后一位（末尾清零）

    & ~1  通用
  */
	unsigned short sh = 16385; //0100 0000 0000 0001
	ch = ch & ~1;
	sh = sh & ~1;
	printf("%d, %d\n", ch, sh); // 14, 16384
	unsigned char cha1 = 1; // 0000 0001 --> 1111 1110
	unsigned char cha2 = ~(~cha1);
	printf("%d, %d\n", ~cha1, cha2); // -2

	system("pause");
}
