#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MaxSize 100

/*
��Ҫ˼·��
(1)6�������ܹ����������״̬��Ϊ6!=720�֣���Щ״̬���Թ���һ������ͼ��
    �ʿɲ���ͼ�ı����㷨���������⣻
(2)��������õ�������ͼ�Ĺ�����ȱ����㷨���ؼ������ڶ�״̬���ʵļ�¼�Լ�����״̬���ж���

ע�⣺
���ڹ�����ȱ�����״̬���ʼ�¼����visited[]�˴�������Ϊ��ȫ�ֱ�����
��Ϊ���ڱ�ʾ�����Ƿ��״̬��־����һ����λ����ʾ�ģ�����λ�������ֵΪ654321��
��visited[]����������Ҫ�ռ�Ϊ654321*4=2617284B��
��C���Ե�ռ�ռ����ֻ��2MB���ң����Բ����ں������ڲ���������顣
*/

/*
����һ��ȫ�ַ������飬���ڼ�¼ÿ��״̬�ķ������
˼·��ÿ�����ֶ�ֻ��Ӧһ�����֣�ͨ��ת��Ϊ���ּ����û���ظ�
*/
int visited[700000] = { 0 };

typedef struct{
  int change_num;
  int elem[6];
}Data;

// �������
typedef struct{
  Data elem[MaxSize];  // һ��ָ�룬��ָ��һ����10��intԪ�ص�����
  int front, rear;
}Queue;

int enter(Queue *q, Data d){ // ���
    if((q->rear+1)%MaxSize!=q->front){ // ��δ��
        q->rear=(q->rear+1)%MaxSize;
        q->elem[q->rear]=d;
        return 1;
    }
    else
        return 0;
}

void leave(Queue *q, Data *d){ // ����
    if(q->rear!=q->front){ // ��δ��
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
void alpha_transform(int * a){ // alpha�任
    int temp=a[0];
    a[0]=a[3];
    a[3]=a[4];
    a[4]=a[1];
    a[1]=temp;
}*/
void alpha_transform(Data *d){ // alpha�任
    int temp=d->elem[0];
    d->elem[0]=d->elem[3];
    d->elem[3]=d->elem[4];
    d->elem[4]=d->elem[1];
    d->elem[1]=temp;
}
/*
void beta_transform(int * a){ // beta�任
    int temp=a[1];
    a[1]=a[4];
    a[4]=a[5];
    a[5]=a[2];
    a[2]=temp;
}*/
void beta_transform(Data *d){ // beta�任
    int temp=d->elem[1];
    d->elem[1]=d->elem[4];
    d->elem[4]=d->elem[5];
    d->elem[5]=d->elem[2];
    d->elem[2]=temp;
}

int check(Data d){
    if(d.elem[0]==1&&d.elem[1]==2&&d.elem[2]==3&&d.elem[3]==4&&d.elem[4]==5&&d.elem[5]==6)
        return 1; // Ŀ�겼��
    else
        return 0;
}

int check_state(Data d){ // ��鵱ǰ���ֵ�״̬
    int num=0;
    for(int i = 5; i >= 0; i--){
        num += d.elem[i] * pow(10, i);
    }
    if(visited[num]==0) // δ���ֹ�
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
    Data da1, da2; // ���������ͬ���֣�����һ������alpha�任����һ������beta�任
    qu.front=-1;qu.rear=-1; // ��ʼ��
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

// ����������
int six_digits()
{
    int n;
    Data digits;
    digits.change_num=0;
    int result[MaxSize]; // ��������ÿ�����������Ľ��
    printf("��������������ĸ���n��\n");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<6; j++){
            scanf("%d", &digits.elem[j]);
        }
        result[i]=judge(digits);
        memset(visited, 0, sizeof(visited)); //û�ж���һ�����ֺ󣬽�visitedԪ��ȫ��Ϊ0
    }
    for(int i=0; i<n; i++){
        printf("%d\n", result[i]);
    }
    return 0;
}
