#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MaxSize 10
#define SIZE 10

typedef struct Value {
    int data[MaxSize];
}Value;

typedef struct Node {
    char data;
	struct Node *next;
}Node, *LinkList;

void InitLinkList(LinkList *L, char str[]){
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next=NULL;
    Node *r=*L, *s;
    for(int i=0; str[i]!='\0'; i++){
        s=(Node*)malloc(sizeof(Node));
        s->data=str[i];
        r->next=s;
        s->next=NULL;
        r=s;
    }
}

int calculate(int value1, int value2, char op){
    switch(op){
        case 'a': return value1&value2; // '与'运算
        case 'o': return value1|value2; // '或'运算
        case 'i': // '蕴含'运算
            if(value1==1&&value2==0)
                return 0;
            else
                return 1;
        case 'e': return value1==value2; // '等值'运算
        default: return 0;
    }
}

void evaluate_update(LinkList *L, Value *va, int n){
    LinkList r=(*L)->next;
    Node *first=NULL, *second=NULL, *third=NULL;
    int first_index=0, second_index=1, third_index=2; // 3个元素分别对应的真值下标
    while(third->data>='0'&&third->data<='9'){ // 如果第3个还是数字不是运算符，就不能运算
        first=first->next;
        first_index++;
        second=second->next;
        second_index++;
        third=third->next;
        third_index++;
    }
    if(third->data<'0'||third->data>'9'){
        /// 更新真值表
        va->data[0]=calculate(va->data[0], va->data[1], third->data);
        for(int i=3, k=1; i<n; i++, k++){
            va->data[k]=va->data[i];
        }
        /// 更新链表，前3个字符求出真值，用first中的数字保存，去掉链表中间两个元素
        r->next=first;
        first->next=third->next;
    }
}

int evaluate(LinkList L, Value va, int n){
    LinkList r=L->next;
    Node *first=NULL, *second=NULL, *third=NULL, *head; // 3个值或2个值构成一个运算,
    head = (Node*)malloc(sizeof(Node)); // 链表头必须定义
    head->next=NULL;
    if(r->next==NULL&&n==1){ // 命题公式只有一个变元
        //printf("命题公式只有一个变元\n");
        return va.data[0];
    }
    else if(r->next->next==NULL&&r->next->data=='n'&&n==1){ // 命题公式有两个变元，即‘非’运算，n表示非
        //printf("命题公式个变元\n");
        return !va.data[0];
    }
    else if(n==2){ // 命题公式字符串有3个字符，即2个变元1个运算符
        first=r;
        second=first->next;
        third=second->next;
        //printf("命题公式3个变元\n");
        //printf("\n%c %c %c\n", first->data, second->data, third->data);
        if(third->data<'0'||third->data>'9'){ // 第3个字符是运算符，即可以求真值
            /*
            switch(third->data){
                case 'a': return va.data[0]&va.data[1]; // '与'运算
                case 'o': return va.data[0]&va.data[1]; // '或'运算
                case 'i': // '蕴含'运算
                    if(va.data[0]==1&&va.data[1]==0)
                        return 0;
                    else
                        return 1;
                case 'e': return va.data[0]==va.data[1]; // '等值'运算
                default: return 0;
            }
            */
            return calculate(va.data[0], va.data[1], third->data);
        }
        else{
            return 0;
        }
    }
    else if(n>2){ // 在变元数大于3的情况下
        printf("wode  ");
        first=r;
        second=first->next;
        third=second->next;
        printf("   %c %c %c   ", first->data, second->data, third->data);
        if(third->data<'0'||third->data>'9'){ // 如果前3个是2个变元1个运算符，即可以求真值
            printf("UUUUU  ");
            /// 更新真值表
            Value temp;
            temp.data[0]=calculate(va.data[0], va.data[1], third->data);
            for(int i=2, k=1; i<n; i++, k++){
                temp.data[k]=va.data[i];
            }
            printf("QQQQQ  ");
            /// 更新链表，前3个字符求出真值，用first中的数字保存，去掉链表中间两个元素
            head->next=first;
            printf("CCCCC  ");
            first->next=third->next;
            printf("HHHHH  ");
            return evaluate(head, temp, n-2);
        }
        else{
            head->next=r;
            evaluate_update(&head, &va, n);
            return evaluate(head, va, n-2);
        }
    }
    else
        return 0;
}

int truth_table()
{
    int n;
    LinkList exp=NULL;
    Node *h;
    char proposition[SIZE];
    Value va;
    printf("请输入一个正整数n(n小于等于10)：\n");
    scanf("%d", &n);
    fflush(stdin); // 吃掉回车
    printf("再输入一个类似于逆波兰表达式的字符串表示一个命题公式：\n");
    gets(proposition);
    InitLinkList(&exp, proposition);
    h=exp->next;
    while(h!=NULL){
        printf("%c\n", h->data);
        h=h->next;
    }
    /// 打印表格
    /*
    int temp, value, bit;
    for(int i=0; i<pow(2, n); i++){
        temp=n;
        bit=sizeof(i)-1; // 这个变量，如果编译器是32位的，这里temp=31
        printf("temp::%d\n", temp);
        printf("bit::%d\n", bit);
        while(temp>0){

            i>>temp, temp移动后，是把这个整数的二进制形式中最后一位，依次与1进行按位与运算
            假如temp=31,就是把这个整数的二进制形式右移31位，
            只剩下了这个整数的二进制开头第一个数字，然后与1进行按位与运算。真则为1，假则为0
            运算符	意义	    示例	    结果
            <<	    向左移位	x<<y	x 的每个位向左移动y个位
            >>	    向右移位	x>>y	x 的每个位向右移动y个位

            value=i>>bit&1;
            printf("%d ", value);
            bit--;
            temp--;
        }
        printf("%d\n", i);
    }
    */
    /*
    int temp, value, bit;
    for(int i=0; i<pow(2, n); i++){
        temp=i;
        while(temp!=0){
            value=temp/2;
            bit=temp-value*2;
            printf("%d ", bit);
            temp=temp/2;
        };
        printf("%d\n", i);
    }
    */
    int bit;
    for(int i=0; i<pow(2, n); i++){
        for(int j=n-1, k=0; j>=0; j--, k++){
            bit = (i&(1<<j)) != 0;
            //printf("bit::%d\n", bit);
            va.data[k]=bit;
            printf("%d ", bit);
        }
        printf("%d\n", evaluate(exp, va, n));
        //printf("\n");
        //printf("%d\n", i);
    }
    /// 表达式判断
    printf("\n%s\n", proposition);
    return 0;
}
