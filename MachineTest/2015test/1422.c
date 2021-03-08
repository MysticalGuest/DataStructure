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
        case 'a': return value1&value2; // '��'����
        case 'o': return value1|value2; // '��'����
        case 'i': // '�̺�'����
            if(value1==1&&value2==0)
                return 0;
            else
                return 1;
        case 'e': return value1==value2; // '��ֵ'����
        default: return 0;
    }
}

void evaluate_update(LinkList *L, Value *va, int n){
    LinkList r=(*L)->next;
    Node *first=NULL, *second=NULL, *third=NULL;
    int first_index=0, second_index=1, third_index=2; // 3��Ԫ�طֱ��Ӧ����ֵ�±�
    while(third->data>='0'&&third->data<='9'){ // �����3���������ֲ�����������Ͳ�������
        first=first->next;
        first_index++;
        second=second->next;
        second_index++;
        third=third->next;
        third_index++;
    }
    if(third->data<'0'||third->data>'9'){
        /// ������ֵ��
        va->data[0]=calculate(va->data[0], va->data[1], third->data);
        for(int i=3, k=1; i<n; i++, k++){
            va->data[k]=va->data[i];
        }
        /// ��������ǰ3���ַ������ֵ����first�е����ֱ��棬ȥ�������м�����Ԫ��
        r->next=first;
        first->next=third->next;
    }
}

int evaluate(LinkList L, Value va, int n){
    LinkList r=L->next;
    Node *first=NULL, *second=NULL, *third=NULL, *head; // 3��ֵ��2��ֵ����һ������,
    head = (Node*)malloc(sizeof(Node)); // ����ͷ���붨��
    head->next=NULL;
    if(r->next==NULL&&n==1){ // ���⹫ʽֻ��һ����Ԫ
        //printf("���⹫ʽֻ��һ����Ԫ\n");
        return va.data[0];
    }
    else if(r->next->next==NULL&&r->next->data=='n'&&n==1){ // ���⹫ʽ��������Ԫ�������ǡ����㣬n��ʾ��
        //printf("���⹫ʽ����Ԫ\n");
        return !va.data[0];
    }
    else if(n==2){ // ���⹫ʽ�ַ�����3���ַ�����2����Ԫ1�������
        first=r;
        second=first->next;
        third=second->next;
        //printf("���⹫ʽ3����Ԫ\n");
        //printf("\n%c %c %c\n", first->data, second->data, third->data);
        if(third->data<'0'||third->data>'9'){ // ��3���ַ��������������������ֵ
            /*
            switch(third->data){
                case 'a': return va.data[0]&va.data[1]; // '��'����
                case 'o': return va.data[0]&va.data[1]; // '��'����
                case 'i': // '�̺�'����
                    if(va.data[0]==1&&va.data[1]==0)
                        return 0;
                    else
                        return 1;
                case 'e': return va.data[0]==va.data[1]; // '��ֵ'����
                default: return 0;
            }
            */
            return calculate(va.data[0], va.data[1], third->data);
        }
        else{
            return 0;
        }
    }
    else if(n>2){ // �ڱ�Ԫ������3�������
        printf("wode  ");
        first=r;
        second=first->next;
        third=second->next;
        printf("   %c %c %c   ", first->data, second->data, third->data);
        if(third->data<'0'||third->data>'9'){ // ���ǰ3����2����Ԫ1�������������������ֵ
            printf("UUUUU  ");
            /// ������ֵ��
            Value temp;
            temp.data[0]=calculate(va.data[0], va.data[1], third->data);
            for(int i=2, k=1; i<n; i++, k++){
                temp.data[k]=va.data[i];
            }
            printf("QQQQQ  ");
            /// ��������ǰ3���ַ������ֵ����first�е����ֱ��棬ȥ�������м�����Ԫ��
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
    printf("������һ��������n(nС�ڵ���10)��\n");
    scanf("%d", &n);
    fflush(stdin); // �Ե��س�
    printf("������һ���������沨�����ʽ���ַ�����ʾһ�����⹫ʽ��\n");
    gets(proposition);
    InitLinkList(&exp, proposition);
    h=exp->next;
    while(h!=NULL){
        printf("%c\n", h->data);
        h=h->next;
    }
    /// ��ӡ���
    /*
    int temp, value, bit;
    for(int i=0; i<pow(2, n); i++){
        temp=n;
        bit=sizeof(i)-1; // ��������������������32λ�ģ�����temp=31
        printf("temp::%d\n", temp);
        printf("bit::%d\n", bit);
        while(temp>0){

            i>>temp, temp�ƶ����ǰ���������Ķ�������ʽ�����һλ��������1���а�λ������
            ����temp=31,���ǰ���������Ķ�������ʽ����31λ��
            ֻʣ������������Ķ����ƿ�ͷ��һ�����֣�Ȼ����1���а�λ�����㡣����Ϊ1������Ϊ0
            �����	����	    ʾ��	    ���
            <<	    ������λ	x<<y	x ��ÿ��λ�����ƶ�y��λ
            >>	    ������λ	x>>y	x ��ÿ��λ�����ƶ�y��λ

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
    /// ���ʽ�ж�
    printf("\n%s\n", proposition);
    return 0;
}
