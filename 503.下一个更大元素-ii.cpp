/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
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
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        if (nums.empty())
            return res;
        stack<int> sta;
        sta.push(0);

        for (int i = 0;i < nums.size() * 2;i++)
        {
            if (nums[i % nums.size()] < nums[sta.top() % nums.size()])
                sta.push(i);
            else if (nums[i % nums.size()] == nums[sta.top() % nums.size()])
                sta.push(i);
            else {
                while (!sta.empty() && nums[i % nums.size()] > nums[sta.top() % nums.size()])
                {
                    if (sta.top() < nums.size())
                        res[sta.top()] = nums[i % nums.size()];
                    sta.pop();
                }
            }
            sta.push(i);

        }

        return res;
    }
};
// @lc code=end

