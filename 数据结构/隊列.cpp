#include<stdio.h>
#include<stdlib.h>
typedef struct que
{
	int data;
	struct que* next;
	struct que* pre;
}queue;
que* initque()
{
	que* q=(que*)malloc(sizeof(que));
	q->data=0;
	q->pre=q;
	q->next=q;
	return q;
}
void enque(que* q,int data)
{
	que* node=(que*)malloc(sizeof(que));
	node->data=data;
	node->next=q;
	node->pre=q->pre;
	q->pre->next=node;
	q->pre=node;
	q->data++;
}
int isempty(que* q)
{
	if(q->data==0||q->next==q)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int deque(que* q)
{
	if(isempty(q)==1)
	{
		return 0;
	}
	else
	{
		que* node=q->next;
		q->next=q->next->next;
		q->next->pre=q;
		return node->data;
	}
}
void display(que* q)
{
	que* node=q->next;
	while(node!=q)
	{
		printf("%d -> ",node->data);
		node=node->next;
	}
	printf("NULL\n");
}
int main()
{
	que* q=initque();
	enque(q,1);
	enque(q,2);
	enque(q,3);
	enque(q,4);
	enque(q,5);
	display(q);
	printf("deque = %d\n",deque(q));
	printf("deque = %d\n",deque(q));
	display(q);
	return 0;
}
