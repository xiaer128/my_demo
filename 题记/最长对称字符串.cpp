#include <stdio.h>
#include <string.h>
int findcmp(char a[],int i,int j) 
{
	int flag=1;
	while(i<=j)
	{
		if(a[i++]!=a[j--])
		{
			flag=0;
		}
	}
	return flag;
}
int main()
{
	char s[10001];
	gets(s);
	int i,j,count=0;
	int len=strlen(s);
	for(i=0;i<len;i++)
	{
		for(j=len-1;j>i;j--)
		{
			if(findcmp(s,i,j))
			{
				count=count>(j-i+1)?count:(j-i+1);
			}
		}
	}
	printf("%d",count);
}
