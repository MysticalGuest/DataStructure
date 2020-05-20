#include<stdio.h>
#include<stdlib.h>

#define VERTEXNUM 20
#define INFINITY 32768
#define True 1
#define False 0

int visited[VERTEXNUM];

typedef enum{
	DG,DN,UDG,UDN
}GraphKind;

typedef struct ArcNode{
	int adj;
}ArcNode;

typedef struct{
	char vertex[VERTEXNUM];
	ArcNode arcs[VERTEXNUM][VERTEXNUM];
	int vexnum,arcnum;
	GraphKind kind;
}AdjMatrix;


void InitGraph(AdjMatrix *g){
	int i,j;
	for(i=0;i<g->vexnum;i++)
		for(j=0;j<g->vexnum;j++){
			g->arcs[i][j].adj=INFINITY;
		}
}

int LocateVertex(AdjMatrix *g,char ch){
	int i;
	for(i=0;i<g->vexnum;i++){
		if(g->vertex[i]==ch)
			return i;
	}
	return -1;
}

void CreateGraph(AdjMatrix *g){
	int i,j,k;
	char v1,v2;
	printf("Please input the number of vertexes and verarcs respectively :");
	scanf("%d%d",&g->vexnum,&g->arcnum);
	InitGraph(g);
	printf("Please input each vertex successively:");
	getchar();
	for(i=0;i<g->vexnum;i++)
		scanf("%c",&g->vertex[i]);
	for(k=0;k<g->arcnum;k++){
		printf("Please input two vertexes of the arc:");
		fflush(stdin);
		scanf("%c%c",&v1,&v2);
		i=LocateVertex(g,v1);
		j=LocateVertex(g,v2);
		g->arcs[i][j].adj=1;
	}
}

void DepthFirstSearch(AdjMatrix g,int v){
	int i;
	printf("%c",g.vertex[v]);
	visited[v]=True;
	for(i=0;i<g.vexnum;i++){
		if(visited[i]==False&&g.arcs[v][i].adj==1)
			DepthFirstSearch(g,i);
	}
}

void TraverseGraph(AdjMatrix g){
	int vi;
	for(vi=0;vi<g.vexnum;vi++)
		visited[vi]=False;
	printf("Depth-First Search of this graph is:");
	for(vi=0;vi<g.vexnum;vi++)
		if(!visited[vi])
			DepthFirstSearch(g,vi);
	printf("\n");
}

void main(){
	AdjMatrix G;
	CreateGraph(&G);
	TraverseGraph(G);
}