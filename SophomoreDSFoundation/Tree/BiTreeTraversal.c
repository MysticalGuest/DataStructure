#include <stdio.h>
#include <stdlib.h>

typedef struct treenode      //树的节点
{
    char data ;
    treenode * leftchild, * rightchild ;
}TreeNode;

typedef TreeNode * StackElemType ;   //定义栈包含的数据类型

typedef struct stacknode    //栈的节点
{
    StackElemType data ;
    stacknode * next ;
}StackNode;

typedef TreeNode * QueueElemType ;     //定义队列包含的数据类型

typedef struct queuenode     //定义队列节点
{
    QueueElemType  data ;
    struct queuenode * next ;
}QueueNode;

typedef struct queuehead    //定义队列的头节点
{
    QueueNode * front, * rear ;
}QueueHead;

//stack的有关声明
StackNode * InitStack(StackNode * S) ;
void StackPush(StackNode * S, StackElemType data) ;
void StackPop(StackNode * S, StackElemType & data) ;
int StackEmpty(StackNode * S) ;
int StackGetTop(StackNode * S, StackElemType & data) ;

//queue的有关声明
QueueHead * InitQueue(QueueHead * Q) ;
void QueuePush(QueueHead * Q, QueueElemType data) ;
void QueuePop(QueueHead * Q, QueueElemType & data) ;
int QueueEmpty(QueueHead * Q) ;

//TreeTraverse的有关声明
TreeNode * InitTree(TreeNode * T) ;
void PreTraverseTree1(TreeNode * T) ;
void PreTraverseTree2(TreeNode * T) ;
void InOrderTraverseTree1(TreeNode * T) ;
void InOrderTraverseTree2(TreeNode * T) ;
void LastTraverseTree1(TreeNode * T) ;
void LastTraverseTree2(TreeNode * T) ;
void LevelTraverseTree(TreeNode * T) ;

//栈的函数定义
StackNode * InitStack(StackNode * S)
{
    S = (StackNode *)malloc(sizeof(StackNode)) ;
    if(NULL == S)
    {
        printf("Not enough memory！\n") ;
        exit(0) ;
    }

    S->next = NULL ;
    return(S) ;
}

void StackPush(StackNode * S, StackElemType data)
{
    StackNode * q ;
    q = (StackNode *)malloc(sizeof(StackNode)) ;
    if(NULL == q)
    {
        printf("Not enough memory！\n") ;
        exit(0) ;
    }
    q->data = data ;
    q->next = S->next ;
    S->next = q ;
}

void StackPop(StackNode * S, StackElemType & data)
{
    StackNode * q ;
    if(NULL == S->next)
    {
        printf("Empty Stack！\n") ;
    }

    q = S->next ;
    data = q->data ;
    S->next = q->next ;
    free(q) ;
}

int StackEmpty(StackNode * S)
{
    if(NULL == S->next)
    {
        return(1) ;
    }

    return(0) ;
}

int StackGetTop(StackNode * S, StackElemType & data)
{
    if(NULL != S->next)
    {
        data = S->next->data ;
        return(1) ;
    }
    else
    {
        //data = NULL ;
        return(0) ;
    }
}


//队列函数的定义
QueueHead * InitQueue(QueueHead * Q)
{
    QueueNode * q ;
    Q = (QueueHead *)malloc(sizeof(QueueHead)) ;
    if(NULL == Q)
    {
        printf("Not enough memory！\n") ;
        exit(0) ;
    }
    q = (QueueNode *)malloc(sizeof(QueueNode)) ;
    if(NULL == q)
    {
        printf("Not enough memory！\n") ;
        exit(0) ;
    }

    q->next = NULL ;
    Q->front = q ;
    Q->rear = q ;

    return(Q) ;
}

void QueuePush(QueueHead * Q, QueueElemType data)
{
    QueueNode * q ;
    q = (QueueNode *)malloc(sizeof(QueueNode)) ;
    if(NULL == q)
    {
        printf("Not enough memory！\n") ;
        exit(0) ;
    }

    q->data = data ;
    q->next = Q->rear->next ;
    Q->rear->next = q ;
    Q->rear = q ;
}

void QueuePop(QueueHead * Q, QueueElemType & data)
{
    QueueNode * q ;
    if(Q->front == Q->rear)
    {
        printf("Null Queue！\n") ;
        return ;
    }

    q = Q->front->next ;
    data = q->data ;
    Q->front->next = q->next ;
    if(Q->rear == q)
        Q->rear = Q->front ;

    free(q) ;
}

int QueueEmpty(QueueHead * Q)
{
    if(Q->front == Q->rear)
        return(1) ;
    else
        return(0) ;
}


//树的各种遍历函数定义

/*建立一棵二叉树*/
TreeNode * InitTree(TreeNode * T)
{
    char data ;
    scanf("%c", &data) ;

    if('#' == data)
    {
        T = NULL ;
    }
    else
    {
        T = (TreeNode *)malloc(sizeof(TreeNode)) ;
        T->data = data ;
        T->leftchild = InitTree(T->leftchild) ;
        T->rightchild = InitTree(T->rightchild) ;
    }

    return(T) ;
}

