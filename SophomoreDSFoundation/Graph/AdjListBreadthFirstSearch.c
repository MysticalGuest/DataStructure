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

int IsEmpty(SeqQueue Q){
	if(Q.rear==Q.front)
		return 1;
	else
		return 0;
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
	int v1;
	ArcNode *w;
	SeqQueue Q;
	InitQueue(&Q);
	EnterQueue(&Q,v);
	printf("%c",g.vertex[v].date);
	visited[v]=True;
	while(!IsEmpty(Q)){
		DeleteQueue(&Q,&v1);
		w=g.vertex[v1].firstarc;
		while(w!=NULL){
			if(!visited[w->adjvex]){
				printf("%c",g.vertex[w->adjvex]);
				visited[w->adjvex]=True;
				EnterQueue(&Q,w->adjvex);
			}
			w=w->nextarc;
		}
	}
}

void TraverseGraph(AdjList g){
	int vi;
	for(vi=0;vi<g.vexnum;vi++)
		visited[vi]=False;
	printf("Breadth-First Search of this graph is:");
	for(vi=0;vi<g.vexnum;vi++)
		if(!visited[vi])
			BreadthFirstSearch(g,vi);
	printf("\n");
}
/*
int Path(AdjList g,int v1,int v2){
	int i,v;
	SeqQueue Q;
	ArcNode *w;
	InitQueue(&Q);
	for(i=0;i<VERTEXNUM;i++)
		visited[i]=False;
	if(v1==v2)
		return 1;
	visited[v1]=True;
	EnterQueue(&Q,v1);
	while(!IsEmpty(Q)){
		DeleteQueue(&Q,&v);
		w=g.vertex[v].firstarc;
		while(w!=NULL){
			if(!visited[w->adjvex]){
				if(w->adjvex==v2)
					return 1;
				visited[w->adjvex]=True;
				EnterQueue(&Q,w->adjvex);
			}
			w=w->nextarc;
		}
	}
	return 0;
}

void IsPath(AdjList g){
	char v1,v2;
	int i,j;
	printf("Please input two vertexes: ");
	fflush(stdin);
	scanf("%c%c",&v1,&v2);
	getchar();
	printf("%c,%c\n",v1,v2);
	i=LocateVertex(&g,v1);
	j=LocateVertex(&g,v2);
	if(Path(g,i,j)==1)
		printf("Yes!\n");
	else
		printf("No!\n");
}
*/
void main(){
	AdjList G;
	CreateGraph(&G);
	TraverseGraph(G);
	//IsPath(G);
}