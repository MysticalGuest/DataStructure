#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MaxSize 100

/*
主要思路：
(1)6个数字总共的排列组合状态数为6!=720种，这些状态可以构成一个有向图，
    故可采用图的遍历算法来求解此问题；
(2)本程序采用的是有向图的广度优先遍历算法，关键点在于对状态访问的记录以及对新状态的判定；

注意：
用于广度优先遍历的状态访问记录数组visited[]此处被定义为了全局变量；
因为用于标示访问是否的状态标志是用一个六位数表示的，该六位数的最大值为654321，
故visited[]数组至少需要空间为654321*4=2617284B；
而C语言的占空间最大只有2MB左右，所以不能在函数体内部定义该数组。
*/

/*
定义一个全局访问数组，用于记录每个状态的访问情况
思路是每个布局都只对应一个数字，通过转化为数字检查有没有重复
*/
int visited[700000] = { 0 };

typedef struct{
  int change_num;
  int elem[6];
}Data;

// 定义队列
typedef struct{
  Data elem[MaxSize];  // 一个指针，它指向一个有10个int元素的数组
  int front, rear;
}Queue;

int enter(Queue *q, Data d){ // 入队
    if((q->rear+1)%MaxSize!=q->front){ // 队未满
        q->rear=(q->rear+1)%MaxSize;
        q->elem[q->rear]=d;
        return 1;
    }
    else
        return 0;
}

void leave(Queue *q, Data *d){ // 出队
    if(q->rear!=q->front){ // 队未空
        q->front=(q->front+1)%MaxSize;
        *d=q->elem[q->front];
    }
}

int isEmpty(Queue qu){
    if(qu.rear==qu.front)
        return 1;
    else
        return 0;
}
/*
void alpha_transform(int * a){ // alpha变换
    int temp=a[0];
    a[0]=a[3];
    a[3]=a[4];
    a[4]=a[1];
    a[1]=temp;
}*/
void alpha_transform(Data *d){ // alpha变换
    int temp=d->elem[0];
    d->elem[0]=d->elem[3];
    d->elem[3]=d->elem[4];
    d->elem[4]=d->elem[1];
    d->elem[1]=temp;
}
/*
void beta_transform(int * a){ // beta变换
    int temp=a[1];
    a[1]=a[4];
    a[4]=a[5];
    a[5]=a[2];
    a[2]=temp;
}*/
void beta_transform(Data *d){ // beta变换
    int temp=d->elem[1];
    d->elem[1]=d->elem[4];
    d->elem[4]=d->elem[5];
    d->elem[5]=d->elem[2];
    d->elem[2]=temp;
}

int check(Data d){
    if(d.elem[0]==1&&d.elem[1]==2&&d.elem[2]==3&&d.elem[3]==4&&d.elem[4]==5&&d.elem[5]==6)
        return 1; // 目标布局
    else
        return 0;
}

int check_state(Data d){ // 检查当前布局的状态
    int num=0;
    for(int i = 5; i >= 0; i--){
        num += d.elem[i] * pow(10, i);
    }
    if(visited[num]==0) // 未出现过
        return 0;
    else
        return 1;
}

void state_transform(Data d){
    int num=0;
    for(int i = 5; i >= 0; i--){
        num += d.elem[i] * pow(10, i);
    }
    visited[num]=1;
}

int judge(Data d){
    Queue qu;
    Data da1, da2; // 两个存放相同布局，其中一个进行alpha变换，另一个进行beta变换
    qu.front=-1;qu.rear=-1; // 初始化
    enter(&qu, d);
    while(!isEmpty(qu)){
        leave(&qu, &da1);
        state_transform(da1);
        da2=da1;
        if(check(da1))
            return da1.change_num;
        alpha_transform(&da1);
        if(check_state(da1)==0){
            da1.change_num++;
            enter(&qu, da1);
        }
        beta_transform(&da2);
        if(check_state(da2)==0){
            da2.change_num++;
            enter(&qu, da2);
        }

    }
    return -1;
}

// 六数码问题
int six_digits()
{
    int n;
    Data digits;
    digits.change_num=0;
    int result[MaxSize]; // 用数组存放每个测试用例的结果
    printf("请输入测试用例的个数n：\n");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<6; j++){
            scanf("%d", &digits.elem[j]);
        }
        result[i]=judge(digits);
        memset(visited, 0, sizeof(visited)); //没判断完一个布局后，将visited元素全置为0
    }
    for(int i=0; i<n; i++){
        printf("%d\n", result[i]);
    }
    return 0;
}
