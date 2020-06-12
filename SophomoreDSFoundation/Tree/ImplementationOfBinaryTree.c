#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define NAMELEN 40

typedef struct Node{
	char name[NAMELEN];
	char author[NAMELEN];
	double price;
	struct Node *LChild;
	struct Node *RChild;
}BSTNode,*BSTree;

void InOrder(BSTree bst){
	if(bst!=NULL){
		InOrder(bst->LChild);
		printf("%s\n",bst->name);
		printf("%s\n",bst->author);
		printf("%.2lf\n",bst->price);
		InOrder(bst->RChild);
	}
}

void InsertBSTOfName(BSTree *bst,char n[],char a[],double p){
	BSTree s;
	if(*bst==NULL){
		s=(BSTree)malloc(sizeof(BSTNode));
		strcpy(s->name,n);
		strcpy(s->author,a);
		s->price=p;
		s->LChild=NULL;
		s->RChild=NULL;
		*bst=s;
	}
	else if(strcmp(n,(*bst)->name)<0)
		InsertBSTOfName(&((*bst)->LChild),n,a,p);
	else if(strcmp(n,(*bst)->name)>=0)
		InsertBSTOfName(&((*bst)->RChild),n,a,p);
}

void InsertBSTOfAuthor(BSTree *bst,char n[],char a[],double p){
	BSTree s;
	if(*bst==NULL){
		s=(BSTree)malloc(sizeof(BSTNode));
		strcpy(s->name,n);
		strcpy(s->author,a);
		s->price=p;
		s->LChild=NULL;
		s->RChild=NULL;
		*bst=s;
	}
	else if(strcmp(a,(*bst)->author)<0)
		InsertBSTOfAuthor(&((*bst)->LChild),n,a,p);
	else if(strcmp(a,(*bst)->author)>=0)
		InsertBSTOfAuthor(&((*bst)->RChild),n,a,p);
}

void InsertBSTOfPrice(BSTree *bst,char n[],char a[],double p){
	BSTree s;
	if(*bst==NULL){
		s=(BSTree)malloc(sizeof(BSTNode));
		strcpy(s->name,n);
		strcpy(s->author,a);
		s->price=p;
		s->LChild=NULL;
		s->RChild=NULL;
		*bst=s;
	}
	else if(p<(*bst)->price)
		InsertBSTOfPrice(&((*bst)->LChild),n,a,p);
	else if(p>=(*bst)->price)
		InsertBSTOfPrice(&((*bst)->RChild),n,a,p);
}

void CreateBST(BSTree *bstOfName,BSTree *bstOfAuthor,BSTree *bstOfPrice){
	FILE *fp;
	int len=0;
	char ch,name[NAMELEN],author[NAMELEN];
	double price;
	fp=fopen("Library.txt","r");
	*bstOfName=NULL;
	*bstOfAuthor=NULL;
	*bstOfPrice=NULL;
	ch=fgetc(fp);
	while(ch!='#'){
		len++;
		ch=fgetc(fp);
	}
	fgets(name,len+1,fp);
	len=0;
	ch=fgetc(fp);
	while(ch!='#'){
		len++;
		ch=fgetc(fp);
	}
	fgets(author,len,fp);
	fscanf(fp,"%lf",&price);
	while(price!=-1){
		InsertBSTOfName(bstOfName,name,author,price);
		InsertBSTOfAuthor(bstOfAuthor,name,author,price);
		InsertBSTOfPrice(bstOfPrice,name,author,price);
		len=0;
		ch=fgetc(fp);
		while(ch!='#'){
			len++;
			ch=fgetc(fp);
		}
		fgets(name,len,fp);
		len=0;
		ch=fgetc(fp);
		while(ch!='#'){
			len++;
			ch=fgetc(fp);
		}
		fgets(author,len,fp);
		fscanf(fp,"%lf",&price);
	}
}

BSTree SearchBST(BSTree bst,char name[]){
	if(!bst) return NULL;
	else if(strcmp(bst->name,name)==0)
		return bst;
	else if(strcmp(bst->name,name)>0)
		return SearchBST(bst->LChild,name);
	else
		return SearchBST(bst->RChild,name);
}

BSTree SearchInAuthor(BSTree bst,char author[]){
	if(!bst) return NULL;
	else if(strcmp(bst->author,author)==0)
		return bst;
	else if(strcmp(bst->author,author)>0)
		return SearchInAuthor(bst->LChild,author);
	else
		return SearchInAuthor(bst->RChild,author);
}

BSTree SearchInMoney(BSTree bst,double price){
	if(!bst) return NULL;
	else if(bst->price==price)
		return bst;
	else if(bst->price>price)
		return SearchInMoney(bst->LChild,price);
	else
		return SearchInMoney(bst->RChild,price);
}

int compare(BSTree bst,char cond[]){
	int i,pri;
	double price=0,point=1; 
	if(cond[0]=='<'){
		if(strcmp(bst->name,cond)==0)
			return 1;
	}
	else if(cond[0]>='0'&&cond[0]<='9'){
		for(i=0;i<strlen(cond);i++){
			if(cond[i]=='.'){
				point=strlen(cond)-(double)i-1;
				point=pow(10,point);
				continue;
			}
			pri=cond[i]-'0';
			price=price*10+pri;
		}
		price/=point;
		if(bst->price==price)
			return 1;
	}
	else{
		if(strcmp(bst->author,cond)==0)
			return 1;
	}
	return 0;
}

