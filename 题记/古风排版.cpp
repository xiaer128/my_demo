#include<stdio.h>
#include<string.h>
int main ( )
{
    int n, j, i, k=0, len;
    int row, column; // row Ϊ�У�columnΪ��;
    char s[1001];
    char str[101][1001];
    scanf("%d",&n);
    getchar();
    row = n;
    gets(s);
    len = strlen(s);
    column = len/n;//������ 
    if(len%n!=0)
        column++; // ���һ�� 
    for(j=column-1;j>=0;j--)//�̶��У������ұ��п�ʼ
    {
        for(i=0;i<row;i++) // �̶��У��ӵ�һ�п�ʼ��
        {
            if(k<len) // �ж��Ƿ�������������ÿո�
            {
            	str[i][j]=s[k]; // �洢�ַ���
            	k++;
			}
            else
            {
            	str[i][j]=' ';//��϶��ȱ 
			}
        }
    }
    for(i=0;i<row;i++) //���
    {
        for(j=0;j<column;j++)
        {
            printf("%c",str[i][j]);
        }
     printf("\n");
    }
    return 0;
}

