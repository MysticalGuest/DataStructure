#include<stdio.h>

typedef int ElemType;
typedef struct Node{
	int num;
	struct Node *lChild;
	struct Node *rChild;
}BiTNode,*BiTree;

// 练习1
int path(TreeNode* t)
{
  if(t==NULL)
    return 0;
  int left=path(t->left)+1;
  int right=path(t->right)+1;
  return left+right;
}

int pathLen = 0;
// layer初值为1
void BiTreePathLen(BiTree bt, int layer){
  if(bt==NULL)  return;
  pathLen = pathLen + layer - 1;
  BiTreePathLen(bt->lChild, layer+1);
  BiTreePathLen(bt->rChild, layer+1);
}

// 练习2
BiTNode *pre = NULL;
BiTNode LinkLeaf(BiTree bt){
  BiTNode *head;
  if(bt==NULL)  return NULL;

  if(bt->lChild==NULL && bt->rChild==NULL){
    if(pre==NULL){  // 第一个叶子节点
      // pre = bt;
      // head = pre;
      head->rChild=bt;
    }
    else{
      pre->rChild = bt;
      pre=bt;
    }
  }
  LinkLeaf(bt->lChild);
  LinkLeaf(bt->rChild);

  return head;
}


// 练习3
int Parent(BiPTree T, BiTPNode son, TElemType data)
{ /* 初始条件：二叉树T存在，e是T中某个结点 */
  /* 操作结果：若e是T的非根结点，则返回它的双亲，否则返回＂空＂*/
  BiPTree a;
  if(T) /* 非空树 */
  {
    if(son && son!=T) /* T中存在结点e且e是非根结点 */
      son->parent->data = data; /* 返回e的双亲的值 */
    return OK;
  }
  return ERROR; /* 其余情況返回空 */
}

void setParent(BiTree bt){
  if(bt==NULL)  return;

  setParent(bt->lChild);

  if(bt->lChild)  bt->lChild->parent=data;
  if(bt->rChild)  bt->rChild->parent=data;

  setParent(bt->lChild);
}

// 练习4
int Huffman(TreeNode* t){
	if(T){
		int weight = i*T->weight;
		int l=PreOrder(T->lchild, i+1);
		int r=PreOrder(T->rchild, i+1);//这里的压栈，只是为了再一次调用上面的函数
    return weight+l+r;
	}
  else{
    return 0;
  }
}

void Print(CSTree bt){
  if(bt--NULL)  return;

  p=bt->FirstChild;
  while(p!=NULL){
    printf("(%c, %c)", bt->data, p->data);
    p = p->nextsibling;
  }

  Print(bt->FirstChild);
  Print(bt->nextsibling);
}