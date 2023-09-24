#include <stdio.h>
#include<math.h>
int main()
{
	int a[5][6];
	int n;
	int i,j,k;
	for(i=0;i<6;i++)
	{
		scanf("%d",&a[0][i]);
	}
	scanf("%d",&n);
	for(i=0;i<6;i++)
	{
		if(a[0][i]<6)
		{
			a[1][i]=6;
		}
		if(a[0][i]==6)
		{
			a[1][i]=5;
		}
	}
	for(i=1;i<n;i++)
	{
		for(j=0;j<6;j++)
		{
			a[1][j]--;
			if(a[1][j]==a[0][j])
			{
				a[1][j]--;
			}
		}
	}
	for(i=0;i<6;i++)
	{
		printf("%d",a[1][i]);
		if(i!=5)
		{
			printf(" ");
		}
	}
	return 0;
}
