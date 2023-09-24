#include <stdio.h>
#include <stdlib.h>
int num[55][10005],a[55][10005],anum[10005];
int cmp(const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}
int main() 
{
	int n,m[55],k,i,j,a,x,y,t;
	scanf("%d",&n);
	for(i = 1;i <= n;i++)
	{
	    scanf("%d",&m[i]);//数组记录集合编号 
	    for(j = 1;j <= m[i];j++)
	    {
	        scanf("%d",&num[i][j]);//录入不同编号的集合内容 
	    }
	    qsort(num[i]+1,m[i],sizeof(int),cmp);//qsort对编号集合内容进行升序排序
	    for(a=2,j=2;a<=m[i];a++)//将数值重复的元素，靠右的元素赋值为下一个元素，若再重复则重复此操作，直到遍历结束 
	    {
	        if(num[i][a]!=num[i][a-1])
	        {
	            num[i][j] = num[i][a];
	            j++;
	        }
	    }
	    m[i]=j-1;//去重，只记录不同元素的个数 
	}
	scanf("%d",&k);
	while(k--)
	{
	    double sum1 = 0,sum2 = 0;//Nc,Nt 
	    scanf("%d%d",&x,&y);
	    i=1,j=1;
	    while(i <= m[x] && j <= m[y])//同时遍历两个集合 
	    {
	        if(num[x][i]==num[y][j])
	        {
	            i++,j++;
	            sum2++,sum1++;//记录共有的整数个数 
	        }
	        else if(num[x][i]<num[y][j])
	        {
	            i++;
	            sum2++;//记录不相等的整数个数 
	        }
	        else if(num[x][i]>num[y][j])
	        {
	            j++;
	            sum2++; //记录不相等的整数个数 
	        }
	    }
	    if(i>m[x])//m[x]遍历结束 
	    {
	        while(j<=m[y])//如果m[y]遍历未结束，则其剩余整数都不相等 
	        {
    	        j++;
    	        sum2++;  
	        }
	        
	    }
	    else if(j>m[y])//m[y]遍历结束 
	    {
	        while(i <= m[x])
	        {
    	        i++;
    	        sum2++;
	        }
	    }
	    printf("%.2f%%\n",sum1/sum2*100);
	}
	return 0;
}
