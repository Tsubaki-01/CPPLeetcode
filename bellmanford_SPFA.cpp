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
    // 定义两个整数m和n，用于存储输入的边数和顶点数
    int m, n;
    // 从标准输入中读取m和n的值
    cin >> n >> m;
    // 定义一个长度为n+1的vector，用于存储每个顶点到起点的最短距离，初始值为INT_MAX
    vector<int> minDist(n + 1, INT_MAX);
    // 定义起点和终点
    int start = 1;
    int end = n;

    // 将起点的最短距离设为0
    minDist[start] = 0;

    // 定义一个长度为n+1的vector，用于存储每个顶点的邻接表
    vector<list<edge>> edges(n + 1);
    // 从标准输入中读取m条边的信息，并存储到邻接表中
    while (m--)
    {
        int s, t, v;
        cin >> s >> t >> v;
        edges[s].push_back(edge(t, v));
    }

    // 定义一个队列，用于存储待处理的顶点
    queue<int> que;
    // 定义一个长度为n+1的vector，用于存储每个顶点是否在队列中
    vector<bool> isInQueue(n + 1, false);

    // 将起点加入队列，并将起点标记为在队列中
    que.push(start);
    isInQueue[start] = true;

    // 当队列不为空时，循环处理队列中的顶点
    while (!que.empty())
    {
        // 取出队列中的第一个顶点
        int cur = que.front();que.pop();
        // 将该顶点标记为不在队列中
        isInQueue[cur] = false;

        // 遍历当前顶点的邻接表
        for (auto e : edges[cur])
        {
            // 如果通过当前顶点到达邻接顶点的距离小于已知的最短距离，则更新最短距离
            if (minDist[cur] + e.val < minDist[e.to])
            {
                minDist[e.to] = minDist[cur] + e.val;
                // 如果邻接顶点不在队列中，则将其加入队列，并标记为在队列中
                if (!isInQueue[e.to])
                {
                    que.push(e.to);
                    isInQueue[e.to] = true;
                }
            }
        }
    }


    // 如果终点的最短距离仍为INT_MAX，则说明无法到达终点，输出-1
    if (minDist[end] == INT_MAX)
        cout << -1 << endl;
    // 否则输出终点的最短距离
    else cout << minDist[end] << endl;

    // 返回0，表示程序正常结束
    return 0;
}