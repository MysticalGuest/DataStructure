#include <stdio.h>
#include <Windows.h>

#define MAX_VERtEX_NUM 20                   //顶点的最大个数
#define VRType int                          //表示顶点之间的关系的变量类型
#define InfoType char                       //存储弧或者边额外信息的指针变量类型
#define VertexType int                      //图中顶点的数据类型

typedef enum{DG=1,DN=2,UDG=3,UDN=4}GraphKind;       //枚举图的 4 种类型

typedef enum{false,true}bool;               //定义bool型常量
bool visited[MAX_VERtEX_NUM];               //设置全局数组，记录标记顶点是否被访问过

typedef struct Queue{                       //广度优先搜索的实现需要借助队列
    VertexType data;
    struct Queue * next;
}Queue;

typedef struct {
    VRType adj;                             //对于无权图，用 1 或 0 表示是否相邻；对于带权图，直接为权值。
    InfoType *info;                        //弧或边额外含有的信息指针
}ArcCell, AdjMatrix[MAX_VERtEX_NUM][MAX_VERtEX_NUM];

typedef struct {
    VertexType vexs[MAX_VERtEX_NUM];        //存储图中顶点数据
    AdjMatrix arcs;                         //二维数组，记录顶点之间的关系
    int vexnum, arcnum;                      //记录图的顶点数和弧（边）数
    GraphKind kind;                         //记录图的种类
}MGraph;

//根据顶点本身数据，判断出顶点在二维数组中的位置
int LocateVex(MGraph * G,VertexType v){
  int i=0;
  //遍历一维数组，找到变量v
  for (; i<G->vexnum; i++) {
    if (G->vexs[i]==v) {
        break;
    }
  }
  //如果找不到，输出提示语句，返回-1
  if (i>G->vexnum) {
    printf("no such vertex.\n");
    return -1;
  }
  return i;
}

//构造无向图
void CreateDN(MGraph *G){
  printf("Enter the number of vertices and edges: ");
  scanf("%d%d", &(G->vexnum),&(G->arcnum));
  printf("Please enter all vertices: ");
  for (int i=0; i<G->vexnum; i++) {
    scanf("%d", &(G->vexs[i]));
  }
  for (int i=0; i<G->vexnum; i++) {
    for (int j=0; j<G->vexnum; j++) {
        G->arcs[i][j].adj=0;
        G->arcs[i][j].info=NULL;
    }
  }
  for (int i=0; i<G->arcnum; i++) {
    int v1,v2;
    printf("Enter the subscript i and j on the side (vi, vj):");
    scanf("%d%d", &v1, &v2);
    int n=LocateVex(G, v1);
    int m=LocateVex(G, v2);
    if (m==-1 ||n==-1) {
        printf("no this vertex\n");
        return;
    }
    G->arcs[n][m].adj=1;
    G->arcs[m][n].adj=1;      //无向图的二阶矩阵沿主对角线对称
  }
}

//输出函数
void PrintGrapth(MGraph G) {
  for (int i = 0; i < G.vexnum; i++){
    for (int j = 0; j < G.vexnum; j++){
      printf("%d ", G.arcs[i][j].adj);
    }
    printf("\n");
  }
}

void visitVex(MGraph G, int v){
  printf("%d ",G.vexs[v]);
}

int FirstAdjVex(MGraph G,int v){
  //查找与数组下标为v的顶点之间有边的顶点，返回它在数组中的下标
  for(int i = 0; i<G.vexnum; i++){
    if( G.arcs[v][i].adj ){
      return i;
    }
  }
  return -1;
}
int NextAdjVex(MGraph G,int v,int w){
  //从前一个访问位置w的下一个位置开始，查找之间有边的顶点
  for(int i = w+1; i<G.vexnum; i++){
    if(G.arcs[v][i].adj){
      return i;
    }
  }
  return -1;
}

void DFS(MGraph G,int v){
  visited[v] = true;//标记为true
  visitVex( G,  v); //访问第v 个顶点
  //从该顶点的第一个边开始，一直到最后一个边，对处于边另一端的顶点调用DFS函数
  for(int w = FirstAdjVex(G,v); w>=0; w = NextAdjVex(G,v,w)){
    //如果该顶点的标记位false，证明未被访问，调用深度优先搜索函数
    if(!visited[w]){
      DFS(G,w);
    }
  }
}

void Judge(MGraph G, bool *b){
  printf("The spanning tree or forest of this graph is: ");
  int v;
  //将用做标记的visit数组初始化为false
  for( v = 0; v < G.vexnum; ++v){
    visited[v] = false;
  }
  DFS( G, 0);    //从任意一点遍历，这里从下标为0的点开始
  for( v = 1; v < G.vexnum; v++){
    if(!visited[v]){
      DFS( G, v);
      *b = false;
      printf(" | ");
    }
  }
  *b = true;
}

/* 邻接表 */
typedef struct ArcNode{
  int adjvex;//邻接点在数组中的位置下标
  struct ArcNode * nextarc;//指向下一个邻接点的指针
  int weight;  //权值
  InfoType * info;//信息域
}ArcNode;

typedef struct VNode{
  VertexType data;//顶点的数据域
  ArcNode * firstarc;//指向邻接点的指针
}VNode, AdjList[MAX_VERtEX_NUM];//存储各链表头结点的数组

typedef struct {
  AdjList vertices;//图中顶点的数组
  int vexnum,arcnum;//记录图中顶点数和边或弧数
  GraphKind kind;//记录图的种类
}ALGraph;

/* 建立无向图的邻接表结构 */
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

//输出函数
void PrintAdjList(ALGraph G) {
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

//DFS遍历

void DFSAdjList(ALGraph *g,int i,int *visited){
	ArcNode *p;
	visited[i]=1;
	printf("%d ",g->vertices[i].data);
	p=g->vertices[i].firstarc;
	while( p ){
		if(!visited[p->adjvex]){
			DFSAdjList(g, p->adjvex,visited);
		}
		p=p->nextarc;
	}
}

void JudgeAdjList(ALGraph *g, bool *b){
  printf("The spanning tree or forest of this graph is: ");
	int i;
	int visited[MAX_VERtEX_NUM];
	for(i=0;i<g->vexnum;i++){
		visited[i]=0;
	}
  DFSAdjList(g, 0, visited);
	for(i=1;i<g->vexnum;i++){
		if(!visited[i]){
      printf(" | ");
			DFSAdjList(g, i, visited);
      *b = false;
		}
	}
  *b = true;
}

void main() {
  MGraph G;           //建立一个图的变量
  int i=0;
  bool b;
  CreateDN(&G);    //调用创建函数，传入地址参数
  PrintGrapth(G);     //输出图的二阶矩阵
  Judge(G, &b);
  if(b==true)
    printf("\nThis graph is a connected graph.\n");
  else
    printf("\nThis graph is not a connected graph.\n");
  ALGraph AG;
  printf("\n");
  bool b1;
  CreateDGALGraph(&AG);
  PrintAdjList(AG);
  JudgeAdjList(&AG, &b1);
  if(b1==true)
    printf("\nThis graph is a connected graph.\n");
  else
    printf("\nThis graph is not a connected graph.\n");
  system("pause");
}