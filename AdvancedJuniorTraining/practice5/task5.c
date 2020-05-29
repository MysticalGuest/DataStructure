#include<stdio.h>
#include<Windows.h>

#define StackSize 50

// 定义汉诺塔数据
typedef struct{
	char A;
  char B;
  char C;
  int n;
}HanoiData;

// 定义栈
typedef struct{
	HanoiData elem[StackSize];
	int top;
}SeqStack;

void InitStack(SeqStack *S){
	S->top=-1;
}

void push(SeqStack *S, HanoiData hd){
  if(S->top == StackSize - 1){   // 栈满
    return ;
  }
  else{
    S->top++;
    S->elem[S->top] = hd;
    return ;
  }
}

void pop(SeqStack *S, HanoiData *e){
  if(S->top == -1){   // 栈空
    return ;
  }
  else{
    *e = S->elem[S->top];
    S->top--;
    return ;
  }
}

// HanoiData getTop(SeqStack S){
//   if(S.top == -1){   // 栈空
//     return ;
//   }
//   else{
//     return S.elem[S.top];
//   }
// }

void move1(int n,char A,char B,char C){
  if(n==1){
    printf("%c-->%c\n",A,C);	
  }
  else{
    move1(n-1,A,C,B);
    move1(1,A,B,C);
    move1(n-1,B,A,C);
  }	
}

void hanoi(int n){
	SeqStack S;
	InitStack(&S);
  HanoiData h = {'A', 'B', 'C', n};
	push(&S,h);//初始栈 
	// hanoi_data x;//用来保存出栈的n,A,B,C 

	while(S.top!=-1){
		pop(&S, &h);//出栈并用x带回 
		if(h.n==1){
			printf("%c-->%c\n",h.A,h.C);//打印出移动方案  
		}
		else{
      HanoiData h1 = {h.B, h.A, h.C, h.n-1};
			push(&S,h1);
      HanoiData h2 = {h.A, h.B, h.C, 1};
			push(&S,h2);
      HanoiData h3 = {h.A, h.C, h.B, h.n-1};
			push(&S,h3);
		}
	}
}

void main(){
  int n;
  printf("Please enter the number of plates: ");
  scanf("%d", &n);
  printf("The steps required to move all plates to Tower C are: \n");
  // move1(n, 'A', 'B', 'C');
  hanoi(n);
  system("pause");
}
