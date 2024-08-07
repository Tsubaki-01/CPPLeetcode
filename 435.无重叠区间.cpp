/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
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
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int cnt = 0;
        if (intervals.empty())
            return cnt;
        ++cnt;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {return a[0] < b[0];});
        for (int i = 1;i < intervals.size();i++)
        {
            if (intervals[i][0] >= intervals[i - 1][1])
                ++cnt;
            else intervals[i][1] = min(intervals[i][1], intervals[i - 1][1]);
        }
        return intervals.size() - cnt;
    }
};
// @lc code=end

