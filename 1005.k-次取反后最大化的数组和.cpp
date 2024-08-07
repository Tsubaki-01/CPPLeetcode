/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */
#include<iostream>
#include <string>
#include<algorithm>
#include<vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        if (nums.size() == 0)
            return 0;
        for (int i = 0;i < k;i++)
        {
            sort(nums.begin(), nums.end());
            nums[0] = -nums[0];
        }
        int res = 0;
        for (int i = 0;i < nums.size();i++)
            res += nums[i];
        return res;
    }
};
// @lc code=end

