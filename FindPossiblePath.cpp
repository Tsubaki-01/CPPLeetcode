#include <bits/stdc++.h>
using namespace std;

/*
题目描述

给定一个包含 n 个节点的无向图中，节点编号从 1 到 n （含 1 和 n ）。

你的任务是判断是否有一条从节点 source 出发到节点 destination 的路径存在。

输入描述

第一行包含两个正整数 N 和 M，N 代表节点的个数，M 代表边的个数。

后续 M 行，每行两个正整数 s 和 t，代表从节点 s 与节点 t 之间有一条边。

最后一行包含两个正整数，代表起始节点 source 和目标节点 destination。

输出描述

输出一个整数，代表是否存在从节点 source 到节点 destination 的路径。如果存在，输出 1；否则，输出 0。
 */

class DSU
{
private:
    vector<int> father;
public:
    DSU(int n)
    {
        init(n);
    };
    DSU() { };
    ~DSU() = default;

    // 并查集初始化
    void init(int n)
    {
        father.resize(n);
        for (int i = 0; i < n; ++i)
        {
            father[i] = i;
        }
    }

    // 并查集里寻根的过程
    int find(int u)
    {
        return u == father[u] ? u : father[u] = find(father[u]); // 路径压缩
    }

    // 判断 u 和 v是否找到同一个根
    bool isSame(int u, int v)
    {
        int uRoot = find(u);
        int vRoot = find(v);
        return uRoot == vRoot;
    }

    // 将v->u 这条边加入并查集
    void join(int parent, int child)
    {
        int parentRoot = find(parent); // 寻找u的根
        int childRoot = find(child); // 寻找v的根
        if (parentRoot == childRoot) return; // 如果发现根相同，则说明在一个集合，不用两个节点相连直接返回
        father[childRoot] = parentRoot;
    }
};

int main()
{
    int m, n;
    cin >> n >> m;
    DSU dsu(n + 1);
    for (int i = 0;i < m;i++)
    {
        int s, t;
        cin >> s >> t;

        dsu.join(s, t);
    }
    int source, destination;
    cin >> source >> destination;

    cout << (dsu.isSame(source, destination) ? 1 : 0) << endl;

    return 0;
}





