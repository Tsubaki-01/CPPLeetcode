/*
 * @lc app=leetcode.cn id=1334 lang=cpp
 *
 * [1334] 阈值距离内邻居最少的城市
 *
 * https://leetcode.cn/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/
 *
 * algorithms
 * Medium (62.09%)
 * Likes:    202
 * Dislikes: 0
 * Total Accepted:    32K
 * Total Submissions: 51.6K
 * Testcase Example:  '4\n[[0,1,3],[1,2,1],[1,3,4],[2,3,1]]\n4'
 *
 * 有 n 个城市，按从 0 到 n-1 编号。给你一个边数组 edges，其中 edges[i] = [fromi, toi, weighti] 代表
 * fromi 和 toi 两个城市之间的双向加权边，距离阈值是一个整数 distanceThreshold。
 *
 * 返回在路径距离限制为 distanceThreshold 以内可到达城市最少的城市。如果有多个这样的城市，则返回编号最大的城市。
 *
 * 注意，连接城市 i 和 j 的路径的距离等于沿该路径的所有边的权重之和。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
 * 输出：3
 * 解释：城市分布图如上。
 * 每个城市阈值距离 distanceThreshold = 4 内的邻居城市分别是：
 * 城市 0 -> [城市 1, 城市 2] 
 * 城市 1 -> [城市 0, 城市 2, 城市 3] 
 * 城市 2 -> [城市 0, 城市 1, 城市 3] 
 * 城市 3 -> [城市 1, 城市 2] 
 * 城市 0 和 3 在阈值距离 4 以内都有 2 个邻居城市，但是我们必须返回城市 3，因为它的编号最大。
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]],
 * distanceThreshold = 2
 * 输出：0
 * 解释：城市分布图如上。 
 * 每个城市阈值距离 distanceThreshold = 2 内的邻居城市分别是：
 * 城市 0 -> [城市 1] 
 * 城市 1 -> [城市 0, 城市 4] 
 * 城市 2 -> [城市 3, 城市 4] 
 * 城市 3 -> [城市 2, 城市 4]
 * 城市 4 -> [城市 1, 城市 2, 城市 3] 
 * 城市 0 在阈值距离 2 以内只有 1 个邻居城市。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= n <= 100
 * 1 <= edges.length <= n * (n - 1) / 2
 * edges[i].length == 3
 * 0 <= fromi < toi < n
 * 1 <= weighti, distanceThreshold <= 10^4
 * 所有 (fromi, toi) 都是不同的。
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold)
    {
        vector<vector<int>> dp(n, vector<int>(n, 154919));
        for (auto edge : edges)
        {
            dp[edge[0]][edge[1]] = edge[2];
            dp[edge[1]][edge[0]] = edge[2];
        }
        for (int i = 0;i < n;i++)
        {
            dp[i][i] = 0;
        }

        // Floyd k是一个集合，表示目前路径可能经过了节点0~k中的若干个
        // 引入中间节点k进行动态规划
        for (int k = 0;k < n;k++)
            for (int i = 0;i < n;i++)
                for (int j = 0;j < n;j++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

        vector<int> res(n, 0);
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
            {
                if (j == i)
                    continue;
                if (dp[i][j] <= distanceThreshold)
                    res[i]++;
            }
        reverse(res.begin(), res.end());
        auto p = min_element(res.begin(), res.end());
        return distance(p, res.end() - 1);
    }
};
// @lc code=end

