#include<stdio.h>
#include<stdlib.h>

#define StackSize 50
//定义运算符栈
typedef struct
{
	char elem[StackSize];
	int top;
}CSeqStack;

void InitCStack(CSeqStack *S){
	S->top=-1;
}
//定义运算数栈
typedef struct
{
	int num[StackSize];
	int top;
}NSeqStack;

void InitNStack(NSeqStack *S){
	S->top=-1;
}
void main(){
	CSeqStack cs;
	InitCStack(&cs);
	NSeqStack ns;
	InitNStack(&ns);
}