#include"stdio.h"
#include"malloc.h"
typedef char vertextype;
#define maxsize 100
typedef struct 
{
	vertextype v[maxsize];
	int arcnum[maxsize][maxsize];
	int vex,arc; 
}graph;
int create(graph *g)
{
	int vex,i,j,arc,k;
	printf("�����붥����ߵ�������\n");
	scanf("%d %d",&vex,&arc);
	getchar();
	g->vex=vex;
	g->arc=arc;
	for(i=0;i<vex;i++)
	{
		printf("�������%d�����㣺\n",i+1);//���춥������ 
		scanf("%c",&(g->v[i]));
		getchar();
		for(j=0;j<vex;j++)
		{
			g->arcnum[i][j];
		} 
	}
	for(k=0;k<arc;k++)
	{
		printf("�������%d���ߵ��±�λ��(����)��\n",k+1);
		scanf("%d %d",&i,&j);
		getchar();
		g->arcnum[i][j]=1;
		g->arcnum[j][i]=1;
	}
	return 0;
}
int print(graph g)
{
	int vex=(g.vex),i,j;
	puts("�ڽӾ���ͼΪ��");
	for(i=0;i<vex;i++)
	{
		for(j=0;j<vex;j++)
		{
			printf("%d",g.arcnum[i][j]);
		}
		printf("\n");
	}
	return 0;
}
int main()
{
	graph *g=(graph*)malloc(sizeof(graph));
	create(g);
	print(*g);
	return 0;
}
