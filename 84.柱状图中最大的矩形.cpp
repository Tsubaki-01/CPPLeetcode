/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
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
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty())
            return 0;

        heights.push_back(0);
        heights.insert(heights.begin(), 0);
        int res = 0;
        stack<int> sta;
        sta.push(0);

        for (int i = 1;i < heights.size();i++)
        {
            if (heights[i] > heights[sta.top()])
            {
                sta.push(i);
            }
            else if (heights[i] == heights[sta.top()])
            {
                sta.pop();
                sta.push(i);
            }
            else {
                while (!sta.empty() && heights[i] < heights[sta.top()])
                {
                    int mid = sta.top();
                    sta.pop();
                    int left = sta.top();
                    res = max(res, heights[mid] * (i - left - 1));

                }
                sta.push(i);

            }
        }
        return res;
    }

};
// @lc code=end

