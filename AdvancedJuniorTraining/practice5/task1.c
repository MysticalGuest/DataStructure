/*
  中缀表达式就是我们正常使用的那种，例如：a+b*c
  后缀表达式就是abc*+；
  为什么要有中缀表达式和后缀表达式呢？
  因为中缀表达式便于人们的理解与计算，但是后缀表达式更方便计算机的运算（如二叉树、堆栈的方法计算），
  因此在读取一个中缀表达式后，我们得办法将他转化为后缀表达式。
*/

/*
  转化方式有三种
*/

/*
  第一种：基于堆栈的算法
  1.从左到右扫描每一个字符。如果扫描到的字符是操作数（如a、b等），就直接输出这些操作数。
  2.如果扫描到的字符是一个操作符，分三种情况：
    （1）如果堆栈是空的，直接将操作符存储到堆栈中（pushCStack it）
    （2）如果该操作符的优先级大于堆栈出口的操作符，就直接将操作符存储到堆栈中（pushCStack it）
    （3）如果该操作符的优先级低于堆栈出口的操作符，就将堆栈出口的操作符导出（popCStack it）, 
      直到该操作符的优先级大于堆栈顶端的操作符。将扫描到的操作符导入到堆栈中（pushCStack）。
  3.如果遇到的操作符是左括号"（”，就直接将该操作符输出到堆栈当中。该操作符只有在遇到右括号“)”的时候移除。这是一个特殊符号该特殊处理。
  4.如果扫描到的操作符是右括号“）”，将堆栈中的操作符导出（popCStack）到output中输出，直到遇见左括号“（”。将堆栈中的左括号移出堆栈（popCStack ）。继续扫描下一个字符。
  5.如果输入的中缀表达式已经扫描完了，但是堆栈中仍然存在操作符的时候，我们应该讲堆栈中的操作符导出并输入到output 当中。
*/
#include<stdio.h>
#include<ctype.h>
#include<Windows.h>

#define StackSize 50
#define INFINITY 32768

// 定义运算符栈
typedef struct{
	char elem[StackSize];
	int top;
}SeqCStack;

void InitCStack(SeqCStack *S){
	S->top=-1;
}

void pushCStack(SeqCStack *S, char operator){
  if(S->top == StackSize - 1){   // 栈满
    return ;
  }
  else{
    S->top++;
    S->elem[S->top] = operator;
    return ;
  }
}

void popCStack(SeqCStack *S, char *e){
  if(S->top == -1){   // 栈空
    return ;
  }
  else{
    *e = S->elem[S->top];
    S->top--;
    return ;
  }
}

char getCStackTop(SeqCStack S){
  if(S.top == -1){   // 栈空
    return '#';
  }
  else{
    return S.elem[S.top];
  }
}

void traverse(SeqCStack S){
  int i=0;
  while(i <= S.top){
    printf("%c  ", S.elem[i++]);
  }
  printf("\n");
}

// 定义运算数栈
typedef struct{
	int data[StackSize];
	int top;
}SeqNStack;

void InitNStack(SeqNStack *S){
	S->top=-1;
}

void pushNStack(SeqNStack *S, int num){
  if(S->top == StackSize - 1){   // 栈满
    return ;
  }
  else{
    S->top++;
    S->data[S->top] = num;
    return ;
  }
}

void popNStack(SeqNStack *S, int *e){
  if(S->top == -1){   // 栈空
    return ;
  }
  else{
    *e = S->data[S->top];
    S->top--;
    return ;
  }
}

int getNStackTop(SeqNStack S){
  if(S.top == -1){   // 栈空
    return INFINITY;
  }
  else{
    return S.data[S.top];
  }
}

char compare(char operator, char top){
  if(top == '#')   // 空栈，操作符直接进栈
    return '>';
  else if(operator==')' && top=='(')
    return '=';
  else if(top=='(')
    return '>';
  else if(operator=='+')    // 如果操作符是'+', 无论栈顶元素是什么, '+'优先级都小
    return '<';
  else if(operator=='-')
    return '<';
  else if(operator=='*' && top=='+')
    return '>';
  else if(operator=='*' && top=='-')
    return '>';
  else if(operator=='*' && top=='*')
    return '<';
  else if(operator=='*' && top=='/')
    return '<';
  else if(operator=='*' && top=='(')
    return '<';
  else if(operator=='/' && top=='+')
    return '>';
  else if(operator=='/' && top=='-')
    return '>';
  else if(operator=='/' && top=='*')
    return '<';
  else if(operator=='/' && top=='(')
    return '<';
  else if(operator=='(')
    return '>';
  else if(operator==')')
    return '<';
}

