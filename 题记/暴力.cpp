#include <stdlib.h>
#include <stdio.h>

int main()
{
  char str[30][50];
  gets(str);
  int i,j,l;
  int m,n;//б������
  int count=0;
  for(i=0;i<30;i++)
    for(j=0;j<50;j++)//������������ж�ÿһ��Ԫ��
    {
      for(l=j;l<50;l++)//����
        if(str[i][j] < str[i][l])
          count++;
      
      for(l=i;l<30;l++)//����
        if(str[i][j] < str[l][j])
          count++;

      for(m=i,n=j;m<30 && n<50;m+=1,n+=1)//����,б��
        if(str[i][j] < str[m][n])
          count++;

      for(m=i,n=j;m<30 && n>=0;m+=1,n-=1)//����,б��
      {
        if(str[i][j] > str[m][n])
          count++;
        if(str[i][j] < str[m][n])//����,б��
          count++;
      }
    }

  printf("%d",count);
  return 0;
}
