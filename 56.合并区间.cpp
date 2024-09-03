// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem56.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <numeric>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end(), [] (vector<int>& a, vector<int>& b)
            {
                return a[0] < b[0];
            });
        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= res.back()[1])
            {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
            else
            {
                res.push_back(intervals[i]);
            }
        }
        return res;

    }
};
// @lc code=end
/*
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {return a[0] < b[0];});
        vector<vector<int>> res;

        res.push_back(intervals[0]);

        for (int i = 1;i < intervals.size();i++)
        {
            if (intervals[i][0] <= res.back()[1])
                res.back()[1] = max(intervals[i][1], res.back()[1]);
            else
                res.push_back(intervals[i]);
        }
        return res;

    }
}; */