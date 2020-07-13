#include<stdio.h>
#include<Windows.h>

#define  MAX_VERTEX_NUM 20//最大顶点个数
#define  VertexType int//顶点数据的类型
#define  InfoType int//图中弧或者边包含的信息的类型

typedef enum{DG=1,DN=2,UDG=3,UDN=4}GraphKind;       //枚举图的 4 种类型
typedef enum{false,true}bool;               //定义bool型常量

typedef struct ArcNode{
  int adjvex;//邻接点在数组中的位置下标
  struct ArcNode * nextarc;//指向下一个邻接点的指针
  int weight;  //权值
  InfoType * info;//信息域
}ArcNode;

typedef struct VNode{
  VertexType data;//顶点的数据域
  ArcNode * firstarc;//指向邻接点的指针
}VNode, AdjList[MAX_VERTEX_NUM];//存储各链表头结点的数组

typedef struct {
  AdjList vertices;//图中顶点的数组
  int vexnum,arcnum;//记录图中顶点数和边或弧数
  GraphKind kind;//记录图的种类
}ALGraph;

typedef struct Queue{                       //广度优先搜索的实现需要借助队列
    VertexType data;
    struct Queue * next;
}Queue;

/* 建立有向图图的邻接表结构 */
void CreateDGALGraph(ALGraph *G){
  int i, j, k;
  ArcNode *e;
  printf("Enter the number of vertices and edges: ");
  scanf("%d%d", &G->vexnum, &G->arcnum);  /* 输入顶点数和边数 */
  printf("Please enter all vertices: ");
  for(i=0; i<G->vexnum; i++){               /* 读入顶点信息，建立顶点表 */
    scanf("%d", &G->vertices[i].data);                  /* 输入顶点信息 */
    G->vertices[i].firstarc=NULL;                /* 将边表置为空表 */
  }
  for(k=0; k<G->arcnum; k++){                  /* 建立边表 */
    printf("Enter the vertex number on the edge (vi, vj): ");
    scanf("%d%d", &i, &j);                       /* 输入边(vi, vj)上的顶点序号 */
    e=(ArcNode *)malloc(sizeof(ArcNode));      /* 向内存申请空间 *//* 生成边表结点 */
    e->adjvex=j;                                 /* 邻接序号为j */
    /* 头插法 */
    e->nextarc=G->vertices[i].firstarc;             /* 将e指针指向当前顶点指向的结点 */
    G->vertices[i].firstarc=e;                   /* 将当前顶点的指针指向e */
  }
}

/* 建立无向图的邻接表结构 */
void CreateDNALGraph(ALGraph *G){
  int i, j, k;
  ArcNode *e;
  printf("Enter the number of vertices and edges: ");
  scanf("%d%d", &G->vexnum, &G->arcnum);  /* 输入顶点数和边数 */
  printf("Please enter all vertices: ");
  for(i=0; i<G->vexnum; i++){               /* 读入顶点信息，建立顶点表 */
    scanf("%d", &G->vertices[i].data);                  /* 输入顶点信息 */
    G->vertices[i].firstarc=NULL;                /* 将边表置为空表 */
  }
  for(k=0; k<G->arcnum; k++){                  /* 建立边表 */
    printf("Enter the vertex number on the edge (vi, vj): ");
    scanf("%d%d", &i, &j);                       /* 输入边(vi, vj)上的顶点序号 */
    e=(ArcNode *)malloc(sizeof(ArcNode));      /* 向内存申请空间 *//* 生成边表结点 */
    e->adjvex=j;                                 /* 邻接序号为j */
    /* 头插法 */
    e->nextarc=G->vertices[i].firstarc;             /* 将e指针指向当前顶点指向的结点 */
    G->vertices[i].firstarc=e;                   /* 将当前顶点的指针指向e */
    
    e=(ArcNode *)malloc(sizeof(ArcNode));      /* 向内存申请空间 *//* 生成边表结点 */
    e->adjvex=i;                                 /* 邻接序号为i */
    e->nextarc=G->vertices[j].firstarc;             /* 将e指针指向当前顶点指向的结点 */
    G->vertices[j].firstarc=e;                   /* 将当前顶点的指针指向e */
  }
}

/* 建立有向网的邻接表结构 */
void CreateUDGALGraph(ALGraph *G){
  int i, j, k, w;
  ArcNode *e;
  printf("Enter the number of vertices and edges: ");
  scanf("%d%d", &G->vexnum, &G->arcnum);  /* 输入顶点数和边数 */
  printf("Please enter all vertices: ");
  for(i=0; i<G->vexnum; i++){               /* 读入顶点信息，建立顶点表 */
    scanf("%d", &G->vertices[i].data);                  /* 输入顶点信息 */
    G->vertices[i].firstarc=NULL;                /* 将边表置为空表 */
  }
  for(k=0; k<G->arcnum; k++){                  /* 建立边表 */
    printf("Enter the arc head, arc tail and the weight of this edge: ");
    scanf("%d%d%d", &i, &j, &w);                       /* 输入边(vi, vj)上的顶点序号 */
    e=(ArcNode *)malloc(sizeof(ArcNode));      /* 向内存申请空间 *//* 生成边表结点 */
    e->adjvex=j;                                 /* 邻接序号为j */
    e->weight=w;
    /* 头插法 */
    e->nextarc=G->vertices[i].firstarc;             /* 将e指针指向当前顶点指向的结点 */
    G->vertices[i].firstarc=e;                   /* 将当前顶点的指针指向e */
  }
}

