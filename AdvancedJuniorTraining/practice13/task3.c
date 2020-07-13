#include <stdio.h>
#include <Windows.h>

#define MAX_VERTEX_NUM 20                   //顶点的最大个数
#define InfoType char                       //存储弧或者边额外信息的指针变量类型
#define VertexType int                      //图中顶点的数据类型
#define INFINITY 65535             /* 用65535来代表无穷大 */

typedef enum{false,true}bool;               //定义bool型常量
typedef enum{DG=1,DN=2,UDG=3,UDN=4}GraphKind;       //枚举图的 4 种类型
bool visited[MAX_VERTEX_NUM];               //设置全局数组，记录标记顶点是否被访问过

/* 邻接表 */
typedef struct ArcNode{
  int adjvex;//邻接点在数组中的位置下标
  struct ArcNode * nextarc;//指向下一个邻接点的指针
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

    e=(ArcNode *)malloc(sizeof(ArcNode));      /* 向内存申请空间 *//* 生成边表结点 */
    e->adjvex=i;                                 /* 邻接序号为i */
    e->nextarc=G->vertices[j].firstarc;             /* 将e指针指向当前顶点指向的结点 */
    G->vertices[j].firstarc=e;                   /* 将当前顶点的指针指向e */
  }
}

//输出函数
void PrintAdjList(ALGraph G) {
  printf("This graph is represented by adjacency list as: \n");
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

int Dijkstra(ALGraph G){
  int s=0, t=3, i, j;
  int visit[MAX_VERTEX_NUM];
  int distance[MAX_VERTEX_NUM];        //从 s 到各点的距离
  
  for(i=0; i<G.vexnum; i++){
    distance[i]=INFINITY;
    visit[i]=false;
  }
  distance[s]=0;
  visit[s]=1;
  ArcNode *p=G.vertices[s].firstarc;
  
  while(p){   //先把距离源点距离最近的顶点都遍历完
    if(!visit[p->adjvex]){
      distance[p->adjvex]=1;
      visit[p->adjvex]=1;        //当前顶点已访问
    }
    p=p->nextarc;
  }

  for(i=0; i<G.vexnum; i++){      //再求其他顶点
    if(!visit[G.vertices[i].data]){
      p=G.vertices[i].firstarc;   //未访问的节点
      while(p){
        if(distance[p->adjvex]<INFINITY){
          distance[G.vertices[i].data]=distance[p->adjvex]+1;
        }
        p=p->nextarc;
      }
    }
  }
}

void findAllSimplePath(ALGraph G, int start, int end, int path[], int i){
  ArcNode *p;
  int j, n;
  visited[start]=1;  // 记录已近访问过这个顶点
  p=G.vertices[start].firstarc;
  while (p){
    n=p->adjvex;
    if(n==end){   //找到一个路径
      path[i+1] = end;
      for(j=0; j<=i+1; j++)
        printf("%-3d", path[j]);
      printf("\n");
    }
    else if(!visited[n]){   //改点未被遍历
      path[i+1]=n;//存入路径
      findAllSimplePath(G, n, end, path, i+1); // 递归
    }
    p=p->nextarc;
  }
  // visited[x]=0;
}

void PrintPath(ALGraph G){
  int s, e;
  int path[MAX_VERTEX_NUM]; // 声明记录路径的数组
  // 初始化访问数组
  for(int i=0; i<G.vexnum; i++){
    visited[i]=false;
  }
  // 请输入任意两个顶点
  printf("Please enter any two vertices: ");
  scanf("%d%d", &s, &e);
  path[0]=s;// 出发点
  printf("The path between vertex %d and vertex %d are: \n", s, e);
  findAllSimplePath(G, path[0], e, path, 0);
}

void main() {
  ALGraph G;
  CreateDGALGraph(&G);
  PrintAdjList(G);
  PrintPath(G);
  system("pause");
}