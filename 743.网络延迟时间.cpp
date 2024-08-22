// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem743.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=743 lang=cpp
 *
 * [743] 网络延迟时间
 *
 * https://leetcode.cn/problems/network-delay-time/description/
 *
 * algorithms
 * Medium (56.73%)
 * Likes:    754
 * Dislikes: 0
 * Total Accepted:    134.8K
 * Total Submissions: 237.5K
 * Testcase Example:  '[[2,1,1],[2,3,1],[3,4,1]]\n4\n2'
 *
 * 有 n 个网络节点，标记为 1 到 n。
 *
 * 给你一个列表 times，表示信号经过 有向 边的传递时间。 times[i] = (ui, vi, wi)，其中 ui 是源节点，vi 是目标节点，
 * wi 是一个信号从源节点传递到目标节点的时间。
 *
 * 现在，从某个节点 K 发出一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回 -1 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
 * 输出：2
 *
 *
 * 示例 2：
 *
 *
 * 输入：times = [[1,2,1]], n = 2, k = 1
 * 输出：1
 *
 *
 * 示例 3：
 *
 *
 * 输入：times = [[1,2,1]], n = 2, k = 2
 * 输出：-1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= k <= n <= 100
 * 1 <= times.length <= 6000
 * times[i].length == 3
 * 1 <= ui, vi <= n
 * ui != vi
 * 0 <= wi <= 100
 * 所有 (ui, vi) 对都 互不相同（即，不含重复边）
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        vector < bool> visited(n + 1, false);
        vector<int> minTime(n + 1, INT_MAX);
        minTime[k] = 0;

        vector<list<pair<int, int>>> paths(n + 1);
        for (auto time : times)
        {
            paths[time[0]].emplace_back(time[1], time[2]);
        }

        auto cmp = [] (pair<int, int>& a, pair<int, int>& b) { return a.second > b.second; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> heap(cmp);

        heap.emplace(k, 0);

        while (!heap.empty())
        {
            auto cur = heap.top();heap.pop();
            if (visited[cur.first])
                continue;

            visited[cur.first] = true;

            for (auto path : paths[cur.first])
            {
                if (minTime[cur.first] + path.second < minTime[path.first])
                {
                    minTime[path.first] = minTime[cur.first] + path.second;
                    heap.emplace(path.first, minTime[path.first]);
                }

            }
        }


        auto p = max_element(minTime.begin() + 1, minTime.end());
        if (*p == INT_MAX)
            return -1;
        else return *p;

    }
};
// @lc code=end




/* class Solution
{
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        vector < bool> visited(n + 1, false);
        vector<int> minTime(n + 1, INT_MAX);
        minTime[k] = 0;

        vector<list<pair<int, int>>> paths(n + 1);
        for (auto time : times)
        {
            paths[time[0]].emplace_back(time[1], time[2]);
        }


        int temp = n;
        while (temp--)
        {
            int minT = INT_MAX;
            int cur = -1;
            for (int i = 1;i < n + 1;i++)
            {
                if (!visited[i] && minTime[i] < minT)
                {
                    minT = minTime[i];
                    cur = i;
                }
            }

            if (cur == -1)
                break;

            visited[cur] = true;

            for (auto path : paths[cur])
            {
                minTime[path.first] = min(minTime[path.first], minTime[cur] + path.second);
            }
        }

        auto p = max_element(minTime.begin() + 1, minTime.end());
        if (*p == INT_MAX)
            return -1;
        else return *p;

    }
}; */




// BellmanFord


/* class Solution
{
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        vector<int> minTime(n + 1, INT_MAX);
        minTime[k] = 0;

        vector<list<pair<int, int>>> paths(n + 1);
        for (auto time : times)
        {
            paths[time[0]].emplace_back(time[1], time[2]);
        }

        queue<int>que;
        que.push(k);
        vector<bool> isInQueue(n + 1);
        isInQueue[k] = true;

        while (!que.empty())
        {
            int cur = que.front();que.pop();
            for (auto path : paths[cur])
            {
                if (minTime[cur] != INT_MAX && minTime[path.first] > minTime[cur] + path.second)
                {
                    minTime[path.first] = minTime[cur] + path.second;
                    if (!isInQueue[path.first])  que.push(path.first);
                }
            }
        }

        auto ptr = max_element(minTime.begin() + 1, minTime.end());
        if (*ptr == INT_MAX)
            return -1;
        else return *ptr;
    }
}; */


/* class Solution
{
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        vector<int> minTime(n + 1, INT_MAX);
        minTime[k] = 0;
        for (int i = 0;i < n - 1;i++)
        {
            for (auto time : times)
            {
                if (minTime[time[0]] != INT_MAX && minTime[time[1]] > minTime[time[0]] + time[2])
                    minTime[time[1]] = minTime[time[0]] + time[2];
            }
        }

        auto ptr = max_element(minTime.begin() + 1, minTime.end());
        if (*ptr == INT_MAX)
            return -1;
        else return *ptr;
    }
}; */