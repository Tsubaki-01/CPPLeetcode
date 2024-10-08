// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem630.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=630 lang=cpp
 *
 * [630] 课程表 III
 *
 * https://leetcode.cn/problems/course-schedule-iii/description/
 *
 * algorithms
 * Hard (48.47%)
 * Likes:    612
 * Dislikes: 0
 * Total Accepted:    47.1K
 * Total Submissions: 97.1K
 * Testcase Example:  '[[100,200],[200,1300],[1000,1250],[2000,3200]]'
 *
 * 这里有 n 门不同的在线课程，按从 1 到 n 编号。给你一个数组 courses ，其中 courses[i] = [durationi,
 * lastDayi] 表示第 i 门课将会 持续 上 durationi 天课，并且必须在不晚于 lastDayi 的时候完成。
 *
 * 你的学期从第 1 天开始。且不能同时修读两门及两门以上的课程。
 *
 * 返回你最多可以修读的课程数目。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：courses = [[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]
 * 输出：3
 * 解释：
 * 这里一共有 4 门课程，但是你最多可以修 3 门：
 * 首先，修第 1 门课，耗费 100 天，在第 100 天完成，在第 101 天开始下门课。
 * 第二，修第 3 门课，耗费 1000 天，在第 1100 天完成，在第 1101 天开始下门课程。
 * 第三，修第 2 门课，耗时 200 天，在第 1300 天完成。
 * 第 4 门课现在不能修，因为将会在第 3300 天完成它，这已经超出了关闭日期。
 *
 * 示例 2：
 *
 *
 * 输入：courses = [[1,2]]
 * 输出：1
 *
 *
 * 示例 3：
 *
 *
 * 输入：courses = [[3,2],[4,3]]
 * 输出：0
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= courses.length <= 10^4
 * 1 <= durationi, lastDayi <= 10^4
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
/*
   如果能增大课程数量，就增大课程数量，
   如果不能增大课程数量，就在保持课程数量不变的前提下，尝试减少总时长，使得后续增大课程数量的概率增加
*/
class Solution
{
public:
    int scheduleCourse(vector<vector<int>>& courses)
    {
        priority_queue<int, vector<int>> duration;

        int curDay = 0;
        // 按DDL排序
        sort(courses.begin(), courses.end(), [] (vector<int>& a, vector<int>& b)
            {
                return a[1] < b[1];
            });

        for (int i = 0;i < courses.size();i++)
        {
            curDay += courses[i][0];
            duration.push(courses[i][0]);
            if (curDay > courses[i][1])
            {
                curDay -= duration.top();
                duration.pop();
            }
        }
        /*
        如果能增大课程数量，就增大课程数量，
        如果不能增大课程数量，就在保持课程数量不变的前提下，尝试减少总时长，使得后续增大课程数量的概率增加
        */
        /*
        if (curDay + courses[i][0] > courses[i][1])
        {
            if (courses[i][0] < duration.top())
            {
                curDay -= duration.top();
                duration.pop();
            }
            else continue;
        }
        curDay += courses[i][0];
        duration.push(courses[i][0]);
        */
        return duration.size();
    }
};
// @lc code=end
