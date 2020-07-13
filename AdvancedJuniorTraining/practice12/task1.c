#include <stdio.h>
#include <Windows.h>

#define MAX_VERTEX_NUM 20                   //顶点的最大个数
#define VRType int                          //表示顶点之间的关系的变量类型
#define InfoType char                       //存储弧或者边额外信息的指针变量类型
#define VertexType int                      //图中顶点的数据类型

typedef enum{DG=1,DN=2,UDG=3,UDN=4}GraphKind;       //枚举图的 4 种类型

typedef enum{false,true}bool;               //定义bool型常量
bool visited[MAX_VERTEX_NUM];               //设置全局数组，记录标记顶点是否被访问过

typedef struct Queue{                       //广度优先搜索的实现需要借助队列
    VertexType data;
    struct Queue * next;
}Queue;

typedef struct {
    VRType adj;                             //对于无权图，用 1 或 0 表示是否相邻；对于带权图，直接为权值。
    InfoType *info;                        //弧或边额外含有的信息指针
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct {
    VertexType vexs[MAX_VERTEX_NUM];        //存储图中顶点数据
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
//构造有向图
void CreateDG(MGraph *G){
  //输入图含有的顶点数和弧的个数
  printf("Enter the number of vertices and edges: ");
  scanf("%d%d",&(G->vexnum),&(G->arcnum));
  //依次输入顶点本身的数据
  printf("Please enter all vertices: ");
  for (int i=0; i<G->vexnum; i++) {
    scanf("%d",&(G->vexs[i]));
  }
  //初始化二维矩阵，全部归0，指针指向NULL
  for (int i=0; i<G->vexnum; i++) {
    for (int j=0; j<G->vexnum; j++) {
        G->arcs[i][j].adj=0;
        G->arcs[i][j].info=NULL;
    }
  }
  //在二维数组中添加弧的数据
  for (int i=0; i<G->arcnum; i++) {
    int v1,v2;
    //输入弧头和弧尾
    printf("Enter arc head and arc tail: ");
    scanf("%d%d", &v1, &v2);
    //确定顶点位置
    int n=LocateVex(G, v1);
    int m=LocateVex(G, v2);
    //排除错误数据
    if (m==-1 ||n==-1) {
      printf("no this vertex\n");
      return;
    }
    //将正确的弧的数据加入二维数组
    G->arcs[n][m].adj=1;
  }
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
    scanf("%d%d", &v1,&v2);
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

//构造有向网，和有向图不同的是二阶矩阵中存储的是权值。
void CreateUDG(MGraph *G){
  printf("Enter the number of vertices and edges: ");
  scanf("%d%d",&(G->vexnum),&(G->arcnum));
  printf("Please enter all vertices: ");
  for (int i=0; i<G->vexnum; i++) {
    scanf("%d",&(G->vexs[i]));
  }
  for (int i=0; i<G->vexnum; i++) {
    for (int j=0; j<G->vexnum; j++) {
      G->arcs[i][j].adj=0;
      G->arcs[i][j].info=NULL;
    }
  }
  for (int i=0; i<G->arcnum; i++) {
    int v1,v2,w;
    printf("Enter the arc head, arc tail and the weight of this edge: ");
    scanf("%d%d%d",&v1,&v2,&w);
    int n=LocateVex(G, v1);
    int m=LocateVex(G, v2);
    if (m==-1 ||n==-1) {
      printf("no this vertex\n");
      return;
    }
    G->arcs[n][m].adj=w;
  }
}

//构造无向网。和无向图唯一的区别就是二阶矩阵中存储的是权值
void CreateUDN(MGraph* G){
  printf("Enter the number of vertices and edges: ");
  scanf("%d%d",&(G->vexnum),&(G->arcnum));
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
    int v1,v2,w;
    printf("Enter the two vertices of the edge and the weight of this edge: ");
    scanf("%d%d%d",&v1,&v2,&w);
    int m=LocateVex(G, v1);
    int n=LocateVex(G, v2);
    if (m==-1 ||n==-1) {
        printf("no this vertex\n");
        return;
    }
    G->arcs[n][m].adj=w;
    G->arcs[m][n].adj=w;      //矩阵对称
  }
}

void CreateGraph(MGraph *G) {
  //选择图的类型
  printf("Please enter the serial number of the picture you want to create: ");
  scanf("%d", &(G->kind));
  //根据所选类型，调用不同的函数实现构造图的功能
  switch (G->kind) {
    case DG:
      return CreateDG(G);
      break;
    case DN:
      return CreateDN(G);
      break;
    case UDG:
      return CreateUDG(G);
      break;
    case UDN:
      return CreateUDN(G);
      break;
    default:
      break;
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

void visitVex(MGraph G, int v){
  printf("%d ",G.vexs[v]);
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

//深度优先搜索
void DFSTraverse(MGraph G){
  printf("The sequence of depth-first search for this graph is: ");
  int v;
  //将用做标记的visit数组初始化为false
  for( v = 0; v < G.vexnum; ++v){
    visited[v] = false;
  }
  //对于每个标记为false的顶点调用深度优先搜索函数
  for( v = 0; v < G.vexnum; v++){
    //如果该顶点的标记位为false，则调用深度优先搜索函数
    if(!visited[v]){
      DFS( G, v);
    }
  }
  printf("\n");
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

//广度优先搜索
void BFSTraverse(MGraph G){
  printf("The sequence of breadth-first search for this graph is: ");
  int v;
  //将用做标记的visit数组初始化为false
  for( v = 0; v < G.vexnum; ++v){
    visited[v] = false;
  }
  //对于每个标记为false的顶点调用深度优先搜索函数
  Queue * Q;
  InitQueue(&Q);
  for( v = 0; v < G.vexnum; v++){
    if(!visited[v]){
      visited[v]=true;
      visitVex(G, v);
      EnQueue(&Q, G.vexs[v]);
      while (!QueueEmpty(Q)) {
        int u;
        DeQueue(&Q, &u);
        u=LocateVex(&G, u);
        for (int w=FirstAdjVex(G, u); w>=0; w=NextAdjVex(G, u, w)) {
          if (!visited[w]) {
            visited[w]=true;
            visitVex(G, w);
            EnQueue(&Q, G.vexs[w]);
          }
        }
      }
    }
  }
  printf("\n");
}

void main() {
  MGraph G;           //建立一个图的变量
  int i=0;
  printf("There are four types of graphs:\n1.DG\n2.DN\n3.UDG\n4.UDN\n");
  while(i<2){
    CreateGraph(&G);    //调用创建函数，传入地址参数
    PrintGrapth(G);     //输出图的二阶矩阵
    DFSTraverse(G);     //深度优先搜索图
    BFSTraverse(G);     //广度优先搜索图
    i++;
  }
  // CreateGraph(&G);    //调用创建函数，传入地址参数
  // PrintGrapth(G);     //输出图的二阶矩阵
  // DFSTraverse(G);     //深度优先搜索图
  // BFSTraverse(G);     //广度优先搜索图
  system("pause");
}