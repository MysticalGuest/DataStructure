#include<stdio.h>
#include<stdlib.h>

#define VERTEXNUM 20

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
	ArcNode elem[VERTEXNUM];
	int top;
}SeqStack;

void InitStack(SeqStack *S){
	S->top=-1;
}

void Push(SeqStack *S,ArcNode ch){
	if(S->top==VERTEXNUM-1)
		return;
	else{
		S->top++;
		S->elem[S->top]=ch;	
	}
}

void Pop(SeqStack *S,ArcNode *ch){
	if(S->top==-1)
		return;
	else{
		*ch=S->elem[S->top];
		S->top--;
	}
}

int IsEmpty(SeqStack S){
	if(S.top==-1)
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
	ArcNode *s;
	printf("Please input the number of vertexes and verarcs respectively :");
	scanf("%d%d",&g->vexnum,&g->arcnum);
	printf("Please input each vertex successively:");
	getchar();
	for(i=0;i<g->vexnum;i++){
		scanf("%c",&g->vertex[i].date);
		g->vertex[i].firstarc=NULL;
	}
	for(k=0;k<g->arcnum;k++){
		printf("Please input two vertexes of the arc:");
		fflush(stdin);
		scanf("%c,%c",&v1,&v2);

		i=LocateVertex(g,v1);
		j=LocateVertex(g,v2);
		s=(ArcNode*)malloc(sizeof(ArcNode));
		s->adjvex=i;
		s->nextarc=g->vertex[j].firstarc;
		g->vertex[j].firstarc=s;
	}
}

void InsertVertex(AdjList *g,char ch){
	g->vertex[g->vexnum].date=ch;
	g->vertex[g->vexnum].firstarc=NULL;
	g->vexnum++;
}

void InsertArc(AdjList *g,char v,char w){
	int i,j;
	ArcNode *s,*p;
	i=LocateVertex(g,v);
	j=LocateVertex(g,w);
	s=(ArcNode*)malloc(sizeof(ArcNode));
	s->adjvex=j;
	s->nextarc=g->vertex[i].firstarc;
	g->vertex[i].firstarc=s;
	p=(ArcNode*)malloc(sizeof(ArcNode));
	p->adjvex=i;
	p->nextarc=g->vertex[j].firstarc;
	g->vertex[j].firstarc=p;
}

void main(){
	char ch;
	AdjList G;
	CreateGraph(&G);
	printf("What vertex do you want to insert:");
	fflush(stdin);
	ch=getchar();
	InsertVertex(&G,ch);
}