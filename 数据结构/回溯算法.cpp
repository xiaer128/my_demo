#include"stdio.h"
#include"malloc.h"
int** result;//用于储存所有组合的结果集 
int resultsize;
int* path;//用于储存组合的一维数组 
int pathsize;
void backtrack(int n,int k,int startindex) 
//n为数字范围，k为组合大小，startindex为确定搜索的起始位置
{
	if(pathsize==k)
	{
		int *temp=(int*)malloc(sizeof(int)*k);
		for(int i=0;i<k;i++)
		{
			temp[i]=path[i];
		}
		result[resultsize++]=temp;//因为全局变量的值会发生改变所以不能指向path的地址 
		return;//退出回溯 
	}
	for(int i=startindex;i<=n;i++)
	{
		path[pathsize]=i;
		pathsize++;
		backtrack(n,k,i+1);
		pathsize--;//回溯 
	}
} 
int** combine(int n,int k，int* returnindex;int** returncolumnindex)//returncolumnsizes为列大小
{
	result=(int**)malloc(sizeof(int*)*10000);
	path=(int*)malloc(sizeof(int)*k);
	resultsize=0;
	pathsize=0;
	backtrack(n,k,1);
	//返回result数组大小 
	*returnindex=resultsize;
	*returncolumnindex=(int*)malloc(sizeof(int)*resultsize);
	//returncolumnindex数组存储result二维数组对应下标中一维数组的长度 
	for(int i=0;i<*returnindex;i++)
	{
		(*returncolumnindex)[i]=k;
	}
	return result;
} 
int main()
{
	int n,k;
	int** a;
	scanf("%d %d",&n,&k);
	a=combine(n,k); 
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<100;j++)
		{
			printf("%d",a[i][j]);
		}
	}
	return 0;
} 
