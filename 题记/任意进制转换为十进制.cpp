#include"stdio.h"
#include"math.h"
int main()
{
	int i,j=3,count=0;
	int x;
	int a[4]={2,0,2,2};
	puts("��������Ҫת��ʮ���ƵĽ������ͣ�"); 
	scanf("%d",&x);
	for(i=0;i<=3;i++,j--)
	{
		count+=a[i]*pow(x,j);
	}
	printf("%d ���Ƶ�2022��ʮ����ֵΪ��\n",x);
	printf("%d",count);
	return 0;
}
