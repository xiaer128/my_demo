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
		if(g[child]<=s[cookie])// 每当用当前饼干可以满足当前孩子的需求，child加一 
		{
			child++;
		}
		cookie++;//饼干只能用一次，如果没法满足则跳过该饼干 
	}
	return child;
}
int main()
{
	int g[10],s[10];
	int i,c,b;
	puts("请输入小孩的个数以及饼干的个数：\n");
	puts("                                       ps：饼干的尺寸对应小孩的胃口大小");
	scanf("%d %d",&c,&b);
	puts("请输入各个小孩的胃口值：");
	printf("\n"); 
	for(i=0;i<c;i++)
	{
		printf("第 %d 个小孩的胃口值为：\n",i+1);
		scanf("%d",&g[i]);
	}
	puts("请输入每个饼干的尺寸：");
	printf("\n"); 
	for(i=0;i<b;i++)
	{
		printf("第 %d 个饼干的尺寸为：\n",i+1);
		scanf("%d",&s[i]);
	}
	puts("输入完毕！");
	sort(g,c);
	sort(s,b);
	puts("能吃饱的孩子一共有：");
	int result=findcontentchildren(g,c,s,b);
	printf("%d个",result);
	if(result==c)
	{
		puts("你真是个好人！！"); 
	} 
	if(result<c)
	{
		printf("还有 %d 个孩子没吃饱",c-result);
	}
	return 0;
} 
