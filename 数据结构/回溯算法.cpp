#include"stdio.h"
#include"malloc.h"
int** result;//���ڴ���������ϵĽ���� 
int resultsize;
int* path;//���ڴ�����ϵ�һά���� 
int pathsize;
void backtrack(int n,int k,int startindex) 
//nΪ���ַ�Χ��kΪ��ϴ�С��startindexΪȷ����������ʼλ��
{
	if(pathsize==k)
	{
		int *temp=(int*)malloc(sizeof(int)*k);
		for(int i=0;i<k;i++)
		{
			temp[i]=path[i];
		}
		result[resultsize++]=temp;//��Ϊȫ�ֱ�����ֵ�ᷢ���ı����Բ���ָ��path�ĵ�ַ 
		return;//�˳����� 
	}
	for(int i=startindex;i<=n;i++)
	{
		path[pathsize]=i;
		pathsize++;
		backtrack(n,k,i+1);
		pathsize--;//���� 
	}
} 
int** combine(int n,int k��int* returnindex;int** returncolumnindex)//returncolumnsizesΪ�д�С
{
	result=(int**)malloc(sizeof(int*)*10000);
	path=(int*)malloc(sizeof(int)*k);
	resultsize=0;
	pathsize=0;
	backtrack(n,k,1);
	//����result�����С 
	*returnindex=resultsize;
	*returncolumnindex=(int*)malloc(sizeof(int)*resultsize);
	//returncolumnindex����洢result��ά�����Ӧ�±���һά����ĳ��� 
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
