#include <iostream>
using namespace std;
int g[100][100]={0};//初始化都为0，利用图的关系性质来解题
int relationship[100];
void init(int n)
{
    for(int i=0;i<=n;i++)
    {
        relationship[i]=i;
    }
}

int find(int x)//建立朋友关系，需要利用relationship数组下标对应数值两者即为朋友关系数组
{
    if(relationship[x]==x)
    {
        return x;
    }
    return relationship[x]=find(relationship[x]);
}

void unit(int x,int y)
{
    int a= find(x);
    int b= find(y);
    relationship[b]=relationship[a];
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int i;
    int a,b,friendship;
    init(n);
    for (i = 0; i < m ; i++)
    {
        cin>>a>>b>>friendship;
        g[a][b]=friendship;
        g[b][a]=friendship;
        if(friendship==1)
        {
            unit(a,b);
        }
    }
    while(k--)
    {
        cin>>a>>b;
        if(g[a][b]==1)
        {
            cout<<"No problem\n";
        }
        else if(g[a][b]==0)
        {
            cout<<"OK\n";
        }
        else
        {
            if(find(a)==find(b))
            {
                cout<<"OK but...\n";
            }
            else
            {
                cout<<"No way\n";
            }
        }
    }
    return 0;
}
