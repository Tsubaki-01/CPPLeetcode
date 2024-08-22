/*
题目描述

在象棋中，马和象的移动规则分别是“马走日”和“象走田”。现给定骑士的起始坐标和目标坐标，要求根据骑士的移动规则，计算从起点到达目标点所需的最短步数。

骑士移动规则如图，红色是起始位置，黄色是骑士可以走的地方。



棋盘大小 1000 x 1000（棋盘的 x 和 y 坐标均在 [1, 1000] 区间内，包含边界）

输入描述

第一行包含一个整数 n，表示测试用例的数量。

接下来的 n 行，每行包含四个整数 a1, a2, b1, b2，分别表示骑士的起始位置 (a1, a2) 和目标位置 (b1, b2)。

输出描述

输出共 n 行，每行输出一个整数，表示骑士从起点到目标点的最短路径长度。

输入示例

6
5 2 5 4
1 1 2 2
1 1 8 8
1 1 8 7
2 1 3 3
4 6 4 6
输出示例

2
4
6
5
1
0
 */

#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> step(1001, vector<int>(1001));
int directions[8][2] = { {1,2} ,{2,1} ,{1,-2},{2,-1},{-1,2},{-2,1},{-1,-2},{-2,-1} };

struct Knight
{
    int x, y;
    int f, g, h;
};

int getH(Knight& k, int endx, int endy)
{
    return (endx - k.x) * (endx - k.x) + (endy - k.y) * (endy - k.y);
}

void A_star(Knight& start, int endx, int endy, vector<vector<int>>& step)
{
    auto cmp = [] (Knight& a, Knight& b) { return a.f > b.f; };
    priority_queue <Knight, vector<Knight>, decltype(cmp)> pq(cmp);

    pq.push(start);
    while (!pq.empty())
    {
        Knight cur;
        Knight next;
        cur = pq.top();pq.pop();
        if (cur.x == endx && cur.y == endy)
            break;

        for (auto direction : directions)
        {
            next.x = cur.x + direction[0];
            next.y = cur.y + direction[1];
            if ((next.x == start.x && next.y == start.y) || next.x < 1 || next.x >= step.size()
                || next.y < 1 || next.y >= step[0].size())
                continue;

            // 如果已经有数据了，说明之前已经到过这个格子了，之后到达的步数肯定比之前的要多，跳过
            // 避免将较小的步数覆盖了
            if (step[next.x][next.y]) continue;
            step[next.x][next.y] = step[cur.x][cur.y] + 1;

            next.g = cur.g + 5;
            next.h = getH(next, endx, endy);
            next.f = next.g + next.h;

            pq.push(next);
        }
    }

}



int main()
{


    int n;
    cin >> n;
    Knight start;
    while (n--)
    {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        start.x = a1;
        start.y = a2;
        start.f = 0;
        step[a1][a2] = 0;
        for (auto& s : step)
        {
            for (auto& i : s)
                i = 0;
        }
        A_star(start, b1, b2, step);
        cout << step[b1][b2] << endl;
    }

    return 0;

}