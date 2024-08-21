/*
小明是一位科学家，他需要参加一场重要的国际科学大会，以展示自己的最新研究成果。

小明的起点是第一个车站，终点是最后一个车站。然而，途中的各个车站之间的道路状况、交通拥堵程度以及可能的自然因素（如天气变化）等不同，这些因素都会影响每条路径的通行时间。

小明希望能选择一条花费时间最少的路线，以确保他能够尽快到达目的地。

【输入描述】

第一行包含两个正整数，第一个正整数 N 表示一共有 N 个公共汽车站，第二个正整数 M 表示有 M 条公路。

接下来为 M 行，每行包括三个整数，S、E 和 V，代表了从 S 车站可以单向直达 E 车站，并且需要花费 V 单位的时间。

【输出描述】

输出一个整数，代表小明从起点到终点所花费的最小时间。

输入示例

7 9
1 2 1
1 3 4
2 3 2
2 4 5
3 4 2
4 5 3
2 6 4
5 7 4
6 7 9
输出示例：12

【提示信息】

能够到达的情况：

如下图所示，起始车站为 1 号车站，终点车站为 7 号车站，绿色路线为最短的路线，路线总长度为 12，则输出 12。
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<list<pair<int, int>>> paths(n + 1);
    while (m--)
    {
        int s, e, v;
        cin >> s >> e >> v;
        paths[s].emplace_back(e, v);
    }

    vector<int> minDist(n + 1, INT_MAX);
    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, -1);

    int start = 1;
    int end = n;

    minDist[start] = 0;

    // O(V^2+E)
    for (int i = 0;i < n;i++)
    {
        int t = INT_MAX;
        int curPos = -1;
        for (int j = 1;j < n + 1;j++)
        {
            if (minDist[j] < t && visited[j] == false)
            {
                t = minDist[j];
                curPos = j;
            }
        }

        // 没路走了，起点和终点不联通，走不到终点
        if (curPos == -1)
            break;

        visited[curPos] = true;

        for (auto path : paths[curPos])
        {
            // 可以不判断visited，但是为了逻辑通畅还是加上。（因为下一次循环开始时还是会检查visited）
            if (!visited[path.first] && minDist[path.first] > minDist[curPos] + path.second)
            {
                minDist[path.first] = minDist[curPos] + path.second;
                parent[path.first] = curPos;
            }

        }
    }
    if (minDist[end] == INT_MAX)
        cout << -1 << endl;
    else cout << minDist[end] << endl;

    for (int i = 1;i < parent.size();i++)
    {
        cout << i << "    " << parent[i] << endl;
    }

    return 0;
}