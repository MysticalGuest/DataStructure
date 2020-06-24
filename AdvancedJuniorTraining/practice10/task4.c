#include<stdio.h>
#include<math.h>
#include<Windows.h>

typedef struct Node{
	int data;
	struct Node *LChild;
	struct Node *RChild;
}BiTNode,*BiTree;

void CreateBiTree(BiTree *bt, int *list, int locate){
  int ch = list[locate];
	if(ch==-100)
		(*bt)=NULL;
	else{
		(*bt)=(BiTree)malloc(sizeof(BiTNode));
		(*bt)->data=ch;
		CreateBiTree(&((*bt)->LChild), list, 2*locate+1);
		CreateBiTree(&((*bt)->RChild), list, 2*locate+2);
	}
}

void PrintTree(BiTree bt,int nLayer){
	int i;
	if(bt==NULL)
		return;
	PrintTree(bt->RChild,nLayer+1);
	for(i=0; i<nLayer; i++)
		printf("  ");
	printf("%d\n", bt->data);
	PrintTree(bt->LChild,nLayer+1);
}

int Deep(BiTree bt){
  int ld=0,rd=0;
  if(bt){
    ld=Deep(bt->LChild)+1;
    rd=Deep(bt->RChild)+1;
  }
  return ld>=rd?ld:rd;
}

BiTree pre=NULL;
BOOL ISAVL(BiTree root){
  int lcd=0,rcd=0;
  if(root!=NULL){
    int l = ISAVL(root->LChild);
    // printf("pre: %d\n", pre->data);
    lcd=Deep(root->LChild);   // 左子树的深度
    rcd=Deep(root->RChild);   // 右子树的深度
    // printf("Deep(root->LChild): %d\n", Deep(root->LChild));
    // printf("Deep(root->RChild): %d\n", Deep(root->RChild));
    // printf("root: %d\n", root->data);
    if(abs(lcd-rcd)>1){   // 条件1:每一个节点的左子树和右子树的高度差至多等于1
      return FALSE;
    }
    if(pre!=NULL){
      if(pre->data > root->data){    // 条件2:中序遍历的前驱节点大于后面节点的值,就不是平衡二叉树
        return FALSE;
      }
    }
    pre=root;
    int r = ISAVL(root->RChild);
    return l && r;
  }
  return TRUE;
}

void PrintIsAVL(BOOL b){
  if(b==TRUE)
    printf("This is a balanced binary tree!\n");
  else
    printf("This is not a balanced binary tree!\n");
}

void main(){
  int tree1[31] = {16, 10, 20, 5, -100, 15, 24, -100, 8, -100, -100, -100, -100, -100, -100,
    -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100};
  BiTree T1;
  CreateBiTree(&T1, tree1, 0);
  printf("Give a binary tree: \n");
  PrintTree(T1, 1);
  PrintIsAVL(ISAVL(T1));
  int tree2[31] = {16, 10, 20, 5, 12, 17, 24, -100, 8, -100, -100, -100, -100, -100, -100,
    -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100};
  BiTree T2;
  CreateBiTree(&T2, tree2, 0);
  printf("Give a binary tree: \n");
  PrintTree(T2, 1);
  pre=NULL;   // 将前置置空
  PrintIsAVL(ISAVL(T2));
  system("pause");
}