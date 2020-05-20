#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define StackSize 50

typedef struct
{
	char elem[StackSize];
	int top;
}CSeqStack;

typedef struct
{
	int num[StackSize];
	int top;
}NSeqStack;

void InitCStack(CSeqStack *S)
{
	S->top=-1;
}

void InitNStack(NSeqStack *S)
{
	S->top=-1;
}

void PushC(CSeqStack *S,char e){
	if(S->top==StackSize-1)
		printf("The expression that you inputed is too long!Please reboot the procedure!");
	else{
		S->top++;
		S->elem[S->top]=e;	
	}
}

void PushN(NSeqStack *S,int n){
	if(S->top==StackSize-1)
		printf("The expression that you inputed is too long!Please reboot the procedure!");
	else{
		S->top++;
		S->num[S->top]=n;
	}
}

char GetTopC(CSeqStack *S){
	return S->elem[S->top];
}

int GetTopN(NSeqStack *S){
	return S->num[S->top];
}

void PopC(CSeqStack *S){
	if(S->top==-1)
		return;
	else
		S->top--;
}

void PopN(NSeqStack *S){
	if(S->top==-1)
		return;
	else
		S->top--;
}

char Compare(char m,char n){
	switch(m){
	case'+':switch(n){
			case'+':return '=';
			case'-':return '=';
			case'*':return '<';
			case'/':return '<';
			case'#':return '>';
			case'(':return '>';
			}
	case'-':switch(n){
			case'+':return '=';
			case'-':return '=';
			case'*':return '<';
			case'/':return '<';
			case'#':return '>';
			case'(':return '>';
			}
	case'*':switch(n){
			case'+':return '>';
			case'-':return '>';
			case'*':return '=';
			case'/':return '=';
			case'#':return '>';
			case'(':return '>';
			}
	case'/':switch(n){
			case'+':return '>';
			case'-':return '>';
			case'*':return '=';
			case'/':return '=';
			case'#':return '>';
			case'(':return '>';
			}
	case'(':switch(n){
			case'+':return '>';
			case'-':return '>';
			case'*':return '>';
			case'/':return '>';
			case'#':return '>';
			case'(':return '>';
			}
	default:return '<';
	}
}
void ExpEvaluation(NSeqStack *NS,CSeqStack *CS){
	int n,num;
	char ch;
	PushC(CS,'#');
	printf("Please input an expression that you want to calculate(Ending with #):\n");
	ch=getchar();
	while(ch!='#'||GetTopC(CS)!='#'){
		if(ch>='0'&&ch<='9'){
			n=ch-'0';
			ch=getchar();
			while(ch>='0'&&ch<='9'){
				n=n*10+ch-'0';
				ch=getchar();
			}
			PushN(NS,n);	
		}
		else{
			switch(Compare(ch,GetTopC(CS))){
				case'>':PushC(CS,ch);
						ch=getchar();
						break;
				case'=':
				case'<':
				num=GetTopN(NS);
				PopN(NS);
				switch(GetTopC(CS)){
					case'+':num=GetTopN(NS)+num;break;
					case'-':num=GetTopN(NS)-num;break;
					case'*':num=GetTopN(NS)*num;break;
					case'/':num=GetTopN(NS)/num;break;
				}
				PopC(CS);
				PopN(NS);
				PushN(NS,num);
				if(ch==')'){
					PopC(CS);
					ch=getchar();
				}
			}
		}
	}
	printf("The result of your expression is %d.\n",GetTopN(NS));
/*	int i=0,j,k,n,num=0,s;
	char op,exp[100];
	PushC(CS,'#');
	printf("Please input the expression that you want to calculate:(Ending with #)\n");
	gets(exp);
	s=strlen(exp)-1;
	while(i<s){
		if(exp[i]>='0'&&exp[i]<='9'){
			j=i;
			while(exp[j+1]>='0'&&exp[j+1]<='9')
				j++;
			k=j-i;
			for(i;i<=j;i++){
				n=exp[i]-'0';
 				num+=n*pow(10,k);
				k--;
			}
			if(CS->top<2||Compare(exp[i],GetTopC(CS)))
				PushN(NS,num);
			else{
				switch(GetTopC(CS)){
					case'+':num=GetTopN(NS)+num;break;
					case'-':num=GetTopN(NS)-num;break;
					case'*':num=GetTopN(NS)*num;break;
					case'/':num=GetTopN(NS)/num;break;
				}
				PopN(NS);
				PushN(NS,num);
				if(exp[i+1]==')'){
					i++;
					PopC(CS);
					PopC(CS);
					if(GetTopC(CS)!='#'){
						num=GetTopN(NS);
						PopN(NS);
						switch(GetTopC(CS)){
							case'+':num=GetTopN(NS)+num;break;
							case'-':num=GetTopN(NS)-num;break;
							case'*':num=GetTopN(NS)*num;break;
							case'/':num=GetTopN(NS)/num;break;
						}
						PopC(CS);
						PopN(NS);
						PushN(NS,num);
					}
				}
				else
					PopC(CS);
				i++;
			}
		}
		else{
			PushC(CS,exp[i]);
			i++;
		}
		num=0;
	}
	printf("The result of your expression is %d.\n",GetTopN(NS));*/
}

void main(){
	CSeqStack OPTR;
	NSeqStack OVS;
	InitCStack(&OPTR);
	InitNStack(&OVS);
	ExpEvaluation(&OVS,&OPTR);
}