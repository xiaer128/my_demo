#include<stdio.h>
int main()
{
	int n,k,a[10000],t=0,f=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&k);
		for(int j=0;j<k;j++)
		{
			scanf("%d",&t);
			a[t]++;
			if(a[t]>a[f])
			{
				f=t;
			}
			if(a[t]==a[f])
			{
				if(t>f)
				{
					f=t;
				}
			}
		 } 
	} 
	 printf("%d %d",f,a[f]);
	return 0;
} 
