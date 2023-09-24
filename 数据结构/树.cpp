#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include"windows.h"
using namespace std;
typedef struct Treenode
{
	char data;
	struct Treenode *left,*right;
}Treenode,*Tree;
struct Treenode *create(Tree *T)
{
    char c;
    cin>>c;
    if(c == '0')
	{
    	
        *T = NULL;
    }
    else{
        *T = (struct Treenode *)malloc(sizeof(struct Treenode));
        (*T)->data=c;
    	create(&(*T)->left);
        create(&(*T)->right);
    }
    return *T;
}
typedef struct queue
{
	int head;
	int tail;
	Treenode* data[128]; 
}Sqlque;
void initque(Sqlque** q) 
{
    if (!((*q) = (Sqlque*)malloc(sizeof(Sqlque))))
    {
        printf("内存分配失败！");
        exit(-1);
    }
    (*q)->head = (*q)->tail = -1; //置 -1
}
bool enqueue(Sqlque* q,Treenode* T)
{
	if(q->tail==127)//判断队满 
	{
		return false;
	}
	q->tail++;
	q->data[q->tail]=T;//入队
	return true; 
}
bool dequeue(Sqlque* q,Treenode** T)//这里需要取值，所以使用双指针
{
	if(q->head==q->tail)
	{
		return false;//队满 
	} 
	q->head++;
	*T=q->data[q->head];
	return  true;
}
bool emptyque(Sqlque* q)
{
	if(q->head==q->tail)
	{
		return true;
	}
	return false;
} 
void leveltravel(Tree T)
{
	Sqlque* q;
	initque(&q);
	if(T!=NULL)
	{
		enqueue(q,T);
	}
	while(!emptyque(q))
	{
		dequeue(q,&T);
		printf("%c",T->data);
		if(T->left!=NULL)
		{
			enqueue(q,T->left);
		}
		if(T->right!=NULL)
		{
			enqueue(q,T->right);
		}
	}
}
void xiantravel(Tree T)
{
	if(T)
	{
		printf("%c",T->data);
		xiantravel(T->left);
		xiantravel(T->right);
	}
}
void zhongtravel(Tree T)
{
	if(T)
	{
		zhongtravel(T->left);
		printf("%c",T->data);
		zhongtravel(T->right);
	}
}
void houtravel(Tree T)
{
	if(T)
	{
		houtravel(T->left);
		houtravel(T->right);
		printf("%c",T->data);
	}
}
int countnode(Tree T)
{
	if(T==NULL)
	{
		return 0;
	}
	else
	{
		return countnode(T->left)+countnode(T->right)+1;
	}
}
int countleaf(Tree T)
{
	if(T==NULL)
	{
		return 0;
	}
	int count=0;
	if((!T->left)&&(!T->right))
	{
		count++;
	}
	int leftcount=countleaf(T->left);
	int rightcount=countleaf(T->right);
	count+=leftcount+rightcount;
	return count;
}
int depth(Tree T)
{
	if(T==NULL)
	{
		return 0;
	}
	else
	{
		int lt=depth(T->left);
		int rt=depth(T->right);
		return lt>rt?(lt+1):(rt+1);
	}
} 
void exchange(Tree T,Tree &newT)
{
	if(T==NULL)
	{
		newT=NULL;
		return ;
	} 
	else
	{
		newT=(Treenode *)malloc(sizeof(Treenode));
		newT->data=T->data;
		exchange(T->left,newT->right);
		exchange(T->right,newT->left);
	}
}
int main()
{
    puts("1. 建立二叉树"); 
    puts("2. 先序遍历二叉树");
    puts("3. 中序遍历二叉树");
    puts("4. 后序遍历二叉树");
    puts("5. 计算结点个数"); 
    puts("6. 计算叶子结点个数"); 
    puts("7. 计算二叉树的深度"); 
    puts("8. 交换二叉树的左右子树");  
    puts("9. 层次遍历二叉树"); 
    puts("0. 退出");
	Tree tree,newTree;
	int option=99;
	while(option!=0)
	{
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				puts("以'0'为左右子树为空的标志！");
				tree=create(&tree);
				puts("二叉树建立完成");
				break;
			case 2:	 
				puts("先序遍历的结果为：");
				xiantravel(tree);
				puts("\n");
				break; 
			case 3:
				puts("中序遍历的结果为：");
				zhongtravel(tree);
				puts("\n");
				break; 
			case 4:
				puts("后序遍历的结果为：");
				houtravel(tree);
				puts("\n");
				break;
			case 5:
				printf("结点个数为：%d\n",countnode(tree));
				break;
			case 6:
				printf("叶子结点个数为：%d\n",countleaf(tree));
				break;
			case 7:
				printf("二叉树的深度为：%d\n",depth(tree));
				break;
			case 8:
				exchange(tree,newTree);
                tree=newTree;
                puts("交换成功！\n"); 
                break;
            case 9:
				puts("层次遍历结果为：");
				leveltravel(tree);    
		}
	}
	return 0;
}
