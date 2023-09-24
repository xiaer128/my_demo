#include<iostream>
#include<set>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
const int maxn = 10000;
int pre[maxn];
struct node {//存储开始输入的人的基本信息
    int id, house;
    double area;
};
struct family{//输出的家庭结构体
        int id, number;
        double house, area;
};
bool cmp(family a, family b)//自定义比较函数
{
    if (a.area != b.area)
        return a.area > b.area;
    else
        return a.id < b.id;
}
int find(int x)//并查集模板，查找
{
    while(x != pre[x])
        x = pre[x];
    return x;
}
void merge(int x, int y)//并查集模板，合并
{
    int a = find(x);
    int b = find(y);
    if (a != b) pre[a] = b;
}
int main()
{
    int n, x;
    cin >> n;
    set<int>s;//存储每人的编号，默认升序
    /*set翻译为集合，是一个内部自动有序且不含重复元素的容器*/
    map<int, node>nodes;//记录人的房产信息
    for (int i = 0; i < maxn; i++)
        pre[i] = i;//初始化pre数组
    /*输入部分*/

    for (int i = 0; i < n; i++)
    {
        int id, p1, p2, k, house, id1;//分别记录编号 父 母 k 孩子1 ... 孩子k 房产套数
        double area;// 总面积
        cin >> id >> p1 >> p2 >> k;
        s.insert(id);//插入id
        if (p1 != -1)//有爸爸
        {
            s.insert(p1);
            merge(id, p1);
        }
        if (p2 != -1)//有妈妈
        {
            s.insert(p2);
            merge(id, p2);
        }
        for (int j = 0; j < k; j++)//随后的家庭成员
        {
            cin >> id1;
            s.insert(id1);
            merge(id1, id);
        }
        cin >> house >> area;
        nodes[id] = node{ id,house,area };//记录该人的家庭信息
    }

    set<int>s1;//记录家庭编号（也可以理解记录着每个家庭的老大）
    map<int, vector<int>>m;//记录家庭编号（）和成员编号
    for (auto it = s.begin(); it != s.end(); it++)//迭代器访问遍历
    {
        int fa = find(*it);
        m[fa].push_back(*it);
        s1.insert(fa);
    }
    cout << s1.size() << endl;//输出家庭的个数
    vector<family>v1;//容器
    for (auto it = s1.begin(); it != s1.end(); it++)//遍历容器
    {
        int fa = *it;
        double house = 0, area = 0;
        for (auto tmp = 0; tmp < m[fa].size(); tmp++)//将每个家庭的成员及其房产计算汇总，放入family结构体中
        {
            house += nodes[m[fa][tmp]].house;
            area += nodes[m[fa][tmp]].area;
        }
        v1.push_back(family{ m[fa][0],int(m[fa].size()),house * 1.0 / (int)m[fa].size(),area * 1.0 / (int)m[fa].size() });
    }
    sort(v1.begin(), v1.end(), cmp);//进行排序
    for (int i = 0; i < v1.size(); i++) {
        printf("%04d %d %.3lf %.3lf", v1[i].id, v1[i].number, v1[i].house, v1[i].area);
        if (i < v1.size() - 1) puts("");
    }
}
