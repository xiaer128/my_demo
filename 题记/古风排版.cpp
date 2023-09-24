#include<stdio.h>
#include<string.h>
int main ( )
{
    int n, j, i, k=0, len;
    int row, column; // row 为行，column为列;
    char s[1001];
    char str[101][1001];
    scanf("%d",&n);
    getchar();
    row = n;
    gets(s);
    len = strlen(s);
    column = len/n;//求列数 
    if(len%n!=0)
        column++; // 多出一列 
    for(j=column-1;j>=0;j--)//固定列，从最右边列开始
    {
        for(i=0;i<row;i++) // 固定行，从第一行开始。
        {
            if(k<len) // 判断是否结束，结束就用空格
            {
            	str[i][j]=s[k]; // 存储字符串
            	k++;
			}
            else
            {
            	str[i][j]=' ';//空隙补缺 
			}
        }
    }
    for(i=0;i<row;i++) //输出
    {
        for(j=0;j<column;j++)
        {
            printf("%c",str[i][j]);
        }
     printf("\n");
    }
    return 0;
}

