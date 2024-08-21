/*
【题目描述】

某国为促进城市间经济交流，决定对货物运输提供补贴。共有 n 个编号为 1 到 n 的城市，通过道路网络连接，网络中的道路仅允许从某个城市单向通行到另一个城市，不能反向通行。

网络中的道路都有各自的运输成本和政府补贴，道路的权值计算方式为：运输成本 - 政府补贴。权值为正表示扣除了政府补贴后运输货物仍需支付的费用；

权值为负则表示政府的补贴超过了支出的运输成本，实际表现为运输过程中还能赚取一定的收益。

然而，在评估从城市 1 到城市 n 的所有可能路径中综合政府补贴后的最低运输成本时，存在一种情况：

!!!!!!!!!!!!!!!图中可能出现负权回路!!!!!!!!!!!!!!!!!!!

负权回路是指一系列道路的总权值为负，这样的回路使得通过反复经过回路中的道路，理论上可以无限地减少总成本或无限地增加总收益。

为了避免货物运输商采用负权回路这种情况无限的赚取政府补贴，算法还需检测这种特殊情况。

请找出从城市 1 到城市 n 的所有可能路径中，综合政府补贴后的最低运输成本。同时能够检测并适当处理负权回路的存在。

城市 1 到城市 n 之间可能会出现没有路径的情况

【输入描述】

第一行包含两个正整数，第一个正整数 n 表示该国一共有 n 个城市，第二个整数 m 表示这些城市中共有 m 条道路。

接下来为 m 行，每行包括三个整数，s、t 和 v，表示 s 号城市运输货物到达 t 号城市，道路权值为 v。

【输出描述】

如果没有发现负权回路，则输出一个整数，表示从城市 1 到城市 n 的最低运输成本（包括政府补贴）。

如果该整数是负数，则表示实现了盈利。如果发现了负权回路的存在，则输出 "circle"。如果从城市 1 无法到达城市 n，则输出 "unconnected"。
 */


#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int from;
    int to;
    int val;
    edge(int a, int b, int c) :from(a), to(b), val(c) { };
};


int main()
{
    int m, n;
    cin >> n >> m;

    vector<edge> edges;
    while (m--)
    {
        int s, t, v;
        cin >> s >> t >> v;
        edges.push_back(edge(s, t, v));
    }

    vector<int> minDist(n + 1, INT_MAX);
    int start = 1;
    int end = n;

    minDist[start] = 0;

    int times = n - 1;
    while (times--)
    {
        for (auto e : edges)
        {
            if (minDist[e.from] != INT_MAX)
                minDist[e.to] = min(minDist[e.to], minDist[e.from] + e.val);
        }
    }
    if (minDist[end] == INT_MAX)
    {
        cout << "unconnected" << endl;
        return 0;
    }

    for (auto e : edges)
    {
        if (minDist[e.from] != INT_MAX && minDist[e.to] > minDist[e.from] + e.val)
        {
            cout << "circle" << endl;
            return 0;
        }
    }

    cout << minDist[end] << endl;

    return 0;
}
