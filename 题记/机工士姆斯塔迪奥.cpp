 #include"stdio.h"
 #include"stdbool.h"
 bool row[101000],col[101000];
 int main()
{
 	int n,m,q;
 	scanf("%d%d%d",&n,&m,&q);
 	int counta=0,countb=0;
 	while(q--)
 	{
 		int x,y;
		scanf("%d %d",&x,&y);
		if(!x&&!row[y])
		{
			counta++;//��ȫ������+1 
			row[y]=true;//��ȫ��Χ���ʹ�ñ������ 
		}
		if(x&&!col[y])
		{
			countb++;col[y]=true;
		}
	}
	printf("%d",n*m-counta*m-countb*n+counta*countb);
	return 0;
} 