int caculate(int left, int right, char c){
	int re = 0;
	switch (c){
	case '+':
		re = left + right;
		break;
	case '-':
		re = left - right;
		break;
	case '*':
		re = left * right;
		break;
	case '/':
		re = left / right;
		break;
	default:
		break;	
	}
	return re;
}

void main(){
  SeqCStack OS, SuffixExp;
  SeqNStack NS;
  /* 初始化运算符栈 */
	InitCStack(&OS);
  /* 初始化运算数栈 */
	InitNStack(&NS);
  /* 初始后缀表达式栈 */
	InitCStack(&SuffixExp);

  char exp[] = {'5', '+', '2', '*', '(', '1', '+', '6', ')', '-', '8', '/', '2', '\0'};

  char suffixstr[50], temp;
  int i = 0, tempNum;
  while (exp[i]!='\0'){
    if(isdigit(exp[i])){    // 如果是数字直接进后缀表达式栈
      pushCStack(&SuffixExp, exp[i]);
      printf("num------%c\n", exp[i]);
      i++;
    }
    else{
      printf("char------\n");
      printf("aaaaa   %c\n", compare(exp[i], getCStackTop(OS)));
      switch(compare(exp[i], getCStackTop(OS))){
        case '>': 
          pushCStack(&OS, exp[i]);
          printf("case1 > %c\n", exp[i]);
          i++;
          break;
        case '=': 
          popCStack(&OS, &temp);   // 脱括号
          printf("case2 = %c\n", temp);
          i++;
          break;
        case '<':
          while(compare(exp[i], getCStackTop(OS))=='<'){
            printf("case3 < %c\n", exp[i]);
            printf("case3 getCStackTop %c\n", getCStackTop(OS));
            popCStack(&OS, &temp);
            printf("case3 after getCStackTop %c\n", getCStackTop(OS));
            pushCStack(&SuffixExp, temp);
          }
          // if(exp[i]!=')'){i++;}
          break;
      }
    }
  }
  /* 最后把栈中剩余的运算符依次弹栈打印 */
  while(getCStackTop(OS)!='#'){
    popCStack(&OS, &temp);
    pushCStack(&SuffixExp, temp);
  }
  traverse(SuffixExp);
  for(i=SuffixExp.top; i>=0; i--){
    popCStack(&SuffixExp, &temp);
    suffixstr[i] = temp;
  }
  printf("String: %s\n", suffixstr);
  /*
    后缀表达式求值的算法是:
    遍历后缀表达式，
    如果遇到运算数，那么运算数入栈
    如果遇到运算符，那么弹出栈里面两个元素，先弹出的是右运算数，后弹出的是左运算数，计算运算结果，然后将结果入栈。
    最后遍历到后缀表达式末尾，当结果只有一个元素时，就是答案
  */
 char *p=suffixstr;
 while (*p != '\0'){
		if (isdigit(*p)){
			pushNStack(&NS, *p-'0');
		}
		else
		{
			popNStack(&NS, &tempNum);
			int rightNum = tempNum;
      printf("rightNum:::%d\n", rightNum);
			// free(temp);
			popNStack(&NS, &tempNum);
			int leftNum = tempNum;
			// free(temp);
            
			int result = caculate(leftNum, rightNum, *p);
      printf("aasas1111: %d\n", result);
			pushNStack(&NS, result);
		}
		p++;
	}
  printf("result: %d\n", getNStackTop(NS));

  system("pause");
}


/*
  第二种：括号法，这种真的很简单啊，好记又简单
  1：按照运算符的优先级对所有的运算单位加括号~
    式子变成拉：（（a+（b*c））+（（（d*e+f）*g））
  2：转换前缀与后缀表达式
    前缀：把运算符号移动到对应的括号前面
    则变成拉：+(+(a*(bc))*(+(*(de)+g))
    把括号去掉：++a*bc*+*de+g 前缀式子出现

    后缀：把运算符号移动到对应的括号后面
    则变成拉：((a(bc)*)+(((de)*f)+g)*)+
    把括号去掉：abc*+de*f+g *+后缀式子出现
*/

/*
  第三种：二叉树
  表达式生成树的特点为:
    a. 叶子节点都是操作数；
    b. 非叶子节点都是运算符；
    c. 树根的运算符优先级低；
*/

