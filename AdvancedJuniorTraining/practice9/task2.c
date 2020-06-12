#include<stdio.h>
#include<Windows.h>

typedef struct Node{
	char elem;
	struct Node *LChild;
	struct Node *RChild;
}BiTNode,*BiTree;

void CreateBiTree(BiTree *bt, char *list, int locate){
  char ch = list[locate];
	if(ch=='#')
		(*bt)=NULL;
	else{
		(*bt)=(BiTree)malloc(sizeof(BiTNode));
		(*bt)->elem=ch;
		CreateBiTree(&((*bt)->LChild), list, 2*locate+1);
		CreateBiTree(&((*bt)->RChild), list, 2*locate+2);
	}
}

void PrintTree(BiTree bt,int nLayer){
	int i;
	if(bt==NULL)
		return;
	PrintTree(bt->RChild,nLayer+1);
	for(i=0;i<nLayer;i++)
		printf(" ");
	printf("%c\n", bt->elem);
	PrintTree(bt->LChild,nLayer+1);
}

void level_in_x(BiTree BT,char x,int level){

  if (BT == NULL){
    return ;
  }
  if(BT->elem == x){
    printf("x in %d",level);
  }
  level++;
  printf("1:%d----\n", level);
  level_in_x(BT->LChild,x,level);
  printf("2:%d----\n", level);
  level_in_x(BT->RChild,x,level);
  printf("3:%d----\n", level);
  level--;
}

int find_node_level(BiTree bt, char x, int h){
  if (bt == NULL)
    return 0;
  else if (bt->elem == x)
    return h;
  else{
    int l = find_node_level(bt->LChild, x, h+1);
    if (l != 0)
      return l;
    else
      return find_node_level(bt->RChild, x, h+1);
  }
}

int layer(BiTree bt, char x){
  int cot = 0;
  if(bt==NULL)
    return cot;
  else if(bt->elem==x){
    cot = 1;
    return cot;
  }
  else{
    printf("layer(bt->LChild, x): %d\n", layer(bt->LChild, x));
    if(layer(bt->LChild, x)){
      cot = layer(bt->LChild, x)+1;
      return cot;
    }
    printf("layer(bt->RChild, x): %d\n", layer(bt->RChild, x));
    if(layer(bt->RChild, x)){
      cot = layer(bt->RChild, x)+1;
      return cot;
    }
  }
  return cot;
}

void main(){
  char list[31] = {'A', 'B', 'C', '#', 'D', '#','E', '#', '#', 'F', 'G','#','#','H','#',
    '#','#', '#','#', '#','#', '#','#', '#','#', '#','#', '#','#', '#','#'};
  BiTree T;
  CreateBiTree(&T, list, 0);
  printf("Give a binary tree: \n");
  PrintTree(T, 1);
  char x;
  printf("Enter the median of the binary tree you want to find, x = ");
  scanf("%c", &x);
  // level_in_x(T, x, 1);
  int lay= find_node_level(T, x, 1);
  if(lay==0)
    printf("The element you entered is not in the binary tree!\n");
  else
    printf("The layer number of the node with value %c in the binary tree is: %d\n", x, lay);
  printf("The layer number of the node with value %c in the binary tree is: %d\n", x, layer(T, x));
  system("pause");
}