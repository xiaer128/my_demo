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
	    scanf("%d",&m[i]);//�����¼���ϱ�� 
	    for(j = 1;j <= m[i];j++)
	    {
	        scanf("%d",&num[i][j]);//¼�벻ͬ��ŵļ������� 
	    }
	    qsort(num[i]+1,m[i],sizeof(int),cmp);//qsort�Ա�ż������ݽ�����������
	    for(a=2,j=2;a<=m[i];a++)//����ֵ�ظ���Ԫ�أ����ҵ�Ԫ�ظ�ֵΪ��һ��Ԫ�أ������ظ����ظ��˲�����ֱ���������� 
	    {
	        if(num[i][a]!=num[i][a-1])
	        {
	            num[i][j] = num[i][a];
	            j++;
	        }
	    }
	    m[i]=j-1;//ȥ�أ�ֻ��¼��ͬԪ�صĸ��� 
	}
	scanf("%d",&k);
	while(k--)
	{
	    double sum1 = 0,sum2 = 0;//Nc,Nt 
	    scanf("%d%d",&x,&y);
	    i=1,j=1;
	    while(i <= m[x] && j <= m[y])//ͬʱ������������ 
	    {
	        if(num[x][i]==num[y][j])
	        {
	            i++,j++;
	            sum2++,sum1++;//��¼���е��������� 
	        }
	        else if(num[x][i]<num[y][j])
	        {
	            i++;
	            sum2++;//��¼����ȵ��������� 
	        }
	        else if(num[x][i]>num[y][j])
	        {
	            j++;
	            sum2++; //��¼����ȵ��������� 
	        }
	    }
	    if(i>m[x])//m[x]�������� 
	    {
	        while(j<=m[y])//���m[y]����δ����������ʣ������������� 
	        {
    	        j++;
    	        sum2++;  
	        }
	        
	    }
	    else if(j>m[y])//m[y]�������� 
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
