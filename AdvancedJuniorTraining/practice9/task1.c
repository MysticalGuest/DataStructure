#include<stdio.h>
#include<Windows.h>

typedef char ElemType;
typedef struct Node{
	ElemType elem;
	struct Node *LChild;
	struct Node *RChild;
}BiTNode, *BiTree;

// 前序+中序重建二叉树
void ReBuildByPreAndInOrder(char *prelist, char *inlist, int len, BiTree *bt){
  if(!prelist || !inlist || len<=0 )		//空树 
		return;
	int i;
	
	// 找到根结点在中序遍历中的位置 
	for(i = 0; i < len; i++){
		if(inlist[i] == prelist[0])			
			break;					 
	} 
	
	if(i>=len)
		return;
	
	// 初始化根结点 
	*bt = (BiTNode*)malloc(sizeof(BiTNode));
	if(!bt) // 申请失败
		return;
	(*bt)->LChild = (*bt)->RChild = NULL;
	(*bt)->elem = prelist[0];
	
	// 重建左子树
	ReBuildByPreAndInOrder(prelist+1, inlist, i, &(*bt)->LChild); 
	// 重建右子树 
	ReBuildByPreAndInOrder(prelist+i+1, inlist+i+1, len-i-1, &(*bt)->RChild);
}

// 中序+后序重建二叉树
void ReBuildByInAndPostOrder(char *inlist,char *postlist, int len, BiTree *bt){
  if(!inlist || !postlist || len<=0 )		//空树 
		return;
	int i;
	
	// 找到根结点在中序遍历中的位置 
	for(i = 0; i < len; i++){
		if(inlist[i] == postlist[len-1])			
			break;					 
	} 
	
	if(i>=len)
		return;
	
	// 初始化根结点 
	*bt = (BiTNode*)malloc(sizeof(BiTNode));
	if(!bt)
		return;
	(*bt)->LChild = (*bt)->RChild = NULL;
	(*bt)->elem = postlist[len-1];
	
	//重建左子树	
	ReBuildByInAndPostOrder(inlist, postlist, i, &(*bt)->LChild); 				
	//重建右子树 
	ReBuildByInAndPostOrder(inlist+i+1, postlist+i, len-i-1, &(*bt)->RChild);
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

void main(){
  char pre[7]={'A', 'B', 'D', 'E', 'C', 'F', 'G'},
    inorder1[7] = {'D', 'B', 'E', 'A', 'F', 'C', 'G'},
    inorder2[9] = {'G', 'D', 'H', 'B', 'A', 'E', 'C', 'I', 'F'},
    post[9] = {'G', 'H', 'D', 'B', 'E', 'I', 'F', 'C', 'A'};
  int i=0;

  /* 前序+中序重建二叉树 */
  printf("Give the preorder and midorder traversal of a binary tree: \nPreorder = ");
  for(i=0; i<7; i++){
    printf("%c  ", pre[i]);
  }
  printf("\nMidorder = ");
  for(i=0; i<7; i++){
    printf("%c  ", inorder1[i]);
  }

  BiTree T1=NULL;
  ReBuildByPreAndInOrder(pre, inorder1, 7, &T1);
  printf("\nThe binary tree constructed by two traversal sequences is: \n");
  PrintTree(T1, 1);
  /* 前序+中序重建二叉树 */

  /* 中序+后序重建二叉树 */
  printf("Give the midorder and postorder traversal of a binary tree: \nMidorder = ");
  for(i=0; i<9; i++){
    printf("%c  ", inorder2[i]);
  }
  printf("\nPostorder = ");
  for(i=0; i<9; i++){
    printf("%c  ", post[i]);
  }

  BiTree T2=NULL;
  ReBuildByInAndPostOrder(inorder2, post, 9, &T2);
  printf("\nThe binary tree constructed by two traversal sequences is: \n");
  PrintTree(T2, 1);
  /* 中序+后序重建二叉树 */

  system("pause");
}