void FindBooks(BSTree bstOfName,BSTree bstOfAuthor,BSTree bstOfPrice){
	BSTree p;
	int i, num, numOfBook=0, pri;
	double price=0, point=1;
	char cond1[NAMELEN], cond2[NAMELEN], ch='Y';
	printf("Input one or more conditions of a book you want to find.\n\n");
	printf("Warning!!!:\n(1)The condions respectively are title,author and price!\n(2)The name of book needs symbol '<<>>'!\n");
	while(ch=='Y'){
		printf("\nThe num of condions you will input is(Up to 3 condions): ");
		scanf("%d",&num);
		fflush(stdin);
		switch(num){
			case 1:gets(cond1);break;
			case 2:gets(cond1);
				   gets(cond2);break;
			case 3:printf("Name Of Book: ");gets(cond1);
				   printf("Author: ");gets(cond2);
				   printf("Price: ");scanf("%lf",&price);
		}
		if(num==1)
			if(cond1[0]=='<'){
				p=bstOfName;
				while(p!=NULL){
					p=SearchBST(p,cond1);
					if(p){
						numOfBook++;
						if(numOfBook==1)
							printf("Find it! The books are as follows:\n");
						printf("%s, Writer: %s, Price: %.2lf\n",p->name,p->author,p->price);
						p=p->RChild;
					}
				}
				if(numOfBook==0)
					printf("There is no book that you want to find!\n");
				numOfBook=0;
			}
			else if(cond1[0]>='0'&&cond1[0]<='9'){
				p=bstOfPrice;
				for(i=0;i<strlen(cond1);i++){
					if(cond1[i]=='.'){
						point=strlen(cond1)-(double)i-1;
						point=pow(10,point);
						continue;
					}
					pri=cond1[i]-'0';
					price=price*10+pri;
				}
				while(p!=NULL){
					p=SearchInMoney(p,price/point);
					if(p){
						numOfBook++;
						if(numOfBook==1)
							printf("Find it! The books are as follows:\n");
						printf("Price: %.2lf,\tName: %s, Writer: %s\n",p->price,p->name,p->author);
						p=p->RChild;
					}
				}
				if(numOfBook==0)
					printf("There is no book that you want to find in this price!\n");
				point=1;
				price=0;
				numOfBook=0;
			}
			else{
				p=bstOfAuthor;
				while(p!=NULL){
					p=SearchInAuthor(p,cond1);
					if(p){
						numOfBook++;
						if(numOfBook==1)
							printf("Find it! The books are as follows:\n");
						printf("Writer: %s,\tName: %s, Price: %.2lf\n",p->author,p->name,p->price);
						p=p->RChild;
					}
				}
				if(numOfBook==0)
					printf("There is no book that you want to find from this writer!\n");
				numOfBook=0;
			}
		else if(num==2){
			if(cond1[0]=='<'){
				p=bstOfName;
				while(p!=NULL){
					p=SearchBST(p,cond1);
					if(p){
						if(compare(p,cond2))
							numOfBook++;
						if(numOfBook==1){
							numOfBook++;
							printf("Find it! The books are as follows:\n");
						}
						if(compare(p,cond2))
							printf("%s, Writer: %s, Price: %.2lf\n",p->name,p->author,p->price);
						p=p->RChild;
					}
				}
				if(numOfBook==0)
					printf("There is no book that you want to find!\n");
				numOfBook=0;
			}
			else if(cond1[0]>='0'&&cond1[0]<='9'){
				p=bstOfPrice;
				for(i=0;i<strlen(cond1);i++){
					if(cond1[i]=='.'){
						point=strlen(cond1)-(double)i-1;
						point=pow(10,point);
						continue;
					}
					pri=cond1[i]-'0';
					price=price*10+pri;
				}
				while(p!=NULL){
					p=SearchInMoney(p,price/point);
					if(p){
						if(compare(p,cond2))
							numOfBook++;
						if(numOfBook==1){
							numOfBook++;
							printf("Find it! The books are as follows:\n");
						}
						if(compare(p,cond2))
							printf("Price: %.2lf,\tName: %s, Writer: %s\n",p->price,p->name,p->author);
						p=p->RChild;
					}
				}
				if(numOfBook==0)
					printf("There is no book that you want to find!\n");
				point=1;
				price=0;
				numOfBook=0;
			}
			else{
				p=bstOfAuthor;
				while(p!=NULL){
					p=SearchInAuthor(p,cond1);
					if(p){
						if(compare(p,cond2))
							numOfBook++;
						if(numOfBook==1){
							numOfBook++;
							printf("Find it! The books are as follows:\n");
						}
						if(compare(p,cond2))
							printf("Writer: %s,\tName: %s, Price: %.2lf\n",p->author,p->name,p->price);
						p=p->RChild;
					}
				}
				if(numOfBook==0)
					printf("There is no book that you want to find from this writer!\n");
				numOfBook=0;
			}
		}
		else if(num==3){
			p=bstOfName;
			while(p!=NULL){
				p=SearchBST(p,cond1);
				if(p){
					if(strcmp(p->author,cond2)==0&&p->price==price)
						numOfBook++;
					if(numOfBook==1){
						numOfBook++;
						printf("Find it! The books are as follows:\n");
					}
					if(strcmp(p->author,cond2)==0&&p->price==price)
						printf("%s, Writer: %s, Price: %.2lf\n",p->name,p->author,p->price);
					p=p->RChild;
				}
			}
			if(numOfBook==0)
				printf("There is no book that you want to find!\n");
			numOfBook=0;
		}
		else
			printf("What you input is illegal!\n");
		printf("\nDo you need to continue to find?Input 'Y' to continue or 'N' to exit:");
		fflush(stdin);
		ch=getchar();
	}
}

void main(){
	BSTree BSTOfName,BSTOfAuthor,BSTOfPrice;
	CreateBST(&BSTOfName,&BSTOfAuthor,&BSTOfPrice);
//	InOrder(BSTOfName);
	//printf("\n\n");
	FindBooks(BSTOfName,BSTOfAuthor,BSTOfPrice);
}