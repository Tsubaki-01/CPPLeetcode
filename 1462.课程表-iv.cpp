/*
 * @lc app=leetcode.cn id=1462 lang=cpp
 *
 * [1462] 课程表 IV
 *
 * https://leetcode.cn/problems/course-schedule-iv/description/
 *
 * algorithms
 * Medium (51.16%)
 * Likes:    201
 * Dislikes: 0
 * Total Accepted:    33K
 * Total Submissions: 64.5K
 * Testcase Example:  '2\n[[1,0]]\n[[0,1],[1,0]]'
 *
 * 你总共需要上 numCourses 门课，课程编号依次为 0 到 numCourses-1 。你会得到一个数组 prerequisite ，其中
 * prerequisites[i] = [ai, bi] 表示如果你想选 bi 课程，你 必须 先选 ai 课程。
 *
 *
 * 有的课会有直接的先修课程，比如如果想上课程 1 ，你必须先上课程 0 ，那么会以 [0,1] 数对的形式给出先修课程数对。
 *
 *
 * 先决条件也可以是 间接 的。如果课程 a 是课程 b 的先决条件，课程 b 是课程 c 的先决条件，那么课程 a 就是课程 c 的先决条件。
 *
 * 你也得到一个数组 queries ，其中 queries[j] = [uj, vj]。对于第 j 个查询，您应该回答课程 uj 是否是课程 vj
 * 的先决条件。
 *
 * 返回一个布尔数组 answer ，其中 answer[j] 是第 j 个查询的答案。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：numCourses = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
 * 输出：[false,true]
 * 解释：课程 0 不是课程 1 的先修课程，但课程 1 是课程 0 的先修课程。
 *
 *
 * 示例 2：
 *
 *
 * 输入：numCourses = 2, prerequisites = [], queries = [[1,0],[0,1]]
 * 输出：[false,false]
 * 解释：没有先修课程对，所以每门课程之间是独立的。
 *
 *
 * 示例 3：
 *
 *
 *
 *
 * 输入：numCourses = 3, prerequisites = [[1,2],[1,0],[2,0]], queries =
 * [[1,0],[1,2]]
 * 输出：[true,true]
 *
 *
 *
 *
 * 提示：
 *
 *
 *
 *
 * 2 <= numCourses <= 100
 * 0 <= prerequisites.length <= (numCourses * (numCourses - 1) / 2)
 * prerequisites[i].length == 2
 * 0 <= ai, bi <= n - 1
 * ai != bi
 * 每一对 [ai, bi] 都 不同
 * 先修课程图中没有环。
 * 1 <= queries.length <= 10^4
 * 0 <= ui, vi <= n - 1
 * ui != vi
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start

// 广搜加拓扑排序，查询起来快
class Solution
{
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries)
    {
        // (m,n) m是n的前置条件
        vector<vector<bool>> preTable(numCourses, vector<bool>(numCourses, false));

        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> nexts(numCourses);

        for (auto pre : prerequisites)
        {
            inDegree[pre[1]]++;
            nexts[pre[0]].push_back(pre[1]);
            preTable[pre[0]][pre[1]] = true;
        }

        queue<int> que;
        for (int i = 0;i < numCourses;i++)
        {
            if (inDegree[i] == 0)
                que.push(i);
        }

        while (!que.empty())
        {
            int cur = que.front();que.pop();
            for (auto next : nexts[cur])
            {
                inDegree[next]--;
                for (int i = 0;i < numCourses;i++)
                {
                    preTable[i][next] = preTable[i][next] | preTable[i][cur];
                }
                if (inDegree[next] == 0)
                    que.push(next);
            }
        }

        vector<bool> res(queries.size(), false);
        for (int i = 0;i < queries.size();i++)
        {
            res[i] = preTable[queries[i][0]][queries[i][1]];
        }

        return res;

    }
};
// @lc code=end


// 只用广搜，每个查询需要重新计算，速度慢
class Solution
{
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries)
    {
        vector<vector<int>> nexts(numCourses);
        for (auto pre : prerequisites)
        {
            nexts[pre[0]].push_back(pre[1]);
        }
        vector<bool> res(queries.size(), false);

        for (int i = 0;i < queries.size();i++)
        {
            queue<int> que;
            vector<bool> visited(numCourses, false);
            que.push(queries[i][0]);
            visited[queries[i][0]] = true;

            while (!que.empty())
            {
                int cur = que.front();
                que.pop();
                for (auto next : nexts[cur])
                {
                    if (visited[next])
                        continue;

                    if (next == queries[i][1])
                    {
                        res[i] = true;
                        while (!que.empty())
                        {
                            que.pop();
                        }
                        break;
                    }
                    que.push(next);
                    visited[next] = true;
                }
            }
        }
        return res;
    }
};