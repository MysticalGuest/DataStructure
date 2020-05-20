///////////////二叉树遍历应用///////////////

//设置三叉链表的Parent域
void SetParent(BiTree bt)
{
  if(bt!=NULL)
  {
        SetParent(bt->LChild);
	SetParent(bt->RChild);
    
        if(bt->LChild) bt->LChild->Parent=bt;
        if(bt->RChild) bt->RChild->Parent=bt;
  }
}

//二叉树基本操作：求结点双亲
BiTNode* Parent(BiTree bt,ElemType x)
{
   if(bt==NULL || bt->data==x)  return NULL; //空树或者根节点为x，返回NULL
   if(bt->L->data==x || bt->R->data==x)  return bt;  //找到x结点和其双亲

   p=parent(bt->L,x);  //在左子树上找
   if(p!=NULL)  return p;   //在左子树上找到，返回

   p=parent(bt->R,x);  //在左子树上没找到，在右子树上找
   if(p!=NULL)  return p;  //在右子树上找到，返回

   return NULL;  //在左右子树上都没找到，返回空
}


//顺序存储的二叉树，先序遍历
//i初值为1
int PreOrder(ElemType a[],int n,int i)
{
   if(i<=n && i>0)
   {
      visit(a[i]);
      PreOrder(a,n,2*i);
      PreOrder(a,n,2*i+1);
   } 
}


