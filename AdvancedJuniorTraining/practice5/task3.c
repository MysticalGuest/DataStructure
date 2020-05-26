#include<stdio.h>
#include<Windows.h>

int Jump(int i, int n) {
    //表示当前台阶数大于总台阶数，很显然这种情况不符合，走不通，记为 0
    if (i > n) {
        return 0;
    }
    //表示当前台阶数正好等于总的台阶数，那么这种情况符合，记为 1
    if (i == n) {
        return 1;
    }
    return Jump(i + 1, n) + Jump(i + 2, n);
}

/*
  Q：一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
  A：f(n) = f(n-1)+f(n-2)+…+f(1)
  f(n-1) = f(n-2)+ f(n-3)…+f(1)
  两式相减，得到f(n) = 2*f(n-1)
*/

int JumpN(int num){
  if (num == 1){
    return 1;
  }
  else{
    return 2*JumpN(num-1);
  }
}

void main(){
  int n;
  printf("Please enter the number of steps: ");
  scanf("%d", &n);
  printf("When a frog can jump 1 step at a time, he can also jump to 2 steps. There are %d ways to jump. \n", Jump(0, n));
  printf("When a frog can jump up to 1 step at a time, he can jump up to 2 steps, or he can jump up to 3 steps. . . . and can also jump to level n. There are %d ways to jump. \n", JumpN(n));
  system("pause");
}

