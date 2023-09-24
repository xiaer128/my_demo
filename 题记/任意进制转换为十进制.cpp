#include"stdio.h"
#include"math.h"
int main()
{
	int i,j=3,count=0;
	int x;
	int a[4]={2,0,2,2};
	puts("请输入你要转成十进制的进制类型："); 
	scanf("%d",&x);
	for(i=0;i<=3;i++,j--)
	{
		count+=a[i]*pow(x,j);
	}
	printf("%d 进制的2022的十进制值为：\n",x);
	printf("%d",count);
	return 0;
}
