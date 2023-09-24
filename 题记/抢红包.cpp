#include <iostream>
#include <algorithm>
#include "stdio.h"
using namespace std;

struct people
{
    int id;
    double account;
    int geshu;
} peo[100000];

bool cmp( people a, people b)
{
    if (a.account == b.account)
    {
        if(a.geshu == b.geshu)
        {
            return a.id < b.id;
        }
        return a.geshu > b.geshu;
    }
    return a.account > b.account;
}

int main()
{
    int n;
    cin >> n;
    int i, j;
    int id,hongbao;
    double outcome=0,income=0;
    for (i = 0; i < n; i++)
    {
        peo[i].account = 0;
        peo[i].geshu=0;
        peo[i].id = i+1;
    }
    for (i = 0; i < n; i++)
    {
        cin >> hongbao;
        for (j = 0; j < hongbao; j++)
        {
            cin >> id;
            cin >> income;
            peo[id-1].account += income;
            outcome += income;
            peo[id-1].geshu++;
        }
        peo[i].account -= outcome;
        outcome=0;
    }
    sort(peo, peo + n, cmp);
    for (i=0;i<n;i++)
    {
        cout<<peo[i].id<<" ";
        printf("%.2lf\n",peo[i].account/100);
    }
    return 0;
}