//先序遍历的非递归算法
void PreOrder(BiTree root) 
{  SeqStack S;
   BiTree p,pre==NULL;
   InitStack(&S);
   p=root;

   while(p!=NULL || !IsEmpty(&S))
   { 
      if (p!=NULL)  
      { Visit(p->data); 
        Push(&S,p);
        p=p->LChild;
      }
      else
      { 
         Pop(&S,&p);         
         p=p->RChild;        
      }
}

///////////////孩子兄弟链存储的树的应用//////////////

对一棵以孩子-兄弟链表表示的树统计其叶子的个数。
算法1：
int  leafNum(CSTree root)   //中序、后序都可
{ static num=0;
	if (root!=NULL)
	{
		If(root->FirstChild==NULL)  num++;
		leafNum (root -> FirstChild);    		
leafNum (root ->NextSibling);   
	   return num;
	}
}
算法2：
int leaf_b(CSTree root)
{
	int LeafCount;
	if(root==NULL)	
		LeafCount =0;
	else if((root->FirstChild==NULL)
		LeafCount =1+leaf_b(root->NextSibling);
	else 
	     LeafCount=leaf_b(root->FirstChild)+leaf_b(root->NextSibling);
	
	return LeafCount;
}


//对以孩子-兄弟链表表示的树，按(双亲,孩子)形式打印。
void PrintTree(CSree root)
{
	if(root!=NULL)
	{
                p=root->FirstChild;
                while(p!=NULL)
                {
 		      printf("(%c,%c)",root->data,p->data);
                      p=p->NextSibling;
                }
		PrintTree(root->FirstChild);
		PrintTree(root->NextSibling);		
	}
}


//对以孩子-兄弟链表表示的树，按树的层次输出所有结点。

void PrintTree(CSree root)
{
	Queue Q;
	InitQueue(&Q);
	EnterQueue(&Q,root);
	printf(“%c”,root->data);
	while(!IsEmpty(Q))
	{
		DeleteQueue(&Q,&p);
		pC=p->FirstChild;
                while(pC!=NULL)
                {  
                   printf(“%c”,pC->data);
		   EnterQueue(&Q,pC);
                  pC=pC->NextSibling;
               }  
	}
}


/////////////////层次遍历的应用//////////////////////

//按层次打印二叉树，每层一行
方法1：将节点地址和层次捆绑一起进队列
typedef char DataType;
typedef struct Node
{
	DataType data;
	struct Node *LChild;
	struct Node *RChild;
}BiTNode, *BiTree;

typedef struct{
  BiTNode *root;
  int layer;
}QueueElementType; 

typedef struct
{
	QueueElementType  element[MAXSIZE]; 
	int front; 
	int rear;  
}SeqQueue;

int  LayerOrder(BiTree bt)
{ 
	SeqQueue *Q;     
        QueueElementType tmp,x;
        int justlayer=1;
	Q=(SeqQueue *)malloc(sizeof(SeqQueue));
	
	InitQueue(Q);  
	if(bt == NULL) return ERROR; 

        tmp.root=bt; tmp.layer=1;
       	EnterQueue(Q, tmp);
	while(!IsEmpty(Q))
	{ 
                DeleteQueue(Q, &tmp);
                if(justlayer!=tmp.layer)
                 { printf("\n");justlayer=layaer;}
		printf("%c  ",p->data);
                
		if(tmp.root->LChild )   
                {  x.root=tmp.root->LChild; x.layer=tmp.layer+1; 
                   EnterQueue(Q, x);
                 }
                  
		if(tmp.root->RChild )   
                {  x.root=tmp.root->RChild; x.layer=tmp.layer+1; 
                   EnterQueue(Q, x);
                 }
               }
                 
	}
        free(Q);
	return OK;
}


方法2：增加一个求队列大小的函数
int  LayerOrder(BiTree bt)
{ 
	SeqQueue *Q;     
        BiTNode *p;
	Q=(SeqQueue *)malloc(sizeof(SeqQueue));
	
	InitQueue(Q);  
	if(bt == NULL) return ERROR; 

       	EnterQueue(Q, bt);
	while(!IsEmpty(Q))
	{ 
                size=QueueSize(Q);
                while(size>=1)
                {
		   DeleteQueue(Q, &p);
		   printf("%c  ",p->data);
                
		  if(p->LChild )   
                      EnterQueue(Q, p->LChild);
                  
		  if(p->RChild )
                      EnterQueue(Q, p->RChild);
                  size--;
               }
               printf("\n");
                 
	}
        free(Q);
	return OK;
}


//方法3：每层结尾进一个空结点
void  LayerOrder(BiTree bt)
{ 
	SeqQueue *Q;     
        BiTNode *p;
	Q=(SeqQueue *)malloc(sizeof(SeqQueue));
	
	InitQueue(Q);  
	if(bt == NULL) return ERROR; 

       	EnterQueue(Q, bt);
       	EnterQueue(Q, NULL); //空结点代表一个回车
	while(!IsEmpty(Q))
	{ 
              	DeleteQueue(Q, &p);
                //若出队元素是NULL，则表示一行结束，输出一个回车。然后再进一个空
                if(p==NULL){ EnterQueue(Q, NULL); printf("\n");}
		printf("%c  ",p->data);
                
		if(p->LChild )   
                      EnterQueue(Q, p->LChild);
                  
		if(p->RChild )
                      EnterQueue(Q, p->RChild);
                 
	}	
}

//计算二叉树最大宽度的算法。二叉树的最大宽度是指：二叉树所有层中结点个数的最大值。
int  WidthTree(BiTree bt)
{ 
	SeqQueue *Q;     
        BiTNode *p;
        int width=0;
	Q=(SeqQueue *)malloc(sizeof(SeqQueue));
	
	InitQueue(Q);  
	if(bt == NULL) return ERROR; 

       	EnterQueue(Q, bt);
	while(!IsEmpty(Q))
	{ 
                size=QueueSize(Q);
                if(size > width) width=size;

                while(size>=1)
                {
		   DeleteQueue(Q, &p);
		   printf("%c  ",p->data);
                
		  if(p->LChild )   
                      EnterQueue(Q, p->LChild);
                  
		  if(p->RChild )
                      EnterQueue(Q, p->RChild);
                  size--;
               }              
                 
	}
        free(Q);
	
        return width;
}


// 给定一棵二叉树，判断其是否为完全二叉树。
方法1： 遇到空结点，做标记。空不进队列

int JudgeCompleteBiT(BiTree bt)
{
   int tag=0;
   BiTNode *p=bt;
   Queue Q;  //队列中存放节点指针

   InitQueue(&Q);
   if(p==NULL) return 1;

   EnterQueue(&Q,p);
   while(!IsEmpty(Q))
   {
      DeleteQueue(&Q,&p);

      if(p->LChild!=NULL && tag==0)  EnterQueue(&Q,p->LChild);
      else if(p->LChild!=NULL)  return 0;
      else tag=1;

      if(p->RChild!=NULL && tag==0)  EnterQueue(&Q,p->RChild);
      else if(p->RChild!=NULL)  return 0;
      else tag=1;
   }  

   return 1;   
}

方法2： 遇到空结点，做标记，空进队列
int JudgeCompleteBiT(BiTree bt)
{
   int tag=0;
   BiTNode *p=bt;
   Queue Q;  //队列中存放节点指针

   InitQueue(&Q);
   if(p==NULL) return 1;

   EnterQueue(&Q,p);
   while(!IsEmpty(Q))
   {
      DeleteQueue(&Q,&p);
      if(p==NULL) { tag=1; continue;}
      if(p!=NULL && tag==1) return 0;  

      EnterQueue(&Q,p->LChild);
      EnterQueue(&Q,p->RChild);
      
   }  

   return 1;   
}
