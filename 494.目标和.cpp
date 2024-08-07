/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
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
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > sum) return 0; //全正或全负
        int t = (sum + target) / 2;
        if (2 * t != sum + target) return 0;

        vector<vector<int>> dp(nums.size(), vector<int>(t + 1, 0));
        dp[0][0] = 1; // 后续迭代需要
        if (t >= nums[0]) dp[0][nums[0]] += 1; // 考虑第一个元素是0
        for (int i = 1;i < dp.size();++i)
            for (int j = 0;j < dp[0].size();++j)
                if (j < nums[i]) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]];

        return dp.back().back();
    }
};
// @lc code=end

