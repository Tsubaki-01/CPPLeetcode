/*
题目描述

某国为促进城市间经济交流，决定对货物运输提供补贴。共有 n 个编号为 1 到 n 的城市，通过道路网络连接，网络中的道路仅允许从某个城市单向通行到另一个城市，不能反向通行。

网络中的道路都有各自的运输成本和政府补贴，道路的权值计算方式为：运输成本 - 政府补贴。

权值为正表示扣除了政府补贴后运输货物仍需支付的费用；权值为负则表示政府的补贴超过了支出的运输成本，实际表现为运输过程中还能赚取一定的收益。

请找出从城市 1 到城市 n 的所有可能路径中，综合政府补贴后的最低运输成本。

如果最低运输成本是一个负数，它表示在遵循最优路径的情况下，运输过程中反而能够实现盈利。

城市 1 到城市 n 之间可能会出现没有路径的情况，同时保证道路网络中不存在任何负权回路。

负权回路是指一系列道路的总权值为负，这样的回路使得通过反复经过回路中的道路，理论上可以无限地减少总成本或无限地增加总收益。

输入描述

第一行包含两个正整数，第一个正整数 n 表示该国一共有 n 个城市，第二个整数 m 表示这些城市中共有 m 条道路。

接下来为 m 行，每行包括三个整数，s、t 和 v，表示 s 号城市运输货物到达 t 号城市，道路权值为 v（单向图）。

输出描述

如果能够从城市 1 到连通到城市 n， 请输出一个整数，表示运输成本。如果该整数是负数，则表示实现了盈利。如果从城市 1 没有路径可达城市 n，请输出 "unconnected"。

输入示例：

6 7
5 6 -2
1 2 1
5 3 1
2 5 2
2 4 -3
4 6 4
1 3 5

 */

#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int to;
    int val;
    edge(int b, int c) : to(b), val(c) { };
};

// 对稀疏图效果好
int main()
{
    int m, n;
    cin >> n >> m;
    vector<int> minDist(n + 1, INT_MAX);
    int start = 1;
    int end = n;

    minDist[start] = 0;

    vector<list<edge>> edges(n + 1);
    while (m--)
    {
        int s, t, v;
        cin >> s >> t >> v;
        edges[s].push_back(edge(t, v));
    }

    queue<int> que;
    vector<bool> isInQueue(n + 1, false);

    que.push(start);
    isInQueue[start] = true;

    while (!que.empty())
    {
        int cur = que.front();que.pop();
        isInQueue[cur] = false;

        for (auto e : edges[cur])
        {
            if (minDist[cur] + e.val < minDist[e.to])
            {
                minDist[e.to] = minDist[cur] + e.val;
                if (!isInQueue[e.to])
                {
                    que.push(e.to);
                    isInQueue[e.to] = true;
                }
            }
        }
    }


    if (minDist[end] == INT_MAX)
        cout << -1 << endl;
    else cout << minDist[end] << endl;

    return 0;
}