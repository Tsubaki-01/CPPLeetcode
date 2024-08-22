/*
【题目描述】

某国为促进城市间经济交流，决定对货物运输提供补贴。共有 n 个编号为 1 到 n 的城市，通过道路网络连接，网络中的道路仅允许从某个城市单向通行到另一个城市，不能反向通行。

网络中的道路都有各自的运输成本和政府补贴，道路的权值计算方式为：运输成本 - 政府补贴。

权值为正表示扣除了政府补贴后运输货物仍需支付的费用；

权值为负则表示政府的补贴超过了支出的运输成本，实际表现为运输过程中还能赚取一定的收益。

请计算在最多经过 k 个城市的条件下，从城市 src 到城市 dst 的最低运输成本。

【输入描述】

第一行包含两个正整数，第一个正整数 n 表示该国一共有 n 个城市，第二个整数 m 表示这些城市中共有 m 条道路。

接下来为 m 行，每行包括三个整数，s、t 和 v，表示 s 号城市运输货物到达 t 号城市，道路权值为 v。

最后一行包含三个正整数，src、dst、和 k，src 和 dst 为城市编号，从 src 到 dst 经过的城市数量限制。

【输出描述】

输出一个整数，表示从城市 src 到城市 dst 的最低运输成本，如果无法在给定经过城市数量限制下找到从 src 到 dst 的路径，则输出 "unreachable"，表示不存在符合条件的运输方案。

输入示例：

6 7
1 2 1
2 4 -3
2 5 2
1 3 5
3 5 1
4 6 4
5 6 -2
2 6 1
输出示例：

0
 */

#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int from;
    int to;
    int val;
    Edge(int s, int t, int v) :from(s), to(t), val(v) { };
};


int main()
{
    // 读取节点数和边数
    int n, m;
    cin >> n >> m;

    // 定义边集
    vector<Edge> edges;
    int s, t, v;
    // 读取每条边的信息
    while (m--)
    {
        cin >> s >> t >> v;
        // 将边的信息存入边集
        edges.emplace_back(s, t, v);
    }

    // 读取源节点、目标节点和迭代次数
    int src, dst, k;
    cin >> src >> dst >> k;

    // 定义最短路径数组，初始值为无穷大
    vector<int> minDist(n + 1, INT_MAX);

    // 源节点的最短路径为0
    minDist[src] = 0;
    // 迭代k次
    for (int t = 0;t < k + 1;t++)
    {
        // 复制最短路径数组
        auto minDist_copy = minDist;
        // 遍历每条边
        for (auto e : edges)
        {
            // 如果边的起点到源节点的最短路径不为无穷大，且边的起点到源节点的最短路径加上边的权值小于边的终点到源节点的最短路径
            if (minDist_copy[e.from] != INT_MAX && minDist_copy[e.from] + e.val < minDist[e.to])
            {
                // 更新边的终点到源节点的最短路径
                minDist[e.to] = minDist_copy[e.from] + e.val;
            }
        }
    }

    // 如果目标节点的最短路径为无穷大，则输出“unreachable”，否则输出最短路径
    if (minDist[dst] == INT_MAX)
        cout << "unreachable" << endl;
    else cout << minDist[dst] << endl;

    return 0;

}