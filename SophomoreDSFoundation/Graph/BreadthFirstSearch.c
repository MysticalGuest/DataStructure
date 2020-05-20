#include<stdio.h>
#include<stdlib.h>

#define VERTEXNUM 20
#define True 1
#define False 0

int visited[VERTEXNUM];

typedef enum{
	DG,DN,UDG,UDN
}GraphKind;

typedef struct ArcNode{
	int adjvex;
	struct ArcNode *nextarc;
}ArcNode;

typedef struct VertexNode{
	char date;
	ArcNode *firstarc;
}VertexNode;

typedef struct{
	VertexNode vertex[VERTEXNUM];
	int vexnum,arcnum;
	GraphKind kind;
}AdjList;

typedef struct{
	int date[VERTEXNUM];
	int front,rear;
}SeqQueue;

void InitQueue(SeqQueue *Q){
	Q->front=Q->rear=0;
}

void EnterQueue(SeqQueue *Q,int x){
	if((Q->rear+1)%VERTEXNUM==Q->front)
		return;
	Q->date[Q->rear]=x;
	Q->rear=(Q->rear+1)%VERTEXNUM;
}

void DeleteQueue(SeqQueue *Q,int *x){
	if(Q->front==Q->rear)
		return;
	*x=Q->date[Q->front];
	Q->front=(Q->front+1)%VERTEXNUM;
}

int LocateVertex(AdjList *g,char ch){
	int i;
	for(i=0;i<g->vexnum;i++){
		if(g->vertex[i].date==ch)
			return i;
	}
	return -1;
}

void CreateGraph(AdjList *g){
	int i,j,k;
	char v1,v2;
	ArcNode *s,*p;
	printf("Please input the number of vertexes and verarcs respectively :");
	scanf("%d%d",&g->vexnum,&g->arcnum);
	printf("Please input each vertex successively:");
	getchar();
	for(i=0;i<g->vexnum;i++){
		scanf("%c",&g->vertex[i]);
		g->vertex[i].firstarc=NULL;
	}
	for(k=0;k<g->arcnum;k++){
		printf("Please input two vertexes of the arc:");
		fflush(stdin);
		scanf("%c%c",&v1,&v2);
		i=LocateVertex(g,v1);
		s=(ArcNode*)malloc(sizeof(ArcNode));
		s->adjvex=i;
		s->nextarc=g->vertex[i].firstarc;
		g->vertex[i].firstarc=s;
		j=LocateVertex(g,v2);
		p=(ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex=j;
		p->nextarc=g->vertex[i].firstarc;
		g->vertex[i].firstarc=p;
	}
}

void BreadthFirstSearch(AdjList g,int v){
}

void main(){
	AdjList G;
	CreateGraph(&G);
}