/* 建立无向网的邻接表结构 */
void CreateUDNALGraph(ALGraph *G){
  int i, j, k, w;
  ArcNode *e;
  printf("Enter the number of vertices and edges: ");
  scanf("%d%d", &G->vexnum, &G->arcnum);  /* 输入顶点数和边数 */
  printf("Please enter all vertices: ");
  for(i=0; i<G->vexnum; i++){               /* 读入顶点信息，建立顶点表 */
    scanf("%d", &G->vertices[i].data);                  /* 输入顶点信息 */
    G->vertices[i].firstarc=NULL;                /* 将边表置为空表 */
  }
  for(k=0; k<G->arcnum; k++){                  /* 建立边表 */
    printf("Enter the arc head, arc tail and the weight of this edge: ");
    scanf("%d%d%d", &i, &j, &w);                       /* 输入边(vi, vj)上的顶点序号 */
    e=(ArcNode *)malloc(sizeof(ArcNode));      /* 向内存申请空间 *//* 生成边表结点 */
    e->adjvex=j;                                 /* 邻接序号为j */
    e->weight=w;
    /* 头插法 */
    e->nextarc=G->vertices[i].firstarc;             /* 将e指针指向当前顶点指向的结点 */
    G->vertices[i].firstarc=e;                   /* 将当前顶点的指针指向e */
    
    e=(ArcNode *)malloc(sizeof(ArcNode));      /* 向内存申请空间 *//* 生成边表结点 */
    e->adjvex=i;                                 /* 邻接序号为i */
    e->weight=w;
    e->nextarc=G->vertices[j].firstarc;             /* 将e指针指向当前顶点指向的结点 */
    G->vertices[j].firstarc=e;                   /* 将当前顶点的指针指向e */
  }
}

//输出函数
void PrintGrapth(ALGraph G) {
  int i;
  ArcNode *p;
  for(i=0; i<G.vexnum; i++){
    printf("%d ", G.vertices[i].data);
    p=G.vertices[i].firstarc;
    while(p){
      printf(" -> %d", p->adjvex);
      p=p->nextarc;
    }
    printf("\n");
  }
}

//输出函数
void PrintUGrapth(ALGraph G) {
  int i;
  ArcNode *p;
  for(i=0; i<G.vexnum; i++){
    printf("%d ", G.vertices[i].data);
    p=G.vertices[i].firstarc;
    while(p){
      printf(" -> %d(%d)", p->adjvex, p->weight);
      p=p->nextarc;
    }
    printf("\n");
  }
}

//DFS遍历

void DFS(ALGraph *g,int i,int *visited){
	ArcNode *p;
	visited[i]=1;
	printf("%d ",g->vertices[i].data);
	p=g->vertices[i].firstarc;
	while( p ){
		if(!visited[p->adjvex]){
			DFS(g,p->adjvex,visited);
		}
		p=p->nextarc;
	}
}

void TraDFS(ALGraph *g){
	int i;
	int visited[MAX_VERTEX_NUM];
	for(i=0;i<g->vexnum;i++){
		visited[i]=0;
	}
	for(i=0;i<g->vexnum;i++){
		if(!visited[i]){
			DFS(g,i,visited);
		}
	}
}

/* 队列操作 */
//初始化队列
void InitQueue(Queue ** Q){
  (*Q)=(Queue*)malloc(sizeof(Queue));
  (*Q)->next=NULL;
}
//顶点元素v进队列
void EnQueue(Queue **Q,VertexType v){
  Queue * element=(Queue*)malloc(sizeof(Queue));
  element->data=v;
  element->next = NULL;
  Queue * temp=(*Q);
  while (temp->next!=NULL) {
    temp=temp->next;
  }
  temp->next=element;
}
//队头元素出队列
void DeQueue(Queue **Q,int *u){
  (*u)=(*Q)->next->data;
  (*Q)->next=(*Q)->next->next;
}
//判断队列是否为空
bool QueueEmpty(Queue *Q){
  if (Q->next==NULL) {
    return true;
  }
  return false;
}

//BFS遍历
void TraBFS(ALGraph *g){
	int i,j;
	Queue *q;
	int visited[MAX_VERTEX_NUM];
	for(i=0; i<g->vexnum; i++){
		visited[i]=0;
	}
	InitQueue(&q);
	for(i=0; i<g->vexnum;i++){
		if(!visited[i]){
			printf("%d ",g->vertices[i].data);
			visited[i]=1;
			EnQueue(&q, i);
			while(!QueueEmpty(q)){
				DeQueue(&q,&i);
				ArcNode *p = g->vertices[i].firstarc;
				while( p ){
					if(!visited[p->adjvex])
					{
						printf("%d ",g->vertices[p->adjvex].data);
						visited[p->adjvex]=1;
						EnQueue(&q,p->adjvex);
					}
					p=p->nextarc;
				}
			}
		}
	}
}

void main(){
  ALGraph G;
  printf("There are four types of graphs:\n1.DG\n2.DN\n3.UDG\n4.UDN\n");
  printf("Please enter the serial number of the picture you want to create: ");
  int k;
  scanf("%d", &k);
  CreateDNALGraph(&G);
  PrintGrapth(G);
  printf("DFS:  ");
  TraDFS(&G);
  printf("\nBFS:  ");
  TraBFS(&G);
  printf("\nPlease enter the serial number of the picture you want to create: ");
  scanf("%d", &k);
  CreateUDGALGraph(&G);
  PrintUGrapth(G);
  printf("DFS:  ");
  TraDFS(&G);
  printf("\nBFS:  ");
  TraBFS(&G);
  printf("\n");
  system("pause");
}