#include"stdio.h"
int cmp(int* a,int* b)
{
	return *a-*b;
}
void sort(int a[],int n)
{
	int i,j,t;
	for (i = 0; i < n-1; i++) 
	{
		for (j = 0; j < n-1-i; j++) 
		{
			if (a[j] > a[j+1]) 
			{
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
}
int findcontentchildren(int g[],int c,int s[],int b)
{
	int child=0,cookie=0;
	while(child<c&&cookie<b)
	{
		if(g[child]<=s[cookie])// ÿ���õ�ǰ���ɿ������㵱ǰ���ӵ�����child��һ 
		{
			child++;
		}
		cookie++;//����ֻ����һ�Σ����û�������������ñ��� 
	}
	return child;
}
int main()
{
	int g[10],s[10];
	int i,c,b;
	puts("������С���ĸ����Լ����ɵĸ�����\n");
	puts("                                       ps�����ɵĳߴ��ӦС����θ�ڴ�С");
	scanf("%d %d",&c,&b);
	puts("���������С����θ��ֵ��");
	printf("\n"); 
	for(i=0;i<c;i++)
	{
		printf("�� %d ��С����θ��ֵΪ��\n",i+1);
		scanf("%d",&g[i]);
	}
	puts("������ÿ�����ɵĳߴ磺");
	printf("\n"); 
	for(i=0;i<b;i++)
	{
		printf("�� %d �����ɵĳߴ�Ϊ��\n",i+1);
		scanf("%d",&s[i]);
	}
	puts("������ϣ�");
	sort(g,c);
	sort(s,b);
	puts("�ܳԱ��ĺ���һ���У�");
	int result=findcontentchildren(g,c,s,b);
	printf("%d��",result);
	if(result==c)
	{
		puts("�����Ǹ����ˣ���"); 
	} 
	if(result<c)
	{
		printf("���� %d ������û�Ա�",c-result);
	}
	return 0;
} 
