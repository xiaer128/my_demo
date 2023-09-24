#include <stdio.h>
#include"string.h"
int main() 
{
    int n,k,s;
    int f[291]={0};
    int pta,pat;
    scanf("%d %d %d",&n,&k,&s);
    int i,j,count=0;
    for(i=0;i<n;i++)
    {
    	scanf("%d %d",&pta,&pat);
		if(pta>=175)
		{
			f[pta]++;
			if(pat>=s)
			{
				f[pta]--;
				count++;
			} 
		}
	}
	for(i=0;i<=290;i++)
	{
		if(f[i]<=k)
		{
			count+=f[i];
		}
		else
		{
			count+=k;
		}
	} 
	printf("%d",count);
    return 0;
}
