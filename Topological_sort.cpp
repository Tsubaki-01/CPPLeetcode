#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    cin >> n >> m;
    vector<int> inDegree(n, 0);
    unordered_map<int, vector<int>> nextDirection;
    queue<int> que;
    vector<int> res;

    while (m--)
    {
        int s, t;
        cin >> s >> t;
        inDegree[t]++;
        nextDirection[s].push_back(t);
    }

    for (int i = 0;i < n;i++)
    {
        if (inDegree[i] == 0)
        {
            que.push(i);
        }
    }
    // auto it = find_if(inDegree.begin(), inDegree.end(), [] (int t) { return t == 0; });

    while (!que.empty())
    {
        int cur = que.front();que.pop();
        for (auto next : nextDirection[cur])
        {
            inDegree[next]--;
            if (inDegree[next] == 0)
                que.push(next);
        }
        res.push_back(cur);
    }

    if (res.size() == n)
    {
        for (int i = 0; i < n - 1; i++) cout << res[i] << " ";
        cout << res[n - 1];
    }
    else cout << -1 << endl;
}


/*
题目描述：

某个大型软件项目的构建系统拥有 N 个文件，文件编号从 0 到 N - 1，在这些文件中，某些文件依赖于其他文件的内容，
这意味着如果文件 A 依赖于文件 B，则必须在处理文件 A 之前处理文件 B （0 <= A, B <= N - 1）。
请编写一个算法，用于确定文件处理的顺序。

输入描述：

第一行输入两个正整数 N, M。表示 N 个文件之间拥有 M 条依赖关系。

后续 M 行，每行两个正整数 S 和 T，表示 T 文件依赖于 S 文件。

输出描述：

输出共一行，如果能处理成功，则输出文件顺序，用空格隔开。

如果不能成功处理（相互依赖），则输出 -1。

输入示例：

5 4
0 1
0 2
1 3
2 4
输出示例：

0 1 2 3 4
 */