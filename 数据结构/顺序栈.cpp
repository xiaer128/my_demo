#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
	int data;
	struct stack* next;
}stack;
stack* initstack()//��ʼ�� 
{
	stack *s=(stack *)malloc(sizeof(stack));
	s->data=0;
	s->next=NULL;
	return s;
}
int ifempty(stack *s)//�ж�ջ�Ƿ�Ϊ�� 
{
	if(s->data==0||s->next==NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
} 
int input(stack *s,int x)
{
	stack *node=(stack *)malloc(sizeof(stack));
	node->data=x;
	node->next=s->next;
	s->next=node;
	s->data++;//ͷ����¼Ԫ�ظ��� 
}
int popstack(stack *s)//ȡջ��Ԫ�� 
{
	if(ifempty(s)==0)
	{
		printf("ջΪ��");
		return 0; 
	}
	else
	{
		if(s->data==0)
		{
			return 0;
		}
		else
		{
			stack *node=s->next;
			int data=node->data;
			s->next=node->next;
			free(node);
			s->data--;
			return data;
		}
	}
}
void display(stack *s)//��ӡ 
{
	stack *node=s->next;
	while(node)
	{
		printf("%d -> ",node->data);
		node=node->next;
	}
	printf("NULL\n");
}
int main()
{	
	stack *s=initstack();
	 input(s,1);
	 input(s,2);
	 input(s,3);
	 input(s,4);
	 input(s,5);
	 input(s,6);
	 input(s,7);
	popstack(s);
	display(s);
	return 0;
}