/*二叉树递归先序遍历*/
void PreTraverseTree1(TreeNode * T)
{
    if(T)
    {
        printf("%c  ", T->data) ;
        PreTraverseTree1(T->leftchild) ;
        PreTraverseTree1(T->rightchild) ;
    }
}

/*二叉树的非递归先序遍历*/
void PreTraverseTree2(TreeNode * T)
{
    StackNode * S ;
    TreeNode * p ;
    S = NULL ;
    p = T ;
    S = InitStack(S) ;

    if(NULL == p)
    {
        printf("NULL！\n") ;
        return ;
    }

    while(p || !StackEmpty(S))
    {
        if(p)
        {
            StackPush(S, p) ;
            printf("%c  ", p->data) ;
            p = p->leftchild ;
        }
        else
        {
            StackPop(S, p) ;
            p = p->rightchild ;
        }
    }

    free(S) ;
}

/*二叉树递归中序遍历*/
void InOrderTraverseTree1(TreeNode * T)
{
    if(T)
    {
        InOrderTraverseTree1(T->leftchild) ;
        printf("%c  ", T->data) ;
        InOrderTraverseTree1(T->rightchild) ;
    }
}

/*二叉树的非递归中序遍历*/
void InOrderTraverseTree2(TreeNode * T)
{
    StackNode * S ;
    TreeNode * p ;
    S = NULL ;
    p = T ;
    S = InitStack(S) ;

    if(NULL == p)
    {
        printf("NULL！\n") ;
        return ;
    }

    while(p || !StackEmpty(S))
    {
        if(p)
        {
            StackPush(S, p) ;
            p = p->leftchild ;
        }
        else
        {
            StackPop(S, p) ;
            printf("%c  ", p->data) ;
            p = p->rightchild ;
        }
    }
    free(S) ;
}

/*二叉树递归后序遍历*/
void LastTraverseTree1(TreeNode * T)
{
    if(T)
    {
        LastTraverseTree1(T->leftchild) ;
        LastTraverseTree1(T->rightchild) ;
        printf("%c  ", T->data) ;
    }
}

/*二叉树非递归后序遍历*/
void LastTraverseTree2(TreeNode * T)
{
    StackNode * S ;
    TreeNode * cur, * pre ;
    S = NULL ;
    S = InitStack(S) ;
    if(NULL == T)
    {
        printf("NULL！\n") ;
        return ;
    }

    pre = NULL ;    cur = NULL ;
    StackPush(S,T) ;
    while(!StackEmpty(S))
    {
        cur = NULL ;
        StackGetTop(S,cur) ;
        if((cur->leftchild == NULL && cur->rightchild == NULL) || (pre != NULL && (pre == cur->leftchild ||pre == cur->rightchild)))
        {
            printf("%c  ", cur->data) ;
            pre = cur ;
            StackPop(S,cur) ;
        }
        else
        {
            if(cur->rightchild != NULL)
            {
                StackPush(S,cur->rightchild) ;
            }
            if(cur->leftchild != NULL)
            {
                StackPush(S,cur->leftchild) ;
            }
        }
    }
    free(S) ;
}

/*二叉树层次遍历*/
void LevelTraverseTree(TreeNode * T)
{
    QueueHead * Q ;
    TreeNode * p ;
    Q = NULL ;    p = T ;
    Q = InitQueue(Q) ;
    if(NULL == p)
    {
        printf("NULL！\n") ;
        return ;
    }

    QueuePush(Q,p) ;
    while(!QueueEmpty(Q))
    {
        p = NULL ;
        QueuePop(Q,p) ;

        if(NULL != p->leftchild)
            QueuePush(Q,p->leftchild) ;

        if(NULL != p->rightchild)
            QueuePush(Q,p->rightchild) ;

        printf("%c  ", p->data) ;
    }
}


//主函数的定义
void Tips()
{
	printf("********************************************************************************\n\n");
	printf("                              BiTree traversal!                             \n\n");
	printf("     Bitree is constructed according to PreOrder, '#' represents Null node! \n\n") ;
	printf("********************************************************************************\n\n");
   
    printf("Please input the BiTree：") ;
}

int main()
{
    TreeNode * T ;
    T = NULL ;

    Tips() ;

    T = InitTree(T) ;

    printf("Recursive preOrder traversal...\n") ;
    PreTraverseTree1(T) ;
    printf("\n\n") ;

    printf("Non-recursive preOrder traversal...\n") ;
    PreTraverseTree2(T) ;
    printf("\n\n") ;

    printf("Recursive InOrder traversal...\n") ;
    InOrderTraverseTree1(T) ;
    printf("\n\n") ;

    printf("Non-recursive InOrder traversal...\n") ;
    InOrderTraverseTree2(T) ;
    printf("\n\n") ;

    printf("Recursive PostOrder traversal...\n") ;
    LastTraverseTree1(T) ;
    printf("\n\n") ;

    printf("Non-recursive PostOrder traversal...\n") ;
    LastTraverseTree2(T) ;
    printf("\n\n") ;

    printf("Hierarchical traversal...\n") ;
    LevelTraverseTree(T) ;
    printf("\n\n") ;

    return 0 ;
}