#include<stdio.h>
#include<math.h>
#include<Windows.h>

// #define StackSize 50

// typedef struct Node{
// 	int data;
// 	struct Node *LChild;
// 	struct Node *RChild;
// }BiTNode,*BiTree;


BOOL VerifySequenceOfBST(int *array,int length){
	if(array==NULL || length<=0)
		return FALSE;
	int root=array[length-1];
	int i=0;    //左子树的结点小于根节点；
	for(;i<length-1;i++){
		if(array[i]>root)
			break;    //找完了全部的左子树的序列；
	}
	int j=i;//右子树的结点大于根结点；
	for(;j<length-1;j++){
		if(array[j]<root)
			return FALSE;
	}
	BOOL left=TRUE;
	if(i>0)
		left=VerifySequenceOfBST(array,i);
	BOOL right=TRUE;
	if(j<length-1)
		right=VerifySequenceOfBST(array+i,length-i-1);
	return left && right;
}

void FormatPrint(BOOL b){
  if(b)
    printf("Whether it is a postorder traversal sequence of a binary sorting tree: true.\n");
  else
    printf("Whether it is a postorder traversal sequence of a binary sorting tree: flase.\n");
}

void main(){
  int arr1[7]={5, 7, 6, 9, 11, 10, 8};  //YES
  int arr2[4]={7, 6, 4, 5};  //NO
  int i;
  printf("Give an array of integers: \n(");
  for(i=0; i<7; i++)
    printf(" %d ", arr1[i]);
  printf(")\n");
  FormatPrint(VerifySequenceOfBST(arr1, 7));
  printf("Give an another array of integers: \n(");
  for(i=0; i<4; i++)
    printf(" %d ", arr2[i]);
  printf(")\n");
  FormatPrint(VerifySequenceOfBST(arr2, 4));
  system("pause");
}