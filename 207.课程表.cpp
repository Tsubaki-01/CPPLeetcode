// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem207.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 *
 * https://leetcode.cn/problems/course-schedule/description/
 *
 * algorithms
 * Medium (54.23%)
 * Likes:    1995
 * Dislikes: 0
 * Total Accepted:    440.5K
 * Total Submissions: 811.4K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * 你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。
 *
 * 在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi]
 * ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。
 *
 *
 * 例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
 *
 *
 * 请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：numCourses = 2, prerequisites = [[1,0]]
 * 输出：true
 * 解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。
 *
 * 示例 2：
 *
 *
 * 输入：numCourses = 2, prerequisites = [[1,0],[0,1]]
 * 输出：false
 * 解释：总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0 ；并且学习课程 0 之前，你还应先完成课程 1 。这是不可能的。
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= numCourses <= 2000
 * 0 <= prerequisites.length <= 5000
 * prerequisites[i].length == 2
 * 0 <= ai, bi < numCourses
 * prerequisites[i] 中的所有课程对 互不相同
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        queue<int> zero;
        vector<int> res;
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> nexts(numCourses);

        for (auto dependency : prerequisites)
        {
            inDegree[dependency[0]]++;
            nexts[dependency[1]].push_back(dependency[0]);
        }

        for (int i = 0;i < inDegree.size();i++)
        {
            if (inDegree[i] == 0)
                zero.push(i);
        }

        while (!zero.empty())
        {
            int cur = zero.front();zero.pop();
            for (auto next : nexts[cur])
            {
                inDegree[next]--;
                if (inDegree[next] == 0)
                {
                    zero.push(next);
                }
            }
            res.push_back(cur);
        }

        if (res.size() == numCourses)
        {
            return true;
        }
        return false;
    }
};
// @lc code=end

