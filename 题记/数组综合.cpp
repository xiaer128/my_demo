#include <stdio.h>
#include"iostream"
using namespace std;
void show()
{
    printf("A.ð������\n");
    printf("B.ѡ������\n");
    printf("C.ֱ�ӽ�������\n");
    printf("D.��������\n");
    printf("E.�۰����\n");
    printf("X.����\n");
}
int main() 
{
	int a[100],t,i,j,p,k,n,x,left,right,mid,flag=0,count=0,min,m;//�������Ҫ�������������������ٶ���
	char c;
    printf("������Ԫ�ظ���\n");
	scanf("%d",&n);
    printf("������Ԫ�أ�\n");
	for(i=0; i<n; i++)
		scanf("%d",&a[i]);
	left=0;right=n-1;mid=(left+right)/2;
	while(c!='X') 
	{
        printf("����������Ҫ���е�����\n");
        show();
        cin>>c;
		if(c=='A')
		{
				printf("ð���������Ϊ:  \n");
				for (i = 0; i < n-1; i++) 
				{
					for (j = 0; j < n-1-i; j++) 
					{
						if (a[j] > a[j+1]) 
						{
							t = a[j];
							a[j] = a[j+1];
							a[j+1] = t;
						}
					}
					for(k=0; k<n; k++) 
					{
						printf("%d ",a[k]);
					}
					printf("\n");
				}
	    }
		else if(c=='B')
		{
				printf("ѡ���������Ϊ:  \n");
				for( i=0; i<n-1; i++)
				{
					min=i;
					for(j=i+1; j<n; j++)
					{
						if(a[j]<a[min])
						{
							min=j;
						}	
					}
					if(i!=min)
						{
							t=a[i];
							a[i]=a[min];
							a[min]=t;
						}
					for( p=0; p<n; p++)
						printf("%d ",a[p]);
					printf("\n");
				}
  		}
		else if(c=='C')
		{
				printf("ֱ�ӽ����������Ϊ:  \n");
				for(i=0;i<n-1;i++)
				{
					for(j=i+1;j<n;j++)
					{
						if(a[i]>a[j])
						{
							t=a[i];
							a[i]=a[j];
							a[j]=t;
						}
					}
					for(k=0;k<n;k++)
					{
						printf("%d ",a[k]);
					}
					printf("\n");
				}
		}
		else if(c=='D')
		{ 
				printf("�����������Ϊ:  \n");
				for(i=1;i<n;i++)
				{
				m = a[i];
				j = i - 1;
				while(j>=0&&m<a[j])
				{
					a[j+1] = a[j];
					j--;
				}
				a[j+1] = m;
				for(k=0;k<n;k++)
				{
					printf("%d ",a[k]);
				}
				printf("\n");
				}
		}
		else if(c=='E')//�۰���� 
		{
            printf("����������Ҫ���ҵ�Ԫ�أ�\n");
            scanf("%d",&x);
			for(i=0;i<n;i++)
			{
				for(j=i+1;j<n;j++)
				{
					if(a[i]>a[j])
					{
						m = a[i];
						a[i] = a[j];
						a[j] = m;
					}
				}
			}
			if(x>=a[left]&&x<=a[right])
			{
				while(!flag&&left<=right)
				{
					mid = (left+right) / 2;
					if(a[mid]==x)
                    {
						flag = 1;
					}
					else if(x>a[mid])
					{
						left = mid + 1;
						count++;
					}
					else
					{
						right = mid - 1;
						count++;
					}
				}
			}
			if(flag==1)
			{
				printf("%d %d\n",mid,count+1);
			}
			else
			{
				printf("no\n");
			}
		}
	}
	return 0;
}







